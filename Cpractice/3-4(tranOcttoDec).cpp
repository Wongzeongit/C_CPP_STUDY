#include <iostream>
#include <vector>
using namespace std;
int main() {
    string v;
    getline(cin,v);
    if (v.find("8")!=string::npos&&v.find("9")!=string::npos) {
        cout<<"Error Data!";
        return 0;
    }
    int sum=0,flag=1;
    auto it=v.rbegin();
    while (it!=v.rend()) {
        sum+=((*it-'0')*flag);
        it++;
        flag*=8;
    }
    cout<<sum;
}