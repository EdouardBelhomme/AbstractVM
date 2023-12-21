/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** ParseFile
*/

#include "Parser.hpp"
#include "Exception.hpp"
#include <algorithm>
#include <iterator>

void Parser::parseFile(std::string fileName)
{
    std::ifstream file(fileName);
    std::string delimiter = " ";
    std::string line;
    std::string type;
    std::string value;
    eOperandType typeEnum;

    if (file.is_open() == false)
        throw ExceptionError("ERROR: Failed to open file: " + fileName  );
    while (file && line != "exit") {
        getline(file, line);
        if (line.find("\t") != std::string::npos)
            replace(line.begin(), line.end(), '\t' , ' ');
        line = trimLine(line);
        if (line.empty() || line[0] == ';')
            continue;
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
            if (m_value.back() == '\r')
                m_value.pop_back();
            m_value.pop_back();
            m_instructions.emplace_back(m_command, typeEnum, m_value);
            m_value = "";
            typeEnum = None;
        }
        else if (!line.empty()) {
            m_command = line;
            if (m_command.back() == '\r')
                m_command.pop_back();
            m_instructions.push_back({m_command, m_typeMap["NONE"], ""});
        }
    }

    file.close();
    replaceTypes(m_instructions);
}