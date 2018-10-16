/********************************************************************************
** Form generated from reading UI file 'test.ui'
**
** Created by: Qt User Interface Compiler version 5.11.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEST_H
#define UI_TEST_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_testClass
{
public:
    QPushButton *P;
    QPushButton *K;

    void setupUi(QWidget *testClass)
    {
        if (testClass->objectName().isEmpty())
            testClass->setObjectName(QStringLiteral("testClass"));
        testClass->resize(600, 400);
        P = new QPushButton(testClass);
        P->setObjectName(QStringLiteral("P"));
        P->setGeometry(QRect(130, 0, 93, 28));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(P->sizePolicy().hasHeightForWidth());
        P->setSizePolicy(sizePolicy);
        K = new QPushButton(testClass);
        K->setObjectName(QStringLiteral("K"));
        K->setGeometry(QRect(0, 0, 93, 28));

        retranslateUi(testClass);

        QMetaObject::connectSlotsByName(testClass);
    } // setupUi

    void retranslateUi(QWidget *testClass)
    {
        testClass->setWindowTitle(QApplication::translate("testClass", "test", nullptr));
        P->setText(QApplication::translate("testClass", "Prim", nullptr));
        K->setText(QApplication::translate("testClass", "Krusukal", nullptr));
    } // retranslateUi

};

namespace Ui {
    class testClass: public Ui_testClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEST_H
