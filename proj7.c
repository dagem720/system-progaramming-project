#include<stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define max 10

void owner();
void mode();
void exit_function();

int main()
{
	int x;
	printf("\t\tFile permission system\n");
	while(1){

	printf("1.change Owner\n");
	printf("2.change Mode\n");
	printf("3.exit\n");
	scanf("%d", &x);
//system("clear");
	switch(x)
	{
		case 1:owner();break;
		case 2:mode();break;
		case 3:exit_function();break;
		default :printf("press the correct number\n");break;
	}

}



}
void owner()
{
	char dir[25];
	char user[25];
	char group[25];
	int ch;
	char mmain[300];
	char ls[50];
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

system("cat /etc/group "  );
printf(" Enter the group   \n" );
scanf("%s",group);
printf("Insert the directory");
scanf("%s",dir);

snprintf(mmain, 100, "%s%s%s%s%s%s","sudo chown " , user,":" ,group," ",dir);
snprintf(ls ,100, "%s%s%s%s%s%s","ls " , user,":" ,group," ",dir);

system(mmain);
if(system(mmain)){
	system(ls);
}

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
	 char filename[25];
	 char user_name[25];



	printf("enter file name \n");
    
	//scanf("%s",filename);
	printf("Enter user name \n");
	scanf("%s",user_name);
	//printf("\n", );
	//snprintf(ls ,100, "%s%s%s%s%s%s","ls " , user,":" ,group," ",dir);

}
void exit_function()
{
	printf("Exit \n");

}