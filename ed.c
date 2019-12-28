#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>


int main()
{

	printf("Please select what you want to do\n");
	printf("1) Encrypt\n2) Decrypt\n");
	int x;
	char fn[100],ch;
	FILE *fo, *fot;
	here:
	scanf("%d",&x);
	
	
	if(x==1)
	{
		printf("insert the file name to be encrypted\n");
		scanf("%s", fn);
		fo=fopen(fn, "w");
		fot=fopen("temp.txt","w");
		while(1)
	{
		ch=fgetc(fo);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fot);
		}
	}
	fclose(fo);
	fclose(fot);
	fo=fopen(fn, "w");
	if(fo==NULL)
	{
		printf("Error in opening source file..!!");
		exit(3);
	}
	fo=fopen("temp.txt", "r");
	if(fot==NULL)
	{
		printf("Error in opening temp.txt file...!!");
		fclose(fo);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fot);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fo);
		}
	}


	fclose(fo);
	fclose(fot);

		printf("The file has been encrypted\n");
	}
	else if(x==2)
	{
		printf("insert the file name to be decrypted\n");
		scanf("%s", fn);
		system("gpg -d $file2 ");
	}
	else{
		printf("please put the correct number!\n");
		goto here;
	}
}