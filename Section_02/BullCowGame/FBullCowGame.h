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

enum class EGuessStatus
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
	FString PickHiddenWord() const;
	bool IsGameWon() const;

	void Reset();
	FBullCowCount SubmitValidGuess(FString);

private:
	int32 MyCurrentTry;
	FString MyHiddenWords[10] = {"planet", "age", "view", "outside", "sword", "aftershock", "flashpoint", "ultrasonic", "dispute", "demographics"};
	FString MyHiddenWord;
	bool bGameIsWon;
	int32 InitValues[10][2] = { {3,5}, {4,7}, {5,10}, {6,16}, {7,20}, {8,26}, {9,32}, {10,40}, {11,50}, {12,60} };

	bool IsIsogram(FString) const;
	bool IsLowercase(FString) const;
};
