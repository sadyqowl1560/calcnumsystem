#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "myfunctions.h"

int main() {
 printf("Enter binary number (0 - 1 - others will be ignored): \t ") ;
 long long  input = 0 ;
 scanf("%lld",&input) ;
 puts("") ;
//bin to decimal
 printf("\nDecimal number of %lld : %lld",input,cbtdn(input,gnod(input))) ;
//bin to octal
 long long octal_number =atoi(cbton(input,gnod(input))) ;
 printf("\nOcatal number of %lld : %lld",input,octal_number) ;
//bin to hexadecimal
 printf("\nHexadecimal number of %lld : %s\n",input,cbthdn(input,gnod(input))) ;
 return 0;
}
