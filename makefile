CFLAGS = -std=c89 -nostdinc -nostdlib -ffreestanding -c -O2
CC = gcc
LD = ld

INSTALL = install

TARGET = libc.a
DIR_OBJ = ./obj
OUT_DIR = ./bin

SUBDIR = assert ctype errno float locale math signal stdio stdlib string time _tc86 #setjmp

SRCS = $(wildcard *.c $(foreach fd, $(SUBDIR), $(fd)/*.c))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))
INC_DIR = -I ./_headers

$(DIR_OBJ)/%.o: %.c $(INCS)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(CFLAGS) $(INC_DIR)

$(TARGET): $(OBJS)
	mkdir -p $(OUT_DIR)
	ar cr $(OUT_DIR)/$@ $^

PHONY += clean
clean:
	rm -rf $(OUT_DIR) $(DIR_OBJ)

PHONY += echoes
echoes:
	echo $(DIR_OBJ)
	echo $(SRCS)
	echo $(OBJS)

PHONY += echoes
