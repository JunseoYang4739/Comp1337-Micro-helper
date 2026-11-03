# Variables - Customize these for your project
CC = gcc
CFLAGS = -Wall -Wextra -g
TARGET = qt4004

# Automatically find all .c files and convert them to .o filenames
SRCS = $(wildcard *.c)
OBJS = $(SRCS:.c=.o)

# The first target is the default when you run 'make'
all: $(TARGET)

# Rule to link object files and create the final executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Pattern rule to compile .c files into .o object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove generated build files
clean:
	rm -f $(OBJS) $(TARGET)

# Declare targets that don't represent actual files
.PHONY: all clean
