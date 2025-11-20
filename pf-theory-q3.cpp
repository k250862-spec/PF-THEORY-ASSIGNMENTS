#include<stdio.h>
void update(int matrix[][5]);
void Query(int matrix[][5]);
void diagnostic(int matrix[][5]);

int main(){
    int matrix[5][5]={0};
    int opt;
    do {
        printf("MENU :\n");
        printf("PRESS:\n1 : Update Grid\n2 : Query Sector Status\n3 : Run System Diagnostic\n4 : Exit\n");
        scanf("%d",&opt);
        switch (opt){
            case 1:
                update(matrix);
                printf("\n\n\n");
                break;
            case 2:
                Query(matrix);
                printf("\n\n\n");
                break;
            case 3:
                diagnostic(matrix);
                printf("\n\n\n");
                break;
            case 4:
                printf("Exiting Program....");
        }
    }while (opt !=4);

}

void update(int matrix[][5]){
    int bit, r, c, action;
    printf("Enter Sector Row\n");
    scanf("%d",&r);
    printf("Enter Sector Column\n");
    scanf("%d",&c);
    printf("To Set a bit Press 1\tTo clear a bit press 0\n");
    scanf("%d",&action);
    if (action){
        printf("Enter Bit You want to set\n0 : Power Status\t1 : Overload Warning\t2 : Maintenance Required\n");
        scanf("%d",&bit);
        matrix[r][c]=matrix[r][c] | (1<<bit);
    }
    else{
        printf("Enter Bit You want to clear\n0 : Power Status\t1 : Overload Warning\t2 : Maintenance Required\n");
        scanf("%d",&bit);
        matrix[r][c]=matrix[r][c] & ~(1<<bit);
    }
}

void Query(int matrix[][5]){
    int r, c;
    printf("Enter Grid Row you want to check\n");
    scanf("%d",&r);
    printf("Enter Grid Column you want to check\n");
    scanf("%d",&c);
    if (matrix[r][c]&1){printf("Power is ON\n");}
    else{printf("Power is OFF\n");}

    if (matrix[r][c]&2){printf("Sector is OVERLOADED!\n");}
    else{printf("Sector is Normal\n");}

    if (matrix[r][c]&4){printf("Maintenance REQUIRED!\n");}
    else{printf("Maintenance not required\n");}
}

void diagnostic(int matrix[][5]){
    int i, j, count=0;
    for (i=0;i<5;i++){
        for (j=0;j<5;j++){
            if (matrix[i][j]&2 || matrix[i][j]&4){
                count++;
            }
        }
    }
    printf("%d sectors are overloaded OR require maintenance",count);
}