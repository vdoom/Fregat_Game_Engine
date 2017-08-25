#if defined(Fregat_EXPORTS) // inside DLL
#   define FREGAT_API   __declspec(dllexport)
#else // outside DLL
#   define FREGAT_API   __declspec(dllimport)
#endif 