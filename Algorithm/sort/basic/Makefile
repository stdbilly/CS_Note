INC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard ./*.c) 
OBJS:= $(patsubst %.c, %.o, $(SRCS))
LIBS:= 

CXX:=gcc

CXXFLAGS:= -w -g  $(addprefix -I , $(INC_DIR)) $(LIBS) 

EXE:=main.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
