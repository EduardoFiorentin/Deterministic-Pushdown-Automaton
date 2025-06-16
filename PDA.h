/*
 * Trabalho 2 - GEX101 - Linguagens Formais e Autômatos - 2025/1
 *
 * Nome:      Daniele Rohr
 * Matricula: 2121101060
 * 
 * Nome:      Eduardo Fiorentin
 * Matricula: 2211100002
 */

#ifndef PDA_H
#define PDA_H

#include <stack>
#include <map>
#include <string>
#include <iostream>
#include <utility>
#include <tuple>  


#define T_TUPLE         std::make_tuple // <char_string, char_topo_pilha, char_pop_pilha>
#define T_NEXT_STATE    std::pair<char, char>  // <proximo_estado, oq_entra_na_pilha>
#define T_PRODUCTIONS   std::map<std::tuple<char, char, char>, T_NEXT_STATE> // define as transições

class PDA {
public:

    void set_alphabet(char *alphabet);
    void set_productions(T_PRODUCTIONS productions);
    void set_states(char *states);
    void set_final_states(char *final_states);
    void set_init_state(char state);

    bool process_string(std::string str);

private:
    char *alphabet;
    T_PRODUCTIONS productions;
    std::stack<char> stack;
    char *states, *final_states;
    char current_state;

    bool state_is_defined(char state);
    bool string_is_in_alphabet(std::string string);
};


#endif // PDA_H