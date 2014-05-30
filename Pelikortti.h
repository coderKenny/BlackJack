#pragma once

//#include "CommonHederi.h"

class Pelikortti
{
public:

	// Maa -->
	enum ESuit
    {
        kSuit_Heart,
        kSuit_Club,
        kSuit_Diamond,
        kSuit_Spade,
        kSuit_Count // Kuinka monta maata
    };

	// Arvo -->
    enum ERank
    {
        kRank_Ace,
        kRank_Two,
        kRank_Three,
        kRank_Four,
        kRank_Five,
        kRank_Six,
        kRank_Seven,
        kRank_Eight,
        kRank_Nine,
        kRank_Ten,
        kRank_Jack,
        kRank_Queen,
        kRank_King,
        kRank_Count // Kuinka monta arvoa
    };

	static int const skNumCards = kSuit_Count * kRank_Count;  // Vakiokorttien lukumäärä

	// Konstruktori -->
  Pelikortti( int cardIndex )
    : mSuit( static_cast<ESuit>( cardIndex / kRank_Count ) )
    , mRank( static_cast<ERank>( cardIndex % kRank_Count ) )
    {}

  ESuit GetSuit() const { return mSuit; }
  ERank GetRank() const { return mRank; }


	Pelikortti(void);
	//Pelikortti(Maa maa);
	//Pelikortti(Maa maa,int numeroArvo);
	~Pelikortti(void);


	private:
		ESuit mSuit;
		ERank mRank;
};

