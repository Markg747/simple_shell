#include "shell1.h"
/**
 * _realloc - realloc
 * @ptr: pointer
 * @old_size: old size of array
 * @new_size: new size of array
 * Return: new array
 **/
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *nptr;

	if (new_size == old_size)
		return (ptr);

	if (ptr == NULL)
	{
		nptr = malloc(new_size);
		return (nptr);
	}

	if (!new_size)
	{
		free(ptr);
		return (NULL);
	}

	nptr = malloc(old_size + (new_size - old_size));

	memcpy(nptr, ptr, old_size);

	free(ptr);

	return (nptr);
}
