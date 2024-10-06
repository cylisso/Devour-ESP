
typedef void (*il2cpp_register_object_callback)(void** arr, int size, void* userdata);
typedef void* (*il2cpp_liveness_reallocate_callback)(void* ptr, size_t size, void* userdata);
typedef const void* (*Il2CppSetFindPlugInCallback)(const void*);
typedef void (*Il2CppFrameWalkFunc) (const void* info, void* user_data);
typedef void(*Il2CppMethodPointer)();
typedef size_t(*Il2CppBacktraceFunc) (Il2CppMethodPointer* buffer, size_t maxSize);

DO_API(int, il2cpp_init, (const char* domain_name));

DO_API(int, il2cpp_init_utf16, (const void* domain_name));

DO_API(void, il2cpp_shutdown, ());

DO_API(void, il2cpp_set_config_dir, (const char* config_path));

DO_API(void, il2cpp_set_data_dir, (const char* data_path));

DO_API(void, il2cpp_set_temp_dir, (const char* temp_path));

DO_API(void, il2cpp_set_commandline_arguments, (int argc, const char* const argv[], const char* basedir));

DO_API(void, il2cpp_set_commandline_arguments_utf16, (int argc, const void* const argv[], const char* basedir));

DO_API(void, il2cpp_set_config_utf16, (const void* executablePath));

DO_API(void, il2cpp_set_config, (const char* executablePath));



DO_API(void, il2cpp_set_memory_callbacks, (void* callbacks));

DO_API(const void*, il2cpp_get_corlib, ());

DO_API(void, il2cpp_add_internal_call, (const char* name, Il2CppMethodPointer method));

DO_API(Il2CppMethodPointer, il2cpp_resolve_icall, (const char* name));



DO_API(void*, il2cpp_alloc, (size_t size));

DO_API(void, il2cpp_free, (void* ptr));



// array

DO_API(void*, il2cpp_array_class_get, (void* element_class, uint32_t rank));

DO_API(uint32_t, il2cpp_array_length, (void* array));

DO_API(uint32_t, il2cpp_array_get_byte_length, (void* array));

DO_API(void*, il2cpp_array_new, (void* elementTypeInfo, uintptr_t length));

DO_API(void*, il2cpp_array_new_specific, (void* arrayTypeInfo, uintptr_t length));

DO_API(void*, il2cpp_array_new_full, (void* array_class, uintptr_t* lengths, uintptr_t* lower_bounds));

DO_API(void*, il2cpp_bounded_array_class_get, (void* element_class, uint32_t rank, bool bounded));

DO_API(int, il2cpp_array_element_size, (const void* array_class));



// assembly

DO_API(const void*, il2cpp_assembly_get_image, (const void* assembly));



// class

DO_API(void, il2cpp_class_for_each, (void(*klassReportFunc)(void* klass, void* userData), void* userData));

DO_API(const void*, il2cpp_class_enum_basetype, (void* klass));

DO_API(bool, il2cpp_class_is_generic, (const void* klass));

DO_API(bool, il2cpp_class_is_inflated, (const void* klass));

DO_API(bool, il2cpp_class_is_assignable_from, (void* klass, void* oklass));

DO_API(bool, il2cpp_class_is_subclass_of, (void* klass, void* klassc, bool check_interfaces));

DO_API(bool, il2cpp_class_has_parent, (void* klass, void* klassc));

DO_API(void*, il2cpp_class_from_il2cpp_type, (const void* type));

DO_API(void*, il2cpp_class_from_name, (const void* image, const char* namespaze, const char* name));

DO_API(void*, il2cpp_class_from_system_type, (void* type));

DO_API(void*, il2cpp_class_get_element_class, (void* klass));

DO_API(const void*, il2cpp_class_get_events, (void* klass, void** iter));

DO_API(void*, il2cpp_class_get_fields, (void* klass, void** iter));

DO_API(void*, il2cpp_class_get_nested_types, (void* klass, void** iter));

DO_API(void*, il2cpp_class_get_interfaces, (void* klass, void** iter));

DO_API(const void*, il2cpp_class_get_properties, (void* klass, void** iter));

DO_API(const void*, il2cpp_class_get_property_from_name, (void* klass, const char* name));

DO_API(void*, il2cpp_class_get_field_from_name, (void* klass, const char* name));

DO_API(const void*, il2cpp_class_get_methods, (void* klass, void** iter));

DO_API(const void*, il2cpp_class_get_method_from_name, (void* klass, const char* name, int argsCount));

DO_API(const char*, il2cpp_class_get_name, (void* klass));

DO_API(void, il2cpp_type_get_name_chunked, (const void* type, void(*chunkReportFunc)(void* data, void* userData), void* userData));

DO_API(const char*, il2cpp_class_get_namespace, (void* klass));

DO_API(void*, il2cpp_class_get_parent, (void* klass));

DO_API(void*, il2cpp_class_get_declaring_type, (void* klass));

DO_API(int32_t, il2cpp_class_instance_size, (void* klass));

DO_API(size_t, il2cpp_class_num_fields, (const void* enumKlass));

DO_API(bool, il2cpp_class_is_valuetype, (const void* klass));

DO_API(int32_t, il2cpp_class_value_size, (void* klass, uint32_t* align));

DO_API(bool, il2cpp_class_is_blittable, (const void* klass));

DO_API(int, il2cpp_class_get_flags, (const void* klass));

DO_API(bool, il2cpp_class_is_abstract, (const void* klass));

DO_API(bool, il2cpp_class_is_interface, (const void* klass));

DO_API(int, il2cpp_class_array_element_size, (const void* klass));

DO_API(void*, il2cpp_class_from_type, (const void* type));

DO_API(const void*, il2cpp_class_get_type, (void* klass));

DO_API(uint32_t, il2cpp_class_get_type_token, (void* klass));

DO_API(bool, il2cpp_class_has_attribute, (void* klass, void* attr_class));

DO_API(bool, il2cpp_class_has_references, (void* klass));

DO_API(bool, il2cpp_class_is_enum, (const void* klass));

DO_API(const void*, il2cpp_class_get_image, (void* klass));

DO_API(const char*, il2cpp_class_get_assemblyname, (const void* klass));

DO_API(int, il2cpp_class_get_rank, (const void* klass));

DO_API(uint32_t, il2cpp_class_get_data_size, (const void* klass));

DO_API(void*, il2cpp_class_get_static_field_data, (const void* klass));



// testing only

DO_API(size_t, il2cpp_class_get_bitmap_size, (const void* klass));

DO_API(void, il2cpp_class_get_bitmap, (void* klass, size_t* bitmap));



// stats

DO_API(bool, il2cpp_stats_dump_to_file, (const char* path));

DO_API(uint64_t, il2cpp_stats_get_value, (int stat));



// domain

DO_API(void*, il2cpp_domain_get, ());

DO_API(const void*, il2cpp_domain_assembly_open, (void* domain, const char* name));

DO_API(const void**, il2cpp_domain_get_assemblies, (const void* domain, size_t* size));



// exception

DO_API(void, il2cpp_raise_exception, (void*));

DO_API(void*, il2cpp_exception_from_name_msg, (const void* image, const char* name_space, const char* name, const char* msg));

DO_API(void*, il2cpp_get_exception_argument_null, (const char* arg));

DO_API(void, il2cpp_format_exception, (const void* ex, char* message, int message_size));

DO_API(void, il2cpp_format_stack_trace, (const void* ex, char* output, int output_size));

DO_API(void, il2cpp_unhandled_exception, (void*));

DO_API(void, il2cpp_native_stack_trace, (const void* ex, uintptr_t** addresses, int* numFrames, char** imageUUID, char** imageName));



// field

DO_API(int, il2cpp_field_get_flags, (void* field));

DO_API(const char*, il2cpp_field_get_name, (void* field));

DO_API(void*, il2cpp_field_get_parent, (void* field));

DO_API(size_t, il2cpp_field_get_offset, (void* field));

DO_API(const void*, il2cpp_field_get_type, (void* field));

DO_API(void, il2cpp_field_get_value, (void* obj, void* field, void* value));

DO_API(void*, il2cpp_field_get_value_object, (void* field, void* obj));

DO_API(bool, il2cpp_field_has_attribute, (void* field, void* attr_class));

DO_API(void, il2cpp_field_set_value, (void* obj, void* field, void* value));

DO_API(void, il2cpp_field_static_get_value, (void* field, void* value));

DO_API(void, il2cpp_field_static_set_value, (void* field, void* value));

DO_API(void, il2cpp_field_set_value_object, (void* instance, void* field, void* value));

DO_API(bool, il2cpp_field_is_literal, (void* field));

// gc

DO_API(void, il2cpp_gc_collect, (int maxGenerations));

DO_API(int32_t, il2cpp_gc_collect_a_little, ());

DO_API(void, il2cpp_gc_start_incremental_collection, ());

DO_API(void, il2cpp_gc_disable, ());

DO_API(void, il2cpp_gc_enable, ());

DO_API(bool, il2cpp_gc_is_disabled, ());

DO_API(void, il2cpp_gc_set_mode, (int mode));

DO_API(int64_t, il2cpp_gc_get_max_time_slice_ns, ());

DO_API(void, il2cpp_gc_set_max_time_slice_ns, (int64_t maxTimeSlice));

DO_API(bool, il2cpp_gc_is_incremental, ());

DO_API(int64_t, il2cpp_gc_get_used_size, ());

DO_API(int64_t, il2cpp_gc_get_heap_size, ());

DO_API(void, il2cpp_gc_wbarrier_set_field, (void* obj, void** targetAddress, void* object));

DO_API(bool, il2cpp_gc_has_strict_wbarriers, ());

DO_API(void, il2cpp_gc_set_external_allocation_tracker, (void(*func)(void*, size_t, int)));

DO_API(void, il2cpp_gc_set_external_wbarrier_tracker, (void(*func)(void**)));

DO_API(void, il2cpp_gc_foreach_heap, (void(*func)(void* data, void* userData), void* userData));

DO_API(void, il2cpp_stop_gc_world, ());

DO_API(void, il2cpp_start_gc_world, ());

DO_API(void*, il2cpp_gc_alloc_fixed, (size_t size));

DO_API(void, il2cpp_gc_free_fixed, (void* address));

// gchandle

DO_API(uint32_t, il2cpp_gchandle_new, (void* obj, bool pinned));

DO_API(uint32_t, il2cpp_gchandle_new_weakref, (void* obj, bool track_resurrection));

DO_API(void*, il2cpp_gchandle_get_target, (uint32_t gchandle));

DO_API(void, il2cpp_gchandle_free, (uint32_t gchandle));

DO_API(void, il2cpp_gchandle_foreach_get_target, (void(*func)(void* data, void* userData), void* userData));



// vm runtime info

DO_API(uint32_t, il2cpp_object_header_size, ());

DO_API(uint32_t, il2cpp_array_object_header_size, ());

DO_API(uint32_t, il2cpp_offset_of_array_length_in_array_object_header, ());

DO_API(uint32_t, il2cpp_offset_of_array_bounds_in_array_object_header, ());

DO_API(uint32_t, il2cpp_allocation_granularity, ());



// liveness

DO_API(void*, il2cpp_unity_liveness_allocate_struct, (void* filter, int max_object_count, il2cpp_register_object_callback callback, void* userdata, il2cpp_liveness_reallocate_callback reallocate));

DO_API(void, il2cpp_unity_liveness_calculation_from_root, (void* root, void* state));

DO_API(void, il2cpp_unity_liveness_calculation_from_statics, (void* state));

DO_API(void, il2cpp_unity_liveness_finalize, (void* state));

DO_API(void, il2cpp_unity_liveness_free_struct, (void* state));



// method

DO_API(const void*, il2cpp_method_get_return_type, (const void* method));

DO_API(void*, il2cpp_method_get_declaring_type, (const void* method));

DO_API(const char*, il2cpp_method_get_name, (const void* method));

DO_API(const void*, il2cpp_method_get_from_reflection, (const void* method));

DO_API(void*, il2cpp_method_get_object, (const void* method, void* refclass));

DO_API(bool, il2cpp_method_is_generic, (const void* method));

DO_API(bool, il2cpp_method_is_inflated, (const void* method));

DO_API(bool, il2cpp_method_is_instance, (const void* method));

DO_API(uint32_t, il2cpp_method_get_param_count, (const void* method));

DO_API(const void*, il2cpp_method_get_param, (const void* method, uint32_t index));

DO_API(void*, il2cpp_method_get_class, (const void* method));

DO_API(bool, il2cpp_method_has_attribute, (const void* method, void* attr_class));

DO_API(uint32_t, il2cpp_method_get_flags, (const void* method, uint32_t* iflags));

DO_API(uint32_t, il2cpp_method_get_token, (const void* method));

DO_API(const char*, il2cpp_method_get_param_name, (const void* method, uint32_t index));



// profiler

#if IL2CPP_ENABLE_PROFILER





#endif



// property

DO_API(uint32_t, il2cpp_property_get_flags, (void* prop));

DO_API(const void*, il2cpp_property_get_get_method, (void* prop));

DO_API(const void*, il2cpp_property_get_set_method, (void* prop));

DO_API(const char*, il2cpp_property_get_name, (void* prop));

DO_API(void*, il2cpp_property_get_parent, (void* prop));



// object

DO_API(void*, il2cpp_object_get_class, (void* obj));

DO_API(uint32_t, il2cpp_object_get_size, (void* obj));

DO_API(const void*, il2cpp_object_get_virtual_method, (void* obj, const void* method));

DO_API(void*, il2cpp_object_new, (const void* klass));

DO_API(void*, il2cpp_object_unbox, (void* obj));



DO_API(void*, il2cpp_value_box, (void* klass, void* data));



// monitor

DO_API(void, il2cpp_monitor_enter, (void* obj));

DO_API(bool, il2cpp_monitor_try_enter, (void* obj, uint32_t timeout));

DO_API(void, il2cpp_monitor_exit, (void* obj));

DO_API(void, il2cpp_monitor_pulse, (void* obj));

DO_API(void, il2cpp_monitor_pulse_all, (void* obj));

DO_API(void, il2cpp_monitor_wait, (void* obj));

DO_API(bool, il2cpp_monitor_try_wait, (void* obj, uint32_t timeout));



// runtime

DO_API(void*, il2cpp_runtime_invoke, (const void* method, void* obj, void** params, void** exc));

DO_API(void*, il2cpp_runtime_invoke_convert_args, (const void* method, void* obj, void** params, int paramCount, void** exc));

DO_API(void, il2cpp_runtime_class_init, (void* klass));

DO_API(void, il2cpp_runtime_object_init, (void* obj));



DO_API(void, il2cpp_runtime_object_init_exception, (void* obj, void** exc));



DO_API(void, il2cpp_runtime_unhandled_exception_policy_set, (int value));



// string

DO_API(int32_t, il2cpp_string_length, (void* str));

DO_API(void*, il2cpp_string_chars, (void* str));

DO_API(void*, il2cpp_string_new, (const char* str));

DO_API(void*, il2cpp_string_new_len, (const char* str, uint32_t length));

DO_API(void*, il2cpp_string_new_utf16, (const void* text, int32_t len));

DO_API(void*, il2cpp_string_new_wrapper, (const char* str));

DO_API(void*, il2cpp_string_intern, (void* str));

DO_API(void*, il2cpp_string_is_interned, (void* str));



// thread

DO_API(void*, il2cpp_thread_current, ());

DO_API(void*, il2cpp_thread_attach, (void* domain));

DO_API(void, il2cpp_thread_detach, (void* thread));



DO_API(void**, il2cpp_thread_get_all_attached_threads, (size_t* size));

DO_API(bool, il2cpp_is_vm_thread, (void* thread));



// stacktrace

DO_API(void, il2cpp_current_thread_walk_frame_stack, (Il2CppFrameWalkFunc func, void* user_data));

DO_API(void, il2cpp_thread_walk_frame_stack, (void* thread, Il2CppFrameWalkFunc func, void* user_data));

DO_API(bool, il2cpp_current_thread_get_top_frame, (void* frame));

DO_API(bool, il2cpp_thread_get_top_frame, (void* thread, void* frame));

DO_API(bool, il2cpp_current_thread_get_frame_at, (int32_t offset, void* frame));

DO_API(bool, il2cpp_thread_get_frame_at, (void* thread, int32_t offset, void* frame));

DO_API(int32_t, il2cpp_current_thread_get_stack_depth, ());

DO_API(int32_t, il2cpp_thread_get_stack_depth, (void* thread));

DO_API(void, il2cpp_override_stack_backtrace, (Il2CppBacktraceFunc stackBacktraceFunc));



// type

DO_API(void*, il2cpp_type_get_object, (const void* type));

DO_API(int, il2cpp_type_get_type, (const void* type));

DO_API(void*, il2cpp_type_get_class_or_element_class, (const void* type));

DO_API(char*, il2cpp_type_get_name, (const void* type));

DO_API(bool, il2cpp_type_is_byref, (const void* type));

DO_API(uint32_t, il2cpp_type_get_attrs, (const void* type));

DO_API(bool, il2cpp_type_equals, (const void* type, const void* otherType));

DO_API(char*, il2cpp_type_get_assembly_qualified_name, (const void* type));

DO_API(bool, il2cpp_type_is_static, (const void* type));

DO_API(bool, il2cpp_type_is_pointer_type, (const void* type));



// image

DO_API(const void*, il2cpp_image_get_assembly, (const void* image));

DO_API(const char*, il2cpp_image_get_name, (const void* image));

DO_API(const char*, il2cpp_image_get_filename, (const void* image));

DO_API(const void*, il2cpp_image_get_entry_point, (const void* image));



DO_API(size_t, il2cpp_image_get_class_count, (const void* image));

DO_API(const void*, il2cpp_image_get_class, (const void* image, size_t index));



// Memory information

DO_API(void*, il2cpp_capture_memory_snapshot, ());

DO_API(void, il2cpp_free_captured_memory_snapshot, (void* snapshot));



DO_API(void, il2cpp_set_find_plugin_callback, (Il2CppSetFindPlugInCallback method));



// Logging

DO_API(void, il2cpp_register_log_callback, (void* method));



// Debugger

DO_API(void, il2cpp_debugger_set_agent_options, (const char* options));

DO_API(bool, il2cpp_is_debugger_attached, ());

DO_API(void, il2cpp_register_debugger_agent_transport, (void* debuggerTransport));



// Debug metadata

DO_API(bool, il2cpp_debug_get_method_info, (const void*, void* methodDebugInfo));



// TLS module

DO_API(void, il2cpp_unity_install_unitytls_interface, (const void* unitytlsInterfaceStruct));



// custom attributes

DO_API(void*, il2cpp_custom_attrs_from_class, (void* klass));

DO_API(void*, il2cpp_custom_attrs_from_method, (const void* method));



DO_API(void*, il2cpp_custom_attrs_get_attr, (void* ainfo, void* attr_klass));

DO_API(bool, il2cpp_custom_attrs_has_attr, (void* ainfo, void* attr_klass));

DO_API(void*, il2cpp_custom_attrs_construct, (void* cinfo));



DO_API(void, il2cpp_custom_attrs_free, (void* ainfo));



// void user data for GetComponent optimization

DO_API(void, il2cpp_class_set_userdata, (void* klass, void* userdata));

DO_API(int, il2cpp_class_get_userdata_offset, ());



DO_API(void, il2cpp_set_default_thread_affinity, (int64_t affinity_mask));


