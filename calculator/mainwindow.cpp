#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "calculator.h"
//#include "controller.h"
#include <QDebug>

MainWindow::MainWindow(QWidget* parent, Calculator<ControllerType> calculator)
    : QMainWindow(parent), calculator_{calculator} , ui(new Ui::MainWindow){
    ui->setupUi(this);
    ui->l_result->setText("0");
    ui->l_memory->setText("");
    ui->l_formula->setText("");

    connect(ui->cmb_controller,&QComboBox::currentIndexChanged,this, &MainWindow::onControllerChanged);
    connect(ui->btn_0,&QPushButton::clicked,this, &MainWindow::onDigitButtonClicked);
    connect(ui->btn_1,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_2,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_3,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_4,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_5,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_6,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_7,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_8,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);
    connect(ui->btn_9,&QPushButton::clicked,this,&MainWindow::onDigitButtonClicked);

    connect(ui->btn_addition,&QPushButton::clicked,this,&MainWindow::onOperationButtonClicked);
    connect(ui->btn_substruction,&QPushButton::clicked,this,&MainWindow::onOperationButtonClicked);
    connect(ui->btn_multiplicate,&QPushButton::clicked,this,&MainWindow::onOperationButtonClicked);
    connect(ui->btn_division,&QPushButton::clicked,this,&MainWindow::onOperationButtonClicked);
    connect(ui->btn_power,&QPushButton::clicked,this,&MainWindow::onOperationButtonClicked);



    connect(ui->btn_clear,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_memory_clear,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_memory_remember,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_memory_store,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_change_sign,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->tb_extra,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_result,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
    connect(ui->btn_delete,&QPushButton::clicked,this,&MainWindow::onControlButtonClicked);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::SetInputText(const std::string& text) {

    ui->l_result->setText(QString::fromStdString(text));
    ui->l_result->setStyleSheet("");
}

void MainWindow::SetErrorText(const std::string& text) {
    ui->l_result->setText(QString::fromStdString(text));
    ui->l_result->setStyleSheet("color: red;"); // Установка красного цвета
}

void MainWindow::SetFormulaText(const std::string& text) {
    ui->l_formula->setText(QString::fromStdString(text));
}

void MainWindow::SetMemText(const std::string& text) {
    ui->l_memory->setText(QString::fromStdString(text));
}

void MainWindow::SetExtraKey(const std::optional<std::string>& key) {
    if (key) {
        ui->tb_extra->setText(QString::fromStdString(*key));
        ui->tb_extra->show();
    } else {
        ui->tb_extra->hide();
    }
}

void MainWindow::SetDigitKeyCallback(std::function<void(int key)> cb) {

    digit_cb_ = cb;

}

void MainWindow::SetProcessOperationKeyCallback(std::function<void(Operation key)> cb) {
    operation_cb_ = cb;
}

void MainWindow::SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb) {
    control_cb_ = cb;
}

void MainWindow::SetControllerCallback(std::function<void(ControllerType controller)> cb) {
    controller_cb_ = cb;
}

void MainWindow::onDigitButtonClicked() {
    QPushButton *button = (QPushButton *)sender();
    int num = (button->text()).toInt();
    if (digit_cb_) {
        digit_cb_(num);
    }


}

void MainWindow::onOperationButtonClicked() {
    QPushButton *button = (QPushButton *)sender();
    QString txt = button->text();
    Operation op;
    if(txt == "+"){
        op = Operation::PLUS;
    }
    else if(txt == "−"){
        op = Operation::MINUS;
    }
    else if(txt == "×"){
        op = Operation::MULTIPLY;
    }
    else if(txt == "÷"){
        op = Operation::DIV;
    }
    else if(txt == "xʸ"){
        op = Operation::EXP;
    }
    if (operation_cb_) {
       operation_cb_(op);
    }
}

void MainWindow::onControlButtonClicked() {
    ControlKey key;

    QPushButton *button = (QPushButton *)sender();
    QString txt = button->text();

    if(txt == "⌫"){
        key = ControlKey::BACKSPACE;
    }
    else if(txt == "MC"){
        key = ControlKey::MEM_CLEAR;
    }
    else if(txt == "MR"){
        key = ControlKey::MEM_LOAD;
    }
    else if(txt == "MS"){
        key = ControlKey::MEM_SAVE;
    }
    else if(txt == "C"){
        key = ControlKey::CLEAR;
    }
    else if(txt == "±"){
        key = ControlKey::PLUS_MINUS;
    }
    else if(txt == "="){
        key = ControlKey::EQUALS;
    }
    else if(txt == "." || txt == "/"){
        key = ControlKey::EXTRA_KEY;
    }
    if (control_cb_) {
        control_cb_(key);
    }
}

void MainWindow::onControllerChanged() {
    QString text = ui->cmb_controller->currentText();
    ControllerType index;
    if(text == "double"){
        index = ControllerType::DOUBLE;
    }
    else if(text == "float"){
        index = ControllerType::FLOAT;
    }
    else if(text == "uint8_t"){
        index = ControllerType::UINT8_T;
    }
    else if(text == "int"){
        index = ControllerType::INT;
    }
    else if(text == "int64_t"){
        index = ControllerType::INT64_T;
    }
    else if(text == "size_t"){
        index = ControllerType::SIZE_T;
    }
    else if(text == "Rational"){
        index = ControllerType::RATIONAL;
    }


    if (controller_cb_) {
        controller_cb_(index);
    }
}


