
SHELL := /bin/bash
SOURCES := $(wildcard *.cpp)
EXE := test

PP := g++
PP_FLAGS := -std=c++98 -Wall -Wextra -Werror -g3 -fsanitize=address

GREEN = \x1b[32;01m
RED = \x1b[31;01m
BLUE = \x1b[34;01m
RESET = \x1b[0m
YELLOW = \x1b[33;01m

all: $(SOURCES)
	@$(PP) $(PP_FLAGS) $(SOURCES) -o $(EXE)
	@printf "(C++ 00) $(GREEN)Created program $(EXE)$(RESET)\n"

run: all
	@clear
	@./$(EXE)

clean:
	@rm -f $(EXE)
	@printf "(C++ 00) $(RED)Removed program $(EXE)$(RESET)\n"

re: clean all

.PHONY: run, all, clean, re