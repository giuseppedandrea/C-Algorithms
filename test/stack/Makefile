# Folder name
NAME := $(notdir $(CURDIR))

# Declaration of variables
CC = gcc
CC_FLAGS = -Wall -g

# File names
EXEC = $(NAME)_test.out
SOURCES = $(wildcard ../../src/$(NAME)/*.c) $(NAME)_test.c
OBJECTS = $(SOURCES:%.c=%.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC)

# To obtain object files
%.o: %.c
	$(CC) -c $(CC_FLAGS) $< -o $@

# To remove generated files
clean:
	rm -f $(EXEC) $(OBJECTS)

# To execute program
run:
	./$(EXEC) $(ARGS)