#include <iostream>
using namespace std;
int main() {
    float sum=1;
    for (int i=0;i<10;i++) {
        sum++;
        sum*=2;
    }
    cout<<sum<<endl;
    return 0;
}