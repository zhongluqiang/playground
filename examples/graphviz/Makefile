SRCS = $(wildcard *.dot)
TARGET= $(SRCS:.dot=)

all:$(TARGET)

%:%.dot
	dot -Tpng $@.dot -o $@.png

clean:
	rm -fr *.png