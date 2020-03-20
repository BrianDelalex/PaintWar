 #
# Template Builder for X64BUILD target
 #

TARGET_CXX_SOURCE 	+=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_CXX_OBJECT 	+=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_CXX_SOURCE))

.PHONY: x64builder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	+=	$(TARGET_CXX_OBJECT) $(TARGET_ASM_OBJECT)

x64builder:		buildheader $(TARGET_CXX_OBJECT) $(BUILDICHOTOMY)

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
else ifeq ($(BUILDTYPE),$(BUILDTYPE_ARCLIB))
	@$(AR) rcs $(TGTSHARED_LIBARC) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LNK      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_LIBARC))"
endif

buildheader:
	@echo -e "\nBuilding $(BUILDHEADER) objects...\n"