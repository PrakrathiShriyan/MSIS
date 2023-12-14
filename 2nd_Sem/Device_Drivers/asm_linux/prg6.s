.text
.global main
.extern printf
main:
        push {ip, lr}

        ldr r0, =string
        ldr r7, =array
        mov r2, #4     
	mov r3, #4
	add r7, #4
	ldr r1, [r7]
              
l1:     bl printf
	ldr r1, [r7,r3]
	add r3, #4
	sub r2, #1
	cmp r2, #1
	bne l1
       // pop {ip, pc}

.data
array: .word 10,20,30,40
string: .asciz "The number is: %d\n"
