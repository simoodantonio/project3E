#include <iostream>
#include <time.h>
#include <random>

using namespace std;

void coutArray(int a[], int n) {
    cout<<"[";
    for (int i=0; i<n; i++) {
        cout<<a[i];
        if (i != n-1) cout<<", ";
    }
    cout<<"]";
}

void exchangeSort(int a[], int n);
void selectionSort(int a[], int n);

void bubbleSort(int a[], int n);
void bubbleSortSentinella(int a[], int n);
void bubbleSortSentinellaStop(int a[], int n);

void quickSort(int a[], int n);
void quickSort(int a[], int n, int inizio, int fine);

void mergeSort(int a[], int n);
void mergeSort(int a[], int inizio, int fine);
void merge(int a[], int inizio, int centro, int fine);

int main(int argc, char const *argv[]) {
    int n, k;

    cout<<"Inserire la grandezza dell'array: ";
    cin>>n;

    int a[n];

    srand(time(0));
    for (int i=0; i<n; i++) {
        a[i] = rand() % 100;
    }

    cout<<"Array non ordinato: ";
    coutArray(a, n);

    mergeSort(a, n);

    cout<<"\nArray ordinato: ";
    coutArray(a, n);

    return 0;
}

void exchangeSort(int a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=i+1; j<n; j++) {
			if (a[i] > a[j]) {
				int holder = a[i];
				a[i] = a[j];
				a[j] = holder;
			}
		}
	}
}

void selectionSort(int a[], int n) {
	for (int i=0; i<n-1; i++) {
		int posizioneMinimo = i;
		
		for (int j=i+1; j<n; j++) 
            if (a[posizioneMinimo] > a[j]) posizioneMinimo = j;
		
		if (posizioneMinimo != i) {
			int holder = a[i];
			a[i] = a[posizioneMinimo];
			a[posizioneMinimo] = holder;
		}
	}
}

void bubbleSort(int a[], int n) {
	for (int i=0; i<n-1; i++) {
		for (int j=0; j<n-1; j++) {
			if (a[j] > a[j+1]) {
				int holder = a[j];
				a[j] = a[j+1];
				a[j+1] = holder;
			}
		}
	}
}

void bubbleSortSentinella(int a[], int n) {
	bool scambio;

	do {
		scambio = false;
		for (int j=0; j<n-1; j++) {
			if (a[j] > a[j+1]) {
				int holder = a[j];
				a[j] = a[j+1];
				a[j+1] = holder;
				scambio = true;
			}
		}
	} while (scambio);
}

void bubbleSortSentinellaStop(int a[], int n) {
	int stop = n-1;
	bool scambio;

	do {
		scambio = false;
		for (int j=0; j<n-1; j++) {
			if (a[j] > a[j+1]) {
				int holder = a[j];
				a[j] = a[j+1];
				a[j+1] = holder;
				scambio = true;
			}
		}
		stop--;
	} while (scambio);
}

void quickSort(int a[], int n) {
    quickSort(a, n, 0, n);
}

void quickSort(int a[], int n, int inizio, int fine) {
	int pivot;

	if (inizio < fine) {
		pivot = inizio;
		int i = inizio;
		int j = fine;
		while (i < j) {
			while (a[i] <= a[pivot] and i < fine) i++;
			while (a[j] > a[pivot]) j--;
			if (i < j) {
				int holder = a[i];
				a[i] = a[j];
				a[j] = holder;
			}
		}
		int holder = a[pivot];
		a[pivot] = a[j];
		a[j] = holder;
		
		quickSort(a, (j-inizio), inizio, j-1);
		quickSort(a, (fine-j), j+1, fine);
	}
}

void mergeSort(int a[], int n) {
    mergeSort(a, 0, n);
}

void mergeSort(int a[], int inizio, int fine) {
    if (inizio < fine) {
        int centro = (inizio + fine) / 2;
        mergeSort(a, inizio, centro);
        mergeSort(a, centro+1, fine);
        merge(a, inizio, centro, fine);
    }
}

void merge(int a[], int inizio, int centro, int fine) {
    int i = inizio;
    int j = centro + 1;
    int k = 0;
    int b[fine - inizio + 1];

    while (i <= centro and j <= fine) {
        if (a[i] < a[j]) {
            b[k] = a[i];
            i++;
        } else {
            b[k] = a[j];
            j++;
        }
        k++;
    }

    while (i <= centro) {
        b[k] = a[i];
        i++;
        k++;
    }

    while (j <= fine) {
        b[k] = a[j];
        j++;
        k++;
    }

    for (k=inizio; k<=fine; k++) {
        a[k] = b[k-inizio];
    }
}
