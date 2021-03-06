// GameEXE.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Lab5Game.h"
#include <string>

using namespace std;

//TODO
//Shuffle deck?
//Add win conditions
//Check bounds on card entries
//Make tests
//Turn in by 6!!!!!!

int main()
{
	std::string Player1Name;
	std::string Player2Name;
	
	cout << "Please enter player ones name " << endl;
	cin >> Player1Name;
	cout << "Player one is named " << Player1Name << endl;

	cout << "Please enter player twos name " << endl;
	cin >> Player2Name;
	cout << "Player two is named " << Player2Name << endl;


	Player * player1 = new Player(Player1Name);
	Player * player2 = new Player(Player2Name);
	Deck * GameDeck = new Deck();

	GameDeck->init_deck();
	player1->InitHand(GameDeck);
	player2->InitHand(GameDeck);

	bool WinCondition = false;

	while (!WinCondition)
	{
		int Player1Move;
		int Player2Move;
		int MTSRank;
		int MTSSuit;
		int DCRank;
		int DCSuit;
		bool PlayerOneTurnCheck = false;
		bool PlayerTwoTurnCheck = false;
		bool P1Win = false;
		bool P2Win = false;

		while (!PlayerOneTurnCheck)
		{
			std::vector<const Card*> Player1Hand = player1->GetPlayerHand();
			std::list<const Card *> Player1Stack = player1->GetPlayerStack();

			int count = 1;
			int count2 = 1;
			cout << Player1Name << "'s hand contains: " << endl;
			for (const Card * c : Player1Hand)
			{
				if (player1->GetHandSize() > count)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << ", ";
					count++;
				}
				else if (player1->GetHandSize() == count)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << endl;
					count++;
				}
			}

			cout << Player1Name << "'s stack contains: " << endl;
			for (const Card * c : Player1Stack)
			{
				if (player1->GetStackSize() > count2)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << ", ";
					count2++;
				}
				else if (player1->GetStackSize() == count2)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << endl;
					count2++;
				}
			}

			cout << "Player 1 choose your move" << endl;
			cout << "Enter 0 to draw a card" << endl;
			cout << "Enter 1 to add a card to your stack" << endl;
			cout << "Enter 2 to discard a card" << endl;
			cin >> Player1Move;

			if (Player1Move > 2 || Player1Move < 0)
			{
				cout << "Invalid move, please re-enter" << endl;
			}
			else if (Player1Move == 0 && player1->GetHandSize() < 6)
			{
				player1->DrawCard(GameDeck);
				std::vector<const Card*> Player1Hand = player1->GetPlayerHand();
			}
			else if (Player1Move == 0 && player1->GetHandSize() >= 6)
			{
				cout << "You have too many cards" << endl;
			}
			else if (Player1Move == 1)
			{
				cout << "Enter the rank of the card you wish to add" << endl;
				cin >> MTSRank;
				cout << "Enter the suit of the Card you wish to add" << endl;
				cin >> MTSSuit;
				const Card * TempCard = new Card((suit_t)MTSSuit, MTSRank);
				const Card * TempCardForRank = new Card((suit_t)0, 1);
					if (player1->GetStackSize() > 0)
					{
						TempCardForRank = player1->GetTopCardOfStack();
					}
					if (player1->GetStackSize() == 0 && TempCard->GetRank() == 1)
					{
						player1->PutCardInStack(TempCard);
					}
					else if ((TempCardForRank->GetRank() + 1) == TempCard->GetRank())
					{
						player1->PutCardInStack(TempCard);
					}
					else
					{
						cout << "This card is not in your hand or is not the right order" << endl;
					}
			}
			else if (Player1Move = 2)
			{
				cout << "Enter the rank of the card you wish to discard" << endl;
				cin >> DCRank;
				cout << "Enter the suit of the Card you wish to discard" << endl;
				cin >> DCSuit;
				const Card * TempCardDC = new Card((suit_t)DCSuit, DCRank);
				player1->DiscardCardFromHand(TempCardDC, GameDeck);
				bool DiscardCheck = player1->DiscardCardFromHand(TempCardDC, GameDeck);
				if (!DiscardCheck)
				{
					cout << "That card is not in your hand or cannot be discarded" << endl;
				}
				else
				{
					PlayerOneTurnCheck = true;
				}
			}
			if (player1->GetStackSize() == 13)
			{
				WinCondition = true;
				P1Win = true;
				break;
			}
		}

		while (!PlayerTwoTurnCheck)
		{
			std::vector<const Card*> Player2Hand = player2->GetPlayerHand();
			std::list<const Card *> Player2Stack = player2->GetPlayerStack();

			int count = 1;
			int count2 = 1;
			cout << Player2Name << "'s hand contains: " << endl;
			for (const Card * c : Player2Hand)
			{
				if (player2->GetHandSize() > count)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << ", ";
					count++;
				}
				else if (player2->GetHandSize() == count)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << endl;
					count++;
				}
			}

			cout << Player2Name << "'s stack contains: " << endl;
			for (const Card * c : Player2Stack)
			{
				if (player2->GetStackSize() > count2)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << ", ";
					count2++;
				}
				else if (player2->GetStackSize() == count2)
				{
					suit_t TempSuit = c->GetSuit();
					cout << "the " << c->GetRank() << " of " << TempSuit << endl;
					count2++;
				}
			}

			cout << "Player 2 choose your move" << endl;
			cout << "Enter 0 to draw a card" << endl;
			cout << "Enter 1 to add a card to your stack" << endl;
			cout << "Enter 2 to discard a card" << endl;
			cin >> Player2Move;

			if (Player2Move > 2 || Player2Move < 0)
			{
				cout << "Invalid move, please re-enter" << endl;
			}
			else if (Player2Move == 0 && player2->GetHandSize() < 6)
			{
				player2->DrawCard(GameDeck);
				std::vector<const Card*> Player1Hand = player2->GetPlayerHand();
			}
			else if (Player2Move == 0 && player2->GetHandSize() >= 6)
			{
				cout << "You have too many cards" << endl;
			}
			else if (Player2Move == 1)
			{
				cout << "Enter the rank of the card you wish to add" << endl;
				cin >> MTSRank;
				cout << "Enter the suit of the Card you wish to add" << endl;
				cin >> MTSSuit;
				const Card * TempCard = new Card((suit_t)MTSSuit, MTSRank);
				const Card * TempCardForRank = new Card((suit_t)0, 1);
				if (player2->GetStackSize() > 0)
				{
					TempCardForRank = player2->GetTopCardOfStack();
				}
				if (player2->GetStackSize() == 0 && TempCard->GetRank() == 1)
				{
					player2->PutCardInStack(TempCard);
				}
				else if ((TempCardForRank->GetRank() + 1) == TempCard->GetRank())
				{
					player2->PutCardInStack(TempCard);
				}
				else
				{
					cout << "This card is not in your hand or is not the right order" << endl;
				}
			}
			else if (Player2Move = 2)
			{
				cout << "Enter the rank of the card you wish to discard" << endl;
				cin >> DCRank;
				cout << "Enter the suit of the Card you wish to discard" << endl;
				cin >> DCSuit;
				const Card * TempCardDC = new Card((suit_t)DCSuit, DCRank);
				player2->DiscardCardFromHand(TempCardDC, GameDeck);
				if (player2->DiscardCardFromHand(TempCardDC, GameDeck) == false)
				{
					cout << "That card is not in your hand or cannot be discarded" << endl;
				}
				else
				{
					PlayerTwoTurnCheck = true;
				}
				PlayerTwoTurnCheck = true;
			}
			if (player1->GetStackSize() == 13)
			{
				WinCondition = true;
				P2Win = true;
				break;
			}
		}
		if (P1Win == true)
		{
			cout << "Congrats " << Player1Name << "you win!!!" << endl;
		}
		else if (P2Win == true)
		{
			cout << "Congrats " << Player2Name << "you win!!!" << endl;
		}
	}
}