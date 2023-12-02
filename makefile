# Default target
all: compile

# Target to compile the program
compile: $(PROGRAM_NAME)
	gcc -o $(PROGRAM_NAME) $(PROGRAM_NAME).c

clean:
	rm -f $(PROGRAM_NAME)

