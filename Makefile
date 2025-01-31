CC = gcc
CFLAGS = -Wall -Wextra -g
OBJ = simplemain.o queue.o
OBJ_ll = simplemain.o queue_ll.o
TARGET = queue_test

# Default target
all: $(TARGET)

run: $(TARGET)
	./$(TARGET)



$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)


queue_ll: $(OBJ_ll)
	$(CC) $(OBJ_ll) -o $(TARGET)






simplemain.o: simplemain.c queue.h
	$(CC) $(CFLAGS) -c simplemain.c





queue.o: queue.c queue.h
	$(CC) $(CFLAGS) -c queue.c


queue_ll.o: queue_ll.c queue.h
	$(CC) $(CFLAGS) -c queue_ll.c






clean:
	rm -f $(OBJ) $(OBJ_ll) $(TARGET)



rebuild: clean all
