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

class Ram{
    private:
        ll run;
        ll given;

    public:
        Ram(ll, ll);
        ll getRun();
        ll getGiven();
};

Ram::Ram(ll Run, ll Given){
    run=Run;
    given=Given;
}

ll Ram::getRun(){
    return run;
}

ll Ram::getGiven(){
    return given;
}

class Sorts{
    public:
        void mergeArray(vector<Ram*>&, vector<Ram*>&, ll, ll, ll);
        void mergeSplit(vector<Ram*>&, vector<Ram*>&, ll, ll);
        void mergeCopy(vector<Ram*>&, vector<Ram*>&, ll, ll);
        void mergeSort(vector<Ram*>&);
};

void Sorts::mergeArray(vector<Ram*>& A, vector<Ram*>& B, ll low, ll mid, ll high){
    ll fp=low, sp=mid+1;
    for(ll i=low; i<=high; i++){
        if(fp==mid+1){
            B[i]=A[sp];
            sp++;
        }else if(sp==high+1){
            B[i]=A[fp];
            fp++;
        }else{
            if(A[fp]->getRun()<A[sp]->getRun()){
                B[i]=A[fp];
                fp++;
            }else{
                B[i]=A[sp];
                sp++;
            }
        }
    }
}

void Sorts::mergeSplit(vector<Ram*>& A, vector<Ram*>& B, ll low, ll high){ 
    if(high-low<1){
        return;
    }
    ll mid=(low+high)/2;
    mergeSplit(A, B, low, mid);
    mergeSplit(A, B, mid+1, high);
    mergeArray(A, B, low, mid, high);
    mergeCopy(A,B, low, high);
}

void Sorts::mergeCopy(vector<Ram*>& A, vector<Ram*>& B, ll low, ll high){
    for(ll i=low; i<=high; i++){
        A[i]=B[i];
    }
}

void Sorts::mergeSort(vector<Ram*>& v1){
    vector<Ram*> v2(v1.size());
    mergeSplit(v1, v2, 0, v1.size()-1);
}

int main(){

    int q;
    cin>>q;
    for(int i=0; i<q; i++){
        int n, ram;
        cin>>n>>ram;
        vector<int> v;
        vector<Ram*> rams;
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux; v.push_back(aux);
        }
        for(int j=0; j<n; j++){
            int aux;
            cin>>aux;
            rams.push_back(new Ram(v[j], aux));
        }
        Sorts sort;
        sort.mergeSort(rams);

        int j=0;
        while(j<n && rams[j]->getRun()<=ram){
            ram+=rams[j]->getGiven();
            j++;
        }

        cout<<ram<<"\n";
    }

    cout<<"\n";
}