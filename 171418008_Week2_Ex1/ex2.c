/*

	BLM3010 - SistemProgramlama_2.HaftaÖdevi
	
	
	
  
	
	Talha UÇAR - 171418008

*/


#include <stdint.h>
#include <stdio.h>

void DumpHex(const void* data, size_t size) {
	char ascii[17];
	size_t i, j;
	ascii[16] = '\0';
	for (i = 0; i < size; ++i) {
		printf("%02X ", ((unsigned char*)data)[i]);
		if (((unsigned char*)data)[i] >= ' ' && ((unsigned char*)data)[i] <= '~') {
			ascii[i % 16] = ((unsigned char*)data)[i];
		} else {
			ascii[i % 16] = '.';
		}
		if ((i+1) % 8 == 0 || i+1 == size) {
			printf(" ");
			if ((i+1) % 16 == 0) {
				printf("|  %s \n", ascii);
			} else if (i+1 == size) {
				ascii[(i+1) % 16] = '\0';
				if ((i+1) % 16 <= 8) {
					printf(" ");
				}
				for (j = (i+1) % 16; j < 16; ++j) {
					printf("   ");
				}
				printf("\n");
			}
		}
	}
}

int main(int argc, char **argv) 
{
char charVal = '0';
int32_t intVal = 1;
float floatVal = 1.0;
double doubleVal = 1.0;
	typedef struct 
	{char charVal; 
	int32_t intVal;
	float floatVal;
	double doubleVal;
	} 
	Ex2Struct; 
	Ex2Struct structVal = { '0', 1, 1.0, 1.0 };
	DumpHex(&charVal, sizeof(char));
	DumpHex(&intVal, sizeof(int32_t)); 
	DumpHex(&floatVal, sizeof(float));
	DumpHex(&doubleVal, sizeof(double));
	DumpHex(&structVal, sizeof(structVal));
	return 0; 
}
	
	
	
	
	
	
	
	
	
	
	
	
	
