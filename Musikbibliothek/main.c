#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Struktur für einen Musiktitel
struct Song {
    char title[100];
    char artist[100];
    int year;
};

// Funktion zum Hinzufügen eines neuen Songs zur Bibliothek
void addSong(struct Song library[], int *numSongs) {
    printf("Titel: ");
    scanf("%s", library[*numSongs].title);

    printf("Künstler: ");
    scanf("%s", library[*numSongs].artist);

    printf("Jahr: ");
    scanf("%d", &library[*numSongs].year);

    (*numSongs)++; // Erhöhe die Anzahl der Songs in der Bibliothek
}

// Funktion zum Anzeigen aller Songs in der Bibliothek
void displayLibrary(const struct Song library[], int numSongs) {
    printf("\nMusikbibliothek:\n");
    for (int i = 0; i < numSongs; i++) {
        printf("%d. %s - %s (%d)\n", i + 1, library[i].artist, library[i].title, library[i].year);
    }
}

void changeMusik(struct Song library[]){

    printf("\nWelches Lied möchten sie ändern?\n");
    printf("Bitte die Nr. eingeben!");
    int nummer = 0;
    scanf("%d" , &nummer);
    if(nummer != 0){
        nummer = nummer - 1;
        printf("\nWas möchten sie ändern?\n");
        printf("1. Titel ändern\n");
        printf("2. Interpreten ändern\n");
        printf("3. Erscheinungsdatum ändern\n");
        printf("0. Nichts ändern\n");
        
        int auswahl = 0;
        scanf("%d" , & auswahl);
        if(auswahl == 1){
            printf("Neuer Titel:\n");
            scanf( "%s", &library[nummer].title);
            printf("Titel wurde geändert\n");
            }
            else
            {
                if(auswahl == 2){
                printf("Neuer Interpreten:\n");
                scanf( "%s", &library[nummer].artist);
                printf("Interpreten wurde geändert\n");
                }
                else{
                    if(auswahl == 3){
                        printf("Neues Jahr:\n");
                        scanf( "%d", &library[nummer].year);
                        printf("Jahr wurde geändert\n");
                        }
                        else{
                            printf("Keine Änderung vorgenomen.\n");
                            }
                            }
            }
            }
    else{
        printf("Falsche eingabe!!");
        }

}
void deleteSongs(struct Song library[], int *numSongs){

    printf("\n Welches Lied möchten sie löschen? Bitte Nummer angeben:\n");
    int nummer;
    scanf("%d", &nummer);
    if(nummer < 1 || nummer > *numSongs){
        printf("Falsche eingabe kehre zum Hauptmenü zurück.");
    }
    else{
        printf("Soll wirklich Song: %s - %s (%d) gelöscht werden?" ,library[nummer-1].artist, library[nummer-1].title, library[nummer-1].year);
        printf("1, Ja\n");
        printf("2. Nein\n");
        int antwort = 2;
        printf("\nantwort : %d", antwort);
        scanf("%d", &antwort);
        printf(" antwort : %d", antwort);
        switch (antwort)
        {
        case 1:
        if( nummer == *numSongs){
            (*numSongs)--;
            }else{
                for(int i = nummer; i <= *numSongs ; i++){
                    int y = i-1;
                    strcpy(library[y].title,library[i].title);
                    strcpy(library[y].artist,library[i].artist);
                    strcpy(library[y].year,library[i].year);
                }
                (*numSongs)--;

            }
            printf("Lied wurde gelöscht.\n");
            break;
        
        default:
        printf("Vorgang wurde abgebrochen kert zurück zum Hauptmenü.\n");
            break;
        }
    }
}

void searchmusik(struct Song library[], int *numSongs){

    printf("Nach was suchen sie?\n");
    printf("1. Nach Titel\n");
    printf("2. Nach Interpreten\n");
    printf("3. Nach erscheiniungs Jahr\n");

    int auswahl = 0;
    int anzahl = *numSongs;
    char eingabe[100];
    int Jahr;
    scanf("%d", &auswahl);
    switch (auswahl){
        case 1:
        printf(" Geben sie den Titel ein:\n");
        scanf("%s" , &eingabe);
        for(int i = 0 ; i < anzahl ; i++ ){
            if(strcmp( eingabe, library[i].title) == 0){
                printf("%d. %s - %s (%d)\n", i + 1, library[i].artist, library[i].title, library[i].year);
            }
        }
        break;
        case 2:
        printf(" Geben sie den Interpreten ein:\n");
        scanf("%s" , &eingabe);
        for(int i = 0 ; i < anzahl ; i++ ){
            if(strcmp( eingabe, library[i].artist) == 0){
                printf("%d. %s - %s (%d)\n", i + 1, library[i].artist, library[i].title, library[i].year);
            }
        }
        break;
        case 3:
        printf(" Geben sie den Jahr ein:\n");
        scanf("%d" , &Jahr);
        for(int i = 0 ; i < anzahl ; i++ ){
            if( Jahr == library[i].year){
                printf("%d. %s - %s (%d)\n", i + 1, library[i].artist, library[i].title, library[i].year);
            }
        }
        break;
        default:
        printf("Falsche Eingabe kehre zum Hauptmenüe zurück");
    }
}

int main() {
    struct Song musicLibrary[100]; // Annahme: maximal 100 Songs in der Bibliothek
    int numSongs = 0; // Anfangsanzahl der Songs

    int choice;
    do {
        // Menü anzeigen
        printf("\n1. Musik hinzufügen\n");
        printf("2. Bibliothek anzeigen\n");
        printf("3. Musik bearbeiten\n");
        printf("4. Musik suchen\n");
        printf("5. Musik löschen\n");
        printf("0. Beenden\n");
        printf("Auswahl: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addSong(musicLibrary, &numSongs);
                break;
            case 2:
                displayLibrary(musicLibrary, numSongs);
                break;
            case 3:
                changeMusik(musicLibrary);
                break;
            case 4:
                searchmusik(musicLibrary, &numSongs);
                break;
            case 5:
                deleteSongs(musicLibrary, &numSongs);
                break;
            case 0:
                printf("Programm wird beendet.\n");
                break;
            default:
                printf("Ungültige Auswahl. Versuche es erneut.\n");
        }
    } while (choice != 0);

    return 0;
}