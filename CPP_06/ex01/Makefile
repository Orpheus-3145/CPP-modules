# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/05 21:08:47 by fra           #+#    #+#                  #
#    Updated: 2023/10/15 20:00:22 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

SOURCES := $(wildcard *.cpp)
EXE := main

PP := g++
PP_FLAGS := -std=c++98 -Wall -Wextra -Werror -Wshadow -g3 -fsanitize=address

GREEN = \x1b[32;01m
RED = \x1b[31;01m
RESET = \x1b[0m

all: $(SOURCES)
	@$(PP) $(PP_FLAGS) $(DEBUG_FLAGS) $(SOURCES) -o $(EXE)
	@printf "(C++ 06) $(GREEN)Created program $(EXE)$(RESET)\n"

run: all
	@clear
	@./$(EXE) 3

clean:
	@rm -f $(EXE)
	@rm -f *.replace
	@printf "(C++ 06) $(RED)Removed program $(EXE)$(RESET)\n"


re: clean all