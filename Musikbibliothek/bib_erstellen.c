#include <stdio.h>
#include <string.h>
#include <stdlib.h>



int* b_erstellen(char* name){
    int* bib_neu= (int*) malloc(250*sizeof(int));
    printf("\nDie Bibliothek mit dem Namen: %s wurde erstellt.", name);
    return bib_neu;
}
void bname_bearbeiten(char* name){
    char* bname_alt = name;
    char* buff_name = bname_alt;
    printf("Geben Sie den neuen Namen ein:");
    scanf("%s",name);
    printf("Wollen Sie den Namen von %s zu %s aendern?", bib_name, name);

}



int main(){
    char bib_name[20];
    printf("Bitte geben Sie den Namen der Bibliothek ein:");

    scanf("%s",bib_name);
    printf("%s", bib_name);

    int* name_neu = b_erstellen(bib_name);


    bname_bearbeiten(bib_name);

    return 0;
} 
 

