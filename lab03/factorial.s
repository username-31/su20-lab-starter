.globl factorial

.data
n: .word 8
.text
main:
    la t0, n
    lw a0, 0(t0)
    jal ra, factorial

    addi a1, a0, 0
    addi a0, x0, 1
    ecall # Print Result

    addi a1, x0, '\n'
    addi a0, x0, 11
    ecall # Print newline

    addi a0, x0, 10
    ecall # Exit

factorial:
    # YOUR CODE HERE
    mv s0, a0 # s0 = n
    mv s1, a0 # s1 = i, init as n
    li s2, 1  # s2 = result, init as 1
    loop:
        beqz s1, exit # while (i > 0)

        # Save Regs
        addi sp, sp, -8
        sw a0, 0(sp) 
        sw ra, 4(sp)

        # Call Func
        mv a0, s2 
        mv a1, s1 
        jal ra, mul # mul(A: i(s1), B: result(s2))
        mv s2, a0 # s2 = result * i

        #Restore Regs
        lw a0, 0(sp)
        lw ra, 4(sp)
        addi sp, sp, 8

        addi s1, s1, -1
        j loop
    exit:
        mv a0, s2 # a0 = result(s2)
        ret

mul:# Calculates A * B, A is a0, B is a1
    li t0, 0 # t0 = res, init as 0
    mv t1, a1 # t1 = B
    mv t2, a0 # t2 = A
    mulloop:
        beqz t1, exitmul # while( B > 0)
        add t0, t0, t2 # result = result + A
        addi t1, t1, -1
        j mulloop
    exitmul:
        mv a0, t0
        ret