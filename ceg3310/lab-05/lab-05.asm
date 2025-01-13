;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

.ORIG x3000
;    Your main() function starts here
LD R6, STACK_PTR            				; LOAD the pointer to the bottom of the stack in R6    (R6 = x6000)
LEA R4, GLOBAL_VARS            				; MAKE your global var pointer R4 point to globals    (R4 = ADDRESS(GLOBAL_VARS))

ADD R6, R6, #-1
STR R7, R6, #0						

ADD R6, R6, #-1
STR R5, R6, #0						
ADD R5, R6, #0						

ADD R6, R6, #-1 					
AND R0, R0, #0 
STR R0, R6, #0						
ADD R6, R6, #-1						
STR R0, R6, #0 						

ADD R0, R4, #0 
ADD R0, R0, #4						
PUTS							

AND R0, R0, #0
ADD R0, R4, #2 						
LDR R0, R0, #0 

ADD R6, R6, #-1 					

JSR GETNUM 

LDR R0, R6, #0
STR R0, R5, #-1 					

ADD R6, R6, #1 					    

ADD R6, R6, #-1
STR R0, R5, #-1 
STR R0, R6, #0 						


JSR FIBONACCI

LDR R0, R6, #0
STR R0, R5, #2 						

ADD R6, R6, #1 						
ADD R6, R6, #1 						

ADD R0, R4, #0
ADD R0, R0, #15
ADD R0, R0, #15
PUTS  

ADD R6, R6, #-1
LDR R0, R5, #-1
STR R0, R6, #0 

JSR DISPLAY

ADD R6, R6, #1 

ADD R0, R4, #0
ADD R0, R0, #15
ADD R0, R0, #15
ADD R0, R0, #4
PUTS  

ADD R6, R6, #-1
LDR R0, R5, #2
STR R0, R6, #0 

JSR DISPLAY

ADD R6, R6, #1 
ADD R6, R6, #1 
ADD R6, R6, #1 
LDR R5, R6, #0
ADD R6, R6, #1 
LDR R7, R6, #0
ADD R6, R6, #1 
HALT

GLOBAL_VARS                    		; Your global variables start here 
ASCII_OFFSET    .FILL x0030         ; MAX_ARRAY_SIZE is a global variable and predefined
STACK_PTR    .FILL x6000            ; STACK_PTR is a pointer to the bottom of the stack (x6000)
NEG_ASCII .FILL #-48 				; 2
ASCII .FILL x30 					; 3
PROMPT1 .STRINGZ "Please enter a number n: "	; 4
RESULT1 .STRINGZ "\nF(" 			; 30
RESULT2 .STRINGZ ") = "				; 34
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
FIBONACCI 
;    Your fibonacci() function starts here

;;;;
; Return value
ADD R6, R6, #-1             

ADD R6, R6, #-1             
STR R7, R6, #0              

ADD R6, R6, #-1             
STR R5, R6, #0              
ADD R5, R6, #0              

ADD R6, R6, #-1             
STR R0, R6, #0              
ADD R6, R6, #-1             
STR R1, R6, #0              
ADD R6, R6, #-1             
STR R2, R6, #0              
ADD R6, R6, #-1             
STR R3, R6, #0              
ADD R6, R6, #-1             

;;;;
; BASE CASE
LDR R0, R5, #3              
ADD R1, R0, #-1             
BRz END_CASE                
ADD R0, R0, #1              
ADD R0, R0, #-1             
BRz END_CASE                

;;;;
; GENERAL CASE
ADD R0, R0, #-1             
STR R0, R6, #0              
JSR FIBONACCI
LDR R1, R5, #-6             

ADD R0, R0, #-1             
STR R0, R6, #0              
JSR FIBONACCI
LDR R2, R5, #-6             

ADD R0, R1, R2              

;;;;
; END CASE
END_CASE
STR R0, R5, #2              

ADD R6, R6, #1             
LDR R3, R6, #0              
ADD R6, R6, #1              
LDR R2, R6, #0              
ADD R6, R6, #1              
LDR R1, R6, #0              
ADD R6, R6, #1              
LDR R0, R6, #0              

ADD R6, R6, #1              
LDR R5, R6, #0              

ADD R6, R6, #1             
LDR R7, R6, #0              

ADD R6, R6, #2              
RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

GETNUM
;    Your getnum() function starts here
ADD R6, R6, #-1			
STR R7, R6, #0

ADD R6, R6, #-1			
STR R5, R6, #0
ADD R5, R6, #0			

ADD R6, R6, #-1 
STR R0, R6, #0			

ADD R6, R6, #-1
STR R1, R6, #0 			

;; logic
AND R0, R0, #0 			
GETC
OUT 

LDR R1, R5, #-1			
ADD R0, R0, R1 			

;; logic end 

STR R0, R5, #2			

LDR R1, R6, #0
ADD R6, R6, #1 			

LDR R0, R6, #0
ADD R6, R6, #1 			

LDR R5, R6, #0			
ADD R6, R6, #1				

LDR R7, R6, #0			 
ADD R6, R6, #1 	
RET

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

DISPLAY
;    Your display() function starts here
ADD R6, R6, #-1
STR R7, R6, #0 
ADD R6, R6, #-1
STR R5, R6, #0 
ADD R5, R6, #0

AND R0, R0, #0
ADD R6, R6, #-1 
STR R0, R6, #0

LDR R3, R4, #3 
AND R2, R2, #0 
ADD R2, R2, #-1 
ADD R0, R0, #-10 
LDR R1, R5, #2 

TEN_LOOP
    ADD R2, R2, #1 
    ADD R1, R1, R0 
BRzp TEN_LOOP
ADD R2, R2, #0 
BRz SKIP_TEN
LDR R0, R4, #1 
ADD R0, R2, R3 
OUT

SKIP_TEN
    ADD R1, R1, #10
    ADD R0, R1, R3
    OUT

ADD R6, R6, #1 

LDR R5, R6, #0
ADD R6, R6, #1 
LDR R7, R6, #0
ADD R6, R6, #1 
RET
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
.END