 #
#  Makefile for client source redirections
 #

SERVER_SOURCE_DIR	=	core

.PHONY: all

all:	subbuild	$(.EXPANSION)	hostbuilder

subbuild:
	@make -C core --no-print-directory

.EXPANSION:
BUILDHEADER	=	$(BINARY)
BUILDTYPE	=	$(BUILDTYPE_BINARY)

include $(MKHELPER_DIR)/builder/builder_host.mk