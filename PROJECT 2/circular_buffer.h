
/* Authors    : Isha Sawant & Om Raheja
 * Project 2  : Circular buffer, UART and interrupts
 * Course     : ECEN 5813 (Principles of Embedded Software)
 * Semester   : FALL 2018
 * File name  : circular_buffer.h
 * */

/*----------------------------------------------------------------------------------------------------------*/
/*                                             START OF PROGRAM                                             */
/*----------------------------------------------------------------------------------------------------------*/

#ifndef INC_CIRCULAR_BUFFER_H_
#define INC_CIRCULAR_BUFFER_H_

/*----------------------------------------------------------------------------------------------------------*/
/*                                                 INCLUDES                                                 */
/*----------------------------------------------------------------------------------------------------------*/

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/*----------------------------------------------------------------------------------------------------------*/
/*                                       STRUCTURE FOR CIRCULAR BUFFER                                      */
/*----------------------------------------------------------------------------------------------------------*/

typedef struct cirbuf{
    int8_t *buffer;
    int8_t *front;
    int8_t *rear;
    int8_t count;
    int8_t size;
    int8_t new_len;
}cirbuf_t;

/*----------------------------------------------------------------------------------------------------------*/
/*                                         STRUCTURE TO CHECK STATUS                                        */
/*----------------------------------------------------------------------------------------------------------*/

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
    INIT_DONE,
    INIT_NOT_DONE
}cirbuf_status;

/*----------------------------------------------------------------------------------------------------------*/
/*                                            FUNCTION PROTOTYPES                                           */
/*----------------------------------------------------------------------------------------------------------*/

cirbuf_status cirbuf_init (cirbuf_t *ptr,int8_t len);
cirbuf_status cirbuf_checkfull (cirbuf_t *ptr);
cirbuf_status cirbuf_checkempty (cirbuf_t *ptr);
cirbuf_status cirbuf_add (cirbuf_t *ptr,int8_t add_num);
cirbuf_status cirbuf_delete (cirbuf_t *ptr/*,int8_t del_num*/);
cirbuf_status cirbuf_display (cirbuf_t *ptr);

#endif /* INC_CIRCULAR_BUFFER_H_ */

/*----------------------------------------------------------------------------------------------------------*/
/*                                              END OF PROGRAM                                              */
/*----------------------------------------------------------------------------------------------------------*/

