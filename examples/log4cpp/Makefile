CPP_SRCS = $(wildcard *.cc)
TARGET = $(CPP_SRCS:.cc=)

CPPFLAGS = -Wall -std=c++11
LD_FLAGS = -llog4cpp -lpthread

all: $(TARGET)

%: %.cc
	g++ $^ $(CPPFLAGS) -o $@ $(LD_FLAGS)
clean:
	rm -fr $(TARGET) log.txt