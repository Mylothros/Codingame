#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int w;
    int h;
    int countX;
    int countY;    
    cin >> w >> h >> countX >> countY; cin.ignore();
    
    int countsx[countX+1], countsy[countY+1], allcounts=0;//creating 2 arrays for w and h respectively

    for(int i = 0; i < countX; i++)
    {
        int x;
        cin >> x; cin.ignore();    
        countsx[i] = x;
    }
    
    countsx[countX] = w;//saving the last element ehich is the width
    
    for(int i = 0; i < countY; i++)
    {
        int y;
        cin >> y; cin.ignore();
        countsy[i] = y; 
    }  
    
    countsy[countY] = h;//saving the last element ehich is the height
    
    int z = (((countX+2)*(countX+2))-(countX+2))/2;//all the possible differences of the width
    int x = (((countY+2)*(countY+2))-(countY+2))/2;//all the possible differences of the height
    int a[z], b[x];
    int counter = countX+1,q=0;
    //saving all the differences in a
    for(int i = 0; i <= countX; i++)
    {
        a[i] = countsx[i];        
        for(int j = i+1; j <= countX; j++)
        {
            a[counter] = countsx[j]-countsx[i];
            counter++;
        }
    }
    
    counter = countY+1;
    //saving all the differences in b
    for(int i = 0; i <= countY; i++)
    {
        b[i] = countsy[i];     
        for(int j = i+1; j <= countY; j++)
        {
            b[counter] = countsy[j]-countsy[i];
            counter++;
        }
    }
    
    sort(a,a+z);
    
    for(int i = 0; i < z; i++)
    {
        if(i != 0 && a[i] == a[i-1])//optimizing the solution. After the first for if the next value is the same increment allcounts by q -> line 78
        {
            allcounts = allcounts+q; 
        }
        else
        {
            q=0;
            for(int j = 0; j < x; j++)
            {
                if(a[i] == b[j])
                {
                    q++;//saving the increments for line 67
                    allcounts++;    
                }
            }
        }
    }
    
    cout<< allcounts << endl;
}
