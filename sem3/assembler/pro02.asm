; Program name: pro02.ASM ***********************************************************************
;*************************************************************************************************************************

org 0x100                ; Start program at address 100H
bits 16                  ; DOS runs in real-mode -> 16bit
SECTION .CODE
M1:                      ; Start label
  MOV AH, 1
  INT 21H
  MOV BL, AL
  SUB BL, 30H
  MOV AH, 1
  INT 21H
  SUB AL, 30H
  ADD AL, BL
  MOV DL, AL
  ADD DL, 30H
  MOV AH, 2H             ; Function number for screen output
  INT 21H                ; General interrupt
ENDE:                    ; END label
  MOV AH, 4CH            ; Function number "return to DOS"
  INT 21H                ; General interrupt