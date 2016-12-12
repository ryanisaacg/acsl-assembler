#ACSL Assembler

Note: This project is not affiliated with the American Computer Science League in any way.

An assembler and a virtual machine for running and testing the assembly from the ACSL competitions. It uses a different, unified syntax. Instead of

	A	DC	1

you write 

	DC A 1

Additionally, labels are written as 

	LABEL L

and may only be one letter long. Currently, `PRINT` only prints the value of the register, and cannot take a variable as a parameter.
