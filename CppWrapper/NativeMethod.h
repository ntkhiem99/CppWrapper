#pragma once
#include "pch.h"
#include "Struct.h"
#include "Delegate.h"
namespace WinApi {
	public ref struct NativeMethod abstract sealed {
		static bool _ShellExecuteEx(Struct::SHELLEXECUTEINFO^% pExecInfo);
		static IntPtr _GetModuleHandle(String^ lpModuleName);
		static IntPtr _LoadLibrary(String^ lpFileName);
		static IntPtr _VirtualAllocEx(IntPtr hProcess, IntPtr lpAddress, SIZE_T dwSize, DWORD flAllocationType, DWORD flProtect);
		static IntPtr _GetProcAddress(IntPtr hModule, String^ procedureName);
		static bool _FreeLibrary(IntPtr hModule);
		static DWORD _GetCurrentThreadId();
		static DWORD _GetProcessId(IntPtr Process);
		static DWORD _WaitForSingleObject(IntPtr hHandle, DWORD dwMilliseconds);
		static DWORD _GetLastError();
		static int _GetClassName(IntPtr hWnd, [Out] String^% lpClassName);
		static IntPtr _GetParent(IntPtr hWnd);
		static bool _TranslateMessage(Struct::MSG^% lpMsg);
		static LRESULT _DispatchMessage(Struct::MSG^% lpMsg);
		static bool _GetMessage(Struct::MSG^% lpMsg, IntPtr hWnd, UINT wMsgFilterMin, UINT wMsgFilterMax);
		static DWORD _MsgWaitForMultipleObjects(DWORD nCount, cli::array<IntPtr>^ pHandles, bool fWaitAll, DWORD dwMilliseconds, DWORD dwWakeMask);
		static IntPtr _FindWindowEx(IntPtr hWndParent, IntPtr hWndChildAfter, String^ lpszClass, String^ lpszWindow);
		static bool _ShowWindow(IntPtr hWnd, int nCmdShow);
		static bool _UnhookWindowsHookEx(IntPtr hhk);
		static LRESULT _CallNextHookEx(IntPtr hhk, int nCode, WPARAM wParam, LPARAM lParam);
		static bool _PostMessage(IntPtr hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static LONG_PTR _GetWindowLong(IntPtr hWnd, int nIndex);
		static int _GetDlgCtrlID(IntPtr hWnd);
		static int _GetWindowText(IntPtr hWnd, [Out] String^% lpString, int nMaxCount);
		static int _GetWindowTextLength(IntPtr hWnd);
		static LRESULT _SendMessage(IntPtr hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);
		static int _system(String^ str);
	};
}