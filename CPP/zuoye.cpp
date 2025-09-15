#include <iostream>
#include <list>
#include <map>
#include <algorithm>
using namespace std;
int main(){
    int T;
    cin>>T;
    list<int> name;
    map<int,string> box;
    while(T--){
        int curname=0;
        string mess;
        cin>>curname>>mess;
        auto it=find(name.begin(),name.end(),curname);
        if (it==name.end()) {
            name.push_front(curname);
        } else {
            name.splice(name.begin(),name,it);
        }
        box[curname]=mess;
    }
    for (int i:name) {
        cout<<i<<": ";
        auto it=box.find(i);
        cout<<it->second<<endl;
    }
    return 0;
}