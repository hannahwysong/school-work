#include "./io.h"
#include "./types.h"

// Track the current cursor's row and column
volatile int cursorCol = 0;
volatile int cursorRow = 0;

// Define a keymap to convert keyboard scancodes to ASCII
char keymap[128] = {};

// C version of assembly I/O port instructions
// Allows for reading and writing with I/O
// The keyboard status port is 0x64
// The keyboard data port is 0x60
// More info here:
// https://wiki.osdev.org/I/O_Ports
// https://wiki.osdev.org/Port_IO
// https://bochs.sourceforge.io/techspec/PORTS.LST

// outb (out byte) - write an 8-bit value to an I/O port address (16-bit)
void outb(uint16 port, uint8 value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
	return;
}

// outw (out word) - write an 16-bit value to an I/O port address (16-bit)
void outw(uint16 port, uint16 value)
{
    asm volatile ("outw %1, %0" : : "dN" (port), "a" (value));
	return;
}

// inb (in byte) - read an 8-bit value from an I/O port address (16-bit)
uint8 inb(uint16 port)
{
   uint8 ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

// inw (in word) - read an 16-bit value from an I/O port address (16-bit)
uint16 inw(uint16 port)
{
   uint16 ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

// Setting the cursor does not display anything visually
// Setting the cursor is simply used by putchar() to find where to print next
// This can also be set independently of putchar() to print at any x, y coordinate on the screen
void setcursor(int x, int y)
{	

    cursorCol = x % SCREEN_WIDTH;
    cursorRow = y % SCREEN_HEIGHT;

	return;
}

// Using a pointer to video memory we can put characters to the display
// Every two addresses contain a character and a color
char putchar(char character)
{

    int index = 2 * (cursorCol + cursorRow * SCREEN_WIDTH);
    uint8 *vidmem = (uint8*) VIDEO_MEM;

    if (character == '\n') {
        cursorCol = 0;
        cursorRow = (cursorRow + 1) % SCREEN_HEIGHT;
    } 
    else {
        vidmem[index] = (uint8)character;
        vidmem[index + 1] = TEXT_COLOR;
        cursorCol++; 
        if (cursorCol >= SCREEN_WIDTH) {
            cursorCol = 0;
            cursorRow = (cursorRow + 1) % SCREEN_HEIGHT;
        }
    }
	return character;
}

// Print the character array (string) using putchar()
// Print until we find a NULL terminator (0)
int printf(char string[]) 
{
    int i = 0;
    while ((string[i]) != '\0') {
        putchar(string[i]);
        i++;
    }
    return i;
}

// Prints an integer to the display
// Useful for debugging
int printint(uint32 n) 
{
	int characterCount = 0;
	if (n >= 10)
	{
        characterCount = printint(n / 10);
    }
    putchar('0' + (n % 10));
	characterCount++;

	return characterCount;
}

// creates character array containing all possible chars and 0-9. Each index
// of the array should map to the scancode of the character 
void initkeymap() {


// uses polling to determine when status of the keyboard is ready to receive a
// scancode. Converts the scancode to ASCII using the key map
}
char getchar() {
    char character;
    return character; 
}

//populates char string[] with the characters typed into the keyboard. Terminates
// the string when it recieves a null character. Prints to display.
void scanf(char string[]) {

}


// Clear the screen by placing a ' ' character in every character location
void clearscreen()
{
    uint8 *vidmem = (uint8*) VIDEO_MEM;
    for (int row = 0; row < SCREEN_HEIGHT; row++) {
        for (int col = 0; col < SCREEN_WIDTH; col++){ 
            int index = 2 * (row * SCREEN_WIDTH + col);
            vidmem[index] = ' ';
            vidmem[index + 1] = TEXT_COLOR;
        }
    }
    cursorCol = 0;
    cursorRow = 0;
    setcursor(cursorCol, cursorRow);

}