/*Од тастатура се читаат непознат број податоци за студенти. Податоците се внесуваат така што во
секој ред се дава:
- име,
- презиме,
- број на индекс (формат xxx/yy), и
- четири броја (поени од секоја задача)
со произволен број празни места или табулатори меѓу нив. Да се напише програма која ќе
испечати список на студенти, каде во секој ред ќе има: презиме, име, број на индекс, вкупен број
на поени од четирите задачи, сортиран според вкупниот број на поени. Имињата и презимињата
да се напишат со голема почетна буква. */

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
struct Student
    {
        char ime[15];
        char prezime[20];
        int index[2]; /* бројот и годината од индексот во низа од два елементи */
        int poeni; /* овде ќе биде сместен вкупниот број на поени од четирите задачи*/
    };
void pochetnaGolema(char *s);
void sortiraj(struct Student a[], int n);
int main()
    {
        struct Student st[50];
        char imeprez[36];
        int i, rbr = 0, zadaca[4];
        for (;;)
        {
            i = scanf("%s %s %d/%d %d %d %d %d\n", &st[rbr].ime, &st[rbr].prezime,
            &st[rbr].index[0], &st[rbr].index[1], &zadaca[0], &zadaca[1], &zadaca[2], &zadaca[3]);
            if (i != 8) break;
            else
            {
                pochetnaGolema(st[rbr].ime);
                pochetnaGolema(st[rbr].prezime);
                st[rbr].poeni = 0;
                for (i = 0; i < 4; i++) st[rbr].poeni += zadaca[i];
                rbr++;
            }
        }
        sortiraj(st, rbr);
        for (i = 0; i < rbr; i++)
        {
            strcpy(imeprez, st[i].prezime); /* формираме едниствен стринг кој ги чува презимето и името */
            strcat(imeprez, " "); /* функцијата strcat(char *vo, char *od) ја прилепува содржината на стрингот od кон стрингот vo */
            strcat(imeprez, st[i].ime);
            printf("%3d. %-35s %3d/%2d %4d\n", i + 1, imeprez, st[i].index[0], st[i].index[1], st[i].poeni);
        }
        return 0; 
    }
void pochetnaGolema(char *s)
    {
        *s = toupper(*s);
        while (*++s != '\0')
        *s = tolower(*s);
    }
void sortiraj(struct Student a[], int n)
    {
        int i, j;
        struct Student s;
        for (i = 0; i < n; i++)
        for (j = 0; j < n - i - 1; j++)
        if (a[j].poeni < a[j + 1].poeni)
        {
            s = a[j];
            a[j] = a[j + 1];
            a[j + 1] = s;
        }
    } 