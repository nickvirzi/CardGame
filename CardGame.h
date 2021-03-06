// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the LAB5GAME_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// LAB5GAME_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef LAB5GAME_EXPORTS
#define LAB5GAME_API __declspec(dllexport)
#else
#define LAB5GAME_API __declspec(dllimport)
#endif

#include <list>
#include <vector>
#include <algorithm>

enum suit_t {
	HEARTS,
	SPADES,
	DIAMONDS,
	CLUBS
};

// This class is exported from the dll
class LAB5GAME_API Card {
public:
	Card(suit_t suit, int rank);

	int GetRank() const
	{
		return m_rank;
	}

	suit_t GetSuit() const
	{
		return m_suit;
	}

private:
	Card();
	suit_t m_suit;
	int m_rank;
	bool dealt;
};

class LAB5GAME_API Deck
{
public:
	Deck(void);
	const Card * GetTopCard();
	void RemoveTopCard();
	void init_deck();
	void AddCardtoBottom(const Card * CardToMoveToDeck);
	std::list<const Card *> GetDeck();
	void SetDeck(Deck deck);
	int GetDeckSize();

private:
	std::list<const Card *> DeckQueue;
};

class LAB5GAME_API Player
{
public:
	Player(std::string Name);
	void InitHand(Deck * deck);
	void DrawCard(Deck * deck);
	int GetHandSize();
	int GetStackSize();
	const Card * GetTopCardOfStack();
	void PutCardInStack(const Card * CardToMoveToStack);
	bool DiscardCardFromHand(const Card * CardToDiscard, Deck * deck);
	void SetPlayerName(std::string PlayerNameInput);
	std::string GetPlayerName();
	std::vector<const Card *> GetPlayerHand();
	void SetPlayerHand(std::vector<const Card *> stack);
	std::list<const Card *> GetPlayerStack();
	void SetPlayerStack(std::list<const Card *> PlayerStackToSet);
private:
	std::list<const Card *> PlayerStack;
	std::vector<const Card *> PlayerHand;
	std::string PlayerName;
};