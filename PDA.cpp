/*
 * Trabalho 2 - GEX101 - Linguagens Formais e Autômatos - 2025/1
 *
 * Nome:      Daniele Rohr
 * Matricula: 2121101060
 * 
 * Nome:      Eduardo Fiorentin
 * Matricula: 2211100002
 */

#include "PDA.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility> 
#include <string>
#include <bits/stdc++.h>


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
    int i = 0;
    bool running = true;
    while (running) {

        //cout << "pilha: " << this->stack.size() << endl;

        if (
            i == size(str) && 
            !this->productions.contains(T_TUPLE(this->current_state , ' ', ' ')) &&
            !this->productions.contains(T_TUPLE(this->current_state , ' ', this->stack.size() != 0 ? this->stack.top() : ' ' ))
        ) {
            break;
        }

        // se conseguir transição sem gastar nada 
        if (this->productions.contains(T_TUPLE(this->current_state , ' ', ' '))) {
            next = productions[T_TUPLE(this->current_state , ' ', ' ')];
            
            //cout << "sem nada - " << this->current_state << " - " << next.first << " - " << next.second << "\n";
        }

        // se consegue consumir apenas string, sem usar pilha
        else if (this->productions.contains(T_TUPLE(this->current_state , str[i], ' '))) {
            next = productions[T_TUPLE(this->current_state , str[i], ' ')];
    
            //cout << "string - " << this->current_state << " - " << next.first << " - " << next.second << "\n";
            i++;
        } 

        // se conseguir consumir apenas da pilha, sem usar string
        else if (this->productions.contains(T_TUPLE(this->current_state , ' ', this->stack.top()))) {
            next = productions[T_TUPLE(this->current_state , ' ', this->stack.top())];
            this->stack.pop();
            
            //cout << "pilha - " << this->current_state << " - " << next.first << " - " << next.second << "\n";

        }
        
        // se conseguir consumir string e pilha
        else if (this->productions.contains(T_TUPLE(this->current_state , str[i], this->stack.top()))) {
            //cout << "antes - " << this->current_state << " - " << next.first << " - " << next.second << "\n";
            
            next = productions[T_TUPLE(this->current_state , str[i], this->stack.top())];
            this->stack.pop();
            
            //cout << "string e pilha - " << this->current_state << " - " << next.first << " - " << next.second << "\n";
            i++;
        } 
        
        // senão - erro
        else {
            return false;
        }


        if (next.second != ' ') {
            //cout << "colocando na pilha: " << next.second << endl;
            this->stack.push(next.second);
        }

        // atualizar estado atual
        this->current_state = next.first;



    }

    //cout << "Estado em que terminou: " << this->current_state << "\n";

    // cout << "final states" << (sizeof(this->final_states) / sizeof(char)) << endl;
    for (int i = 0; i < (sizeof(*this->final_states) / sizeof(char)); ++i)  {
        //cout << "Ver estados " << this->current_state    << " " << this->final_states[i] << endl;
        if (this->current_state == this->final_states[i]) return true;
    }
    return false;
}   