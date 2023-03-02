#include <iostream>
#include <string.h>
#include <list>
#include <bits/stdc++.h>
#include <cstdlib>
#include <time.h>
#include <winbgim.h>
#include <graphics.h

using namespace std;

ifstream fin ("New Text Document(3).txt");

int nrjuc;

struct carte{
    int val, tip, valj;
    carte *next;
}*pachet;

struct jucatori{
    int nrcastig=0;
    carte *mana=NULL;
}juc[10];

carte* generarePachet(){
    int v[52]={0},x,simb,val;
    int cr=52;
    carte* p=NULL,*q;
    while(cr>0){
        x=rand()%52;
        if(v[x]==0){
            v[x]=1;
            cr--;
            simb=x%4;
            val=x%13+1;
            if(val>10){
                val++;
            }
            q=new carte;
            q->tip=simb;
            q->val=val;
            if(q->val<10){
                q->valj=q->val;
            }
            else q->valj=10;
            q->next=p;
            p=q;
        }
    }
    return p;
}

void parcurgere(carte *p){
    while(p){
        cout<<p->tip<<" "<<p->val<<" "<<p->valj<<'\n';
        p=p->next;
    }
}
int calcTotal(carte *mana){
    int total=0;
    int asi=0;
    while(mana!=NULL) {
        total+=mana->valj;
        if(mana->val==1) {
            asi++;
        }
        mana=mana->next;
    }
    while(asi>0){
        if(total+10<=21) {
            total+=10;
        }
        asi--;
    }
    return total;
}

void joc(){
    carte *q;
    for(int i=1;i<=nrjuc;i++){
        juc[i].mana=NULL;
        for(int j=0;j<2;j++){
            q=pachet;
            pachet=pachet->next;
            q->next=juc[i].mana;
            juc[i].mana=q;
        }
        int total_jucator=0;
        while(juc[i].mana!=NULL){
            cout<<"Cartile jucatorului "<<i<<":"<<endl;
            parcurgere(juc[i].mana);
            cout<<endl;
            total_jucator=calcTotal(juc[i].mana);
            cout<<"Total: "<<total_jucator<<endl;
            if(total_jucator>21){
                cout<<"Ai pierdut! Punctajul tău este mai mare de 21!"<<endl;
                break;
            }
            char raspuns;
            do{
                cout<<"Doresti sa mai tragi o carte?";
                cin>>raspuns;
            }while(raspuns!='D' && raspuns!='d' && raspuns!='N' && raspuns!='n');
            if(raspuns=='D' || raspuns=='d'){
                q=pachet;
                pachet=pachet->next;
                q->next=juc[i].mana;
                juc[i].mana=q;
            }
            else{
                break;
            }
        }
    }
    while(juc[0].mana!=NULL) {
        int total=calcTotal(juc[0].mana);
        if(total<rand()%4+16) {
            q=pachet;
            pachet=pachet->next;
            q->next=juc[0].mana;
            juc[0].mana=q;
        }
        else{
            break;
        }
    }
    int dealerTotal=calcTotal(juc[0].mana);
    for(int i=1;i<=nrjuc;i++) {
        int total=calcTotal(juc[i].mana);
        if(total>21 || (total<=dealerTotal && dealerTotal <=21)) {
            juc[i].nrcastig--;
            juc[0].nrcastig++;
        }
        else{
            juc[i].nrcastig++;
            juc[0].nrcastig--;
        }
    }
}
void afisare();
{
    initwindow(1000, 1000, "Black Jack");
    setbkcolor(BLACK);
    setcolor(GREEN);
    
    settextstyle(7, 0, 5);
    outtextxy(200, 200, "Bine ati venit la joc!");
    outtextxy(200, 400, "Doresti sa joci?");
    outtextxy(250, 450, "Alege una dintre optiuni");
    
    getch();
    cleardevice();
    outtextxy(100, 200, "Cartile jucatorului");
    readimagefile(carte->valj, 100, 100, 300, 400);
    readimagefile(carte->val, 300, 100, 500, 400);
    
    getch();
    closegraph();
}
int main()
{
    char alegere;
    srand(time(NULL));
    cout<<"Introduceti numarul de jucatori: ";
    cin>>nrjuc;
    do{
        joc();
        for(int i=1;i<=nrjuc;i++){
            cout<<juc[i].nrcastig<<" "<<'\n';
        }
        cout<<juc[0].nrcastig<<" "<<'\n';
        cout<<"Jucam din nou?";
        cin>>alegere;
    }while(alegere=='d'|| alegere == 'D');
    return 0;
}
