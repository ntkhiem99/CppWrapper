#include "pch.h"
#include "Macro.h"
#include "../CppNative/CppNative.h"

namespace WinApi {
	bool Macro::SelectTab(IntPtr pTabControl, int selected) {
		HWND hTabControl = reinterpret_cast<HWND>(pTabControl.ToPointer());
		if (!hTabControl)
			return false;

		SendMessage(hTabControl, TCM_SETCURSEL, selected, 0);

		if (selected < 0)
			return true;

		HWND parent = GetParent(hTabControl);
		if (!parent)
			return false;

		NMHDR tag = {};
		tag.hwndFrom = hTabControl;
		tag.idFrom = GetDlgCtrlID(hTabControl);
		if(!tag.idFrom)
			return false;

		tag.code = TCN_SELCHANGING;
		if (!CppNative::SendMessageRemote(parent, WM_NOTIFY, reinterpret_cast<WPARAM>(hTabControl), &tag))
			return false;

		tag.code = TCN_SELCHANGE;
		if(!CppNative::SendMessageRemote(parent, WM_NOTIFY, reinterpret_cast<WPARAM>(hTabControl), &tag))
			return false;

		return true;
	}
}

LPCWSTR StringToPointer(String^ string) {

	pin_ptr<const wchar_t> ptr = PtrToStringChars(string);
	return ptr;
}
