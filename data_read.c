#include <data_read.h>

int read_data(FILE* fp, float* data, int max_lines)
{
	char line[32];

	int i = 0;

	while(fgets(line, sizeof line, fp) != NULL && i < max_lines)
	{
		data[i] = atof(line);
		i++;
	}

	return i;
}
