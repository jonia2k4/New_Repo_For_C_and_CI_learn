#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void swap(int*, int*);
int prime_number(int);

void swap(int *a, int *b)
{
   int temp;
   temp = *b;
   *b = *a;
   *a = temp;   
}

int prime_number(int num)
{
/* prime numbers: 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
               53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, */
int i;
int p;

for(i=1; i<=num; i++)
   {
      if(num%i==0)
      {
         p++;
      }
   }
   if(p==2)
   {
     return 1;
   }
   else
   {
    return 0;
   }
}

void Prime_numberCUnitTest(int N)
{

CU_ASSERT(prime_number(19) == 1);
CU_ASSERT(prime_number(1) == 0);
CU_ASSERT(prime_number(79) == 1);
CU_ASSERT(prime_number(100) == 0);
}

void Swap_number_CUnitTest()
 {
    int nums[2] = {10, 15};
 
     swap(&nums[0],&nums[1]);
	 
     CU_ASSERT_EQUAL(nums[0],15);
     CU_ASSERT_EQUAL(nums[1],10);
 }
 
int main()
 {
CU_initialize_registry();
CU_pSuite suite = CU_add_suite("swapnum_test", 0, 0);

	
CU_add_test(suite, "swap_fun", Swap_number_CUnitTest);
CU_add_test(suite, "prime_fun", Prime_numberCUnitTest);

CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();

return 0;
}
