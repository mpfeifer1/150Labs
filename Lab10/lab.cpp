//  CSC 150  Lab 10  USPS address formatter


#define _CRT_SECURE_NO_DEPRECATE
#define _CRT_NONSTDC_NO_DEPRECATE

#include <iostream>
#include <cstring>
#include <cctype>
#include <string.h>
using namespace std;

void split_addr(char address[], char temp_addr[][50]);
void display_addr(char temp_addr[][50]);
void abbrev_street(char word[]);
char *strrev(char *str);

/* *****   DO NOT MAKE ANY CHANGES TO main( )   *****  */
int main()
{
	char addresses[5][100] = {
		"Ed Begely,123 Main Street,Riley,CO,59999",
		"Sally Struthers,2345 East Moon Lane,Hollywierd,CA,92111",
		"Billy Gates,1 Rich Place,Medina,WA,98000",
		"Big Bad Wolf,99 Forest Drive,Big Redwoods,OR,97654",
		"Joe Piggy,43 Straw Circle,Big Redwoods,OR,97800" };

	char temp_addr[5][50] = {""};
	int i;

	for( i = 0; i < 5; i++ )
	{
		split_addr( addresses[i], temp_addr );
		display_addr( temp_addr );
		cout << endl;
	}

    return 0;
}


/* *****   complete the following function, write the other two   *****  */

//converts a street address to have the correct abbreviation
void abbrev_street(char word[])
{
	char words[12][10] = { "BOULEVARD", "CENTER", "CIRCLE", "COURT", "DRIVE", "LANE", "PLACE", "ROAD", "SQUARE", "STREET", "TERRACE", "TRAIL" };
	char abbrevs[12][6] = { "BLVD", "CTR", "CIR", "CT", "DR", "LN", "PL", "RD", "SQ", "ST", "TER", "TRL" };
    int word_index = -1;
    bool found = false;

    strrev(word);

    for(int i = 0; i < 12; i++) {
        strrev(words[i]);
        if(strncmp(word, words[i], strlen(words[i])) == 0) {
            word_index = i;
        }
        strrev(words[i]);
    }

    strrev(word);
    word[strlen(word) - strlen(words[word_index])] = '\0';
    strcat(word, abbrevs[word_index]);
}

void split_addr(char address[], char temp_addr[][50]) {
    int row = 0;
    int column = 0;
    int position = 0;

    for(position = 0; position < strlen(address); position++) {
        address[position] = toupper(address[position]);
        if(address[position] == ',') {
            temp_addr[row][column] = '\0';
            row++;
            column = 0;
            position++;
        }
        temp_addr[row][column] = address[position];
        column++;
    }
    abbrev_street(temp_addr[1]);
}

void display_addr(char temp_addr[][50]) {
    cout << temp_addr[0] << endl;
    cout << temp_addr[1] << endl;
    cout << temp_addr[2] << " " << temp_addr[3] << " " << temp_addr[4] << endl;
}

char *strrev(char *str)
{
      char *p1, *p2;

      if (! str || ! *str)
            return str;
      for (p1 = str, p2 = str + strlen(str) - 1; p2 > p1; ++p1, --p2)
      {
            *p1 ^= *p2;
            *p2 ^= *p1;
            *p1 ^= *p2;
      }
      return str;
}
