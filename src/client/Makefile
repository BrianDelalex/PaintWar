 #
#  Makefile for client source redirections
 #

CLIENT_SOURCE_DIR	=	scheduler	\
						graphic		\
						network		\

.PHONY: all

all:	subbuild	$(.EXPANSION)	hostbuilder

subbuild:
	@make -C scheduler --no-print-directory
	@make -C graphic --no-print-directory
	@make -C network --no-print-directory
	@mkdir -p $(TGTSHARED_PLTLIB)

.EXPANSION:
BUILDHEADER	=	$(BINARY)
BUILDTYPE	=	$(BUILDTYPE_BINARY)

include $(MKHELPER_DIR)/builder/builder_host.mk