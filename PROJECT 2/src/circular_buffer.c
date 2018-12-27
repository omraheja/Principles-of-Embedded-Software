/*Authors     : Isha Sawant and Om Raheja.
 * Project 2  : Circular buffer,UART and Interrupts.
 * Course     : ECEN 5813 Principles of Embedded Software.
 * Semester   : FALL 2018.
 * Date       : 26th November 2018.
 * Filename   : circular_buffer.c
 * */

/*C Standard Library Headers*/
#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>

/*Headers*/
#include "../inc/circular_buffer.h"

/*Circular buffer Initialization function*/
cirbuf_status cirbuf_init(cirbuf_t *ptr,int len)
{
	//printf("ptr---->%p\n\r",ptr);
	cirbuf_status status;
	if((ptr == NULL) || (len <=0))
	{
		//printf("INSIDE INIT_NOT_DONE\n\r");
		status = INIT_NOT_DONE;
	}
	else
       	{
        	ptr->buffer=(int8_t *)malloc(sizeof(int8_t)*len);
        	ptr->front = ptr->buffer;
        	ptr->rear = ptr->buffer;
        
		/*
		printf("front address--->%p\n",ptr->front);
		printf("rear address---->%p\n",ptr->rear);
		printf("buffer address-->%p\n",ptr->buffer);
		*/
	
		ptr->count = 0;
		ptr->size = len;
        	status= INIT_DONE;
	}	
	return status;
}

/*Function to check if Circular buffer is full*/
cirbuf_status cirbuf_checkfull(cirbuf_t *ptr)
{
	cirbuf_status status;
	
	if(ptr==NULL)
	{
		status=FAIL;
	}
	else if(ptr->count == ptr->size)
	{
		status=BUFFER_FULL;
	}
	else
	{
		status=BUFFER_NOT_FULL;
	}
	return status;
}


/*Function to check if the Circular buffer is Empty*/
cirbuf_status cirbuf_checkempty(cirbuf_t *ptr)
{
	cirbuf_status status;

	if(ptr==NULL)
	{
		status =FAIL;
	}
	else
	//if((ptr->front == ptr->rear)  && (ptr->front == ptr->buffer))
	if(ptr->count == 0)
	{
		status=BUFFER_EMPTY;
	}
	else
	{
		status=BUFFER_NOT_EMPTY;
	}
	return status;
}

/*Function to add elements to the Circular buffer*/
cirbuf_status cirbuf_add(cirbuf_t *ptr,int8_t add_num)
{
	cirbuf_status status;

	status = cirbuf_checkfull(ptr);

	if(status == FAIL)
	{
		printf("\n\rMalloc failed\n\r");
	}
	else if(status == BUFFER_FULL)
	{
		printf("BUFFER is FULL! Cannot add element\n");
	}
	else if(status == BUFFER_NOT_FULL)
	{	
		if(ptr->rear == ptr->buffer + ptr->size - 1)
		{
			*ptr->rear=add_num;
//			printf("The added value is %c at position %p\n",add_num,ptr->rear);
			ptr->rear=ptr->buffer;
			ptr->count++;
			printf("COUNT-->%d\n\r",ptr->count);
			status=ADD_SUCCESS;
		}
		else
		{
			*ptr->rear=add_num;
//			printf("The added value is %c at position %p\n",add_num,ptr->rear);
			(ptr->rear)++;
			(ptr->count)++;
			printf("COUNT-->%d\n\r",ptr->count);
			status= ADD_SUCCESS;
		}
	}
	return status;
}

/*Function to delete elements from the Circular buffer*/
cirbuf_status cirbuf_delete(cirbuf_t *ptr)
{
	cirbuf_status status;
	
//	int8_t del_num;

	status = cirbuf_checkempty(ptr);

	if(status ==FAIL)
	{
		printf("\n\rMalloc failed\n\r");
	}

	else if(status == BUFFER_EMPTY)
	{
		printf("BUFFER is EMPTY! Cannot delete element\n");
		status=REMOVE_FAILED;
	}
	else if(status == BUFFER_NOT_EMPTY)
	{
		
		if(ptr->front == ptr->buffer + ptr->size - 1)
		{
//			del_num=*(ptr->front);
//			printf("Deleted number is %c at position %p\n",del_num,ptr->front);
			ptr->front = ptr->buffer;
			(ptr->count)--;
			printf("COUNT-->%d\n\r",ptr->count);
			status=REMOVE_SUCCESS;

		}
		else
		{
//			del_num=*(ptr->front);
//			printf("Deleted number is %c at position %p\n",del_num,ptr->front);
			(ptr->front)++;
			(ptr->count)--;
			printf("COUNT-->%d\n\r",ptr->count);
			status=REMOVE_SUCCESS;
		}
	}
	return status;
}
