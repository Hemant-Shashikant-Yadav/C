#include <stdio.h>

int main()
{
    int ld,n,t,r;
    
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        ld = n%10;
        while(n>0) {r=n%10; n=n/10;}
        printf("%d\n",r+ld);
    }
    return 0;
}

