/*

	Talha Uçar

	171418008

	Hafta2 - Odev2

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <inttypes.h>
#include <math.h>

#include "GetPrime.h"



uint64_t GetPrime(uint16_t number) {
  
  uint16_t c=0,temp=0,i;
  int firstPrime=2;
  if (number <= 0) {
    printf("Girdiginiz sayi gecersiz.\n");
    return 0;
  }
 

  while(c!=number){
  	int count = 0;
  	for(i = 2 ;i <= sqrt(firstPrime); i++)
	{
		if(firstPrime %i == 0){
			count++;
			break;
		}
	}
	if(count == 0){
		c++;
		temp = firstPrime;
	}
	firstPrime = firstPrime + 1;
  }

  return temp;
}


