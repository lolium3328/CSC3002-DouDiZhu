/********************************************************************************
** Form generated from reading UI file 'losescene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSESCENE_H
#define UI_LOSESCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_LoseScene
{
public:
    QLabel *label;

    void setupUi(QDialog *LoseScene)
    {
        if (LoseScene->objectName().isEmpty())
            LoseScene->setObjectName("LoseScene");
        LoseScene->resize(400, 300);
        label = new QLabel(LoseScene);
        label->setObjectName("label");
        label->setGeometry(QRect(60, 100, 301, 81));
        QFont font;
        font.setPointSize(36);
        label->setFont(font);

        retranslateUi(LoseScene);

        QMetaObject::connectSlotsByName(LoseScene);
    } // setupUi

    void retranslateUi(QDialog *LoseScene)
    {
        LoseScene->setWindowTitle(QCoreApplication::translate("LoseScene", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("LoseScene", "YOULOSE\343\200\222\342\226\275\343\200\222", nullptr));
    } // retranslateUi

};

namespace Ui {
    class LoseScene: public Ui_LoseScene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSESCENE_H
