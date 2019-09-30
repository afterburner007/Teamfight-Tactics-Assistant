#include "showPicture.h"
#include <tlhelp32.h>
Mat img;


extern  int processWidth;
extern  int processHigth;
unsigned char showFlag=0;	//确定显示图片的标识符
/************************************************************************
* 显示装备合成图

************************************************************************/
void showPictureEquipment()
{
	img=imread("..\\photo.jpg");
	resize(img, img, Size(processHigth, processWidth), 0, 0, INTER_LINEAR);
	imshow("show", img);
	showFlag = SHOWEQUIPMENT;
}

/************************************************************************
* 显示灵风作用图

************************************************************************/
void showPicturelingfeng()
{
	img = imread("..\\灵风.jpg");
	resize(img, img, Size(processHigth, processWidth), 0, 0, INTER_LINEAR);
	imshow("show", img);
	showFlag = SHOWLINGFENG;
}


/************************************************************************
* 显示拳头图片并缩小

************************************************************************/
void showNewPlayOne()
{
	img = imread("..\\one.jpg");
	resize(img, img, Size(processHigth, processWidth), 0, 0, INTER_LINEAR);
	imshow("show", img);
	showFlag = SHOWNEWPLAYONE;
}

/************************************************************************
* 显示拳头图片并缩小

************************************************************************/
void showNewPlayTwo()
{
	img = imread("..\\two.jpg");
	resize(img, img, Size(processHigth, processWidth), 0, 0, INTER_LINEAR);
	imshow("show", img);
	showFlag = SHOWPLAYTWO;
}

/************************************************************************
* 显示每个等级卡的抽率

************************************************************************/
void showChampionDropRates()
{
	img = imread("..\\championDropRates.jpg");
	resize(img, img, Size(processHigth, processWidth), 0, 0, INTER_LINEAR);
	imshow("show", img);
	showFlag = SHOWCHAMPIONDROPRATES;
}

/************************************************************************
* 重置显示图片大小

************************************************************************/
void resizePicture()
{
	switch (showFlag)
	{
	case SHOWEQUIPMENT:
		showPictureEquipment();
		break;
	case SHOWLINGFENG:
		showPicturelingfeng();
		break;
	case SHOWNEWPLAYONE:
		showNewPlayOne();
		break;
	case SHOWPLAYTWO:
		showNewPlayTwo();
		break;
	case SHOWCHAMPIONDROPRATES:
		showChampionDropRates();
		break;
	default:
		break;
	}
}



/************************************************************************
* 获得线程id

************************************************************************/
int getThreadID(int pid)
{
	THREADENTRY32 te32;
	te32.dwSize = sizeof(te32);
	HANDLE Snapshot_thread = CreateToolhelp32Snapshot(TH32CS_SNAPTHREAD, 0);
	if (Snapshot_thread != INVALID_HANDLE_VALUE)
	{
		if (Thread32First(Snapshot_thread, &te32))
		{
			do
			{
				if (te32.th32OwnerProcessID == pid)
				{
					return te32.th32ThreadID;
				}
			} while (Thread32Next(Snapshot_thread, &te32));
		}
	}
	CloseHandle(Snapshot_thread);
	return 0;
}


/************************************************************************
* 显示进程id

************************************************************************/
int getPID(char *target)
{
	PROCESSENTRY32 pe32;
	MODULEENTRY32 me32;
	HANDLE hProcess, hSnapshot_proc, hSnapshot_mod;
	pe32.dwSize = sizeof(pe32);
	hSnapshot_proc = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (Process32First(hSnapshot_proc, &pe32))
	{
		do
		{
			if (!strcmp(pe32.szExeFile, target))
			{
				return pe32.th32ProcessID;
			}
		} while (Process32Next(hSnapshot_proc, &pe32));
	}
	CloseHandle(hSnapshot_proc);
	return 0;
}