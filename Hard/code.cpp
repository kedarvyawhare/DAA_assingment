#include <bits/stdc++.h>
using namespace std;
const int N=30000+5;
int n,A,B;
char c[N];
int a[N],b[N],d[N],st[N*4];
const long long P=1000000009;
long long has[N],pr[N];
void input(){
    memset(c,0,sizeof(c));
    memset(a,0,sizeof(a));
    memset(b,0,sizeof(b));
    memset(d,0,sizeof(d));
    memset(st,0,sizeof(st));
    memset(has,0,sizeof(has));
    memset(pr,0,sizeof(pr));
    scanf("%d %d %d",&n,&A,&B);
    scanf("%s",c+1);
}
inline bool ch(int x,int y,int z){
    return (has[x+z-1]-has[x-1]+P)*pr[n-x]%P==(has[y+z-1]-has[y-1]+P)*pr[n-y]%P;
}
inline bool boo(int x,int y){
    int r=n-max(x,y)+2;
    if (ch(x,y,r-1)) return x>y;
    int m,l=0;
    while (l+1<r){
        m=(l+r)/2;
        if (ch(x,y,m))  l=m;
        else            r=m;
    }
    return c[x+l]<c[y+l];
}
void build(int l,int r,int x){
    if (l+1==r){
        st[x]=a[l];
        return;
    }
    build(l,(l+r)/2,x*2);
    build((l+r)/2,r,x*2+1);
    st[x]=min(st[x*2],st[x*2+1]);
}
