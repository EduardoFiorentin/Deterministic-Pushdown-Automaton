#ifndef PDA_H
#define PDA_H

#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>
#include <tuple>  

// define um hash de acordo com o par de chars para que possa ser usado 
struct tuple_hash {
    template <typename T1, typename T2, typename T3>
    std::size_t operator()(const std::tuple<T1, T2, T3>& t) const {
        auto h1 = std::hash<T1>{}(std::get<0>(t));  
        auto h2 = std::hash<T2>{}(std::get<1>(t));  
        auto h3 = std::hash<T3>{}(std::get<2>(t));  
        return h1 ^ (h2 << 1) ^ (h3 << 2);  // Combina os hashes com um deslocamento para reduzir colisões
    }
};

#define T_TUPLE         std::tuple<char, char, char>
#define T_NEXT_STATE    std::pair<char, char>  // <proximo_estado, oq_entra_na_pilha>
#define T_PRODUCTIONS   std::unordered_map<T_TUPLE, T_NEXT_STATE, tuple_hash>

class PDA {
public:
    // PDA();
    void set_alphabet(char *alphabet);
    void set_productions(T_PRODUCTIONS productions);
    void set_states(char *states);
    void set_final_states(char *final_states);
    void set_init_state(char state);

    void test();
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