/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Print
*/

#include "VirtualMachine.hpp"
#include "Factory.hpp"

void VirtualMachine::print(IOperand *operand)
{
    if (m_stack.empty()) {
        throw ExceptionError("ERROR: print: Print on empty stack");
    }
    operand = m_stack.back();
    if (operand->getType() != Int8) {
        throw ExceptionError("ERROR: print: Top operand on stack is not an 8-bit integer");
    }
    int asciiValue = std::stoi(operand->convertIntoString());
    char character = static_cast<char>(asciiValue);
    std::cout << character << std::endl;
}