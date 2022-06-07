#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>
using namespace std;

string random_word();
string input_word();
void char_existe(char (&existe)[5], string palabra, string rand_word);
void return_existe(char (&existe)[5]);

int main()
{
    char bucle_game = 'S';
    while(bucle_game == 'S'){
    int intento = 1;
    string palabra;
    string word = random_word();
    cout<<"ADIVINE LA PALABRA"<<endl;
    while(intento <=5){
    cout<<"Intento "<<intento<<") "<<endl;
    palabra = input_word();
    char existe[5] = {'F', 'F', 'F' , 'F' , 'F' };
    char_existe(existe, palabra, word);
    return_existe(existe);
    intento++;
    cout<<endl<<endl;
    if(palabra == word){
        cout<<"Haz ganado el juego, y solo te tomo "<<intento-1<<" intentos. Felicidades, quieres jugar denuevo? (S = SI | CUALQ COSA = NO)"<<endl;
        cin>>bucle_game;
        system("cls");
        intento = 6;
    } //win
    }
    if(palabra != word && intento == 6){
        cout<<"Haz perdido el juego, la palabra era "<<word<<" quieres jugar denuevo? (S = SI | CUALQ COSA = NO)"<<endl;
        cin>>bucle_game;
    }
    } // loose
    return 0;
}


string random_word(){
    srand (time(NULL));
    string lista_palabras[3] = {"patos", "soñar", "reloj"};
    int tam = sizeof(lista_palabras)/sizeof(lista_palabras[0]);
    int palabra = rand() % tam;
    return lista_palabras[palabra];
}
string input_word(){
    string palabra;
    while(1 == 1){
    cin>>palabra;
    if(palabra.length() == 5){
        return palabra;
    }
    else{
        cout<<"la palabra debe tener 5 letras."<<endl;
    }
    }
}
void char_existe(char (&existe)[5],string palabra, string rand_word){
    int letra_localizada[5] = {};
    bool letra_posicion[5];
    for(int x = 0;x<5;x++){
        if(palabra[x] == rand_word[x]){
            existe[x] = 'V';
        }
        for(int y = 0;y<5;y++){
            if(rand_word[y] == palabra[x] && letra_localizada[y] == 0 && rand_word[y] != palabra[y]){


            existe[x] = 'E';
            letra_localizada[y]++;
        }
        }
    }
}
void return_existe(char (&existe)[5]){
    for(int x = 0;x<5;x++){
        cout<<existe[x];
    }
}
