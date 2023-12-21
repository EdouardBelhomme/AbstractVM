/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Mod
*/

#include "VirtualMachine.hpp"

void VirtualMachine::mod(IOperand *operand)
{
    if (m_stack.size() < 2)
        throw ExceptionError("ERROR: mod: Mod on empty stack");
    IOperand *op1 = m_stack.back();
    m_stack.pop_back();
    IOperand *op2 = m_stack.back();
    m_stack.pop_back();
    if ((*op1).convertIntoString() == "0")
        throw ExceptionError("ERROR: mod: Mod operands divisor is equal to 0");
    m_stack.push_back(*op2 % *op1);
}