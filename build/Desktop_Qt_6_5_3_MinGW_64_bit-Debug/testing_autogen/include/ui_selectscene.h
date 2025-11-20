/********************************************************************************
** Form generated from reading UI file 'selectscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SELECTSCENE_H
#define UI_SELECTSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_SelectScene
{
public:
    QPushButton *median;
    QPushButton *easy;
    QLabel *label;

    void setupUi(QDialog *SelectScene)
    {
        if (SelectScene->objectName().isEmpty())
            SelectScene->setObjectName("SelectScene");
        SelectScene->resize(800, 600);
        median = new QPushButton(SelectScene);
        median->setObjectName("median");
        median->setGeometry(QRect(300, 300, 200, 50));
        easy = new QPushButton(SelectScene);
        easy->setObjectName("easy");
        easy->setGeometry(QRect(300, 230, 200, 50));
        label = new QLabel(SelectScene);
        label->setObjectName("label");
        label->setGeometry(QRect(240, 80, 301, 111));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);

        retranslateUi(SelectScene);

        QMetaObject::connectSlotsByName(SelectScene);
    } // setupUi

    void retranslateUi(QDialog *SelectScene)
    {
        SelectScene->setWindowTitle(QCoreApplication::translate("SelectScene", "Dialog", nullptr));
        median->setText(QCoreApplication::translate("SelectScene", "median", nullptr));
        easy->setText(QCoreApplication::translate("SelectScene", "easy", nullptr));
        label->setText(QCoreApplication::translate("SelectScene", "select a level", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SelectScene: public Ui_SelectScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SELECTSCENE_H
