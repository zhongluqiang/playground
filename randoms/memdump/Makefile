SRCS = $(wildcard *.c)
OBJS = $(SRCS:%.c=%.o)
TARGET = memdump

CFLAGS = -Wall

all: $(TARGET)

$(TARGET): $(OBJS)
	gcc $^ -o $(TARGET)
%.o: %.c
	gcc $(CFLAGS) -c $<
clean:
	rm -fr $(OBJS) $(TARGET)