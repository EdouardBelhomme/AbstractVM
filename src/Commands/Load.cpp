/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Load
*/

#include "VirtualMachine.hpp"

void VirtualMachine::load(IOperand *operand)
{
    if (m_register.empty()) {
        throw ExceptionError("ERROR: load: Register v does not contain a value");
    }
    operand = m_register.rbegin()->second;
    m_stack.push_back(operand);
}