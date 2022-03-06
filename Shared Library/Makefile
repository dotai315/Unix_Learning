TARGET = lib_share
WORKSPACE=/home/blackally/Desktop/shared_library

CC=gcc
CFLAGS=-g
CFLAGS+=-Wall
CFLAGS+=-Werror

INC=$(WORKSPACE)/inc
INCLUDES=-Iinc

SRC=$(WORKSPACE)/src
MAIN_SRC=$(SRC)/main.c
SRCS_OBJ=$(SRC)/libhello.c $(SRC)/libscan.c

OBJ=$(WORKSPACE)/obj
OBJS=$(patsubst $(SRC)/%.c, $(OBJ)/%.o, $(SRCS_OBJ))

LIB=$(WORKSPACE)/lib

SHARED_LIB=$(LIB)/shared
SHARED_LIB_SRCS=$(SRC)/libhello.c $(SRC)/libscan.c
SHARED_LIB_OBJS=$(patsubst $(SRC)/%.c, $(SHARED_LIB)/%.so, $(SHARED_LIB_SRCS))
SHARED_LIBS=-lhello -lscan


STATIC_LIB=$(LIB)/static
STATIC_LIB_SRCS=$(SRC)/libstring.c
STATIC_LIB_OBJS=$(patsubst $(SRC)/%.c, $(STATIC_LIB)/%.a, $(STATIC_LIB_SRCS))
STATIC_LIBS=-lstring

BIN_DIR=$(WORKSPACE)/bin
BIN=$(BIN_DIR)/$(TARGET)

.PHONY: all
all: $(BIN)

$(BIN): $(SHARED_LIB_OBJS) $(STATIC_LIB_OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $(MAIN_SRC) -L$(STATIC_LIB) -L$(SHARED_LIB) $(SHARED_LIBS) $(STATIC_LIBS)

$(SHARED_LIB)/%.so: $(SRC)/%.c 
	$(CC) $(CFLAGS) $(INCLUDES) -fPIC -shared -o $@ $< -lc

$(STATIC_LIB)/%.a: $(OBJ)/%.o
	ar rcs $@ $<

$(OBJ)/%.o: $(SRC)/%.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

clean:
	rm -rf $(OBJ)/* $(BIN)/*