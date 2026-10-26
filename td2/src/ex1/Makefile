CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++17

TARGET = main
OBJS = main.o SearchingAlgorithm.o LinearSearch.o BinarySearch.o JumpSearch.o

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)