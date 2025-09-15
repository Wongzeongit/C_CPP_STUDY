#include  <iostream>
using namespace std;
int main(){
    int data;
    cin>>data;
    int a,b,c,d;
    a=data/1000;
    b=data/100-a*10;
    d=data%10;
    c=(data%100-d)/10;
    a=(a+5)%10;
    b=(b+5)%10;
    c=(c+5)%10;
    d=(d+5)%10;
    cout<<d<<c<<b<<a;
    return 0;
}