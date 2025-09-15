#include <cmath>
#include <iostream>
#include <math.h>
using namespace std;
int main() {
    int a=1,b=0;
    double c=0;
    for (a=1;a<10;a++) {
        for (b=0;b<10;b++) {
            c=a*1000+a*100+b*10+b;
            c=sqrt(c);
            int d=(int)c;
            if (d==c&&a!=b) {
                cout<<c*c<<endl;
                return 0;
            }
        }
    }
}