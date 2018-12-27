/*Authors     : Isha Sawant and Om Raheja.
 * Project 2  : Circular buffer,UART and Interrupts.
 * Course     : ECEN 5813 Principles of Embedded Software.
 * Semester   : FALL 2018.
 * Date       : 27th November 2018.
 * Filename   : application.c
 * Description: This .c file will be printing the report according to the characters entered and also print the Fibonacci series and Digits in pi if those characters have been entered.
 * */

/*Headers*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../inc/circular_buffer.h"
#include "../inc/application.h"

/*GLOBAL VARIABLES*/
int8_t c;

cirbuf_t *ptr;int8_t crr[256],h=0;
int8_t k=0,k1=1,fibo[50],num,k2=1,newb,pi[5];


/*Function to add any characters or text into the buffer with boundary checking for onslaught*/
void add_element(cirbuf_t *pt,int size)
{
    uint16_t i=0,f=1;int8_t ch;cirbuf_status st;
    ptr=pt;
    ptr->new=15;
    newb=ptr->new;

    printf("\n\r Enter the text: ");
    do
    {


           if(c==size)
            {


                    st=cirbuf_init1(ptr,newb);


                    printf("\n\r Onslaught has subsided! \n\r"); /*if count reaches 256, the application cannot take more characters into buffer */
             }
	    
	    scanf(" %c",&ch);
	    c++;
	    st=cirbuf_add(ptr,ch,c);

           if(st == ADD_SUCCESS)  /*stores the characters and increments count only when the addition of the character was a success*/
	   {
	    
	    crr[ch]++;
            report();
	    }
		    
	     
	    if(c>=newb)
	    {
		    st=cirbuf_delete(ptr,c);
	    }	    
	    

	    i++;
    

    }while(f==1);

    printf("\n\r APPLICATION DONE!");
}

/*To display the entire report*/
void report()
{
	int8_t i=0,j=0;int8_t *buffront=ptr->front;
        int8_t h1=0;

	printf("\n\r ASCII REPORT:");
        printf("\n\r CHARACTER	ASCII  	   COUNT   ");

	
		
				while(j>=0)
				{
					
				
	
					if(crr[j]>=1 && *buffront>0 && j>0 && i<c)
                                       {

					printf("\n\r      %c          %d          %d ",(char) j,j, crr[j] );
					i=i+crr[j];
					if(j>=48 && j<=57)
					{
                                        num=j-48;
                                        

					if(num==k2)
					{

						fibo[h]=num;
						k2 =k1 +k;

						k=k1;
						k1=k2;
						h++;

					}

					if(num==1 || num==3 || num==4)
					{
						pi[num]=crr[j];
					}
                                 

					buffront++;
					}
				       }

					if(i==c)
						break;
	

				    j++;
				}

				if(fibo[0]!=0)
				{
				printf("\n\n\r FIBONACCI SERIES: ");
				h1=0;
				while(fibo[h1]>0)
				{
					printf(" %d ",fibo[h1]);
			        	h1++;
				}
				}

				if(pi[1]!=0 || pi[3]!=0 || pi[4]!=0)
				{
				printf("\n\n\r DIGITS IN PI: ");
				printf("\n\n\r DIGIT	     COUNT");
                                
				if(pi[1]>0)
			        	printf("\n\r 1           %d",pi[1]);

				if(pi[3]>0)
                                        printf("\n\r 3           %d",pi[3]);

				if(pi[4]>0)
                                        printf("\n\r 4           %d",pi[4]);
				}

			
                                printf("\n\r\n Characters currently in buffer: %d",ptr->count);

				printf("\n\r\n TOTAL CHARACTERS ENTERED: %d \n\r",c);
                                

				
}
