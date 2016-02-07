# Define the compiler and the linker. The linker must be defined since
# the implicit rule for linking uses CC as the linker. g++ can be
# changed to clang++.
CXX = g++
CC  = g++

# Define preprocessor, compiler, and linker flags. Uncomment the # lines
# if you use clang++ and wish to use libc++ instead of GNU's libstdc++.
# -g is for debugging.
CPPFLAGS =  -std=c++11
CXXFLAGS =  -O2 -Wall -Wextra -pedantic-errors 
CXXFLAGS += -std=c++11 
CXXFLAGS += -g
LDFLAGS =   -g 
#CPPFLAGS += -stdlib=libc++
#CXXFLAGS += -stdlib=libc++
#LDFLAGS +=  -stdlib=libc++

# Targets
PROGS = dictionary spell

all: dictionary.o spell.o
	$(CXX) $(CXXFLAGS) dictionary.o spell.o -o main
# Targets rely on implicit rules for compiling and linking
gen: 
	$(CXX) $(CXXFLAGS) genTri.cc -o genTri && ./genTri

dic:
	$(CXX) $(CXXFLAGS) dictionary.cc -o dic && ./dic
# Phony targets
.PHONY: all clean dic

# Standard clean
clean:
	rm -f *.o $(PROGS)

