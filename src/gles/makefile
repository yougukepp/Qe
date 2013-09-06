include         ./buildvars 

APPNAME		= test
LFLAGS         += -Bstatic -L./lib -lEs
LIB_ES          = ./lib/libEs.a
LIB_SRC_DIR     = ./src

all:distclean sample.o $(LIB_ES)
	$(LD) -o $(APPNAME) sample.o $(LFLAGS) $(LFLAGS) 
	./test

d:distclean

sample.o : sample.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIB_ES):
	cd $(LIB_SRC_DIR); make

clean:
	rm -rf *.o
	rm -rf $(APPNAME)

distclean:clean
	cd $(LIB_SRC_DIR); make clean

