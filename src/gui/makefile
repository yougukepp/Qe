include buildvars.sh

TEST = test

SRC  = test.cpp
OBJS = $(addsuffix .o, $(basename $(SRC)))

all:distclean $(TEST)

$(TEST):$(LIB) $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) $(LIB) -o $(TEST) $(LFLAGS) 

$(LIB):
	$(MK) $(MKFLAGS) $(SRC_DIR)

clean:
	$(RM) $(RMFLAGS) $(OBJS)

distclean: clean
	$(MAKE) $(MKFLAGS) $(SRC_DIR) distclean
	$(RM) $(RMFLAGS) $(TEST)

