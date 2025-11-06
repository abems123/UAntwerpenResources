#--- the location of the test includes; YOU MIGHT NEED TO MODIFY THESE
INCL =		..\gtest\include
#--- the location of the test libraries; YOU MIGHT NEED TO MODIFY THESE
TLIBPATH =	-L..\gtest\lib
TLIBS =		-lgtest -lgtest_main


CXXFLAGS =	-O0 -g3 -Wall -fmessage-length=0 -pthread -I$(INCL) 

OBJS =		TicTacToe.o

SRCS =		TicTacToe.cpp \
			TicTacToeMain.cpp \
			TicTacToeTests.cpp
TARGET =	TicTacToeMain	TicTacToeTests

#--- primary target
.PHONY : all
all : $(TARGET)


#--- compiler targets
TicTacToeMain : $(OBJS) TicTacToeMain.o
	$(CXX) $(CXXFLAGS) -o $@ $(OBJS) TicTacToeMain.o

TicTacToeTests : $(OBJS) TicTacToeTests.o
	$(CXX) $(CXXFLAGS) $(TLIBPATH) -o $@ $(OBJS) TicTacToeTests.o $(TLIBS)

%.o : %.cpp %.h
	$(CXX) $(CXXFLAGS) -c -o $@ $<



#--- non-file targets
.PHONY : clean
clean :
	rm -f *.o $(TARGET)

.PHONY : depend
depend :
	g++ -MM -I $(INCL) $(SRCS)

.PHONY : echo
echo :
	@echo CXXFLAGS = $(CXXFLAGS)
	@echo CXX = $(CXX)
	@echo LDFLAGS = $(LDFLAGS)
	@echo INCL = $(INCL)
	@echo TLIBPATH = $(TLIBPATH)
	@echo TLIBS = $(TLIBS)


.PHONY : sourcestar
sourcestar :
	tar -cvf TicTacToe.tar *.h *.cpp Makefile
	
.PHONY : sourceszip
sourceszip :
	zip -q -r TicTacToe.zip *.h *.cpp Makefile
#--zip quietly and recursively

