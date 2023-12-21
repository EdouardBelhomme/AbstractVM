/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Pop
*/

#include "VirtualMachine.hpp"

void VirtualMachine::pop(IOperand *operand)
{
    if (m_stack.empty())
        throw ExceptionError("ERROR: pop: Pop on empty stack");
    m_stack.pop_back();
}