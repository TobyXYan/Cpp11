CC = /usr/bin/gcc
CXX = /usr/bin/g++

# -Wall: Allow to print all useful messages provided by Gcc
# -g: Make sure the program can be debugged
# -werror: Transfer all warnings to error and stop compiling when warning occurs
# -fPIC is required for compiling a .so(dll)
# -fvisibility=hidden is required to make methos in .so unexposed
# -pthread: Adds support for multithreading with the pthreads library. This option sets flags for both the preprocessor and linker.

CFLAGS = -Wall -g -std=c++11 -pthread
#CXXFLAGS = -std=c++11
SRCS = main.cc
OBJS = $(SRCS:.cc=.o)
OUTPUT = run

#.PHONY make sure 'make clean' command in terminal works well
# if we don't use .PHONY, file 'clean' can be found
.PHONY: clean

all: $(OUTPUT)
	@echo $(OUTPUT) is sucessfully compiled

$(OUTPUT): $(OBJS)
	$(CXX) $(CFLAGS) -o $@ $^

%.o:%.cc
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) *.o *~ $(OUTPUT)
