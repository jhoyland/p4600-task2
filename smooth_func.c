	/*
		A good function should catch problems before they happen and fail gracefully.
		In this case we catch some obvious problem arguments.
		Specifically it checks:
		The values for the size of the data and the size of the filter are bigger than zero and that the filter is not larger than the data
		That the input array and output array are not in fact the same array.
		That the input and output pointers are not NULL (i.e. they point to something)

		These checks are not sufficient to catch all problems, particularly they do not guarentee that the pointers point to valid arrays, but they do catch some more obvious mistakes.
		"Failing gracefully" here means the function will return 0. Otherwise the function should return the number of data points in the final data. The zero return is a condition the
		calling function can deal with and try to correct.

	*/


#include <smooth_func.h>
#include <stddef.h> 

int smooth(float* input, float* output, int sz_data, int sz_filter)
{
	/* Check for valid arguments */

	if(sz_filter < 1 || sz_data < 1) return 0;
	if(sz_data < sz_filter) return 0;
	if(input == output) return 0;
	if(input == NULL || output == NULL) return 0;


	int i;  /* i: loop counter */

	for(i=0; i<sz_data-sz_filter + 1; i++)
	{
		output[i] = 0; 

		for(int j=0; j<sz_filter; j++)
		{
			output[i] += input[i+j];
		}

		output[i] /= (float)sz_filter;
	}

	return i;

}
