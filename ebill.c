#include<stdio.h>
int main(){
    int u;
    printf("Enter units: ");
    scanf("%d",&u);
    float total;
    if (u<50)
    {
        total = u*2.5;
    }
    else
    {
        if (u > 50 && u<125)
        {
            total = 125+(u-50)*3;
        }
        else
        {
            if (u > 125 && u <= 225)
            {
                total = 350+(u-125)*3.5;
            }
            else
            {
                if (u >= 225)
                {
                    total = 700+(u-225)*4;
                }
            }
        }
  
    }
    if (u>200)
    {
        total = total*1.2;
    }
    printf("%lf",total);
}