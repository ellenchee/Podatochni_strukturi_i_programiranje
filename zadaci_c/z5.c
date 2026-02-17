/*Да се напише програма која имитира поедноставена facebook апликација. Програмата
чува податоци за вашиот профил: facebook име, град, датум на раѓање, низаа од пријатели,
број на пријатели. Датумот на раѓање е од облик: ден, месец, година. За секој пријател
познати се следниве информации: facebook име, датум на раѓање и порака за ѕид.
1. Да се напишат функции со кои може да ги промените основните податоци за вашиот
профил: facebook име, град и датум на раѓање.
2. Да се напише функција со која прифаќате пријател и го додавате во низата од
пријатели, но само доколку бројот на пријатели не го надминува максимално дозволениот
број (5000 пријатели) и соодветно го менувате вашиот број на пријатели.
3. Да се напише функција со која бришете пријател (според facebook име) од низата на
пријатели и соодветно го менувате вашиот број на пријатели.
4. Да се напише функција со која им честитате роденден (менувајќи го членот – порака за
ѕид) на сите пријатели кои се родени на датумот кој се проследува како аргумент на
функцијата.
-> Да се напише главна програма која ги тестира горенаведените функции.*/
#include <stdio.h>
typedef struct Datum {
    int den;
    int mesec;
    int godina;
    }Datum;
typedef struct Prijatel {
    char fbime[30];
    Datum datumPrijatel; /*променлива од една структура може да е член во друга структура*/
    char poraka[100];
    }Prijatel;
typedef struct Profil {
    char fbime[30];
    char grad[15];
    Datum fbdatum;
    Prijatel listaPrijateli[5000]; /* низа од променливи од една структура како член во друга структура */
    int brPrijateli;
    }Profil;
/* во продолжение едноставни функции кои ги менуваат членовите во структурата Profil */
void smeniIme(Profil *prof) /* пренесувањето по покажувач штеди меморија! */
    {
        printf("Vnesete go novoto facebook ime\n"); fflush(stdout);
        gets(prof->fbime);
        printf("Vaseto facebook ime e smeneto\n"); fflush(stdout);
    }
void smeniGrad(Profil *prof)
    {
        printf("Vnesete go imeto na vasiot grad\n"); fflush(stdout);
        gets(prof->grad);
        printf("Imeto na vasiot grad e smeneto\n"); fflush(stdout);
    } 
void smeniDatum(Profil *prof)
    {
        printf("Vnesete den\n"); fflush(stdout);
        scanf("%d", &(prof->fbdatum.den));
        printf("Vnesete mesec\n");
        scanf("%d", &(prof->fbdatum.mesec)); fflush(stdout);
        printf("Vnesete godina\n"); fflush(stdout);
        scanf("%d", &(prof->fbdatum.godina));
        printf("Datumot na ragjanje e smenet\n"); fflush(stdout);
    }
void dodadiPrijatel(Profil *prof, Prijatel novPrijatel)
    {
        if (prof->brPrijateli > 5000) 
        {
            printf("Ne mozete da dodadete prijatel\n"); fflush(stdout);
        }
        else
        {
            prof->listaPrijateli[prof->brPrijateli] = novPrijatel;
            /* даме нов пријател на последно место во низата listaPrijateli */
            (prof->brPrijateli)++;
            /* и соодветно го зголемуваме бројот на пријатели за еден */
            printf("Imate eden nov prijatel\n"); fflush(stdout);
        }
    }
void brisiPrijatel(Profil *prof, char fbimePrijatel[])
    {
        int i, j, najden = 0;
        for (i = 0; i < prof->brPrijateli; i++)
            {
                if (!strcmp(fbimePrijatel, prof->listaPrijateli[i].fbime))
                {
 /* сите пријатели после најдениот пријател ги поместуваме за едно место
во лево */
        for (j = i; j < prof->brPrijateli - 1; j++)
        prof->listaPrijateli[j] = prof->listaPrijateli[j + 1];
        (prof->brPrijateli)--;
        najden = 1;
        break;
 /* избришавме еден пријател */
                }
    }
    if (!najden) 
    { /* или if (i == prof->brPrijateli) */
        printf("Vo vashata lista na prijateli ne postoi prijatel so ime %s \n",
        fbimePrijatel); fflush(stdout);
    }
    else 
    {
        printf("Prijatelot so ime %s e izbrisan od vasata lista na prijateli\n",
        fbimePrijatel); fflush(stdout);
    }
    }
void cestitaj(Profil *prof, Datum rodenden)
    {
        int i;
        for (i = 0; i < prof->brPrijateli; i++)
        { /* ги изминуваме сите пријатели во низата listaPrijateli и ги бараме оние кои се
            родени на денот и месецот кој го пренесуваме во променливата rodenden */
            if ((rodenden.den == prof->listaPrijateli[i].datumPrijatel.den) &&
                (rodenden.mesec == prof->listaPrijateli[i].datumPrijatel.mesec))
                {
                    strcpy(prof->listaPrijateli[i].poraka, "Srekjen rodenden!!!");
                    printf("Cestitavte rodenden na %s\n", prof->listaPrijateli[i].fbime);
                    fflush(stdout);
                }
        }
    } 
void pechatiProfil(const Profil *prof) /*пренос по покажувач за заштеда на меморија, структурата Профил зафаќа многу меморија, проверете со sizeof*/
    {
        int i;
        printf("Podatoci za profilot:\n"); fflush(stdout);
        printf("Ime: %s\n", prof->fbime); fflush(stdout);
        printf("Grad: %s\n", prof->grad); fflush(stdout);
        printf("Datum na ragjanje: %-2d.%-2d.%-4d\n", prof->fbdatum.den, prof->fbdatum.mesec, prof->fbdatum.godina); fflush(stdout);
        printf("Prijateli:\n"); fflush(stdout);
        for (i = 0; i < prof->brPrijateli; i++) 
        {
            printf("%-15s\n", prof->listaPrijateli[i].fbime); fflush(stdout);
        }
            printf("\n");
    }
int main()
{
    Profil mojprofil = { "DonnaP", "Skopje", { 28,12,1986 }, { { "HarveyS", { 2,2,1986 }, "" }, { "RachelZ", { 20,5,1987 }, "" }, { "LouisL", { 15,3,1978 }, "" } }, 3 };
    Prijatel nov;
    pechatiProfil(&mojprofil);
    smeniIme(&mojprofil);
    pechatiProfil(&mojprofil);
    printf("Dodavam nov prijatel\n"); fflush(stdout);
    printf("Vnesete go imeto na vasiot nov prijatel\n"); fflush(stdout);
    scanf("%s", nov.fbime);
    printf("Vnesete go datumot (den, mesec i godina) na ragjanje na vashiot nov prijatel\n"); fflush(stdout);
    scanf("%d%d%d", &(nov.datumPrijatel.den), &(nov.datumPrijatel.mesec), &(nov.datumPrijatel.godina)); fflush(stdout);
    printf("Vnesete poraka za zid za vasiot nov prijatel\n"); fflush(stdout);
    scanf("%s", nov.poraka);
    dodadiPrijatel(&mojprofil, nov);
    pechatiProfil(&mojprofil);
    brisiPrijatel(&mojprofil, "RachelZ");
    pechatiProfil(&mojprofil);
    return 0;
} 