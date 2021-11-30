#pragma once
#include "pch.h"

namespace WinApi {
	public ref struct Macro abstract sealed {
		static bool SelectTab(IntPtr hTabControl, int selected);
	};
}

LPCWSTR StringToPointer(String^ string);