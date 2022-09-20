#include "boundary.h"


void Ex1_Memset();
void Ex1_Memcpy();
void Ex1_Memmove();


int main() 

{
	printf("\n***** TESTS  Memset ************************************* \n\n");
  
 	Ex1_Memset();
 	
 	printf("\n***** TESTS  Memcpy ************************************* \n\n");
  
 	Ex1_Memcpy();
 
 	printf("\n***** TESTS  Memmove ************************************ \n\n");
  
 	Ex1_Memmove();
 
	return(0);
}	
 	

void Ex1_Memset()
{
	
	char str1[50];
	char str2[50];
	char str3[50];
	char str4[50];
	
	strcpy(str1,"abcdefeg");
	strcpy(str2,"abcdefeg");
	strcpy(str3,"abcdefeg");
	strcpy(str4,"abcdefeg");
	
	printf("Test_1 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str1);
	Memset(str1,'*',3);
	printf("After:	");
	puts(str1);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str2);
	memset(str2,'*',3);
	printf("After:	");
	puts(str2);
	
	printf("\nTest_2 \n");
	printf("my Memset \n");
	printf("Before:	");
	puts(str3);
	Memset(str3,'*',20);
	printf("After:	");
	puts(str3);
	puts("");
	
	printf("original memset \n");
	printf("Before:	");
	puts(str4);
	memset(str4,'*',20);
	printf("After:	");
	puts(str4);
	
	
}

void Ex1_Memcpy()
{
	const char src1[4] = "123";
    char dest1[50] = {0};
    
    const char src2[4] = "123";
    char dest2[50] = {0};
    
    printf("Test_1 \n");
    printf("my memcpy \n");
    strcpy(dest1,"random string");
    printf("Before:	%s\n", dest1);
    Memcpy(dest1, src1, 3);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"random string");
    printf("Before:	%s\n", dest2);
    memcpy(dest2, src2, 3);
    printf("After:	%s\n", dest2);
	
}

void Ex1_Memmove()
{
	const char src1[4] = "123";
    char dest1[50] = {0};
    
    const char src2[4] = "123";
    char dest2[50] = {0};
    
    printf("Test_1 \n");
    printf("my memcpy \n");
    strcpy(dest1,"random string");
    printf("Before:	%s\n", dest1);
    Memmove(dest1, src1, 3);
    printf("After:	%s\n", dest1);
    
    printf("\noriginal memcpy \n");
    strcpy(dest2,"random string");
    printf("Before:	%s\n", dest2);
    memmove(dest2, src2, 3);
    printf("After:	%s\n", dest2);
	
}




   

