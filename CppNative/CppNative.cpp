#pragma once
#include "pch.h"
#include "CppNative.h"

DWORD WINAPI CppNative::ThreadProc(LPVOID lpParameter) {
	DATA<NMHDR>* data = reinterpret_cast<DATA<NMHDR>*>(lpParameter);
	return data->fnSendMessage(data->hWnd, data->Msg, data->wParam, reinterpret_cast<LPARAM>(data->lParam));
}
void CppNative::AfterThreadFunc() { }

void CppNative::error(LPCSTR txt) {
	cout << "ERROR: >> " << txt << " <<" << endl;
}

void CppNative::clean(HANDLE hProcess, HANDLE functionAddress, HANDLE dataAddress, HANDLE thread) {
	if (thread)
		CloseHandle(thread);
	if (functionAddress)
		VirtualFreeEx(hProcess, functionAddress, 0, MEM_RELEASE);
	if (dataAddress)
		VirtualFreeEx(hProcess, dataAddress, 0, MEM_RELEASE);
	if (hProcess)
		CloseHandle(hProcess);
}