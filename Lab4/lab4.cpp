//lab 4  Farmer Joe triangular field

// Every place that C style comments  /*......*/ exist, you must write the code that
//completes that action. It may be one statement, it may be several

#define _USE_MATH_DEFINES  //note that this statement must come before #include lines
#include <iostream>
#include <cmath>
#include <cctype>

using namespace std;

int main( ) {
	double a, b, c;
	double A, B, C;
	double cosA, cosB;
    double area, s;
    double PI = M_PI;
	double seed = 0;


	//get input data
    cout << "Enter 3 sides in feet: ";
    cin >> a;
    cin >> b;
    cin >> c;

	/*prompt for three sides, read them in */

	cout << "How many pounds of seed: ";
	cin >> seed;

    //test if inputs make a valid triangle, if any two sides sum less than
    //or equal third side, it's not a triangle
    if(a + b < c || b + c < a || c + a < b) {
        cout << "This is not a valid triangle" << endl;
        return -1;
    }


    //calculate area with heron's method
    s = (a + b + c) / 2.0;
    area = sqrt(s *
               (s - a) *
               (s - b) *
               (s - c));


	//check if seed is enough, or way too much
    if(seed / area >= .002 && seed / area < .002 * (1.5)) {
        cout << "Farmer Joe has enough seed." << endl;
    } else if(seed / area < .002) {
        cout << "Farmer Joe doesn't have enough seed for " << area << " square feet" << endl;
        return -1;
    } else {
        cout << "Farmer Joe should look for a larger field." << endl;
    }


    //calculate angles, Law of Cosines
    cosA = (pow(b,2) + pow(c,2) - pow(a,2)) / (2 * b * c);
    A = acos(cosA);
    cosB = (pow(c,2) + pow(a,2) - pow(b,2)) / (2 * c * a);
    B = acos(cosB);
    C = 108 - (A + B);

    A *= (180 / PI);
    B *= (180 / PI);
    C *= (180 / PI);

	if(A < 30 || B < 30) {
		cout << "One corner is too tight for the tractor." << endl;
	}
	else {
		cout << "Farmer Joe better get busy planting." << endl;
	}


	return 0;
}
