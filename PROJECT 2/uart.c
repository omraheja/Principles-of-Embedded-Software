/* Authors    : Isha Sawant & Om Raheja
 * Project 2  : Circular buffer, UART and interrupts
 * Course     : ECEN 5813 (Principles of Embedded Software)
 * Semester   : FALL 2018
 * File name  : uart.c
 * */

/*----------------------------------------------------------------------------------------------------------*/
/*                                             START OF PROGRAM                                             */
/*----------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------*/
/*                                                 INCLUDES                                                 */
/*----------------------------------------------------------------------------------------------------------*/

#include "MKL25Z4.h"
#include "../INC/circular_buffer.h"

/*----------------------------------------------------------------------------------------------------------*/
/*                                             GLOBAL VARIABLES                                             */
/*----------------------------------------------------------------------------------------------------------*/

cirbuf_t *ptr;
int flag;
int crr[256];
int8_t rx_data;

/*----------------------------------------------------------------------------------------------------------*/
/*                                                  MACROS                                                  */
/*----------------------------------------------------------------------------------------------------------*/

#define ENABLE_CLOCK_UART0				0x400u			//Enable clock for UART0
#define BDH_VALUE					0x00			//Baud rate value higher bits
#define BDL_VALUE					0x18			//Baud rate value lower bits
#define OSR_VALUE					0x0F			//Over sampling ratio/rate(OSR) value
#define ENABLE_CLOCK_PORTA				0x0200			//Enable clock for PORTA
#define CLOCK_SELECT					0x04000000		//Use FFL output for UART Baud rate generator
#define TIE_FLAG					0x80u			//Enable Transmit Interrupt
#define RIE_FLAG					0x20u			//Enable Receive Interrupt
#define PIN_MUX_CTRL					0x0200			//Select Alternative 2
#define TE_FLAG						0x08			//Enable Transmitter
#define RE_FLAG						0x04			//Enable Receiver

/*----------------------------------------------------------------------------------------------------------*/
/*                                            FUNCTION PROTOTYPES                                           */
/*----------------------------------------------------------------------------------------------------------*/
void uart_init();
void transmit_poll();
void putst(char *);

/*----------------------------------------------------------------------------------------------------------*/
/*                                         TRANSMIT POLLING FUNCTION                                        */
/*----------------------------------------------------------------------------------------------------------*/

void transmit_poll()
{
	/*Transmit polling*/
	while(!(UART0_S1 & UART0_S1_TDRE_MASK))
	{
	}
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                            UART0 INITIALIZATION                                          */
/*----------------------------------------------------------------------------------------------------------*/

void uart_init()
{
	/*Enable clock for UART0.
	 *Select clock for baud rate generation.
	 **/
	SIM_SCGC4 |= ENABLE_CLOCK_UART0;      //Enable clock for UART0 (SIM_SCGC4_UART0_MASK= 0x400)
	SIM_SOPT2 |= CLOCK_SELECT;            //Use FFL output for UART Baud rate generator

	/*Disable UART while configuration change(UART0_C2 = 0)*/
	//UART0_C2 &= ~(TIE_FLAG | RIE_FLAG);
	UART0_C2 &= 0x00;


	/*Baud rate configuration.
	 * 48000000/(15+1)*SBR  = 57600.
	 * SBR=18 (hex).
	 * */
	 UART0_BDH = BDH_VALUE;        //0x00
	 UART0_BDL = BDL_VALUE;        //0x18

	/*Oversampling Rate.
	 * OSR=15 (dec).
	 * OSR=0F (hex).
	 *  */
	 UART0_C4 = OSR_VALUE;         //0x0F

	/*8 bit data.
	 * LOOPS:0->normal operation|Rx and Tx used as separate pins.
	 * DOZEEN:0->UART enabled in wait mode.
	 * RSRC:0->Used only when LOOP=1.
	 * M:0->Select 8 bit data frame.
	 * WAKE:0->Idle line wake up.
	 * ILT:0->Idle char bit count begins after start bit.
	 * PE:0->No parity bit.
	 * PT:0->Used only when PE=1.
	 * */
	 UART0_C1 &= 0x00;

	/*Enable Transmit Polling.
	 UART0_C2 |= 0x08;*/

	/*Enable clock for PORT A
	* SIM_SCGC5_PORTA_MASK=0x0200
	**/
	 SIM_SCGC5 |= ENABLE_CLOCK_PORTA;


	/* Make PTA1 UART0_Rx pin
	 * Make PTA2 UART0_Tx pin */
	 PORTA_PCR1 = PIN_MUX_CTRL;                    //Alternative 2
	 PORTA_PCR2 = PIN_MUX_CTRL;                    //Alternative 2

	 /*Enable Transmitter and Receiver*/
	 UART0_C2 |= (TE_FLAG | RE_FLAG);
	 //UART0_C2 |= RE_FLAG;

	 /*Enable Transmitter and Receiver Interrupts*/
	 //UART0_C2 |= (TIE_FLAG | RIE_FLAG );
	 UART0_C2 |= RIE_FLAG;

	 /*Enable global interrupts (IRQs)*/
	 __enable_irq();

	 /*Interrupt vector assignment for UART0
	  * UART0_IRQn = 12  (Interrupt source number)*/
	 NVIC_EnableIRQ(UART0_IRQn);
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                            INTERRUPT SERVICE ROUTINE                                     */
/*----------------------------------------------------------------------------------------------------------*/

void UART0_IRQHandler()
{
	//Disable all interrupts
	__disable_irq();

	/*To check if receive data buffer is empty or full.
	 * If RDRF bit = 1,then receive data buffer is full.
	 * If RDRF bit = 0,then receive data buffer is empty.
	 * */
	/*If the interrupt is RECEIVE interrupt*/
	if(UART0_S1 & UART0_S1_RDRF_MASK)
	{
		rx_data=UART0->D;
		cirbuf_add(ptr,rx_data);
		flag=1;
		crr[rx_data]++;
		cirbuf_delete(ptr);

		/*If the interrupt is TRANSMIT interrupt*/

		/*
		while(!(UART0_S1 & UART0_S1_TDRE_MASK)){
		}
		UART0->D = rx_data;
		*/
	}

	/*Enable all interrupts*/
	__enable_irq();
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                               PRINTF FUNCTION                                            */
/*----------------------------------------------------------------------------------------------------------*/

void putst(char *string)
{
	while(*string != '\0')
	{
		transmit_poll();
		UART0->D = *string;
		string++;
	}
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                              END OF PROGRAM                                              */
/*----------------------------------------------------------------------------------------------------------*/
