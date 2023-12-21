/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Execption
*/

#pragma once

#include <stdexcept>
#include <string>

class ExceptionError : public std::exception {
    public:
        ExceptionError(const std::string &message) : m_message(std::move(message)) {};
        const char *what() const noexcept override {
            return m_message.c_str();
        }

    private:
        std::string m_message;
};
