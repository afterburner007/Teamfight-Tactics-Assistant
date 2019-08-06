#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "opencv2\opencv.hpp"
#include "showPicture.h"
#include <thread>
using namespace cv;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")


MSG Msg;

HHOOK keybordHook;
HHOOK mouseHook;
DWORD pCopy;
WPARAM wParmCopy;

/************************************************************************
*键盘回调函数

************************************************************************/
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	PKBDLLHOOKSTRUCT p = (PKBDLLHOOKSTRUCT)lParam;
	const char *info = NULL;
	char text[50], data[20];
	wParmCopy = wParam;
	
	if (nCode >= 0)
	{
		if (wParam == WM_KEYDOWN)      info = "普通按鍵按下";
		else if (wParam == WM_KEYUP)        info = "普通按鍵抬起";
		else if (wParam == WM_SYSKEYDOWN)   info = "系統按鍵抬起";
		else if (wParam == WM_SYSKEYUP)     info = "系統按鍵按下";

		ZeroMemory(text, sizeof(text));
		ZeroMemory(data, sizeof(data));

		wsprintf(text, "%s - 键盘码 [%04d], 扫描码 [%04d]  ", info, p->vkCode, p->scanCode);
		wsprintf(data, "按鍵目測為： %c  ", p->vkCode);
		if (p->vkCode == 46 && wParam == WM_KEYDOWN)   //delete
		{
			pCopy = p->vkCode;
			return 1;
		}
		//获得键盘码
		if (p->vkCode == 113 && wParam == WM_KEYDOWN)
		{
			pCopy = p->vkCode;
		}
		else if (p->vkCode == 114 && wParam == WM_KEYDOWN)
		{
			pCopy = p->vkCode;
		}
		else if (p->vkCode == 115 && wParam == WM_KEYDOWN)
		{
			pCopy = p->vkCode;
		}
		else if (p->vkCode == 77 && wParam == WM_KEYDOWN)
		{
			pCopy = p->vkCode;
		}

	}

	return CallNextHookEx(keybordHook, nCode, wParam, lParam);
}


/************************************************************************
*鼠标回调函数

************************************************************************/
LRESULT CALLBACK MouseProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	LPMSLLHOOKSTRUCT p = (LPMSLLHOOKSTRUCT)lParam;
	POINT   pt = p->pt;
	DWORD   mouseData = p->mouseData;
	const char *info = NULL;
	char text[60], pData[50], mData[50];

	if (nCode >= 0)
	{
		if (wParam == WM_MOUSEMOVE)			 info = "鼠标移动　　　　";
		else if (wParam == WM_LBUTTONDOWN)   info = "鼠标【左键】按下";
		else if (wParam == WM_LBUTTONUP)     info = "鼠标【左键】抬起";
		else if (wParam == WM_LBUTTONDBLCLK) info = "鼠标【左键】双击";
		else if (wParam == WM_RBUTTONDOWN)   info = "鼠标【右键】按下";
		else if (wParam == WM_RBUTTONUP)     info = "鼠标【右键】抬起";
		else if (wParam == WM_RBUTTONDBLCLK) info = "鼠标【右键】双击";
		else if (wParam == WM_MBUTTONDOWN)   info = "鼠标【滚轮】按下";
		else if (wParam == WM_MBUTTONUP)     info = "鼠标【滚轮】抬起";
		else if (wParam == WM_MBUTTONDBLCLK) info = "鼠标【滚轮】双击";
		else if (wParam == WM_MOUSEWHEEL)    info = "鼠标【滚轮】滚动";

		ZeroMemory(text, sizeof(text));
		ZeroMemory(pData, sizeof(pData));
		ZeroMemory(mData, sizeof(mData));

		wsprintf(text, "当前状态： %10s   ", info);
		wsprintf(pData, "0x%x - X: [%04d], Y: [%04d]  ", wParam, pt.x, pt.y);
		wsprintf(mData, "附带数据： %16u   ", mouseData);
	}

	return CallNextHookEx(mouseHook, nCode, wParam, lParam);
}

/************************************************************************
*全局键盘、鼠标监视

************************************************************************/
void  globalMonitoringKeyboardAndMouse()
{
	while (1)
	{
		if (GetMessage(&Msg, NULL, 0, 0) > 0)
		{
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}
		waitKey(1000);
	}
}




int main(void)
{
	int numCnt=0;
	int flagToHide=0;
	//init
	pCopy=0;
	wParmCopy = 0;

	keybordHook = SetWindowsHookEx(
		WH_KEYBOARD_LL,     // 监听类型【键盘】
		KeyboardProc,       // 处理函数
		NULL,                  // 当前实例句柄
		NULL                  // 监听窗口句柄(NULL为全局监听)
		);
	mouseHook = SetWindowsHookEx(
		WH_MOUSE_LL,      // 监听类型【鼠标】
		MouseProc,        // 处理函数
		NULL,                // 当前实例句柄
		NULL              // 监听窗口句柄(NULL为全局监听)
		);


	showPictureEquipment();

	std::thread  monitor(globalMonitoringKeyboardAndMouse);
	monitor.detach();

	HWND hq;

	hq = FindWindow(NULL, "show");   /*获取句柄*/

	if (hq == 0)
	{
		MessageBox(NULL, "true", "remain", MB_OK);
		return 0;
	}

	LONG lStyle = ::GetWindowLong(hq, GWL_STYLE);
	SetWindowLong(hq, GWL_STYLE, lStyle & ~WS_CAPTION);   //将当前窗口风格与无窗口标题栏属性取并

	while (1)
	{
		if (pCopy == 113)   //F2
		{
			showPicturelingfeng();
			flagToHide = 0;
		}
		else if (pCopy == 114)  //F3
		{
			showPictureEquipment();
			flagToHide = 0;
		}
		else if (pCopy == 115)  //F4
		{
			showBadMan();
			flagToHide = 0;
		}
		else if (pCopy==77)		//M
		{
			SetWindowPos(hq, HWND_BOTTOM, 0, 0, 0, 0, SWP_NOACTIVATE | SWP_FRAMECHANGED);
			flagToHide = 1;
		}
		else if (pCopy==46)
		{
			destroyWindow("show");
			exit(1);
		}
		else
		{
			SetWindowPos(hq, HWND_TOPMOST, 0, 0, SIZEH, SIZEH, SWP_NOACTIVATE | SWP_FRAMECHANGED);
			numCnt = 0;
		}
		if (numCnt>SWITCHCNT)
		{
			pCopy = 0;
		}
		waitKey(100);
		if (flagToHide == 0)
		{
			numCnt++;
		}

	}


	return  0;
}

