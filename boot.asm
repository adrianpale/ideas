;;*****************************************************
;;kernel.asm
bits 32								;nasm directive - 32 bit
section .text
	;multiboot spec
	 align 4
	 dd 0x1BADB002					;magic
	 dd 0x00						;flags
	 dd - (0x1BADB002 + 0x00)		;checksum. m+f+c should be zero
	 
global start

extern kmain						;kmain is defined in C file

start:
 cli								;block interrupts
 mov esp, stack_space				;set Stack pointer
 call kmain
 hlt								;halt CPU

section .bss
	stack_space: resb 8192				;8KB for Stack
;;*****************************************************