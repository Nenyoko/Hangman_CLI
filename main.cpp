// This file is under MIT License. The program has been made by Nenyoko and Orwenn22.

#include <iostream>
#include <random>
#include <time.h>

#include "words.h"

int main(void){
    start:
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
    bool wordisright;
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
            std::cout << "You lost.. The word was " << wordtoguess << ". Do you want to play again? Y/N" << std::endl;
            std::cin >> userinput;

            if(userinput == 'y' || userinput == 'Y'){
                goto start;
            }
            else{
                isplaying = 0;
            }
        }
        wordisright = true;
        for(int i=0; i!=wordtoguess_lenght; i++){
            if(wordtoguess_visiblebyplayer[i] != wordtoguess[i]){
                wordisright = false;
            }
        }
        if(wordisright == true){
            std::cout << "You won! Do you want to play again? Y/N" << std::endl;
            std::cin >> userinput;

            if(userinput == 'y' || userinput == 'Y'){
                goto start;
            }
            else{
                isplaying = 0;
            }
        }
    }
}