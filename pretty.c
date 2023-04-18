#include <stdio.h>

int main(void) 
{
	int T;
	int L,R;
    printf("Enter the number of iterations.");
	scanf("%d",&T);

	for (int i = 0; i < T; i++)
	{
        int count = 0;
        printf("Enter L and R.");
        scanf("%d %d",&L,&R);
	    for (int j = L; j <= R; j++)
	    {
	        int rem = j%10;
	        if (rem == 2||rem == 3||rem == 9)
	        {
                printf("%d ",j);
	            count++;
	        }
	    }
	    printf("\n%d\n",count);
	}
	return 0;
}
