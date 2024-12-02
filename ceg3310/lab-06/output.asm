.ORIG x5000
TRAP_OUTPUT
ST R0, SAVE_R0
ST R1, SAVE_R1
ST R2, SAVE_R2
ST R3, SAVE_R3
ST R7, SAVE_R7

; Check if R0 is negative or positive
ADD R0, R0, #0
BRzp SKIP_NEGATIVE_SYMBOL
LD R0, NEGATIVE_SYMBOL
OUT
; Reload R0 since we overwrote it with out ascii character
LD R0, SAVE_R0
; Make R0 positive so it is easier to work with
NOT R0, R0
ADD R0, R0, #1
SKIP_NEGATIVE_SYMBOL

ADD R3, R3, #0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Printing 10's digit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
LD R1, NEGATIVE_10
AND R2, R2, #0

; Loop subtracting 10 from our number
; Until negative
; Track the number of loops in R2
TENS_LOOP
ADD R2, R2, #1
ADD R0, R1, R0
BRzp TENS_LOOP

; Subtract 1 from R2 to account for off by 1 errors
ADD R2, R2, #-1
; Add 10 back to our number to account for subtracting 1 too many times
NOT R1, R1
ADD R1, R1, #1
ADD R0, R1, R0

ST R0, RUNNING_TOTAL
ADD R2, R2, #0
BRnp SKIP_CHECK_R3_TENS
ADD R3, R3, #0
BRz SKIP_TENS

SKIP_CHECK_R3_TENS
LD R0, NUM_TO_ASCII		; R0 = x30
ADD R0, R0, R2			; R0 = x30 + R2
ADD R3, R3, #1			; R3 += 1
OUT

SKIP_TENS
LD R0, RUNNING_TOTAL

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; Printing 1's digit
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
LD R1, NEGATIVE_1
AND R2, R2, #0

; Loop subtracting 1 from our number
; Until negative
; Track the number of loops in R2
ONES_LOOP
ADD R2, R2, #1
ADD R0, R1, R0
BRzp ONES_LOOP

; Subtract 1 from R2 to account for off by 1 errors
ADD R2, R2, #-1
; Add 1 back to our number to account for subtracting 1 too many times
NOT R1, R1
ADD R1, R1, #1
ADD R0, R1, R0

ST R0, RUNNING_TOTAL
LD R0, NUM_TO_ASCII		; R0 = x30
ADD R0, R0, R2			; R0 = x30 + R2
OUT

LD R0, RUNNING_TOTAL

LD R0, SAVE_R0
LD R1, SAVE_R1
LD R2, SAVE_R2
LD R3, SAVE_R3
LD R7, SAVE_R7

RET

NUM				.FILL #-1584
NEGATIVE_10		.FILL #-10
NEGATIVE_1		.FILL #-1
NUM_TO_ASCII	.FILL x30
NEGATIVE_SYMBOL .FILL x2D

SAVE_R0			.BLKW #1
SAVE_R1			.BLKW #1
SAVE_R2			.BLKW #1
SAVE_R3			.BLKW #1
SAVE_R7			.BLKW #1
RUNNING_TOTAL 		.BLKW #1
.END