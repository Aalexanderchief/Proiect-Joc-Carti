#include <iostream>
#include <string.h>
#include <list>
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
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
    curent->next=nou;
}

int calculare(nod *cap){
    int total=0;
    int asi=0;
    nod *curent=cap;
    while(curent!=NULL){
        int valoare=curent->carte%13+1;
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
    cout<<"Total: "<<calculare(mana_jucator)<<endl;
    cout<<"Mana dealurului:"<<endl;
    cout<<mana_dealer->carte<<endl;
    cout<<"Carte Ascunsa"<<endl;
    while(calculare(mana_jucator)<21) {
        char action;
        cout<<"Hit or stand?";
        cin>>action;
        if(action=='h'){
            random_(mana_jucator);
            cout<<"Mana jucatorului:"<<endl;
            curent=mana_jucator;
            while(curent!=NULL) {
                cout<<curent->carte<<endl;
                curent=curent->next;
            }
            cout<<"Total: "<<calculare(mana_jucator)<<endl;
        }
        else{
            break;
        }
    }
    while(calculare(mana_dealer)<17) {
        random_(mana_dealer);
        cout<<"Mana dealurului:"<<endl;
        curent=mana_dealer;
        while(curent!=NULL) {
            cout<<curent->carte<<endl;
            curent=curent->next;
        }
        cout<<"Total: "<<calculare(mana_dealer)<<endl;
    }

    int jtotal=calculare(mana_jucator);
    int dtotal=calculare(mana_dealer);
    if(jtotal>21) {
        cout<<"Ai pierdut."<< endl;
    }
    else if(dtotal>21) {
        cout<<"Ai castigat." << endl;
    }
    else if(jtotal>dtotal){
        cout<<"Ai castigat." << endl;
    }
    else if(dtotal>jtotal){
        cout<<"Ai pierdut."<<endl;
    }
    else{
        cout<<"Push. Nimeni nu a castigat."<<endl;
    }
}

int main()
{
    srand(time(NULL));
    char alegere;
    do{
        BlackJack();
        cout<<"Play again? (y/n):";
        cin>>alegere;
    }while(alegere=='y');
    return 0;
}
