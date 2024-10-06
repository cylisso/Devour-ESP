#ifdef __cplusplus
extern "C" {
#endif
    int MH_Initialize();
    int MH_Uninitialize();
    int MH_CreateHook(void* pTarget, void* pDetour, void** ppOriginal);
    int MH_EnableHook(void* pTarget);
    int MH_DisableHook(void* pTarget);

#ifdef __cplusplus
}
#endif

