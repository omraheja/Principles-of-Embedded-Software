/* Author:Om Raheja & Isha Sawant
 * Filename:write_memory.c
 * Date:2nd October,2018
 * Description: Writes a 32 bit number on a specified address location. Both address and value is taken from the user.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/

/* C Standard Library Headers */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

/* Headers */
#include "../inc/functions.h"

/* Write memory function writes the hex number on an address specified by the user */
void write_memory()
{       	
	uint32_t h;            /*hex number*/
	int offset;            /*offset value*/
	char n;                /*for selecting yes and no*/
	char y;	               /*for selecting offset of address*/ 
	int j;
	int flag,flag1;
        uint64_t writeadd;     /*Address at which we want to write*/

	do{
		/* Asks user if they want to enter address or offset */
		printf("Do you want to enter the address or offset?\n");
		printf(" Type 'A' for Address\n'O' for offset\n");
       		scanf(" %c",&y);

		/*To check if entered command is valid or not */
        	if(y!='o' && y!='O' && y!='a' && y!='A')
        	{
	       		printf("Invalid input!");
        	}
        	else
	       		break;

        	/* Gives user another chance to enter the input */
		printf("\nEnter Address/Offset again?\nY/N\n");
        	scanf(" %c",&n);

       	  }while(n=='y'||n=='Y');
         
	
        /* If user has chosen offset option*/
	if(y=='o'|| y=='O')
      	{
		do{
        		printf("enter offset value-0 to %d\n",(size-1));
			scanf("%d",&offset);
			printf("Offset value= %d\n",offset);

			if((offset<0) || (offset>(size-1)))
       			{
       				printf("Invalid  address\n");
       			}

       			else
       			{
       				n='y';
				printf("write address= %p",(address+offset));
				printf("\nEnter the Hex value to be written\n");
        			scanf("%x",&h);
        			*(address+offset)=h;	
				printf("The value at %p is %x\n",(address+offset),*(address+offset));
				break;
       			}
       			
			/* Asks user if they want to enter the offset again */
			printf("Do you want to enter the offset again?\n");
       			printf("Y/N\n");
       			scanf(" %c",&n);
       		}while((n=='y') || (n=='Y'));
	} 
       

       /* If user has chosen address option */
       if((y=='a')||(y=='A'))
	{
		do{
			printf("Enter the address at which you want to write data\n");
			scanf("%lx",&writeadd);

			/* To check if entered address lies in the range of allocated addresses */
			if((uint32_t *)(writeadd)<(uint32_t *)(address) || (uint32_t *)(writeadd)>(uint32_t *)(address+size))
			{
				printf("Invalid  address\n");
				flag1=0;
			}
			
			/* To check if entered address is valid or not */
			for(j=0;j<size;j++)
			{
        			if((uint32_t *)(address+j)==(uint32_t *)(writeadd))
				{
					flag=1;
					break;
				}

				else
				{
					flag=0;
				}
			}
        
	
			if(flag==0||flag1!=0)
        		{
				printf("Invalid  address\n");
        		}

			else
			{
				n='y';
        			printf("\nEnter the Hex value to be written\n");
        			scanf("%x",&h);
        			*(address+j)=h;	
         			printf("The value at %p is %x\n",(address+j),*(address+j));
        			break;
			}
			
			/* Asks the user if they want to enter the address again */
			printf("Do you want to enter the address again?\n");
			printf("Y/N\n");
			scanf(" %c",&n);
		}while((n=='y')|| (n=='Y'));
	
	}    

  
} 
