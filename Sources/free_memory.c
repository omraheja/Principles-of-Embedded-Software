/* Author:Om Raheja & Isha Sawant
 * Filename:free_memory.c
 * Date:2nd October,2018
 * Description: Frees the allocated memory.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/


/* C Standard Library Headers */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<stdint.h>
#include "../Includes/functions.h"

/* Free Function used to free the memory allocated for the user application */
void free_memory()
{       
    
      free(address);
}  
