	.global _start

_start:

	lui t0, 0x10010

	andi t1, t1, 0
	addi t1, t1, 0
	sw t1, 0(t0)

	andi t1, t1, 0
	addi t1, t1, 1
	sw t1, 0(t0)

	andi t1, t1, 0
	addi t1, t1, 16
	sw t1, 0(t0)

	andi t1, t1, 0
	addi t1, t1, 30
	sw t1, 0(t0)

	andi t1, t1, 0
	addi t1, t1, 2047
	sw t1, 0(t0)

finish:
	beq t1, t1, finish
	
