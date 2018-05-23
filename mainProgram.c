#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>
#include"fd1.c"
#include"fd2.c"
#include"fd3.c"
#include"fd4.c"

/* Check the validity of the user whether the username exists or not and asks whether he wants to book a ticket or search flights and accordingly calls the respective functions*/
void ValidityForUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports,char *un,char *pw){
	FILE *user=fopen("user.txt","r");
	char usern[25],pass[25],a;
	int flag=0,m;
	while(fscanf(user,"%s %s",usern,pass)>0){
		if(strcmp(usern,un)==0 && strcmp(pass,pw)==0){
			flag=1;
			do{
            printf("\t\t\tChoose option:\n\n\t\t1.Book ticket\n\n\t\t2.Search flights\n\n\t\tYour choice:  ");
			scanf("%d",&m);
			switch(m){
				case(1):
					task1(route, airlines, airports);
					break;
				case(2):
					searchFlights(route, airlines, airports);
					break;
				default:
					printf("\t\tInvalid option\n\n");

			}
			printf("\n\n\t\tSearch for change option amongst book a ticket and search for a flight? \nEnter y/n: ");
			scanf(" %c",&a);
		}while(a!='n');
		if(a=='n'){
			break;
		}
		}
	}
	if(flag==0){
		printf("\n\nUser does not exists\n\n");
	}
	fclose(user);
}
/*Creates a new username and password and writes it up a new file*/
void createNewUser(char *un,char *pw){
	FILE *user=fopen("user.txt","a+");
	fprintf(user,"%s %s\n",un,pw);
	fclose(user);
}
/*This functions the new username and password as input writes in a file*/
void ForNewUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	printf("\n\n\t\tPlease enter your following details:\n\n");
	printf("\t\t\tUsername:  ");
	char un[50],pw[50];
	scanf(" %[^\n]s",un);
	printf("\n\n\t\t\tPassword:  ");
	scanf(" %[^\n]s",pw);
	createNewUser(un,pw);
}
/* Prompts whether the person is an existing user or a new user and accordingly calls the respective functions*/
void ForUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	char a,un[50],pw[50];
	int t1;
	do{
	printf("\n\n\t\tChoose the apt option:\n\n\t\t1. Existing \n\n\t\t2. New User\n\n\t\tYour choice:  ");
	scanf("%d",&t1);
	switch(t1){
		case(1):
			printf("\n\n\t\tPlease enter your following details:\n\n");
			printf("\t\t\tUsername:  ");
			scanf(" %[^\n]s",un);
			printf("\n\n\t\t\tPassword:  ");
			scanf(" %[^\n]s",pw);
			ValidityForUser(route, airlines, airports,un,pw);
			break;
		case(2):
			ForNewUser(route, airlines, airports);
			break;
		default:
			printf("\n\nInvalid choice\n");
			break;
	}
	printf("\n\n\t\tSearch for change option amongst existing and new user? \nEnter y/n: ");
	scanf(" %c",&a);
	}while(a!='n');

}
/*If the person is an admin person it will take an password as input validate it allow him to modify or delete details if the password is valid*/
void ForAdmin(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	int x;
	printf("\n\n\t\tPlease enter your following details:\n\n");
	char pw[50],a;
	printf("\t\t\tPassword:  ");
	scanf(" %[^\n]s",pw);
	do{
	if(strcmp(pw,"iiits@123")==0){
		printf("\n\t\t\tDo you want to \n\t1.Modify details \n\n\t2.Delete flight\n\n\t Enter your choice :");
		scanf("%d",&x);
		switch(x)
		{
			case(1):
				MODIFY(route, airlines, airports);
				break;
			case(2):
				task3(route, airlines, airports);
				break;
			default:
				printf("\n\nInvalid choice\n");
				break;
		}
	}
	else{
		printf("\n\n\t\tInvalid password\n\n");
	}
	printf("\t\tStay on the page ?\n\nEnter y/n: ");
	scanf(" %c",&a);
	}
	while(a!='n');
}
/*Asks if the person is a user or an admin person*/
void Entrance(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	printf("\n\n\t\t\tWelcome to flight radar\n\n");
	printf("\t\tChoose an option: \n\n\t\t\t1.User \n\n\t\t\t2.Admin\n\n\tYour choice:  ");
	int t1;
	scanf("%d",&t1);
	switch(t1){
		case(1):
			ForUser(route, airlines, airports);
			break;
		case(2):
			ForAdmin(route, airlines, airports);
			break;
		default:
			printf("\n\n\tInvalid choice\n");
			break;
	}
}

void we()
{
printf("\t\t****            ****               ***\n");
printf("\t\t****            ****               ***\n");
printf("\t\t****            ****               ***\n");
printf("\t\t****            ****  ***********  ***           *********  *********  *****     *****  ***********\n");
printf("\t\t****            ****  ***********  ***           *********  *********  *****     *****  ***********\n");
printf("\t\t****  ********  ****  **           ***           ***        **     **  ***   ****  ***  **\n");
printf("\t\t****  ********  ****  *****        ***           ***        **     **  ***    **   ***  *****\n");
printf("\t\t****  ***  ***  ****  *****        ***           ***        **     **  ***         ***  *****\n");
printf("\t\t****  ***  ***  ****  **           ***           ***        **     **  ***         ***  **\n");
printf("\t\t*********  *********  ***********  ************  *********  *********  ***         ***  ***********\n");
printf("\t\t*********  *********  ***********  ************  *********  *********  ***         ***  ***********\n");
}

int main()
{
	ROUTE *route = insertROUTE();
	AIRLINES *airlines = insertAIRLINE();
	AIRPORTS *airports = insertAIRPORT();
	char ans;
	we();
	do{
	Entrance(route,airlines,airports);
	printf("\n\t\tDo you want to proceed further ?\n\n\t Enter your choice :");
	scanf(" %c",&ans);
	}while(ans!='n');
	return 0;
}
