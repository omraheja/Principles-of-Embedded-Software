#include <stdio.h>
#include <stdlib.h>

#include <CUnit/Basic.h>
#include <CUnit/Automated.h>

#include "../inc/circular_buffer.h"

cirbuf_t *ptr;

int init_suit(void)
{
	
	ptr = (cirbuf_t *)malloc(sizeof(cirbuf_t));
	return 0;
}

int clean_suite(void)
{
	return 0;
}


void circular_init_test(void)
{
	CU_ASSERT_EQUAL(cirbuf_init(ptr,10),9);
}


void circular_add_test(void)
{
	CU_ASSERT_EQUAL(cirbuf_add(ptr,10),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,20),2);
	CU_ASSERT_EQUAL(cirbuf_add(ptr,30),2);
        CU_ASSERT_EQUAL(cirbuf_add(ptr,40),2);

}

void circular_delete_test(void)
{
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
	CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
        CU_ASSERT_EQUAL(cirbuf_delete(ptr),3);
}



int register_test_suite(void) {

    CU_pSuite pSuite = NULL;

   	pSuite = CU_add_suite("Functionality Test of circular buffer", init_suit, clean_suite);
    if (NULL == pSuite) {
        return -1;
    }
    /*Adding tests to the suite */
    if ((NULL == CU_add_test(pSuite, "circular init test", circular_init_test))  ||
    	(NULL == CU_add_test(pSuite, "circular add test", circular_add_test)) ||
    	(NULL == CU_add_test(pSuite, "circular delete test", circular_delete_test))) 
    {
        return -1;
    }
    return 0;
}


int main()
{
    /* initialize the CUnit test registry */
    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

 	//register_test_suite will add a test suite to the CUnit test registry
    if (register_test_suite() == -1) {
        CU_cleanup_registry();
        return CU_get_error();
    }

	/* Run all tests using CUnit Basic interface */
	CU_basic_set_mode(CU_BRM_VERBOSE);
	CU_basic_run_tests();

    /* Run all tests using the CUnit Automated interface */
	CU_set_output_filename("CB_test");
	CU_automated_run_tests();

    CU_cleanup_registry();
    return CU_get_error();
}
