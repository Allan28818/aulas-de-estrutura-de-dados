EXEC = sort-algorithms.exe

SRC_DIR = .
OUT_DIR = ./output

CC = gcc

CFLAGS = -Wall -Wextra -g3

SRCS = $(SRC_DIR)/$(wildcard *.c)

$(OUT_DIR)/$(EXEC): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(OUT_DIR)/$(EXEC)

run: $(OUT_DIR)/$(EXEC)
	$(OUT_DIR)/$(EXEC)

clean:
	rm -rf $(OUT_DIR)/$(EXEC)

all: $(OUT_DIR)/$(EXEC)