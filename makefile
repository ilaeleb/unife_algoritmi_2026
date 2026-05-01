CC = gcc
CFLAGS = -Iinclude
DEPS = include/utils.h include/sort.h 
COMMON_OBJS = src/utils.o src/sort.o 
BIN_DIR = bin
TARGETS = $(BIN_DIR)/* 

all: $(TARGETS)

$(BIN_DIR)/spritz: src/spritz.o $(COMMON_OBJS)
	$(CC) -o $@ $^

$(BIN_DIR)/main: src/main.o $(COMMON_OBJS)
	$(CC) -o $@ $^

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

clean:
	rm -f src/*.o $(TARGETS)

spritz: $(BIN_DIR)/spritz
main: $(BIN_DIR)/main