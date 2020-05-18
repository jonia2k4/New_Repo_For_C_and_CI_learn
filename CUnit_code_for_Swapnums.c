#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void swap(int *a, int *b)
{
   int temp;
   temp = *b;
   *b = *a;
   *a = temp;   
}


void Swap_number_CUnitTest()
 {
    int nums[2] = {10, 15};
 
     swap(&nums[0],&nums[1]);
	 
     CU_ASSERT_EQUAL(nums[0],15);
     CU_ASSERT_EQUAL(nums[1],10);
 }
 
void main()
 {
CU_initialize_registry();
CU_pSuite suite = CU_add_suite("swapnum_test", 0, 0);

CU_add_test(suite, "swap_fun", Swap_number_CUnitTest);

CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();

}
