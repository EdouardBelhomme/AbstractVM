/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** VirtualMachine
*/

#pragma once

#include "Exception.hpp"
#include "IOperand.hpp"
#include "Factory.hpp"
#include "Parser.hpp"
#include <list>
#include <map>
#include <utility>
#include <algorithm>
#include <sstream>
#include <iomanip>
#include <limits>

#include <stack>

class VirtualMachine {
    public:
        VirtualMachine();
        ~VirtualMachine();

        void executeCommand(const std::string& command, IOperand *operand);
        void run(std::vector<std::tuple<std::string, eOperandType, std::string>> command);

        VirtualMachine *operator=(const VirtualMachine &rhs);

        void removeTrailingZeros(std::string str);
        double roundUpIfEndsWithLotsOfNines(double num);


        void pushInRegister(IOperand *operand, IOperand *index);
        IOperand *getFromRegister(IOperand *);
        IOperand *getRegisterValue();
        void setRegisterValue(IOperand *operand);
        void push(IOperand *operand = nullptr);
        void pop(IOperand *operand = nullptr);
        void dump(IOperand *operand = nullptr);
        void assert(IOperand *operand = nullptr);
        void add(IOperand *operand = nullptr);
        void sub(IOperand *operand = nullptr);
        void mul(IOperand *operand = nullptr);
        void div(IOperand *operand = nullptr);
        void mod(IOperand *operand = nullptr);
        void print(IOperand *operand = nullptr);
        void dup(IOperand *operand = nullptr);
        void clear(IOperand *operand = nullptr);
        void swap(IOperand *operand = nullptr);
        void exit(IOperand *operand = nullptr);
        void load(IOperand *operand = nullptr);
        void store(IOperand *operand = nullptr);

    private:
        std::map<const std::string, void (VirtualMachine::*)(IOperand *)> m_commands;
        std::list<IOperand*> m_stack;
        std::map<std::string,IOperand*> m_register;
        Factory m_factory;
        std::stack<IOperand*> m_stackRegister;
};
