/*Search flight and print the flights in the input city or input time zone and input country in airlines pointer*/
void searchPrintFlights(char *cityCountry,ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	int flag=1;
	while(airlines != NULL)
	{
		AIRLINE *temp;
		temp = airlines->next;
		while(temp != NULL)
		{
			if(strcmp(cityCountry,temp->country)==0){
			flag=0;
			printf("%-7.2d%-6.7s%-22.18s%-18.18s\n", temp->ID, temp->name, temp->ICAO, temp->country);
			}
			temp = temp->next;
		}
		airlines = airlines->down;
	}
	if(flag==1){
		printf("\n\nSorry, there are no flights in this timezone.\n\n");
	}
}
/*Search flights with input city name and country name in airport pointer*/
void searchFlightsInCity(char *Country,char *src, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	AIRPORTS *first = airports;
	char cityCountry[25];
	while(airports != NULL)
	{
		AIRPORT *head = airports->next;
		while(head != NULL)
		{
			if(strcmp(src,head->city)==0 && strcmp(Country,head->country)==0){
				strcpy(cityCountry,head->country);
				printf("\n\nFlights available:\n\n");
				break;
			}
			head = head->next;
		}
		airports = airports->down;
	}
	searchPrintFlights(cityCountry,route,airlines,airports);
}
/*Search flights with input time zone and country name in airport pointer*/
void searchFlightsInTimezone(char *Country,float tz, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	char cityCountry[25];
	while(airports != NULL)
	{
		AIRPORT *head = airports->next;
		while(head != NULL)
		{
			if(tz == head->timezone && strcmp(Country,head->country)==0){
				strcpy(cityCountry,head->country);
				printf("\n\nFlights available:\n\n");
				break;
			}
			head = head->next;
		}
		airports = airports->down;
	}
	searchPrintFlights(cityCountry,route,airlines,airports);
}
/*Taking required inputs and performing operations as required by the user either do search by city name or time zone*/
void searchFlights(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports){
	char a,Country[50],start[50];
	int fsc;
	float tz;
	do{
	printf("\n\nSearch flights by city , all incoming and outgoing flights in the city entered:\n\n");
	printf("\nEnter the country in which you want to search flights:\n\nCountry name:  ");
	scanf(" %[^\n]s",Country);
	printf("\nDo you want to search by giving input as: \n\n\t1.City name\n\n\t2.Time Zone\n\n\tEnter your option:  ");
	scanf(" %d",&fsc);
	switch(fsc){
		case(1):
			printf("\n\tEnter the city in which you want to search flights:\n\n\tCity name:  ");
			scanf(" %[^\n]s",start);
			searchFlightsInCity(Country,start, route, airlines, airports);
			break;
		case(2):
			printf("\n\tEnter the time zone in which you want to search flights:  ");
			scanf(" %f",&tz);
			searchFlightsInTimezone(Country,tz, route, airlines, airports);
			break;
		default:
			printf("\n\n\tInvalid choice\n");
			break;
	}
	getchar();
	printf("\n\n\t\tSearch for another option to search? \nEnter y/n: ");
	scanf("%c",&a);
	}while(a!='n');

}
