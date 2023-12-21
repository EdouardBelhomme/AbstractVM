/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Push
*/

#include "VirtualMachine.hpp"

void VirtualMachine::push(IOperand *operand)
{
    if (operand == nullptr)
        throw ExceptionError("ERROR: push: No operand");
    m_stack.push_back(operand);
}