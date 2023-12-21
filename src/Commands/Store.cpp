/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Store
*/

#include "VirtualMachine.hpp"

IOperand* VirtualMachine::getRegisterValue()
{
    if (m_register.find("v") == m_register.end()) {
        throw ExceptionError("getRegisterValue: Register v not found");
    }
    return m_register["v"];
}

void VirtualMachine::setRegisterValue(IOperand *operand)
{
    m_register["v"] = operand;
}

void VirtualMachine::store(IOperand *operand)
{
    if (m_stack.empty()) {
        throw ExceptionError("ERROR: store: Store on empty stack");
    }
    operand = m_stack.back();
    m_stack.pop_back();
    setRegisterValue(operand);
}