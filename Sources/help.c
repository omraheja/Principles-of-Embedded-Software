/* Authors:Om Raheja & Isha Sawant
 * Filename:Help.c
 * Date:2nd October,2018
 * Description: This is the 1st function invoked from main.All the other functions are invoked from the help function.
*/

/*************************************************************************************************************************/

/*CODE*/

/*************************************************************************************************************************/


/* C Standard Library Headers */
#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/* Headers */
#include "../inc/functions.h"
#include "../inc/allocate_memory.h"
#include "../inc/write_memory.h"
#include "../inc/display_memory.h"
#include "../inc/write_pattern.h"
#include "../inc/verify_pattern.h"
#include "../inc/invert_block.h"
#include "../inc/exit.h"
#include "../inc/free_memory.h"

/* structure declaration */
typedef struct function_list
{
    char *input;
    void(*function_name)();      /*function pointer as an argument*/
}function_list;                  /*structure variable*/

void help()
{       
        printf("Help has been entered\n");

	/* Array of structure and it's initialization */
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

    	printf("Welcome to help!\nPress Enter to continue\n");
    	getchar();
   	 printf("Press A to allocate memory\n");
   	 printf("Press F to free memory\n");
    	printf("Press D to display memory\n");
    	printf("Press WM to write memory\n");
    	printf("Press I to invert block\n");
    	printf("Press WP to write pattern\n");
    	printf("Press V to verify pattern\n");
    	printf("Press E to exit\n");

    	/* command is a string used to store the input being entered */
    	char command[2];
    	memset(command,0,sizeof(command));
    	char yn[3];
    	do
    	{
    		printf("Enter the command you want to execute:\n");
   		scanf("%s",command);

    		/*Check if input command is invalid or not*/
        	if ((strcasecmp(command,function_list[1].input)!=0) && (strcasecmp(command,function_list[2].input)!=0) && (strcasecmp(command,function_list[3].input)!=0) && (strcasecmp(command,function_list[4].input)!=0) && (strcasecmp(command,function_list[5].input)!=0) && (strcasecmp(command,function_list[6].input)!=0) && (strcasecmp(command,function_list[7].input)!=0) && (strcasecmp(command,function_list[8].input)!=0))
        	{
            		printf("Invalid Command\n");
            		printf("Do you want to enter again?\nType yes or no\n");
            		scanf("%s",yn);
            		continue;
		}
	
		/* For calling the required function */
		for(int i=1;function_list[i].function_name;i++)
		{
            		if (strcasecmp(command,function_list[i].input)==0)
            		{
                		(*(function_list[i].function_name))();
                		break;
            		}
        	}

        	printf("Do you want to enter the function  again?\nType yes or no\n");
        	scanf("%s",yn);
        } while(strcasecmp(yn,"yes")==0);
}  
