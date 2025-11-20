/********************************************************************************
** Form generated from reading UI file 'ingamescene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INGAMESCENE_H
#define UI_INGAMESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_InGameScene
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btn_notcall;
    QPushButton *btn_1p;
    QPushButton *btn_2p;
    QPushButton *btn_3p;
    QWidget *horizontalLayoutWidget_2;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *btn_play;
    QPushButton *btn_hint;
    QPushButton *btn_pass;
    QLabel *label_ai1Remain;
    QLabel *label_ai2Remain;

    void setupUi(QDialog *InGameScene)
    {
        if (InGameScene->objectName().isEmpty())
            InGameScene->setObjectName("InGameScene");
        InGameScene->resize(800, 600);
        horizontalLayoutWidget = new QWidget(InGameScene);
        horizontalLayoutWidget->setObjectName("horizontalLayoutWidget");
        horizontalLayoutWidget->setGeometry(QRect(210, 300, 414, 80));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        btn_notcall = new QPushButton(horizontalLayoutWidget);
        btn_notcall->setObjectName("btn_notcall");
        btn_notcall->setMinimumSize(QSize(100, 40));
        btn_notcall->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(btn_notcall);

        btn_1p = new QPushButton(horizontalLayoutWidget);
        btn_1p->setObjectName("btn_1p");
        btn_1p->setMinimumSize(QSize(100, 40));
        btn_1p->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(btn_1p);

        btn_2p = new QPushButton(horizontalLayoutWidget);
        btn_2p->setObjectName("btn_2p");
        btn_2p->setMinimumSize(QSize(100, 40));
        btn_2p->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(btn_2p);

        btn_3p = new QPushButton(horizontalLayoutWidget);
        btn_3p->setObjectName("btn_3p");
        btn_3p->setMinimumSize(QSize(100, 40));
        btn_3p->setMaximumSize(QSize(100, 40));

        horizontalLayout->addWidget(btn_3p);

        horizontalLayoutWidget_2 = new QWidget(InGameScene);
        horizontalLayoutWidget_2->setObjectName("horizontalLayoutWidget_2");
        horizontalLayoutWidget_2->setGeometry(QRect(260, 380, 291, 51));
        horizontalLayout_3 = new QHBoxLayout(horizontalLayoutWidget_2);
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        horizontalLayout_3->setContentsMargins(0, 0, 0, 0);
        btn_play = new QPushButton(horizontalLayoutWidget_2);
        btn_play->setObjectName("btn_play");
        btn_play->setMinimumSize(QSize(80, 30));
        btn_play->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(btn_play);

        btn_hint = new QPushButton(horizontalLayoutWidget_2);
        btn_hint->setObjectName("btn_hint");
        btn_hint->setMinimumSize(QSize(80, 30));
        btn_hint->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(btn_hint);

        btn_pass = new QPushButton(horizontalLayoutWidget_2);
        btn_pass->setObjectName("btn_pass");
        btn_pass->setMinimumSize(QSize(80, 30));
        btn_pass->setMaximumSize(QSize(80, 30));

        horizontalLayout_3->addWidget(btn_pass);

        label_ai1Remain = new QLabel(InGameScene);
        label_ai1Remain->setObjectName("label_ai1Remain");
        label_ai1Remain->setGeometry(QRect(30, 100, 211, 31));
        QFont font;
        font.setPointSize(14);
        label_ai1Remain->setFont(font);
        label_ai2Remain = new QLabel(InGameScene);
        label_ai2Remain->setObjectName("label_ai2Remain");
        label_ai2Remain->setGeometry(QRect(650, 100, 141, 31));
        label_ai2Remain->setFont(font);

        retranslateUi(InGameScene);

        QMetaObject::connectSlotsByName(InGameScene);
    } // setupUi

    void retranslateUi(QDialog *InGameScene)
    {
        InGameScene->setWindowTitle(QCoreApplication::translate("InGameScene", "Dialog", nullptr));
        btn_notcall->setText(QCoreApplication::translate("InGameScene", "NotCall", nullptr));
        btn_1p->setText(QCoreApplication::translate("InGameScene", "1point", nullptr));
        btn_2p->setText(QCoreApplication::translate("InGameScene", "2points", nullptr));
        btn_3p->setText(QCoreApplication::translate("InGameScene", "3points", nullptr));
        btn_play->setText(QCoreApplication::translate("InGameScene", "play", nullptr));
        btn_hint->setText(QCoreApplication::translate("InGameScene", "hint", nullptr));
        btn_pass->setText(QCoreApplication::translate("InGameScene", "pass", nullptr));
        label_ai1Remain->setText(QCoreApplication::translate("InGameScene", "AI1 left: 17", nullptr));
        label_ai2Remain->setText(QCoreApplication::translate("InGameScene", "AI2 left: 17", nullptr));
    } // retranslateUi

};

namespace Ui {
    class InGameScene: public Ui_InGameScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INGAMESCENE_H
