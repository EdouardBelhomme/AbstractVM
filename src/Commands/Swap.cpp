/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Swap
*/

#include "VirtualMachine.hpp"

void VirtualMachine::swap(IOperand *operand)
{
    if (m_stack.size() < 2)
        throw ExceptionError("ERROR: swap: Swap on empty stack");
    IOperand *op1 = m_stack.back();
    m_stack.pop_back();
    IOperand *op2 = m_stack.back();
    m_stack.pop_back();
    m_stack.push_back(op1);
    m_stack.push_back(op2);
}