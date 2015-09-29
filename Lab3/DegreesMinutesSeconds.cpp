#include <iostream>

using namespace std;

int main() {
	int degreesOne = 0;
	int degreesTwo = 0;
	int minutesOne = 0;
	int minutesTwo = 0;
	int secondsOne = 0;
	int secondsTwo = 0;

	int degrees = 0;
	int minutes = 0;
	int seconds = 0;

	cout << "Enter Angle One:" << endl;
	cin >> degreesOne >> minutesOne >> secondsOne;
	cout << "Enter Angle Two:" << endl;
	cin >> degreesTwo >> minutesTwo >> secondsTwo;

	degrees = degreesOne + degreesTwo;
	minutes = minutesOne + minutesTwo;
	seconds = secondsOne + secondsTwo;

	if(seconds >= 60) {
		minutes += int(seconds / 60);
		seconds %= 60;
	}

	if(minutes >= 60) {
		degrees += int(minutes / 60);
		minutes %= 60;
	}

	cout << degrees << char(248) << minutes << "\'" << seconds << "\"" << endl;
}