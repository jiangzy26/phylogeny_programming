CC    = g++
CPPFLAGS  = -O3
SRC =    main.cpp chapter_3.cpp Parse_fasta.cpp Parse_phylip.cpp NewickTreeReader.cpp Tree.cpp TreeNode.cpp Parse_to_quartet_trees.cpp RandomNumberGenerator.cpp PureBirthProcess.cpp # inline.cpp #fun_ptr.cpp #main.pp
OBJECTS = main.o chapter_3.o Parse_fasta.o Parse_phylip.o NewickTreeReader.o Tree.o TreeNode.o Parse_to_quartet_trees.o  RandomNumberGenerator.o PureBirthProcess.o# inline.o #fun_ptr.o #main.o
PROGS = test

all: $(PROGS)

test: $(OBJECTS)
	$(CC) $(CPPFLAGS) -o $@ $^

clean:
	rm -f *.o *~ $(PROGS)
