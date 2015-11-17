#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;

int main(int argc, char* argv[]) {
    ifstream first;
    ifstream last;
    ofstream output;

    if(argc != 4 && argc != 5) {
        cout << "Wrong number of args" << endl;
        return 1;
    }

    char firstname[20] = "";
    char lastname[20] = "";

    first.open(argv[1]);
    if(!first) {
        cout << "Input file didn't open" << endl;
        return 1;
    }
    last.open(argv[2]);
    if(!last) {
        cout << "Output file didn't open" << endl;
        return 1;
    }

    output.open(argv[3]);

    if(argc == 5 && (strcmp(argv[4], "/r") == 0 || strcmp(argv[4], "/R") == 0)) {
        while(first >> firstname) {
            last >> lastname;
            output << lastname << ", " << firstname << endl;;
        }
    } else {
        while(first >> firstname) {
            last >> lastname;
            output << firstname << " " << lastname << endl;
        }

    }
}
