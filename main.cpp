#include <bits/stdc++.h>
#include "PDA.h"
using namespace std;

int main() {

    T_PRODUCTIONS dict;
    string str =            "010100"; 
    char states[] =         {'a', 'b', 'c'};
    char final_states[] =   {'c'};
    char alphabet[] =       {'0', '1'};

    dict[T_TUPLE('a', '0', ' ')] = T_NEXT_STATE('b', 'x');
    dict[T_TUPLE('a', '1', ' ')] = T_NEXT_STATE('a', 'x');
    dict[T_TUPLE('b', '0', ' ')] = T_NEXT_STATE('c', 'x');
    dict[T_TUPLE('b', '1', ' ')] = T_NEXT_STATE('a', 'x');
    dict[T_TUPLE('c', '0', ' ')] = T_NEXT_STATE('c', 'x');
    dict[T_TUPLE('c', '1', ' ')] = T_NEXT_STATE('a', 'x');

    PDA pda;

    pda.set_productions(dict);
    pda.set_alphabet(alphabet);
    pda.set_states(states);
    pda.set_final_states(final_states);
    pda.set_init_state('a');

    pda.process_string(str);

    return 0;
}