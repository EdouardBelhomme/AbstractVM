/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Div
*/

#include "VirtualMachine.hpp"

void VirtualMachine::div(IOperand *operand)
{
    if (m_stack.size() < 2)
        throw ExceptionError("ERROR: div: Div on empty stack");
    IOperand *op1 = m_stack.back();
    m_stack.pop_back();
    IOperand *op2 = m_stack.back();
    m_stack.pop_back();
    if ((*op1).convertIntoString() == "0")
        throw ExceptionError("ERROR: div: Division divisor is equal to 0");
    m_stack.push_back(*op2 / *op1);
}