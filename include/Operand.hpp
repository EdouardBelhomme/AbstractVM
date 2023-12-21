/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Operand
*/

#pragma once

#include "IOperand.hpp"
#include <string>

template <typename T>
class Operand : public IOperand {
public:
    Operand(T value);
    Operand(T value, eOperandType type);
    ~Operand();

    int getPrecision() const override;
    eOperandType getType() const override;
    std::string convertIntoString() const;

    IOperand *operator+(const IOperand &rhs) const override;
    IOperand *operator-(const IOperand &rhs) const override;
    IOperand *operator*(const IOperand &rhs) const override;
    IOperand *operator/(const IOperand &rhs) const override;
    IOperand *operator%(const IOperand &rhs) const override;
    bool operator!=(const IOperand &rhs) const override;

private:
    T m_value;
    eOperandType m_type;
    int m_precision;
};

template class Operand<int8_t>;
template class Operand<int16_t>;
template class Operand<int32_t>;
template class Operand<float>;
template class Operand<double>;