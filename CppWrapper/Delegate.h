#pragma once
#include "pch.h"

namespace WinApi {
	public ref struct Delegate abstract {
		delegate bool WNDENUMPROC(IntPtr hwnd, LPARAM lParam);
		delegate LRESULT HOOKPROC(int nCode, WPARAM wParam, LPARAM lParam);
	};
}