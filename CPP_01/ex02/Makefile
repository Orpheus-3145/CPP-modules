# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/09/28 18:59:46 by fra           #+#    #+#                  #
#    Updated: 2023/09/28 19:00:07 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

SOURCE := main.cpp
EXE := main

PP := g++
PP_FLAGS := -std=c++98 -Wall -Wextra -Werror
DEBUG_FLAGS := -g3 -fsanitize=address

GREEN = \x1b[32;01m
RED = \x1b[31;01m
RESET = \x1b[0m

all: $(SOURCE)
	@$(PP) $(PP_FLAGS) $(DEBUG_FLAGS) $(SOURCE) -o $(EXE)
	@printf "(C++ 01) $(GREEN)Created program $(EXE)$(RESET)\n"

run: all
	@clear
	@./$(EXE)

clean:
	@rm -f $(EXE)
	@printf "(C++ 01) $(RED)Removed program $(EXE)$(RESET)\n"


re: clean all

.PHONY: all, run, clean, re
