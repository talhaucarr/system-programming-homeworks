/*

	BLM3010 - SistemProgramlama_1.HaftaÖdevi
	
	
	Txt dosyası içerisinde kelime arama uygulaması.
  
	
	Talha UÇAR - 171418008

*/


#include <stdio.h>
#include <string.h>
void match(char [], char [], int, int);

int main(int argc,char **argv) {

  char a[100], b[100],text_length=0,row=0;
  int position;
  
  	FILE *fp;
   char buff[255];

   fp = fopen("test.txt", "r");
   while(fgets(buff,255,fp) != NULL){//Metin dosyasını satır satır okuyoruz
   	text_length = strlen(buff);
   	match(buff, argv[1],text_length, row);//Okuduğumuz satırları fonksiyona gönderiyoruz.
   	row++;
   }

   fclose(fp);

  
  return 0;
}

void match(char text[], char pattern[], int text_length, int row) {
  int c, d, e, pattern_length, position = -1;

  pattern_length = strlen(pattern);//Pattern'in uzunluğunu alıyoruz.


  for (c = 0; c <= text_length - pattern_length; c++) {//Fonksiyona gönderdiğimiz satırı bu for ile gezmeye başlıyoruz.
    position = e = c;

    for (d = 0; d < pattern_length; d++) {//Burada pattern'i geziyoruz.
      if (pattern[d] == text[e]) {//pattern ile satırdaki seçtiğimiz yer eşleşiyorsa programı devam ettiriyoruz.
        e++;
      }
      else {//Eşleşmiyorsa for döngüsünü kırıp diğer index'ten devam ediyoruz.
        break;
      }
    }
    if (d == pattern_length) {
      //return position;
      printf("Found at %d. row %d. Column\n",row,c+1);
    }
  }


}
