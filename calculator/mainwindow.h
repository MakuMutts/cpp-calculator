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
    Number memory_cell_ = 0;
    QString input_number_ = "";
    Number active_number_ = 0;
    Calculator calculator_;
    bool new_number_ = true;
    bool delimeter_ = false;
    bool memory_saved_ = false;
    OperationType current_operation_ = OperationType::NO_OPERATION;
    void InputNumber(const QString &number);
    QString OperationSign(OperationType operation);
    void InputOperation(OperationType operation);
    void CalculateResult(Number right_operand);
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
