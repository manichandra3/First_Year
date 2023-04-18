#include<stdio.h>
#include<time.h>
int main()
{
    time_t tm;
    time(&tm);
    printf("The name of the file is %s\n",__FILE__);
    printf("Current Date/Time = %s", ctime(&tm));
    printf("fun() starts \n");
    printf("Press enter to stop fun \n");
    while(1)
    {
        if (getchar())
            break;
    }
    printf("fun() ends \n");
    clock_t t;
    t = clock();
    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC;
    printf("fun() took %f seconds to execute \n", time_taken);
    return 0;
    return 0;
}