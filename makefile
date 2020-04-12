
CC       = g++
CFLAGS   = -Wall
LDFLAGS  = 
OBJFILES = main.o node.o
TARGET   = program.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

run: all
	./program.o