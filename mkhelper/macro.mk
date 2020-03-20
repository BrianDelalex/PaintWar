 #
# Inc make which define macro for processus control
 #

include $(MKHELPER_DIR)/arch.mk

define RAISE
	@echo -e "[$(BoldRed)ABORT$(Blank)]$(1)"
	@exit 1
endef

define INFO
	@echo -e "[$(BoldBlue)PaintWar$(Blank)]$(1)"
endef

# Check if Build is valid (target)
define EvalTargetBuild
	$(if $(TARGET), $(call INFO, "Build for $(TARGET) target"), $(call RAISE, "Invalid target target"))
endef
