/*

	Talha Uçar

	171418008

	Hafta2 - Odev2

*/

#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>

#include "GetPrime.h"

int main(int argc, char **argv) {
  printf("5. Prime: %" PRIu64 "\n", GetPrime(5));
  printf("60. Prime: %" PRIu64 "\n", GetPrime(60));
  printf("98. Prime: %" PRIu64 "\n", GetPrime(98));
  return 0;
}
