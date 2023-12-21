/*
** EPITECH PROJECT, 2023
** B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
** File description:
** Main
*/

#include "VirtualMachine.hpp"
#include "Parser.hpp"
#include "Exception.hpp"

int main(int ac, char **av)
{
    Parser parser;
    VirtualMachine vm;

    if (ac > 2)
        return 84;
    if (ac < 2)
        parser.parseInput();
    if (ac == 2)
        parser.parseFile(av[1]);
    try {
        vm.run(parser.getInstructions());
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}