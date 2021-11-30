#pragma once
#include "pch.h"

namespace WinApi
{
	public struct Struct abstract sealed
	{
		ref struct SHELLEXECUTEINFO sealed
		{
			ULONG fMask;
			IntPtr hwnd;
			String^ lpVerb;
			String^ lpFile;
			String^ lpParameters;
			String^ lpDirectory;
			int nShow;
			IntPtr hInstApp;
			IntPtr lpIDList;
			String^ lpClass;
			IntPtr hkeyClass;
			DWORD dwHotKey;
			IntPtr hIcon;
			IntPtr hMonitor;
			IntPtr hProcess;
		};
		ref struct POINT sealed
		{
			LONG x;
			LONG y;
		};
		ref struct MSG sealed
		{
			IntPtr hwnd;
			UINT message;
			WPARAM wParam;
			LPARAM lParam;
			DWORD time;
			POINT pt;
			DWORD lPrivate;
		};
		ref struct TBBUTTONINFO sealed
		{
			UINT cbSize;
			DWORD dwMask;
			int idCommand;
			int iImage;
			BYTE fsState;
			BYTE fsStyle;
			WORD cx;
			DWORD_PTR lParam;
			String^ pszText;
			int cchText;
		};
		ref struct tagTB_BUTTONCOUNT sealed
		{
			WPARAM wParam;
			LPARAM lParam;
		};
		ref struct NMHDR sealed
		{
			IntPtr hwndFrom;
			UINT idFrom;
			UINT code;
		};
	};
}