; Program name: pro01.ASM ***********************************************************************
;*************************************************************************************************************************

org 0x100                ; Start program at address 100H
bits 16                  ; DOS runs in real-mode -> 16bit
SECTION .CODE
M1:                      ; Start label
  MOV AH, 08H            ; Read character from keyboard without screen echo
  INT 21H                ; General interrupt
  CMP AL, 1BH            ; Compare content of AL with ESC key
  JE ENDE                ; If equal, jump to END label
  MOV DL, AL             ; Move input character to right data byte
  MOV AH, 2              ; Function number for screen output
  INT 21H                ; General interrupt
  JMP M1                 ; Unconditional jump to M1 label
ENDE:                    ; END label
  MOV AH, 4CH            ; Function number "return to DOS"
  INT 21H                ; General interrupt