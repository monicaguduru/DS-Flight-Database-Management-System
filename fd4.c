#include<stdio.h>
#include<string.h>
#include<stdlib.h>

/*Overwrites the details of airports after deleting given airport to airports.dat file*/
void printDeletedAirport(AIRPORTS *airports)
{
	FILE *fo1=fopen("airports.dat","w");
	while(airports != NULL)
	{
		AIRPORT *headapt;
		headapt = airports->next;
		while(headapt != NULL)
		{
			fprintf(fo1,"%d\t%s\t%s\t%s\t%s\t%s\t%g\n", headapt->ID, headapt->name, headapt->city, headapt->country, headapt->IATA, headapt->ICAO, headapt->timezone);
			headapt = headapt->next;
		}
		airports = airports->down;
	}
	fclose(fo1);
	
}

/*Overwrites details of routes after  deleting a certain routes between two specific cities in routes.dat file*/
void printDeletedRoute(ROUTE *route)
{
	FILE *fo2=fopen("routes.dat","w");
	while(route != NULL)
	{
		AIRPLANE *head2;
		head2 = route->next;
		while(head2 != NULL)
		{
			fprintf(fo2,"%s\t%d\t%s\t%d\t%s\t%d\n", head2->AIRLINE_IATA, head2->AIRLINE_ID, head2->Source, head2->Source_IATA, head2->Dest, head2->Dest_IATA);
			head2 = head2->next;
		}
		route = route->down;
	}
	fclose(fo2);
}

/*Deletes the details of entered airport in airports.dat and routes.dat files*/
void deleteAirport(char aiprt[],ROUTE *route,AIRPORTS *airports)
{
	char i[10];
	AIRPORTS *tmpAir=airports;
	while(tmpAir!=NULL)
	{
		AIRPORT *airpt=tmpAir->next;
		while(airpt!=NULL)
		{
			if(airpt->next != NULL)
			{
				if(strcmp(aiprt,(airpt->next)->name)==0)/*Checking if next node's airport name is same as entered airport name*/
				{
					strcpy(i,(airpt->next)->IATA);/*copying iata code of the given airport*/
					//printf("%s\n",i);
					airpt->next=(airpt->next)->next;
				}
			}
			airpt=airpt->next;
		}
		tmpAir=tmpAir->down;
	}
	printDeletedAirport(airports);
	ROUTE *tmpRoute=route;
	while(tmpRoute!=NULL)
	{
		AIRPLANE *tmpHead1,*pre;
		while(strcmp((tmpRoute->next)->Source,i)==0 || strcmp((tmpRoute->next)->Dest,i)==0)/*Checking if source or destination city of next node matches with string i*/
		{
			tmpRoute->next = tmpRoute->next->next;
		}
		tmpHead1 = tmpRoute->next;
		while(tmpHead1 != NULL)
		{
			int flag = 0;	
			if(tmpHead1->next!=NULL)
			{
				if(strcmp(i,(tmpHead1->next)->Source)==0 || strcmp(i,(tmpHead1->next)->Dest)==0)
				{
					flag = 1;
					tmpHead1->next=(tmpHead1->next)->next;
				}
			}
			if(flag == 0)
			{
				tmpHead1=tmpHead1->next;
			}	
		}
		tmpRoute=tmpRoute->down;
	}
	printDeletedRoute(route);/*Calling the function that overwrites routes.dat file deleting given airport from it*/
}

/*Overwrites details of all airlines other than the one to be deleted to airlines.dat file*/
void printDeletedAirline(AIRLINES *airlines)
{
	FILE *fo3= fopen("airlines.dat","w");
	while(airlines != NULL)
	{
		AIRLINE *head3;
		head3 = airlines->next;
		while(head3 != NULL)
		{
			fprintf(fo3,"%d\t%s\t%s\t%s\n", head3->ID, head3->name, head3->ICAO, head3->country);
			head3 = head3->next;
		}
		airlines = airlines->down;
	}
	fclose(fo3);	
}

/*Deletes the details of given airline from airlines and route*/
void deleteAirline(char airL[],AIRLINES *airlines,ROUTE *route)
{
	int i;
	AIRLINES *tmpAirL=airlines;
	while(tmpAirL!=NULL)
	{
	AIRLINE *airli=tmpAirL->next;
	while(airli!=NULL)
	{
		if(airli->next != NULL)
		{
			if(strcmp(airL,(airli->next)->name)==0)
			{
				i=(airli->next)->ID;/*Assigning the value of airline id to i*/
				//printf("%d\n",i);
				airli->next=(airli->next)->next;
			}
		}
		airli=airli->next;
		}
			tmpAirL=tmpAirL->down;
	}
	printDeletedAirline(airlines);
	ROUTE *tmpRoute2=route;
	while(tmpRoute2!=NULL)
	{
		AIRPLANE *tmpHead1;
		while((tmpRoute2->next)->AIRLINE_ID==i)/*Checking if the first node of list has the given airline id*/
		{
			tmpRoute2->next = tmpRoute2->next->next;
		}
		tmpHead1 = tmpRoute2->next;
		while(tmpHead1 != NULL)
		{
			int flag = 0;	
			if(tmpHead1->next!=NULL)
			{
				if((tmpHead1->next)->AIRLINE_ID==i)/*Checking if next node has same id as the entered airline id*/
				{
					flag = 1;
					tmpHead1->next=(tmpHead1->next)->next;
				}
			}
			if(flag == 0)
			{
				tmpHead1=tmpHead1->next;
			}	
		}
		tmpRoute2=tmpRoute2->down;
	}
	printDeletedRoute(route);
}

/*Deletes all possible routes between two cities*/
void deleteRoute(char c1[],char c2[],ROUTE *route)
{
	ROUTE *tmpRoute=route;
	//int num=0;
	while(tmpRoute!=NULL)
	{
		AIRPLANE *tmpHead;
		int flag;
		while(((strcmp((tmpRoute->next)->Source,c1)==0) && (strcmp((tmpRoute->next)->Dest,c2)==0)))
		{
			tmpRoute->next=tmpRoute->next->next;
		}
		while(((strcmp((tmpRoute->next)->Source,c2)==0) && (strcmp((tmpRoute->next)->Dest,c1)==0)))
		{
			tmpRoute->next=tmpRoute->next->next;
		}
		tmpHead=tmpRoute->next;
		while(tmpHead->next!=NULL)
		{
			//num+=1;
			//printf("num=%d\n",num);
			flag = 0;
			if ((strcmp((tmpHead->next)->Source,c1)==0) && (strcmp((tmpHead->next)->Dest,c2)==0) )
			{
				flag=1;
				(tmpHead->next) = (tmpHead->next)->next;
			}
			if(((strcmp((tmpHead->next)->Source,c2)==0) && (strcmp((tmpHead->next)->Dest,c1)==0)))
			{
				flag = 1;
				(tmpHead->next) = (tmpHead->next)->next;
			}
			if(flag == 0)
			{
				tmpHead=tmpHead->next;
			}
		}
		tmpRoute=tmpRoute->down;
	}
	printDeletedRoute(route);
}
void task3(ROUTE *route,AIRLINES *airlines,AIRPORTS *airports)
{
	int opt,p=1;
	char airp[100],airl[100],c1[100],c2[100];
	printf("Options:1.Erasing details of an entered airplane from the table\n");
	printf("        2.Erasing details of an entered airline from the table\n");
	printf("	3.Erasing route between the entered cities from routes table\n");
	printf("        4.exit\n");
	scanf("%d",&opt);
	getchar();
	while(opt==1 || opt==2 || opt==3)
	{
		if(opt==1)
		{
			printf("Enter the name of the airport you want to delete\n");
			scanf("%[^\n]s",airp);
			getchar();
			deleteAirport(airp,route,airports);
		}
		else if(opt==2)
		{
			printf("Enter the name of the airline you want to delete\n");
			scanf("%[^\n]s",airl);
			getchar();
			deleteAirline(airl,airlines,route);
		}
		else if(opt==3)
		{
			printf("Enter the name of cities between which you want to delete the route:\n");
			scanf("%[^\n]s",c1);
			getchar();
			scanf("%[^\n]s",c2);
			getchar();
			deleteRoute(c1,c2,route);
		}
		p+=1;
		if(p>1)
		{
			printf("Options:1.Erasing details of an entered airplane from the table\n");
			printf("        2.Erasing details of an entered airline from the table\n");
			printf("	3.Erasing route between the entered cities from routes table\n");
			printf("        4.exit\n");

		}
		scanf("%d",&opt);
		getchar();
		if(opt==4)
		{
			printf("End of your deletion process\n");
		}
	}
}
