section .data
    hello db "Hello, Holberton", 0
    nl db 10, 0

section .text
    global main
    extern printf

main:
    push rbp        ; save the base pointer
    mov rbp, rsp    ; set up the new stack frame

    mov rdi, hello  ; set the first argument to the address of hello
    mov rax, 0      ; clear rax for printf
    call printf     ; call printf to print hello

    mov rdi, nl     ; set the first argument to the address of nl
    mov rax, 0      ; clear rax for printf
    call printf     ; call printf to print a new line

    mov rsp, rbp    ; restore the stack pointer
    pop rbp         ; restore the base pointer
    xor eax, eax    ; set the return value to 0
    ret             ; return from main

