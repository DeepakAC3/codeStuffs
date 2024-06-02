#include <stdio.h>
void main(){
    int pH;
    scanf("%d",&pH);
    (pH<2) ? printf("Very Acidic") : (pH<7) ? printf("Acidic") : (pH==7) ? printf("Neutral") : (pH<=12) ? printf("Alkaline") : (pH>12) ? printf("Very Alkaline"): ;
    }

/*
int main()
{
	int yr = 1900;

	(yr%4==0) ? (yr%100!=0? printf("The year %d is a leap year",yr) : (yr%400==0 ? printf("The year %d is a leap year",yr) : printf("The year %d is not a leap year",yr)))
			: printf("The year %d is not a leap year",yr);
	return 0;
}
*/