.DEFAULT_GOAL := risc_asm
risc_asm: basic.cpp InstData.cpp functs.cpp r_format.cpp i_format.cpp s_format.cpp b_format.cpp j_format.cpp u_format.cpp
	g++ -g basic.cpp InstData.cpp functs.cpp r_format.cpp i_format.cpp s_format.cpp b_format.cpp j_format.cpp  u_format.cpp -o riscv_asm

basic.o: basic.cpp
	g++ -c basic.cpp

InstData.o: InstData.cpp InstData.h
	g++ -c InstData.cpp	

functs.o: functs.cpp functs.h
	g++ -c functs.cpp

r_format.o: r_format.cpp r_format.h
	g++ -c r_format.cpp

i_format.o: i_format.cpp i_format.h
	g++ -c i_format.cpp

s_format.o: s_format.cpp s_format.h
	g++ -c s_format.cpp

b_format.o: b_format.cpp b_format.h
	g++ -c b_format.cpp

j_format.o: b_format.cpp b_format.h
	g++ -c b_format.cpp

u_format.o: b_format.cpp b_format.h
	g++ -c b_format.cpp
clean:
	rm *.o risc_asm