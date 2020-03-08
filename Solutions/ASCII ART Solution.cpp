#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Auto-generated code below aims at helping you parse
 * the standard input according to the problem statement.
 **/

int main()
{
    int L;
    cin >> L; cin.ignore();
    int H;
    cin >> H; cin.ignore();
    string T;
    getline(cin, T);
    string tryy;
    tryy="ABCDEFGHIJKLMNOPQRSTUVWXYZ";// set a string to be the alphabet
    int *positionASCIIart,counter=-1,*positionAlphabet,thiss=1;
    positionASCIIart=(int*)malloc(T.length() * sizeof(int));
    positionAlphabet=(int*)malloc(T.length() * sizeof(int));
    for(int k=0;k<T.length();k++)
    {
        for(int j=0; j<tryy.length();j++)
        {
            counter++;
            if(toupper(T[k])==tryy[j])// find the position fo the char in the alphabet-> tryy
            {
                positionAlphabet[k]=counter;//set the position of the char in the alphabet-> tryy
                thiss=0;
            }     
        }
        if(thiss==1)//if thiss = 1 it means that the char is not in the alphabet
        {
            positionAlphabet[k]=26;//set the position to be the ? in the ASCII art which is 1 position after the last char of the alphabet 25+1
        }
        positionASCIIart[k]=positionAlphabet[k]*L;//the position of the first letter in ASCII asrt 
        counter=-1;
        thiss=1;
    }
    for (int i = 0; i < H; i++) 
    { 
        string ROW;
        getline(cin, ROW);  
        
        for(int p=0;p<T.length();p++)
        {
            for(int l=0;l<L;l++)
            {  
            cout << ROW[positionASCIIart[p]+l];//printing row by row the ASCIIart
            }     
        }
        cout << endl ;

    }
}
