#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;


int main()
{
    int nbFloors; // number of floors
    int width; // width of the area    
    int nbRounds; // maximum number of rounds
    int exitFloor; // floor on which the exit is found
    int exitPos; // position of the exit on its floor
    int nbTotalClones; // number of generated clones
    int nbAdditionalElevators; // ignore (always zero)
    int nbElevators; // number of elevators
    cin >> nbFloors >> width >> nbRounds >> exitFloor >> exitPos >> nbTotalClones >> nbAdditionalElevators >> nbElevators; cin.ignore();
    
    int positionelevator[nbElevators+1];//saving the positions of the elevator
    
    for (int i = 0; i < nbElevators; i++)
    {
        int elevatorFloor; // floor on which this elevator is found
        int elevatorPos; // position of the elevator on its floor
        cin >> elevatorFloor >> elevatorPos; cin.ignore();
        positionelevator[elevatorFloor]=elevatorPos;
    }
    positionelevator[nbElevators]=exitPos;//saving the position of the exit with the elevators
    
    while (1) {
        int cloneFloor;
        int clonePos;
        string direction;
        cin >> cloneFloor >> clonePos >> direction; cin.ignore();
        
        if(clonePos == width-1 || clonePos == 0)//if clone is at boundaries
        {            
              cout << "BLOCK" << endl;
        }
        else if((positionelevator[cloneFloor] < positionelevator[cloneFloor-1] && direction == "LEFT")||(positionelevator[cloneFloor] > positionelevator[cloneFloor-1] && direction == "RIGHT"))//if elevator+1 is in the same direction of the elevator
        {
                cout << "WAIT" << endl;
        }
        else if(clonePos == positionelevator[cloneFloor-1])//if clone == elevatorposition block
        {
            cout << "BLOCK" << endl;
            positionelevator[cloneFloor-1]=-10;
        }
        else
        {
            cout << "WAIT" << endl;    
        }
    }
}
