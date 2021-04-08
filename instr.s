	.global _start

_start:
	addi  t0, t1, 0x7ff
	slti  t0, t1, 0x7ff
	sltiu t0, t1, 0x7ff
	andi t0, t1, 0x7ff
	ori  t0, t1, 0x7ff
	xori t0, t1, 0x7ff

	slli t0, t1, 0x7
	srli t0, t1, 0x7
	srai t0, t1, 0x7

	lui   t0, 0xbeef
	auipc t0, 0xbeef

	add  t0, t1, t2
	slt  t0, t1, t2
	sltu t0, t1, t2

	and t0, t1, t2
	or  t0, t1, t2
	xor t0, t1, t2

	sll t0, t1, t2
	srl t0, t1, t2

	sub t0, t1, t2
	sra t0, t1, t2

	jal  ra, finish
	jalr ra, zero, 0x4
	
	beq t0, t1, finish
	bne t0, t1, finish

	blt  t0, t1, finish
	bltu t0, t1, finish

	bge  t0, t1, finish
	bgeu t0, t1, finish
	
	lw  t0, 7(t1)
	lh  t0, 7(t1)
	lhu t0, 7(t1)
	lb  t0, 7(t1)
	lbu t0, 7(t1)

	sw t0, 7(t1)
	sh t0, 7(t1)
	sb t0, 7(t1)
	
	

	
finish:
