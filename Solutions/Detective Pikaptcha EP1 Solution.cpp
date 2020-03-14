#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width;
    int height;    
    int counter=0;
    cin >> width >> height; cin.ignore();    
    char A[height][width];
    
    for (int i = 0; i < height; i++)
    {
        string line;
        cin >> line; cin.ignore();
    
        for(int j = 0; j < line.size(); j++)
        {
            A[counter][j] = line[j];

        }       
        counter++;
    }
    for (int i = 0; i < height; i++) 
    {   
        for(int j = 0; j < width; j++)
        {
            if(A[i][j] != '#')
            {
                if(j < width-1)//check if it is between 0 to width-1 in x axis
                {
                    if(A[i][j+1] != '#')
                    {
                        A[i][j+1] = A[i][j+1] + 1;
                    }
                }
                
                if(j > 0)//check if it is between 1 to width in x axis
                {
                    if(A[i][j-1] != '#')
                    {
                        A[i][j-1] = A[i][j-1] + 1;
                    }
                }
                
                if(i < height-1)//check if it is between 0 to height-1 in y axis
                {
                    if(A[i+1][j] != '#')
                    {
                        A[i+1][j] = A[i+1][j] + 1;
                    }                    
                }
                
                if(i > 0)//check if it is between 1 to height in y axis
                {              
                    if(A[i-1][j] != '#')
                    {
                        A[i-1][j] = A[i-1][j] + 1;
                    }
                }
            }
        }
    }

    for (int i = 0; i < height; i++) 
   {
        for(int j = 0; j < width; j++)
        {
            cout << A[i][j];
        }
        cout << endl;
        
    }
}
