/********************************************************************************
** Form generated from reading UI file 'gamepanel.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMEPANEL_H
#define UI_GAMEPANEL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Gamepanel
{
public:
    QWidget *centralwidget;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *Gamepanel)
    {
        if (Gamepanel->objectName().isEmpty())
            Gamepanel->setObjectName("Gamepanel");
        Gamepanel->resize(800, 600);
        centralwidget = new QWidget(Gamepanel);
        centralwidget->setObjectName("centralwidget");
        Gamepanel->setCentralWidget(centralwidget);
        menubar = new QMenuBar(Gamepanel);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 17));
        Gamepanel->setMenuBar(menubar);
        statusbar = new QStatusBar(Gamepanel);
        statusbar->setObjectName("statusbar");
        Gamepanel->setStatusBar(statusbar);

        retranslateUi(Gamepanel);

        QMetaObject::connectSlotsByName(Gamepanel);
    } // setupUi

    void retranslateUi(QMainWindow *Gamepanel)
    {
        Gamepanel->setWindowTitle(QCoreApplication::translate("Gamepanel", "Gamepanel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gamepanel: public Ui_Gamepanel {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMEPANEL_H
