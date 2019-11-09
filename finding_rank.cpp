
#include <bits/stdc++.h>
using namespace std;

void merge(int left, int mid, int right);
void premer(int left, int right);

class point {
public:
    int x, y, index, rank;
    point(int x=0, int y=0, int index=0)
    {
        this->x=x;
        this->y=y;
        this->index=index;
    }
        
    //to sort
    bool operator<(const point &p) const {
        if(x == p.x)
            return y < p.y;
        return x < p.x;
    }
};

point P[1000000], tem[1000000];


int main() {
    int n;
    int ans[1000000]={0};
    cin>>n;
    int a, b;
    for (int i = 0; i < n; ++i)
    {
        cin>>a>>b;
        P[i]=point(a, b, i);
    }
    sort(P, P+n);
    premer(0, n-1);
    for(int i = 0; i < n; i++)
    {
        ans[P[i].index] = P[i].rank;
    }

    for(int i = 0; i < n; i++)
    {
         cout<<ans[i]<<endl;
    }
    return 0;
}

void merge(int left, int mid, int right)
{
    int front = left;
    int back = mid+1;
    int now = 0;
    int count=0;
    
    while(front <= mid && back <= right) 
    {
        if(P[front].y <= P[back].y)
        {    
            count++;
            tem[now] = P[front];
            now++;
            front++;
        }

        else
        {
            tem[now] = P[back];            
            tem[now].rank += count;
            now++;
            back++;
        }
    }

    while(front <= mid)    
    {
        tem[now] = P[front];
        now++;
        front++;
    }

    while(back <= right)    
    {

        tem[now] = P[back];
        tem[now].rank += count;
        now++;
        back++;
    }

    for(int i = 0; i < now; i++)
    {
        P[left] = tem[i];
        left++;
    }
}


void premer(int left, int right) 
{
    if(left >= right)    return ;
    int mid = (left+right)/2;
    premer(left, mid);
    premer(mid+1, right);
    merge(left, mid, right);
}