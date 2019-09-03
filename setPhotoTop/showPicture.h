#ifndef _SHOWPICTURE_
#define _SHOWPICTURE_

#include <opencv/cv.h>
#include <opencv/cxcore.h>
#include <opencv/highgui.h>
#include "opencv2\opencv.hpp"
#include <windows.h>
#include <WinUser.h>

using namespace cv;

#define SWITCHCNT  (1)
#define SIZEH  (250)
#define SIZEW  (250)




void showPictureEquipment();
void showPicturelingfeng();
void showNewPlayOne();
void showNewPlayTwo();
void showChampionDropRates();
int getThreadID(int pid);
int getPID(char *target);




#endif // _SHOWPICTURE_



