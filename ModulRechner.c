#include <stdio.h>
#include <stdlib.h>

double durchschnitt(double* noten, int* wertungen, int module){
  int i;
  double holder = 0, durchschnitt = 0;
  int totwert = 0;

  //Durschnitt wird errechnet
  for (i = 0; i < module; i++){
      holder = holder + (*(noten+i) * *(wertungen+i));
      //printf("%lf", holder);
      totwert = totwert + *(wertungen+i);
     }
  durchschnitt = (holder/totwert);

  return durchschnitt;
}



//MAIN
int main(void){

int module = 7;
double middle;
//Array definieren
double noten[20];
int wert[20];
int i, k, l;
//reachedcredits and totalcredits
int rcreds = 0;
int tcreds = 0;


//Willkommen und Module einlesen
printf("\n\n\nHerzlich Willkommen\n");
printf("Bitte geben Sie zuerst die Anzahlmodule ein\n");
scanf("%d", &module);

printf("Bitte geben Sie jeweils die Modulnote und die Modulwertung an\n");

  //Einleseschleife
  for (i = 0; i < module; i++){
    printf("%d.Note: ", i+1);
    scanf("%lf", &noten[i]);
    printf("Credits: ");
    scanf("%d", &wert[i]);
    printf("\n");
  }

//Ausgabe Liste
  for (k = 0; k < module; k++) {
    printf("Die %d.te Note: %.2f", k+1 , noten[k]);
    printf(" zählt %d Credits\n", wert[k]);
   }

//Credits berechnen
for (l = 0; l < module; l++){
    tcreds = wert[l] + tcreds;
    if (noten[l] > 4){
        rcreds = rcreds + wert[l];
    }
}

//durchschnitt
printf("\n\nDurchschnitt: %.2lf\n",durchschnitt(noten, wert, module));
//anzahl credits
printf("Sie haben %d von %d Credits erreicht\n\n\n\n", rcreds, tcreds);


return 0;
}
