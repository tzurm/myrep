#include <stdio.h>	/*  printf	    */
#include <stddef.h> /*	size_t		*/
#include <stdlib.h> /*	malloc		*/
#include <ctype.h>	/* 	isupper		*/
#include "sll.h"
#include "hash.h"

#define TABLE_SIZE 30

int CompareFunc(const void *data, void *param);
size_t HashFunc(void *data);
void CountCollision(size_t *arr, size_t len);

void Test_Create(void);
void Test_Insert_Size_t(void);
void Test_HashFunc(void);
void Test_Insert_words(void);

int main()
{
	printf("\n---------Test_Create-------------------------------\n");
	Test_Create();
	printf("\n---------Test_Insert_Size_t-------------------------------\n");
	Test_Insert_Size_t();
	printf("\n---------Test_HashFunc-----------------------------\n");
	Test_HashFunc();
	printf("\n---------Test_Insert_words-----------------------------\n");
	Test_Insert_words();

	return 0;
}

void Test_Create(void)
{
	hash_t *table = NULL;
	size_t table_size = 10;
	(void)table;
	table = Create(table_size, CompareFunc, HashFunc);
	(NULL == table) ? printf("table is null") : printf("not null");
}

void Test_Insert_Size_t(void)
{
	size_t arr[] = {25, 15, 50, 10, 786745, 35, 4, 12, 18, 24, 70, 987797, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t i = 0;
	hash_t *table = NULL;
	size_t table_size = TABLE_SIZE;
	(void)table;
	table = Create(table_size, CompareFunc, HashFunc);

	for (i = 0; i < len; ++i)
	{
		Insert(table, &arr[i]);
	}

	Destroy(table);
}
void Test_Insert_words(void)
{
	hash_t *table = NULL;
	size_t table_size = TABLE_SIZE;
	FILE *fp = fp;
	char str[6] = "";
	size_t i = 0;
	size_t arr_hash[TABLE_SIZE] = {0};

	table = Create(table_size, CompareFunc, HashFunc);

	fp = fopen("words.txt", "r");
	if (NULL == fp)
	{
		perror("Error opening file");
	}
	printf("index\tvalue\t\thash-value\n");
	printf("-------------------------------------------------------\n");
	for (i = 0; i < table_size; ++i)
	{
		if (NULL != fgets(str, 6, fp))
		{
			arr_hash[i] = HashFunc(&str);
			printf("%ld\t%s\t\t\t%ld\n", i, str, HashFunc(&arr_hash[i]));
			Insert(table, &str);
		}
	}
	fclose(fp);
	CountCollision(arr_hash, TABLE_SIZE);
	Destroy(table);
}
/******************************************************************/
int CompareFunc(const void *data, void *param)
{
	return (*(int *)data - *(int *)param);
}

size_t HashFunc(void *data)
{
	char *data_char = (char *)data;
	size_t hash = 5381;
	int c = 0;

	while ((c = *data_char++))
	{
		if (isupper(c))
		{
			c = c + 32;
		}

		hash = ((hash << 5) + hash) + c;
	}
	return hash % TABLE_SIZE;
}

void CountCollision(size_t *arr, size_t len)
{
/*	size_t arr_found[50] = {0}; if want print value hash*/
	size_t i = 0;
	size_t j = 0;
	size_t count = 0;
	int found = 0;

	for (i = 0; i < len; ++i)
	{
		found = 0;

		for (j = i + 1; j < len; ++j)
		{
			if (arr[i] == arr[j])
			{
				found = 1;
			}
		}
		if (1 == found)
		{
			/*arr_found[count] = arr[i];*/
			++count;
			printf("indexes:\t%ld \n", i);
		}
	}
	printf("Total\t\t%ld\n", count);
}

void Test_HashFunc(void)
{
	size_t arr[] = {25, 15, 50, 10, 786745, 35, 4, 12, 18, 24, 70, 987797, 44, 66, 90};
	size_t len = sizeof(arr) / sizeof(arr[0]);
	size_t arr_hash[50] = {0};
	size_t i = 0;

	printf("index\tvalue\thash-value\n");
	for (i = 0; i < len; ++i)
	{
		arr_hash[i] = HashFunc(&arr[i]);
		printf("%ld\t%ld\t%ld\n", i, arr[i], HashFunc(&arr[i]));
	}
	printf("Collision-------------\n");
	CountCollision(arr_hash, len);
}