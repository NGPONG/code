target = main
src = $(wildcard *.c)
obj = $(patsubst %.c,%.o, $(src))

$(target): $(obj)
	@gcc -g $(obj) -o $(target) -I ./
	@rm -rf ./*.o
	@echo "ok"

%.o: %.c
	@gcc -g -c $<
