#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "opencv2\opencv.hpp"
#include "showPicture.h"
#include <thread>

using namespace cv;
#pragma comment(linker, "/subsystem:\"windows\" /entry:\"mainCRTStartup\"")



HWND hq;
HHOOK keybordHook;
HHOOK mouseHook;

int   processWidth = SIZEW;
int   processHigth = SIZEH;
/************************************************************************
*键盘回调函数

************************************************************************/
LRESULT CALLBACK KeyboardProc(int nCode, WPARAM wParam, LPARAM lParam)
{
	if (wParam == 113)   //F2
	{
		showPictureEquipment();
		processHigth = SIZEH;
		processWidth = SIZEW;
	}
	else if (wParam == 114)  //F3
	{
		showPicturelingfeng();
		processHigth = SIZEH;
		processWidth = SIZEW;
	}
	else if (wParam == 115)  //F4
	{
		processHigth = SIZEH;
		processWidth = SIZEW;
		showChampionDropRates();
	}
	else if (wParam == 116)	//F5
	{
		processHigth = SIZEH;
		processWidth = SIZEW;
		showNewPlayOne();
	}
	else if (wParam == 117)	//F6
	{

		processHigth = SIZEH;
		processWidth = SIZEW;
		showNewPlayTwo();
	}
	else if (wParam == 77)		//M
	{
		processHigth = 0.0F;
		processWidth = 0.0F;
	}
	else if (wParam == 46)
	{
		UnhookWindowsHookEx(keybordHook);			//卸载hook
		exit(1);
	}

	return CallNextHookEx(keybordHook, nCode, wParam, lParam);
}






int main(void)
{

	showPictureEquipment();

	
	hq = FindWindow(NULL, "show");   /*获取窗口句柄*/

	if (hq == 0)
	{
		MessageBox(NULL, "true", "remain", MB_OK);
		return 0;
	}

	LONG lStyle = ::GetWindowLong(hq, GWL_STYLE);
	SetWindowLong(hq, GWL_STYLE, lStyle & ~WS_CAPTION);   //将当前窗口风格与无窗口标题栏属性取并

	

	HINSTANCE instance = GetModuleHandle("setPhotoTop.exe");			//获取程序句柄
	if (instance == NULL)
	{
		printf("get instance failure!\n");
	}
	DWORD threadId = 0;
	threadId = getThreadID(getPID("setPhotoTop.exe"));
	if (threadId == 0)
	{
		printf("get thread id failure!\n");
	}
	keybordHook = SetWindowsHookEx(						//安装hook
		WH_KEYBOARD,     // 监听类型【键盘】
		KeyboardProc,       // 处理函数
		instance,                  // 当前实例句柄
		threadId                  // 监听窗口句柄(NULL为全局监听)
		);

	while (1)
	{
		SetWindowPos(hq, HWND_TOPMOST, 0, 0, processHigth, processWidth, SWP_NOACTIVATE | SWP_FRAMECHANGED);
		waitKey(100);
	}


	return  0;
}

