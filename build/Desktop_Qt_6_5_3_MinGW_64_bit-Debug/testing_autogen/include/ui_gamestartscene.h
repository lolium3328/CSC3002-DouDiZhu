/********************************************************************************
** Form generated from reading UI file 'gamestartscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAMESTARTSCENE_H
#define UI_GAMESTARTSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Gamestartscene
{
public:
    QPushButton *start;
    QLabel *label;
    QPushButton *exit;

    void setupUi(QDialog *Gamestartscene)
    {
        if (Gamestartscene->objectName().isEmpty())
            Gamestartscene->setObjectName("Gamestartscene");
        Gamestartscene->resize(800, 600);
        start = new QPushButton(Gamestartscene);
        start->setObjectName("start");
        start->setGeometry(QRect(300, 290, 200, 50));
        label = new QLabel(Gamestartscene);
        label->setObjectName("label");
        label->setGeometry(QRect(250, 160, 301, 111));
        QFont font;
        font.setPointSize(24);
        label->setFont(font);
        label->setAlignment(Qt::AlignCenter);
        exit = new QPushButton(Gamestartscene);
        exit->setObjectName("exit");
        exit->setGeometry(QRect(300, 350, 200, 50));

        retranslateUi(Gamestartscene);

        QMetaObject::connectSlotsByName(Gamestartscene);
    } // setupUi

    void retranslateUi(QDialog *Gamestartscene)
    {
        Gamestartscene->setWindowTitle(QCoreApplication::translate("Gamestartscene", "Dialog", nullptr));
        start->setText(QCoreApplication::translate("Gamestartscene", "Start", nullptr));
        label->setText(QCoreApplication::translate("Gamestartscene", "TextLabel", nullptr));
        exit->setText(QCoreApplication::translate("Gamestartscene", "Exit", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Gamestartscene: public Ui_Gamestartscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAMESTARTSCENE_H
