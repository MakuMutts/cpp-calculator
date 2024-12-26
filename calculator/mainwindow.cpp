#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent, Calculator calculator)
    : QMainWindow(parent), calculator_{calculator} , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    connect(ui->btn_0,&QPushButton::clicked,this, &MainWindow::digits_numbers);
    connect(ui->btn_1,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_2,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_3,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_4,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_5,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_6,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_7,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_8,&QPushButton::clicked,this,&MainWindow::digits_numbers);
    connect(ui->btn_9,&QPushButton::clicked,this,&MainWindow::digits_numbers);

    connect(ui->btn_addition,&QPushButton::clicked,this,&MainWindow::Addition);
    connect(ui->btn_substruction,&QPushButton::clicked,this,&MainWindow::Substraction);
    connect(ui->btn_multiplicate,&QPushButton::clicked,this,&MainWindow::Multiplication);
    connect(ui->btn_division,&QPushButton::clicked,this,&MainWindow::Division);
    connect(ui->btn_power,&QPushButton::clicked,this,&MainWindow::Power);

    connect(ui->btn_result,&QPushButton::clicked,this,&MainWindow::Result);

    connect(ui->btn_memory_clear,&QPushButton::clicked,this,&MainWindow::MemClear);
    connect(ui->btn_memory_remember,&QPushButton::clicked,this,&MainWindow::MemRemember);
    connect(ui->btn_memory_store,&QPushButton::clicked,this,&MainWindow::MemStore);

    connect(ui->btn_change_sign,&QPushButton::clicked,this,&MainWindow::BtnChangeSign);
    connect(ui->btn_delimeter,&QPushButton::clicked,this,&MainWindow::BtnDelimeter);
    connect(ui->btn_clear,&QPushButton::clicked,this,&MainWindow::BtnClear);
    connect(ui->btn_delete,&QPushButton::clicked,this,&MainWindow::BtnDelete);

}

MainWindow::~MainWindow() {
    delete ui;
}



void MainWindow::digits_numbers(){
    QPushButton *button = (QPushButton *)sender();
    InputNumber(button->text());
}

void MainWindow::Addition(){
    InputOperation(OperationType::ADDITION);
}

void MainWindow::Substraction(){
    InputOperation(OperationType::SUBTRACTION);
}

void MainWindow::Multiplication(){
    InputOperation(OperationType::MULTIPLICATION);
}

void MainWindow::Division(){
    InputOperation(OperationType::DIVISION);
}

void MainWindow::Power(){
    InputOperation(OperationType::POWER);
}

void MainWindow::Result(){
    ShowResult();
}

void MainWindow::MemClear(){
    MemoryClear();
}

void MainWindow::MemRemember(){
    MemoryRemember();
}

void MainWindow::MemStore(){
    MemoryStore();
}

void MainWindow::BtnChangeSign(){
    ChangeSign();
}

void MainWindow::BtnDelimeter(){
    Delimeter();
}

void MainWindow::BtnClear(){
    ClearInput();
}

void MainWindow::BtnDelete(){
    DeleteInput();
}



void MainWindow::InputNumber(const QString &number) {
    if (new_number_ && number != '0') {
        input_number_ = number;
        ui->l_result->setText(input_number_);
        new_number_ = false;
        return;
    };

    if (input_number_.size() == 1 && number == '0')
        return;

    input_number_.push_back(number);
    ui->l_result->setText(input_number_);
}


QString MainWindow::OperationSign(OperationType operation) {
    QString result;

    if(operation == OperationType::ADDITION) {
        result = "+";
    }
    else if(operation == OperationType::SUBTRACTION){
        result = "−";
    }
    else if(operation == OperationType::MULTIPLICATION){
        result = "×";
    }
    else if(operation == OperationType::DIVISION){
        result = "÷";
    }
    else if(operation == OperationType::POWER){
        result = "^";
    }
    return result;
}


void MainWindow::InputOperation(OperationType operation){

    QString formula;
    QString output = "%1 %2";

    active_number_ = input_number_.toDouble();
    calculator_.Set(active_number_);
    current_operation_ = operation;
    formula = output.arg(calculator_.GetNumber()).arg(OperationSign(operation));
    new_number_ = true;
    delimeter_ = false;

    ui->l_formula->setText(formula);


}

void MainWindow::CalculateResult(Number right_operand) {

    if(current_operation_ == OperationType::ADDITION){
        calculator_.Add(right_operand);
        active_number_ = calculator_.GetNumber();
    }
    else if(current_operation_ == OperationType::SUBTRACTION){
        calculator_.Sub(right_operand);
        active_number_ = calculator_.GetNumber();
    }
    else if(current_operation_ == OperationType::MULTIPLICATION){
        calculator_.Mul(right_operand);
        active_number_ = calculator_.GetNumber();
    }
    else if(current_operation_ == OperationType::DIVISION){
        calculator_.Div(right_operand);
        active_number_ = calculator_.GetNumber();
    }
    else if(current_operation_ == OperationType::POWER){
        calculator_.Pow(right_operand);
        active_number_ = calculator_.GetNumber();
    }

    return;
}
void MainWindow::MemoryClear() {
    memory_cell_ = 0;
    ui->l_memory->setText("");
}

void MainWindow::MemoryStore() {
    memory_cell_ = input_number_.toDouble();
    ui->l_memory->setText("M");
}

void MainWindow::MemoryRemember() {
    input_number_ = QString::number(memory_cell_);
    ui->l_result->setText(input_number_);
}

void MainWindow::ClearInput() {
    active_number_ = 0;
    input_number_ = '0';

    delimeter_ = false;
    new_number_ = true;

    calculator_.Set(active_number_);
    ui->l_result->setText(input_number_);
    ui->l_formula->setText("");
}

void MainWindow::ChangeSign() {
    if (input_number_ == "0")
        return;

    if (input_number_.front() == '-') {
        input_number_.remove('-');
    }
    else {
        input_number_.push_front('-');
    }

    ui->l_result->setText(input_number_);
}



void MainWindow::Delimeter() {

    if (new_number_) {
        input_number_ = "0.";
        delimeter_ = true;
        new_number_ = false;
        ui->l_result->setText(input_number_);
        return;
    };

    if (delimeter_)
        return;

    input_number_.push_back('.');
    delimeter_ = true;
    ui->l_result->setText(input_number_);
}

void MainWindow::ShowResult() {
    Number left_operand = active_number_;
    Number right_operand = input_number_.toDouble();
    QString formula;
    QString output = "%1 %2 %3 =";
    if (current_operation_ == OperationType::NO_OPERATION)
        return;

    CalculateResult(right_operand);
    input_number_ = QString::number(active_number_);

    formula = output.arg(left_operand).arg(OperationSign(current_operation_)).arg(right_operand);

    ui->l_formula->setText(formula);
    ui->l_result->setText(input_number_);

    new_number_ = true;
    delimeter_ = false;

    current_operation_ = OperationType::NO_OPERATION;
}

void MainWindow::DeleteInput() {

    if (input_number_.back() == '.')
        delimeter_ = false;

    if (input_number_.size() > 0)
        input_number_.truncate(input_number_.size() - 1);

    if (input_number_.size() == 0)
        input_number_ = "0";

    ui->l_result->setText(input_number_);
}

