/*Edmundo Canedo Cervantes - A01645576 */
#include <bits/stdc++.h>
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define forex(i, l, r) for (long long i = (l); i >= (r); i--)
#define nl cout<<"\n"
#define cnl "\n"
#define rfc "\033[31;1m"
#define gfc "\033[32;1m"
#define yfc "\033[33;1m"
#define bfc "\033[34;1m"
#define pfc "\033[35;1m"
#define cfc "\033[36;1m"
#define nfc "\033[0m"
#define pb push_back
using namespace std;

/**
 * @class RAM
 * 
 * Declaración de la clase RAM, la cuál
 * contiene los datos del programa que da
 * más ram.
 */
class Ram{
    private:
        int run;
        int given;

    public:
        Ram(int, int);
        int getRun();
        int getGiven();
};

/**
 * @brief Constructor del RAM.
 * 
 * @param Run La cantidad de RAM necesaria 
 * para ejecutar el programa.
 * @param Given La cantidad de RAM que regresa
 * el programa después de su ejecución.
 */
Ram::Ram(int Run, int Given){
    run=Run;
    given=Given;
}

/**
 * @brief Regresa la cantidad de RAM
 * necesaria para ejecutar el programa.
 * 
 * @return int - El valor del RAM.
 */
int Ram::getRun(){
    return run;
}

/**
 * @brief Regresa la cantidad de RAM
 * regresada al terminar la ejecución del
 * programa.
 * 
 * @return int - El valor del RAM.
 */
int Ram::getGiven(){
    return given;
}

/**
 * @brief Clase que contiene el método
 * para el ordenamiento de los programas.
 */
class Sorts{
    public:
        void shellSort(vector<Ram*>&);
};

/**
 * @brief Ordena los programas dependiendo del RAM
 * que ocupan para su ejecución. Tiene una complejidad
 * temporal de O(n(log(n))^2), lo que lo hace más rápido
 * que los que tienen O(n^2).
 * 
 * @param v El vector a ordenar.
 */
void Sorts::shellSort(vector<Ram*> &v){
    int gap = v.size() / 2;

    while(gap>0){
        for(int i=gap; i<v.size(); i++){
            for(int j=i; j>=gap && v[j]->getRun()<v[j-gap]->getRun(); j-=gap){
                swap(v[j], v[j-gap]);
            }
        }
        gap/=2;
    }
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int q; //Número de casos
    cin>>q;

    for(int i=0; i<q; i++){
        int n, ram;
        cin>>n>>ram;
        vector<int> v; //Solo guarda los datos para meterlos posteriormente en el de RAM
        vector<Ram*> rams;

        for(int j=0; j<n; j++){
            int aux;
            cin>>aux; v.push_back(aux);
        }
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux;
            rams.push_back(new Ram(v[j], aux)); //Incluyo el valor de ejecución (vector pasado) y el que regresa al final (valor leído)
        }
        Sorts sort;
        sort.shellSort(rams); //Se ordena dependiendo del valor de ejecución

        int j=0;
        while(j<n && rams[j]->getRun()<=ram){ //Mientras el RAM actual me permita ejecutar el siguiente programa
            ram+=rams[j]->getGiven(); //Le añado el RAM que regresa el programa
            j++;
        }

        cout<<ram<<"\n";
    }

    cout<<"\n";

    return 0;
}