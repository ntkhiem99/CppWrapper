#include "pch.h"
#include "Macro.h"
#include "../CppNative/CppNative.h"

namespace WinApi {
	bool Macro::SelectTab(IntPtr pTabControl, int selected) {
		HWND hTabControl = reinterpret_cast<HWND>(pTabControl.ToPointer());
		if (!hTabControl) {
			CppNative::error("hTabControl");
			return false;
		}

		if (selected < 0) {
			SendMessage(hTabControl, TCM_SETCURSEL, selected, 0);
			return true;
		}

		HWND parent = GetParent(hTabControl);
		if (!parent) {
			CppNative::error("parent");
			return false;
		}

		NMHDR tag = {};
		tag.hwndFrom = hTabControl;
		tag.idFrom = GetDlgCtrlID(hTabControl);
		if (!tag.idFrom) {
			CppNative::error("idFrom");
			return false;
		}

		tag.code = TCN_SELCHANGING;
		if (!CppNative::SendMessageRemote(parent, WM_NOTIFY, reinterpret_cast<WPARAM>(hTabControl), &tag)) {
			CppNative::error("TCN_SELCHANGING");
			return false;
		}

		if (SendMessage(hTabControl, TCM_SETCURSEL, selected, 0) == -1) {
			CppNative::error("TCM_SETCURSEL");
			return false;
		}

		tag.code = TCN_SELCHANGE;
		if (!CppNative::SendMessageRemote(parent, WM_NOTIFY, reinterpret_cast<WPARAM>(hTabControl), &tag)) {
			CppNative::error("TCN_SELCHANGE");
			return false;
		}

		return true;
	}
}

LPCWSTR StringToPointer(String^ string) {
	pin_ptr<const wchar_t> ptr = PtrToStringChars(string);
	return ptr;
}
