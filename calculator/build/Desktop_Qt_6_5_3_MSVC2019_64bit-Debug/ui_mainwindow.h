/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.5.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QPushButton *btn_8;
    QPushButton *btn_delete;
    QPushButton *btn_clear;
    QPushButton *btn_7;
    QPushButton *btn_4;
    QHBoxLayout *horizontalLayout;
    QLabel *l_memory;
    QLabel *l_result;
    QPushButton *btn_1;
    QPushButton *btn_addition;
    QPushButton *btn_6;
    QPushButton *btn_memory_remember;
    QPushButton *btn_memory_store;
    QPushButton *btn_change_sign;
    QPushButton *btn_power;
    QPushButton *btn_0;
    QLabel *l_formula;
    QPushButton *btn_result;
    QPushButton *btn_9;
    QPushButton *btn_delimeter;
    QPushButton *btn_memory_clear;
    QPushButton *btn_substruction;
    QPushButton *btn_3;
    QPushButton *btn_2;
    QPushButton *btn_5;
    QPushButton *btn_division;
    QPushButton *btn_multiplicate;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->setEnabled(true);
        MainWindow->resize(369, 669);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(14);
        MainWindow->setFont(font);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        btn_8 = new QPushButton(centralwidget);
        btn_8->setObjectName("btn_8");
        btn_8->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_8, 4, 1, 1, 1);

        btn_delete = new QPushButton(centralwidget);
        btn_delete->setObjectName("btn_delete");
        btn_delete->setEnabled(true);
        btn_delete->setMaximumSize(QSize(16777215, 60));
        btn_delete->setFocusPolicy(Qt::TabFocus);

        gridLayout->addWidget(btn_delete, 8, 2, 1, 1);

        btn_clear = new QPushButton(centralwidget);
        btn_clear->setObjectName("btn_clear");
        btn_clear->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_clear, 3, 0, 1, 2);

        btn_7 = new QPushButton(centralwidget);
        btn_7->setObjectName("btn_7");
        btn_7->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_7, 4, 0, 1, 1);

        btn_4 = new QPushButton(centralwidget);
        btn_4->setObjectName("btn_4");
        btn_4->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_4, 6, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        l_memory = new QLabel(centralwidget);
        l_memory->setObjectName("l_memory");
        sizePolicy.setHeightForWidth(l_memory->sizePolicy().hasHeightForWidth());
        l_memory->setSizePolicy(sizePolicy);
        l_memory->setMaximumSize(QSize(16777215, 40));

        horizontalLayout->addWidget(l_memory);

        l_result = new QLabel(centralwidget);
        l_result->setObjectName("l_result");
        l_result->setMaximumSize(QSize(16777215, 40));
        l_result->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(l_result);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 8);

        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 4);

        btn_1 = new QPushButton(centralwidget);
        btn_1->setObjectName("btn_1");
        btn_1->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_1, 7, 0, 1, 1);

        btn_addition = new QPushButton(centralwidget);
        btn_addition->setObjectName("btn_addition");
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(2);
        sizePolicy1.setHeightForWidth(btn_addition->sizePolicy().hasHeightForWidth());
        btn_addition->setSizePolicy(sizePolicy1);
        btn_addition->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_addition, 7, 3, 1, 1);

        btn_6 = new QPushButton(centralwidget);
        btn_6->setObjectName("btn_6");
        btn_6->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_6, 6, 2, 1, 1);

        btn_memory_remember = new QPushButton(centralwidget);
        btn_memory_remember->setObjectName("btn_memory_remember");
        btn_memory_remember->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(btn_memory_remember, 2, 1, 1, 1);

        btn_memory_store = new QPushButton(centralwidget);
        btn_memory_store->setObjectName("btn_memory_store");
        btn_memory_store->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(btn_memory_store, 2, 2, 1, 1);

        btn_change_sign = new QPushButton(centralwidget);
        btn_change_sign->setObjectName("btn_change_sign");
        btn_change_sign->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_change_sign, 3, 2, 1, 1);

        btn_power = new QPushButton(centralwidget);
        btn_power->setObjectName("btn_power");
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(1);
        sizePolicy2.setHeightForWidth(btn_power->sizePolicy().hasHeightForWidth());
        btn_power->setSizePolicy(sizePolicy2);
        btn_power->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(btn_power, 2, 3, 1, 1);

        btn_0 = new QPushButton(centralwidget);
        btn_0->setObjectName("btn_0");
        btn_0->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_0, 8, 1, 1, 1);

        l_formula = new QLabel(centralwidget);
        l_formula->setObjectName("l_formula");
        l_formula->setMaximumSize(QSize(16777215, 40));

        gridLayout->addWidget(l_formula, 0, 3, 1, 1);

        btn_result = new QPushButton(centralwidget);
        btn_result->setObjectName("btn_result");
        sizePolicy1.setHeightForWidth(btn_result->sizePolicy().hasHeightForWidth());
        btn_result->setSizePolicy(sizePolicy1);
        btn_result->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_result, 8, 3, 1, 1);

        btn_9 = new QPushButton(centralwidget);
        btn_9->setObjectName("btn_9");
        btn_9->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_9, 4, 2, 1, 1);

        btn_delimeter = new QPushButton(centralwidget);
        btn_delimeter->setObjectName("btn_delimeter");
        btn_delimeter->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_delimeter, 8, 0, 1, 1);

        btn_memory_clear = new QPushButton(centralwidget);
        btn_memory_clear->setObjectName("btn_memory_clear");
        btn_memory_clear->setMaximumSize(QSize(16777215, 30));

        gridLayout->addWidget(btn_memory_clear, 2, 0, 1, 1);

        btn_substruction = new QPushButton(centralwidget);
        btn_substruction->setObjectName("btn_substruction");
        sizePolicy1.setHeightForWidth(btn_substruction->sizePolicy().hasHeightForWidth());
        btn_substruction->setSizePolicy(sizePolicy1);
        btn_substruction->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_substruction, 6, 3, 1, 1);

        btn_3 = new QPushButton(centralwidget);
        btn_3->setObjectName("btn_3");
        btn_3->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_3, 7, 2, 1, 1);

        btn_2 = new QPushButton(centralwidget);
        btn_2->setObjectName("btn_2");
        btn_2->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_2, 7, 1, 1, 1);

        btn_5 = new QPushButton(centralwidget);
        btn_5->setObjectName("btn_5");
        btn_5->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_5, 6, 1, 1, 1);

        btn_division = new QPushButton(centralwidget);
        btn_division->setObjectName("btn_division");
        sizePolicy1.setHeightForWidth(btn_division->sizePolicy().hasHeightForWidth());
        btn_division->setSizePolicy(sizePolicy1);
        btn_division->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_division, 3, 3, 1, 1);

        btn_multiplicate = new QPushButton(centralwidget);
        btn_multiplicate->setObjectName("btn_multiplicate");
        sizePolicy1.setHeightForWidth(btn_multiplicate->sizePolicy().hasHeightForWidth());
        btn_multiplicate->setSizePolicy(sizePolicy1);
        btn_multiplicate->setMaximumSize(QSize(16777215, 60));

        gridLayout->addWidget(btn_multiplicate, 4, 3, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        QWidget::setTabOrder(btn_memory_clear, btn_memory_remember);
        QWidget::setTabOrder(btn_memory_remember, btn_memory_store);
        QWidget::setTabOrder(btn_memory_store, btn_power);
        QWidget::setTabOrder(btn_power, btn_clear);
        QWidget::setTabOrder(btn_clear, btn_change_sign);
        QWidget::setTabOrder(btn_change_sign, btn_division);
        QWidget::setTabOrder(btn_division, btn_7);
        QWidget::setTabOrder(btn_7, btn_8);
        QWidget::setTabOrder(btn_8, btn_9);
        QWidget::setTabOrder(btn_9, btn_multiplicate);
        QWidget::setTabOrder(btn_multiplicate, btn_4);
        QWidget::setTabOrder(btn_4, btn_5);
        QWidget::setTabOrder(btn_5, btn_6);
        QWidget::setTabOrder(btn_6, btn_substruction);
        QWidget::setTabOrder(btn_substruction, btn_1);
        QWidget::setTabOrder(btn_1, btn_2);
        QWidget::setTabOrder(btn_2, btn_3);
        QWidget::setTabOrder(btn_3, btn_addition);
        QWidget::setTabOrder(btn_addition, btn_delimeter);
        QWidget::setTabOrder(btn_delimeter, btn_0);
        QWidget::setTabOrder(btn_0, btn_delete);
        QWidget::setTabOrder(btn_delete, btn_result);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\232\320\260\320\273\321\214\320\272\321\203\320\273\321\217\321\202\320\276\321\200", nullptr));
        btn_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        btn_delete->setText(QCoreApplication::translate("MainWindow", "\342\214\253", nullptr));
        btn_clear->setText(QCoreApplication::translate("MainWindow", "C", nullptr));
        btn_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        btn_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        l_memory->setText(QCoreApplication::translate("MainWindow", "l_memory", nullptr));
        l_result->setText(QCoreApplication::translate("MainWindow", "l_result", nullptr));
        btn_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        btn_addition->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        btn_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        btn_memory_remember->setText(QCoreApplication::translate("MainWindow", "MR", nullptr));
        btn_memory_store->setText(QCoreApplication::translate("MainWindow", "MS", nullptr));
        btn_change_sign->setText(QCoreApplication::translate("MainWindow", "\302\261", nullptr));
        btn_power->setText(QCoreApplication::translate("MainWindow", "x\312\270", nullptr));
        btn_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        l_formula->setText(QCoreApplication::translate("MainWindow", "l_formula", nullptr));
        btn_result->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        btn_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        btn_delimeter->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        btn_memory_clear->setText(QCoreApplication::translate("MainWindow", "MC", nullptr));
        btn_substruction->setText(QCoreApplication::translate("MainWindow", "\342\210\222", nullptr));
        btn_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        btn_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        btn_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        btn_division->setText(QCoreApplication::translate("MainWindow", "\303\267", nullptr));
        btn_multiplicate->setText(QCoreApplication::translate("MainWindow", "\303\227", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
