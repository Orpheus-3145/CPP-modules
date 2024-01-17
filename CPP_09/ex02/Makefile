# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/05 21:08:47 by fra           #+#    #+#                  #
#    Updated: 2024/01/17 17:09:31 by faru          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
NAME := PmergeMe

PP := c++
PP_FLAGS := -Wall -Wextra -Werror -Wshadow -Wpedantic -O3

GREEN = \x1b[32;01m
RED = \x1b[31;01m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	@$(PP) $(PP_FLAGS) $(DEBUG_FLAGS) $(SOURCES) -o $(NAME)
	@printf "(C++ 09) $(GREEN)Created program $(NAME)$(RESET)\n"

run: all
	@clear
	@./$(NAME) `seq 100000 | shuf -n 1000 | tr '\n' ' '`

clean:
	@rm -f $(NAME)
	@rm -f *.replace
	@printf "(C++ 09) $(RED)Removed program $(NAME)$(RESET)\n"

re: clean all	
