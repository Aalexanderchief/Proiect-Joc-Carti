#include <iostream>
#include <string.h>
#include <list>
#include <bits/stdc++.h>
#include <cstdlib>
using namespace std;
struct nod{
    int carte;
    nod *next;
};

void random_(nod *&cap){
    int tragere=rand()%52;
    nod *nou=new nod;
    nou->carte=tragere;
    nou->next=NULL;
    if(cap==NULL){
        cap=new nod;
    }
    nod *curent=cap;
    while(curent->next!=NULL){
        curent=curent->next;
    }
    curent->next=new nod;
}

int calculare(nod *cap){
    int total=0;
    int asi=0;
    nod *curent=cap;
    while(curent!=NULL){
        int valoare=curent->carte %13 +1;
        if(valoare>10){
            valoare=10;
        }
        if(valoare==1){
            asi++;
        }
        total+=valoare;
        curent=curent->next;
    }
    while(total<=11 && asi>0){
        total+=10;
        asi--;
    }
    return total;
}

void BlackJack(){
    nod *mana_jucator=NULL;
    nod *mana_dealer=NULL;
    random_(mana_jucator);
    random_(mana_dealer);
    random_(mana_jucator);
    random_(mana_dealer);
    cout<<"Mana jucatorului: "<<'\n';
    nod *curent=mana_jucator;
    while(curent!=NULL){
        cout<<curent->carte<<'\n';
        curent=curent->next;
    }
    cout<<"Totalul jucatorului: "<<calculare(mana_jucator)<<'\n';
    cout<<"Mana dealurului: "<<mana_dealer->carte<<" si "<<mana_dealer->next->carte<<'\n';
    cout<<"Totalul dealurului: "<<calculare(mana_dealer);
}

int main()
{

    return 0;
}
