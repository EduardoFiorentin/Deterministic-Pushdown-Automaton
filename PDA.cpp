#include "PDA.h"
#include <exception>
#include <stdexcept>
#include <algorithm>
#include <string>
#include <iostream>
#include <utility> 

using namespace std;

// #define T_PRODUCTIONS std::unordered_map<std::string, std::string>

// class PDA {
//     public:
//         // PDA();
    
//         void process();
//         void set_alphabet(char *alphabet);
//         void set_productions(T_PRODUCTIONS productions);
//         void set_string(std::string string);
//         void set_states(char *states);
//         void set_init_state(char state);
    
//         bool process_string();
//         void test();
    
//     private:
//         char *alphabet;
//         T_PRODUCTIONS productions;
//         std::string string;
//         std::stack<char> stack;
//         char states;
    
//         bool state_is_defined(char state);
//         bool string_is_in_alphabet(std::string string);
        
// };


void PDA::set_alphabet(char* alphabet) {
    this->alphabet = alphabet;
}

void PDA::set_productions(T_PRODUCTIONS productions) {
    this->productions = productions;
}

void PDA::test() {
    cout << productions["cpp"] << "\n";
}

