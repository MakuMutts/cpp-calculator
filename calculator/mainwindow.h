#pragma once

#include "calculator.h"

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


enum class OperationType {
    NO_OPERATION,
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    POWER
};


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr, Calculator calculator = Calculator());
    ~MainWindow();


private slots:

    void digits_numbers();
    void Addition();
    void Substraction();
    void Multiplication();
    void Division();
    void Power();
    void Result();
    void MemClear();
    void MemRemember();
    void MemStore();
    void BtnChangeSign();
    void BtnDelimeter();
    void BtnClear();
    void BtnDelete();



private:
    double memory_cell_;
    QString input_number_;
    double active_number_;
    Calculator calculator_;
    bool new_number_ = true;
    bool delimeter_ = false;
    bool memory_saved_ = false;
    OperationType current_operation_ = OperationType::NO_OPERATION;
    void InputNumber(QString  number);
    QString OperationSign(OperationType operation);
    void InputOperation(OperationType operation);
    void CalculateResult(double right_operand);
    void ShowResult();
    void MemoryClear();
    void MemoryStore();
    void MemoryRemember();
    void ClearInput();
    void ChangeSign();
    void Delimeter();
    void DeleteInput();
    Ui::MainWindow* ui;
};
