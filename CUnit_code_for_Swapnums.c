#include <CUnit/CUnit.h>
#include <CUnit/Basic.h>

void swap(int*, int*);
int prime_number(int);
int largest_in_Array(int[],int); 
int Validate_Pwd(char a[]);

/* This function is to swap 2 integers */
void swap(int *a, int *b)
{
   int temp;
   temp = *b;
   *b = *a;
   *a = temp;   
}

/* This function return True if the given input is Prime */
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

/* This function return largest number in the array */
int largest_in_Array(int arr[], int n) 
{ 
    int i; 
     
    int max = arr[0]; 
   
    for (i = 1; i < n; i++) 
        if (arr[i] > max) 
            max = arr[i]; 
  
    return max; 
}


/* This function validate the Pwd */
int Validate_Pwd(char a[])
{
    char c;
    int len,i,flag1=0,flag2=0,flag3=0,flag4=0;
    len=strlen(a);
    if(len<6)
    flag1=1;
    else
    {
        for(i=0;i<len;i++)
        if((a[i]>=48&&a[i]<=58))
        {
            flag2=0;

            break;
        }
        else
        flag2=1;

        for(i=0;i<len;i++)
        if((a[i]>=65&&a[i]<=90))
        {
            flag3=0;

            break;
        }
        else
        flag3=1;

        for(i=0;i<len;i++)
        if(a[i]=='#'||a[i]=='$'||a[i]=='*'||a[i]=='&')
        {
            flag4=0;

            break;
        }
        else
        flag4=1;


    }
    if(flag1==1||flag2==1||flag3==1||flag4==1)
    return 0;
    else
    return 1;
}


/* Cunit testcases to validate the Pwd */
void ValidtaePwd_CUnitTest()
{
 /*("Enter your password that should satisfy the following criteria\n1.
password should contain atleast one capital letter\n2. 
should have one digit from(o-9)\n3. atleast one special charecter($,*,#,&)\n4.
length should be atleast 6\n");*/

CU_ASSERT(Validate_Pwd("J1$abc") == 1);
CU_ASSERT(Validate_Pwd("J1$abcwyie") == 1);
CU_ASSERT(Validate_Pwd("J1abef") == 0);
CU_ASSERT(Validate_Pwd("b1dac") == 0);
	
}	


/* Cunit testcases to find the Prime number */
void Prime_numberCUnitTest()
{

CU_ASSERT(prime_number(19) == 1);
CU_ASSERT(prime_number(1) == 0);
CU_ASSERT(prime_number(79) == 1);
CU_ASSERT(prime_number(100) == 0);
}


/* Cunit testcases to find largest number in the array */
void largestnumberin_ArrayCUnitTest()
{

   int arr[] = {10, 324, 45, 90, 9808};
   int n = sizeof(arr)/sizeof(arr[0]);
   int result=0;
   result = largest_in_Array(arr,n);    
	 
   CU_ASSERT_EQUAL(result,9808);  

}


/* Cunit testcases to swap integers */
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
CU_add_test(suite, "ValidatePwd",ValidtaePwd_CUnitTest);
	
CU_basic_set_mode(CU_BRM_VERBOSE);
CU_basic_run_tests();
CU_cleanup_registry();

return 0;
}
