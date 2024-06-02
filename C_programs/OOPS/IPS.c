#include <stdio.h>
int main(){
	int a[3][3]={{2,2,2},{2,2,2},{2,2,2}};
	int v,c,row,column,i,j,k,m;
	c=1;
	printf("player 1 is 0 and player 2 is 1");
	printf("\n");
	for(i=0;i<9;i++){
		for(j=0;j<3;j++){
			for(k=0;k<3;k++){
				printf("%d ",a[j][k]);
	    }
		printf("\n");		
		}
	if((i!=0) && ((i%2)==0)){
		c=1;
	}
	else{
		c=0;
	}	
	printf("player %d which row and column would u choose?\n",c);
	printf("row ");
	scanf("%d",&row);
	printf("column ");
	scanf("%d",&column);
	a[row][column]=c;
	printf("the row %d and column %d have been assigned\n",row,column);
	for(m=0;m<=3;m++){
		if(a[m][0]==a[m][1]==a[m][2]){
			switch(a[m][0]){
				case 0:
					printf("player 1 won");
					v=1;
					break;
				case 1:
				    printf("player 2 won");
					v=1;
					break;
						
			}
			}
		if(a[0][m]==a[1][m]==a[2][m]){
			switch(a[0][m]){
				case 0:
					printf("player 1 won");
					v=1;
					break;
				case 1:
				    printf("player 2 won");
					v=1;
					break;
						
			}
		}
	}
		if (a[0][0]==a[1][1]==a[2][2]){
			switch(a[0][0]){
				case 0:
					printf("player 1 won");
					v=1;
					break;
				case 1:
				    printf("player 2 won");
					v=1;
					break;	
			}
		}
		if (a[2][0]==a[1][1]==a[0][2]){
			switch (a[2][0]){
				case 0:
					printf("player 1 won");
					v=1;
					break;
				case 1:
				    printf("player 2 won");
					v=1;
					break;	
		if (v==1){
		break;
		}			
			}
		}
		}
	return 0;		
		}