CXX = clang++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

contador: main.cpp contador.cpp contador.hpp
	$(CXX) $(CXXFLAGS) main.cpp contador.cpp -o contador

clean:
	rm -f contador