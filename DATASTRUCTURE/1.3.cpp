#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
	vector<int> mis(1500);
    mis[0]=1;
    int i1=0,i2=0,i3=0;
    int next1=2,next2=3,next3=5;
    for (int i=1;i<1500;i++) {
        mis[i]=min({next1,next2,next3});
        if (mis[i]==next1) {
            i1++;
            next1=mis[i1]*2;
        } 
		if (mis[i]==next2) {
            i2++;
            next2=mis[i2]*3;
        } 
		if (mis[i]==next3) {
            i3++;
            next3=mis[i3]*5;
        }
    }
    cout<<mis[1499];
    return 0;
}