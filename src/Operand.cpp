/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Operand
*/

#include "Operand.hpp"
#include "Factory.hpp"
#include <sstream>
#include <iomanip>
#include <cmath>

template <typename T>
Operand<T>::Operand(T value) : m_value(value)
{
}

template <typename T>
Operand<T>::Operand(T value, eOperandType type) : m_value(value), m_type(type)
{
    switch (type) {
        case eOperandType::Int8:
            m_precision = 0;
            break;
        case eOperandType::Int16:
            m_precision = 0;
            break;
        case eOperandType::Int32:
            m_precision = 0;
            break;
        case eOperandType::Float:
            m_precision = 7;
            break;
        case eOperandType::Double:
            m_precision = 15;
            break;
        default:
            m_precision = 0;
            break;
    }
}

template <typename T>
Operand<T>::~Operand()
{
}

template <typename T>
int Operand<T>::getPrecision() const
{
    return static_cast<int>(getType());
}

template <typename T>
eOperandType Operand<T>::getType() const
{
    return m_type;
}

template <typename T>
std::string Operand<T>::convertIntoString() const
{
    return std::to_string(m_value);
}

template <typename T>
IOperand *Operand<T>::operator+(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    T value = m_value + std::stod(rhs.convertIntoString());
    return Factory::createOperand(type, std::to_string(value));
}

template <typename T>
IOperand *Operand<T>::operator-(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    T value = m_value - std::stod(rhs.convertIntoString());
    return Factory::createOperand(type, std::to_string(value));
}

template <typename T>
IOperand *Operand<T>::operator*(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    T value = m_value * std::stod(rhs.convertIntoString());
    return Factory::createOperand(type, std::to_string(value));
}

template <typename T>
IOperand *Operand<T>::operator/(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    T value = m_value / std::stod(rhs.convertIntoString());
    return Factory::createOperand(type, std::to_string(value));
}

template <typename T>
IOperand *Operand<T>::operator%(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    T value = std::fmod(m_value, std::stod(rhs.convertIntoString()));
    return Factory::createOperand(type, std::to_string(value));
}


template <typename T>
bool Operand<T>::operator!=(const IOperand &rhs) const
{
    eOperandType type = std::max(Operand::getType(), rhs.getType());
    bool value = m_value != std::stod(rhs.convertIntoString());
    return Factory::createOperand(type, value ? "1" : "0");
}
