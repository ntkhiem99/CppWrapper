#pragma once
#include "pch.h"

class CppNative final {
private:
	typedef LRESULT(_stdcall* LPFN_SENDMESSAGE)(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam);

	template<typename T>
	struct DATA {
		HWND hWnd;
		UINT Msg;
		WPARAM wParam;
		byte lParam[sizeof(T)];
		LPFN_SENDMESSAGE fnSendMessage;
	};

	static DWORD WINAPI ThreadProc(LPVOID lpParameter);
	static void AfterThreadFunc();

	static void clean(HANDLE hProcess, HANDLE functionAddress, HANDLE dataAddress, HANDLE thread);

public:
	static void error(LPCSTR txt);

	template<typename T>
	static bool SendMessageRemote(HWND hWnd, UINT Msg, WPARAM wParam, T* lParam) {
		HANDLE hProcess = nullptr;
		HANDLE functionAddress = nullptr;
		HANDLE dataAddress = nullptr;
		HANDLE thread = nullptr;

		HMODULE pUser32 = GetModuleHandle(_T("user32.dll"));
		if (!pUser32) {
			error("pUser32");
			return false;
		}

		FARPROC lpFnSendMessage = GetProcAddress(pUser32, "SendMessageA");
		if (lpFnSendMessage == nullptr) {
			error("SendMessage");
			return false;
		}

		DATA<T> data = {};
		data.hWnd = hWnd;
		data.Msg = Msg;
		data.wParam = wParam;
		memcpy(data.lParam, lParam, sizeof(T));
		data.fnSendMessage = reinterpret_cast<LPFN_SENDMESSAGE>(lpFnSendMessage);

		DWORD processId;
		GetWindowThreadProcessId(hWnd, &processId);
		if (!processId) {
			error("processId");
			return false;
		}

		hProcess = OpenProcess(PROCESS_CREATE_THREAD | PROCESS_QUERY_INFORMATION | PROCESS_VM_OPERATION | PROCESS_VM_WRITE | PROCESS_VM_READ, false, processId);
		if (!hProcess) {
			error("hProcess");
			return false;
		}

		//data
		SIZE_T dataSize = sizeof(data);
		dataAddress = VirtualAllocEx(hProcess, nullptr, dataSize, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
		if (!dataAddress) {
			clean(hProcess, functionAddress, dataAddress, thread);
			error("dataAddress");
			return false;
		}

		if (!WriteProcessMemory(hProcess, dataAddress, &data, dataSize, nullptr)) {
			clean(hProcess, functionAddress, dataAddress, thread);
			error("Write dataAddress");
			return false;
		}

		//function
		SIZE_T fncSize = (LPBYTE)AfterThreadFunc - (LPBYTE)ThreadProc;
		functionAddress = VirtualAllocEx(hProcess, nullptr, fncSize, MEM_RESERVE | MEM_COMMIT, PAGE_EXECUTE_READWRITE);
		if (!functionAddress) {
			clean(hProcess, functionAddress, dataAddress, thread);
			error("functionAddress");
			return false;
		}

		if (!WriteProcessMemory(hProcess, functionAddress, ThreadProc, fncSize, nullptr)) {
			clean(hProcess, functionAddress, dataAddress, thread);
			error("Write functionAddress");
			return false;
		}

		//thread
		thread = CreateRemoteThread(hProcess, nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(functionAddress), dataAddress, 0, nullptr);
		if (!thread) {
			clean(hProcess, functionAddress, dataAddress, thread);
			error("thread");
			return false;
		}

		DWORD waitCode = WaitForSingleObject(thread, INFINITE);
		if (waitCode) {
			clean(hProcess, functionAddress, dataAddress, thread);
			string s("WaitForSingleObject: ");
			s += to_string(waitCode);
			error(s.data());
			return false;
		}

		clean(hProcess, functionAddress, dataAddress, thread);

		return true;
	}
};