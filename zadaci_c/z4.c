/*Креирајте текстуална датотека Podatoci.txt во следниов формат:
 [prezime]…[ime]…[bod1]…[bod2]
каде:
- колоната [prezime] зафаќа 15 места;
- колоната [ime] зафаќа 10 места;
- колоната [bod1] и [bod2] зафаќаат по 4 места и претставуваат број на поени освоени на прв и
втор колоквиум, соодветно. (при внесување на податоци во датотеката Podatoci.txt внимавајте на
местата кои ги зафаќаат колоните).
Напишете програма која ја чита содржината на датотеката Podatoci.txt и според податоците во
неа ќе креира нова датотека, Polozhile.txt во која треба да се наоѓа список само на оние
студенти кои го положиле испитот, сортиран според бројот на вкупни поени (се смета дека
испитот е положен ако од двата колоквиуми се освоени по минимум 30 поени, a вкупниот број на
поени е минимум 100).
Датотеката Polozhile.txt содржи податоци во следниов формат:
 [prezime]…[ime]…[vkupno] */
#include <stdio.h>
#include <stdlib.h>
typedef struct Student 
    {
        char prezime[15];
        char ime[10];
        int prv;
        int vtor;
    } Student;
int main()
{
    FILE *Vlez, *Izlez;
    Student podatoci[15]; /* претпоставуваме дека во влезната датотека нема повеќе од 15 податоци за студенти */
    Student pom;
    int i = 0, j, k;
    if ((Vlez = fopen("Podatoci.txt", "r")) == NULL)
    {
        printf("Greska pri otvaranje na datotekata");
        exit(1);
    }
    Izlez = fopen("Polozhile.txt", "w");
/*
 Ги читаме податоците од влезната датотека и ги сместуваме во низата podatoci.
 Променливата i го означува бројот на студенти кои го положиле испитот.
 */
    while (fscanf(Vlez, "%15s%10s%4d%4d", &podatoci[i].prezime, &podatoci[i].ime, &podatoci[i].prv, &podatoci[i].vtor) != EOF)
    {
        if ((podatoci[i].prv >= 30) && (podatoci[i].vtor >= 30) && (podatoci[i].prv + podatoci[i].vtor >= 100))
        {
            podatoci[i].prv += podatoci[i].vtor; /* во podatoci[i].prv сега ќе биде сместен вкупниот број на поени */
            i++;
        }
    } 
 /* Со SimpleSort ги сортираме елементите од низата studenti, според вкупниот број на поени */
    for (j = 0; j < i - 1; j++)
        for (k = j + 1; k < i; k++)
            if (podatoci[k].prv > podatoci[j].prv)
            {
                pom = podatoci[j];
                podatoci[j] = podatoci[k];
                podatoci[k] = pom;
            }
/* Сортираните податоци ги запишуваме во излезна датотека */
    for (j = 0; j < i; j++)
        fprintf(Izlez, "%-15s%-10s%-4d\n", podatoci[j].prezime, podatoci[j].ime, podatoci[j].prv);
        fclose(Vlez);
        fclose(Izlez);
    return 0;
} 