 #
# Inc make which define build variable
 #

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(BUILDIR)/config

# Norm Libraries
export TGTSHARED_PLTLIB	:=	$(BUILDIR)/*.a

export BUILDTYPE_NOLINK		:=	0
export BUILDTYPE_PLTLIB		:=	1
export BUILDTYPE_BINARY		:=	2