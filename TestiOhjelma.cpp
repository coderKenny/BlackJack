


#include "CommonHederi.h"
#include "JaettavaPakka.h"
#include "ApuLuokka.h"



void main (void)
{

	
	ApuLuokka* apuluokka = new ApuLuokka();
	

	//if(pakka->pelikortit.at(0).GetSuit() == Pelikortti::kSuit_Heart && pakka->pelikortit.at(0).GetSuit() == Pelikortti::kRank_Ace)
	//{
	//	cout << "ACE OF HEARTS" << std::endl;
	//}

	apuluokka->PelaaPelia();

	//cout<<pakka->pelikortit.at(1).GetSuit()<<endl;
	

	delete apuluokka;
}