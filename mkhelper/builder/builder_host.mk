 #
# Template Builder for X64BUILD target
 #

CXX	:=	g++

TARGET_CXX_SOURCE 	=	$(wildcard $(addsuffix /*$(EXTENSION_SRC), $(TARGET_SOURCE_DIR)))

TARGET_CXX_OBJECT 	=	$(patsubst %$(EXTENSION_SRC), $(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ), $(TARGET_CXX_SOURCE))

TARGET_PREFIX_BUILD	:=	$(shell realpath --relative-to $(PROJECT_PATH)/$(ROOT_SRC_DIR) .)

.PHONY: hostbuilder

.SECONDEXPANSION:
TARGET_BUILT_OBJECT	=	$(TARGET_CXX_OBJECT)

hostbuilder:	buildheader	$(TARGET_CXX_OBJECT)	BUILDICHOTOMY

$(BUILDIR)/$(TARGET_PREFIX_BUILD)/%$(EXTENSION_OBJ): %$(EXTENSION_SRC)
	@mkdir -p $(shell dirname $@)
	@$(CXX) $(CXXFLAGS) -c $< -o $@
	@-echo -e "    CXX      $(shell basename $(BUILDIR))$(subst $(BUILDIR),,$@)"

BUILDICHOTOMY:	$(.SECONDEXPANSION)
ifeq ($(BUILDTYPE),$(BUILDTYPE_BINARY))
	@$(CXX) $(TARGET_BUILT_OBJECT) $(shell find $(BUILDIR)/$(TARGET) -name *.o) $(LDFLAGS)
	@-echo -e "    LNK      $(BINARY)"
else ifeq ($(BUILDTYPE),$(BUILDTYPE_PLTLIB))
	@$(AR) rcs $(TGTSHARED_PLTLIB)/$(BUILDHEADER)$(EXTENSION_LIB) $(TARGET_BUILT_OBJECT)
	@-echo -e "    LNK      $(shell realpath --relative-to $(shell dirname $(BUILDIR)) $(TGTSHARED_PLTLIB))/$(BUILDHEADER)$(EXTENSION_LIB)"
endif

buildheader:
	@echo -e "\nBuilding $(BUILDHEADER)...\n"