#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int W, H;
    cin >> W >> H; cin.ignore();

    int counter[W/3 + 1];
    for(int i = 0; i < W/3 + 1; i++)//initialize the indexes of the first line A B C 0 1 2
    {
        counter[i] = i;
    }
    
    char first_label[W/3 + 1],second_label[W/3 + 1];
    
    for(int i = 0; i < H; i++)
    {
        string line;
        getline(cin, line);

        for(int j = 0; j < W/3 + 1; j++)
        {
            if(line[j*3+1] == '-')//if the char - is found
            {
                for(int k = 0; k < W/3 + 1; k++)//for each index change its position by +1 if it is before '-' and by -1 if it is after '-'
                {
                    if(counter[k] == j)
                    {
                        counter[k] += 1;
                    }
                    else if(counter[k] == j+1)
                    {
                        counter[k] -= 1;
                    }
                }
            }
        }

        if(i == 0)
        {
            for(int i = 0; i < W/3 + 1; i++)//initialize the first line
            {
                first_label[i] = line[3*i];
            }
        } 
        else if(i == H-1)
        {
            for(int i = 0; i < W/3 + 1; i++)//initialize the last line
            {
                second_label[i] = line[3*i];
            }
        }
    }

    for(int i = 0; i < W/3 + 1; i++)
    {
        cout << first_label[i] << second_label[counter[i]] << endl;
    }
}