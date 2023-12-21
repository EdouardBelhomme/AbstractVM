/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Commands
*/

#pragma once

#include <stack>
#include <vector>
#include <string>
#include <iostream>
#include <map>
#include <utility>
#include <algorithm>
#include <memory>
#include <list>
#include "IOperand.hpp"
#include "Exception.hpp"
#include <iomanip>

class Commands {
    public:
        Commands() = default;
        ~Commands() = default;
        void run(std::vector<std::tuple<std::string, eOperandType, std::string>> cmd);
        void runCommand(const std::string& command, IOperand *operand = nullptr);

        void pushInRegister(IOperand *operand, IOperand *index);
        IOperand *getFromRegister(IOperand *);
        IOperand *getRegisterValue();
        void setRegisterValue(IOperand *operand);
        void push(IOperand *operand = nullptr);
        void pop();
        void dump();
        void assertt(IOperand *operand = nullptr);
        void add();
        void sub();
        void mul();
        void div();
        void mod();
        void print();
        void dup();
        void clear();
        void swap();
        void exit();
        void load();
        void store();

    private:
        std::list<IOperand*> m_stack;
        std::map<std::string,IOperand*> m_register;
        static Commands m_commands;

};

typedef std::map<const std::string, void (Commands::*)(IOperand *)> Command;

