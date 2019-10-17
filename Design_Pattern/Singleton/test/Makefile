INC_DIR:= ./
SRC_DIR:= ./
SRCS:=$(wildcard *.cc)
OBJS:= $(patsubst %.cc, %.o, $(SRCS))
LIBS:= -lpthread -lboost_thread

CXX:=g++

CXXFLAGS:= -w -g  $(addprefix -I, $(INC_DIR)) $(LIBS) 

EXE:=./singleton.exe

$(EXE):$(OBJS)
	$(CXX) -o $(EXE) $(OBJS) $(CXXFLAGS)

clean:
	rm -rf $(EXE)
	rm -rf $(OBJS)
