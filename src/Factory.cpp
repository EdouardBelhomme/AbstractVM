/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Factory
*/

#include "Factory.hpp"
#include "Operand.hpp"
#include "Exception.hpp"
#include <limits>
#include <memory>
#include <iostream>
Factory::Factory()
{
}

Factory::~Factory()
{
}

IOperand* Factory::createOperand(eOperandType type, const std::string& value)
{
    Factory *s_factory;
    switch (type) {
        case eOperandType::Int8:
            return s_factory->createInt8(value);
        case eOperandType::Int16:
            return s_factory->createInt16(value);
        case eOperandType::Int32:
            return s_factory->createInt32(value);
        case eOperandType::Float:
            return s_factory->createFloat(value);
        case eOperandType::Double:
            return s_factory->createDouble(value);
        default:
            throw ExceptionError("ERROR: Invalid operand type");
    }
}

Factory::Operands Factory::m_operands = {
    {eOperandType::Int8, &Factory::createInt8},
    {eOperandType::Int16, &Factory::createInt16},
    {eOperandType::Int32, &Factory::createInt32},
    {eOperandType::Float, &Factory::createFloat},
    {eOperandType::Double, &Factory::createDouble},
};



bool Factory::isAFloat(const std::string &value)
{
    if (value.find('.') != std::string::npos || value.find(',') != std::string::npos)
        return true;
    else
        return false;
}



IOperand *Factory::createInt8(const std::string &value)
{
    IOperand *operand;

    if (isAFloat(value))
        throw ExceptionError("ERROR: Invalid value");
    if (std::stod(value) > std::numeric_limits<int8_t>::max())
        throw ExceptionError("ERROR: Overflow");
    if (std::stod(value) < std::numeric_limits<int8_t>::min()) 
        throw ExceptionError("ERROR: Underflow");
    operand = new Operand<int8_t>(std::stoi(value), eOperandType::Int8);
    return operand;
}

IOperand *Factory::createInt16(const std::string &value)
{
    IOperand *operand;

    if (isAFloat(value))
        throw ExceptionError("ERROR: Invalid value");
    if (std::stod(value) > std::numeric_limits<int16_t>::max())
        throw ExceptionError("ERROR: Overflow");
    if (std::stod(value) < std::numeric_limits<int16_t>::min())
        throw ExceptionError("ERROR: Underflow");
    operand = new Operand<int16_t>(std::stoi(value), eOperandType::Int16);
    return operand;
}

IOperand *Factory::createInt32(const std::string &value)
{
    IOperand *operand;

    if (isAFloat(value))
        throw ExceptionError("ERROR: Invalid value");
    if (std::stod(value) > std::numeric_limits<int32_t>::max())
        throw ExceptionError("ERROR: Overflow");
    if (std::stod(value) < std::numeric_limits<int32_t>::min())
        throw ExceptionError("ERROR: Underflow");
    operand = new Operand<int32_t>(std::stoi(value), eOperandType::Int32);
    return operand;
}

IOperand *Factory::createFloat(const std::string &value)
{
    IOperand *operand;

    if (std::stod(value) > std::numeric_limits<float>::max())
        throw ExceptionError("ERROR: Overflow");
    if (std::stod(value) < std::numeric_limits<float>::min())
        throw ExceptionError("ERROR: Underflow");
    operand = new Operand<float>(std::stof(value), eOperandType::Float);
    return operand;
}

/* IOperand *Factory::createDouble(const std::string &value)
{
    IOperand *operand;

    if (std::stod(value) > std::numeric_limits<double>::max())
        throw ExceptionError("ERROR: Overflow");
    if (std::stod(value) < std::numeric_limits<double>::min())
        throw ExceptionError("ERROR: Underflow");
    operand = new Operand<double>(std::stod(value), eOperandType::Double);
    return operand;
}
 */
IOperand *Factory::createDouble(const std::string &value)
{
    IOperand *operand;

    operand = new Operand<double>(std::stod(value), eOperandType::Double);
    return operand;
}