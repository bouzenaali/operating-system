CC=gcc
CFLAGS=-Wall -Wextra -std=c11

# List all your C source files (replace program1.c, program2.c, etc., with your actual filenames)
SRCS=program1.c program2.c program3.c

# Replace .c with .o for object files
OBJS=$(SRCS:.c=.o)

# The default target
all: $(OBJS)

# Rule for compiling C source files to object files
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Clean target to remove compiled files
clean:
	rm -f $(OBJS)

# PHONY target to prevent conflicts with filenames
.PHONY: all clean

