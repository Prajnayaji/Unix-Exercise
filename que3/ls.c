#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>

int main()
{
 
	char path[100];
	DIR *directory;
	struct dirent *d;

	printf("Enter the absolute path of the file\n");
	scanf("%[^\n]",path);
	printf("File path is: %s\n",path);
	directory = opendir(path);
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
