/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Parser
*/

#pragma once

#include "EOperandType.hpp"
#include <stdexcept>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <array>
#include <tuple>
#include <map>
#include <iomanip>

class Parser {
    public:
        Parser();
        ~Parser();

        void parseFile(std::string fileName);
        void parseInput();

        std::string trimLine(const std::string &str);
        void replaceTypes(std::vector<std::tuple<std::string, eOperandType, std::string>> &instructions);

        std::string checkType(std::string type);

        std::vector<std::tuple<std::string, eOperandType, std::string>> getInstructions() const;

    private:
        std::string m_command;
        std::vector<std::tuple<std::string, eOperandType, std::string>> m_instructions;
        std::string m_value;
        eOperandType m_type;
        std::map<std::string, eOperandType> m_typeMap {
            {"int8", Int8},
            {"int16", Int16},
            {"int32", Int32},
            {"float", Float},
            {"double", Double},
            {"NONE", None}
        };
        std::vector<std::string> m_listTypes {
            "int8",
            "int16",
            "int32",
            "float",
            "double"
        };
};