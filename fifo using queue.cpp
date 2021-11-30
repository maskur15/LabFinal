#include<bits/stdc++.h>
using namespace std;
bool  isExist(queue<int>temp,int val)
{
    while(temp.size())
    {
        if(val==temp.front())
        {
            return true;
        }
        temp.pop();
    }
    return false;
}
int main()
{
    int frame_size,page_size;
    cout << "Enter number of page ref: ";
    cin >> page_size;
    cout << "enter number of page frame: ";
    cin >> frame_size;
    int page[page_size];
    cout << "Enter " << page_size << "page reference : ";
    for(int i=0;i<page_size;i++)
        cin >> page[i];
    int hit=0;
    queue<int>q;
    for(int i=0;i<page_size;i++)
    {

       if(isExist(q,page[i]))
        {
            hit+=1;
        }
        else if(q.size()<frame_size)
        {
            q.push(page[i]);
        }
        else {
            q.pop(); q.push(page[i]);
        }
    }
    cout << "Number of hits : " << hit << endl;
    cout << "Number of page faults : " << page_size-hit << endl;
    cout << "hit ratio : " << float(hit)/page_size*100 << "%" << endl;
    cout << "Miss ratio : " << float(page_size-hit)/page_size*100 << "%" << endl;

}

