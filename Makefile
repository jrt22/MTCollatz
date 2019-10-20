CXX = g++
CXXFLAGS = -std=c++11 -Wall -ftest-coverage -fprofile-arcs

OBJECTS = mt-collatz.o

main: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^ 

testBuild: $(OBJECTS)
	$(CXX) $(CXXFLAGS)  -Itest/catch -o test/test $(OBJECTS) test/test.cpp

test: testBuild
	test/test --success


clean:
	$(RM) *.o *.gch main test/test
