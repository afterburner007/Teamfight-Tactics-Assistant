#include "tfthelper.h"

TFTHelper::TFTHelper(QWidget *parent)
	: QMainWindow(parent)
{

	ui.setupUi(this);
	showImage();
}

TFTHelper::~TFTHelper()
{

}


void TFTHelper::showImage()
{
	QImage pictureEquipment("../photo.jpg");
	pictureEquipment = pictureEquipment.scaled(WIDTH, WIDTH, Qt::KeepAspectRatio);
	ui.label->setGeometry(QRect(0, 0, WIDTH, WIDTH));
	ui.label->setPixmap(QPixmap::fromImage(pictureEquipment));
}
