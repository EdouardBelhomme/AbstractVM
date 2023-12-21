/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Operands
*/

#pragma once

#include "IOperand.hpp"
#include "EOperandType.hpp"
#include "Exception.hpp"
#include <map>


class Factory
{
    public:
        Factory();
        ~Factory();

        IOperand *createInt8(const std::string &value);
        IOperand *createInt16(const std::string &value);
        IOperand *createInt32(const std::string &value);
        IOperand *createFloat(const std::string &value);
        IOperand *createDouble(const std::string &value);

        static IOperand* createOperand(eOperandType type, const std::string& value);

        bool isAFloat(const std::string &value);

        eOperandType getType() const;
        std::string convertIntoString() const;

    private:
        std::string m_value;
        int m_precision;
        eOperandType m_type;
        typedef std::map<eOperandType, IOperand *(Factory::*)(const std::string&)> Operands;
        static Operands m_operands;
};
