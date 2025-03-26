#include <stdio.h>

typedef struct {
    int codice;
    int quantita;
    float prezzo;
}articolo;

void InserimentoArticoli(int i,articolo* articoli){
    for (int j = 0; j < i; ++j) {
        printf("inserisci il codice dell'articolo:\n");
        scanf("%d",&articoli[j].codice);
        printf("inserisci la quantita dell'articolo:\n");
        scanf("%d",&articoli[j].quantita);
        printf("inserisci il prezzo dell'articolo:\n");
        scanf("%f",&articoli[j].prezzo);
    }
}

void VisualizzaMagazzino(int i, articolo* articoli){
    printf("%d",articoli[1].quantita);
}


int RicercaCodice(int i,articolo* articoli,int CodiceUtente){
    for (int j = 0; j < i; ++j) {
        if (articoli[j].codice == CodiceUtente){
            printf("l'articolo di codice %d esiste:\n",CodiceUtente);
            printf("Contenuto: Codice: %d, Quantita': %d, Prezzo: %f\n",articoli[j].codice,articoli[j].quantita,articoli[j].prezzo);
            return 1;
        }
    }
    printf("l'articolo di codice %d non esiste:\n",CodiceUtente);
    return 0;
}

void ModificaArticolo(int i,articolo* articoli,int CodiceUtente){
    if (RicercaCodice(i,&articoli[i],CodiceUtente) == 1){
        printf("inserisci il codice dell'articolo:\n");
        scanf("%d",&articoli[i].codice);
        printf("inserisci la quantita dell'articolo:\n");
        scanf("%d",&articoli[i].quantita);
        printf("inserisci il prezzo dell'articolo:\n");
        scanf("%f",&articoli[i].prezzo);
    }
}

float CalcoloValore(int i,articolo* articoli){
    float valore = 0;
    for (int j = 0; j < i; ++j) {
        float temp = articoli[j].quantita;
        valore = valore + (temp*articoli[j].prezzo);
    }
    return valore;
}



int main(void) {
    printf("quanti articoli ha il magazzino? (min 1/max 100)\n");
    int i = 0;
    scanf("%d",&i);
    while (i < 1 || i > 100){
        printf("quantita invilida");
        printf("quanti articoli ha il magazzino? (min 1/max 100)\n");
        scanf("%d",&i);
    }
    articolo articoli[i];
    int a=0;
    while (a==0){
        printf("inserisci: 0 per uscire dal programma\n");
        printf("inserisci: 1 per inserire degli articoli\n");
        printf("inserisci: 2 per visualizzare gli articoli\n");
        printf("inserisci: 3 per cercare un articolo tramite codice\n");
        printf("inserisci: 4 per modificare un articolo tramite codice\n");
        printf("inserisci: 5 per vedere il valore del magazzino\n");
        int caso=0;
        scanf("%d",&caso);
        switch (caso) {
            default: a=1;
                break;
            case 0: a=1;
                break;
            case 1:
                printf("inserimento degli articoli:\n");
                InserimentoArticoli(i,&articoli[i]);
                break;
            case 2:
                VisualizzaMagazzino(i,&articoli[i]);
                break;
            case 3:
                printf("inserisci il codice che vuoi cercare\n");
                int codice;
                scanf("%d",&codice);
                RicercaCodice(i,&articoli[i],codice);
                break;
            case 4:
                printf("inserisci il codice che vuoi cercare\n");
                int c;
                scanf("%d",&c);
                ModificaArticolo(i,&articoli[i],c);
                break;
            case 5:
                printf("il magazzino ha un valore totale di %.2f\n", CalcoloValore(i,&articoli[i]));
                break;
        }
    }
}
