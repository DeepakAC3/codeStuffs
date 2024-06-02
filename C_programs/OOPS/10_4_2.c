#include<stdio.h>
#include<stdlib.h>

struct Employee{
    int id;
    char name[50];
    double salary;
};


int main(){
    int choice;
    int numEmployees=0;
    struct Employee *Employeelist = (struct Employee *)calloc(numEmployees+1,sizeof(struct Employee));
    do{
        printf("Your Choice :");
        scanf("%d",&choice);
        if (choice == 3) break;
        else if (choice == 1){
            scanf("%d",&Employeelist[numEmployees].id);
            scanf("%s",Employeelist[numEmployees].name);
            scanf("%lf",&Employeelist[numEmployees].salary);
            Employeelist = realloc(Employeelist,++numEmployees*sizeof(struct Employee));
        }
        else if (choice == 2){
            for(int i=0;i<numEmployees;i++){
                printf("%d",Employeelist[i].id);
                printf("%s",Employeelist[i].name);
                printf("%lf",Employeelist[i].salary);
            }
        }
    }
    while(choice != 3);
    return 0;
}