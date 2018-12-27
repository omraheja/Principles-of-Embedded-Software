/*Authors     : Isha Sawant and Om Raheja.
 * Project 2  : Circular buffer,UART and Interrupts.
 * Course     : ECEN 5813 Principles of Embedded Software.
 * Semester   : FALL 2018.
 * Date       : 27th November 2018.
 * Filename   : circular_buffer.c
 * Description: Responsible for the initialisation, addition and deletion of the files.
 * */


/*Header files*/

#include<stdio.h>
#include<stdlib.h>
#include<stdint.h>
#include "../inc/circular_buffer.h"

/*Global variables*/
int8_t *po;
int8_t newbuf=100,s;int n=1,n1=2;

/*To initialize the circular buffer with a given length*/
cirbuf_status cirbuf_init(cirbuf_t *ptr,int8_t len)
{
	cirbuf_status status;
        ptr->buffer=(int8_t *)malloc(sizeof(int8_t)*len);
        ptr->front = ptr->buffer;
        ptr->rear = ptr->buffer;
        s=len;
	po=(ptr->buffer);


	printf("front address--->%p\n",ptr->front);
	printf("rear address---->%p\n",ptr->rear);
	printf("buffer address-->%p\n",ptr->buffer);
	
	ptr->count = 0;
	ptr->size = len;
        status= INIT_DONE;
        return status;
}

/*To initialize new buffer, demonstrating reallocation function*/
cirbuf_status cirbuf_init1(cirbuf_t *ptr,int8_t len)
{
        cirbuf_status status;
	newbuf=ptr->new;
        
        	
        ptr->buffer = (int8_t *)realloc(ptr->buffer,sizeof(int8_t)*len);
        ptr->front = ptr->buffer;
        ptr->rear =(po+s);

        printf("front address--->%p\n",ptr->front);
        printf("rear address---->%p\n",ptr->rear);
        printf("buffer address-->%p\n",ptr->buffer);

	printf("\n\r Final Pointer:  %p",(ptr->buffer+(newbuf)));
        ptr->size =len;
        status= INIT_DONE;

        return status;
}



/*adding the element to the circular bufffer*/
cirbuf_status cirbuf_add(cirbuf_t *ptr,int8_t add_num,int8_t c)
{
	cirbuf_status status;



		
         	if(ptr->rear == ptr->buffer + ptr->size - 1 && ptr->count<(s-1))
		{
			 
			*ptr->rear=add_num;
			printf("The added value is %d at position %p\n",add_num,ptr->rear);
			ptr->rear=ptr->buffer;
			ptr->count++;
			printf("COUNT-->%d\n",ptr->count);
			status=ADD_SUCCESS;
		}
                
		if(ptr->count >=(newbuf)-1)
                 {
                        *ptr->rear=add_num;
                       
		       	printf("\n\r The added value is %d at position %p\n",add_num,ptr->rear);
                        ptr->count++;
			(ptr->rear)++;
		  	if(c==(n*newbuf))
	        	{
		       	ptr->rear=ptr->buffer;
			n++;
			}
			
		

                        status=ADD_SUCCESS;
			
	         	
                }


		else
		{
			
			*ptr->rear=add_num;
			printf("\n\r The added value is %d at position %p\n",add_num,ptr->rear);
			(ptr->rear)++;
			(ptr->count)++;
			status= ADD_SUCCESS;
		}
	
	return status;
}

/*deleting elements once buffer is full, making space for new characters to be added*/
cirbuf_status cirbuf_delete(cirbuf_t *ptr,int8_t c)
{
	cirbuf_status status;
	int8_t del_num;


		if((ptr->front == ptr->buffer + ptr->size - 1) && ptr->count<(s-1) )
		{
			del_num=*(ptr->front);
		
			printf("Deleted number is %d at position %p\n",del_num,ptr->front);
			ptr->front = ptr->buffer;
			(ptr->count)--;

			status=REMOVE_SUCCESS;

		}
		if( ptr->count >= ((newbuf)-1)) 
                {
			if(c==(n1*newbuf))
                       {
                        ptr->front = ptr->buffer;
			n1++;
                       }

		       
                        del_num=*(ptr->front);
                        printf("Deleted number is %d at position %p\n",del_num,ptr->front);
			(ptr->count)--;
                  
                        status=REMOVE_SUCCESS;
			(ptr->front)++;

                }

		else
		{
			del_num=*(ptr->front);
			printf("Deleted number is %d at position %p\n",del_num,ptr->front);
			(ptr->front)++;
			(ptr->count)--;
		
                 	status=REMOVE_SUCCESS;
		}


		
	return status;
}
