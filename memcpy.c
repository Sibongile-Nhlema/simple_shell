#include "shell.h"

/**
 * myCustom_mempy - copy the contents from the
 * old memory block to the new memory
 * @dest: destination
 * @src: source
 * @size: size
 *
 * Return: destination pointer
 */

void *myCustom_memcpy(void *dest, const void *src, size_t size)
{
	char *dest_ptr = (char *)dest;
	const char *src_ptr = (const char *)src;
	size_t i;

		for (i = 0; i < size; i++)
			dest_ptr[i] = src_ptr[i];

	return (dest);
}
