/*Authors: Isha Sawant and Om Raheja
 * Project 2:Circular buffers, UART and Interrupts
 * Course: ECEN 5813 Principles of Embedded Software
 * Semester: FALL 2018
 * Date: 27th November 2018
 * */

/*Headers*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/


/* @Function name : add_element()
 * @Parameters    : cirbuf_t *ptr , int size1
 * @Description   : Adds the element/character to the buffer or deletes when full and calls the report function after each character.
 * @return        : void
 * */
void add_element(cirbuf_t *,int);

/* @Function name : report()
 * @Parameters    : void
 * @Description   : Generates and displays a clean report of all contents in the buffer and also prints the Fibonacci series and digits in pi according to inputs.
 * @return        : void
 * */

void report();

