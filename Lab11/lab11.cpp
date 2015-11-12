/*--------------------------------------------------------------------
  Program: lab11.cpp

    This program reads data into a 2-D array named cadmium with daily
    readings of airborne cadmium in a room of a house every six
    hours (6am, noon, 6pm, and midnight) for seven consecutive
    days.  Then, it computes the highest cadmium reading per day and
	the highest reading in the week. In the case of two readings with
    the same highest reading, it chooses the first occurrence.
	Writes a summary of each day's high reading and time, as well as
	the weekly high (day, reading, time).

---------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;


//-------------------------------------------------------------------
// Global constants
//------------------------------------------------------------------
const int  NUM_DAYS         = 7;
const int  NUM_READINGS     = 4;
const char DAY_NAMES[7][10] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
const char TIMES[4][10]     = { "12am", "6am", "12pm", "6pm" };


//-------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------
int high_reading(double day[4]);
bool read_data(ifstream& fin, double readings[7][4]);
void write_summary(int heights[7], double readings[7][4]);
void highestReading(int& i, int& j, double readings[7][4]);

int main( )
{
    double readings[7][4];
    int heights[7]; // contains indexes ofdaily heights
    ifstream fin;
    fin.open("readings.txt");
    if(!fin) {
        cout << "Idiot. This program needs a file." << endl;
        return -1;
    }

    read_data(fin, readings);
    for(int i = 0; i < 7; i++) {
        heights[i] = high_reading(readings[i]);
    }

    write_summary(heights, readings);

   return 0;
}

bool read_data(ifstream& fin, double readings[7][4]) {
    int i = 0, j = 0;
    for(i = 0; i < 7; i++) {
        for(j = 0; j < 4; j++) {
            fin >> readings[i][j];
        }
    }
    return true;
}

int high_reading(double day[4]) {
    double max = 0;
    int index = 0;
    for(int i = 0; i < 4; i++) {
        if(day[i] > max) {
            index = i;
            max = day[i];
        }
    }
    return index;
}

void highestReading(int& i, int& j, double readings[7][4]) {
    double max = 0;
    int indexI = 0, indexJ = 0;
    for(i = 0; i < 7; i++) {
        for(j = 0; j < 4; j++) {
            if(readings[i][j] > max) {
                indexI = i;
                indexJ = j;
                max = readings[i][j];
            }
        }
    }
    i = indexI;
    j = indexJ;
}

void write_summary(int heights[7], double readings[7][4]) {
    ofstream fout;
    fout.open("summary.txt");
    if(!fout) {
        cout << "What are you even doing? You can't even make a file?!" << endl;
    }
    for(int i = 0; i < 7; i++) {
        fout << "Highest cadmium reading on " << DAY_NAMES[i] << " was " << readings[i][heights[i]] << " at " << TIMES[heights[i]] << endl;
    }

    fout << endl;

    int i = 0, j = 0;
    highestReading(i, j, readings);
    fout << "The overall highest reading was on " << DAY_NAMES[i] << " at " << TIMES[j] << endl;
}
