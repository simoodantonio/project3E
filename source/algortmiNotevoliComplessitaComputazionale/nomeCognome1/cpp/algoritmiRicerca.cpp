#include <iostream>

using namespace std;

int ricercaCompleta(int a[], int n, int k);
int ricercaBinaria(int a[], int n, int k);

int main(int argc, char const *argv[]) {
    int n, k;

    cout<<"Inserire la grandezza dell'array: ";
    cin>>n;

    int a[n];

    for (int i=0; i<n; i++)
        a[i] = i;
    
    
    cout<<"Inserire il valore da trovare: ";
    cin>>k;

    cout<<"Valore trovato in posizione "<<ricercaCompleta(a, n, k);
    cout<<"\nValore trovato in posizione "<<ricercaBinaria(a, n, k);

    return 0;
}

int ricercaCompleta(int a[], int n, int k) {
    for (int i=0; i<n; i++) {
        if (a[i] == k) return i;
    }
    return -1;
}

int ricercaBinaria(int a[], int n, int k) {
    int sx = 0, dx = n;
    
    while (sx <= dx) {
        int m = (sx + dx) / 2;
        if (k > a[m]) sx = m+1;
        else if (k < a[m]) dx = m-1;
        else return m;
    }

    return -1;
}