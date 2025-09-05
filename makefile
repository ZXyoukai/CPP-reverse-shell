CXX = c++

all: client target

client: client.cpp
	$(CXX) -o client client.cpp

target: target.cpp
	$(CXX) -o target target.cpp
clean:
	rm -f client target
re: clean all

.PHONY: all clean re