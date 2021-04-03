#include <stdio.h>
#include <dirent.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <unistd.h>

char files[50][255] ;
char directorys[50][255];
int file_counter = 0, dir_counter = 0; 

void get_file_or_directory(char []);
void print_file_dir();
void inside_dir();
void open_file(char patt[]);
int EndsWithTxt(char *string);
void match(char [], char [], int, int);
void write_file();

int main(){

 	get_file_or_directory(".");
 	inside_dir();
 	print_file_dir();
 	open_file("ece");
 	
	return 0;
}

void get_file_or_directory(char directory[]){
	
	DIR *dir;
   	dir=opendir(".");
   	

	struct dirent *dent;
	struct stat st;
	if(dir!=NULL)
	{

	   while((dent=readdir(dir)))
		 {
		    FILE *ptr;
		  
			
	      	lstat(dent->d_name, &st);
			  if(S_ISDIR(st.st_mode))
			  {
			  		if(strcmp(dent->d_name,".") != 0 && strcmp(dent->d_name,"..")!=0)
			  		 {
			  		 	strcpy(*(directorys+dir_counter),dent->d_name);
			  			dir_counter++;
			  			
			  		 }
			  			
			  		
			  }
			  	else
			  	{
			  		if(EndsWithTxt(dent->d_name) == 0){
			  		
				  		strcpy(*(files+file_counter),dent->d_name);
				  		file_counter++;
				  		
			  		
			  		}
			  		
			  	}
		}
		   closedir(dir);
	}
	else
		printf("ERROR OPENIN DIRECTORY");
	
}

void print_file_dir(){

   int i=0;
   
   for(i = 0; i < file_counter;i++){
   
   		printf("File:%s\n",*(files+i));
   		
   } 
   
   for(i = 0; i < dir_counter;i++){
   
   		printf("Dir:%s\n",*(directorys+i));
   	
   } 

}

int EndsWithTxt(char *string){//stackoverflow.com/questions/744766/how-to-compare-ends-of-strings-in-c

	string = strrchr(string,'.');
	if(string !=NULL)
		return(strcmp(string,".txt"));
		
	return (-1);
	
}

void match(char text[], char pattern[], int text_length, int row) {
  int c, d, e, pattern_length, position = -1;

  pattern_length = strlen(pattern);//Pattern'in uzunluğunu alıyoruz.
  FILE *fp;
fp = fopen("log.txt","a+");

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
      	
	fprintf(fp,"Found at %d. row %d. Column\n",row,c+1);
      printf("Found at %d. row %d. Column\n",row,c+1);
      
    }
  }

fclose(fp);
}

void open_file(char patt[]){

	
	int position;

	FILE *fp,*fp_temp;
	char buff[255];
	memset(buff,0,sizeof(buff));
	int i;
	for (i = 0; i < file_counter; i ++){
		char text_length=0,row=0;
		printf("\t%s adlı dosyada.\n",*(files +i));
		fp_temp = fopen("log.txt","a+");
		fprintf(fp_temp,"\t%s adlı dosyada.\n",*(files +i));
		fclose(fp_temp);
	
		fp = fopen(*(files +i), "r");

		while(fgets(buff,255,fp) != NULL){//Metin dosyasını satır satır okuyoruz

		text_length = strlen(buff);
			match(buff, patt,text_length, row);//Okuduğumuz satırları fonksiyona gönderiyoruz.
			row++;

		}

		fclose(fp);
		
	
	}


}


void inside_dir(){
	
	
	int i;
	for(i = 0; i < dir_counter; i++){
		
		DIR *dir;
   	dir=opendir(*(directorys+i));

	struct dirent *dent;
	struct stat st;
	if(dir!=NULL)
	{	

	   while((dent=readdir(dir)))
		 {
		    FILE *ptr;
		  
		  
		
	      	lstat(dent->d_name, &st);
			  if(S_ISDIR(st.st_mode))
			  {
			  		
			  		if(EndsWithTxt(dent->d_name) == 0){
			  			
			  			char curr_dir[255] ="./"; 
						char temp[255] = "/";
			  			strcat(curr_dir,*(directorys+i));
			  			
			  			strcat(curr_dir, temp);
			  			strcat(curr_dir,dent->d_name );
			  			
				  		strcpy(*(files+file_counter),curr_dir);
				  		file_counter++;
				  		
			  		
			  		}
			  		if(strcmp(dent->d_name,".") != 0 && strcmp(dent->d_name,"..")!=0)
			  		 {
			  		 	strcpy(*(directorys+dir_counter),dent->d_name);
			  			dir_counter++;
			  			
			  		 }
			  			
			  		
			  }
			  	else
			  	{
			  	
			  		if(EndsWithTxt(dent->d_name) == 0){
			  		
				  		char curr_dir[255] ="./"; 
						char temp[255] = "/";
			  			strcat(curr_dir,*(directorys+i));
			  			
			  			strcat(curr_dir, temp);
			  			strcat(curr_dir,dent->d_name );
				  		strcpy(*(files+file_counter),curr_dir);
				  		file_counter++;
				  		
			  		
			  		}
			  		
			  	}
		}
		   closedir(dir);
	}
	else
		printf("ERROR OPENIN DIRECTORY\n");	
		
	}
	

}



