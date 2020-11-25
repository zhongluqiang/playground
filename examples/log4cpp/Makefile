CPP_SRCS = $(wildcard *.cc)
OBJS = $(CPP_SRCS:%.cc=%.o)
TARGET = test_log4cpp

CPPFLAGS = -Wall -std=c++11
LD_FLAGS = -llog4cpp -lpthread

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ $^ -o $(TARGET) $(LD_FLAGS)
%.o: %.cc
	g++ $(CPPFLAGS) -c $<
clean:
	rm -fr $(OBJS) $(TARGET)