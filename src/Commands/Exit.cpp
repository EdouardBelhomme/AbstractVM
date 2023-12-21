/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Exit
*/

#include "VirtualMachine.hpp"

void VirtualMachine::exit(IOperand *operand)
{
    std::exit(0);
}
