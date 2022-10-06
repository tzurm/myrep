#include <assert.h>					/*		assert			*/
#include <stddef.h>					/*		size_t			*/
#include <stdlib.h>					/*		malloc			*/
#include <stdio.h>					/*		printf			*/
#include <string.h>					/*		memcpy			*/
#include "vector.h"					/*		my_vector		*/

#define MALLOC_CHECK(ptr) if(NULL == ptr) {return NULL;}
#define GROWTH_FACTOR 2
#define SHRINK_FACTOR 4


struct vector
{	
	void *array;					/*	point to array		*/
	size_t size;					/*	current size 		*/
	size_t capacity;				/*	max of the stack	*/
	size_t element_size;			/*	size of the element	*/
};

vector_t *VectorCreate(size_t capacity , size_t element_size)
{
	vector_t *vector = (vector_t*)malloc(sizeof(vector_t));
	vector_t *array = malloc(capacity * element_size);

	MALLOC_CHECK(vector);
	MALLOC_CHECK(array);
	
	vector -> array = array;
	vector -> element_size = element_size;
	vector -> capacity = capacity;
	vector -> size = 0;

	return(vector);

}

void VectorDestroy(vector_t *vector)
{
	assert(NULL != vector);
	
	free(vector -> array);
	free(vector);
}

void *VectorAccessElement(const vector_t *vector ,size_t index)
{
	assert(NULL != vector);
	
	return (char*)vector -> array + (index *(vector -> element_size));
	
}


status VectorPush(vector_t *vector, const void *value)
{
	assert(NULL != vector);
	
	if(VectorSize(vector) == VectorCapacity(vector))
	{
		vector -> capacity *= GROWTH_FACTOR;
		VectorReserve(vector , vector -> capacity);
	}
	
	memcpy((void *)((char *)vector -> array + (vector-> size) * 
		(vector -> element_size)),value, vector -> element_size);
			
	++(vector-> size);
	
	return SUCCESS; 
}

status VectorPop(vector_t *vector)
{
	assert(NULL != vector);
	
	
	--(vector-> size);
	
	if(SHRINK_FACTOR*VectorSize(vector) < VectorCapacity(vector))
	{
		vector -> capacity /= 2;
		vector -> array = realloc
			(vector -> array, vector -> capacity * vector -> element_size);
	}
	
	return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;


}


size_t VectorSize(const vector_t *vector)
{
	assert(NULL != vector);	
	
	return vector -> size;
}

size_t VectorCapacity(const vector_t *vector)
{
	assert(NULL != vector);
	
	return vector -> capacity;
}


status VectorReserve(vector_t *vector,size_t value)
{
	if(value >  (vector -> capacity))
	{
		vector -> capacity = value;
		vector -> array = realloc
			(vector -> array, vector -> capacity * vector -> element_size);
	}
	
	return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;
}

status VectorShrink(vector_t *vector)
{
	vector -> capacity = vector -> size;
	vector -> array = realloc
		(vector -> array, vector -> capacity * vector -> element_size);
	
	return (NULL == vector -> array) ? REALLOC_ERROR : SUCCESS;
}


