
#include "calculator.h"

#include <cmath>



#include <string>
using Number = double;

void Calculator::Set(Number n){
    number_ = n;
}

Number Calculator::GetNumber() const{
    return number_;
}

void Calculator::Add(Number n){
    number_ += n;
}


void Calculator::Sub(Number n){
    number_ -= n;
}

void Calculator::Div(Number n){
    number_ /= n;
}

void Calculator::Mul(Number n){
    number_ *= n;
}

void Calculator::Pow(Number n){
    number_ = pow(number_,n);
}

void Calculator::Save(){
    memory = number_;
    memory_ = true;
}

void Calculator::Load(){
    if(memory_){
        number_ = memory;
    }

}

bool Calculator::HasMem() const{
    if(memory_){
        return true;
    }
    return false;
}

std::string Calculator::GetNumberRepr() const{
    return std::to_string(number_);
}
