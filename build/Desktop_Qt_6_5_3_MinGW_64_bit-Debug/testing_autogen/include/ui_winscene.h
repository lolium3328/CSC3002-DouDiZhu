/********************************************************************************
** Form generated from reading UI file 'winscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WINSCENE_H
#define UI_WINSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WinScene
{
public:
    QLabel *label;

    void setupUi(QDialog *WinScene)
    {
        if (WinScene->objectName().isEmpty())
            WinScene->setObjectName("WinScene");
        WinScene->resize(400, 300);
        label = new QLabel(WinScene);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 90, 221, 91));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(WinScene);

        QMetaObject::connectSlotsByName(WinScene);
    } // setupUi

    void retranslateUi(QDialog *WinScene)
    {
        WinScene->setWindowTitle(QCoreApplication::translate("WinScene", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("WinScene", "YOUWIN\357\274\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class WinScene: public Ui_WinScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WINSCENE_H
