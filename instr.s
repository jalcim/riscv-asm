	.global _start

_start:
	addi t1, t1, 0x7ff
	slti t3, t2, 0x7ff
	sltiu t3, t2, 0x7ff

	andi t1, t2, 0x7ff
	ori t1, t2, 0x7ff
	xori t1, t2, 0x7ff

	slli t1, t2, 0x7
	srli t1, t2, 0x7
	srai t1, t2, 0x7

	lui t1, 0xbeef
	auipc t1, 0xbeef

	add t2, t4, t5
	slt t2, t4, t5
	sltu t2, t4, t5

	and t2, t4, t5
	or t2, t4, t5
	xor t2, t4, t5

	sll t2, t4, t5
	srl t2, t4, t5

	sub t2, t4, t5
	sra t2, t4, t5

	jal ra, finish
	jalr ra, zero, 0x4






	
	beq t1, t1, finish
	bne t1, t2, finish

	blt t1, t2, finish
	bltu t1, t2, finish

	bge t1, t2, finish
	bgeu t1, t2, finish





	
	lw t1, 7(t6)
	lh t1, 7(t6)
	lhu t1, 7(t6)
	lb t1, 7(t6)
	lbu t1, 7(t6)

	sw t1, 7(t6)
	sh t1, 7(t6)
	sb t1, 7(t6)
	
	

	
finish:
