#define Convension _declspec(dllexport)

extern "C" {
	Convension bool _EnumChildWindows(_In_opt_ HWND hWndParent, _In_ WNDENUMPROC lpEnumFunc, _In_ LPARAM lParam) {
		return EnumChildWindows(hWndParent, lpEnumFunc, lParam);
	}
	Convension HHOOK _SetWindowsHookEx(_In_ int idHook, _In_ HOOKPROC lpfn, _In_opt_ HINSTANCE hmod, _In_ DWORD dwThreadId) {
		return SetWindowsHookEx(idHook, lpfn, hmod, dwThreadId);
	}
}