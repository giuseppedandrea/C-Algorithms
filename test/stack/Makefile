# Folder name
NAME := $(notdir $(CURDIR))

# Declaration of constants
CC := gcc
CC_FLAGS := -Wall -g
CC_INC := -I ../../src/$(NAME)
EXEC := $(NAME)_test
ifeq ($(OS),Windows_NT)
EXT := exe
else
EXT := out
endif

SOURCES = $(wildcard ../../src/$(NAME)/*.c) $(NAME)_test.c
OBJECTS = $(SOURCES:%.c=%.o)

# Main target
$(EXEC): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(EXEC).$(EXT)

# To obtain object files
%.o: %.c
	$(CC) $(CC_FLAGS) $(CC_INC) -c $< -o $@

# To remove generated files for current OS
clean:
	rm -f $(EXEC).$(EXT) $(OBJECTS)

# To execute program
run:
	./$(EXEC).$(EXT) $(ARGS)
