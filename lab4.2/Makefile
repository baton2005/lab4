CXX = g++
CXXFLAGS = -Wall -std=c++11
LDFLAGS = -lUnitTest++
TARGET = test

all: $(TARGET)

$(TARGET): test.cpp modAlphakey.cpp
	$(CXX) $(CXXFLAGS) -o $(TARGET) test.cpp modAlphakey.cpp $(LDFLAGS)

clean:
	rm -f $(TARGET)
