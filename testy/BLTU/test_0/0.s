/* kod aplikacji */
	.text
	.align	1
	.globl _start
	.globl	main
	.type	main, @function

_start:
    ori a0, a0, 0x4
    ori a1, a1, 0x8
	bltu a0, a1, success
	nop
success:
    add a0, a0, a1
/* dane aplikacji */
/* zmienna, wstepnie zadeklarowana typu char[] */
	.globl	mdata
	.data
	.align	2	/* alokacja co 2B */
	.type	mdata, @object
	.size	mdata, 14
mdata:
	.string "Hello world!\n"

