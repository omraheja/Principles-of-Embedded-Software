/*Authors     : Isha Sawant and Om Raheja.
 * Project 2  : Circular buffer,UART and Interrupts.
 * Course     : ECEN 5813 Principles of Embedded Software.
 * Semester   : FALL 2018.
 * Date       : 27th November 2018.
 * Filename   : main.c
 * Description: Driver function of the entire project to enable the application. 
 * */

/* Headers*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../inc/circular_buffer.h"
#include "../inc/application.h"

cirbuf_status st;
cirbuf_t *pt;
int8_t size1;

int main()
{
/*Initialization of the pointer for the circular buffer allocation*/
pt = (cirbuf_t *)malloc(sizeof(cirbuf_t));

printf("Start pointer --->%p\n\r",pt);

size1=5;

st=cirbuf_init(pt,size1);


if(st == INIT_DONE)
{
	add_element(pt,size1);
}
}
