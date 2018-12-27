/*Authors: Isha Sawant and Om Raheja
 * Project 2:Circular buffers, UART and Interrupts
 * Course: ECEN 5813 Principles of Embedded Software
 * Semester: FALL 2018
 * Date: 27th November 2018
 * */


/*Standard Library Headers*/
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>


/*Structure for Circular Buffer
 *@members: 1)buffer : After malloc,stores the base/starting address of the circular buffer.
            2)front  : Increments after each element has been deleted from the circular buffer..
	    3)rear   : Increments after each elements has been added to the circular buffer.
	    4)count  : Keeps count of the number of elements present in the circular buffer.
	    5)size   : Stores the length of the circular buffer.
            6)new    : Stores size for reallocation.
*/ 
typedef struct cirbuf{
	int8_t *buffer;
	int8_t *front;
	int8_t *rear;
	int8_t count;
	int8_t size;
	int8_t new;
}cirbuf_t;


/*Checks the returned status*/
typedef enum{
	SUCCESS,
	FAIL,
	ADD_SUCCESS,
	REMOVE_SUCCESS,
	REMOVE_FAILED,
	BUFFER_FULL,
	BUFFER_NOT_FULL,
	BUFFER_EMPTY,
	BUFFER_NOT_EMPTY,
	INIT_DONE
}cirbuf_status;




/*Function prototypes*/


/* @Function name : cirbuf_init() and cirbuf_init1()
 * @Parameters    : cirbuf_t *ptr , int8_t len
 * @Description   : Configures and Inititalizes the circular buffer parameters.
 * @return        : INIT_DONE or INIT_NOT_DON
*/

cirbuf_status cirbuf_init (cirbuf_t *ptr,int8_t len);
cirbuf_status cirbuf_init1 (cirbuf_t *ptr,int8_t len);

/* @Function name : cirbuf_add()
 * @Parameters    : cirbuf_t *ptr , int8_t add_num , int8_t c
 * @Description   : Adds a new element to the circular buffer and increments the
 * 	 	    rear pointer.
 * @return        : ADD_SUCCESS
 * */

cirbuf_status cirbuf_add (cirbuf_t *ptr,int8_t add_num,int8_t c);

/* @Function name : cirbuf_delete()
 * @Parameters    : cirbuf_t *ptr , int8_t c
 * @Description   : Deletes an elemet from the circular buffer and increments the
 * 		    front pointer.
 * @return        : REMOVE_SUCCESS or REMOVE_FAILED
*/
cirbuf_status cirbuf_delete (cirbuf_t *ptr,int8_t c);



