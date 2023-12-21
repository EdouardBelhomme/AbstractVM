/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Parser
*/

#include "Parser.hpp"
#include "VirtualMachine.hpp"

Parser::Parser()
{
}

Parser::~Parser()
{
}

std::vector<std::tuple<std::string, eOperandType, std::string>> Parser::getInstructions() const
{
    return m_instructions;
}

/* eOperandType Parser::checkType(std::string type)
{
    std::transform(type.begin(), type.end(), type.begin(), ::tolower);

    if (m_typeMap.find(type) == m_typeMap.end()) {
        throw std::invalid_argument("ERROR: Invalid type: " + type);
    }

    return m_typeMap[type];
} */

std::string Parser::checkType(std::string type) {
    int ok = 0;

    for (unsigned int i = 0; i < m_listTypes.size(); i++) {
        if (type == m_listTypes[i])
            ok = 1;
    }
    if (ok == 0)
        return ("NONE");
    else
        return (type);
}

std::string Parser::trimLine(const std::string &str)
{
    size_t beginning = str.find_first_not_of(" \t");

    return (beginning == std::string::npos) ? "" : str.substr(beginning);
}

void Parser::replaceTypes(std::vector <std::tuple<std::string, eOperandType, std::string>> &commands)
{
    std::vector<std::string> withoutArgs = {
            "pop",
            "clear",
            "dup",
            "swap",
            "dump",
            "add",
            "sub",
            "mul",
            "div",
            "mod",
            "print",
            "exit"
    };
    std::vector<std::string>::iterator ir;
    unsigned i = 0;
    for (auto it : commands) {
        ir = std::find(withoutArgs.begin(), withoutArgs.end(), std::get<0>(it));
        if (ir != withoutArgs.end())
            std::replace(commands.begin(), commands.end(), it, std::tuple<std::string, eOperandType, std::string>(std::get<0>(it), eOperandType::None, ""));
        i++;
    }
}