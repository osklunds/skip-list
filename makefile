
CXX      = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS  = 
OBJFILES = main.o node.o
TARGET   = program.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) *~

run: all
	./program.o