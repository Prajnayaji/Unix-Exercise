#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 
	char filename[100];
	DIR *directory;
	struct dirent *d;

	printf("Enter the absolute path of the file\n");
	scanf("%[^\n]",filename);
	printf("File path is: %s\n",filename);
	directory = opendir(filename);
	if ( directory == NULL)
	{
		printf("No such file or directory\n");
		return -1;
	}

	while( d = readdir(directory))
	{

		if((strcmp(d->d_name,".")) && (strcmp(d->d_name,"..")))
		{
			printf("%s\t",d->d_name);

		}


	}

	printf("\n");


	return 0;
}
