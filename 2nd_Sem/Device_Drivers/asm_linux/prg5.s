.text
.global main
.extern printf
main:
        push {ip, lr}

        ldr r0, =string
        mov r1, #20
        mov r2, #30
        //add r1, #15
        //mov r1, #1024
        cmp r1,r2
        mov r1, r2
        bhi l1
        
        bl printf

        pop {ip, pc}

.data
string: .asciz "The larger number is: %d\n"
