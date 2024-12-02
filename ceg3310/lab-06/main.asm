; Sample Code for Lab 6
; This sample code implements the int main() function

.ORIG x3000
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; int main()
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Main's return value
LD R6, STACK_BASE		; R6 = x6000

; Main's return address
ADD R6, R6, #-1			; R6 = x5FFF
STR R7, R6, #0

; Previous frame pointer
ADD R6, R6, #-1			; R6 = x5FFE
STR R5, R6, #0

; Set frame pointer
ADD R5, R6, #0			; R5 = R6 = x5FFE

; node_t *head
ADD R6, R6, #-1			; R6 = x5FFD
AND R0, R0, #0			; R0 = 0
STR R0, R6, #0

; char selection
ADD R6, R6, #-1			; R6 = x5FFC
LD R0, LOWERCASE_S		; R0 = 's'
STR R0, R6, #0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; while(selection != 'q')
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Perform the check for the while loop
; We check to see if char selection is equal to 'q'
; If equal, quit
; It not equal, continue running the loop
CHECK_WHILE
LDR R0, R5, #-2			; R0 = char selection
LD R1, LOWERCASE_Q
NOT R1, R1
ADD R1, R1, #1
ADD R1, R0, R1
BRz BREAK_WHILE_LOOP

; Print the options menu
LEA R0, PROMPT_MENU
PUTS

; Get a character from the keyboard and put it in selection
; (We don't have to write our own scanf() function)
GETC
OUT
STR R0, R5, #-2			; Store the character on the runtime stack in char selection (R0 = char selection)

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; if(selection == 'p')
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Check if char selection is equal to 'p'
LD R1, LOWERCASE_P
NOT R1, R1
ADD R1, R1, #1
ADD R1, R0, R1
BRnp ELSE_IF_A			; If not equal to 'p' check 'a'

; Display prompt
LEA R0, PROMPT_PRINT
PUTS

; node_t **head (&head) (input to printList())
ADD R6, R6, #-1			; R6 = x5FFA
ADD R0, R5, #-1			; R0 = &head = x5FFD
STR R0, R6, #0

;PRINT LISTS RETURN VALUE
ADD R6, R6, #-1         ;R6 = X5FF9

JSR PRINT_LIST

; Pop return value (void)
ADD R6, R6, #1			; R6 = x5FF9

; Pop node_t **head
ADD R6, R6, #1			; R6 = x5FFB

BRnzp CONTINUE_WHILE_LOOP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; else if(selection == 'a')
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Check if char selection is equal to 'a'
ELSE_IF_A
LD R1, LOWERCASE_A
NOT R1, R1
ADD R1, R1, #1
ADD R1, R0, R1
BRnp ELSE_IF_R

; int a
ADD R6, R6, #-1			; R6 = x5FFB
AND R0, R0, #0
STR R0, R6, #0

; Display prompt
LEA R0, PROMPT_ADD
PUTS

; Call TRAP service routine for getting number here
TRAP x40 ; INPUT

; Store number entered into int a
STR R0, R5, #-3

; node_t **head (&head) (input to addValue())
ADD R6, R6, #-1			; R6 = x5FFA
ADD R0, R5, #-1			; R0 = &head = x5FFD
STR R0, R6, #0

; int added (a) (input to addValue())
ADD R6, R6, #-1			; R6 = x5FF9
LDR R0, R5, #-3
STR R0, R6, #0

;addValues's return value
ADD R6, R6, #-1     ;R6 = x5ff9

JSR ADD_VALUE

; Pop return value (void)
ADD R6, R6, #1			; R6 = x5FF9

; Pop int added
ADD R6, R6, #1			; R6 = x5FFA

; Pop node_t **head
ADD R6, R6, #1			; R6 = x5FFB

; Pop int a
ADD R6, R6, #1			; R6 = x5FFC

BRnzp CONTINUE_WHILE_LOOP

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
; else if(selection == 'r')
;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

; Check if char selection is equal to 'r'
ELSE_IF_R
LD R1, LOWERCASE_R
NOT R1, R1
ADD R1, R1, #1
ADD R1, R0, R1
BRnp CONTINUE_WHILE_LOOP

; int r
ADD R6, R6, #-1			; R6 = x5FFB
AND R0, R0, #0
STR R0, R6, #0

; Display prompt
LEA R0, PROMPT_REMOVE
PUTS

; Call TRAP service routine for getting number here
TRAP x40 ;INPUT

; Store number entered into int r
STR R0, R5, #-3

; node_t **head (&head) (input to removeValue())
ADD R6, R6, #-1			; R6 = x5FFA
ADD R0, R5, #-1			; R0 = &head = x5FFD
STR R0, R6, #0

; int removed (r) (input to removeValue())
ADD R6, R6, #-1			; R6 = x5FF9
LDR R0, R5, #-3
STR R0, R6, #0

;REMOVEVALUES RETURN VALUE
ADD R6, R6, #-1         ; R6 = X5FF8

JSR REMOVE_VALUE

; Pop return value (void)
ADD R6, R6, #1			; R6 = x5FF9

; Pop int removed
ADD R6, R6, #1			; R6 = x5FFA

; Pop node_t **head
ADD R6, R6, #1			; R6 = x5FFB

; Pop int r
ADD R6, R6, #1			; R6 = x5FFC

BRnzp CONTINUE_WHILE_LOOP

; Loop back to check the while loop condition again
CONTINUE_WHILE_LOOP
BRnzp CHECK_WHILE

BREAK_WHILE_LOOP

; Pop local variables in main
ADD R6, R6, #2			; R6 = x5FFE

; Pop previous frame pointer
LDR R5, R6, #0
ADD R6, R6, #1			; R6 = x5FFF

; Pop return address
LDR R7, R6, #0
ADD R6, R6, #1			; R6 = x6000

HALT

STACK_BASE .FILL x6000

LOWERCASE_A .FILL x0061
LOWERCASE_P .FILL x0070
LOWERCASE_Q .FILL x0071
LOWERCASE_R .FILL x0072
LOWERCASE_S .FILL x0073

PROMPT_MENU .STRINGz 	"\n Available options:\np - Print linked list\na - Add value to linked list\nr - Remove value from linked list\nq - Quit\nChoose an option: "
PROMPT_PRINT .STRINGz 	"\nContents of the linked list: \n"
PROMPT_ADD .STRINGz 	"\nType a number to add: "
PROMPT_REMOVE .STRINGz 	"\nType a number to remove: "
LIST_BASE .FILL x8000

; void printList(node_t **head)
PRINT_LIST
ADD R6, R6, #-1 ; push return address 
STR R7, R6, #0

ADD R6, R6, #-1 ; push previous frame pointer
STR R5, R6, #0
ADD R5, R6, #0 ; set frame pointer 

ADD R6, R6, #-1 ; push node_t current

LDR R1, R5, #3 ; **head
LDR R1, R1, #0 ; *head
STR R1, R6, #0 ; *current = *head
BRz PRINT_DONE ; branch if null

PRINT_LOOP
    LDR R0, R1, #0 ; get value
    TRAP x41 ; trap output
    LDR R1, R1, #1 ; get next
    STR R1, R6, #0 ; *current = next
    BRz PRINT_DONE ; branch if null
    LEA R0, SEP_STR
    PUTS 
BRnzp PRINT_LOOP
PRINT_DONE 

ADD R6, R6, #1 ; pop *current

LDR R5, R6, #0
ADD R6, R6, #1 ; pop previous frame pointer

LDR R7, R6, #0
ADD R6, R6, #1 ; pop return address 
RET
SEP_STR .STRINGZ " -> "

ADD_VALUE
ADD R6, R6, #-1 ; push return address
STR R7, R6, #0

ADD R6, R6, #-1 ; push previous frame pointer
STR R5, R6, #0
ADD R5, R6, #0 ; set frame pointer


ADD R6, R6, #-1 ; push node_t *current
LDR R0, R5, #4 ; **head
LDR R0, R0, #0 ; *head
STR R0, R6, #0 ; *current = *head
BRnp ADD_BEGIN 
    LD R0, LIST_BASE ; new node address 

    LDR R1, R5, #3 ; get int a
    STR R1, R0, #0 ; set value
    AND R1, R1, #0
    STR R1, R0, #1 ; set next node as null
    LDR R1, R5, #4 ; **head
    STR R0, R1, #0 ; *header
BRnzp ADD_DONE

ADD_BEGIN
LDR R0, R6, #0 ; *current
ADD_LOOP
    LDR R1, R0, #1 ; get next
    BRz ADD_LOOP_DONE ; branch if null
    ADD R0, R0, #2 ; address of next node
    STR R0, R6, #0 ; update *current
BRnp ADD_LOOP

ADD_LOOP_DONE
ADD R0, R0, #2 ; head of next node
LDR R1, R5, #3 ; get int a
STR R1, R0, #0 ; set current value
AND R1, R1, #0 
STR R1, R0, #1 
STR R0, R0, #-1 ; set previous node to this node


ADD_DONE
ADD R6, R6, #1 ; pop *current

LDR R5, R6, #0
ADD R6, R6, #1 ; pop previous frame pointer

LDR R7, R6, #0
ADD R6, R6, #1 ; pop return address 
RET


REMOVE_VALUE
ADD R6, R6, #-1 ; push return address 
STR R7, R6, #0

ADD R6, R6, #-1 ; push previous frame pointer
STR R5, R6, #0
ADD R5, R6, #0 ; set frame pointer


ADD R6, R6, #-1 ; push *previous

LDR R0, R5, #4 ; **head
LDR R0, R0, #0 ; *head
STR R0, R6, #0 ; *previous = *head

BRz REMOVE_DONE ; branch if null

LDR R1, R5, #3 ; int removed
LDR R2, R0, #0

;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
ADD R2, R1, R2 
BRnp REMOVE_BEGIN

LDR R2, R0, #1 
LDR R0, R5, #4 ; **head
STR R2, R0, #0 ; update **head
AND R2, R2, #0
LDR R0, R6, #0 ; *previous
STR R2, R0, #0 ; remove *previous ->value
STR R2, R0, #0 ; remove *previous ->next

BRnzp REMOVE_DONE

REMOVE_BEGIN
ADD R6, R6, #-1 ; push *current
LDR R0, R5, #4 ; **head
LDR R0, R0, #0 ; *head
STR R0, R6, #0 ; *current = *head
LDR R1, R5, #3 ; int removed
REMOVE_LOOP
    LDR R0, R6, #0 ; get *current
    LDR R2, R0, #0 ; get *current ->value
    NOT R2, R2
    ADD R2, R2, #1 
    ADD R2, R1, R2 
    BRz REMOVE_LOOP_DONE 
    STR R0, R6, #1 ; *previous = *current
    LDR R0, R0, #1 ; get *current ->next
    STR R0, R6, #0 ; current = current -> next
    BRnzp REMOVE_LOOP
REMOVE_LOOP_DONE


LDR R0, R6, #1 ; get *previous
LDR R1, R6, #0 ; get *current
LDR R2, R1, #1 ; get *current -> next
STR R2, R0, #1 ; *previous ->next = *current -> next
AND R2, R2, #0
STR R2, R1, #0 ; remove *current -> value
STR R2, R1, #1 ; remove *current -> next

ADD R6, R6, #1 ; pop *current
REMOVE_DONE
ADD R6, R6, #1 ; pop *previous

LDR R5, R6, #0
ADD R6, R6, #1 ; pop previous frame pointer

LDR R7, R6, #0
ADD R6, R6, #1 ; pop return address 
RET

.END