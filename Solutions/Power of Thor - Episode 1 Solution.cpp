#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int lightX; // the X position of the light of power
    int lightY; // the Y position of the light of power
    int initialTX; // Thor's starting X position
    int initialTY; // Thor's starting Y position
    cin >> lightX >> lightY >> initialTX >> initialTY; cin.ignore();
    
    int currentTX=initialTX;
    int currentTY=initialTY;
    string dir="";

    while (1)
    {
        int remainingTurns;
        cin >> remainingTurns;
        cin.ignore();
        
        //checking all the possible orientations      
        if (lightY - currentTY > 0)
        {
            dir += "S";
            currentTY += 1;
        }        
        else if (lightY - currentTY < 0)
        {
            dir+= "N";
            currentTY -= 1;
        }

        if (lightX - currentTX > 0)
        {
            dir += "E";
            currentTX += 1;
        } 
        else if (lightX - currentTX < 0)
        {
            dir += "W";
            currentTX -= 1;
        }
        
        cout << dir << endl;
        dir="";
    }
}
