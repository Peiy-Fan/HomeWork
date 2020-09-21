#include <algorithm>
#include <fstream>
#include <iostream>
#include <cstring>
#include <time.h>
using namespace std;

const int w_1m=1000000;
int w[w_1m];

bool is_match(int t, int w[], int w_length)
{

    int left=0,right=w_length,mid;
    //二分法查找
    while(left<right)
    {
        mid=(left+right)/2;
        if(t<w[mid])
        {
            right=mid-1;
        }
        else if(t>w[mid])
        {
            left=mid+1;
        }
        else if(t==w[mid])
        {
            return false;
        }
    }
    return true;
}

// brute -w whitelist < T
int main(int argc, char *argv[])
{
    clock_t start,end;
    start = clock();
    if(argc != 3 || strcmp(argv[1], "-w"))
    {
        return 1;
    }

// init w
////    for(int i=0;i<w_1m)
////    {
////        w[i]=-1; //填充非法数据
////    }
    ifstream infile;
    infile.open(argv[2]);
    int i=0;
    cout << argv[2]<< endl;
    while(infile>>w[i++])
    {
    }
    int w_length = i-1;
    cout << w_length << endl;
// check t
    int t=0;
    sort(w,w+w_length);
    while(cin >> t)
    {
        if(is_match(t, w, w_length))
        {
            cout << t << endl;
        }
    }
    end = clock();
    cout<<"time = "<<double(end-start)/CLOCKS_PER_SEC<<"s"<<endl;;
}
