/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** VirtualMachine
*/

#include "VirtualMachine.hpp"
#include <algorithm>

VirtualMachine::VirtualMachine()
{
    this->m_commands = {
        {"push", &VirtualMachine::push},
        {"pop", &VirtualMachine::pop},
        {"dump", &VirtualMachine::dump},
        {"assert", &VirtualMachine::assert},
        {"add", &VirtualMachine::add},
        {"sub", &VirtualMachine::sub},
        {"mul", &VirtualMachine::mul},
        {"div", &VirtualMachine::div},
        {"mod", &VirtualMachine::mod},
        {"print", &VirtualMachine::print},
        {"dup", &VirtualMachine::dup},
        {"clear", &VirtualMachine::clear},
        {"swap", &VirtualMachine::swap},
        {"exit", &VirtualMachine::exit},
        {"load", &VirtualMachine::load},
        {"store", &VirtualMachine::store},
    };
}

VirtualMachine::~VirtualMachine()
{

}

void VirtualMachine::executeCommand(const std::string& command, IOperand *operand)
{
   void (VirtualMachine::*func)(IOperand *) = m_commands[command];
    return (this->*func)(operand);
}

void VirtualMachine::run(std::vector<std::tuple<std::string, eOperandType, std::string>> cmd)
{
    bool exitCmdExecuted = false;
    for (auto& [command, type, value] : cmd)
    {
        if (m_commands.count(command) == 0)
            throw ExceptionError("Unknown command " + command);
        if (command == "exit") {
            exitCmdExecuted = true;
            break;
        }
        if (type != eOperandType::None)
            executeCommand(command, Factory::createOperand(type, value));
        else
            executeCommand(command, nullptr);
    }
    if (!exitCmdExecuted)
        throw ExceptionError("Missing exit command");
}