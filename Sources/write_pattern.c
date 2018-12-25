/* Author:Om Raheja & Isha Sawant
 * Filename:write_pattern.c
 * Date:2nd October,2018
 * Description: Writes a pseudo random number on a specified address location.The inputs taken from the user are length , address and the seed value required to generate the pseudo random number.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/


/* C Standard Library headers */
#include<stdio.h>
#include<time.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>

/* Headers */
#include "../Includes/functions.h"

/*Write pattern is used to write a pseudo random number on a specific address specified by the user */
void write_pattern()
{      
        uint64_t wpadd;      /*Address at which we want to write pattern*/
        int j;
        int k;
        int l;
        int num;
        int flag,flag1;
        int len;             /*Enter the length*/
        int seed;            /*Enter the seed value*/
	int offset;          /*Offset value*/
	char n;	
	char y;
        do{
       		/* Asks the user to enter address or offset */
		printf("Do you want to enter the address or offset?\n");
       		printf(" Type 'A' for Address\n'O' for offset\n");
       		scanf(" %c",&y);

       		/*To check if inputed command is valid or not*/
       		if(y!='o' && y!='O' && y!='a' && y!='A')
       		{
               		printf("Invalid input!");

       		}
       		else
               		break;

		/*Ask user if they want to enter the address/offset again */
       		printf("\nEnter Address/Offset again?\nY/N\n");
       		scanf(" %c",&n);

      	 }while(n=='y'||n=='Y');



	/*If offset option is selected*/
	if(y=='o'||y=='O')
	{
		do{
			printf("Enter the offset value\n");
        		scanf("%d",&offset);

			if(offset<0 || offset>(size-1))
			{
				printf("Invalid address");
			}
			else
			{
				n='y';
				/* Enter the length of random number */
	 			printf("Enter the length of the random number\n");
        			scanf("%d",&len);

				/* Enter the seed value */
        			printf("Enter the seed value\n");
        			scanf("%d",&seed);

				/* Start timer to measure the time taken to generate the pseudo-random number */
        			clock_t ts =clock();
        			int p=1;
     
       				/*To generate pseudo random number*/
        			for(l=1;l<=len;l++)
        			{
         				p=p*10;
        			}

				/* Pseudo-random number */        			
				x=((-1)*(((12345678*seed)+(1234*len)+123)%p));
        			*(address+offset)=x;
        			printf("The pseudo-random number generated is %d\n",x);
        			ts=clock()-ts;
        			double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;

				/*Print the time taken to generate the pseudo-random number */
        			printf("Time taken: %f seconds\n",cpu_time_used);
				break;
			}
			
			/*Ask user if they want to enter the offset again*/
			printf("Do you want to enter the offset again?\n");
			printf("Y/N\n");
			scanf(" %c",&n);
		 }while((n=='y')||(n=='Y'));
	}

	/*If address option is selected*/
	if(y=='a'||y=='A')
	{
        	do{
	 		printf("Enter the address for writing pattern:\n");
 			scanf("%lx",&wpadd);

			/*To check if address is valid or not*/
 	 		if((uint32_t *)(wpadd)<(uint32_t *)(address) || (uint32_t *)(wpadd)>(uint32_t *)(address+size))
 			{
  				printf("Invalid address\n");
  				flag1=0;
 			}
 
			/* To check if the entered address is valid or not */
 			for(j=0;j<size;j++)
			{
        			if((uint32_t *)(address+j)==(uint32_t *)(wpadd))
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
				printf("Enter the length of the random number\n");
        			scanf("%d",&len);
        			printf("Enter the seed value\n");
        			scanf("%d",&seed);
				/*Start timer to measure the time taken to generate the pseudo random number*/
				clock_t ts =clock();	
				int p=1;

				/*To generate pseudo random number*/
				for(l=1;l<=len;l++)
				{
	 				p=p*10;
				}

				/* Generate the pseudo random number */
				x=((-1)*(((12345678*seed)+(1234*len)+123)%p));	//pseudo-random number
				*(address+j)=x;
				printf("The pseudo-random number generated is %d\n",x);
				ts=clock()-ts;
				double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;
				/*Print the time taken to generate pseudo random number*/
				printf("Time taken: %f seconds\n",cpu_time_used);
				break;
 			}
 			printf("Do you want to enter the address again?\n");
 			scanf(" %c",&n);
 		}while((n=='y')||(n=='Y'));
	}
}  
