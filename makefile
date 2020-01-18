syko.exe:
	gcc -c mem_abs.c -o bin/mem_abs.o
	gcc -c f_add1.c -o bin/f_add1.o
	gcc -c f_jalr.c -o bin/f_jalr.o
	gcc -c f_jmp.c -o bin/f_jmp.o
	gcc -c f_lui.c -o bin/f_lui.o
	gcc -c main.c -o bin/main.o
	gcc bin/mem_abs.o bin/f_lui.o bin/f_add1.o bin/f_jalr.o bin/f_jmp.o bin/main.o -o syko.exe

clean:
	rm -f bin/mem_abs.o
	rm -f bin/f_add1.o
	rm -f bin/f_jalr.o
	rm -f bin/f_jmp.o
	rm -f bin/f_lui.o
	rm -f bin/main.o
	rm -f syko.exe

