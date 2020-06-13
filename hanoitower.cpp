#include<iostream>
using namespace std;

void MoveDisk(int n, char source, char dest, char temp)
{
    if(n==1) {
        cout<<"Move disk 1 from "<<source<<" to "<<dest<<endl;
        return;
    }
    else {
        MoveDisk(n-1,source,temp,dest);
        cout<<"Move disk "<<n<<" from "<<source<<" to "<<dest<<endl;
        MoveDisk(n-1,temp,dest,source);
    }
}

int main()
{
    int n;
    cout<<"Enter n:"<<endl;
    cin>>n;
    MoveDisk(n,'A','C','B');
    return 0;
}