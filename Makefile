 #
# Root Makefile project, calling sub-build
 #

include mkhelper/def.mk
include mkhelper/macro.mk
include mkhelper/builder/build.mk

.PHONY: all checkup build fclean clean

all:	checkup	build

# Evaluate if the build is correct
checkup:
	$(call EvalTargetBuild, $(TARGET))
	@echo -e "\n *"
	@echo -e "*  Building $(PROJECT) $(TARGET)"
	@echo -e " *\n"

# Lauch the build, clean & exit if failed
build:
	@make -C $(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(TARGET) --no-print-directory	\
		|| \
	(echo -e "[$(BoldRed)ABORT$(Blank)] Build Failed" && make fclean --no-print-directory && exit 0)

# Clean the relocatable objects & kbuild
clean:
	@$(RM) $(BUILDIR)

# Full clean the projet
fclean:	clean
	@$(RM) $(PROJECT)*.$(BIN_EXTENSION)
	@$(RM) vgcore.*
	@$(RM) $(shell find . -name $(BUILDEP))