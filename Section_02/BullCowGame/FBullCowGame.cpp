#pragma once

#include "FBullCowGame.h"
#include <map>
#include <cstdlib>
#include <ctime>

// To adhere syntax to the Unreal coding standards
#define TMap std::map

FBullCowGame::FBullCowGame() { Reset(); } // Constructor

int32 FBullCowGame::GetCurrentTry() const { return MyCurrentTry; }
int32 FBullCowGame::GetHiddenWordLength() const { return MyHiddenWord.length(); }
bool FBullCowGame::IsGameWon() const { return bGameIsWon; }

FString FBullCowGame::PickHiddenWord() const
{ 
	srand((int)time(0));
	int random = (rand() % 10);
	return MyHiddenWords[random]; 
}

int32 FBullCowGame::GetMaxTries() const
{
	TMap <int32, int32> WordLengthToMaxTries;
	for (int i = 0; i < sizeof(InitValues)/sizeof(InitValues[0]); i++)
	{
		WordLengthToMaxTries[InitValues[i][0]] = InitValues[i][1];
	}
	return WordLengthToMaxTries[MyHiddenWord.length()];
}

void FBullCowGame::Reset()
{
	MyHiddenWord = PickHiddenWord();
	MyCurrentTry = 1;
	bGameIsWon = false;
	return;
}

EGuessStatus FBullCowGame::CheckGuessValidity(FString Guess) const
{
	if (!IsIsogram(Guess)) {
		return EGuessStatus::Not_Isogram;
	}
	else if (!IsLowercase(Guess)) {
		return EGuessStatus::Not_Lowercase;
	}
	else if (Guess.length() != GetHiddenWordLength()) {
		return EGuessStatus::Wrong_Length;
	}
	else {
		return EGuessStatus::OK;
	}
}

FBullCowCount FBullCowGame::SubmitValidGuess(FString Guess)
{
	MyCurrentTry++;
	FBullCowCount BullCowCount;
	int32 WordLength = MyHiddenWord.length();
	for (int32 i = 0; i < WordLength; i++) {
		for (int32 j = 0; j < WordLength; j++) {
			if (Guess[i] == MyHiddenWord[j]) {
				if (i == j) {
					BullCowCount.Bulls++;
				}
				else {
					BullCowCount.Cows++;
				}
			}
		}
	}
	if (BullCowCount.Bulls == WordLength) {
		bGameIsWon = true;
	}
	else {
		bGameIsWon = false;
	}
	return BullCowCount;
}

bool FBullCowGame::IsIsogram(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	TMap<char, bool> LetterSeen;
	for (auto Letter : Word) // For all letters of the word
	{
		Letter = tolower(Letter);
		if (LetterSeen[Letter]) {
			return false;
		}
		else {
			LetterSeen[Letter] = true;
		}
	}
	return true;
}

bool FBullCowGame::IsLowercase(FString Word) const
{
	if (Word.length() <= 1) { return true; }

	for (auto Letter : Word)
	{
		if (!islower(Letter)) {
			return false;
		}
	}
	return true;
}
