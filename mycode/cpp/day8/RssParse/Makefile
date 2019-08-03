SRCS:=$(wildcard *.cc *.cpp)
OBJS:=$(patsubst %.cc %.cpp,%.o,$(SRCS))
ELF:=main
CC:=g++
CFLAGS:=-g -Wall
$(ELF):$(OBJS)
	g++ -o $@ $^ -lboost_regex
clean:
	rm -rf $(OBJS) $(ELF)
