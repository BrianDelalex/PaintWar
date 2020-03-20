 #
#  Makefile for client source redirections
 #

SERVER_SOURCE_DIR	=	

.PHONY: all


all:	subbuild	$(.EXPANSION)	hostbuilder

subbuild:
	@make -C XXX --no-print-directory

.EXPANSION:
BUILDHEADER	=	$(BINARY)
BUILDTYPE	=	$(BUILDTYPE_BINARY)

include $(MKHELPER_DIR)/builder/builder_host.mk