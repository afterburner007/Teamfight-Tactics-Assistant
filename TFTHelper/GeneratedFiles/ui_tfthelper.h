/********************************************************************************
** Form generated from reading UI file 'tfthelper.ui'
**
** Created by: Qt User Interface Compiler version 5.9.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TFTHELPER_H
#define UI_TFTHELPER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TFTHelperClass
{
public:
    QWidget *centralWidget;
    QLabel *label;

    void setupUi(QMainWindow *TFTHelperClass)
    {
        if (TFTHelperClass->objectName().isEmpty())
            TFTHelperClass->setObjectName(QStringLiteral("TFTHelperClass"));
        TFTHelperClass->resize(300, 300);
        centralWidget = new QWidget(TFTHelperClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        label = new QLabel(centralWidget);
        label->setObjectName(QStringLiteral("label"));
        //label->setGeometry(QRect(0, 0, 300, 300));
        //label->setPixmap(QPixmap(QString::fromUtf8("../photo.jpg")));
        TFTHelperClass->setCentralWidget(centralWidget);

        retranslateUi(TFTHelperClass);

        QMetaObject::connectSlotsByName(TFTHelperClass);
    } // setupUi

    void retranslateUi(QMainWindow *TFTHelperClass)
    {
        TFTHelperClass->setWindowTitle(QApplication::translate("TFTHelperClass", "TFTHelper", Q_NULLPTR));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TFTHelperClass: public Ui_TFTHelperClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TFTHELPER_H
