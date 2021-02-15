#include "stdafx.h"
#include "CppUnitTest.h"
#include "Lab5Game.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace Lab5UnitTest
{		
	TEST_CLASS(UnitTest1)
	{
	public:

		TEST_METHOD(InnitDeck)
		{
			Deck * deck = new Deck();
			deck->init_deck();

			Assert::AreEqual(52, deck->GetDeckSize());
		}

		TEST_METHOD(RemoveTopCard)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			deck->RemoveTopCard();

			Assert::AreEqual(51, deck->GetDeckSize());
		}

		TEST_METHOD(AddCardToBottom)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			const Card * TestCard = new Card((suit_t)1, 1);
			deck->AddCardtoBottom(TestCard);

			Assert::AreEqual(53, deck->GetDeckSize());
		}

		TEST_METHOD(MoveCardToStack)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			Player * player = new Player("Jay");
			player->InitHand(deck);
			std::vector<const Card*> PlayerHand = player->GetPlayerHand();
			std::list<const Card *> PlayerStack = player->GetPlayerStack();
			const Card * TestCard = PlayerHand.front();
			player->PutCardInStack(TestCard);

			Assert::AreEqual(1, player->GetStackSize());
			Assert::AreEqual(4, player->GetHandSize());
			Assert::AreEqual(47, deck->GetDeckSize());
		}

		TEST_METHOD(InnitHand)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			Player * player = new Player("Jay");
			player->InitHand(deck);

			Assert::AreEqual(5, player->GetHandSize());
			Assert::AreEqual(47, deck->GetDeckSize());
		}

		TEST_METHOD(DiscardFromHand)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			Player * player = new Player("Jay");
			player->InitHand(deck);
			std::vector<const Card*> PlayerHand = player->GetPlayerHand();
			const Card * TestCard = PlayerHand.front();
			player->DiscardCardFromHand(TestCard, deck);

			Assert::AreEqual(4, player->GetHandSize());
			Assert::AreEqual(48, deck->GetDeckSize());

		}
		
		TEST_METHOD(GetTopOfStackTest)
		{
			Deck * deck = new Deck();
			deck->init_deck();
			Player * player = new Player("Jay");
			player->InitHand(deck);
			std::vector<const Card*> PlayerHand = player->GetPlayerHand();
			std::list<const Card *> PlayerStack = player->GetPlayerStack();
			const Card * TestCard = PlayerHand.front();
			player->PutCardInStack(TestCard);
			const Card * TestCard2 = player->GetTopCardOfStack();

			Assert::AreEqual(1, player->GetStackSize());
			Assert::AreEqual(4, player->GetHandSize());
			Assert::AreEqual(TestCard->GetRank(), TestCard2->GetRank());
		}

		TEST_METHOD(CardTest)
		{
			const Card * TestCard = new Card((suit_t)1, 1);
			const Card * TestCard2 = new Card((suit_t)3, 12);

			Assert::AreEqual(1, TestCard->GetRank());
			Assert::AreEqual(12, TestCard2->GetRank());
		}
	};
}