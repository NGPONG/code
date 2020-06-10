target := build/foo
compare_path := build/

foo: $(compare_path) $(compare_path)main.o $(compare_path)source_1.o $(compare_path)source_2.o
	gcc $(wildcard $(compare_path)*.o) -o $(target) -I ./header

$(compare_path):
	@mkdir $(compare_path)

$(compare_path)%.o: %.c
	gcc -c $< -o $@

.PHONY: clean
clean:
	@mv $(target) ./ && rm -rf $(wildcard $(compare_path)*.o)
