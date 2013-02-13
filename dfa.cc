#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <cstdlib>
#include <algorithm>

using namespace std;

int main () {
    int size;
    //cout << "Enter alphabet size: ";
    cin >> size;
    vector<string> alphabets;
    for (int i = 0; i != size; i++) {
        string alpha = "";
        //cout << "Enter alphabet " << i << ": ";
        cin >> alpha;
        alphabets.push_back(alpha);
    }
    int num_states;
    //cout << "Enter number of states: ";
    cin >> num_states;
    vector<string> states;
    for (int i = 0; i != num_states; i++) {
        string state = "";
        //cout << "Enter state " << i << ": ";
        cin >> state;
        states.push_back(state);
    }
    //cout << "Enter starting state: ";
    string starting_state = "";
    cin >> starting_state;
    int num_endstates;
    //cout << "Enter number of end states: ";
    cin >> num_endstates;
    vector<string> endStates;
    for (int i = 0; i != num_endstates; i++) {
        string end = "";
        //cout << "Enter end " << i << ": ";
        cin >> end;
        endStates.push_back(end);
    }
    int num_transitions;
    //cout << "Enter number of transition states: ";
    cin >> num_transitions;
    multimap<string,string> transitionMap;
    for (int i = 0; i != num_transitions; i++) {
        string from = "";
        string via = "";
        string to = "";
        //cout << "Enter transition state #" << i << ": ";
        cin >> from;
        cin >> via;
        cin >> to;
        via.append(" ");
        via.append(to);
        transitionMap.insert(pair<string,string>(from,via));
//        cout << "Multimap [" << from << "] = {" << via << "}" << endl;
    }
    
    
    string line;
    int loops = 0;
    while (getline(cin, line)) {
        line += " ";
//        cout << "Line read: |" << line << "|" << endl;
        if (loops == 0) {
            loops++;
            continue;
        }
        istringstream iss(line);
        string token = "";
        string state = starting_state;
        while (iss >> token) {
//            cout << "Token just read:\t" << token << endl;
//            cout << "Current state:\t" << state << endl;
            vector<string>::iterator vit;
            vit = find(alphabets.begin(), alphabets.end(), token);
            if (vit ==  alphabets.end()) {
                cout << "Error: Symbol " << token << " is not in alphabet" << endl;
                continue;
            }
            
            multimap<string,string>::iterator it = transitionMap.find(state);
            if (it == transitionMap.end()) {
                cerr << "Error: Unknown token " << token << endl;
            } else {
                istringstream r (it->second);
                string via, to;
                r >> via >> to;
                while (it != transitionMap.end() && via != token)  {
                    istringstream r (it->second);
                    r >> via >> to;
                    ++it;
                }
                state = to;
//                cout << "New state is: " << state << endl;
            }
        }
        // check if the resulting state is one of the end states.
        std::vector<string>::iterator findIT = find(endStates.begin(), endStates.end(), state);
        if (findIT != endStates.end()) {
            cout << "true" << endl;
        } else {
            cout << "false" << endl;
        }
    }


    return 0;
}
