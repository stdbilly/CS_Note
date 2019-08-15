SRCS:=$(wildcard *.cc)
OBJS:=$(patsubst %.cc,%.o,$(SRCS))
ELF:=thread.exe
CC:=g++
CFLAGS:=-Wall -lpthread 
$(ELF):$(OBJS)
	g++ $^ -o $@ $(CFLAGS)
.PYONY:clean
clean::
	rm -rf $(OBJS) $(ELF)
