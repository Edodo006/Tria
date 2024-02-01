#include <stdio.h>
#include <stdlib.h>

#define GRIGLIA 3
#define TOTALERIQUADRI 9

int trisGioco(int griglia[GRIGLIA][GRIGLIA], int player){
    
    int c=0;
    int n=0;
    int turno=0;
    int orizzontale;
    int verticale;
    int validita;
    char pointer;

    for(c=0; c<GRIGLIA; c++){
        for(n=0; n<GRIGLIA; n++){
            griglia[c][n] = -1;
        }
    }

    for(turno=0; turno<TOTALERIQUADRI; turno++){
        if(turno%2==0){
            player=0;
        }else{
            player=1;
        }
        
        validita=0;

        while(validita !=1){
            printf("Giocatore %d inserisci la coordinata orizzontale\n", player);
            scanf("%d", &orizzontale);
            printf("Giocatore %d inserisci la coordinata verticale\n", player);
            scanf("%d", &verticale);

            if((griglia[orizzontale][verticale] != -1) || (orizzontale>2) || (verticale>2) || (orizzontale<0) || (verticale<0)){
                validita=0;
                if((orizzontale>2) || (verticale>2) || (orizzontale<0) || (verticale<0)){
                    printf("Coordinate inesistenti, perfavore ritenta con delle coordinate giuste\n");
                }else{
                    printf("OPS, hai beccato una casella gia occupata, ritenta");
                }
            }else{
                validita = 1;
                griglia[orizzontale][verticale] = player;
            }
        }

        for(c=0; c<GRIGLIA; c++){
            for(n=0; n<GRIGLIA; n++){
                if(griglia[c][n] == -1){
                    pointer='#';
                }else{
                    if(griglia[c][n] == 0){
                        pointer = 'X';
                    }else{
                        pointer = 'O';
                    }
                }

                if(n<2){
                    printf("%c", pointer);
                }else{
                    printf("%c\n", pointer);
                }
            }
        }

        if((((griglia[0][0] == griglia[0][1]) && (griglia[0][1] == griglia[0][2]) && (griglia[0][0] != -1) && (griglia[0][1] != -1) && (griglia[0][2] != -1)) || ((griglia[1][0] == griglia[1][1]) && (griglia[1][1] == griglia[1][2]) && (griglia[1][0] != -1) && (griglia[1][1] != -1) && (griglia[1][2] != -1)) || ((griglia[2][0] == griglia[2][1]) && (griglia[2][1] == griglia[2][2]) && (griglia[2][0] != -1) && (griglia[2][1] != -1) && (griglia[2][2] != -1)))){
            printf("Il giocatore %d e il vincitore", player);
            return 1;
        }
        if(((griglia[0][0] == griglia[1][0]) && (griglia[1][0] == griglia[2][0]) && (griglia[0][0] != -1) && (griglia[1][0] != -1) && (griglia[2][0] != -1)) || ((griglia[0][1] == griglia[1][1]) && (griglia[1][1] == griglia[2][1]) && (griglia[0][1] != -1) && (griglia[1][1] != -1) && (griglia[2][1] != -1)) || ((griglia[0][2] == griglia[1][2]) && (griglia[1][2] == griglia[2][2]) && (griglia[0][2] != -1) && (griglia[1][2] != -1) && (griglia[2][2] != -1))){
            printf("Il giocatore %d e il vincitore", player);
            return 1;
        }
        if((griglia[0][0] == griglia[1][1]) && (griglia[1][1] == griglia[2][2]) && (griglia[0][0] != -1) && (griglia[1][1] != -1) && (griglia[2][2] != -1)){
            printf("Il giocatore %d e il vincitore", player);
            return 1;
        }
        if((griglia[0][2] == griglia[1][1]) && (griglia[1][1] == griglia[2][0]) && (griglia[0][2] != -1) && (griglia[1][1] != -1) && (griglia[2][0] != -1)){
            printf("Il giocatore %d e il vincitore", player);
            return 1;
        }
        if(turno == 8){
            printf("Pareggio");
            return 1;
        }
    }
    return player;

}

int main() {
    
    int player;
    int griglia[GRIGLIA][GRIGLIA];
    int scelta;
    int prossimo;

    do{
        system("cls");
        printf("1. Leggi le regole del gioco");
        printf("\n2. Gioca a Tris");
        printf("\n3. Uscita sicura dal gioco. Torna a Windows");
        printf("\nInserire un opzione da eseguire\n");
        scanf("%d", &scelta);

        switch(scelta){
            case 1: {
                system("cls");
                printf("==REGOLE==");
                printf("\n\n\n");
                printf("Ogni giocatore deve provare a formare una fila di 3 pedine su una stessa linea, un tris. Quando tutte le pedine sono posizionate sulla scacchiera, a turno si sposta una pedina lungo una linea verso una casella libera adiacente, sempre allo scopo di formare un tris.");
                printf("\n\n\n");
                printf("Premere un tasto per uscire\n");
                scanf("%d", &prossimo);
                break;
            }
            
            case 2: {
                system("cls");
                printf("==TRIS GIOCO==");
                printf("\n\n\n");
                trisGioco(griglia, player);
                printf("\n\n\n");
                printf("Inserire un numero per uscire\n");
                scanf("%d", &prossimo);
                break;
            }
        }
    }while(1);
    
}