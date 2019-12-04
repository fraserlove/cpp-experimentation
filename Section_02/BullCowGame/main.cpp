/*
This is the console executable, that makes use of the BullCow class
This acts as a view in a MVC pattern, and is responsible for all user interaction.
For game logic see the FBullCowGame class.
*/

#pragma once

#include <iostream>
#include <string>
#include "FBullCowGame.h"

// To adhere syntax to the Unreal coding standards
using FText = std::string;
using int32 = int;

void PrintIntro();
void PlayGame();
FText GetValidGuess();
bool AskToPlayAgain();
void PrintGameSummary();

FBullCowGame BCGame; // Instantiate a new game

int main()
{
	bool bPlayAgain = false;
	do {
		BCGame.Reset();
		PrintIntro();
		PlayGame();
		bPlayAgain = AskToPlayAgain();
	}
	while (bPlayAgain);
	return 0;
}

void PrintIntro()
{
	std::cout << "Welcome to Bulls and Cows" << std::endl;
	std::cout << "A Game Developed in C++ by Fraser Love" << std::endl << std::endl;
	std::cout << "Can you guess the " << BCGame.GetHiddenWordLength() << " letter isogram I am thinking of?" << std::endl;
	return;
}

void PlayGame()
{
	int32 MaxTries = BCGame.GetMaxTries();
	while (!BCGame.IsGameWon() && BCGame.GetCurrentTry() <= MaxTries)
	{
		FText Guess = GetValidGuess();
		FBullCowCount BullCowCount = BCGame.SubmitValidGuess(Guess);
		std::cout << "Bulls: " << BullCowCount.Bulls << "\tCows: " << BullCowCount.Cows << std::endl;
	}
	PrintGameSummary();
}

FText GetValidGuess()
{
	FText Guess = "";
	EGuessStatus Status = EGuessStatus::Invalid_Status;
	do {
		std::cout << std::endl << "Try " << BCGame.GetCurrentTry() << " of " << BCGame.GetMaxTries() << ". Enter your guess: ";
		std::getline(std::cin, Guess);

		Status = BCGame.CheckGuessValidity(Guess);
		switch (Status)
		{
		case EGuessStatus::Wrong_Length:
			std::cout << "Please enter a " << BCGame.GetHiddenWordLength() << " letter word." << std::endl;
			break;
		case EGuessStatus::Not_Isogram:
			std::cout << "Please enter a word without repeating letters." << std::endl;
			break;
		case EGuessStatus::Not_Lowercase:
			std::cout << "Please enter all lowercase letters." << std::endl;
			break;
		default:
			break;
		}
	} while (Status != EGuessStatus::OK);
	return Guess;
}

bool AskToPlayAgain()
{
	std::cout << "Do you want to play again with a different hidden word (y/n)? ";
	FText Response = "";
	std::getline(std::cin, Response);
	if (Response[0] == 'y' || Response[0] == 'Y') {
		std::cout << "\n\n\n\n\n" << std::endl;
		return true;
	}
	else {
		return false;
	}
}

void PrintGameSummary()
{
	if (BCGame.IsGameWon())
	{
		std::cout << std::endl << "Well Done - You Won!" << std::endl << std::endl;
	}
	else {
		std::cout << std::endl << "Better luck next time!" << std::endl << std::endl;
	}
}
