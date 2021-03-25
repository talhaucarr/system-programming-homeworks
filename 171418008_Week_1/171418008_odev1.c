/*

	BLM3010 - SistemProgramlama_1.HaftaÖdevi
	
	
	Nilakantha serisindeki 0'dan n'ye kadar olan terimleri bir araya
	getirerek PI tahmin eden C programı.
  
	
	Talha UÇAR - 171418008

*/



#include <stdio.h>
#include <math.h>
#include <stdlib.h>


int main(int argc,char **argv){
	
	int i;
	
	double pi=0.0,pi_temp=0;
	
	int n = atoi(argv[1]);//Terminalden girdiğimiz değeri atoi fonksiyonuyla int türüne çeviriyoruz.
	
	if(n == 0){//String girişi olursa ekrana hata mesajı verip programı sonlandırıyoruz.
		printf("Yanlış girdi!\n");
		return 0;
	}
	
	
	for(i = 0; i < n; i++){
		if(i == 0){//Serinin 0. terimi 3 olduğundan buraya bir kontrol koyduk.
			pi = 3.0;
		}
		else{//Sonraki terimler için serinin her elemanını bulup bir temp değişkenine atıyoruz.
			pi_temp = pow(-1,i+1)*4/(2*i*(2*i+1)*(2*i+2));
			pi+= pi_temp;//Atadığımız temp değişkenini tahmin ettiğimiz pi sayısıyla topluyoruz.
		}
		
		
		printf("%0.20f\n",pi);
	}
	
	return 0;
	

}
