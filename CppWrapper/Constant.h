#pragma once
#include "pch.h"
#include <WinUser.h>

namespace WinApi {
	public struct Constant abstract sealed {
		ref struct PAGE abstract sealed {
			literal int NOACCESS = PAGE_NOACCESS;
			literal int READONLY = PAGE_READONLY;
			literal int READWRITE = PAGE_READWRITE;
			literal int WRITECOPY = PAGE_WRITECOPY;
			literal int EXECUTE = PAGE_EXECUTE;
			literal int EXECUTE_READ = PAGE_EXECUTE_READ;
			literal int EXECUTE_READWRITE = PAGE_EXECUTE_READWRITE;
			literal int EXECUTE_WRITECOPY = PAGE_EXECUTE_WRITECOPY;
			literal int GUARD = PAGE_GUARD;
			literal int NOCACHE = PAGE_NOCACHE;
			literal int WRITECOMBINE = PAGE_WRITECOMBINE;
		};
		ref struct MEM abstract sealed {
			literal int COMMIT = MEM_COMMIT;
			literal int RESERVE = MEM_RESERVE;
			literal int DECOMMIT = MEM_DECOMMIT;
			literal int RELEASE = MEM_RELEASE;
			literal int RESET = MEM_RESET;
			literal int PHYSICAL = MEM_PHYSICAL;
			literal int TOP_DOWN = MEM_TOP_DOWN;
			literal int WRITE_WATCH = MEM_WRITE_WATCH;
			literal int LARGE_PAGES = MEM_LARGE_PAGES;
		};
		ref struct GWL abstract sealed {
#ifdef _WIN64
			literal int WNDPROC = GWLP_WNDPROC;
			literal int HINSTANCE = GWLP_HINSTANCE;
			literal int HWNDPARENT = GWLP_HWNDPARENT;
			literal int USERDATA = GWLP_USERDATA;
#else
			literal int WNDPROC = GWL_WNDPROC;
			literal int HINSTANCE = GWL_HINSTANCE;
			literal int HWNDPARENT = GWL_HWNDPARENT;
			literal int USERDATA = GWL_USERDATA;
#endif
			

			literal int ID = GWL_ID;
			literal int STYLE = GWL_STYLE;
			literal int EXSTYLE = GWL_EXSTYLE;
		};
		ref struct WM abstract sealed {
			literal int COMMAND = WM_COMMAND;
			literal int GETTEXTLENGTH = WM_GETTEXTLENGTH;
			literal int GETTEXT = WM_GETTEXT;
			literal int NOTIFY = WM_NOTIFY;
		};
		ref struct HCBT abstract sealed {
			literal int MOVESIZE = HCBT_MOVESIZE;
			literal int MINMAX = HCBT_MINMAX;
			literal int QS = HCBT_QS;
			literal int CREATEWND = HCBT_CREATEWND;
			literal int DESTROYWND = HCBT_DESTROYWND;
			literal int ACTIVATE = HCBT_ACTIVATE;
			literal int CLICKSKIPPED = HCBT_CLICKSKIPPED;
			literal int KEYSKIPPED = HCBT_KEYSKIPPED;
			literal int SYSCOMMAND = HCBT_SYSCOMMAND;
			literal int SETFOCUS = HCBT_SETFOCUS;
		};
		ref struct TB abstract sealed {
			literal int GETBUTTON = TB_GETBUTTON;
			literal int BUTTONCOUNT = TB_BUTTONCOUNT;
			literal int GETBUTTONINFO = TB_GETBUTTONINFO;
		};
		ref struct WH abstract sealed {
			literal int MSGFILTER = WH_MSGFILTER;
			literal int JOURNALRECORD = WH_JOURNALRECORD;
			literal int JOURNALPLAYBACK = WH_JOURNALPLAYBACK;
			literal int KEYBOARD = WH_KEYBOARD;
			literal int GETMESSAGE = WH_GETMESSAGE;
			literal int CALLWNDPROC = WH_CALLWNDPROC;
			literal int CBT = WH_CBT;
			literal int SYSMSGFILTER = WH_SYSMSGFILTER;
			literal int MOUSE = WH_MOUSE;
			literal int DEBUG = WH_DEBUG;
			literal int SHELL = WH_SHELL;
			literal int FOREGROUNDIDLE = WH_FOREGROUNDIDLE;
			literal int CALLWNDPROCRET = WH_CALLWNDPROCRET;
			literal int KEYBOARD_LL = WH_KEYBOARD_LL;
			literal int MOUSE_LL = WH_MOUSE_LL;
		};
		ref struct SW abstract sealed {
			literal int HIDE = SW_HIDE;
			literal int SHOWNORMAL = SW_SHOWNORMAL;
			literal int SHOWMINIMIZED = SW_SHOWMINIMIZED;
			literal int SHOWMAXIMIZED = SW_SHOWMAXIMIZED;
			literal int SHOWNOACTIVATE = SW_SHOWNOACTIVATE;
			literal int SHOW = SW_SHOW;
			literal int MINIMIZE = SW_MINIMIZE;
			literal int SHOWMINNOACTIVE = SW_SHOWMINNOACTIVE;
			literal int SHOWNA = SW_SHOWNA;
			literal int RESTORE = SW_RESTORE;
			literal int SHOWDEFAULT = SW_SHOWDEFAULT;
			literal int FORCEMINIMIZE = SW_FORCEMINIMIZE;
		};
		ref struct SEE_MASK abstract sealed {
			literal int DEFAULT = SEE_MASK_DEFAULT;
			literal int CLASSNAME = SEE_MASK_CLASSNAME;
			literal int CLASSKEY = SEE_MASK_CLASSKEY;
			literal int IDLIST = SEE_MASK_IDLIST;
			literal int INVOKEIDLIST = SEE_MASK_INVOKEIDLIST;
			literal int HOTKEY = SEE_MASK_HOTKEY;
			literal int NOCLOSEPROCESS = SEE_MASK_NOCLOSEPROCESS;
			literal int CONNECTNETDRV = SEE_MASK_CONNECTNETDRV;
			literal int NOASYNC = SEE_MASK_NOASYNC;
			literal int FLAG_DDEWAIT = SEE_MASK_FLAG_DDEWAIT;
			literal int DOENVSUBST = SEE_MASK_DOENVSUBST;
			literal int FLAG_NO_UI = SEE_MASK_FLAG_NO_UI;
			literal int UNI = SEE_MASK_UNICODE;
			literal int NO_CONSOLE = SEE_MASK_NO_CONSOLE;
			literal int ASYNCOK = SEE_MASK_ASYNCOK;
			literal int NOQUERYCLASSSTORE = SEE_MASK_NOQUERYCLASSSTORE;
			literal int HMONITOR = SEE_MASK_HMONITOR;
			literal int NOZONECHECKS = SEE_MASK_NOZONECHECKS;
			literal int WAITFORINPUTIDLE = SEE_MASK_WAITFORINPUTIDLE;
			literal int FLAG_LOG_USAGE = SEE_MASK_FLAG_LOG_USAGE;
			literal int FLAG_HINST_IS_SITE = SEE_MASK_FLAG_HINST_IS_SITE;
		};
		ref struct VERB abstract sealed {
			literal String^ edit = "edit";
			literal String^ explore = "explore";
			literal String^ find = "find";
			literal String^ open = "open";
			literal String^ print = "print";
			literal String^ properties = "properties";
			literal String^ runas = "runas";
		};
		ref struct CBN abstract sealed {
			literal int ERRSPACE = CBN_ERRSPACE;
			literal int SELCHANGE = CBN_SELCHANGE;
			literal int DBLCLK = CBN_DBLCLK;
			literal int SETFOCUS = CBN_SETFOCUS;
			literal int KILLFOCUS = CBN_KILLFOCUS;
			literal int EDITCHANGE = CBN_EDITCHANGE;
			literal int EDITUPDATE = CBN_EDITUPDATE;
			literal int DROPDOWN = CBN_DROPDOWN;
			literal int CLOSEUP = CBN_CLOSEUP;
			literal int SELENDOK = CBN_SELENDOK;
			literal int SELENDCANCEL = CBN_SELENDCANCEL;
		};
		ref struct CB abstract sealed {
			literal int FINDSTRING = CB_FINDSTRING;
			literal int SETCURSEL = CB_SETCURSEL;
			literal int GETCOUNT = CB_GETCOUNT;
			literal int GETLBTEXT = CB_GETLBTEXT;
			literal int GETLBTEXTLEN = CB_GETLBTEXTLEN;
		};
		ref struct BM abstract sealed {
			literal int CLICK = BM_CLICK;
		};
		ref struct TCM abstract sealed {
			literal int GETCURSEL = TCM_GETCURSEL;
			literal int SETCURSEL = TCM_SETCURSEL;
			literal int SETCURFOCUS = TCM_SETCURFOCUS;
		};
		ref struct TCN abstract sealed {
			literal UINT FIRST = TCN_FIRST;
			literal UINT SELCHANGE = TCN_SELCHANGE;
			literal UINT SELCHANGING = TCN_SELCHANGING;
		};
	};
}