/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** ParseInput
*/

#include "Parser.hpp"
#include <iterator>
#include <algorithm>


void Parser::parseInput()
{
    std::string line;
    std::string delimiter = " ";
    eOperandType typeEnum;
    std::string type;
    std::string value;
    int exit = 0;

    while (line != ";;" && exit == 0) {
        getline(std::cin, line);
        if (line.find("\t") != std::string::npos)
            replace(line.begin(), line.end(), '\t' , ' ');
        line = trimLine(line);
        if (line.length() >= 2) {
            if (line.at(0) == ';' && line.at(1) == ';')
                continue;
        }
        if (line == "exit")
            exit = 1;
        if (line.find(" ") != std::string::npos) {
            m_command = line.substr(0, line.find(delimiter));
            line.erase(0, line.find(delimiter) + delimiter.length());
            type = line.substr(0, line.find("("));
            type.erase(remove_if(type.begin(), type.end(), isspace), type.end());
            type = checkType(type);
            typeEnum = m_typeMap[type];
            line.erase(0, line.find("(") + delimiter.length());
            value = line;
            value.erase(remove_if(value.begin(), value.end(), isspace), value.end());
            m_value = value;
            m_value.pop_back();
            m_instructions.emplace_back(m_command, typeEnum, m_value);
            m_value = "";
            typeEnum = None;
        }
        else if (!line.empty()) {
            m_command = line;
            m_instructions.push_back({m_command, m_typeMap["NONE"], ""});
        }
    }
    while (line != ";;") {
        getline(std::cin, line);
    }
    replaceTypes(m_instructions);
}
