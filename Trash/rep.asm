  include \masm32\include\masm32rt.inc
  
.code                       
start:                          ; the CODE entry point to the program
    call main                   ; branch to the "main" procedure
    exit
; «««««««««««««««««««««««««««««««««««««««««««««««««««««««««««««
main proc
    LOCAL var1:DWORD            ; 2 DWORD integral variables
    LOCAL var2:DWORD            ;

  ; Input 2 integers
    mov var1, sval(input("Enter number 1 : "))
    mov var2, sval(input("Enter number 2 : "))

    print chr$("v1 + v2 = ")
    mov ecx, var1               ; copy var1 to ecx
    add ecx, var2               ; add var2 to ecx
    print str$(ecx)
    print chr$(13,10)

    print chr$("v1 - v2 = ")
    mov ecx, var1               ; copy var1 to ecx
    sub ecx, var2               ; sub var2 from ecx
    print str$(ecx)
    print chr$(13,10)

    print chr$("v1 * v2 = ")
    mov eax, var1               ; copy var1 to eax
    mul var2                    ; mul var2 to eax
    print str$(eax)
    print chr$(13,10)

    CMP [var2], 0	              
    je STOP				  
    print chr$("v1 / v2 : ", 13,10)
    print chr$("- The quotient is: ")
    mov eax, var1               ; copy var1 to eax
    mov ebx, var2               ; copy var2 to ebx
    xor edx, edx
    div ebx
    print str$(eax)
    print chr$(13,10)
    print chr$("- The remainder is: ")
    mov eax, var1               ; copy var1 to eax
    mov ebx, var2               ; copy var2 to ebx
    xor edx, edx
    div ebx
    print str$(edx)
    
    ret

    STOP:       
        print chr$("v1 / v2 : Error. Divide by zero!")
    ret
main endp