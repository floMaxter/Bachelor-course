Title Logical shift left
.686
.MODEL FLAT, C
.STACK
.DATA
;-----------Local data------------------------------
; value_asm  2 
; multiplier_asm 4
.CODE
;-----------External usage-------------------------
EXTRN value_asm : WORD
EXTRN multiplier_asm : WORD
EXTRN res_asm : WORD
;-----------Function definitions-------------------
PUBLIC C logic_shift_left_ASM
logic_shift_left_ASM PROC far;
mov ax, value_asm
mov bx, multiplier_asm
mul bx
mov res_asm, ax
retn
logic_shift_left_ASM ENDP
END