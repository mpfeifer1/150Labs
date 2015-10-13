//lab 7 - Measurment Conversions with Functions

#include <iostream>
#include <iomanip>
#include <cctype>
using namespace std;

const double MTH_TO_HRS = 30.4368 * 24;
const double OZ_TO_LBS = 0.0625;
const double LBS_TO_KG = 0.4536;

void displayMenu();
void convertHours(int hours);
void ozToLbAndKg(int ounces);
void celToFar(int cel);

int main()
{
	int hours = 0.0;
	int ounces = 0;
	int celsius = 0.0;
	char choice = ' ';

	//set output formatting
	cout << setprecision(4);
	cout << fixed;
	cout << showpoint;

	do
	{
        displayMenu();

		cin >> choice;
		choice = toupper(choice);


		switch (choice)
		{
		case 'H':
			//get hours input
			cout << "Hours: ";
			cin >> hours;
			convertHours(hours);
			break;

		case 'O':
			//get input ounces
			cout << "Ounces: ";
			cin >> ounces;
            ozToLbAndKg(ounces);
			break;

		case 'C':
			cout << "Celsius to Fahrenheit" << endl;
			cout << "Celsius temperature: ";
			//get Celsius input
			cin >> celsius;
            celToFar(celsius);
			break;

		case 'Q':
			cout << "Program ending. Goodbye." << endl << endl;

			break;

		default:
			cout << "Invalid selection, try again." << endl << endl;

		}

	} while (choice != 'Q');

	return 0;
}

void displayMenu() {
    cout << "Measurement Conversions" << endl << endl;
    cout << "H - Hours to Years, Months and Days" << endl;
    cout << "O - Ounces to Pounds and Kilograms" << endl;
    cout << "C - Celsius to Fahrenheit" << endl;
    cout << "Q - Quit" << endl;

    cout << "Your choice: ";

}
void convertHours(int hours) {
    int years = 0;
    int months = 0;
    double days = 0;

    //convert hours to years, months, days
    //hours = years * YRS_TO_HRS + months * MTH_TO_HRS + days * 24;
    months = int(hours / MTH_TO_HRS);
    days = (hours - (MTH_TO_HRS * months)) / 24;
    years = months / 12;
    months = months - (years * 12);
   //display resulting hours
   cout << hours << " hours is: " << years << " years, " << months << " months, " << days << " days" << endl << endl;
}

void ozToLbAndKg(int ounces) {
    double pounds = 0.0;
    double kilos = 0.0;

    //convert to pounds and liograms
    pounds = ounces * OZ_TO_LBS;
    kilos = pounds * LBS_TO_KG;
    //display resulting pounds and kilos
    cout << ounces << " ounces = " << pounds << " pounds" << endl;
    cout << ounces << " ounces = " << kilos << " kilograms" << endl
         << endl;
}

void celToFar(int cel) {
    double fahrenheit = 0;

    //convert to celsius
    fahrenheit = cel * (9.0 / 5.0) + 32;
    //display resulting celsius
    cout << cel << " Celsius = " << fahrenheit << " Fahrenheit"
         << endl << endl;

}

