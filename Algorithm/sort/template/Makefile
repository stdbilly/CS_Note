INC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard ./*.cc) 
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
LIBS:= 

CXX:=g++

CXXFLAGS:= -w -g  $(addprefix -I , $(INC_DIR)) $(LIBS) 

EXE:=main.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
