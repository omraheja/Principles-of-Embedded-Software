/* Author:Om Raheja & Isha Sawant
 * Filename:display_memory.c
 * Date:2nd October,2018
 * Description: Displays the number of 32 bit words specified by the user at the given address.
*/

/* ************************************************************************************************************************* */
/*                                             C STANDARD LIBRARY HEADERS                                                    */
/* ************************************************************************************************************************* */
#include<stdio.h>
#include<string.h>
#include<stdint.h>
#include<stdlib.h>

/* ************************************************************************************************************************* */
/*                                                     HEADERS                                                               */
/* ************************************************************************************************************************* */
#include "../Includes/functions.h"

/* ************************************************************************************************************************* */
/*                                             DISPLAY MEMORY FUNCTION                                                       */
/* ************************************************************************************************************************* */

/* Display function displays the value stored at a specified address in hexadecimal form */
void display_memory()
{
	/* variable declaration */
	uint64_t dispadd;      /*Address at which data is to be viewed*/
	int  j;	
	int  flag;
	int  flag1;
	int  k;
	int  offset;
	int  num;
	char n;
	char y;
	
	/* Ask user to enter either address or the offset value */
	do{
		printf("Do you want to enter the address or offset?\n");
		printf(" Type 'A' for Address\n'O' for offset\n");
		scanf(" %c",&y);
		
		/*To check for invalid input*/
		if(y!='o' && y!='O' && y!='a' && y!='A')
		{
			printf("Invalid input!");
		}
		else
			break;
		printf("\nEnter Address/Offset again?\nY/N\n");
		scanf(" %c",&n);
	}while(n=='y'||n=='Y');
	
	/* If offset option is selected */
	if((y=='o') ||(y=='O'))
	{
		do
		{
			printf("Enter the offset value:\n");
			scanf("%d",&offset);
			
			/* To check if entered offset lies within the permittable range */
			if((offset<0) || (offset>(size-1)))
			{
 	 			printf("Invalid address\n");
	 		}	
 			else
 			{
 				n='y';
				
				/* Number of 32 bit words to be displayed */
 				printf("Enter the number of 32-bit words to be displayed\n");
 				scanf(" %d",&num);
				
				/* Print the data in hexadecimal format at the address */
				for(j=0;j<num;j++)
				{
	 				printf("Value at %p is %x\n",((address)+(offset)+j),*((address)+(offset)+j));
				}	
	 			break;
 			} 

			/* Ask user if they want to enter the addres again */
	 		printf("Do you want to enter the address again?\n");
 			scanf(" %c",&n);
		}while((n=='y')||(n=='Y'));
	}
	
	/* If address option is selected */
	if((y=='a') ||(y=='A'))
	{
		do
		{
			printf("Enter the address for dispaying data:\n");
	 		scanf("%lx",&dispadd);

	 		/*To check if entered address is valid or not */
 	 		if((uint32_t *)(dispadd)<(uint32_t *)(address) || (uint32_t *)(dispadd)>(uint32_t *)(address+size))
 			{
  				printf("Invalid address\n");
  				flag1=0;
 			}
 
	 		/* To check if entered address is valid or not */
			for(j=0;j<size;j++)
			{
				if((uint32_t *)(address+j)==(uint32_t *)(dispadd))
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
				printf("Enter the number of 32-bit words to be displayed\n");
				scanf(" %d",&num);
				
				/* Print the data in hexadecimal form at the specified address */
				for(k=0;k<num;k++)
				{
					printf("Value at %p is %x\n",(address+j),*(address+j));
					j++;
				}
				break;
			}
			printf("Do you want to enter the address again?\n");
			scanf(" %c",&n);
		}while((n=='y')||(n=='Y'));
	}
}  
