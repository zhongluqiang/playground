SRCS = $(wildcard *.cpp)
TARGET = $(SRCS:.cpp=)

all: $(TARGET)

%:%.cpp
	g++ -Wall $< -o $@

clean:
	rm -fr $(TARGET)