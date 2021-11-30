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
                int in=-1,mIndex=-1;

               for(int k=0;k<frameSize;k++)
               {
                   int val=frame[k];
                   in=-1;
                   for(int j=i;j<pageSize;j++)
                   {
                       if(val==page[i]){
                        in=j;
                       }
                   }
                   if(in==-1){
                    frame[k]=page[i]; break;
                   }
                   if(mIndex<in)
                   {
                       mIndex=in;
                   }
               }
               if(in!=-1){
                for(int k=0;k<frameSize;k++)
                {
                    if(frame[k]==page[mIndex])
                    {
                        frame[k]=page[i]; break;
                    }
                }
               }

            }
        }
    }
    cout << "Number of page hit: " << hit<< endl;
    cout << "Number of page fault: " << pageSize-hit << endl;

}

