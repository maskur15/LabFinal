#include<bits/stdc++.h>
using namespace std;
int main()
{
    int frame_size,page_size;
    cout << "Enter number of page ref: ";
    cin >> page_size;
    cout << "enter number of page frame: ";
    cin >> frame_size;
    int frame[frame_size];
    int page[page_size];
    cout << "Enter " << page_size << "page reference : ";
    for(int i=0;i<page_size;i++)
        cin >> page[i];
    int hit=0,f=0;
    for(int i=0;i<page_size;i++)
    {
        bool flag=true;
        for(int k=0;k<frame_size;k++)
        {
            if(frame[k]==page[i])
            {
                hit+=1;
                flag=false;
                break;
            }
        }
        if(flag)
        {
            frame[f]=page[i]; f++;
        }
        if(f==frame_size)
        {
            f=0;
        }
    }
    cout << "hit : " << hit << endl;
    cout << "miss : " << page_size-hit << endl;
    cout << "hit ratio : " << float(hit)/page_size*100 << "%" << endl;
    cout << "Miss ratio : " << float(page_size-hit)/page_size*100 << "%" << endl;

}
