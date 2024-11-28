/*Edmundo Canedo Cervantes - A01645576 */
#include <bits/stdc++.h>
#define fore(i, l, r) for (long long i=(l); i < (r); i++)
#define forex(i, l, r) for (long long i=(l); i >= (r); i--)
#define ll long long
#define ull unsigned long long
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
 * @class Map
 * 
 * Contiene métodos y atributos para implementar un
 * mapa.
 */
template<class Key, class Value>
class Map{
    private:
        unsigned long size;
        unsigned long current;
        Key initialValue;

        Key* keys;
        Value* values;

        unsigned long hash(string);

    public:
        Map(unsigned long, Key);
        bool full();
        long getIndex(Key); 
        void put(Key, Value);
        Value get(Key);
};

/**
 * @brief Constructor del mapa.

 * @param Size Cantidad de elementos.
 * @param InitialValue Valor por defecto de la llave.
 */
template<class Key, class Value>
Map<Key, Value>::Map(unsigned long Size, Key InitialValue){
    size=Size;
    current=0;
    initialValue=InitialValue;
    keys=new Key[size];
    values=new Value[size];
    for(long i=0; i<size; i++){ //Inicializa las llaves y valores
        keys[i]=initialValue;
        values[i]=0;
    }
}

/**
 * @brief Encuentra el valor hash para una
 * llave dada. Tiene una complejidad temporal
 * de O(s).
 * 
 * @param id - La llave.
 * @return unsigned long - El valor del hash.
 */
template<class Key, class Value>
unsigned long Map<Key, Value>::hash(string id){
    unsigned long c=0;
    for(unsigned long i=0; i<id.size(); i++){
        c+=(int)id[i];
    }
    return c;
}

/**
 * @brief Checa si el mapa está lleno.
 * 
 * @return TRUE si el mapa está lleno | FALSO si el mapa
 * tiene espacios vacíos. 
 */
template<class Key, class Value>
bool Map<Key, Value>::full(){
    return current==size;
}

/**
 * @brief Obtiene el índice de un elemento
 * dependiendo de una llave. Tiene una complejidad
 * temporal de O(n).
 * 
 * Se da por sentado que el elemento SI existe en 
 * el mapa.
 * 
 * @param id La llave a buscar.
 * @return long - El índice del elemento.
 */
template<class Key, class Value>
long Map<Key, Value>::getIndex(Key id){
    long start=hash(id)%size;
	long i=start, x=1;
	if(keys[i]==id) return i;

	while(keys[i]!=id){ //Itera, en caso de regresar a donde se empezó regresa -1 porque no existe el elemento
		i=start+x*x;
        x++;
		i%=size;
	}

	return i;
}

/**
 * @brief Le añade un valor a un mapa vinculado
 * a una llave. Tiene una complejidad temporal
 * de O(n).
 * 
 * @param id La llave del valor.
 * @param val El valor.
 */
template<class Key, class Value>
void Map<Key, Value>::put(Key id, Value val){
    if(full()) return;

	long start=hash(id)%size;
	long i=start, x=1;

	while(keys[i]!=initialValue){ //Mientras la llave sea distinta al valor inicial, es decir, busca un índice vacío
		i=start+x*x;
        x++;
		i%=size;
	}

	keys[i]=id;
	values[i]=val;
	current++;
}

/**
 * @brief Obtiene el valor de un elemento dependiendo
 * de su llave. Tiene una complejidad temporal de O(n).
 * 
 * @param id La llave del elemento.
 * @return Value - El valor del elemento.
 */
template<class Key, class Value>
Value Map<Key, Value>::get(Key id){
    long pos=getIndex(id);
    return values[pos];
}

/**
 * @brief Normaliza las strings. Cambia las
 * mayúsculas por minúsculas.
 * 
 * @param s El string a normalizar.
 * @return string - El string normalizado.
 */
string normalize(string s){ 
    for(auto& i:s){
        if(i>='a' && i<='z') i-=('a'-'A');
    }
    return s;
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("input.txt", "r", stdin); //Elimina esta linea

    int a; cin>>a;
    int val=0;

    Map<string, int> users(250,"-");
    users.put(normalize("Polycarp"), 1);

    //map<string, int> users;
    //users[normalize("Polycarp")]=1;

    fore(i,0,a){
        string u1, u2, aux;
        cin>>u1>>aux>>u2;

        users.put(normalize(u1),users.get(normalize(u2))+1);
        val=max(val, users.get(normalize(u1)));

        //users[normalize(u1)]=users[normalize(u2)]+1;
        //val=max(val, users[normalize(u1)]);

    }

    cout<<val;

    cout<<"\n";
}