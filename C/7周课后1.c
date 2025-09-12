#include <stdio.h>
#include <math.h>
    int Sushu(int);
    int Digui(int);
    int Sushu(int num){
        if(num<2)return 0;
	    if(num<2||num==3)return 1;
        if(num%2==0||num%3==0)return 0;
        int j=5;
        int w=2;
        while(j*j<=num){
            if(num%j==0)return 0;
        j+=w;
        w=6-w;
        }
        return 0;
    }
    int Digui(int a){
        if ((a==1)||(a==2)){
            return 1;
        }
	    int sum=0;
	    if(Sushu(a)){
		    for(int i=1;i<a;i++){
			    if(a%i==0){
				    sum+=Digui(i);
			    }
		    }
            return sum;
        }else{
		    for(int i=0;;i++){
			    if(pow(2,i)>a){
				    return Digui((int)pow(2,i-1));
			    }
		    }
	    }
    }
int main(){
    int a=0;
    scanf("%d",&a);
    printf("%d",Digui(a));
    return 0;
}