#include "shell.h"

/**
 * myCustom_realloc - reallocates memory
 *
 * @ptr: pointer to the memory block
 * @size: size of the argument
 *
 * Return: A void pointer to a block of memory
 */

void *myCustom_realloc(void *ptr, size_t size)
{
	void *new_ptr;

	if (ptr == NULL)
		return (malloc(size));

	if (size == 0)
	{
		free(ptr);
		return (NULL);
	}
	new_ptr = malloc(size);
	if (new_ptr == NULL)
		return (NULL); /*malloc failure*/
	myCustom_memcpy(new_ptr, ptr, size);
	free(ptr);

	return (new_ptr);
}
