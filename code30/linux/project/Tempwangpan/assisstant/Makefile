SRCS:=$(wildcard src/*.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
ELF:=server
CC:=gcc
CFLAGS:=-Wall -lpthread -lrt -I /usr/include/mysql/ -lmysqlclient -lcrypt
$(ELF):$(OBJS)
	gcc $^ -o $@ $(CFLAGS) $(MYSQL)
.PYONY:clean
clean:
	rm -rf $(OBJS) $(ELF)
