include		../buildvars.sh

GLES_DIR	=	./gles

LIB_SRC		=	GCallBack.cpp\
		       	GScreen.cpp\
		       	GVertex.cpp\
		       	GColor.cpp\
		       	GPosition.cpp\
		       	GPrimitive.cpp\
			GLines.cpp

LIB_OBJS	=	$(addsuffix .o, $(basename $(LIB_SRC)))





all:clean $(LIB)

$(LIB):$(LIB_OBJS) 
	$(MK) $(MKFLAGS) $(GLES_DIR)
	$(AR) $(ARFLAGS) $(LIB) $(LIB_OBJS)

clean:
	$(RM) $(RMFLAGS) $(LIB_OBJS)
	$(MK) $(MKFLAGS) $(GLES_DIR) clean

distclean: clean
	$(RM) $(RMFLAGS) $(LIB)
	$(RM) $(RMFLAGS) $(LIB_DIR)

