include		../../buildvars.sh

PREP		=	mk_lib_dir

LIB_SRC		=	GEgl.cpp GShader.cpp GProgram.cpp
LIB_OBJS	=	$(addsuffix .o, $(basename $(LIB_SRC)))


all:clean $(LIB)

$(LIB):$(PREP) $(LIB_OBJS)
	$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJS)

$(PREP):
	if [ ! -e $(LIB_DIR) ]; then mkdir $(LIB_DIR); fi

$(LIB_OBJS):$(LIB_SRC)

clean:
	$(RM) $(RMFLAGS) $(LIB_OBJS)

distclean: clean
	$(RM) $(RMFLAGS) $(LIB)
	$(RM) $(RMFLAGS) $(LIB_DIR)
