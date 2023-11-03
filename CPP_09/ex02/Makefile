# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/05 21:08:47 by fra           #+#    #+#                  #
#    Updated: 2023/11/03 23:58:50 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

SOURCES := $(wildcard *.cpp)
EXE := PmergeMe

PP := c++
PP_FLAGS := -Wall -Wextra -Werror -Wshadow -Wpedantic  -g3 -fsanitize=address

GREEN = \x1b[32;01m
RED = \x1b[31;01m
RESET = \x1b[0m

all: $(EXE)

$(EXE): $(SOURCES)
	@$(PP) $(PP_FLAGS) $(DEBUG_FLAGS) $(SOURCES) -o $(EXE)
	@printf "(C++ 09) $(GREEN)Created program $(EXE)$(RESET)\n"

run: all
	@clear
	@./$(EXE) test2.input

clean:
	@rm -f $(EXE)
	@rm -f *.replace
	@printf "(C++ 09) $(RED)Removed program $(EXE)$(RESET)\n"

re: clean all	