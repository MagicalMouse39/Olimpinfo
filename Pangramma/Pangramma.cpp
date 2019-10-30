#include <iostream>
using namespace std;

int conta(int N, int K, int *V) {
    
    int panCounter = 0;
    for (int index = K; index < N; index++) { //Appurato
        
        int subV[index];
        int subCounter = 0;

        for (int i = 0; i < N; i++) { //    i = POSIZIONE IN V[]
            if (i != 0 && i % index == 0) { //    Ogni INDEX volte:
                subV[subCounter] = V[i];
                subCounter = 0;
                unsigned int KR[K];

                for (int j = 0; j < index; j++)
                    KR[subV[j]]++;
                
                int multicount = 0;
                int mulitiplier = 1;

                for (int j = 0; j < K; j++) {
                    if (KR[j] == 0)
                        multicount++;
                    if (multicount == 0)
                        mulitiplier *= KR[j];
                }

                if (multicount == 0)
                    panCounter += mulitiplier;

                i += multicount;

            }
            else
                subV[subCounter++] = V[i];
        }

        if (panCounter > 0)
            break;

    }

    return panCounter;
}


/*
int conta(int N, int K, vector<int>& V) {
    //K = Numero alfabeto
    //N = V.size();
    //Simboli = valori da 0 a K - 1
    //0 <= V[x] <= K - 1 per i 0...N - 1
    for (int index = K; index < N; index++) {
        
        int sV[index];
        int c = 0;
        
        for (int i = 0; i < N; i++) {
            if (i != 0 && i % index == 0) {
                sV[c] = V[i];
                c = 0;
                unsigned int KR[K];

                for (int j = 0; j < index; j++)
                    KR[sV[j]]++;
                
                int jc = 0;
                int mlt = 1;
                for (int j = 0; j < K; j++) {
                    if (KR[j] == 0)
                        jc++;
                    if (jc == 0)
                        mlt *= KR[j];
                }
                i += jc - 1;
            }
            else
                sV[c++] = V[i];
            
        }
    }
    */
int main() {
    int V[5] = {0,0,1,2,0};
    cout << conta(5, 3, V) << endl;
    return 0;
}