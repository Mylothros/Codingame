#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;


int main()
{
    int y; // columns
    int x; // rows
    cin >> x >> y; cin.ignore();//changed the x with y so it wont be confusing
    int N; // maximum number of turns before game over.
    cin >> N; cin.ignore();
    cerr <<N<<endl;
    int x0;
    int y0;
    cin >> x0 >> y0; cin.ignore();
    
    int Xa=0,Ya=0;

    while (1) 
    {
        string direction; // the direction of the bombs from batman's current location (U, UR, R, DR, D, DL, L or UL)
        cin >> direction; cin.ignore();
        
        if(direction.find('R') != string::npos)
        {
            Xa=x0;//holds the left boundary
            x0 += (x-x0)/2.0;            
        }        
        else if(direction.find('L') != string::npos)
        {
            x=x0;//holds the right boundary
            x0 -= (x0-Xa)/2.0;
        }        
        if(direction.find('U') != string::npos)
        {
            y=y0;//holds the bottom boundary
            y0 -= (y0-Ya)/2.0;
        }        
        else if(direction.find('D') != string::npos)
        {
            Ya=y0;////holds the top boundary
            y0 += (y-y0)/2.0;
        }        
        cout << x0 <<" "<< y0 << endl;      
    }   
}
