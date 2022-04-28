/*	Bus Reservation System
	Jordan Fokui
	Project from: Learnprogramo
*/

#include <conio.h>
#include <cstdio>
#include <iostream>
#include <string.h>
#include <cstdlib>

using namespace std;

// track the instancied class Bus 
static int p = 0;

// Class Bus

class Bus_class {
	// Members are private by default
	char bus_nummer[5], driver_name[10];
	char t_arrival[5], t_depart[5]; // In format 15h00 (24h)
	char from[10], destination[10];
	char seat[8][4][10];

public:
	void install();
	void allotment();
	void empty();
	void show();
	void available();
	void position(int i);

}
Bus[10];


// Function of Bus Class
void Bus_class::install() {
	// Enter all the bus informations
	// To do: add management right later for differents user

	cout << "Enter bus no: ";
	cin >> Bus[p].bus_nummer;

	cout << "\nEnter the driver's name: ";
	cin >> Bus[p].driver_name;

	cout << "\nEnter the Arrival time: ";
	cin >> Bus[p].t_arrival;

	cout << "\nEnter the departure: ";
	cin >> Bus[p].t_depart;

	cout << "\nDrive from: \t\t\t";
	cin >> Bus[p].from;

	cout << "\nDrive to: \t\t\t";
	cin >> Bus[p].destination;

	Bus[p].empty();
	p++;

}

// Functions to design
// draw a line
void vline(char ch) {
	for (int i = 80; i > 0; i--) cout << ch;
}

// Allotment 

void Bus_class::allotment() {
	int seat;
	char number[5];

top:
	cout << "Bus no: ";
	cin >> number;

	int n;

	// search between the instancied object of bus class
	for (n = 0; n <= p; n++) {
		// check if the bus nummer exits
		if (strcmp(Bus[n].bus_nummer, number) == 0)
			break;
	}


	while (n <= p) {
		cout << "\nSeat Number: ";
		cin >> seat;

		if (seat > 32) {
			cout << "\nThere are only 32 seats available in this bus.";
		}
		else {
			if (strcmp(Bus[n].seat[seat / 4][(seat % 4) - 1], "Empty") == 0) {
				cout << "Enter passanger's name: ";
				cin >> Bus[n].seat[seat / 4][(seat % 4) - 1];
				break;
			}
			else cout << "The seat no. is already reserved.\n";
		}
	}

	if (n > p) {
		cout << "Enter correct bus no.\n";
		goto top;
	}
}


// This function fill the name with empty

void Bus_class::empty() {

	// We have 4 colonnes
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 4; j++) {
			strcpy_s(Bus[p].seat[i][j], "Empty");
		}
	}
}


// This function display the informations

void Bus_class::show() {
	int n;
	char number[5];
	cout << "Enter the bus no: ";
	cin >> number;

	for (n = 0; n <= p; n++) {
		if (strcmp(Bus[n].bus_nummer, number) == 0)
			break;
	}

	while (n <= p) {
		vline('*');
		cout << "\nBus mo: \t" << Bus[n].bus_nummer
			<< "\nDriver: \t" << "\tDeparture time: " << Bus[n].t_depart
			<< "\nFrom: \t\t" << Bus[n].from << "\t\tTo: \t\t"
			<< Bus[n].destination << "\n";

		vline('*');
		Bus[0].position(n);

		int a = 1;

		for (int i = 0; i < 8; i++) {
			for (int j = 0; j < 4; j++) {
				a++;		// variable to count the seat 1 -> 32
				if (strcmp(Bus[n].seat[i][j], "Empty") != 0)
					cout << "\nThe seat no " << (a - 1) << " is reserved for: "
					<< Bus[n].seat[i][j] << ".";
			}
		}
		break;
	}
	if (n > p)
		cout << "Enter correct bus no: ";
}


// This function ....
void Bus_class::position(int l) {
	
	int seat_index{ 0 }, empty_seat{ 0 };

	for (int i = 0; i < 8; i++) {
		cout << "\n";
		for (int j = 0; j < 4; j++) {
			seat_index++; // // variable to count the seat 1 -> 32
			if (strcmp(Bus[l].seat[i][j], "Empty") == 0) {
				cout.width(5);
				cout.fill(' ');
				cout << seat_index << ".";
				cout.width(10);
				cout.fill(' ');
				cout << Bus[l].seat[i][j];
				empty_seat++;
			}
			else {
				cout.width(5);
				cout.fill(' ');
				cout << seat_index << ".";
				cout.width(10);
				cout.fill(' ');
				cout << Bus[l].seat[i][j];
			}
		}
	}
	cout << "\n\nThere are " << empty_seat << " empty seats in bus no: " << Bus[l].bus_nummer;

}


// This function ....
void Bus_class::available() {

	for (int n = 0; n < p; n++) {
		vline('*');
		cout << "Bus no: \t" << Bus[n].bus_nummer << "\nDriver: \t" << Bus[n].driver_name
			<< "\t\tArrival time: \t" << Bus[n].t_arrival << "\tDeparture Time: \t"
			<< Bus[n].t_depart << "\nFrom: \t\t" << Bus[n].from << "\t\tTo: \t\t\t"
			<< Bus[n].destination << "\n";

		vline('*');
		vline('_');
	}
}


// Main function

int main()
{
	/* Clearing the Screen: system("CLS"); When the screen is cleared in Visual C++, 
	the cursor is moved to the upper left corner of the screen.
	*/
	system("cls");

	int w;
	while (1) {
		cout << "\n\n\n\n\n";
		cout << "\t\t\t1.Install \n";
		cout << "\t\t\t2. Reservation \n";
		cout << "\t\t\t3. Show \n";
		cout << "\t\t\t4. Buses Available \n";
		cout << "\t\t\t5. Exit \n";
		cout << "\t\t\tEnter your choices: ->";
		cin >> w;

		switch (w) {
			case 1:
				Bus[p].install();
				break;
			case 2:
				Bus[p].allotment();
				break;
			case 3:
				Bus[p].show();
				break;
			case 4:
				Bus[p].available();
				break;
			case 5:
				exit(0);

		}
	}
	return 0;
}