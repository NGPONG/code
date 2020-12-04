# OBJECT = main.o common.o
# CC = gcc
# 
# vpath %.h ./header
# vpath %.c ./source
# 
# main: $(OBJECT)
# 	$(CC) $(OBJECT) -o $@
# 	@echo $@
# 	@echo $<
# 	@echo $^
# 
# common.o: common.h common.c
# 	$(CC) -c ./source/common.c
# 
# main.o: common.h main.c
# 	$(CC) -c main.c

OBJECT = main.o common.o
CC = gcc

main: $(OBJECT)
	@echo "main"

%.o: %.c
	@echo $@
	@echo $<

.PHONY:
clean:
	@find ./ ! -name "header" ! -name "*makefile*" ! -name "mk" ! -name "source" ! -name "." ! -name "*.c" ! -name "*.h" -exec rm -rf {} \;
	@echo "cleaned"
