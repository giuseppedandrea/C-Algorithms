# Folder name
NAME := $(notdir $(CURDIR))

# Declaration of variables
CC = gcc
CC_FLAGS = -Wall -g
EXEC_WIN = $(NAME)_test.exe
EXEC_LIN = $(NAME)_test.out

# File names
ifeq ($(OS),Windows_NT)
EXEC = $(EXEC_WIN)
else
EXEC = $(EXEC_LIN)
endif

SOURCES = $(wildcard ../../src/$(NAME)/*.c) $(NAME)_test.c

OBJECTS = $(SOURCES:%.c=%.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files for current OS
clean:
	rm -f $(EXEC) $(OBJECTS)

# To remove all generated files
clean_all:
	rm -f $(EXEC_WIN) $(EXEC_LIN) $(OBJECTS)

# To execute program
run:
	./$(EXEC) $(ARGS)
