#include "funcs.h"
#include <assert.h>
#define ESC 27

/* date: 5.9
writer: Tzur
review: Arye
Status: approved
*/

void Spressed()
{
 	char c='\0';
    system("stty  -icanon -echo");
    
    printf("Enter A  or T  , Esc to exit\n");
   	scanf("%c", &c);
   	
    while(c != ESC) 
    {
    	
		switch(c)
		{

			case 'A':
			{
				printf("A-pressed \n");
				break;
			}		
			case 'T':
			{		
				printf("T-pressed \n");
				break;
		   	}
			default:
			{
		        printf("Error! \n");
			}
		}	
		scanf("%c", &c);
    }
 	system("stty icanon echo");

}

/* date: 5.9
writer: Tzur
review: Arye
Status: approved
*/

void Ipressed()
{
 	char c='\0';
    system("stty  -icanon -echo");
    
    printf("Enter A  or T  , Esc to exit");
   	scanf("%c", &c);
   	
    while(c != ESC) 
    {
    	
		if ('A' == c)
		{ 
			printf("A-pressed \n");
		}
		
		else if ('T' == c)
		{ 		
			printf("T-pressed \n");
		}
		else
		{
			printf("Press  again \n" );
		}
		
		scanf("%c", &c);
    }
 	system("stty icanon echo");
}


void Print(char c)
{
	printf("%c is pressed\n",c);
}

void Dummy(char c)
{
	c=c;
}

void Lpressed()
{
	char c = '\0';
	int i = 0;
	 
	 /*  def of array of function pointers that will print if pressed */ 	
	typedef void (*arrayfun)(char);
	arrayfun letter[256]={0};
	
	
	for(i = 0; i < 256; i++)
	{
		letter[i]=Dummy;
	}
	letter[65] = Print;
	letter[84] = Print;
	
	system("stty -icanon -echo");
	
	printf("Enter A  or T  , Esc to exit");
	scanf("%c", &c);
	
	while(c != ESC)
	{
	
		letter[(unsigned)c](c);
		scanf("%c", &c);
		
	}
	system("stty icanon echo");
	printf("\n");
	
}


