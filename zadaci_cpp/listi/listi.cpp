/*1. Да се напишат потребните структури и функции за имплементирање на единечно поврзана
листа и поддршка на функции за креирање на листа со еден елемент, бришење и додавање на
елементи на почеток и крај на листата. Да се напише програма што ќе ги тестира сите фунции. */
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Jazol
{
int info;
Jazol *link;
};
struct EPLista
{
Jazol *head;
void init();
void kreirajLista(int el);
void dodadiPrv(int el);
void dodadiPosleden(int el);
void brishiPrv();
void brishiPosleden();
void pechatiLista();
void brishiLista();
};
void EPLista::init()
{
 head = NULL;
}
void EPLista::kreirajLista(int el)
{
 head = new Jazol;
 head->info = el;
 head->link = NULL;
}
void EPLista::dodadiPrv(int el)
{
Jazol *pom = new Jazol;
 pom->info = el;
 pom->link = head;
 head = pom;
}
void EPLista::dodadiPosleden(int el)
{
Jazol *dvizhi = head, *pom = new Jazol;
 pom->info = el;
if (head == NULL)
 head = pom;
else
 {
 while (dvizhi->link != NULL)
 dvizhi = dvizhi->link;
 dvizhi->link = pom;
 }
 pom->link = NULL;
 }
void EPLista::brishiPrv()
{
if (head != NULL)
 {
 if ((head)->link == NULL)
 {
 delete head;
 head = NULL;
 }
 else
 {
 Jazol *pom = head;
 head = head->link;
 delete pom;
 }
 }
}
void EPLista::brishiPosleden()
{
if (head != NULL)
 {
 if (head->link == NULL)
 {
 delete head;
 head = NULL;
 }
 else
 {
 Jazol *pom = head, *brishi;
 while (pom->link->link != NULL)
 pom = pom->link;
 brishi = pom->link;
 pom->link = NULL;
 delete brishi;
 }
 }
}
void EPLista::pechatiLista()
{
 cout << "Elementite vo listata se: ";
for (Jazol *pom = head; pom != NULL; pom = pom->link)
 cout << pom->info << '\t';
 cout << endl;
}
void EPLista::brishiLista()
{
while (head != NULL)
 brishiPosleden();
}
int main()
{
EPLista l1;
 l1.init();
 l1.dodadiPrv(1);
 l1.dodadiPosleden(7);
 l1.dodadiPosleden(8);
 l1.brishiPrv();
 cout << "Prviot jazol vo listata ima info pole " << l1.head->info << endl;
 l1.pechatiLista();
EPLista l2;
 l2.kreirajLista(2);
 l2.dodadiPosleden(4);
 l2.dodadiPosleden(5);
 l2.brishiPosleden();
 l2.pechatiLista();
 l1.brishiLista();
 l2.brishiLista();
 l1.pechatiLista();
 l2.pechatiLista();
return 0;
}
