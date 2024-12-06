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
    string line;
    while(std::getline(file, line)) {
        words.push_back(line);
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
        cout << endl << "1 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << "      |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 4){
        cout << endl << "2 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /    |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 3){
        cout << endl << "3 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|   |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;
    }else if(hearts == 2){
        cout << endl << "4 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|\\  |\n"
             << "      |\n"
             << "      |\n"
             << "========"
             << endl;    
    }else if(hearts == 1){
        cout << endl << "5 mistakes:\n"
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
    vector<char> wrong_guess; 
    string actual_word = random_word_generator();
    string current_guess(actual_word.size(), '?'); 
    int hearts = 6;
    char guess_character;
    cout << current_guess << endl; 
    cout << "hearts: " << hearts << endl;
    while(current_guess != actual_word) {
        hangman_display(hearts);
        cout << "Try to guess a character" << endl; 
        cin >> guess_character; 
        bool correct_guess = false;
        for(int i = 0; i < actual_word.size(); i++){
            if(guess_character == actual_word[i]) {
                correct_guess = true; 
                current_guess[i] = guess_character;
                cout << "hearts: " << hearts << endl;
            }
        }
        
        cout << "Your current guess is: " << current_guess << endl;
        
        if(!correct_guess){
            wrong_guess.push_back(guess_character);
            cout << "The character: " << guess_character << " is wrong" << endl; 
            hearts--;
            cout << "hearts: " << hearts << endl;
            cout << "previous guesses: "; 
            for(char c : wrong_guess){
                cout << c << " ";
            }
        }
        

        if(current_guess == actual_word){
            cout << "Congratulations, you have guessed the word!" << endl; 
        }

        if(hearts == 0){
            cout << endl << "You have lost!" << endl  
             << "6 mistakes:\n"
             << "  +---+\n"
             << "  |   |\n"
             << "  O   |\n"
             << " /|\\  |\n"
             << " / \\  |\n"
             << "      |\n"
             << "========"             
            << endl << "the word is: " << actual_word << endl; 
            break;
        }
    }
}

void game_update(){
  
    srand(static_cast<unsigned int>(time(0)));
    guess_word();
}

int main() {
    game_update();
    return 0;
}