#include "showPicture.h"

Mat img;




/************************************************************************
* 显示装备合成图

************************************************************************/
void showPictureEquipment()
{
	img=imread("..\\photo.png");
	resize(img, img, Size(SIZEH, SIZEH), 0, 0, INTER_LINEAR);
	namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}

/************************************************************************
* 显示灵风作用图

************************************************************************/
void showPicturelingfeng()
{
	img = imread("..\\灵风.jpg");
	resize(img, img, Size(SIZEH, SIZEH), 0, 0, INTER_LINEAR);
	//namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}


/************************************************************************
* 显示拳头图片并缩小

************************************************************************/
void showPicturefist()
{
	img = imread("..\\fist.jpg");
	resize(img, img, Size(20, 20), 0, 0, INTER_LINEAR);
	namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}

/************************************************************************
* 显示坏男人布隆图

************************************************************************/
void showBadMan()
{
	img = imread("..\\坏男人.png");
	resize(img, img, Size(SIZEH, SIZEH), 0, 0, INTER_LINEAR);
	//namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}