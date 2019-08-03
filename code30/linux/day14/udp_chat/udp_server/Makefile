SRCS:=$(wildcard *.c)
OBJS:=$(patsubst %.c,%.o,$(SRCS))
ELF:=udp_server
CC:=gcc
CFLAGS:=-g -Wall
$(ELF):$(OBJS)
	gcc -o $@ $^
clean:
	rm -rf $(OBJS) $(ELF)
