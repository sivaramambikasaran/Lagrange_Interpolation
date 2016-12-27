CC		=	g++
CFLAGS		=	-c -Wall -Ofast -I ./ -I ./../cplot/
LDFLAGS		=	
SOURCES		=	./examples/Lagrange.cpp
OBJECTS		=	$(SOURCES:.cpp=.o)
EXECUTABLE	=	./exec/Lagrange

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(LDFLAGS) $(OBJECTS) -o $@

.cpp.o:
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -rf *.out ./examples/*.o ./LAGRANGE/*.o ./exec/*

tar:
	tar -zcvf cplot.tar.gz ./makefile.mk ./exec ./LAGRANGE ./examples ./README.md ./LICENSE.md
