 #
# Template Builder for X64BUILD target
 #

CXX	:=	g++

TARGET_CXX_SOURCE 	+=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_CXX_OBJECT 	+=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_CXX_SOURCE))

.PHONY: hostbuilder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_CXX_OBJECT) $(TARGET_ASM_OBJECT)

hostbuilder:	buildheader $(TARGET_CXX_OBJECT) $(BUILDICHOTOMY)

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(CCFLAGS) -c $< -o $@
	@-echo -e "     CXX      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

$(BUILDICHOTOMY):	$(.SECONDEXPANSION)
	@echo ""
ifeq ($(BUILDTYPE),$(BUILDTYPE_BINARY))
	@$(CXX) $(TARGET_BUILT_OBJECT) $(LDFLAGS)
	@-echo -e "    LNK      $@"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_PLTLIB))
	@$(AR) rcs $(TGTSHARED_LIBPLT) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LNK      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBPLT))"
endif

buildheader:
	@echo -e "\nBuilding $(BUILDHEADER) objects...\n"