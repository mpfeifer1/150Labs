#include <iostream>

using namespace std;

void convertAngle();
void multTable();
void fibonacci();

int main() {
    bool quit = false;
    char choice;

    do {
        cout << "Looping Exercise" << endl;
        cout << "C - convert angle" << endl;
        cout << "M - multiplication table" << endl;
        cout << "F - fibonacci numbers" << endl;
        cout << "Q - quit" << endl;

        cout << "Choice: ";
        cin >> choice;

        cout << endl;

        switch(choice) {
            case 'C':
            case 'c':
                convertAngle();
                break;
            case 'M':
            case 'm':
                multTable();
                break;
            case 'F':
            case 'f':
                fibonacci();
                break;
            case 'Q':
            case 'q':
                cout << "Goodbye" << endl;
                quit = true;
                break;
            default:
                cout << "Invalid choice, try again" << endl;
        }

    cout << endl;

    } while(!quit);

}

void convertAngle() {
    double angle = 0;

    do {
        cout << "Enter an angle: ";
        cin >> angle;
    } while(angle > 5467.83 || angle < -243.9);

    cout << "Input is " << angle << endl;

    while(angle > 360) {
        angle -= 360;
    }

    while (angle < 0) {
        angle += 360;
    }

    cout << "Converted to " << angle << endl;
}

void multTable() {
    for(int i = 1; i <= 12; i++) {
        for(int j = 1; j <= 12; j++) {
            int number = i * j;

            cout << " ";
            if(number < 100) { // Outputs extra space so formatting is nice
                cout << " ";
                if(number < 10) {
                    cout << " ";
                }
            }

            cout << number;

        }
        cout << endl;
    }
}

void fibonacci() {
    int index = 0;
    cout << "Chose fibonacci number to find ";
    cin >> index;

    int a = 0;
    int b = 1;

    cout << "0 1 ";
    for(int i = 0; i < index; i++) { // Starts at two because first two already done
        a += b;
        swap(a,b);
        cout << b << " ";
    }
    cout << endl;
}
