@set MPATH=G:\Libs\Risc-V\bin rem D:\Risc-V\bin

@set GAS=%MPATH%\riscv64-unknown-elf-as.exe
@set GLD=%MPATH%\riscv64-unknown-elf-ld.exe
@set GOBJDUMP=%MPATH%\riscv64-unknown-elf-objdump.exe
@set GOBJCOPY=%MPATH%\riscv64-unknown-elf-objcopy.exe
@set GREADELF=%MPATH%\riscv64-unknown-elf-readelf.exe

@set LD_OPTIONS=-nostartfiles 

%GAS% main.s -o main.o
%GLD% %LD_OPTIONS% -Tlinker.ld main.o -o test
%GOBJDUMP% -DxS test > test.lst
%GREADELF% -a test >test_elf.lst
@%GOBJCOPY% -j ".text" -O binary test file_code.bin
@%GOBJCOPY% -j ".data" -O binary test file_data_in.bin
@%GOBJCOPY% -j ".riscv.attributes" -O binary test file_reg_in.bin
