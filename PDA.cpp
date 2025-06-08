#include "PDA.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility> 
#include <string>

using namespace std;


void PDA::set_alphabet(char* alphabet) {
    this->alphabet = alphabet;
}

void PDA::set_productions(T_PRODUCTIONS productions) {
    this->productions = productions;
}

void PDA::test() {
    cout << productions[T_TUPLE('c', 'p', 'p')].first << " " << productions[T_TUPLE('c', 'p', 'p')].second << "\n";
}

void PDA::set_states(char *states) {
    this->states = states;
}

void PDA::set_init_state(char state) {
    this->current_state = state;
}

void PDA::set_final_states(char *final_states) {
    this->final_states = final_states;
}

bool PDA::process_string(std::string str) {
    T_NEXT_STATE next;
    for (char chr: str) {

        next = productions[T_TUPLE(this->current_state , chr, ' ')];

        cout << "P - " << this->current_state << " - " << next.first << " - " << next.second << "\n";

        // colocar na pilha o next.second
        this->stack.push(next.second);

        // atualizar estado atual
        this->current_state = next.first;

    }

    cout << "Estado em que terminou: " << this->current_state << "\n";

    for (int i = 0; i < (sizeof(this->final_states) / sizeof(char)); ++i)  {
        if (this->current_state == this->final_states[i]) return true;
    }
    return false;
}   