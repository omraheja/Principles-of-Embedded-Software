/*Authors     : Isha Sawant and Om Raheja.
 * Project 2  : Circular buffer,UART and Interrupts.
 * Course     : ECEN 5813 Principles of Embedded Software.
 * Semester   : FALL 2018.
 * Date       : 26th November 2018.
 * Filename   : unittest.c
 * Credits    : https://github.com/sorabhgandhi01
 * 	      : cunit.sourceforge.net/screenshots.html
 * */


/*C Standard Library Headers*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/*Cunit test Library Headers*/
#include <CUnit/Basic.h>
#include <CUnit/Automated.h>


/*Headers*/
#include "../inc/circular_buffer.h"


/*Global variables*/
cirbuf_t *ptr;
int random_num;


/*Function Prototypes*/
int init_suite(void);
int clean_suite(void);
void circular_init_test(void);
void circular_add_test(void);
void circular_delete_test(void);
int register_test_suite(void);


/*Suite Initialization funciton*/
int suite_init(void)
{
	
	ptr = (cirbuf_t *)malloc(sizeof(cirbuf_t));
	//printf("PTR_SUITE_INIT-->%p\n",ptr);
	return 0;
}


/*Clean Suite function*/
int clean_suite(void)
{
	free(ptr);
	return 0;
}


/*Function to test the working of cirbuf_init()*/
void circular_init_test(void)
{
	//printf("RANDOM NUMBER-->%d\n\r",random_num%255);
	CU_ASSERT_EQUAL(cirbuf_init(ptr,((random_num) % 255)),9);
	//CU_ASSERT_EQUAL(cirbuf_init(ptr,-2),10);
}


/*Function to test the working of cirbuf_add*/
void circular_add_test(void)
{

	for(int z=0;z<(random_num) % 255;z++)
	{
		CU_ASSERT_EQUAL(cirbuf_add(ptr,z),2);
	}
	
	/*
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'a'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'b'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'c'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'d'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'e'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'f'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'g'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'h'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'i'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'j'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'k'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'l'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'m'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'n'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'o'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'p'),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,'q'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'r'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'s'),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,'t'),2);
	*/	
}


/*Function to test the working of cirbuf_delete*/
void circular_delete_test(void)
{
	for(int z=0;z<(random_num) % 255;z++)
        {
                CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
        }

	/*
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
        CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
	*/
}


int register_test_suite(void)
{
    CU_pSuite pSuite = NULL;
    
    /*Add suite to registry*/
    pSuite = CU_add_suite("Functionality Test of circular buffer",suite_init, clean_suite);
    if (NULL == pSuite)
    {
        return -1;
    }
    
    /*Add tests to suite*/
    if (((CU_add_test(pSuite, "circular init test", circular_init_test)) == NULL)  || 
	((CU_add_test(pSuite, "circular add test", circular_add_test)) == NULL)    ||  
	((CU_add_test(pSuite, "circular delete test", circular_delete_test)) == NULL)) 
    {
        return -1;
    }
    
    return 0;
}


int main()
{

	/*Generate Random number for automated testing*/
	srand(time(0));
	random_num=rand();
	if(random_num <= 0)
	{
		main();
	}

	/*Initialize Cunit test registry*/
	if (CU_initialize_registry() != CUE_SUCCESS)
	{
        	return CU_get_error();
	}

    	/*register_test_suite will add a test suite to the CUnit test registry*/
    	if (register_test_suite() == -1)
    	{
        	CU_cleanup_registry();
        	return CU_get_error();
    	}

	/*CUnit Basic interface used to run test cases */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

   	/* Run all the tests using the CUnit Automated interface */
	CU_set_output_filename("CB_test");
	CU_automated_run_tests();
    
	/*Clean up registry and return*/
	CU_cleanup_registry();
	return CU_get_error();
}
