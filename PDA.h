#ifndef PDA_H
#define PDA_H

#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>
#include <utility>

struct pair_hash {
    template <typename T1, typename T2>
    std::size_t operator() (const std::pair<T1, T2>& p) const {
        auto h1 = std::hash<T1>{}(p.first);
        auto h2 = std::hash<T2>{}(p.second);
        return h1 ^ h2;  // Usar XOR entre os dois hashes
    }
};

#define T_PRODUCTIONS std::unordered_map<std::string, std::string>
#define T_DICT std::unordered_map<std::pair<char, char>, std::string, pair_hash>
#define T_PAIR pair<char, char>

class PDA {
    public:
        // PDA();
    
        void process();
        void set_alphabet(char *alphabet);
        void set_productions(T_PRODUCTIONS productions);
        void set_string(std::string string);
        void set_states(char *states);
        void set_init_state(char state);
    
        void test();
        bool process_string();
    
    private:
        char *alphabet;
        T_PRODUCTIONS productions;
        std::string string;
        std::stack<char> stack;
        char states;
    
        bool state_is_defined(char state);
        bool string_is_in_alphabet(std::string string);
        
};


#endif // PDA_H