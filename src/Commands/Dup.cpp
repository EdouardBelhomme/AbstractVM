/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Dup
*/

#include "VirtualMachine.hpp"

void VirtualMachine::dup(IOperand *operand)
{
    if (m_stack.empty())
        throw ExceptionError("ERROR: dup: Dup on empty stack");
    m_stack.push_back(m_stack.back());
}