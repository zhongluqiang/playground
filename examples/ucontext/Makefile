SRCS = $(wildcard *.c)
TARGET=$(SRCS:.c=)

all: $(TARGET)

%:%.c
	gcc -g -Wall $< -o $@

clean:
	rm -fr $(TARGET)