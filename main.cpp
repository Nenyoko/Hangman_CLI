// This file is under MIT License. The program has been made by Nenyoko and Orwenn22.

#include <iostream>
#include <random>
#include <time.h>

//list of words.
#include "words.h"

int main(void){
    start:
    //generate a pseudo-random number.
    srand((unsigned int)time(0));
    int selectedword = rand() % wordnumber;

    //choose a world from the list and determine his length.
    std::string wordtoguess = wordlist[selectedword];
    int wordtoguess_lenght = wordtoguess.length();
    

    std::string wordtoguess_visiblebyplayer = "          ";
    for(int i=0; i!=wordtoguess_lenght; i++){
        wordtoguess_visiblebyplayer[i] = '_';
    }

    //variables used in the game loop.
    char userinput;
    int playerlife = 6;
    bool playerisright;
    bool wordisright;
    int isplaying = 1;
    while (isplaying == 1){
        std::cout << wordtoguess_visiblebyplayer << std::endl;

        playerisright = false;

        //get character from user
        std::cin >> userinput;

        //verify if the character from the user is in the word.
        for(int i=0; i!=wordtoguess_lenght; i++){
            //if yes, add the letter in "wordtoguess_visiblebyplayer"
            if(userinput == wordtoguess[i]){
                wordtoguess_visiblebyplayer[i] = userinput;
                playerisright = true;
            }
        }
        //if the player didn't guess one of the right letters
        if(playerisright == false){
            playerlife--;
            std::cout << "Wrong letter, try again! Remaining life: " << playerlife << std::endl;
        }
        //if the player don't have any life, ask the player if he wants to play one more game
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

        //verify if the player have guessed all the letters of the word
        wordisright = true;
        for(int i=0; i!=wordtoguess_lenght; i++){
            if(wordtoguess_visiblebyplayer[i] != wordtoguess[i]){
                wordisright = false;
            }
        }
        //if the word have been guessed, ask the player if he wants to play one more game
        if(wordisright == true){
            std::cout << wordtoguess_visiblebyplayer << std::endl;
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