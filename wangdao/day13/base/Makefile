SRCS:=$(wildcard *.c)
ELFS:=$(SRCS:%.c=%)
CC:=gcc
all:$(ELFS)

%:%.c
	$(CC) $< -g -o $@ -lpthread
clean:
	rm -rf $(ELFS)

