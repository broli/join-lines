#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void usage (char *nombre)
{
	printf("Usage help:\n%s <path>\nWhere <path> where path is the full path (incliding file name) of the file to convert\n the result file will be writen to stdout\n",nombre);
}

int main(int argc, char *argv[])
{
	FILE *InFile=NULL;
	
	size_t nbytes = 1;
	char *line;

	
	if (argc != 2)
	{
		printf("Wrong number of parameters\n");
		usage(argv[0]);
		return EXIT_FAILURE;
	}
	
	InFile = fopen(argv[1],"r");
	if (InFile==NULL)
	{
		printf("Error: unable to open %s for reading\n",argv[1]);
		return EXIT_FAILURE;
	}

	line = malloc (nbytes + 1);
	
	while (getline (&line, &nbytes, InFile) != -1)
	{
		char *ptr;
		ptr = strstr( line,"\n");
		if (ptr != NULL)
			{
				ptr --;
				if ( ptr[0] == '.' )
				{
					printf("%s",line);
				}
				else
				{
					/*should be the same line, so we delete the new line*/
					ptr++;
					*ptr = '\0';
					printf("%s",line);
			 		fflush(stdout);
				}
			}
		else
			{
				return EXIT_FAILURE;
			}
	}	
	
	free(line);
	fclose(InFile);
	return EXIT_SUCCESS;
}

