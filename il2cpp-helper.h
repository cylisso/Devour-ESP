#pragma once
#include "include.h"

void* find_class(const char* klN, const char* nsN)
{
	const auto domain = il2cpp_domain_get();
	size_t assembly_count = 0;
	void* kl;
	const void** assemblies = il2cpp_domain_get_assemblies(domain, &assembly_count);

	for (size_t idx{ 0 }; idx < assembly_count; idx++) {
		const auto img = il2cpp_assembly_get_image(assemblies[idx]);
		kl = il2cpp_class_from_name(img, nsN, klN);
		if (!kl) continue;
		return kl;
	}

	return 0;
}

uintptr_t find_method(const char* methodName, const char* className, const char* namespaceName = "",
	int argumentCount = -1, const char* argTypeName = "", int selectedArgument = -1)
{
	__try
	{
		const auto klass = find_class(className, namespaceName);
		if (!klass) return 0;

		void* iterator = nullptr;
		while (auto method = il2cpp_class_get_methods(klass, &iterator))
		{
			const auto fnName = il2cpp_method_get_name(method);

			if (strcmp(fnName, methodName) != 0)
				continue;

			if (argumentCount != -1)
			{
				auto methodCount = il2cpp_method_get_param_count(method);
				if (methodCount != argumentCount)
					continue;
			}

			if (selectedArgument != -1)
			{
				auto param = il2cpp_method_get_param(method, selectedArgument);
				if (param)
				{
					const char* paramName = il2cpp_type_get_name(param);
					if (!paramName || strcmp(paramName, argTypeName) != 0)
						continue;
				}
				else
				{
					continue;
				}
			}

			return reinterpret_cast<uintptr_t>(method);
		}
	}
	__except (1) {}

	return 0;
}

uintptr_t FindObjectOfType(const char* klN, const char* nsN = "")
{
	__try
	{
		void* klass = find_class(klN, nsN);
		if (!klass) return NULL;

		auto _type = il2cpp_class_get_type(klass);
		if (!_type) return NULL;

		auto obj = il2cpp_type_get_object(_type);
		if (!obj) return NULL;

		return oFindObjectOfType(obj);
	}
	__except (1) {}

	return NULL;
}

uintptr_t FindGameObjectWithTag(const char* tag)
{
	__try 
	{
		return oFindGameObjectWithTag(il2cpp_string_new(tag));
	}
	__except (1) {}
}