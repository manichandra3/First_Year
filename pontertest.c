#include<stdio.h>
main( ) 
{
int i=3,*j,**k;
j = &i ;
k = &j ;
printf ( "\nAddress of i = %u", &i ) ; printf ( "\nAddress of i = %u", j ) ; printf ( "\nAddress of i = %u", *k ) ; printf ( "\nAddress of j = %u", &j ) ; printf ( "\nAddress of j = %u", k ) ; printf ( "\nAddress of k = %u", &k ) ; printf("\nValueofj =%u",j); printf("\nValueofk =%u",k); printf("\nValueofi =%d",i); printf("\nValueofi =%d",*(&i)); printf("\nValueofi =%d",*j); printf ( "\nValue of i = %d", **k ) ;
}
