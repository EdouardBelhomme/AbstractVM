/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** IOperand
*/

#pragma once

#include <string>
#include "EOperandType.hpp"

class IOperand
{
    public:
        virtual std::string convertIntoString() const = 0;

        virtual eOperandType getType() const = 0;

        virtual IOperand *operator+(const IOperand &rhs) const = 0; // Sum
        virtual IOperand *operator-(const IOperand &rhs) const = 0; // Difference
        virtual IOperand *operator*(const IOperand &rhs) const = 0; // Product
        virtual IOperand *operator/(const IOperand &rhs) const = 0; // Quotient
        virtual IOperand *operator%(const IOperand &rhs) const = 0; // Modulo

        virtual ~IOperand() {};

        virtual bool operator!=(const IOperand& rhs) const = 0;

        virtual int getPrecision() const = 0;

    private:
        int m_precision;
};
