.ORIG x3000

LD R0, INTX ; load x into R0
LD R1, INTY ; load y into R1
LD R2, INTX ; load x into R2
LD R3, ZERO ; load zero into R3

ADD R1, R1, #-1
OUTER_LOOP
BRz END_OUTER ; If y = 0, break

LD R0, INTX ; load x into R0

INNER_LOOP
  BRz END_INNER

  ADD R3, R3, R2 ; add R2 to R3
  ADD R0, R0, #-1; decrease x

  BRnzp INNER_LOOP 
END_INNER

ST R3, INTZ ; store R3 into INTZ
LD R2, INTZ ; load z into R2
LD R3, ZERO ; load R3 into 0
ADD R1, R1, #-1 ; decrease y

BRnzp OUTER_LOOP
END_OUTER

STI R2, RESULT ; store R2 in result

HALT

INTX .FILL #3 ; base number
INTY .FILL #2 ; exponent
INTZ .FILL #0
ZERO .FILL #0
RESULT .FILL x8000

.END