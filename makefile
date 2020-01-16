
syko.exe:
	gcc -c mem_abs.c -o mem_abs.o
	gcc -c f_add1.c -o f_add1.o
	gcc -c f_add2.c -o f_add2.o
	gcc -c f_jmp.c -o f_jmp.o
	gcc -c main.c -o main.o
	gcc mem_abs.o f_add1.o f_add2.o f_jmp.o main.o -o syko.exe

clean:
	rm -f mem_abs.o
	rm -f f_add1.o
	rm -f f_add2.o
	rm -f f_jmp.o
	rm -f main.o
	rm -f syko.exe

