/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function

_start:
    ori a0, a0, 0x2
    ori a0, a0, 0x8
    nop

/* dane aplikacji */
/* zmienna, wstepnie zadeklarowana typu char[] */
	.globl	mdata
	.data
	.align	2	/* alokacja co 2B */
	.type	mdata, @object
	.size	mdata, 14
mdata:
	.string "Hello world!\n"

