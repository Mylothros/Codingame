#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int width, height, fori, forj;
    cin >> width >> height; cin.ignore();

    char a[height][width];
    
    for (int i = 0; i < height; i++)
    {
        string line;
        getline(cin, line);
        
        for(int j = 0; j < line.size(); j++)
        {
            a[i][j] = line[j];//saving the information in a 2d array
        }
    }
    
    for (int i = 0; i < height; i++)
    {
        fori = i;//holding the value of i
        
        for(int j = 0; j < width; j++)
        {
            forj = j;//holding the value of i
            
            if(a[i][j] != '.')
            {
                cout << j << " " << i << " ";//if it is not '.' then print the position
                
                while(1)
                {
                    if(j != width - 1)
                    {
                        if(a[i][j+1] != '.')//if the right node is not '.' print it and break the while line 38
                        {
                            cout << j + 1 << " " << i << " ";
                            break;
                        }
                        if(a[i][j+1] == '.' && j+1 == width - 1)//if the right node is  '.' and j+1(right node) is the last position print -1 -1 and break the while
                        {
                            cout << "-1 -1 ";
                            break;
                        }
                        if(a[i][j+1] == '.' && j+1 != width - 1)//if right node is '.' but it isnt the last position of the row then add +1 to j and run again until it found a node to the right or unti it reaches the last value of the row line 47
                        {
                            j++;
                        }
                    }
                    
                    if(j == width - 1)//if j is the last position of the node print -1 -1 and break the while
                    {
                        cout << "-1 -1 ";
                        break;
                    }
                }
                
                j = forj;// give j the value it had in the begining of the forloop so it will check the next positions
                
                while(1)//it is the same method with the while line 38 but for i not j
                {
                    if(i != height - 1)
                    {
                        if(a[i + 1][j] != '.')
                        {
                            cout << j << " " << i + 1 << endl;
                            break;
                        }
                        if(a[i + 1][j] == '.' && i+1 == height - 1)
                        {
                            cout << "-1 -1"<< endl;
                            break;
                        }
                        if(a[i + 1][j] == '.' && i+1!= height - 1)
                        {
                            i++;
                        }
                    }
                    
                    if(i == height - 1)
                    {
                        cout << "-1 -1 " << endl;
                        break;
                    }
                }
                
                i = fori;
            }
        }
    }
}