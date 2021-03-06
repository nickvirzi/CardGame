// Lab5Game.cpp : Defines the exported functions for the DLL application.
//

#include "header.h"
#include "Lab5Game.h"

Card::Card(suit_t suit, int rank) :m_rank(rank), m_suit(suit)
{

}

Deck::Deck()
{

}

const Card * Deck::GetTopCard()
{
	const Card * UsedCard = DeckQueue.front();
	return DeckQueue.front();
}

void Deck::RemoveTopCard()
{
	DeckQueue.pop_front();
}

void Deck::init_deck()
{
	for (int s = 0; s < 4; s++) {
		for (int rank = 1; rank <= 13; rank++)
		{
			Card * TempCard = new Card((suit_t)s, rank);
			DeckQueue.push_back(TempCard);
		}
	}
}

void Deck::AddCardtoBottom(const Card * CardToMoveToDeck)
{
	DeckQueue.push_back(CardToMoveToDeck);
}

std::list<const Card *> Deck::GetDeck()
{
	return DeckQueue;
}

void Deck::SetDeck(Deck deck)
{
	DeckQueue = deck.GetDeck();
}

int Deck::GetDeckSize()
{
	return DeckQueue.size();
}

Player::Player(std::string Name)
{

}

void Player::DrawCard(Deck * deck)
{
	const Card * TopCard = deck->GetTopCard();
	deck->RemoveTopCard();
	PlayerHand.push_back(TopCard);
}

int Player::GetHandSize()
{
	return PlayerHand.size();
}

int Player::GetStackSize()
{
	return PlayerStack.size();
}

const Card * Player::GetTopCardOfStack()
{
	return PlayerStack.front();
}

void Player::PutCardInStack(const Card * CardToMoveToStack)
{
	int MovingCardRank = CardToMoveToStack->GetRank();
	int PlayerStackTopRank = 0;
	int StackSize = GetStackSize();
	if (StackSize > 0)
	{
		const Card * TempCard = PlayerStack.front();
		PlayerStackTopRank = TempCard->GetRank();
	}
	if (GetStackSize() == 0 && MovingCardRank == 1)
	{
		PlayerStack.push_front(CardToMoveToStack);
		int DiscardedRank = CardToMoveToStack->GetRank();
		suit_t DiscardedSuit = CardToMoveToStack->GetSuit();
		const Card * TempCard = PlayerHand.back();
		PlayerHand.back() = CardToMoveToStack;
		PlayerHand.pop_back();
		PlayerHand.front() = TempCard;
		const Card * TempCard2 = PlayerHand.front();
		for (int i = 0; i < GetHandSize() - 1; i++)
		{
			PlayerHand.at(i) = PlayerHand.at(i + 1);
		}
		PlayerHand.back() = TempCard2;
	}
	else if (GetStackSize() > 0 && PlayerStackTopRank + 1 == MovingCardRank)
	{
		PlayerStack.push_front(CardToMoveToStack);
		int DiscardedRank = CardToMoveToStack->GetRank();
		suit_t DiscardedSuit = CardToMoveToStack->GetSuit();
		const Card * TempCard = PlayerHand.back();
		PlayerHand.back() = CardToMoveToStack;
		PlayerHand.pop_back();
		PlayerHand.front() = TempCard;
		const Card * TempCard2 = PlayerHand.front();
		for (int i = 0; i < GetHandSize() - 1; i++)
		{
			PlayerHand.at(i) = PlayerHand.at(i + 1);
		}
		PlayerHand.back() = TempCard2;
	}
}

bool Player::DiscardCardFromHand(const Card * CardToDiscard, Deck * deck)
{
	int DiscardedRank;
	suit_t DiscardedSuit;
	int CardPos;
	const Card * TempCard;
	int DCRank1;
	int DCRank2;
	suit_t DCSuit1;
	suit_t DCSuit2;
	bool found = false;
	for (const Card * c : PlayerHand)
	{
		DCRank1 = c->GetRank();
		DCSuit1 = c->GetSuit();
		DCRank2 = CardToDiscard->GetRank();
		DCSuit2 = CardToDiscard->GetSuit();
		if (DCRank1 == DCRank2 && DCSuit1 == DCSuit2)
		{
			DiscardedRank = c->GetRank();
			DiscardedSuit = c->GetSuit();
			TempCard = PlayerHand.back();
			PlayerHand.back() = c;
			PlayerHand.pop_back();
			PlayerHand.front() = TempCard;
			found = true;
			break;
		}
		else
		{
			found = false;
		}
	}

	if (found == false)
	{
		return false;
	}
	const Card * TempCardTwo = new Card(DiscardedSuit, DiscardedRank);
	deck->AddCardtoBottom(TempCardTwo);
	return true;
}

void Player::SetPlayerName(std::string PlayerNameInput)
{
	PlayerName = PlayerNameInput;
}

std::string Player::GetPlayerName()
{
	return PlayerName;
}

std::vector<const Card*> Player::GetPlayerHand()
{
	return PlayerHand;
}

void Player::SetPlayerHand(std::vector<const Card*> stack)
{
	PlayerHand = stack;
}

std::list<const Card*> Player::GetPlayerStack()
{
	return PlayerStack;
}

void Player::SetPlayerStack(std::list<const Card*> PlayerStackToSet)
{
	PlayerStack = PlayerStackToSet;
}

void Player::InitHand(Deck * deck)
{
	for (int i = 0; i < 5; i++)
	{
		const Card * TempCard = deck->GetTopCard();
		deck->RemoveTopCard();
		PlayerHand.push_back(TempCard);
	}
	/*deck.SetDeck();*/
}