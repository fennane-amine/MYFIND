CC=gcc
CFLAGS=-std=c99 -pedantic -Wall -Wextra -Wfloat-equal -Wundef -Wshadow
CFLAGS+=-Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align
CFLAGS+=-Waggregate-return -Wstrict-prototypes -Wmissing-prototypes
CFLAGS+=-Wmissing-declarations -Wnested-externs -Wunreachable-code
CFLAGS+=-Wwrite-strings -g
VPATH=src
INCLUDE=include

FIND=myfind


FIND_SRC=$(wildcard src/*.c)
SRC=$(filter-out $(FIND).c, $(FIND_SRC))
OBJS=$(FIND_SRC:.c=.o)

SRC_STRING=$(wildcard src/my_libstring/*.c)
OBJS_STRING=$(SRC_STRING:.c=.o)

SRC_TREE=$(wildcard src/init_tree/*.c)
OBJS_TREE=$(SRC_TREE:.c=.o)


.PHONY:all clean check
all: $(FIND)

check:$(FIND)
	./tests/testing_Commands.sh

$(FIND):CFLAGS+=-iquote $(INCLUDE)
$(FIND):$(OBJS) $(OBJS_STRING) $(OBJS_TREE)


clean:
	$(RM) src/*.o $(FIND)
	$(RM) src/my_libstring/*.o
	$(RM) src/init_tree/*.o

