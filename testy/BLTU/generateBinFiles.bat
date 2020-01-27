@set MPATH=D:\Risc-v\bin
rem D:\Risc-V\bin

@set GAS=%MPATH%\riscv64-unknown-elf-as.exe
@set GLD=%MPATH%\riscv64-unknown-elf-ld.exe
@set GOBJDUMP=%MPATH%\riscv64-unknown-elf-objdump.exe
@set GOBJCOPY=%MPATH%\riscv64-unknown-elf-objcopy.exe
@set GREADELF=%MPATH%\riscv64-unknown-elf-readelf.exe

@set LD_OPTIONS=-nostartfiles 

for /l %%x in (0, 1, 1) do (
	%GAS% ./test_%%x/%%x.s -o ./test_%%x/main.o
	%GLD% %LD_OPTIONS% -T./../linker.ld ./test_%%x/main.o -o ./test_%%x/test
	%GOBJDUMP% -DxS ./test_%%x/test > ./test_%%x/test.lst
	%GREADELF% -a ./test_%%x/test >./test_%%x/test_elf.lst
	@%GOBJCOPY% -j ".text" -O binary ./test_%%x/test ./test_%%x/file_code.bin
	@%GOBJCOPY% -j ".data" -O binary ./test_%%x/test ./test_%%x/file_data_in.bin
	@%GOBJCOPY% -j ".riscv.attributes" -O binary ./test_%%x/test ./test_%%x/file_reg_in.bin

	python ./../../binaryGeneration/binMaker.py ./test_%%x/
)
pause