										PROJECT ID : 22
										---------------

									PROJECT NAME : Flight Database
									------------------------------
Data Structure Used:
			Linked Lists of Linked Lists i.e. insertion is done based on the first letter of a corresponding field from 3 huge databases and stored in 3 different structures, each of which consisting of 26 linked lists, each containing large number of nodes
Group Members :
---------------

1. Subhadeep Dash ( Roll No. : 201601021 )    -----------> Task 1
2. G.Monica Sagar ( Roll No. : 201601026 )    -----------> Task 2
3. V. S. Pragna ( Roll No. :201601106 )	      -----------> Task 3
4. Laisha Wadhwa ( Roll No. 201601048 )       -----------> Task 4


Main Function details:

1. First it will prompt asking whether you are an user or admin.

------------------ For User ------------------

1. Then it will ask you whether you are an existing user or a new user

------------------ For Existing User ---------

1. It will ask for username and password and if the username and password exists in our users file then it will ask whether you want to book a ticket or search flights

----------------- For New User ---------------

1. It will ask for your username and password and store it in our users file

-----------------For Admin -------------------

1. You will be prompted to enter a password and if the password is valid then you can modify details or delete details 

------------------------------------------------------------ By Subhadeep Dash --------------------------------------------------------

=========================================================================================================================================

BOOK A TICKET:

------>	When the user prompts to book a ticket, a screen appears, giving the user the choice of booking between two countries or between two cities. 


------> After selecting the desired option, the user is prompted to enter the source and destination cities/countries. A screen appears showing all the available flights with their IDs.

------> If there are any flights available, then the user is prompted to book a ticket by filling its particulars. The passenger record is stored in a file by name Passenger.txt
==========================================================================================================================================
*******Functions for task1():
------------------------------------------------------------------------------------------------------------------------------------------
------>
void task1(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******This task calls the entire booking options.
*******This task will call the further functions for booking a ticket of his choice.
*******After this, the user will be able to choose between the bookings for country or city by user's choice.

------------------------------------------------------------------------------------------------------------------------------------------
------>
void bookaTicket(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******This function calls all the above ones by choice to the user
*******As soon as this function is called, the user will be prompted whether to book a ticket
*******This prompts the user to book a ticket either by country or by city
------------------------------------------------------------------------------------------------------------------------------------------
------>
void bookByCity(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******This facilitates the user to book based on Source and Destination Cities
*******This provides the user to obtain the available flights
*******After obtaining you can further book a ticket, if the flights are available

------------------------------------------------------------------------------------------------------------------------------------------
------>
void bookByCountry(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******This facilitates the user to book based on Source and Destination Countries
*******This provides the user to obtain the available flights between any two cities of the countries
*******After obtaining you can further book a ticket, if the flights are available

------------------------------------------------------------------------------------------------------------------------------------------
------>
void findFlightsbyCity(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******This function finds out the flights by considering two strings
*******It compares all the strings and gives all available flights between two cities
*******The output is all the flights, from src to dest, from further function searchFlightsByCityID

------------------------------------------------------------------------------------------------------------------------------------------
------>
void findFlightsbyCountry(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

*******It finds all the flights originating from a particular country to another country by considering to two strings.
*******Therefore you get the output as flights by searching all relevant data

------------------------------------------------------------------------------------------------------------------------------------------
------>
int searchFlightsByCityID(char *src, char *dest, AIRLINES *airlines, ROUTE *route, int source, int destination)

*******It traverses through the entire data ROUTE and finds out the flights between two cities
*******If there are any flights, it prompts the user to book
*******Else it ends with a non availability message
------------------------------------------------------------------------------------------------------------------------------------------
------>
void findAirline(AIRLINES *airlines, int search, char *airl)

*******This function finds the name of the airline with an airlineID
*******This function traverses through the entire AIRLINES data structure and stores it in airl
*******This stores the airline name in an array airl

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRPORTS *insertAIRPORT()

*******In this function, we scan an airport and store it in the AIRPORT data structure
*******This function further sends it to insertAirportsItem function

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRPORTS *insertAirportsItem(AIRPORTS *airports, AIRPORT *airD)

*******Here we test the first letter of the Country and traverse till the desired pointer.
*******Then we insert it in the linked list to which the pointer refers

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRPORTS *initializeAirportsItem()

*******Here we initialize 26 pointer nodes to 26 linked lists which are initially NULL

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRLINES *insertAIRLINE()

*******In this function, we scan an airline and store it in the AIRLINE data structure
*******This function further sends it to insertAirlinesItem function

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRLINES *insertAirlinesItem(AIRLINES *airlines, AIRLINE *airD)

*******Here we test the first letter of the Country and traverse till the desired pointer.
*******Then we insert it in the linked list to which the pointer refers

------------------------------------------------------------------------------------------------------------------------------------------
------>
AIRLINES *initializeAirlinesItem()

*******Here we initialize 26 pointer nodes to 26 linked lists which are initially NULL
------------------------------------------------------------------------------------------------------------------------------------------
------>
ROUTE *insertROUTE()

*******In this function, we scan a route and store it in the AIRPLANE data structure
*******This function further sends it to insertAirportsItem function
------------------------------------------------------------------------------------------------------------------------------------------
------>
ROUTE *insertRouteItem(ROUTE *route, AIRPLANE *airD)

*******Here we test the first letter of the IATA code of the source city and traverse till the desired pointer.
*******Then we insert it in the linked list to which the pointer refers

------------------------------------------------------------------------------------------------------------------------------------------
------>
ROUTE *initializeRouteItem()

*******Here we initialize 26 pointer nodes to 26 linked lists which are initially NULL

------------------------------------------------------------------------------------------------------------------------------------------
------>
void loader(int j)

*******This function is defined for the loader
*******This makes the interface quite user friendly till the user waits

------------------------------------------------------------------------------------------------------------------------------------------
------>
void book(int x)

*******This initializes a menu for booking a ticket and collects corresponding details from the user.
*******It stores the user data in a file named passenger.txt

------------------------------------------------------------------------------------------------------------------------------------------


========================================================================== Task 2 =========================================================================================

--------------------------------------------------------------SEARCH BY G.MONICA---------------------------------------------------------------------

You will enter this interface if you are an existing user and only after you enter correct username and password.


void searchFlights(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> This function will ask you to input a country name 

--> Then you can search the flight names with city name or timezone

--> This will call two functions according to the option you fill




void searchFlightsInCity(char *Country,char *src, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> This function will search flights in a city of a country.

--> This will traverse through the hash table and match the input country name and input city name and call a function again.

--> This internally will call a function to print the details of the flight.




void searchFlightsInTimezone(char *Country,float tz, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> This is taking a timezone as input and printing the flights in that time zone
.
--> This internally will also call a function to print the details of the flight.




void searchPrintFlights(char *cityCountry,ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> This is function traverses and is used to print details of the flight




---------------------------------------------------------- Main function by Monica -----------------------------------------------------


void Entrance(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> asks whether the person is a user or an admin person and accordingly calls functions




void ForUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> Asks if the person is an exising or a new user and accordingly calls the functions 




void ForExistingUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports);


--> Asks for username and password and checks the validity
.
--> If the username and password is valid then asks whether the user wants to book a ticket or search flight

--> If it has to book a ticket it will call book function and ask details accordingly




void ValidityForUser(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports,char *un,char *pw);


--> Checks whether the input username and password exists and allows you to book or search flights if your username and password are valid 


void createNewUser(char *un,char *pw);


--> Creates a new user name with the given input username and password.




void ForAdmin(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
;

--> It will ask you to input a password

--> THe input password's validity is checked and the admin can modify details or delete details

=========================================================  Task 3  =======================================================================


------------------------------------------------ By Pragna ----------------------------------------
==========================================================================================================================================
DELETION:
	  
	  
===>gives four options to the user asking user what he/she wants to delete. 
	  
	  
===>first three options to delete certain particulars i.e. (airport,airline,route).
	  
	  
===>last option to exit the deletion function.

==========================================================================================================================================


----------------------------- Functions in task3 --------------------------------------------


	 
1) void printDeletedAirport(AIRPORTS *airports)
  
	    
	    Input : modified airports linked list.

		    Output : overwrites airports.dat file by airports other than the one that is to be deleted.
	    

	 
2)void printDeletedRoute(ROUTE *route)
	 
	   
	
			Input : modified routes linked list.
	   
			Output : Overwrites routes.dat file by routes other than the routes that are between two given cities.
	   
	 
3)void printDeletedAirline(AIRLINES *airlines)
	   
	   

			Input : modified airlines linked list.
	   
			Output : Overwrites airlines.dat file by airlines other than the one that is to be deleted.
	   
	 

4)void deleteAirport(char aiprt[],ROUTE *route,AIRPORTS *airports)
	 
	   

			Input :  name of the airport to be deleted,route linked list,airpots linked list.
	   
			Output : Deletes the details of airport in airports,route linked lists and overwrites the modified airports, route linked lists to airports.dat, route.dat files.
	   
	
5)void deleteAirline(char airL[],AIRLINES *airlines,ROUTE *route)
	 
	   
			
			Input : name of the airline to be deleted,airlines linked list,route linked list.
	   
			Output : Deletes the details of airline in airline,route linked lists and overwrites the modified airline, route linked lists to airlines.dat, route.dat files.
	   
	

6)void deleteRoute(char c1[],char c2[],ROUTE *route)
	   
	   

			Input: names of cities between which routes have to be deleted,route linked list.
	   
			Output: Deletes routes between the two given cities and overwrites the modified route linked list to routes.dat file. 


========================================================================== Task 4 ==============================================================================




## MODIFY  BY laisha##


Function Prototypes
------------------MODIFICATION CAN BE DONE BY ADMIN ONLY(PASSWORD iiits@123)-------------------

~

1).FUNCTION TO PROVIDE MENU FOR MODIFYING

void MODIFY(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)


INPUTS:
CHOICE
 	1)MODIFY ROUTE AND FLIGHT DETAILS
      
 	2)MODIFY AIRPORT DETAILS
OUTPUT:
	
	THE DETAILS OF THE CORRESPONDING FLIGHT AND THEIR ROUTE IS CHANGED 

2).calling FUNCTION TO MODIFY ROUTE AND AIRLINE DETAILS which calls 
	void Flight(ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)
 
	CALLS searchroute() function

 

3).FUNCTION TO MODIFY AIRPORT DETAILS

	void Airport(AIRPORTS *airports)

	INPUT:
NAME OF OLD AIRPORT
NAME OF NEW AIRPORT




4).FUNCTION FOR MODIFYING DATABASE
	void printfairports(AIRPORTS *air,ROUTE *route, AIRLINES *airlines,char *fnam,int f)
	
	CONTENT OF THE AIRPORT DATABASE IS UPDATED WITH NEW AIRPORT  NAME AND IATA CODE
	CONTENT OF THE OTHER TWO DATABASES ROUTES AND AIRLINES IS ALSO UPDATED DEPENDING ON THE VALUE OF THE 	FLAG VARIABLE
	
	flag variable   Database file name
	1               AIRPORTS FILE
	
	2	        AIRLINES FILE
	
	3		ROUTES DATABASE



5).FUNCTION TO DISPLAY THE ROUTES BETWEEN TWO CITIES FOR USER TO MODIFY THE REQUIRED DETAILS LIKE AIRLINE SOURCE AND DESTINATION
	
void searchroute(char *src, char *dest, ROUTE *route, AIRLINES *airlines, AIRPORTS *airports)

	>>WHAT IT DOES?

	SEARCHES THE SOURCE AND DESTINATION TO PRINT REQUIRED FLIGHTS IN AIRLINE AND ROUTES DATABASE

(by traversing the data structure and matching the given parameters.Using souce 	and destination from airports file the control reaches airlines and finds the airline with that id and overwrits the new updated content

6).FUNCTION TO MODIFY ROUTE AND FLIGHT DETAILS
	
int modify2(char *src, char *dest, AIRLINES *airlines, ROUTE *route, int source, int destination)

	INPUTS:
SOURCE AND DESTINATION FOR REQUIRED FLIGHTS
NEXT,
NEW SOURCE,DESTINATION,AIRLINE NAME

	OUTPUT:
MOFIED DETAILS ARE WRITTEN TO THE FILE AIRLINES AND ROUTES FILE AFTER MODIFICATION
7).FUNCTION TO FIND AIRLINE NAME CORRESPONDING TO THE AIRLINE ID
	

void findAirline(AIRLINES *airlines, int search)


	input: airline id and pointer to head

	output: matching case overwritten

