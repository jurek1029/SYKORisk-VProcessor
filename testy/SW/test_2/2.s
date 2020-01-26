/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function

_start:
	ori a0, a0, -1
	lui a1, 0	
	ori a1, a1, 1
	sw a0, 0(a1)


/* dane aplikacji */
/* zmienna, wstepnie zadeklarowana typu char[] */
	.globl	mdata
	.data
	.align	2	/* alokacja co 2B */
	.type	mdata, @object
	.size	mdata, 14
mdata:
	.string "Hello world!\n"

