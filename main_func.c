#include <stdlib.h>
#include <stdio.h>
#include <smooth_func.h>
#include <data_read.h>

#define MAX_LINES 256

int main(void)
{
	FILE* inputFile = fopen("data.dat","r");

	if(inputFile == NULL)
	{
		printf("\nInput file open failed");
		return EXIT_FAILURE;
	}

	printf("\nFiled open");

	float inputData[MAX_LINES];

	int sz_data = read_data(inputFile,inputData,MAX_LINES);

	printf("\nRead %i lines of data",sz_data);

	fclose(inputFile);

	printf("\nInput filed closed");

	if(sz_data>0)
	{
		int sz_filter = 5;
		int sz_output = sz_data - sz_filter + 1;
		float output[sz_output];

		printf("\nSmoothing data with filter size %i ... ",sz_filter);

		if( smooth(inputData,output,sz_data,sz_filter) == 0 ) return EXIT_FAILURE;

		printf("complete");

		printf("\nSaving data");

		FILE* outputFile = fopen("outdata.dat","w");

		if(outputFile == NULL)
		{
			printf("\nOutput file open failed!");
			return EXIT_FAILURE;
		}

		for(int i=0; i<sz_output; i++)
		{
			fprintf(outputFile, "%.6f\n", output[i]);
		}

		fclose(outputFile);

		return EXIT_SUCCESS;
	}

	return EXIT_FAILURE;
}