.PHONY: clean All

All:
	@echo "----------Building project:[ My2DGameEngine - Debug ]----------"
	@cd "My2DGameEngine" && "$(MAKE)" -f  "My2DGameEngine.mk"
clean:
	@echo "----------Cleaning project:[ My2DGameEngine - Debug ]----------"
	@cd "My2DGameEngine" && "$(MAKE)" -f  "My2DGameEngine.mk" clean
