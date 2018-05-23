#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*FUNCTION TO WRITE MODIFIED CONTENTS TO FILE
1-->AIRPORTS FILE
2--> AIRLINES FILE
3-->ROUTES DATABASE*/
void printfairports(AIRPORTS *air,ROUTE *route, AIRLINES *airlines,char *fnam,int f)
{

//AIRPORTS MODIFICATION
if(f==1)
{
FILE *f=fopen(fnam, "w");
while(air != NULL)
	{
		AIRPORT *head = air->next;
		while(head != NULL)
		{
			fprintf(f,"%d\t%s\t%s\t%s\t%s\t%s\t%g\n", head->ID, head->name, head->city, head->country, head->IATA, head->ICAO, head->timezone);
			head = head->next;
		}
		air = air->down;
	}
	fclose(f);

}
//AIRLINES MODOFICATION
if(f==2)
{
FILE *f2=fopen(fnam, "w");
while(airlines != NULL)
	{
		AIRLINE *head;
		head = airlines->next;
		while(head != NULL)
		{
			fprintf(f2,"%d\t%s\t%s\t%s\n", head->ID, head->name, head->ICAO, head->country);
			head = head->next;
		}
		airlines = airlines->down;
	}
	fclose(f2);

}

//ROUTES MODIFICATION
if(f==3)
{
FILE *f3=fopen(fnam, "w");
while(route != NULL)
	{
		AIRPLANE *head;
		head = route->next;
		while(head != NULL)
		{
	fprintf(f3,"%s\t%d\t%s\t%d\t%s\t%d\n", head->AIRLINE_IATA, head->AIRLINE_ID, head->Source, head->Source_IATA, head->Dest, head->Dest_IATA);
			head = head->next;
		}
		route = route->down;
	}
    fclose(f3);

}
}

/*FUNCTION TO FIND AIRLINE NAME CORRESPONDING TO THE AIRLINE ID */

void LocateAirline(AIRLINES *airlines, int search, char *airl)
{
	while(airlines != NULL)
	{
		AIRLINE *head;
		head = airlines->next;
		while(head != NULL)
		{
			if(head->ID == search)
			{
				strcpy(airl, head->name);
			}
			head = head->next;
		}
		airlines = airlines->down;
	}
}
/*UTILITY FUNCTION TO TRAVERSE DATA STRUCTURE AND MODIFY THE NEW CITY DESTINATION AND SOIRCE AND AIRLINE NAME*/

int modify2(char *src, char *dest, AIRLINES *airlines, ROUTE *route, int source, int destination,AIRPORTS *airports)
{	ROUTE *c1=route;
	AIRLINES *a1=airlines;
	AIRPORTS *ap1=airports;
	ROUTE *first = route;
	ROUTE *sec=first;
	AIRLINES *air=airlines;
	int flag = 0, j = 0,di=0;
	TICKET *firs, *trav,*dummy;
	char srce[50],des[50],newair[50];
	int ia,ia2;
	while(route != NULL)
	{
		AIRPLANE *head = route->next;
		while(head != NULL)
		{
			if(head->Source_IATA == source && head->Dest_IATA == destination)
			{
				char airl[200];
				LocateAirline(airlines, head->AIRLINE_ID, airl);
				j++;
				if(flag == 0)
				{
					TICKET *temp;
					temp = (TICKET *)(malloc(sizeof(TICKET)));
					temp->ID = j;
					strcpy(temp->src, src);
					strcpy(temp->dest, dest);
					strcpy(temp->airl, airl);
					temp->next = NULL;
					trav = temp;
					firs = temp;
					flag = 1;
				}
				else
				{
					TICKET *temp;
					temp = (TICKET *)(malloc(sizeof(TICKET)));
					temp->ID = j;
					strcpy(temp->src, src);
					strcpy(temp->dest, dest);
					strcpy(temp->airl, airl);
					temp->next = NULL;
					trav->next = temp;
					trav = temp;
				}
			}
			head = head->next;
		}
		route = route->down;
	}
	route = first;
	if(flag == 0)
	{
		return 0;
	}
	trav = firs;
	dummy=trav;
	while(dummy!=NULL)
	{
	printf("%-6d %-18.18s\t %-18.18s\t %-38.38s\n", dummy->ID, dummy->src, dummy->dest, dummy->airl);
	dummy=dummy->next;
	}
		// NEW PARAMETERS INPUT FROM USER

	 printf("Enter id of flight to be changed :");
	 scanf("%d",&di);
	 printf("Enter the new source city :");
	 scanf(" %[^\n]s",srce);
	 printf("Enter the new destination city : ");
	 scanf(" %[^\n]s",des);
	 printf("Enter new airlines name : ");
	 scanf(" %[^\n]s",newair);
	 printf("Enter the new destination city iata : ");
	 scanf(" %d",&ia2);
	 printf("Enter the new source city iata: ");
	 scanf(" %d",&ia);
	AIRPORTS *f = airports;
	int source1 = -1, destination1 = -1,f1=0,f2=0;
	/*TRAVERSAL IN LIST TO MODIFY THAT PARTICUALR ID OF FLIGHT*/

	while(airports != NULL)
	{
		AIRPORT *h = airports->next;
		while(h != NULL)
		{
			if(strcmp(src, h->city) == 0 && strcmp(dest, h->city) == 0)
			{	strcpy(h->city,srce);
				strcpy(h->city,des);
				destination = h->ID;
				source = h->ID;
				f1=1;
				break;
			}
			h = h->next;
		}
		if(f1==1)
		break;
		airports = airports->down;
	}
	f1=0;
	while(sec != NULL)
	{
		AIRPLANE *h2 = sec->next;
		while(h2 != NULL)
		{
			if(h2->Source_IATA == source && h2->Dest_IATA == destination)
			{
				h2->Source_IATA=ia;
				h2->Dest_IATA=ia2;
				f1=1;
				break;
				while(air != NULL)
					{
				AIRLINE *h3;
				h3 = air->next;
				while(h3 != NULL)
				{
				if(h3->ID == h2->AIRLINE_ID)
				{
					strcpy(h3->name,newair);
					f2=1;
					break;
				}
					h3 = h3->next;
				}
				if(f1==1 && f2==1)
				break;
				air = air->down;
				}
			}
			if(f1==1 && f2==1)
			break;
		h2 = h2->next;
		}
	 sec = sec->down;
	}
	/*WRITING TO FILE*/
	printfairports(ap1,c1,a1,"airports.dat",1);
	printfairports(ap1,c1,a1,"airlines.dat",2);
	printfairports(ap1,c1,a1,"routes.dat",3);
	printf("\t\tMODIFICATION SUCCESSFUL\n");
		return 1;
}

/*FUNCTION TO DISPLAY FLIGHTS AVAILABLE FOR MODIFICATION*/

void searchroute(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	AIRPORTS *first = airports;
	int source = -1, destination = -1;
	int flag = 0;
	while(airports != NULL)
	{
		AIRPORT *head = airports->next;
		while(head != NULL)
		{
			if(strcmp(src, head->city) == 0)
			{
				source = head->ID;
			}
			head = head->next;
		}
		head = airports->next;
		while(head != NULL)
		{
			if(strcmp(dest, head->city) == 0)
			{
				destination = head->ID;
			}
			head = head->next;
		}
		airports = airports->down;
	}
	airports = first;
	if(source != -1 && destination != -1)
	{
		if(modify2(src, dest, airlines, route, source, destination,airports) == 0)
		{
			printf("Sorry, no flights are available on this route\n");
		}
	}
	else if(source == -1 || destination == -1)
	{
		printf("Sorry, one of these cities is not present in the database\n");
	}
	else
	{
		printf("Sorry, No such cities are present in the database\n");
	}
}

/*fUNCTION REQUIRED TO PROMPT THE USER TO DISPLAY AVILABLE FLIGHTS BETWEEN TWO CITIES*/

void Flight(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
  char Source[500], Destination[500];
	printf("Enter the source city:\n");
	scanf(" %[^\n]s", Source);
	printf("Enter the destination city:\n");
	scanf(" %[^\n]s", Destination);

	searchroute(Source, Destination, route, airlines, airports);

}

/*FUNCTION TO UPDATE THE AIRPORT DETAILS IN DATA STRUCTURE*/

void modify(char *old,char *na,char *t,char *c,AIRPORTS *airports)
{
    AIRPORTS *head=airports;
    int f=0;
    while(head!=NULL)
	{
		AIRPORT *newp = head->next;
		while(newp != NULL)
		{
			if(strcmp(old,newp->name)==0)
                {	f=1;
                    strcpy(newp->name,na);
                     strcpy(newp->IATA,t);
                      strcpy(newp->ICAO,c);
                }
             	newp = newp->next;
		}
		head = head->down;
        }
        if(f==0)
        printf("INVALID AIRPORT NAME CANT MODIFY\n");
        else
        printf("\t\tMODIFICATION SUCCESSFUL\n");
}

/*FUNCTION TO TAKE NEW DETAILS AS INPUT TO UPDATE AIRPORT DETAILS*/

void Airport(AIRPORTS *airports,ROUTE *route, AIRLINES *airlines)
{
    AIRPORTS *ne=airports;

 char fna[35],IAT[5],IAC[6],old[35];
 printf("Enter the old airport name :");
 scanf(" %[^\n]s",old);
 printf("Enter the new airport name : ");
 scanf(" %[^\n]s",fna);
 printf("Enter new IATA code : ");
 scanf(" %s",IAT);
 printf("Enter new ICAO code : ");
 scanf(" %s",IAC);
 modify(old,fna,IAT,IAC,airports);
 printfairports(airports,route,airlines,"airports.dat",1);

}




/*FUNCTION TO PROVIDE USER THE OPTION TO NAVIGATE IN MODIFY MENU*/
void MODIFY(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	int a;
	char ans;
	system("clear");
	do
    {
	printf("\t\t\t\tWHAT CHANGES DO YOU NEED TO MAKE?\n\t\t\t1. ROUTE AND FLIGHT DETAILS \n\t\t\t2. AIRPORT DETAILS\n");
	scanf("%d", &a);
	switch(a)
	{
		case(1):
        Flight(route, airlines, airports);
			break;
		case(2):
			Airport(airports,route,airlines);
			break;
		default:
			printf("ENTER A VALID CHOICE\n");
			break;
	}
	printf("\t\t\t\t\tMODIFY ANY OTHER DETAILS(y/n)?:");
	scanf(" %c",&ans);
	system("clear");
    }while(ans!='n');
}
