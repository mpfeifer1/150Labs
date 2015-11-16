//Read text from file multiple times, writing to output
//file of same name with "_out" appended to name

#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <stdio.h>
#include <assert.h>
#include <ctype.h>

#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

long long int atoi(const char *c);

int main( int argc, char * argv[] )
{
    ifstream fin;
    ofstream fout;
    char input[256] = "";
    char outname[256] = "";
    int num = 0;
    int i;

    //check for correct program usage
    if( argc < 3 )
    {
        cout << "Incorrect usage:  prog.exe filenname number" << endl;
        cout << "Exiting now, please try again." << endl;
        return -1;
    }

    //open and check input file
    fin.open( argv[1] );
    if( !fin )
    {
        cout << "Error opening file \"" << argv[1] << "\", exiting." << endl;
        return -1;
    }

    //converts the string holding a number to numeric value
    num = atoi( argv[2] );

    //make output file name, insert "_out" before extension
    strncpy( outname, argv[1], strlen( argv[1]) - 4 );
    strcat( outname, "_out.txt" );

    for( i = 0; i < num; i++ )
    {   
        fout.open( outname, ios::app );
        if( !fout )
        {
            cout << "Error opening file \"" << outname << "\", exiting." << endl;
            fin.close( );
            return -1;
        }

        //read input file, copy to output file
        while ( fin.getline( input, 256) )
            fout << input << endl;

        //close and reset output file variable
        fout.close( );
        fout.clear( );

        //clear eof and reset input file to beginning 
        fin.clear( );   
        fin.seekg( 0 );
    }

    fin.close( );
    
    return 0;
}

long long int atoi(const char *c)
{
    long long int value = 0;
    int sign = 1;
    if( *c == '+' || *c == '-' )
    {
        if( *c == '-' ) sign = -1;
        c++;
    }
    while (isdigit(*c))
    {
        value *= 10;
        value += (int) (*c-'0');
        c++;
    }
    return (value * sign);
}
