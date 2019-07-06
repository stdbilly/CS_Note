SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
ELF:=thread_pool_server
CC:=gcc
CFLAGS:=-Wall
$(ELF):$(OBJS)
	gcc -o $@ $^ -pthread
clean:
	rm -rf $(OBJS) $(ELF)
