/* Author:Om Raheja & Isha Sawant
 * Filename:invert_block.c
 * Date:2nd October,2018
 * Description: Inverts the data at a specified location by using xor opertion.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/

/* C Standard Library Headers */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

/* Headers */
#include "../Includes/functions.h"

/* 'numb' is the number of 32 bit words to be inverted */
void invert_block()
{      
        uint64_t invadd;       /*Address at which inversion has to be performed*/
	int flag,flag1;
	int j;
	int k;
	int offset;           /*offset value*/
	int numb;
	char n;
	char y;
        do{
		printf("Do you want to enter the address or offset?\n");
		printf(" Type 'A' for Address\n'O' for offset\n");
       		scanf(" %c",&y);

       		if(y!='o' && y!='O' && y!='a' && y!='A')
       		{
               		printf("Invalid input!");
       		}
       		else
               		break;
       		printf("\nEnter Address/Offset again?\nY/N\n");
       		scanf(" %c",&n);

       	 }while(n=='y'||n=='Y');

         
        //If offset option is selected
        if(y=='o'||y=='O')
	{
		do{	
			printf("Enter the offset value\n");
			scanf("%d",&offset);
        		/* To check if entered offset is valid or not */
			if(offset<0 || offset>(size-1))
			{
				printf("Invalid address\n");
			}

			else
			{
				n='y';
				printf("Enter the number of 32-bit words to be inverted\n");
       				scanf("%d",&numb);
         			/* To calculate the amount of time required to perform inversion */
				clock_t ts=clock();
				/* Perform inversion */
			 	for(j=0;j<numb;j++)
                		*(address+offset+j)=*(address+offset+j)^(0xFFFFFFFF);
        			ts=clock()-ts;
        			double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;
				/* Print the time taken to perform inversion */
        			printf("\nTime taken for inverting the block is %f seconds\n",cpu_time_used);
				break;
			}
			
			/* Asks the user if they want to enter the offset value again */
			printf("Do you want to enter the offset value again?\n");
			printf("Y/N\n");
			scanf(" %c",&n);
		}while((n=='y')||(n=='Y'));
	}

	//If address option is selected
	if((y=='a') ||(y=='A'))
	{
 		do{
 			printf("Enter the address for dispaying data:\n");
 			scanf("%lx",&invadd);

			/* To check if the entered address is valid or not */
  			if((uint32_t *)(invadd)<(uint32_t *)(address) || (uint32_t *)(invadd)>(uint32_t *)(address+size))
	 		{
  				printf("Invalid address\n");
  				flag1=0;
	 		}
 
	 		for(j=0;j<size;j++)
			{
        			if((uint32_t *)(address+j)==(uint32_t *)(invadd))
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
 				printf("Enter the number of 32-bit words to be inverted\n");
 				scanf(" %d",&numb);
				/* To calculate the amount of time required to perform inversion */
 				clock_t ts=clock();
				/* Perform Inversion */
				for(k=0;k<numb;k++)
				{
					*(address+j+k)=*(address+j+k)^(0xFFFFFFFF);
					j++;
				}
 				ts=clock()-ts;
        			double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;
				/* Print the time taken to perform inversion */
        			printf("\nTime taken for inverting the block is %f seconds\n",cpu_time_used);
 				break;
			}	
			
			 /* Asks the user if they want to enter the addres again */
	 		printf("Do you want to enter the address again?\n");
	 		scanf(" %c",&n);
	 	}while((n=='y')||(n=='Y'));
	}
}  
