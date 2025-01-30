#pragma once

#include "calculator.h"
#include "enums.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE


class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget* parent = nullptr, Calculator<ControllerType> calculator = Calculator<ControllerType>());
    ~MainWindow();

    void SetInputText(const std::string& text);
    void SetErrorText(const std::string& text);
    void SetFormulaText(const std::string& text);
    void SetMemText(const std::string& text);
    void SetExtraKey(const std::optional<std::string>& key);


    void SetDigitKeyCallback(std::function<void(int key)> cb);
    void SetProcessOperationKeyCallback(std::function<void(Operation key)> cb);
    void SetProcessControlKeyCallback(std::function<void(ControlKey key)> cb);
    void SetControllerCallback(std::function<void(ControllerType controller)> cb);



private slots:
    void onDigitButtonClicked();
    void onOperationButtonClicked();
    void onControlButtonClicked();
    void onControllerChanged();




private:
    //Number memory_cell_ = 0;
    QString input_number_ = "";
    //Number active_number_ = 0;
    Calculator<ControllerType> calculator_;
    bool new_number_ = true;
    bool delimeter_ = false;
    bool memory_saved_ = false;

    Ui::MainWindow* ui;


    std::function<void(int key)> digit_cb_;
    std::function<void(Operation key)> operation_cb_;
    std::function<void(ControlKey key)> control_cb_;
    std::function<void(ControllerType controller)> controller_cb_;
};
