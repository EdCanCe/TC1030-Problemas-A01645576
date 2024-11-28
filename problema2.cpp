/*Edmundo Canedo Cervantes - A01645576 */
#include <bits/stdc++.h>
#define fore(i, l, r) for (long long i = (l); i < (r); i++)
#define forex(i, l, r) for (long long i = (l); i >= (r); i--)
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

template <class T> class Deque; //Declaración anticipada

/**
 * @class Node
 * 
 * Declaración de la clase Node, la cuál
 * es usada para declarar los elementos
 * del deque.
 */
template <class T>
class Node{
    private:
        T value;
        Node* prev;
        Node* next;

        Node(T);
        Node(T, Node*, Node*);

    friend class Deque<T>; //Clase amiga
};

/**
 * @brief Constructor de un Nodo.
 * 
 * @param val EL valor que va a tener el nodo.
 */
template <class T>
Node<T>::Node(T val){
    value=val;
    prev=0;
    next=0;
}

/**
 * @class Deque
 * 
 * Declaración de la clase Deque, la cual
 * maneja los diferentes nodos para su inserción,
 * acceso y eliminación.
 */
template <class T>
class Deque{
    private:
        int size;
        Node<T>* head;
        Node<T>* tail;

    public:
        Deque();
        bool empty();
        T back();
        void pop_back(); 
        void push_back(T);
        T front();
        void pop_front();
        void push_front(T);
};

/**
 * @brief Constructor del Deque.
 */
template <class T>
Deque<T>::Deque(){
    size=0;
    head=0;
    tail=0;
}

/**
 * @brief Verifica si el Deque está vacís.
 * 
 * @return TRUE - El Deque está vacío | FALSE
 *  - El Deque tiene alguno o varios elementos.
 */
template <class T>
bool Deque<T>::empty(){
    return size==0;
}

/**
 * @brief Regresa el valor trasero del Deque.
 * Tiene una complejidad temporal de O(1).
 */
template <class T>
T Deque<T>::back(){
    return tail->value;
}

/**
 * @brief Elimina el valor trasero del Deque.
 * Tiene una complejidad temporal de O(1).
 */
template <class T>
void Deque<T>::pop_back(){
    if(empty()) return;
    size--;
    if(size==0){
        head=0;
        tail=0;
    }else{
        Node<T>* aux=tail->next;
        tail=aux;
    }
}

/**
 * @brief Añade un elemento a la parte trasera
 * del Deque. Tiene una complejidad temporal 
 * de O(1).
 * 
 * @param val El valor a añadir.
 */
template <class T>
void Deque<T>::push_back(T val){
    size++;
    if(size==1){
        tail=new Node(val);
        head=tail;
    }else{
        Node<T>* aux=new Node(val);
        tail->next=aux;
        aux->prev=tail;
        tail=aux;
    }
}

/**
 * @brief Regresa el valor frontal del Deque.
 * Tiene una complejidad temporal de O(1).
 */
template <class T>
T Deque<T>::front(){
    return head->value;
}

/**
 * @brief Elimina el valor frontal del Deque.
 * Tiene una complejidad temporal de O(1).
 */
template <class T>
void Deque<T>::pop_front(){
    if(empty()) return;
    size--;
    if(size==0){
        tail=0;
        head=0;
    }else{
        Node<T>* aux=head->prev;
        head=aux;
    }
}

/**
 * @brief Añade un elemento a la parte frontal
 * del Deque. Tiene una complejidad temporal 
 * de O(1).
 * 
 * @param val El valor a añadir.
 */
template <class T>
void Deque<T>::push_front(T val){
    size++;
    if(size==1){
        head=new Node(val);
        tail=head;
    }else{
        Node<T>* aux=new Node(val);
        head->next=aux;
        aux->prev=head;
        head=aux;
    }
}

/**
 * @brief Imprime la dirección que marca
 * el Deque. Tiene una complejidad temporal
 * de O(n).
 * 
 * @param directory La dirección.
 * @return string - La dirección en formato
 * de cadena.
 */
string pwd(Deque<string> directory){
    stringstream s;
    s<<"/";
    while(!directory.empty()){
        s<<directory.back();
        directory.pop_back();
        s<<"/";
    }
    return s.str();
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin>>n; //La candidad de comandos

    Deque<string> directory, aux;

    for(int i=0; i<n; i++){
        string op;
        cin>>op;
        if(op=="pwd") cout<<pwd(directory)<<"\n"; //Checa si imprime o modifica la dirección
        else{
            cin>>op;
            stringstream chars;
            chars<<op;
            char c;
            op=""; //Va guardando la carpeta de ese momento
            bool pass=false;
            while(chars>>c){
                if(pass==false && c=='/'){ //Si el primer caracter es / resetea la dirección
                    directory=aux; 
                }
                pass=true; //Indica que ya NO es el primer caracter
                if(c!='/') op+=c; //Mientras no sea una /, completa la carpeta
                else{
                    if(op==".."){ //Se regresa una carpeta
                        if(!directory.empty()) directory.pop_front();
                    }
                    else if(op.size()!=0) directory.push_front(op); //Añade una carpeta
                    op=""; //Resetea la carpeta
                }
            }
            if(op==".."){ //Se regresa una carpeta
                if(!directory.empty()) directory.pop_front();
            }
            else if(op.size()!=0) directory.push_front(op); //Añade una carpeta
        }
    }

    cout<<"\n";
}