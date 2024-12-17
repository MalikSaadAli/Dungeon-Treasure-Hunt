# Compiler and flags
CC = gcc
CFLAGS = -Wall -g

# Object files
OBJS = main.o direction.o attack.o look.o	

# Executable name
TARGET = run

# Default rule to build the executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to compile A.c
main.o: main.c
	$(CC) $(CFLAGS) -c main.c -o main.o

# Rule to compile direction.c
direction.o: direction.c
	$(CC) $(CFLAGS) -c direction.c -o direction.o

# Rule to compile attack.c
attack.o: attack.c
	$(CC) $(CFLAGS) -c attack.c -o attack.o

# Rule to compile look.c
look.o: look.c
	$(CC) $(CFLAGS) -c look.c -o look.o

# Clean rule to delete object files and executable
clean:
	del /f *.o $(TARGET)

# PHONY targets to avoid conflicts with file names
.PHONY: clean
