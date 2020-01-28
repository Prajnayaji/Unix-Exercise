#include<stdio.h>
#include<dirent.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>

int main()
{
 
	char filename[100];
	DIR *directory;
	struct dirent *d;
	FILE *f;
	printf("Enter the path of the file\n");
	scanf("%[^\n]",filename);
	char pwd[100];
	char path[100];
	getcwd(pwd,100);
	printf("Present working directory is %s\n",pwd);
	if(filename[0]=='/')
	{
		printf("Given path is absolute\n");             // if the path is absolute keep it as it is
		strcpy(path,filename);

	}

	else
	{
		printf("Given path is relative\n");
		strcat(pwd,"/");                          // if the path is relative add present working directory path to it
		strcat(pwd,filename);
		strcpy(path,pwd);

	}
	printf("File path is: %s\n",filename);
	directory = opendir(path);
	if ( directory == NULL)
	{

		f = fopen(path,"r");
		if( f != NULL)
		{
			printf("Given path is a file\n");
			fclose(f);
			return -1;
		}
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
