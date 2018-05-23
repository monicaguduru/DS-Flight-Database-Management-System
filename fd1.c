#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<malloc.h>

/*defining the struct AIRPORT*/
typedef struct AIRPORT
{
	int ID;
	char name[100];
	char city[100];
	char country[100];
	char IATA[5];
	char ICAO[5];
	float timezone;
	struct AIRPORT *next;
}AIRPORT;

/*defining the struct AIRPORTS*/
typedef struct AIRPORTS
{
	struct AIRPORT *next;
	struct AIRPORTS *down;
}AIRPORTS;

/*defining the struct AIRLINE*/
typedef struct AIRLINE
{
	int ID;
	char name[500];
	char ICAO[5];
	char country[100];
	struct AIRLINE *next;
}AIRLINE;

/*defining the struct AIRLINES*/
typedef struct AIRLINES
{
	struct AIRLINE *next;
	struct AIRLINES *down;
}AIRLINES;

/*defining the struct AIRPLANE*/
typedef struct AIRPLANE
{
	char AIRLINE_IATA[3];
	int AIRLINE_ID;
	char Source[5];
	int Source_IATA;
	char Dest[5];
	int Dest_IATA;
	struct AIRPLANE *next;
}AIRPLANE;

/*defining the struct ROUTE*/
typedef struct ROUTE
{
	struct AIRPLANE *next;
	struct ROUTE *down;
}ROUTE;

/*defining a linked list NODE*/
typedef struct NODE
{
	int data;
	char city[1000];
	struct NODE *next;
}NODE;

/*defining a linked list TICKET*/
typedef struct TICKET
{
	int ID;
	char src[100];
	char dest[100];
	char airl[200];
	struct TICKET *next;
}TICKET;

/*booking a ticket*/
void book(int x)
{
	FILE *fp=fopen("passenger.txt","a+");
	char ans[3],na[50],s;
	int id,age,f=0;
	printf("\n\n\t\tENTER FOLLOWING DETAILS FOR BOOKING TICKET\n\n");
	printf("Enter name: ");
	scanf(" %[^\n]s",na);
	printf("Enter gender(M/F)");
	scanf(" %c",&s);
	printf("Enter age:");
	scanf("%d",&age);
	printf("enter flight no.: ");
	scanf("%d",&id);
	if(id>=1 && id<=x)
	  f=1;
	if(f==1)
	{
		printf("TICKET SUCCESFULLY BOOKED IN THE NAME OF %s\n",na);
		fprintf(fp,"%s\t",na);
		fprintf(fp,"%c\t",s);
		fprintf(fp,"%d\t",age);
		fprintf(fp,"%d\n",id);
	}
	else
		printf("NO SUCH FLIGHT EXISTS\n");
	fclose(fp);
}

/*loader*/
void loader(int j)
{
	int i;
	system("clear");
	for(i = 0; i <= 19; i++)
	{
		printf("\n");
	}
	for(i = 0; i <= 58; i++)
	{
		printf(" ");
	}
	printf("LOADING\n");
	for(i = 0; i <= 58; i++)
	{
		printf(" ");
	}
	for(i = 0; i <= j;i++)
	{
		printf(".");
	}
	for(i = 0; i <= 19; i++)
	{
		printf("\n");
	}
}

/*initializing Route Item*/
ROUTE *initializeRouteItem()
{
	ROUTE *route, *first;
	route = (ROUTE *)malloc(sizeof(ROUTE));
	route->next = NULL;
	route->down = NULL;
	first = route;
	int i = 1;
	while(i	!= 26)
	{
		ROUTE *temp = (ROUTE *)malloc(sizeof(ROUTE));
		temp->next = NULL;
		temp->down = NULL;
		route->down = temp;
		route = temp;
		i++;
	}
	route = first;
	return route;
}

/*inserting an item in route*/
ROUTE *insertRouteItem(ROUTE *route, AIRPLANE *airD)
{
	int i = airD->Source[0] - 65;
	ROUTE *first = route;
	while(i >= 1)
	{
		route = route->down;
		i--;
	}
	if(route->next == NULL)
	{
		route->next = airD;
	}
	else
	{
		AIRPLANE *temp;
		temp = route->next;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = airD;
	}
	route = first;
	return route;
}

/*inserting a route*/
ROUTE *insertROUTE()
{
	FILE *routes = fopen("routes.dat", "r+");
	int r_count = 66765, i = 0, m = 0, l = 0, k = 0, j = 0;
	ROUTE *route;
	route = initializeRouteItem();
	while(i != r_count)
	{
		AIRPLANE *airD = (AIRPLANE *)(malloc(sizeof(AIRPLANE)));
		char temp[100];
		char scan[500];
		char tem[10][500];
		for(m = 0; m <= 5; m++)
		{
			strcpy(tem[m], temp);
		}
		fgets(scan, 500, routes);
		if(scan[0] == ' ' || scan[0] <= 0)
		{
			break;
		}
		else if(scan[0] == '\n'|| scan[0] == '\0')
		{
			break;
		}
		i++;
		l = 0;
		for(k = 0; k <= 5; k++)
		{
			for(j = 0;scan[l] != '\t';)
			{
				tem[k][j++] = scan[l++];
			}
			tem[k][j] ='\0';
			l++;
		}
		strcpy(airD->AIRLINE_IATA, tem[0]);
		airD->AIRLINE_ID = atoi(tem[1]);
		strcpy(airD->Source, tem[2]);
		airD->Source_IATA = atoi(tem[3]);
		strcpy(airD->Dest, tem[4]);
		airD->Dest_IATA = atoi(tem[5]);
		airD->next = NULL;
		//printf("%s %d %s %d %s %d\n", airD->AIRLINE_IATA, airD->AIRLINE_ID, airD->Source, airD->Source_IATA, airD->Dest, airD->Dest_IATA);
		route = insertRouteItem(route, airD);
	}
	fclose(routes);
	return route;
}

/*initializing Airlines item*/
AIRLINES *initializeAirlinesItem()
{
	AIRLINES *airlines, *first;
	airlines = (AIRLINES *)malloc(sizeof(AIRLINES));
	airlines->next = NULL;
	airlines->down = NULL;
	first = airlines;
	int i = 1;
	while(i	!= 26)
	{
		AIRLINES *temp = (AIRLINES *)malloc(sizeof(AIRLINES));
		temp->next = NULL;
		temp->down = NULL;
		airlines->down = temp;
		airlines = temp;
		i++;
	}
	airlines = first;
	return airlines;
}

/*insert Airlines Item*/
AIRLINES *insertAirlinesItem(AIRLINES *airlines, AIRLINE *airD)
{
	int i = airD->country[0] - 65;
	AIRLINES *first = airlines;
	while(i >= 1)
	{
		airlines = airlines->down;
		i--;
	}
	if(airlines->next == NULL)
	{
		airlines->next = airD;
	}
	else if(airlines->next != NULL)
	{
		AIRLINE *temp;
		temp = airlines->next;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = airD;
	}
	airlines = first;
	return airlines;
}

/*insert Airline*/
AIRLINES *insertAIRLINE()
{
	FILE *airlines = fopen("airlines.dat", "r+");
	int a_count = 5942, i = 0, m = 0, l = 0, k = 0, j = 0;
	AIRLINES *airways;
	airways = initializeAirlinesItem();
	while(i != a_count)
	{
		AIRLINE *airD = (AIRLINE *)(malloc(sizeof(AIRLINE)));
		char airID[10];
		char temp[500];
		char scan[500];
		char tem[10][500];
		for(m = 0; m <= 7; m++)
		{
			strcpy(tem[m], temp);
		}
		fgets(scan, 500, airlines);
		if(scan[0] == ' ' || scan[0] <= 0)
		{
			break;
		}
		else if(scan[0] == '\n' || scan[0] == '\0')
		{
			break;
		}
		i++;
		l = 0;
		for(k = 0; k <= 3; k++)
		{
			for(j = 0;scan[l] != '\t';)
			{				
				if(scan[l] == '\n')
				{
					break;
				}
				tem[k][j++] = scan[l++];	
			}
			tem[k][j] ='\0';
			l++;
		} 
		airD->ID = atoi(tem[0]);
		strcpy(airD->name, tem[1]);
		strcpy(airD->ICAO, tem[2]);
		strcpy(airD->country, tem[3]);
		airD->next = NULL;
		//printf("%d\t\t%s\t\t%s\t\t%s\n", airD->ID, airD->name, airD->ICAO, airD->country);
		airways = insertAirlinesItem(airways, airD);
	}
	fclose(airlines);
	return airways;
}

/*initializing Airports item*/
AIRPORTS *initializeAirportsItem()
{
	AIRPORTS *airports, *first;
	airports = (AIRPORTS *)malloc(sizeof(AIRPORTS));
	airports->next = NULL;
	airports->down = NULL;
	first = airports;
	int i = 1;
	while(i	!= 26)
	{
		AIRPORTS *temp = (AIRPORTS *)malloc(sizeof(AIRPORTS));
		temp->next = NULL;
		temp->down = NULL;
		airports->down = temp;
		airports = temp;
		i++;
	}
	airports = first;
	return airports;
}

/*insert Airports Item*/
AIRPORTS *insertAirportsItem(AIRPORTS *airports, AIRPORT *airD)
{
	int i = airD->country[0] - 65;
	AIRPORTS *first = airports;
	while(i >= 1)
	{
		airports = airports->down;
		i--;
	}
	if(airports->next == NULL)
	{
		airports->next = airD;
	}
	else if(airports->next != NULL)
	{
		AIRPORT *temp;
		temp = airports->next;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = airD;
	}
	airports = first;
	return airports;
}

/*insert Airport*/
AIRPORTS *insertAIRPORT()
{
	FILE *airports = fopen("airports.dat", "r+");
	int a_count = 4842, i = 0, m = 0, l = 0, k = 0, j = 0;
	AIRPORTS *aports;
	aports = initializeAirportsItem();
	while(i != a_count)
	{
		AIRPORT *airD = (AIRPORT *)(malloc(sizeof(AIRPORT)));
		char airID[10];
		char temp[500];
		char scan[500];
		char tem[10][500];
		for(m = 0; m <= 7; m++)
		{
			strcpy(tem[m], temp);
		}
		fgets(scan, 500, airports);
		if(scan[0] == ' ' || scan[0] <= 0)
		{
			break;
		}
		else if(scan[0] == '\n'|| scan[0] == '\0')
		{
			break;
		}
		i++;
		l = 0;
		for(k = 0; k <= 6; k++)
		{
			for(j = 0;scan[l] != '\t';)
			{				
				if(scan[l] == '\n')
				{
					break;
				}
				tem[k][j++] = scan[l++];	
			}
			tem[k][j] ='\0';
			l++;
		} 
		airD->ID = atoi(tem[0]);
		strcpy(airD->name, tem[1]);
		strcpy(airD->city, tem[2]);
		strcpy(airD->country, tem[3]);
		strcpy(airD->IATA, tem[4]);
		strcpy(airD->ICAO, tem[5]);
		airD->timezone = atof(tem[6]);
		airD->next = NULL;
		//printf("%d %s\t\t%s\t\t%s\t\t%s\t\t%s\t\t%g\n", airD->ID, airD->name, airD->city, airD->country, airD->IATA, airD->ICAO, airD->timezone);
		aports = insertAirportsItem(aports, airD);
	}
	fclose(airports);
	return aports;
}
/*find name of the airline by ID*/
void findAirline(AIRLINES *airlines, int search, char *airl)
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

/*search Flights by City ID*/
int searchFlightsByCityID(char *src, char *dest, AIRLINES *airlines, ROUTE *route, int source, int destination)
{
	ROUTE *first = route;
	int flag = 0, j = 0;
	TICKET *firs, *trav;
	while(route != NULL)
	{
		AIRPLANE *head = route->next;
		while(head != NULL)
		{
			if(head->Source_IATA == source && head->Dest_IATA == destination)
			{	
				char airl[200];
				findAirline(airlines, head->AIRLINE_ID, airl);
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
	if(j > 0)
	{
		printf("-----------------------------------------------------------------------------\nA.ID\tSource                  Destination                 Airline name\n-----------------------------------------------------------------------------\n");
	}
	while(trav != NULL)
	{
		printf("%-6d %-18.18s\t %-18.18s\t %-38.38s\n", trav->ID, trav->src, trav->dest, trav->airl);
		trav = trav->next;
	}
	book(j);
	return 1;
}

/*find flights between 2 countries*/
void findFlightsbyCountry(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	int i = src[0] - 65, j = 0, k = 0, l = 0;
	AIRPORTS *first = airports;
	while(i >= 1)
	{
		airports = airports->down;
		i--;
	}
	AIRPORT *head = airports->next;
	ROUTE *fir = route;
	NODE *source_trav, *source_first;
	int flag = 0;
	while(head != NULL)
	{
		if(strcmp(src, head->country) == 0)
		{
			NODE *temp;
			temp = (NODE *)malloc(sizeof(NODE));
			temp->data = head->ID;
			strcpy(temp->city, head->city);
			temp->next = NULL;
			if(flag == 0)
			{
				source_trav = temp;
				source_first = temp;
				flag = 1;
			}
			else
			{
				source_trav->next = temp;
				source_trav = temp;
			}	
		}
		head = head->next;
	}
	source_trav = source_first;
	airports = first;
	i = dest[0] - 65;
	while(i >= 1)
	{
		airports = airports->down;
		i--;
	}
	head = airports->next;
	NODE *dest_trav, *dest_first;
	int flag1 = 0;
	while(head != NULL)
	{
		if(strcmp(dest, head->country) == 0)
		{
			NODE *temp;
			temp = (NODE *)malloc(sizeof(NODE));
			temp->data = head->ID;
			strcpy(temp->city, head->city);
			temp->next = NULL;
			if(flag1 == 0)
			{
				dest_trav = temp;
				dest_first = temp;
				flag1 = 1;
			}
			else
			{
				dest_trav->next = temp;
				dest_trav = temp;
			}	
		}
		head = head->next;
	}
	airports = first;
	source_trav = source_first;
	dest_trav = dest_first;
	if(flag != 0 && flag1 != 0)
	{
		flag = 0;
		TICKET *firs, *trav;
		while(source_trav != NULL)
		{
			dest_trav = dest_first;
			while(dest_trav != NULL)
			{
				while(route != NULL)
				{
					AIRPLANE *head1 = route->next;
					while(head1 != NULL)
					{
						l++;
						if(l%100000000 == 0)
						{
							k++;
							loader((k)%7);
						}
						if(head1->Source_IATA == source_trav->data && head1->Dest_IATA == dest_trav->data)
						{	
							j++;
							char airl[200];
							findAirline(airlines, head1->AIRLINE_ID, airl);
							if(flag == 0)
							{
								TICKET *temp;
								temp = (TICKET *)(malloc(sizeof(TICKET)));
								temp->ID = j;
								strcpy(temp->src, source_trav->city);
								strcpy(temp->dest, dest_trav->city);
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
								strcpy(temp->src, source_trav->city);
								strcpy(temp->dest, dest_trav->city);
								strcpy(temp->airl, airl);
								temp->next = NULL;
								trav->next = temp;	
								trav = temp;
							}
						}
						head1 = head1->next;
					}
					route = route->down;
				}
				route = fir;
				dest_trav = dest_trav->next;
			}
			source_trav = source_trav->next;
		}
		trav = firs;
		source_trav = source_first;
		dest_trav = dest_first;
		system("clear");
		if(j > 0)
		{
			printf("-----------------------------------------------------------------------------\nA.ID\tSource                  Destination                 Airline name\n-----------------------------------------------------------------------------\n");
		}
		while(trav != NULL)
		{
			printf("%-6d %-18.18s\t %-18.18s\t %-38.38s\n", trav->ID, trav->src, trav->dest, trav->airl);
			trav = trav->next;
		}
		if(j > 0)
		{
			book(j);
		}
		else
		{
			printf("Sorry, no flights available between these two countries\n");
		}
	}
	else if(flag != 0 || flag1 != 0)
	{
		printf("One of the countries entered is not valid\n");
	}
	else
	{
		printf("Both the countries entered are not valid\n");
	}
}

/*find flights between 2 cities*/
void findFlightsbyCity(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
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
		if(searchFlightsByCityID(src, dest, airlines, route, source, destination) == 0)
		{
			printf("Sorry, no flights are available on this route\n");
		}
	}
	else if(source == -1 && destination == -1)
	{
		printf("Sorry, No such cities are present in the database\n");
	}
	else
	{
		printf("Sorry, one of these cities is not present in the database\n");
	}
}

/*booking by country menu*/
void bookByCountry(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	char Source[500], Destination[500];
	printf("Enter the source country:\n");
	scanf(" %[^\n]s", Source);
	printf("Enter the destination country:\n");
	scanf(" %[^\n]s", Destination);
	findFlightsbyCountry(Source, Destination, route, airlines, airports);
}

/*booking by city menu*/
void bookByCity(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	char Source[500], Destination[500];
	printf("Enter the source city:\n");
	scanf(" %[^\n]s", Source);
	printf("Enter the destination city:\n");
	scanf(" %[^\n]s", Destination);
	findFlightsbyCity(Source, Destination, route, airlines, airports);
}
/*function calling all the above ones by choice to the user*/
void bookaTicket(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	int choice;
	system("clear");
	printf("On what basis do you want to book a ticket?\n1.Country\n2.City\n");
	scanf("%d", &choice);
	switch(choice)
	{
		case(1):
			bookByCountry(route, airlines, airports);
			break;
		case(2):
			bookByCity(route, airlines, airports);
			break;
		default:
			printf("Invalid choice\n");
			break;
	}
}

/*task function*/
void task1(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
{
	bookaTicket(route, airlines, airports);
}
