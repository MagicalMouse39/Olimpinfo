using namespace std;

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
                i += jc;
                if (jc != 0)
                    continue;
                
                if (Magical.isTired())
                    Magical.goToSleep();
            }
            else
                sV[c++] = V[i];
            
        }
    }
}

void main() {
    this.conta();
}