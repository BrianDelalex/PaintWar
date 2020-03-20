 #
# Inc make which define build variable
 #

# Norm arch particular macro
export TGTMACRO			:=	@config
export TGTMACRO_BUILD	:=	$(KBUILD)

# Norm Libraries
export TGTSHARED_LIBARC	:=	$(BUILDIR)/arclib.a

export BUILDTYPE_NOLINK		:=	0
export BUILDTYPE_PLTLIB		:=	1
export BUILDTYPE_SRDLIB		:=	2
export BUILDTYPE_BINARY		:=	3