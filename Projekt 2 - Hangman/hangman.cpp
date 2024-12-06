#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>
#include <algorithm>

using namespace std;
using std::cout; 

string random_word_generator() {
    vector<string> words;

    std::ifstream file("words.txt");
    string line;
    while(std::getline(file, line)) {
        words.push_back(line);
    }

    int random_word_index = rand() % words.size();
    string random_word = words[random_word_index];
    return random_word;
}

void hangman_display(int hearts) {
    
    vector<string> hangman_stages = {
    "\n  +---+\n  |   |\n      |\n      |\n      |\n      |\n========",
    "1 mistake \n  +---+\n  |   |\n  O   |\n      |\n      |\n      |\n========",
    "2 mistakes \n  +---+\n  |   |\n  O   |\n /    |\n      |\n      |\n========",
    "3 mistakes \n  +---+\n  |   |\n  O   |\n /|   |\n      |\n      |\n========",
    "4 mistakes \n  +---+\n  |   |\n  O   |\n /|\\  |\n      |\n      |\n========",
    "5 mistakes \n  +---+\n  |   |\n  O   |\n /|\\  |\n /    |\n      |\n========",
    "6 mistakes \n  +---+\n  |   |\n  O   |\n /|\\  |\n / \\  |\n      |\n========"
    };  
    
    cout << "\n" << hangman_stages[6 - hearts] << "\n";
    
}

void guess_word(){
    vector<char> wrong_guess; 
    string actual_word = random_word_generator();
    string current_guess(actual_word.size(), '?'); 
    int hearts = 6;
    char guess_character;
    cout << "Welcome to Hangman! Try to guess the word, one letter at a time. \n" << 
            "You have 6 attempts to save the Hangman. Good luck! \n";
    cout << "\n" << "Currently guessed words: " << current_guess << "\n"; 
    while(current_guess != actual_word) {
        hangman_display(hearts);
        cout << "Try to guess a character" << "\n"; 
        cin >> guess_character; 
        guess_character = tolower(guess_character);
        bool correct_guess = false;

        if(!isalpha(guess_character)){
            cout << "Invalid input. Please enter a single letter." << "\n";
            cin.clear();
            cin.ignore(1000, '\n');
            continue; 
        }

        if (find(wrong_guess.begin(), wrong_guess.end(), guess_character) != wrong_guess.end()) {
            cout << "You already guessed that letter!" << "\n";
            continue;
        }


        for(int i = 0; i < actual_word.size(); i++){
            if(guess_character == actual_word[i]) {
                correct_guess = true; 
                current_guess[i] = guess_character;
                cout << "hearts: " << hearts << "\n";
            }
        }
        
        cout << "Your current guess is: " << current_guess << "\n";
        
        if(!correct_guess){
            if(isalpha(guess_character)){
                wrong_guess.push_back(guess_character);
            }
            cout << "The character: " << guess_character << " is wrong" << "\n";      
            cout << "attempts left: " << hearts << "\n";
            hearts--;
            cout << "previous guesses: "; 
            for(char c : wrong_guess){
                cout << c << " ";
            }
        }
        
        if(current_guess == actual_word){
            cout << "Congratulations, you have guessed the word!" << "\n"; 
            break;
        }

        if(hearts == 0){
            cout << "\n" << "You have lost!" << "\n";
            hangman_display(0);  
            cout << "the word is: " << actual_word << "\n"; 
            break;
        }
    }
}

int main() {
    srand(static_cast<unsigned int>(time(0)));
    guess_word();
    return 0;
}