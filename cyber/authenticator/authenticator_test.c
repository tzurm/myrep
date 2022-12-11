
#include <stdio.h>
#include <stdlib.h>

void PrintAuthenticateTest(const char *user_name, const char *password);
int AddUser(const char *user_name, const char *password);
int Authenticate(const char *user_name, const char *password);

int main()
{

    char *username = "tzur";
    char *password = "123456";
    char *notusername = "pop";
    char *notpass = "12345";
 /*-----------------------------------------------------------Test AddUser----*/
    AddUser(username, password);
    AddUser("user0", "mypass123");
    AddUser("user1", "12345678");
 /*------------------------------------------------------Test Authenticate----*/
 
    PrintAuthenticateTest(username, password); /*found*/
    PrintAuthenticateTest("tzur", "123456"); /*found*/
    PrintAuthenticateTest("user0",  "mypass123"); /*found*/
    PrintAuthenticateTest(username, notpass); /*not found*/
    PrintAuthenticateTest(notusername, notpass); /*not found*/

    return 1;
}

void PrintAuthenticateTest(const char *user_name, const char *password)
{
    (1 == Authenticate(user_name, password)) ? printf("%s found\n", user_name) : printf("%s not found\n", user_name);
}