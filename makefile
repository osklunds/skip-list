
CXX      = g++
CXXFLAGS = -Wall -std=c++17
LDFLAGS  = 
OBJFILES = main.o node.o list.o
TARGET   = program.o

OBJFILES_T = list_tests.o main_tests.o node.o list.o
TARGET_T   = tests.o

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

clean:
	rm -f $(OBJFILES) $(TARGET) $(OBJFILES_T) $(TARGET_T) *~

run: all
	./program.o

test: $(TARGET_T)
	./tests.o

$(TARGET_T): $(OBJFILES_T)
	$(CXX) $(CXXFLAGS) -o $(TARGET_T) $(OBJFILES_T) $(LDFLAGS)