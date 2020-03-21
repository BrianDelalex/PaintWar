 #
# Inc make which define static variable
 #

# Built for link
export BUILDIR	:=	$(realpath .)/build

export MKHELPER_DIR	:=	$(shell realpath .)/mkhelper

export PROJECT_PATH	:=	$(shell realpath .)

# Root diretcories
export ROOT_SRC_DIR	:=	src
export ROOT_INC_DIR	:=	inc

# We Will provide the full path each time
export INCLUDE_DIR	=	-I $(realpath $(ROOT_INC_DIR))

# Binary definition
export PROJECT			:=	PaintWar
# export VERSION			:=	0.1.0
export BIN_EXTENSION	:=	bin
export BINARY			:=	$(PROJECT)-$(TARGET).$(BIN_EXTENSION)

# Norm extension
export EXTENSION_SRC	:=	.cpp
export EXTENSION_OBJ	:=	.o
export EXTENSION_LIB	:=	.a

# Library Flags
LIBFLAGS	=	-lsfml-system	\
				-lsfml-window	\
				-lsfml-network

export LDFLAGS			=	-o	$(PROJECT_PATH)/$(BINARY)							\
							-L	$(TGTSHARED_PLTLIB)/*$(EXTENSION_LIB)		\
							$(LIBFLAGS)

export LDFLAGS_DEBUG	=	--trace					\
							--cref					\
							--print-map				\

export RM	:=	rm -rf

export BUILDEP	:=	dep.d

# Cleaner as possible
export CXXFLAGS	=	$(INCLUDE_DIR)						\
					-MMD								\
					-MF		$(BUILDEP)					\
					-Wall								\
					-Wextra				 				\
					-Winline							\
					-Wpragmas							\
					-Wuninitialized						\
					-Wno-missing-braces					\
					-Wcast-align						\
					-Wwrite-strings						\
					-Wparentheses						\
					-Wunreachable-code					\
					-Wunused							\
					-Wmissing-field-initializers		\
					-Wswitch-enum						\
					-Wshadow				 			\
					-Wuninitialized				 		\
					-Wmissing-declarations				\
					-Wpointer-arith						\
					-imacros $(TGTMACRO)				\
					# -Werror

CXXFLAGS += $(LIBFLAGS)


# Compile-time Macro
CXXFLAGS	+=	'-D PROJECT="$(PROJECT)"'			\

# Debug mode
export 	CFLAGSDEBUG	= 	-D DEBUG \
						-g3

debug ?= 0
ifeq ($(debug), 1)
    CXXFLAGS 	+= $(CFLAGSDEBUG)
	LDFLAGS	+= $(LDFLAGS_DEBUG)
endif

# Output coloration
export Red			:= \e[0;31m
export BoldRed		:= \e[1;31m
export Green		:= \e[0;32m
export BoldGreen	:= \e[1;32m
export Yellow		:= \e[0;33m
export BoldYellow	:= \e[01;33m
export Blue			:= \e[0;34m
export BoldBlue		:= \e[1;34m
export Magenta		:= \e[0;35m
export BoldMagenta 	:= \e[1;35m
export Cyan			:= \e[0;36m
export BoldCyan		:= \e[1;36m
export Blank		:= \e[0m