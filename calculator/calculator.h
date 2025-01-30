
#pragma once

#include <string>
#include <optional>
#include <cmath>
#include "rational.h"
#include "enums.h"
#include "pow.h"
//#include "mainwindow.h"

using Error = std::string;



template<typename Number>
class Calculator{
public:
    //Calculator() {}
    void Set(Number n){
        number_ = n;
    }

    Number GetNumber() const{
        return number_;
    }

    std::optional<Error> Add(Number n){

        number_ += n;
        return std::nullopt;
    }

    std::optional<Error> Sub(Number n){
        number_ -= n;
        return std::nullopt;
    }

    std::optional<Error> Div(Number n){
        //тип является целым числом
        if (std::is_integral_v<Number> && n == 0){
            return "Division by zero";
        }
        else if (std::is_same_v<Number, Rational> && n == 0){
            return "Division by zero";
        }
        number_ /= n;
        return std::nullopt;
    }

    std::optional<Error> Mul(Number n){
        number_ *= n;
        return std::nullopt;
    }

    std::optional<Error> Pow(Number n);


    void Save(){
        memory = number_;
        memory_ = true;
    }

    void Load(){
        if(memory_){
            number_ = *memory;
        }

    }

    bool HasMem() const{
        if(memory_){
            return true;
        }
        return false;
    }

    std::string GetNumberRepr() const{
        return std::to_string(number_);
    }



    bool GetHasMem(){
        return memory_;
    }

private:
    Number number_;
    std::optional<Number> memory;
    bool memory_ = false;

};





template <typename Number>
std::optional<Error> Calculator<Number>::Pow(Number n) {
    if constexpr (std::is_integral_v<Number>) {

        if (n == 0)
            return "Zero power to zero";

        if (n < 0)
            return "Integer negative power";

        number_ = IntegerPow(number_,n);
        return std::nullopt;

    } else if constexpr (std::is_same_v<Number, Rational>){
        if (n == 0)
            return "Zero power to zero";

        if (n.GetDenominator() != 1)
            return "Fractional power is not supported";

        number_ = ::Pow(number_, n);
        return std::nullopt;
    } else {
        if (n == 0)
            return "Zero power to zero";

        number_ = pow(number_, n);
        return std::nullopt;
    }
};
