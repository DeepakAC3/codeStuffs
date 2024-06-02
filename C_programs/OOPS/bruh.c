#include <stdio.h>
#include<string.h>
#include<ctype.h>
// characters in string
//if upper, lower, digit, whitespace, special symbol
//print count of each category
//use loops
int main(){
    int len;
    int whit,upp,low,spl,dig;
    scanf("%d",&len);
    char a[len];
    scanf("%s",&a);
    for(int i=0;i<len;i++){
        if (iswspace(a[i])==1)
        whit++;
        if (islower(a[i])==1)
        low++;
        if (isupper(a[i])==1)
        upp++;
        if(ispunct(a[i])==1)
        spl++;
        if(isdigit(a[i])==1)
        dig++;
    }
    printf("%d %d %d %d %d",whit,low,upp,spl,dig);
    return 0;
}