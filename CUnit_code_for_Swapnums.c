#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>
#include <math.h>
#include <stdio.h>  
#include <stdlib.h> 

void swap(int*, int*);
int prime_number(int);
int largest_in_Array(int[],int); 
float findAreaTriangle(float,float,float);

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
int i=0;
int p=0;

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

int largest_in_Array(int arr[], int n) 
{ 
    int i; 
     
    int max = arr[0]; 
   
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
}

float findAreaTriangle(float a, float b, float c) 
{ 
    // Length of sides must be positive and sum of any two sides 
    // must be smaller than third side. 
    if (a < 0 || b < 0 || c <0 || (a+b <= c) || 
        a+c <=b || b+c <=a) 
    { 
        exit(0); 
    } 
    float s = (a+b+c)/2; 
    return sqrt(s*(s-a)*(s-b)*(s-c)); 
} 

void AreaTriangleCUnitTest()
{
  float a = 3.0; 
  float b = 4.0; 
  float c = 5.0; 
  float result;
  result = findAreaTriangle(a, b, c);
  CU_ASSERT_EQUAL(result,6.0);
}

void Prime_numberCUnitTest()
{

CU_ASSERT(prime_number(19) == 1);
CU_ASSERT(prime_number(1) == 0);
CU_ASSERT(prime_number(79) == 1);
CU_ASSERT(prime_number(100) == 0);
}

void largestnumberin_ArrayCUnitTest()
{

   int arr[] = {10, 324, 45, 90, 9808};
   int n = sizeof(arr)/sizeof(arr[0]);
   int result=0;
   result = largest_in_Array(arr,n);    
	 
   CU_ASSERT_EQUAL(result,9808);  

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
CU_add_test(suite, "Maxarr_fun",largestnumberin_ArrayCUnitTest);
CU_add_test(suite, "areaTriangle",AreaTriangleCUnitTest);
	
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();

return 0;
}
