TARGET = lib_share
WORKSPACE=/home/blackally/Desktop/shared_library

CC=gcc
CFLAGS=-g
CFLAGS+=-Wall

SRC=$(WORKSPACE)/src
SRCS=$(wildcard $(SRC)/*.c)

OBJ=$(WORKSPACE)/obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS))

INC=$(WORKSPACE)/inc
INCLUDES=-I$(INC)

LIB=$(WORKSPACE)/lib
SHARE_LIB=$(LIB)/share

BIN_DIR=bin
BIN=$(WORKSPACE)/$(BIN_DIR)/$(TARGET) $(SHARE_LIB)/hello.so

all:$(BIN)

$(BIN): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $@

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

$(SHARE_LIB)/%.so: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -fPIC -shared -o $@ $< -lc 
clean:
	rm -rf $(BIN_DIR)/* $(OBJ)/*.o 
