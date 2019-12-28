#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define max 10

void owner();
void mode();
void ed();
void exit_function();

int main()
{
	int x;
	printf("\t\tFile permission system\n");
	while(1){

	printf("1.change Owner\n");
	printf("2.change Mode\n");
	printf("3.Encrypt and Decrypt a file \n");
	printf("4.exit\n");
	scanf("%d", &x);
//system("clear");
	switch(x)
	{
		case 1:owner();break;
		case 2:mode();break;
		case 3:ed();break;
		case 4:return 0;break;
		default :printf("press the correct number\n");break;
	}

}



}
void owner()
{
	char dir[25];
	char path[25];
	char user[25];
	char group[25];
	int ch;
	char mmain[300];
	char find[35];
	
	//printf("owner \n");
		system("cd ~");
		system("pwd");

		printf("1.Change user ownership and group ownership \n 2.Change user ownership \n 3.Change group ownership \n\n" );
		scanf("%d", &ch);
		if(ch==1){
printf("Users  \n" );
system("cat /etc/passwd | cut -d \":\" -f1  ");
printf(" Enter the user  \n" );
scanf("%s",user);

system("cat /etc/group : "  );
printf(" Enter the group  : \n" );
scanf("%s",group);
printf("Enter the file or folder : ");
scanf("%s",dir);
snprintf(find, 100, "%s%s","realpath  " , dir );
system(find);
printf("\n Enter the path starting from the Desktop like ~/Desktop ... \n");
scanf("%s",path);

snprintf(mmain, 100, "%s%s%s%s%s%s","sudo chown " , user,":" ,group," " , path );

printf("%s\n",mmain );
system(mmain);


		}else if(ch == 2){
printf("user\n" );
		}
		else if(ch==3){
printf("group\n" );
		}else{
printf("else\n" );
		}

	printf("enter the file directory\n");

	fgets(dir,100,stdin);
	printf("Enter the user who wents to won the data\n");

	fgets(user,100,stdin);
	
	

	
	char Dir[200]="chown ";
	strcat(Dir,user);
strcat(Dir," ");
strcat(Dir,dir);
	printf("%s\n",Dir );

		
   //execl("/bin/bash","-c","ls");
	//system("cd dir");

}
void mode()
{
	 char filename[23];
	 //char user_name[25];
	 char mode[9];
	 char mmain[100];



	printf("enter file directoryr\n");

  scanf("%s",filename);

printf("Enter the mode \n" );
    scanf("%s",mode);	

	snprintf(mmain,100, "%s%s%s%s","sudo chmod  " ,mode," ",filename);
	printf("%s\n",mmain );
	system(mmain);

}
void ed()
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


