/*
 * Trabalho 2 - GEX101 - Linguagens Formais e Autômatos - 2025/1
 *
 * Nome:      Daniele Rohr
 * Matricula: 2121101060
 * 
 * Nome:      Eduardo Fiorentin
 * Matricula: 2211100002
 */

#include <bits/stdc++.h>
#include "PDA.h"
using namespace std;

int main() {

    T_PRODUCTIONS dict;
    string w;
    char states[] =         {'a', 'b', 'c', 'd', 'e'};
    char final_states[] =   {'e'};
    char alphabet[] =       {'#', 'A', 'T', 'C', 'G'};

    // T_TUPLE(est_atual, string, leitura_pilha)
    // T_NEXT(prox_estado, grava_pilha)
    
    // transições 
    // transição a(qo) -> b(q1)
    dict[T_TUPLE('a', ' ', ' ')] = T_NEXT_STATE('b', '$');
    
    // transições q1(b) -> q1(b)
    dict[T_TUPLE('b', 'A', 'T')] = T_NEXT_STATE('b', ' ');   
    dict[T_TUPLE('b', 'T', 'A')] = T_NEXT_STATE('b', ' ');    
    dict[T_TUPLE('b', 'C', ' ')] = T_NEXT_STATE('b', ' ');
    dict[T_TUPLE('b', 'G', ' ')] = T_NEXT_STATE('b', ' ');
    
    //transições q1(b) -> q2(c) -> q1(b)
    dict[T_TUPLE('b', 'A', '$')] = T_NEXT_STATE('c', '$');   
    dict[T_TUPLE('b', 'A', 'A')] = T_NEXT_STATE('c', 'A');    
    dict[T_TUPLE('c', ' ', ' ')] = T_NEXT_STATE('b', 'A');    

     //transições q1(b) -> q3(d) -> q1(b)
    dict[T_TUPLE('b', 'T', '$')] = T_NEXT_STATE('d', '$');   
    dict[T_TUPLE('b', 'T', 'T')] = T_NEXT_STATE('d', 'T');    
    dict[T_TUPLE('d', ' ', ' ')] = T_NEXT_STATE('b', 'T');  

    // transição para estado de aceitação q5(e)
    dict[T_TUPLE('b', '#', '$')] = T_NEXT_STATE('e', '$');


        PDA pda;

        pda.set_productions(dict);
        pda.set_alphabet(alphabet);
        pda.set_states(states);
        pda.set_final_states(final_states);

    // para os arquivos de teste
    // while (getline(cin, w)) {

    //          pda.set_init_state('a');
                
    //         bool resultado = pda.process_string(w);
    //         cout << w << " - " << resultado << endl;
    // }
        
   
        while (true) {
        
            pda.set_init_state('a');

            cout << "Digite o DNA (ou 0 para sair): \n";
            cin >> w;

            if (w == "0") {           
                break;
            }       

            bool resultado = pda.process_string(w);
            
            cout << (resultado ? "DNA válido! \n" : "DNA inválido! \n");
    }

    return 0;
}