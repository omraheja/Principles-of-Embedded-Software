/* Authors:Om Raheja & Isha Sawant
 * Filename:Help.c
 * Date:2nd October,2018
 * Description: This is the 1st function invoked from main.All the other functions are invoked from the help function.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/

/*C Standard Library Headers*/
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdint.h>

/* Headers */
#include "../Includes/functions.h"
#include "../Includes/help.h"
#include "../Includes/allocate_memory.h"
#include "../Includes/free_memory.h"
#include "../Includes/display_memory.h"
#include "../Includes/write_memory.h"
#include "../Includes/invert_block.h"
#include "../Includes/write_pattern.h"
#include "../Includes/verify_pattern.h"
#include "../Includes/exit.h"

typedef struct function_list
{
    char *input;            //string to take command from user
    void(*function_name)(); //function pointer as an argument
}function_list;             //structure variable

int main()
{
        struct function_list function_list[9]={
        {"H",&help},
        {"A",&allocate_memory},
        {"F",&free_memory},
        {"D",&display_memory},
        {"WM",&write_memory},
        {"I",&invert_block},
        {"WP",&write_pattern},
        {"V",&verify_pattern},
	{"E",&om_exit},
        };

        (*(function_list[0].function_name))();
        return 0;
}

