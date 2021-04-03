// This file is under MIT License. The program has been made by Nenyoko and Orwenn22.

#include <iostream>
#include <random>
#include <time.h>

#include "words.h"

int main(void){
    srand((unsigned int)time(0));
    int selectedword = rand() % wordnumber;

    std::string wordtoguess = wordlist[selectedword];
    int wordtoguess_lenght = wordslenght[selectedword];
    
    std::string wordtoguess_visiblebyplayer = "          ";
    for(int i=0; i!=wordtoguess_lenght; i++){
        wordtoguess_visiblebyplayer[i] = '_';
    }

    char userinput;
    int playerlife = 6;
    bool playerisright;
    int isplaying = 1;
    while (isplaying == 1){
        std::cout << wordtoguess_visiblebyplayer << std::endl;

        playerisright = false;
        std::cin >> userinput;
        for(int i=0; i!=wordtoguess_lenght; i++){
            if(userinput == wordtoguess[i]){
                wordtoguess_visiblebyplayer[i] = userinput;
                playerisright = true;
            }
        }
        if(playerisright == false){
            playerlife--;
            std::cout << "Wrong letter, try again! Remaining life: " << playerlife << std::endl;
        }
        if(playerlife == 0){
            std::cout << "You lost.."  << std::endl;
            isplaying = 0;
        }
        for(int i=0; i!=wordtoguess_lenght; i++){
            if(wordtoguess_visiblebyplayer[i] == wordtoguess[i]){
                std::cout << "You won!" << std::endl;
                isplaying = 0;
            }
        }
    }

}