 #
# Inc make which define macro for processus control
 #

define RAISE
	@echo -e "[$(BoldRed)ABORT$(Blank)]$(1)"
	@exit 1
endef

define INFO
	@echo -e "[$(BoldBlue)PaintWar$(Blank)]$(1)"
endef

HANDLED_TARGET	:=	server	\
					client

# Check if Build is valid (target)
define EvalTargetBuild
	$(if $(filter $(TARGET),$(HANDLED_TARGET)), $(call INFO, "Build for $(TARGET) target"), $(call RAISE, "Invalid target: must be in [$(HANDLED_TARGET)]"))
endef
