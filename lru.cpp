#include<bits/stdc++.h>
using namespace std;
int main()
{
    int frameSize,pageSize;
    cout << "Enter the number of page ref: ";
    cin >> pageSize;
    cout << "Enter the number of page frame: ";
    cin>> frameSize;
    int page[pageSize];
    int frame[frameSize];
    cout << "Enter " << pageSize<< " references : ";
    for(int i=0;i<pageSize;i++)
       cin>> page[i];
    int f=0,hit=0;
    for(int i=0;i<pageSize;i++)
    {
        bool exist=false;
        for(int k=0;k<frameSize;k++)
        {
            if(frame[k]==page[i])
            {
                hit+=1; exist=true; break;
            }
        }
        if(!exist)
        {
            if(f<frameSize)
            {
                frame[f]=page[i];
                f++;
            }
            else {
                int mIndex=3333,in;
                for(int k=0;k<frameSize;k++)
                {
                    int val=frame[k];
                    for(int j=i-1;j>=0;j--)
                    {
                        if(page[j]==val)
                        {
                            in=j; break;
                        }
                    }
                    if(in<=mIndex)
                    {
                        mIndex=in;
                    }
                }
                for(int k=0;k<frameSize;k++)
                {
                    if(page[mIndex]==frame[k])
                    {
                        frame[k]=page[i];
                    }
                }
            }
        }
    }
    cout << "Number of page hit: " << hit<< endl;
    cout << "Number of page fault: " << pageSize-hit << endl;

}
