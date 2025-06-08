#include <bits/stdc++.h>
#include "PDA.h"
using namespace std;

int main() {

    // Create an empty dictionary using unordered_map
    T_PRODUCTIONS dict;

    // Insert key-value pairs
    // dict[pair<char, char>("cpp", "1")] = "C++";
    // dict["py"] = "Python";
    // dict["j"] = "Java";

    // cout << "\nOq eu quero: " << dict["cpp"];
    // Inserir pares chave-valor
    dict[T_PAIR('c', 'p')] = "C++";
    dict[T_PAIR('p', 'y')] = "Python";
    dict[T_PAIR('j', 'v')] = "Java";

    cout << "teste" << dict[T_PAIR('c', 'p')] << "\n";

    PDA pda;

    pda.set_productions(dict);
    pda.test();

    return 0;
}