CC = afl-gcc-fast
CFLAGS = -Wall -I../toyparser

LIBPARSER_DIR = ../toyparser
HARNESS_SRC = harness.c

LIBPARSER_SRC = $(LIBPARSER_DIR)/parser.c $(LIBPARSER_DIR)/utils.c
HARNESS = harness
HARNESS_ASAN = $(HARNESS)-asan

all: $(HARNESS)

$(HARNESS): $(HARNESS_SRC) $(LIBPARSER_SRC)
	$(CC) $(CFLAGS) $(HARNESS_SRC) $(LIBPARSER_SRC) -o $(HARNESS)

asan: CFLAGS += -fsanitize=address
asan: $(HARNESS_ASAN)

$(HARNESS_ASAN): $(HARNESS_SRC) $(LIBPARSER_SRC)
	$(CC) $(CFLAGS) $(HARNESS_SRC) $(LIBPARSER_SRC) -o $(HARNESS_ASAN)

clean:
	rm -f $(HARNESS) $(HARNESS_ASAN)

.PHONY: all clean asan

