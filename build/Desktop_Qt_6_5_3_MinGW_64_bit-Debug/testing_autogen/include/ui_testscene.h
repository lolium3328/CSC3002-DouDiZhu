/********************************************************************************
** Form generated from reading UI file 'testscene.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTSCENE_H
#define UI_TESTSCENE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>

QT_BEGIN_NAMESPACE

class Ui_testscene
{
public:

    void setupUi(QDialog *testscene)
    {
        if (testscene->objectName().isEmpty())
            testscene->setObjectName("testscene");
        testscene->resize(800, 600);

        retranslateUi(testscene);

        QMetaObject::connectSlotsByName(testscene);
    } // setupUi

    void retranslateUi(QDialog *testscene)
    {
        testscene->setWindowTitle(QCoreApplication::translate("testscene", "Dialog", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testscene: public Ui_testscene {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTSCENE_H
