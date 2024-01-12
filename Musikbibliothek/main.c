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

int main() {
    struct Song musicLibrary[100]; // Annahme: maximal 100 Songs in der Bibliothek
    int numSongs = 0; // Anfangsanzahl der Songs

    int choice;
    do {
        // Menü anzeigen
        printf("\n1. Musik hinzufügen\n");
        printf("2. Bibliothek anzeigen\n");
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
            case 0:
                printf("Programm wird beendet.\n");
                break;
            default:
                printf("Ungültige Auswahl. Versuche es erneut.\n");
        }
    } while (choice != 0);

    return 0;
}