#include "showPicture.h"

Mat img;
//HWND hq;
void showPictureEquipment()
{
	img=imread("..\\photo.png");
	resize(img, img, Size(200, 200), 0, 0, INTER_LINEAR);
	namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}

void showPicturelingfeng()
{
	img = imread("..\\¡È∑Á.jpg");
	resize(img, img, Size(200, 200), 0, 0, INTER_LINEAR);
	//namedWindow("show", CV_WINDOW_AUTOSIZE);
	imshow("show", img);
}




