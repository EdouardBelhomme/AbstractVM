/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Operators
*/

#include "IOperands.hpp"
#include "Factory.hpp"

IOperand* Factory::operator+(const IOperand& rhs) const
{
    if (rhs.getType() != m_type) {
        throw std::runtime_error("ERROR: Operands have different types");
    }

    long double left = std::stold(m_value);
    long double right = std::stold(rhs.convertIntoString());
    long double result = left + right;

    std::ostringstream oss;
    oss << result;
    std::string str_result = oss.str();

    return createOperand(m_type, str_result);
}

IOperand* Factory::operator-(const IOperand& rhs) const
{
    if (rhs.getType() != m_type) {
        throw std::runtime_error("ERROR: Operands have different types");
    }

    long double left = std::stold(m_value);
    long double right = std::stold(rhs.convertIntoString());
    long double result = left - right;

    std::ostringstream oss;
    oss << result;
    std::string str_result = oss.str();

    return createOperand(m_type, str_result);
}

IOperand* Factory::operator*(const IOperand& rhs) const
{
    if (rhs.getType() != m_type) {
        throw std::runtime_error("ERROR: Operands have different types");
    }

    long double left = std::stold(m_value);
    long double right = std::stold(rhs.convertIntoString());
    long double result = left * right;

    std::ostringstream oss;
    oss << result;
    std::string str_result = oss.str();

    return createOperand(m_type, str_result);
}

IOperand* Factory::operator/(const IOperand& rhs) const
{
    if (rhs.getType() != m_type) {
        throw std::runtime_error("ERROR: Operands have different types");
    }

    long double left = std::stold(m_value);
    long double right = std::stold(rhs.convertIntoString());

    if (right == 0) {
        throw std::runtime_error("ERROR: Division by zero");
    }

    long double result = left / right;

    std::ostringstream oss;
    oss << result;
    std::string str_result = oss.str();

    return createOperand(m_type, str_result);
}

IOperand* Factory::operator%(const IOperand& rhs) const
{
    if (rhs.getType() != m_type) {
        throw std::runtime_error("ERROR: Operands have different types");
    }

    long double left = std::stold(m_value);
    long double right = std::stold(rhs.convertIntoString());

    if (right == 0) {
        throw std::runtime_error("ERROR: Modulo by zero");
    }

    long double result = std::fmod(left, right);

    std::ostringstream oss;
    oss << result;
    std::string str_result = oss.str();
    

    return createOperand(m_type, str_result);
}

bool IOperand::operator!=(const IOperand& rhs) const {
    return convertIntoString() != rhs.convertIntoString();
}
