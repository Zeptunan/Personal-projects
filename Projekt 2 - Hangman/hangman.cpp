#include <iostream>
#include <vector>
#include <random>
#include <iomanip>
#include <fstream>

using namespace std;
using std::cout; 

string random_word_generator() {
    vector<string> words;

    std::ifstream file("words.txt");
    string rad;
    while(std::getline(file, rad)) {
        words.push_back(rad);
    }

    int random_word_index = rand() % words.size();
    string random_word = words[random_word_index];
    return random_word;
}

void hangman_display(int hearts) {
    if (hearts == 6) {
        cout << "0 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "      |\n"
             << "      |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 5){
        cout << "1 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << "      |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 4){
        cout << "2 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /    |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 3){
        cout << "3 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|   |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 2){
        cout << "4 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|\\  |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;    
    }else if(hearts == 1){
        cout << "5 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|\\  |\n"
             << " /    |\n"
             << "      |\n"
             << "========"
             << endl;           
    }
}


void guess_word(){
    string actual_word = random_word_generator();
    string current_guess(actual_word.size(), '?'); 
    int hearts = 6;
    char guess_character;
    cout << current_guess << endl; 
    cout << hearts << endl;
    while(current_guess != actual_word) {
        hangman_display(hearts);
        cout << "Try to guess a character" << endl; 
        cin >> guess_character; 
        bool correct_guess = false;
        for(int i = 0; i < actual_word.size(); i++){
            if(guess_character == actual_word[i]) {
                correct_guess = true; 
                current_guess[i] = guess_character;
            }
        }
        if(!correct_guess){
            cout << "The character: " << guess_character << " is wrong" << endl; 
            hearts--;
            cout << "hearts: " << hearts << endl;
        }
        cout << "Your current guess is: " << current_guess << endl;

        if(current_guess == actual_word){
            cout << "Congratulations, you have guess the word!" << endl; 
        }

        if(hearts == 0){
            cout << "You have lost!"  
             << "6 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|\\  |\n"
             << " / \\  |\n"
             << "      |\n"
             << "========"             
            << endl << "the word is " << actual_word << endl; 
            break;
        }
    }
}

void main_function(){
  
    srand(static_cast<unsigned int>(time(0)));
    guess_word();
}

int main() {
    main_function();
    return 0;
}