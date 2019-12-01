#pragma once

#include <string>

// To adhere syntax to the Unreal coding standards
using FString = std::string;
using int32 = int;

struct FBullCowCount
{
	int32 Bulls = 0;
	int32 Cows = 0;
};

enum EGuessStatus
{
	Invalid_Status,
	OK,
	Not_Isogram,
	Wrong_Length,
	Not_Lowercase
};

class FBullCowGame
{
public:
	FBullCowGame(); // Constructor

	int32 GetMaxTries() const;
	int32 GetCurrentTry() const;
	int32 GetHiddenWordLength() const;
	EGuessStatus CheckGuessValidity(FString) const;
	bool IsGameWon() const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWords[12] = {"planet", "bricks", "age", "view", "outside", "lakes", "sword", "aftershock", "flashpoint", "ultrasonic", "dispute", "demographics"};
	FString MyHiddenWord;
	bool bGameIsWon;
	int32 InitValues[6][2] = {{3,5}, {4,7}, {5,10}, {6,16}, {7,20}, {8,26}};

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
	FString PickHiddenWord(FString[]) const;
};
