CC=gcc
CFLAGS=-Wall -g

TARGET=power.exe
OBJECTS=main.o power.o

.INTERMEDIATE: $(OBJECTS)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJECTS)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(TARGET) $(OBJECTS)
.PHONY: clean