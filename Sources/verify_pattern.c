/* Author:Om Raheja & Isha Sawant
 * Filename:verify_memory.c
 * Date:2nd October,2018
 * Description: Verifies the pseudo random number at the given location.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/


/* C Standard Library Headers */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>

/* Headers */
#include "../Includes/functions.h"

/*Verify pattern function verifies the generated pattern with the one generated in the write pattern function*/
void verify_pattern()
{
	uint64_t vpadd;         /*Addres at which we want to verify pattern*/
        int j,k,flag,flag1,l;
        char y;
	int len;                /*Enter the length*/
	int offset;             /*offset value*/
	int seed;               /*seed value*/
	char n;
       
	do{
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
       		printf("\nEnter Address/Offset again?\nY/N\n");
       		scanf(" %c",&n);

       	}while(n=='y'||n=='Y');


       /*If offset option is selected*/
       if(y=='o'||y=='a')
       {
        	do{
        		printf("Enter the offset value\n");
        		scanf("%d",&offset);
        		
			/*Check if input offset is valid or not*/
			if(offset<0 || offset>(size-1))
        		{
        			printf("Invalid address");
        		}
        		else
        		{
        			n='y';
				printf("Enter the length of random number\n");
      				scanf("%d",&len);
        			printf("Enter the seed value\n");
        			scanf("%u",&seed);
        			/*Start timer to measure time taken to verify pattern*/
				clock_t ts=clock();
        			int p=1;
				/*Generate pseudo random number*/
        			for(int l=1;l<=len;l++)
        			{
        				p=p*10;
        			}

        			/*Pseudo random number*/
				r=((-1)*(((12345678*seed)+(1234*len)+123)%p));
       				
				/*Check if patterns match or not*/
        			if(x==r)
        			{
        				printf("Pattern Verified\n");
        			}
        			else
        			{
        				printf("Pattern Verification Failed!\n");
       				}
        			
				ts=clock()-ts;
        			double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;
				/*Print the time taken to verify pattern*/
        			printf("\nTime taken:%f seconds\n",cpu_time_used);

        			break;	
        		}
        	
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
 		scanf("%lx",&vpadd);

		/*To check if entered address is valid or not*/
	 	 if((uint32_t *)(vpadd)<(uint32_t *)(address) || (uint32_t *)(vpadd)>(uint32_t *)(address+size))
 		{
  			printf("Invalid address\n");
 	 		flag1=0;
 		}
 
	 	for(j=0;j<size;j++)
		{
        		if((uint32_t *)(address+j)==(uint32_t *)(vpadd))
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
	 		printf("Enter the length of random number\n");
        		scanf("%d",&len);
        		printf("Enter the seed value\n");
        		scanf("%u",&seed);
        		clock_t ts=clock();
       			int p=1;
        		for(int l=1;l<=len;l++)
        		{
        			p=p*10;
        		}
			
			/*Pseudo random number*/
		        r=((-1)*(((12345678*seed)+(1234*len)+123)%p));

			/*Check if patterns match*/
			if(x==r)
			{
        			printf("Pattern Verified\n");
        		}
        		else
        		{
        			printf("Pattern Verification Failed!\n");
        		}
        		
			ts=clock()-ts;
        		double(cpu_time_used)=((double)(ts))/CLOCKS_PER_SEC;
        		
			/*Print the time taken to verify pattern*/
			printf("\nTime taken:%f seconds\n",cpu_time_used);
			break;
		}
 	
		printf("Do you want to enter the address again?\n");
 		scanf(" %c",&n);
 		}while((n=='y')||(n=='Y'));
	}
}

