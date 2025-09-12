#include <stdio.h>
#include <string.h>
int main(){
    char *input;
    scanf("%c",&input);
    char str[100];
    int m=0;
    while (input[m]!='\0'){
        str[m]=input[m];
        m++;
    }
    int n=0;
    char i=str[0];
    for (int x=0;x<=strlen(str);x++){
        if (str[x]==i){
            n++;
        }else if(str[x]!=i||str[x]=='\0'){
            printf("%c%d",i,n);
            i=str[x];
            n=0;
        }
    }
    return 0;
}
