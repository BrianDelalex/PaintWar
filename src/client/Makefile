 #
#  Makefile compiling client source
 #

BUILDHEADER	:=	client objects

BUILDTYPE	:=	$(BUILDTYPE_BINARY)

TARGET_SOURCE_DIR	+=	graphic		\
						network		\
						scheduler	\

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: all

all:	hostbuilder

include $(MKHELPER_DIR)/builder/builder_host.mk