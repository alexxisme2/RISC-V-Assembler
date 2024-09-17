#### Assembler Description
This Assembler implementation takes in input from "input.s" file and creates a "output.hex" file in which the outpute is stored.

### Instruction line format
If the instruction has a label it must end with ':' without any spaces in between followed by a space before the instruction 
The instruction used must be a part of "RV64I Base Integer Instructions" and not a psuedo instruction except "nop"
The instruction must be followed up with a space before the register name 
The registers, immediates and labels after the instruction must be seperated by ',' and a space except when it is the end of the instruction line
The immediate values must be provided in decimals and not hexa decimals
The ';' character marks the comment start so anything after it will be ignored

### Running the Assembler
All the files mentioned in the Makefile must be present in the same directory along with "input.s"
Use the "make" command to get the executable file "riscv_asm" 
Run "riscv_asm" executable to execute the program and get the output stored in "output.hex"

### File Description
b_format.h is the header file of b_format.cpp necessary to assemble B-format instructions 
r_format.h is the header file of r_format.cpp necessary to assemble R-format instructions 
i_format.h is the header file of i_format.cpp necessary to assemble I-format instructions 
j_format.h is the header file of j_format.cpp necessary to assemble J-format instructions 
s_format.h is the header file of s_format.cpp necessary to assemble S-format instructions 
u_format.h is the header file of u_format.cpp necessary to assemble U-format instructions 

testcases:  This folder contains sample test cases the implemented Assembler was tested on

Please note that if an instruction line is erroneous the Assembler skips the said line and continues executing the other lines
However if the erroneous instruction line has a label and another instruction line calls that label it calculates the offset from the erroneous line
