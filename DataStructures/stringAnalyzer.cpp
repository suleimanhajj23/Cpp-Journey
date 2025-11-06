#include <iostream>
#include <string>
using namespace std;

int main() {
    string text;
    cout << "Enter a sentence: ";
    getline(cin, text);

    int vowels = 0;
    int consonants = 0;
    int words = 0;
    string longest = "";
    string current = "";

    for (int i = 0; i < text.length(); i++) {
        char c = tolower(text[i]);

        // Count vowels and consonants
        if (c >= 'a' && c <= 'z') {
            if (c=='a' || c=='e' || c=='i' || c=='o' || c=='u')
                vowels++;
            else
                consonants++;

            current += c; // build current word
        }
        else {
            // when hitting space or punctuation, word ends
            if (!current.empty()) {
                words++;
                if (current.length() > longest.length())
                    longest = current;
                current = "";
            }
        }
    }

    // check last word
    if (!current.empty()) {
        words++;
        if (current.length() > longest.length())
            longest = current;
    }

    cout << "\nVowels: " << vowels << endl;
    cout << "Consonants: " << consonants << endl;
    cout << "Words: " << words << endl;
    cout << "Longest word: " << longest << endl;

    return 0;
}
