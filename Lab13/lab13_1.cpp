/*-------------------------------------------------------------------
  Program: lab13_1.cpp
  Author: Michael Pfeifer
  Course: CSC 150 - Section M000
  Instructor: A Instructor
  Date: 12/07/2010
  Description:
    Reads a file containing student identifiers and runtimes for a program.
    Stores the data to a 2D array. Allows user to look up individual student
    results.


---------------------------------------------------------------------
  Includes
---------------------------------------------------------------------*/
#include <iostream>
#include <fstream>
using namespace std;


//-------------------------------------------------------------------
// Function Prototypes
//-------------------------------------------------------------------

int search(int arr[300][2], int size, int key);

/********************************************************************
   Function:      main
   Description:   Program entry/exit point, reads data file, prompts for inputs, 
                  displays results
   Parameters:    none
   Returns:       0
*********************************************************************/
int main()
{
    int student;   // input ID
    int index;
    int run_data[300][2] = { 0 };
    int num = 0;  //number of students read

    bool done = false;  //flag to end main loop

    ifstream fin;

    fin.open( "runtimes.txt" );
    if( !fin )
    {
        cout << "Error opening data file. Exiting." << endl;
        return -1 ;
    }

    while( num < 300 && fin >> run_data[num][0] )
    {
        fin >> run_data[num][1];
        num++;
    }

    fin.close( );

    cout << "Enter student ID: ";

    while ( !done && cin >> student )
    {
        //  Test for end of the program
        if (student == 0)
        {
            cout << "End of Program!" << endl;
            done = true;
        }

        else
        {

        // Call search function to find student index
        index = search(run_data, num, student);

        // Display error if not found, otherwise ID and runtime
        if (index == -1)
            cout << "Student not found!" << endl;
        else
            cout << "Student: " << student << " had runtime of: "
                 << run_data[index][1] << " seconds" << endl;

        // prompt for another student
       cout << "Enter student ID: ";
        }

    }

    return 0;
}


/********************************************************************
  Function: search
  Author: MCS/SDSM&T
  Description:
    This function searches a 2-D array for match in the
    first column, returning the index if found or -1 if not.
  Parameters:



  Returns
 ********************************************************************/

int search(int arr[300][2], int size, int key) {
    for(int i = 0; i < size; i++) {
        if(arr[i][0] == key) {
            return i;
        }
    }
    return -1;
}
