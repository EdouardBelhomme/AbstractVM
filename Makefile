##
## EPITECH PROJECT, 2023
## B-SYN-400-BDX-4-1-abstractVM-edouard.belhomme
## File description:
## Makefile
##

NAME	= abstractVM

CC	= g++

RM	= rm -f

SRCS	= ./src/Commands/Add.cpp \
	  ./src/Commands/Assert.cpp \
	  ./src/Commands/Clear.cpp \
	  ./src/Commands/Div.cpp \
	  ./src/Commands/Dump.cpp \
	  ./src/Commands/Dup.cpp \
	  ./src/Commands/Exit.cpp \
	  ./src/Commands/Load.cpp \
	  ./src/Commands/Mod.cpp \
	  ./src/Commands/Mul.cpp \
	  ./src/Commands/Pop.cpp \
	  ./src/Commands/Print.cpp \
	  ./src/Commands/Push.cpp \
	  ./src/Commands/Store.cpp \
	  ./src/Commands/Sub.cpp \
	  ./src/Commands/Swap.cpp \
	  ./src/Factory.cpp \
	  ./src/Parser/ParseFile.cpp \
	  ./src/Parser/ParseInput.cpp \
	  ./src/Parser/Parser.cpp \
	  ./src/VirtualMachine.cpp \
	  ./src/Operand.cpp \
	  ./src/Main.cpp

OBJS	= $(SRCS:.cpp=.o)

CPPFLAGS = -I ./include/
CPPFLAGS += -Wall -Wextra

all: $(NAME)

$(NAME): $(OBJS)
	 $(CC) $(OBJS) -o $(NAME) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
