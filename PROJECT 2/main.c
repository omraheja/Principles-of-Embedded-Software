/* Authors    : Isha Sawant & Om Raheja
 * Project 2  : Circular buffer, UART and interrupts
 * Course     : ECEN 5813 (Principles of Embedded Software)
 * Semester   : FALL 2018
 * File name  : main.c
 * */

/*----------------------------------------------------------------------------------------------------------*/
/*                                             START OF PROGRAM                                             */
/*----------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------*/
/*                                                 INCLUDES                                                 */
/*----------------------------------------------------------------------------------------------------------*/

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "../INC/circular_buffer.h"

/*----------------------------------------------------------------------------------------------------------*/
/*                                             GLOBAL VARIABLES                                             */
/*----------------------------------------------------------------------------------------------------------*/

int flag;
int crr[256];
cirbuf_t *ptr;
int8_t rx_data;

/*----------------------------------------------------------------------------------------------------------*/
/*                                            FUNCTION PROTOTYPES                                           */
/*----------------------------------------------------------------------------------------------------------*/

void uart_init();
void putst(int8_t *string);

/*----------------------------------------------------------------------------------------------------------*/
/*                                                   MACROS                                                 */
/*----------------------------------------------------------------------------------------------------------*/
/* Reference for Blinking LED :
 * Freescale ARM Cortex-M Embedded Programming
 * Using C language by Muhammad Ali Mazidi,
 * Shujen Chenz Sarmad Naimi, Sepehr Naimi.
 *
 * Explaination :
 * 1) SIM_SCGC5:
 * The System clock gating
 * control register 5 is used in order
 * select the PORTB bit to control the
 * clock gate to the PORTB module.
 *
 * 2)PORTB_PCR19 :
 * This register is used to select
 * the Pin MUX control as a GPIO.
 *
 * 3)GPIOB_PDDR :
 * This register is the Port Data direction.
 * It is used to configure individual port pins
 * for input or output.
 *
 * 4)GPIOB_PDOR :
 * This register is the Port Data Output.
 * It is used to toggle the LED.
 * 0-> indicates that a logic 0 is driven
 * on the pin,if the pin has been configured
 * for general purpose output.
 * 1-> indicates that alogic 1 is driven
 * on the pin,if the pin has been configured
 * for general purpose output.
 *
 * */

/* System Integration Module System Clock Gating Control Register 5*/
#define SIM_SCGC5 (*((volatile unsigned int*)0x40048038))
/* Port B Pin Control Register 19*/
#define PORTB_PCR19 (*((volatile unsigned int*)0x4004A04C))
/* Port B Data Direction Register */
#define GPIOB_PDDR (*((volatile unsigned int*)0x400FF054))
/* Port B Data Output Register */
#define GPIOB_PDOR (*((volatile unsigned int*)0x400FF040))

/*----------------------------------------------------------------------------------------------------------*/
/*                                              DELAY FUNCTION                                              */
/*----------------------------------------------------------------------------------------------------------*/

void delayms(int t)
{
	int i,j;

	for(i=0;i<t;i++)
	{
		for(j=0;j<7000;j++)
		{

		}
	}
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                       LED INITIALIZATION FUNCTION                                        */
/*----------------------------------------------------------------------------------------------------------*/

void led_init()
{
	SIM_SCGC5 |= 0x400;
	PORTB_PCR19 = 0x100;
	GPIOB_PDDR |=0x80000;
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                          LED BLINK FUNCTION                                              */
/*----------------------------------------------------------------------------------------------------------*/

void led_blink()
{
	GPIOB_PDOR &= ~(0x80000);
	delayms(10);
	GPIOB_PDOR |= 0x80000;
	delayms(10);
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                           LED DISABLE FUNCTION                                           */
/*----------------------------------------------------------------------------------------------------------*/

void led_disable()
{
	GPIOB_PDOR |= 0x00000;
	delayms(10);
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                               MAIN FUNCTION                                              */
/*----------------------------------------------------------------------------------------------------------*/

int main (void)
{
	unsigned long int msg[100]={0};
	cirbuf_status s;
	uart_init();
    ptr=(cirbuf_t *)(malloc(sizeof(cirbuf_t)));

    s=cirbuf_init(ptr,1);

    if(s== FAIL)
    {
       sprintf(msg,"\n\r ALLOCATION FAILED \n\r");
       putst(msg);
    }
    if(s== INIT_DONE)
    {


    led_init();

    while(1)
    {
    	int8_t str[20]={0};
    	int8_t report[20]={0};
    	unsigned long int count=1;
    	unsigned long int counter[100]={0};
    	unsigned long int term=1;
    	unsigned long int teraterm[100]={0};

    	unsigned long int a,b;
    	a=0;
    	b=1;

    	while(count>=0)
    	{
    		/*FIBONACCI SERIES
    		 * eg. 1 1 2 3 5 8 13 21 34 .....
    		 * */

    		sprintf(counter,"\n\r%lu  \n\r",count);
    		putst(counter);
    		count=a+b;
    		a=b;
    		b=count;
    		if(count>65535)
    		{
    			a=0;
    			b=1;
    		}

    		for(int k=0;k<65535;k++)
    		{
    			//for(int j=0;j<10;j++);
    		}


    		/*SERIES DESCRIPTION :
    		 * 1/(POWER OF 2)
    		 * eg.1/1 1/2 1/4 1/8 1/16 1/32......
    		 * */

    		/*sprintf(teraterm,"\n\r 1/%lu \n\r",term);
    		putst(teraterm);
    		term=(term)*2;
    		if(term>65536)
    		{
    			term =1;
    		}

    		for(int k=0;k<65535;k++)
    		{
    			//for(int j=0;j<10;j++);
    		}
    		*/

    		led_blink();

    		/*REPORT GENERATION*/
    		if(flag==1)
    		{
    			delayms(2);
    			sprintf(report,"******REPORT******");
    			putst(report);
    			for(int i=0;i<256;i++)
    			{
    				if(crr[i] != 0)
    				{
    					led_disable();
    					sprintf(str,"\n\r%c --> %d\n\r",i,crr[i]);
    					putst(str);
    				}
    			}
    			flag=0;
    			}
    		}
    	}
	}
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                              END OF PROGRAM                                              */
/*----------------------------------------------------------------------------------------------------------*/
