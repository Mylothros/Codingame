#include <iostream>

using namespace std;

int main()
{
    int speed, lightCount, counter = 1;
    cin >> speed >> lightCount;
    
    float dis[lightCount], dur[lightCount], k, begin = speed, test = 0;
    bool b = true;
    
    for (int i = 0; i < lightCount; i++) 
    {
        int distance, duration;
        cin >> distance >> duration; cin.ignore();

        dis[i] = distance;//saving distance in array
        dur[i] = duration;//saving duration in array
    }

    for (int i = 0; i < lightCount; i++) 
    {
        while(1)
        {
            test+= (dur[i] * (speed * 1000)) / 3600;//finding how far the car can go with the current speed
            counter++;//a counter to know when the light is green or not
            
            if(test > dis[i] + 1)//if the travel is more than the distance + 1 line 31
            {
                if(counter % 2 != 0)//check if the current light is green or not if it is not then take the initial speed--
                {                    
                    speed = begin - 1;
                    begin = speed;
                    i = -1;                  
                }
                break;
            }           
        }
        counter = 1;
        test = 0;
    }
    
    cout << speed;
}