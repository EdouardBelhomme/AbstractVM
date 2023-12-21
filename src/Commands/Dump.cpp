/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Dump
*/

#include "VirtualMachine.hpp"
#include "Factory.hpp"
#include <cmath>

static std::string removeTrailingZeros(std::string str)
{
    size_t pos = str.find_last_not_of('0');
    if (pos != std::string::npos && str[pos] == '.') {
        pos--;
    }
    return str.substr(0, pos + 1);
}

static double roundUpIfEndsWithLotsOfNines(double num)
{
    std::string numStr = std::to_string(num);
    int numNines = 0;
    for (int i = numStr.size() - 1; i >= 0 && numStr[i] == '9'; i--) {
        numNines++;
    }
    if (numNines >= 2) {
        return std::round(num * 100) / 100;
    } else if (numNines == 1) {
        return std::round(num * 10) / 10;
    } else {
        return num;
    }
}

void VirtualMachine::dump(IOperand *operand)
{
    for (auto it = m_stack.crbegin(); it != m_stack.crend(); it++) {
        std::stringstream ss;
        ss << std::fixed << std::setprecision((*it)->getPrecision()) << (*it)->convertIntoString();
        std::string str = ss.str();
        size_t pos = str.find_last_not_of('0');
        if (pos != std::string::npos && str[pos] == '.') {
            pos--;
        }
        std::cout << str.substr(0, pos + 1) << std::endl;
    }
}