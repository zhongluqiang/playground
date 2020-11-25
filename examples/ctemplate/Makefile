CPP_SRCS = $(wildcard *.cc)
OBJS = $(CPP_SRCS:%.cc=%.o)
TARGET = test_ctemplate

CPPFLAGS = -Wall -std=c++11
LD_FLAGS = -lctemplate -lpthread -ldl

all: $(TARGET)

$(TARGET): $(OBJS)
	g++ $^ -o $(TARGET) $(LD_FLAGS)
%.o: %.cc
	g++ $(CPPFLAGS) -c $<
clean:
	rm -fr $(OBJS) $(TARGET)