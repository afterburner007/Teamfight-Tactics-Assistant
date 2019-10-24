#ifndef TFTHELPER_H
#define TFTHELPER_H

#include <QtWidgets/QMainWindow>
#include "ui_tfthelper.h"

#define WIDTH  (300)
#define HEIGHT (300)


class TFTHelper : public QMainWindow
{
	Q_OBJECT

public:
	TFTHelper(QWidget *parent = 0);
	~TFTHelper();
	void showImage();
private:
	Ui::TFTHelperClass ui;
};

#endif // TFTHELPER_H

