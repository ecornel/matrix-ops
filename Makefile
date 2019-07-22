INCLUDES = -I "./inc"
CXX = g++
CXFLAGS = -g -Wall -std=c++11
OBJS = main.o matrici.o

output: $(OBJS)
	@echo Creating output file...!!!
	$(CXX) $(CXXFLAGS) $(.cpp) -o $@ $(OBJS)

.cpp.o:
	@echo Compiling...!!!
	$(CXX) $(CXXFLAGS) $(INCLUDES) -c $<

# sau detaliat mai jos:
#main.o: main.cpp
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c main.cpp

#matrici.o: matrici.cpp inc/matrici.h
#	$(CXX) $(CXXFLAGS) $(INCLUDES) -c matrici.cpp

clean:
	@echo Cleaning up...!!!
	rm *.o output
