# Compiler and flags
CC = gcc
CFLAGS = -Wall -g
COVFLAGS = -fprofile-arcs -ftest-coverage

# Executable name
TARGET = toyparser  # Change this to parser_app if that's your intended name

# Source files and object files
SRCS = main.c parser.c utils.c
OBJS = $(SRCS:.c=.o)

# Default target
all: $(TARGET)

# Rule to create the executable (normal build)
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Rule to create object files
%.o: %.c
	$(CC) $(CFLAGS) -c $<

# Coverage target to compile with coverage options
cov: CFLAGS += $(COVFLAGS)
cov: $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS) -lgcov

# Clean target to remove object files, executable, and coverage data
clean:
	rm -f $(OBJS) $(TARGET) *.gcda *.gcno *.gcov

