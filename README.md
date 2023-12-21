## AbstractVM

- **Binary Name:** abstractVM
- **Language:** C++
- **Compilation:** via Makefile, including re, clean, and fclean rules

## Overview

The goal of this project is to create a simple virtual machine capable of interpreting programs written in a simplified assembler language. The virtual machine acts as a stack machine, performing basic arithmetic operations specified in assembler programs.

## Machines

A virtual machine simulates electronic elements with a program. This project focuses on a simple virtual machine executing basic arithmetic programs.

## Assembler Language

The assembler language consists of instructions, each on a separate line. Key instructions include:
- `push v`: Stack the value `v` (int8, int16, int32, float, or double).
- `pop`: Unstack the top value.
- `clear`: Clear the stack.
- `dump`: Display values on the stack.
- `add`, `sub`, `mul`, `div`, `mod`: Perform arithmetic operations.
- `assert v`: Verify the top stack value.
- `load v`: Copy the value from register `v` to the stack.
- `store v`: Unstack the first value and store it to register `v`.
- `print`: Interpret the top stack value as an ASCII character and display it.
- `exit`: Quit program execution.

## Errors

AbstractVM must raise exceptions and stop program execution in case of lexical, syntactical errors, or specific conditions.

## Execution Examples

Examples of running programs and expected outputs.

## Technical Considerations

- Operand classes must implement the `IOperand` interface.
- Creation of new operands is handled by a `Factory` class.
- Considerations for precision during arithmetic operations.
- The stack container must only contain `IOperand` pointers.

## Ressource Usage

Proper handling and freeing of resources, adhering to the RAII idiom.

## Restrictions

- Forbidden use of external libraries (except STL).
- STL usage encouraged.
- Specific guidelines for function implementations and coding style.
