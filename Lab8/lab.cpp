#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

int getData(int data[], int size);
void analyze(int data[] , int filled, int count[]);
void display(int count[], int size);

int main() {
    srand(100); // Seeds generator

    const int size = 4000;
    int heights[size] = {0};
    int counts[10] = {0};
    int numToFill = 0;

    do {
        cout << "Enter the number of elements to fill: ";
        cin >> numToFill;
    } while(numToFill <= 0 || numToFill >= size);

    getData(heights, numToFill);
    analyze(heights, numToFill, counts);
    display(counts, numToFill);
}

int getData(int data[], int size) {
    int i;
    for(i = 0; i < size; i++) {
        data[i] = rand() % 40 + 44;
    }
    return i;
}

void analyze(int data[], int filled, int count[]) {
    for(int i = 0; i < filled; i++) {
        if(data[i] <= 48) {
            count[0]++;
        } else if(data[i] <= 52) {
            count[1]++;
        } else if(data[i] <= 56) {
            count[2]++;
        } else if(data[i] <= 60) {
            count[3]++;
        } else if(data[i] <= 64) {
            count[4]++;
        } else if(data[i] <= 68) {
            count[5]++;
        } else if(data[i] <= 72) {
            count[6]++;
        } else if(data[i] <= 76) {
            count[7]++;
        } else if(data[i] <= 80) {
            count[8]++;
        } else {
            count[9]++;
        }
    }
}

void display(int count[], int size) {
    cout << "Upper Limit    Number" << endl;
    cout << "<=48           " << count[0] << endl;
    cout << "52             " << count[1] << endl;
    cout << "56             " << count[2] << endl;
    cout << "60             " << count[3] << endl;
    cout << "64             " << count[4] << endl;
    cout << "68             " << count[5] << endl;
    cout << "72             " << count[6] << endl;
    cout << "76             " << count[7] << endl;
    cout << "80             " << count[8] << endl;
    cout << ">80            " << count[9] << endl;
}
