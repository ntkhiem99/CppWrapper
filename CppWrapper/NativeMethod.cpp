#pragma once
#include "pch.h"
#include "NativeMethod.h"
#include "Struct.h"
#include "Macro.h"
#include "Delegate.h"

namespace WinApi {
	bool NativeMethod::_ShellExecuteEx(Struct::SHELLEXECUTEINFO^% pExecInfo) {
		SHELLEXECUTEINFOW shellExecuteInfo = SHELLEXECUTEINFOW();
		shellExecuteInfo.cbSize = sizeof(SHELLEXECUTEINFO);
		shellExecuteInfo.fMask = pExecInfo->fMask;
		shellExecuteInfo.hwnd = (HWND)pExecInfo->hwnd.ToPointer();
		shellExecuteInfo.lpVerb = StringToPointer(pExecInfo->lpVerb);
		shellExecuteInfo.lpFile = StringToPointer(pExecInfo->lpFile);
		shellExecuteInfo.lpParameters = StringToPointer(pExecInfo->lpParameters);
		shellExecuteInfo.lpDirectory = StringToPointer(pExecInfo->lpDirectory);
		shellExecuteInfo.nShow = pExecInfo->nShow;
		shellExecuteInfo.hInstApp = (HINSTANCE)pExecInfo->hInstApp.ToPointer();
		shellExecuteInfo.lpIDList = pExecInfo->lpIDList.ToPointer();
		shellExecuteInfo.lpClass = StringToPointer(pExecInfo->lpClass);
		shellExecuteInfo.hkeyClass = (HKEY)pExecInfo->hkeyClass.ToPointer();
		shellExecuteInfo.dwHotKey = pExecInfo->dwHotKey;
		shellExecuteInfo.hIcon = pExecInfo->hIcon.ToPointer();
		shellExecuteInfo.hMonitor = pExecInfo->hMonitor.ToPointer();
		shellExecuteInfo.hProcess = pExecInfo->hProcess.ToPointer();

		bool result = ShellExecuteExW(&shellExecuteInfo);

		pExecInfo->hInstApp = IntPtr(shellExecuteInfo.hInstApp);

		return result;
	}

	IntPtr NativeMethod::_GetModuleHandle(String^ lpModuleName) {
		return IntPtr(GetModuleHandleW(StringToPointer(lpModuleName)));
	}

	IntPtr NativeMethod::_LoadLibrary(String^ lpFileName) {
		return IntPtr(LoadLibraryW(StringToPointer(lpFileName)));
	}

	IntPtr NativeMethod::_VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect) {
		return IntPtr(VirtualAllocEx(hProcess.ToPointer(), lpAddress.ToPointer(), dwSize, flAllocationType, flProtect));
	}

	IntPtr NativeMethod::_GetProcAddress(IntPtr hModule, String^ procedureName) {
		LPCWSTR p_str = StringToPointer(procedureName);
		wstring ws(p_str);
		string s(ws.begin(), ws.end());

		return IntPtr(GetProcAddress((HMODULE)hModule.ToPointer(), s.data()));
	}

	bool NativeMethod::_FreeLibrary(IntPtr hModule) {
		return FreeLibrary((HMODULE)hModule.ToPointer());
	}

	DWORD NativeMethod::_GetCurrentThreadId() {
		return GetCurrentThreadId();
	}

	DWORD NativeMethod::_GetProcessId(IntPtr Process) {
		return GetProcessId(Process.ToPointer());
	}

	DWORD NativeMethod::_WaitForSingleObject(IntPtr hHandle, DWORD dwMilliseconds) {
		return WaitForSingleObject(hHandle.ToPointer(), dwMilliseconds);
	}

	DWORD NativeMethod::_GetLastError() {
		return GetLastError();
	}

	int NativeMethod::_GetClassName(IntPtr hWnd, String^% lpClassName) {
		TCHAR ptr[256];

		int result = GetClassName((HWND)hWnd.ToPointer(), ptr, 256);

		lpClassName = gcnew String(ptr);

		return result;
	}

	IntPtr NativeMethod::_GetParent(IntPtr hWnd) {
		return IntPtr(GetParent((HWND)hWnd.ToPointer()));
	}

	bool NativeMethod::_TranslateMessage(Struct::MSG^% lpMsg) {
		POINT point = POINT();
		point.x = lpMsg->pt.x;
		point.y = lpMsg->pt.y;

		MSG msg = MSG();
		msg.pt = point;
		msg.hwnd = (HWND)lpMsg->hwnd.ToPointer();
		msg.message = lpMsg->message;
		msg.time = lpMsg->time;
		msg.lParam = lpMsg->lParam;
		msg.wParam = lpMsg->wParam;

		bool result = TranslateMessage(&msg);

		lpMsg->pt.x = point.x;
		lpMsg->pt.y = point.y;

		lpMsg->hwnd = IntPtr(msg.hwnd);
		lpMsg->message = msg.message;
		lpMsg->time = msg.time;
		lpMsg->lParam = msg.lParam;
		lpMsg->wParam = msg.wParam;

		return result;
	}

	LRESULT NativeMethod::_DispatchMessage(Struct::MSG^% lpMsg) {
		POINT point = POINT();
		point.x = lpMsg->pt.x;
		point.y = lpMsg->pt.y;

		MSG msg = MSG();
		msg.pt = point;
		msg.hwnd = (HWND)lpMsg->hwnd.ToPointer();
		msg.message = lpMsg->message;
		msg.time = lpMsg->time;
		msg.lParam = lpMsg->lParam;
		msg.wParam = lpMsg->wParam;

		LRESULT result = DispatchMessage(&msg);

		lpMsg->pt.x = point.x;
		lpMsg->pt.y = point.y;

		lpMsg->hwnd = IntPtr(msg.hwnd);
		lpMsg->message = msg.message;
		lpMsg->time = msg.time;
		lpMsg->lParam = msg.lParam;
		lpMsg->wParam = msg.wParam;

		return result;
	}

	bool NativeMethod::_GetMessage(Struct::MSG^% lpMsg, IntPtr hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax) {
		POINT point = POINT();
		point.x = lpMsg->pt.x;
		point.y = lpMsg->pt.y;

		MSG msg = MSG();
		msg.pt = point;
		msg.hwnd = (HWND)lpMsg->hwnd.ToPointer();
		msg.message = lpMsg->message;
		msg.time = lpMsg->time;
		msg.lParam = lpMsg->lParam;
		msg.wParam = lpMsg->wParam;

		bool result = GetMessage(&msg, (HWND)hWnd.ToPointer(), wMsgFilterMin, wMsgFilterMax);

		lpMsg->pt.x = point.x;
		lpMsg->pt.y = point.y;

		lpMsg->hwnd = IntPtr(msg.hwnd);
		lpMsg->message = msg.message;
		lpMsg->time = msg.time;
		lpMsg->lParam = msg.lParam;
		lpMsg->wParam = msg.wParam;

		return result;
	}

	DWORD NativeMethod::_MsgWaitForMultipleObjects(DWORD nCount, cli::array<IntPtr>^ pHandles, bool fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask) {
		HANDLE* realArray = new HANDLE[pHandles->Length];
		for (int i = 0; i < pHandles->Length; i++)
			realArray[i] = pHandles[i].ToPointer();

		DWORD result = MsgWaitForMultipleObjects(nCount, realArray, fWaitAll, dwMilliseconds, dwWakeMask);

		delete[] realArray;

		return result;
	}

	IntPtr NativeMethod::_FindWindowEx(IntPtr hWndParent, IntPtr hWndChildAfter, String^ lpszClass, String^ lpszWindow) {
		return IntPtr(FindWindowExW((HWND)hWndParent.ToPointer(), (HWND)hWndChildAfter.ToPointer(), StringToPointer(lpszClass), StringToPointer(lpszWindow)));
	}

	bool NativeMethod::_ShowWindow(IntPtr hWnd, int nCmdShow) {
		return ShowWindow((HWND)hWnd.ToPointer(), nCmdShow);
	}

	bool NativeMethod::_UnhookWindowsHookEx(IntPtr hhk) {
		return UnhookWindowsHookEx((HHOOK)hhk.ToPointer());
	}

	LRESULT NativeMethod::_CallNextHookEx(IntPtr hhk, int nCode, WPARAM wParam, LPARAM lParam) {
		return CallNextHookEx((HHOOK)hhk.ToPointer(), nCode, wParam, lParam);
	}

	bool NativeMethod::_PostMessage(IntPtr hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
		return PostMessage((HWND)hWnd.ToPointer(), Msg, wParam, lParam);
	}

	LONG NativeMethod::_GetWindowLong(IntPtr hWnd, int nIndex) {
		return IntPtr::Size == 8
			? GetWindowLongPtr((HWND)hWnd.ToPointer(), nIndex)
			: GetWindowLong((HWND)hWnd.ToPointer(), nIndex);
	}

	int NativeMethod::_GetDlgCtrlID(IntPtr hWnd) {
		return GetDlgCtrlID((HWND)hWnd.ToPointer());
	}

	int NativeMethod::_GetWindowText(IntPtr hWnd, String^% lpString, int nMaxCount) {
		TCHAR* str_ptr = new TCHAR[nMaxCount];

		int result = GetWindowText((HWND)hWnd.ToPointer(), str_ptr, nMaxCount);

		lpString = gcnew String(str_ptr);

		delete[] str_ptr;

		return result;
	}

	int NativeMethod::_GetWindowTextLength(IntPtr hWnd) {
		return GetWindowTextLength((HWND)hWnd.ToPointer());
	}

	LRESULT NativeMethod::_SendMessage(IntPtr hWnd, UINT Msg, WPARAM wParam, LPARAM lParam) {
		return SendMessage((HWND)hWnd.ToPointer(), Msg, wParam, lParam);
	}

	int NativeMethod::_system(String^ str) {
		wstring ws = StringToPointer(str);
		string s(ws.begin(), ws.end());
		return system(s.data());
	}
}