ROOT            = 	/home/lucid/test/gui

INC_DIR		=	$(ROOT)/include/
SRC_DIR		=	$(ROOT)/src/
LIB_DIR		=	$(ROOT)/lib/

LIB		=	$(LIB_DIR)libGui.a

GCC		=	gcc
CXX		=	g++ 
AR		=	ar
LFLAGS		=       -Wl,-Bdynamic -L/usr/lib/i386-linux-gnu/mesa-egl/ -lm -lX11 -lEGL -lGLESv2
CFLAGS		=	-I$(INC_DIR) -I$(INC_DIR)gles -DEGL_USE_X11 -DG_DEBUG
CXXFLAGS	=	$(CFLAGS)
ARFLAGS		= 	r
MK		=	make
MKFLAGS         =       -C

RM              =       rm
RMFLAGS         =       -rf


