#include <stdlib.h> /*		malloc			*/
#include <assert.h> /*		assert			*/
#include <stddef.h> /*		size_t			*/
#include <stdio.h>	/*		printf			*/

#include "hash.h"
#include "sll.h"

struct hash_table
{
	sll_t **list;
	compare_func_t cmp_func;
	hash_func_t hash_func;
	size_t table_size;
};
/*-------------------------Approved by ziv 15.11.2022-------------------------*/
hash_t *Create(size_t table_size, compare_func_t cmp_func, hash_func_t hash_func)
{
	hash_t *table = NULL;
	sll_t **array_of_list = NULL;
	size_t i = 0;

	table = (hash_t *)malloc(sizeof(hash_t));
	if (NULL == table)
	{
		return NULL;
	}

	array_of_list = (sll_t **)malloc(sizeof(sll_t *) * table_size);
	if (NULL == array_of_list)
	{
		free(table);
		return NULL;
	}

	table->table_size = table_size;
	table->cmp_func = cmp_func;
	table->hash_func = hash_func;
	table->list = array_of_list;

	for (i = 0; i < table_size; ++i)
	{
		*(table->list + i) = SLLCreate();
	}

	return table;
}
/*-------------------------Approved by ??? 16.11.2022-------------------------*/
void Destroy(hash_t *table)
{
	size_t i = 0;
	size_t size = 0;

	assert(NULL != table);

	size = table->table_size;

	for (i = 0; i < size; ++i)
	{
		SLLDestroy(*(table->list + i));
	}

	free(table->list);
	free(table);
}

status_t Insert(hash_t *table, const void *key)
{
	sll_t *list = NULL;
	sll_iter_t iter = NULL;
	hash_func_t hash_func = NULL;
	void *copy_key = NULL;
	size_t hashed = 0;

	assert(NULL != table);

	copy_key = (void *)key;
	hash_func = table->hash_func;
	hashed = hash_func(copy_key);
	list = *(table->list + hashed); /*seg fault*/
	iter = SLLEnd(list);
	SLLInsertBefore(iter, copy_key);

	return SUCCESS;
}

void Remove(hash_t *table, const void *key)
{
	/*
	size_t i = 0;
	size_t table_size = 0;

	assert(NULL != table);

	table_size = table->table_size;

	for (i = 0; i < table_size; ++i)
	{
		SLLRemove(*(table->list + i));
	}
	(void)key;
	*/
}

void *Find(const hash_t *table, const void *key)
{

	void *copy_key = NULL;
	sll_iter_t *list = NULL;
	sll_iter_t *iter = NULL;
	assert(NULL != table);

	copy_key = (void *)key;
	list = table->list;

	iter = SLLFind(table->cmp_func, SLLBegin(list), SLLEnd(list), copy_key);

	return (NULL == iter) ? NULL : SLLGetData(iter);
}
/*
status_t ForEach(hash_t *table, action_func_t callback, const void *param)
{

}
*/
size_t Count(const hash_t *table)
{
	size_t count_inuse = 0;
	size_t i = 0;
	size_t table_size = 0;
	sll_t *list = NULL;

	assert(NULL != table);

	table_size = table->table_size;

	for (i = 0; i < table_size; ++i)
	{
		list = *(table->list + i);
		count_inuse += SLLCount(list);
	}

	return count_inuse;
}
int IsEmpty(const hash_t *table)
{
	if (0 == Count(table))
	{
		return EMPTY;
	}
	return NOT_EMPTY;
}
