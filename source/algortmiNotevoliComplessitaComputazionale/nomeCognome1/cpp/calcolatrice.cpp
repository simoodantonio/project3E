#include <iostream>

using namespace std;

int main(int argc, char const *argv[]) {
    int n1, n2, r; //3
    char o; //1
    
    cin>>n1>>o>>n2; //3

    switch (o) {
    case '+': //1
        r = n1 + n2; //1
        break;
    
    case '-': //1
        r = n1 - n2; //1
        break;

    case '*': //1
        r = n1 * n2; //1
        break;

    case '^': //1
        r = 1; //1
        for (int i=0; i<n2; i++) { // (1 + 1 + 1) * n2 + 1
            r *= n1; //1
        }
        break;
    }

    cout<<r; //1

    return 0;
}
