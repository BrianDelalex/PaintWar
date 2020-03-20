 #
# Root Makefile project, calling sub-build
 #

include mkhelper/def.mk
include mkhelper/macro.mk
include mkhelper/toolchain.mk
include mkhelper/builder/build.mk

.PHONY: all prebuld build fclean debug clean $(KERNEL)

all:	prebuild	build	$(KERNEL)

# Evaluate if the build is correct
prebuild:
	$(call EvalToolchain)
	$(call EvalTargetMachine, $(TARGET))
	@echo -e "\n *"
	@echo -e "*  Building $(PROJECT)"
	@echo -e " *\n"

# Lauch the build, clean & exit if failed
build:
	@make -C $(PROJECT_PATH)/$(ROOT_SRC_DIR)/$(TARGET_DIR) --no-print-directory	\
		|| \
	(echo -e "[$(BoldRed)ABORT$(Blank)] Build Failed" && make fclean --no-print-directory && exit 0)

# Disassemble the kernel (debug)
disassemble: $(KERNEL)
	@$(AARCH64_OBJDMP) --no-show-raw-insn -d -Mintel $(PROJECT)-*$(BIN_EXTENSION) | source-highlight -s asm -f esc256 | less -eRiMX

re:	fclean all

# Clean the relocatable objects & kbuild
clean:
	@$(RM) $(BUILDIR)

# Full clean the projet
fclean:	clean
	@$(RM) $(PROJECT)*.$(BIN_EXTENSION)
	@$(RM) vgcore.*
	@$(RM) $(shell find . -name $(BUILDEP))