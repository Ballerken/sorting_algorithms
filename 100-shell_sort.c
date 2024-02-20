#include "sort.h"

/**
 * shell_sort - Sorts an array of integers in ascending order using the Shell
 * sort algorithm
 * @array: A pointer to the integer array to be sorted
 * @size: The size of the array
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, h;
	int temp;

	/* Generate the initial interval (Knuth sequence) */
	for (h = 1; h < size; h = 3 * h + 1)
		;

	/* Start with the largest interval and reduce */
	for (h = (h - 1) / 3; h > 0; h = (h - 1) / 3)
	{
		for (i = h; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= h && array[j - h] > temp)
			{
				array[j] = array[j - h];
				j -= h;
			}
			array[j] = temp;
		}
		print_array(array, size);
	}
}
