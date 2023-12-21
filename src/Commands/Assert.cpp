/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Assert
*/

#include "VirtualMachine.hpp"

void VirtualMachine::assert(IOperand *operand)
{
    if (m_stack.empty()) {
        throw ExceptionError("ERROR: assert: Assert on empty stack");
    }
    IOperand *top = m_stack.back();
    if (top == nullptr) {
        throw ExceptionError("ERROR: assert: Null value on top of stack");
    }
    if (top->getType() != operand->getType() || top->convertIntoString() != operand->convertIntoString()) {
        throw ExceptionError("ERROR: assert: Assert failed");
    }
}