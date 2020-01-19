syko.exe:
	gcc -c src/mem_abs.c -o bin/mem_abs.o
	gcc -c src/f_add1.c -o bin/f_add1.o
	gcc -c src/f_and.c -o bin/f_and.o
	gcc -c src/f_auipc.c -o bin/f_auipc.o
	gcc -c src/f_bltu.c -o bin/f_bltu.o
	gcc -c src/f_jalr.c -o bin/f_jalr.o
	gcc -c src/f_jmp.c -o bin/f_jmp.o
	gcc -c src/f_lhu.c -o bin/f_lhu.o
	gcc -c src/f_lui.c -o bin/f_lui.o
	gcc -c src/f_lw.c -o bin/f_lw.o
	gcc -c src/f_ori.c -o bin/f_ori.o
	gcc -c src/f_sw.c -o bin/f_sw.o
	gcc -c src/main.c -o bin/main.o
	gcc bin/*.o -o syko.exe

clean:
	rm -f bin/*.o
	rm -f syko.exe

