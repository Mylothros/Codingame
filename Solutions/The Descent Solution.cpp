#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{

    // game loop
    while (1) {
       int max=0;
       int highest;
        for (int i = 0; i < 8; i++) {
            int mountainH; // represents the height of one mountain.
            cin >> mountainH; cin.ignore();
            if(mountainH > max)//checking if the mountain is> than the max value
            {
                max=mountainH;
                highest=i;//setting the position of the highest mountain
            }
        }
        cout << highest << endl;
    }
}
