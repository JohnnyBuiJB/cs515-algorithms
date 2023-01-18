# Adapted from https://www.cs.colby.edu/maxwell/courses/tutorials/maketutor/

IDIR =./
CC=clang++
CFLAGS=-I$(IDIR) -std=c++11 -g

ODIR=../obj

LIBS=-lm

$(ODIR)/%.o: %.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

q1_OBJ = q1.o
q1_OBJ_path = $(patsubst %,$(ODIR)/%,$(q1_OBJ))
q1: $(q1_OBJ_path)
	$(CC) -o $@.out $^ $(CFLAGS) $(LIBS)
	# ./$@.out

# keeps make from doing sth with a file named "clean"
.PHONY: clean

clean:
	rm -f $(ODIR)/*.o ./*.out *~ $(INCDIR)/*~
