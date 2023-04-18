#include<stdio.h>
int main(){
    int basic,hra,da,total;
    printf("Enter your Basic Salary: ");
    scanf("%d", &basic);
    if (basic<30000)
    {
        hra = basic*0.2;
        da = basic*0.3;
        total = basic+hra+da;
        printf("%d",total);
    }
    else
    {
        if (basic>30000 && basic<60000)
        {
            hra = basic*0.25;
            da = basic*0.35;
            total = basic+hra+da;
            printf("%d",total);
        }
        else
        {
            if (basic>60000){
                hra = 0.3*basic;
                da = 0.4*basic;
                total = basic+hra+da;
                printf("%d",total);
            }
        }
    }
}