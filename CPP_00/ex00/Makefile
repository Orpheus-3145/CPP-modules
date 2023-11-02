# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/09/27 17:26:06 by fra           #+#    #+#                  #
#    Updated: 2023/10/13 17:01:43 by faru          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash
NAME := megaphone.cpp
EXE := megaphone

PP := g++
PP_FLAGS := -std=c++98 -Wall -Wextra -Werror

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(NAME)
	@$(PP) $(PP_FLAGS) $(NAME) -o $(EXE)
	@printf "(C++ 00) $(GREEN)Created program $(EXE)$(RESET)\n"

run: all
	@clear
	@./$(EXE) "halo"

clean:
	@rm -f $(EXE)
	@printf "(C++ 00) $(RED)Removed program $(EXE)$(RESET)\n"

fclean: clean

re: fclean all

.PHONY: run, all, clean, fclean, re
