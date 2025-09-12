#include <iostream>
#include <vector>
using namespace std;
int main(){
	int n=0;
    cin>>n;
    vector<vector<int>> matrix(n,vector<int>(n,0));
    int left=0,right=n-1,up=0,down=n-1;
    int a=0,b=0,flag=1;
    for (int i=1;i<=n*n;i++) {
        matrix[a][b]=i;
        if (a==up&&b!=right) {
            b+=flag;
            if (b==right) {
                up++;
            }
        } else if (b==right&&a!=down) {
            a+=flag;
            if (a==down) {
                right--;
                flag*=-1;
            }
        } else if (a==down&&b!=left) {
            b+=flag;
            if (b==left) {
                down--;
            }
        } else if (b==left&&a!=up) {
            a+=flag;
            if (a==up) {
                left++;
                flag*=-1;
            }
        }
    }
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++) {
            if (matrix[i][j]<10) cout<<" ";
            cout<<" "<<matrix[i][j];
        }
        cout<<endl;
    }
    return 0;
}