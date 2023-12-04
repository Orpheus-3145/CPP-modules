# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/05 21:08:47 by fra           #+#    #+#                  #
#    Updated: 2023/12/04 16:33:49 by fra           ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

SOURCES := $(wildcard *.cpp)
HEADERS := $(wildcard *.hpp)
NAME := btc

PP := c++
PP_FLAGS := -Wall -Wextra -Werror -Wshadow -Wpedantic -g3 -fsanitize=address

GREEN = \x1b[32;01m
RED = \x1b[31;01m
RESET = \x1b[0m

all: $(NAME)

$(NAME): $(SOURCES) $(HEADERS)
	@$(PP) $(PP_FLAGS) $(DEBUG_FLAGS) $(SOURCES) -o $(NAME)
	@printf "(C++ 09) $(GREEN)Created program $(NAME)$(RESET)\n"

run: all
	@clear
	@./$(NAME) ./input.txt

clean:
	@rm -f $(NAME)
	@rm -f *.replace
	@printf "(C++ 09) $(RED)Removed program $(NAME)$(RESET)\n"


re: clean all	