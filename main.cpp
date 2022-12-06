#include <iostream>
#include <string>
using namespace std;
#define STATE_OFF 1 // wylaczone jest urzadzonko
#define STATE_IDLE 2 // standard stan spoczynku

#define STATE_WCZYTAJ 11 // plyta moze byc wczytana lub
#define STATE_WYSUN 10 // wysunieta
#define STATE_PLAYING 3// Plyta ma odwarzac obraz

int state = STATE_IDLE;
int plyta{};
int odpowiedz{};
string film{};

int spoczynek();
int wczytywanie();
int wysun();
int play();
//***********************************************

int main(int argc, const char * argv[]) {
    cout<<"Gratulacje jestes w programie napisanym przez jakiegos 2head'a :))) \n";
    do{
        switch (state) {
            case STATE_IDLE:
                spoczynek();
                break;
                
            case STATE_WCZYTAJ:
                wczytywanie();
                break;
                
            case STATE_WYSUN:
                wysun();
                break;
                
            case STATE_PLAYING:
                play();
                break;
                
        default: state = STATE_OFF;
        }
    }while(state != STATE_OFF);
return 0;
}
//***********************************************
int spoczynek(){
  
        do{
            cout<<"Co chcesz zrobic :\n\t1. Wlozyc plyte\n\t2. Wylacz urdzadzenie\nOdpowiedz :";
            cin>>odpowiedz;
        }while(!(odpowiedz==1 || odpowiedz==2));
        if(odpowiedz == 1)
            state = STATE_WCZYTAJ;
        else if(odpowiedz == 2)
            state = STATE_OFF;
    
    return 0;
}

int wczytywanie(){

    do{
        cout<<"Chcesz wczytac plyte zatem wybierz film :\n\t1. Slub wujka Zbyszka z ciocia Mirka\n\t2. Ufo Porno\nZatem co chcesz obejrzec :";
        cin>>odpowiedz;
    }while(!(odpowiedz==1 || odpowiedz==2));
    
    if(odpowiedz == 1 || odpowiedz == 2){
        if(odpowiedz==1)
            film = "SLUB";
        else if(odpowiedz==2)
            film = "UFO";
        cout<<"Wybrales film zatem sprobujmy go odtworzyc !!! \n";
        state = STATE_PLAYING;
    }
    else
        state = STATE_IDLE;
        
    return 0;
}

int wysun(){
    cout<<"Wlasnie wysuwamy *"<<film<<"* \n";
    state = STATE_IDLE;
    return 0;
}

int play(){
    do{
        cout<<"Wlasnie ogladasz *"<<film<<"* \n Zapewnie juz go obejrzales zatem co robimy dalej szefie\n\t1. Ogladamy ponownie\n\t2. Wysuwamy plyte\n Co robimy :";
        cin>>odpowiedz;
    }while(!(odpowiedz==1 || odpowiedz==2));
    if(odpowiedz==1)
        state = STATE_PLAYING;
    else if (odpowiedz==2)
        state = STATE_WYSUN;
    return 0;
}
