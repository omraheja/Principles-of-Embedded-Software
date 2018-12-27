/* Authors    : Isha Sawant & Om Raheja
 * Project 2  : Circular buffer, UART and interrupts
 * Course     : ECEN 5813 (Principles of Embedded Software)
 * Semester   : FALL 2018
 * File name  : circular_buffer.c
 * */

/*----------------------------------------------------------------------------------------------------------*/
/*                                             START OF PROGRAM                                             */
/*----------------------------------------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------------------------------------*/
/*                                                 INCLUDES                                                 */
/*----------------------------------------------------------------------------------------------------------*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../inc/circular_buffer.h"

/*----------------------------------------------------------------------------------------------------------*/
/*                                         CIRCULAR BUFFER INITIALIZATION                                   */
/*----------------------------------------------------------------------------------------------------------*/

cirbuf_status cirbuf_init(cirbuf_t *ptr,int8_t len)
{
    cirbuf_status status;

    if(ptr == NULL || len <=0)
    {
        status = FAIL;

    }
    else
    {
    	ptr->buffer=(int8_t *)malloc(sizeof(int8_t)*len);
        ptr->front = ptr->buffer;
        ptr->rear = ptr->buffer;
        ptr->count = 0;
        ptr->size = len;
        status= INIT_DONE;
    }
    return status;
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                            CIRCULAR BUFFER FULL TEST                                     */
/*----------------------------------------------------------------------------------------------------------*/

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

/*----------------------------------------------------------------------------------------------------------*/
/*                                            CIRCULAR BUFFER EMPTY TEST                                     */
/*----------------------------------------------------------------------------------------------------------*/

cirbuf_status cirbuf_checkempty(cirbuf_t *ptr)
{
    cirbuf_status status;

    if(ptr==NULL)
    {
        status =FAIL;
    }
    else
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

/*----------------------------------------------------------------------------------------------------------*/
/*                                           ADD ELEMENT TO CIRCULAR BUFFER                                 */
/*----------------------------------------------------------------------------------------------------------*/

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
            ptr->rear=ptr->buffer;
            ptr->count++;
            status=ADD_SUCCESS;
        }
        else
        {
            *ptr->rear=add_num;
            (ptr->rear)++;
            (ptr->count)++;
            status= ADD_SUCCESS;
        }
    }
    return status;
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                        DELETE ELEMENT TO CIRCULAR BUFFER                                 */
/*----------------------------------------------------------------------------------------------------------*/

cirbuf_status cirbuf_delete(cirbuf_t *ptr)
{
    cirbuf_status status;

    int8_t del_num;

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
            del_num=*(ptr->front);
            ptr->front = ptr->buffer;
            (ptr->count)--;
            status=REMOVE_SUCCESS;
        }
        else
        {
            del_num=*(ptr->front);
            (ptr->front)++;
            (ptr->count)--;
            status=REMOVE_SUCCESS;
        }

    }
    return status;
}

/*----------------------------------------------------------------------------------------------------------*/
/*                                              END OF PROGRAM                                              */
/*----------------------------------------------------------------------------------------------------------*/
