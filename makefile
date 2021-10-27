CFLAGS = -nostdlib -fno-builtin -ffreestanding -g
INC_DIRS = -I ./_headers -I ./_linux
CC = gcc

INSTALL = install

TARGET = libc_plauger.a
DIR_OBJ = ./obj

SUBDIR = assert ctype errno float locale math signal stdio stdlib string time _linux setjmp

SRCS = $(wildcard $(foreach fd, $(SUBDIR), $(fd)/*.c))
OBJS = $(addprefix $(DIR_OBJ)/, $(SRCS:c=o))
NODIR_SRC = $(notdir $(SRCS))

TESTS_SRC = $(wildcard _test/*.c)
GTESTS = $(foreach f, $(TESTS_SRC), gtest/$(notdir $(basename $(f))))
TESTS = $(foreach f, $(TESTS_SRC), test/$(notdir $(basename $(f))))

$(DIR_OBJ)/%.o: %.c $(DIR_OBJ)
	mkdir -p $(@D)
	$(CC) -o $@ -c $< $(INC_DIRS) $(CFLAGS)

$(TARGET): $(OBJS)
	ar cr $@ $^

gtest/%: _test/%.c
	mkdir -p gtest
	$(CC) -o $@ $< -lm

$(DIR_OBJ):
	mkdir -p $@

test/%: _test/%.c $(TARGET)
	mkdir -p test
	$(CC) $(CFLAGS) $(INC_DIRS) -o $@ -fno-asynchronous-unwind-tables -fno-ident -s -Os -static $< $(TARGET)

PHONY += gtest
gtest: $(GTESTS)

PHONY += test
test: $(TESTS)

PHONY += clean
clean:
	rm -rf $(DIR_OBJ)
	rm -f $(TARGET)
	rm -f test

PHONY += echoes
echoes:
	echo $(DIR_OBJ)
	echo $(SRCS)
	echo $(OBJS)
	echo $(GTESTS)

.PHONY = PHONY
