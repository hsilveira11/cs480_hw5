#include <iostream>
#include <vector>
#include "Movie.hpp"
#include "Customer.hpp"


std::vector<Movie>allMovies;

Movie movieFinder(int c)
{
	int size=allMovies.size();
	for (int i=0; i<size; i++)
	{
		if(allMovies[i].code==c)
		{
			return allMovies[i];
		}
	}
}

Customer noCus("NotFound"," "," ",0); //"not-found" customer

std::vector<Customer>allCusts;

Customer* custFinder(std::string s)
{
	int size=allCusts.size();
	for (int i=0; i<size; i++)
	{
		if(allCusts[i].phoneNum==s)
		{
			return &allCusts[i];
		}
		else
		{
			return(&noCus);
		}
	}
}

struct rental
{
	int r_code;
	int r_days;
};


int main (void)
{


	//entering some movie entries
	Movie m1(1, "Elf", children);
	Movie m2(2, "Avengers", newRelease);
	Movie m3(3, "Harry Potter", regular);
	Movie m4(4, "Batman", regular);

	allMovies.push_back(m1);
	allMovies.push_back(m2);
	allMovies.push_back(m3);
	allMovies.push_back(m4);

	//entering some customer entries
	Customer c1("Heather","Ann","3162223333",10);
	Customer c2("Brandon","Smith","3161234567",5);
	Customer c3("Troy","Michaels","3169998888",15);
	Customer c4("Lukas","Addison","3169876543",12);

	allCusts.push_back(c1);
	allCusts.push_back(c2);
	allCusts.push_back(c3);
	allCusts.push_back(c4);

	//----------------------------------------------------

	char startOver ='s';
	while (startOver=='s')
	{


	std::cout<<"MOVIES:\n";

	//Print available movies:
	int s=allMovies.size();
	for (int i=0; i<s; i++)
	{
		std::cout<< "\n(" << allMovies[i].code << ") " << allMovies[i].title;
	}
	std::cout<<"\n--------------------------------------------------------------------------";

	std::vector<rental>toRent; //vector holds rentals of user

	int code=0;
	int days=0;
	char keepRenting = 'R';
	rental r;

	while (keepRenting=='R')
	{
		while (code<1 || code>s)
		{
			std::cout<<"\n\nPlease type the code of the movie you want to rent: ";
			std::cin>>code;
		}
		std::cout<<"How many days would you like to rent this movie for? ";
		std::cin>>days;

		r.r_code=code;
		r.r_days=days;
		toRent.push_back(r);

		std::cout<<"Type R to keep renting, or type anything else to finish. ";
		std::cin>>keepRenting;

		code=0; //reset movie code
	}


	int costPerDay=1;
	int totalCost=0;
	int runningTotal=0;

	std::cout<<"\n--------------------------------------------------------------------------";
	std::cout<<"\nSTATEMENT:";
	int numRentals = toRent.size();
	for (int i=0;i<numRentals;i++)
	{
		int z= toRent[i].r_code;
		Movie m = movieFinder(z);
		std::cout<<"\nTitle: "<<m.title;
		std::cout<<"\nDays rented: " << toRent[i].r_days;

		if(m.type==newRelease)
		{
			costPerDay=2; //new releases cost $2, else costs $1
		}
		std::cout<<"\nCost per day: $"<<costPerDay;
		totalCost = costPerDay*toRent[i].r_days;
		std::cout<<"\nTotal cost for this movie: $"<<totalCost<<"\n\n";

		runningTotal = runningTotal + totalCost;
		//reset
		costPerDay=1; totalCost=0;
	}
	std::cout<<"TOTAL COST for all rentals: $" << runningTotal;

	std::string input;
	std::cout<<"\nPlease enter your phone number (10 digit, no dashes or spaces): \n";
	std::cin>> input;
	Customer* c = custFinder(input);
	{
		if(c->fName=="NotFound")
		{
			std::cout<<"Sorry, you are not in the system. A new account is being created for you.\n\n";
			std::string newFName;
			std::string newLName;
			std::string phone = input;

			std::cout<<"\nEnter your first name: ";
			std::cin>>newFName;
			std::cout<<"\nEnter your last name: ";
			std::cin>>newLName;

			Customer newCus(newFName, newLName, phone, runningTotal);
			allCusts.push_back(newCus);
			std::cout<<"\nYour new account has been made. You received "<<runningTotal<<" points from today's rentals";

		}
		else
		{
			std::cout<<"\nHello "<<c->fName<<" "<<c->lName<<"!\n";
			std::cout<<"Points before: "<<c->points;
			c->points = c->points + runningTotal;
			std::cout<<"\nPoints after: "<<c->points;
		}
	}

	std::cout<<"\nThank you! Goodbye!";


	std::cout<<"\n\n\nTo use the rental service again, type s. \nOtherwise, type anything else to exit.";
	std::cin>>startOver;
}

	return(0);
}
