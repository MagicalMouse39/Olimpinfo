#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <vector>
#include <sys/time.h>

#define DEBUG false

using namespace std;

int conta(int N, int K, vector<int>& V)
{
	int panC = 0;
	for (int index = K; index <= N; index++)
	{
		for (int num = 0; num <= N - index; num++)
		{
			int values[K] = { };
			bool found = true;
			
			for (int i = 0; i < index; i++)
			{
#if DEBUG
				cout << "values[" << V[num + i] << "]++" << endl;
#endif
				values[V[num + i]]++;
			}
			
			for (int i = 0; i < K; i++)
			{
#if DEBUG
				cout << values[i] << (i == index - 1 ? "" : ":");
#endif
				if (values[i] == 0)
					found = false;
			}

#if DEBUG
			cout << "    " << (found ? "true" : "false") << endl;
#endif
			
			if (found)
				panC++;
		}
		
		if (panC > 0)
			break;
	}
	
	return panC;
}

int main()
{
    // Input da file:
    // freopen("input.txt", "r", stdin);

    // Output su file:
    // freopen("output.txt", "w", stdout);
    size_t n, k;
    cin >> n >> k;
    vector<int> v(n);
    for(size_t i = 0; i < n; i++)
        cin >> v[i];
        
    struct timeval tp;
	gettimeofday(&tp, NULL);
	long int ms = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << endl << endl << "Risultato: " << conta(n, k, v) << endl;
	gettimeofday(&tp, NULL);
	long int ms2 = tp.tv_sec * 1000 + tp.tv_usec / 1000;
    cout << "Millisecondi impiegati: " << ms2 - ms << endl;
    return 0;
}
