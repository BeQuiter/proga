#include <iostream>
#include <map>

using namespace std;

void print_repeated_words_number() {
    string line;
    getline(cin, line);
    line = line + ' ';

    map<string, int> myMap;

    string word;
    for (char& letter : line) {
        if (letter == ' ') {
            myMap[word]++;
            word = "";
            continue;
        }
        word += letter;
    }

    for (const auto& elem : myMap) {
        std::cout << elem.first << " " << elem.second << "\n";
    }
}


int main() {
    print_repeated_words_number();
    return 0;
}