section .data

    player_x dd 0 
    ball_x dd 0 
    ball_y dd 0 



global update
global on_start


section .text


on_start:

    mov dword [player_x], 400 ;half screen w
    ret






update:
    
    ret