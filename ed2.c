#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
void main()
{


printf("Please select what you want to do\n");
	printf("1) Encrypt\n2) Decrypt\n");
	int x;
	
	FILE *fps, *fpt;
	here:
	scanf("%d",&x);
	char fname[20], ch, choice;
	

	
if(x==1){
	printf("Enter file name to be encrypted : ");
	scanf("%s",fname);	
	fps=fopen(fname, "r");
	if(fps==NULL)
	{
		printf("Error in opening file..!!");
		printf("\nexiting...\n");
		sleep(2);
		exit(1);
	}
	fpt=fopen("temp.txt", "w");
	if(fpt==NULL)
	{
		printf("Error in creating temp.txt file..!!");
		fclose(fps);
		printf("\nexiting...\n");
		sleep(2);
		exit(2);
	}
	while(1)
	{
		ch=fgetc(fps);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch+100;
			fputc(ch, fpt);
		}
	}
	fclose(fps);
	fclose(fpt);
	fps=fopen(fname, "w");
	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nexiting...\n");
		//getch();
		sleep(2);
		exit(3);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file...!!");
		fclose(fps);
		printf("\nexiting...\n");
		//getch();
		sleep(2);
		exit(4);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			fputc(ch, fps);
		}
	}
	printf("File %s encrypted successfully..!!", fname);
	printf("\nexiting...\n");
	sleep(2);
	fclose(fps);
	fclose(fpt);
	//getch();
	
}
else if(x==2)
{
	
	char ch1;
	printf("Enter file name (with extension like file.txt) which you have encrypted earlier to decrypt : ");
	scanf("%s",fname);
	fps=fopen(fname, "w");

	if(fps==NULL)
	{
		printf("Error in opening source file..!!");
		printf("\nexiting...\n");
		//getch();
		sleep(2);
		exit(7);
	}
	fpt=fopen("temp.txt", "r");
	if(fpt==NULL)
	{
		printf("Error in opening temp.txt file..!!");
		fclose(fps);
		printf("\nexiting...\n");
		//getch();
		exit(9);
	}
	while(1)
	{
		ch=fgetc(fpt);
		if(ch==EOF)
		{
			break;
		}
		else
		{
			ch=ch-100;
			fputc(ch, fps);
		}
	}
	printf("File %s decrypted successfully..!!",fname);
	printf("\nexiting...\n");
	sleep(2);
	fclose(fps);
	fclose(fpt);
}
else{
	printf("error\n");
}
}
