# **************************************************************************** #
#                                                                              #
#                                                         ::::::::             #
#    Makefile                                           :+:    :+:             #
#                                                      +:+                     #
#    By: fra <fra@student.codam.nl>                   +#+                      #
#                                                    +#+                       #
#    Created: 2023/10/01 02:50:18 by fra           #+#    #+#                  #
#    Updated: 2023/10/19 17:50:46 by faru          ########   odam.nl          #
#                                                                              #
# **************************************************************************** #

SHELL := /bin/bash

NAME := main.cpp
EXE := main
INCLUDE := include
SRC_DIR := sources
OBJ_DIR := objects
HEADERS := $(shell find $(INCLUDE) -type f -name '*.hpp')
SOURCES := $(shell find $(SRC_DIR) -type f -name '*.cpp')
OBJECTS := $(patsubst $(SRC_DIR)%,$(OBJ_DIR)%,$(SOURCES:.cpp=.o))

PP := g++
PP_FLAGS := -std=c++98 -Wall -Wextra -Werror -g3 -fsanitize=address
IFLAGS := -I$(INCLUDE)

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(EXE)

run: all
	@clear
	@./$(EXE)

$(EXE): $(OBJ_DIR) $(OBJECTS) $(NAME)
	@$(PP) $(PP_FLAGS) $(IFLAGS) $(OBJECTS) $(NAME) -o $(EXE)
	@printf "(C++ 00) $(GREEN)Created program $(EXE)$(RESET)\n"

	$(OBJ_DIR):
	@mkdir -p $(OBJ_DIR)
	
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp $(HEADERS)
	@$(PP) $(PP_FLAGS) $(IFLAGS) -c $< -o $@
	@printf "(C++ 00) $(BLUE)Created object $$(basename $@)$(RESET)\n"

clean:
	@for file in $(shell find $(OBJ_DIR) -type f -name '*.o'); do \
		rm -f $$file;	\
		printf "(C++ 00) $(RED)Removed object $$(basename $$file)$(RESET)\n"; \
	done

fclean: clean
	@-rm -f $(EXE)
	@printf "(C++ 00) $(RED)Removed program $(EXE)$(RESET)\n"


re: fclean all

.PHONY: run, all, clean, fclean, re
