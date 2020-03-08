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
    string MESSAGE;
    getline(cin, MESSAGE);
    
    bool ok=true;
    int counter=0;
    int i=0,p=6,counter1=0;
    int *a = (int *)malloc(MESSAGE.length() * 7 * sizeof(int));
    int *b = (int *)malloc(MESSAGE.length() * 7 * sizeof(int)); 
    int *g = (int *)malloc(MESSAGE.length() * 7 * sizeof(int));
    //3 arrays a=binary b=hex numbers g= reverse of a
    for(int j=0;j<MESSAGE.length();j++)
    {
        a[i]=MESSAGE[j]%2;
        b[i]=MESSAGE[j]/2;
        g[p]=a[i];//p=6 means we reverse a array
    while(ok==true)
    {
        p--;//make p=5
        i++;//make i=1
        counter1++;//use in line 58
        a[i]=b[i-1]%2;
        b[i]=b[i-1]/2;
        g[p]=a[i];
            if(b[i]==0)
            {
                ok=false;            
            }   
            counter++;
    }   
    if (counter!=6)//if the binary conversion isnt 7 bytes set zeros
    {
        i++;
        p--;
        counter1++;
        a[i]=0;
        g[p]=a[i];
        counter=0;
    }    
    ok=true;
    i++;
    p--;
    counter1++;
    counter=0;
    p=p+(counter1*2);//make p after 6 to be 12 18.....
    counter1=0;     
    }
    bool q=true,w=true;
    string res;
    for(int k=0;k<=i-1;k++)// converting the array g which has all the message converted in binary to unary message
    {
        if(g[k]==1)
        {
            if(q==true)
            {
                q=false;
                w=true;
                if(k>0)
                {
                    res+=" ";
                }
                res+="0 ";
            }
            res+="0";
        }
        if(g[k]==0)
        {     
            if(w==true)
            {
                q=true;
                w=false;
                if(k>0)
                {
                    res+=" ";
                }
                res+="00 ";
            }
            res+="0";
        }  
    }
    cout << res;
}
