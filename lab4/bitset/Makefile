# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors -Wfatal-errors
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

sb: 
	$(CXX) $(CXXFLAGS) simplebitsettest.cc simplebitset.cc -o simplebitsettest.exe
bt1: 
	$(CXX) $(CXXFLAGS) bitset.cc bitreference.cc bitsettest1.cc -o bt1.exe
bt2: 
	$(CXX) $(CXXFLAGS) bitset.cc bitreference.cc bitsettest2.cc -o bt2.exe


# Phony targets
.PHONY: all clean tr prim date

# Standard clean
clean:
	rm -f *.o $(PROGS)

