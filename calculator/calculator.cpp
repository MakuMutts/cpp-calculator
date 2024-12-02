
#include <iostream>
#include <string>
#include <cmath>
#include "calculator.h"

bool ReadNumber(Number& result){
    if(!(std::cin >> result)){
        std::cerr << "Error: Numeric operand expected" << std::endl;
        return false;
    }
    else{
        return result;
    }
    return true;
}

bool RunCalculatorCycle(){
    Number result;
    if(!ReadNumber(result)){
        return false;
    }
    else {
        Number Memory = 0;
        bool is_memory = false;
        
        for(int i = 0; i <= 1000; ++i){
                std::string sign;
                std::cin >> sign;
            
                if(sign =="+"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Numeric operand expected" << std::endl;
                        break;
                    }
                    else{
                        result += the_number_read;}
                }
            
                else if(sign =="-"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Unknown token " << std::endl;
                        break;
                    }
                    else{
                        result -= the_number_read;}
                }
            
                else if(sign =="*"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Unknown token " << std::endl;
                        break;
                    }
                    else{
                        result *= the_number_read;}
                }
            
                else if(sign =="/"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Unknown token " << std::endl;
                        break;
                    }
                    else{
                        result /= the_number_read;}
                }
            
                else if(sign =="**"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Unknown token " << std::endl;
                        break;
                    }
                    else{
                        result = pow(result,the_number_read);}
                }
            
                else if(sign == "="){
                    std::cout << result << std::endl;
                }
            
                else if(sign ==":"){
                    Number the_number_read;
                    std::cin >> the_number_read;
                    if(std::cin.fail()){
                        std::cerr << "Error: Unknown token " << std::endl;
                        break;
                    }
                    else{
                        result = the_number_read;}
                }
            
                else if(sign =="c"){
                    result = 0;
                }
            
                else if(sign =="q"){
                    break;
                }
                else if(sign == "s"){
                    Memory = result;
                    is_memory = true;
                }
                else if(sign == "l"){
                    if(is_memory){
                          result = Memory;
                    } else {
                        std::cerr << "Error: Memory is empty" << std::endl;
                        break;
                    }
                }
                else {
                    std::cerr << "Error: Unknown token " << sign << std::endl;
                    break;
                }

        } 
    }
    return false;
}            
