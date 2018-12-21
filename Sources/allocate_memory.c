/* Authors:Om Raheja & Isha Sawant
 * Filename:Allocate_memory.c
 * Date:2nd October,2018
 * Description: Allocates the memory size specified by the user.
   This function also checks if memory was allocated properly or not by checking the null pointer.
*/

/* ************************************************************************************************************************* */
/*                                             C STANDARD LIBRARY HEADERS                                                    */
/* ************************************************************************************************************************* */

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/* ************************************************************************************************************************* */
/*                                                     HEADERS                                                               */
/* ************************************************************************************************************************* */

#include "../inc/functions.h"
#include "../inc/allocate_memory.h"

/* ************************************************************************************************************************* */
/*                                              ALLOCATE MEMORY FUNCTION                                                     */
/* ************************************************************************************************************************* */

/* This function allocates memory specified by the user for the application */
void allocate_memory()
{
	/* Number of 32 bit words */
	printf("Enter the number of 32-bit words you want to allocate memory for\n");
	scanf("%d", &size);

	/*Use of Malloc function to allocate memory*/
	address = (uint32_t *) malloc(size*sizeof(int));


	/*To check if malloc is able to service the request for allocating memory*/
	printf("Address in allocate memory is %p\n",address);
	if (address != NULL)   //to check if memory has been allocated or not
	{
		/*Display the allocated memory*/
		for (int i = 0; i < size; i++)
		{
			printf("Address is %p\n", &address[i]);
		}
	}
}
