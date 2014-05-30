#pragma once






#ifndef JAETTAVAPAKKA
#define JAETTAVAPAKKA

#include "JaettavaPakka.h"

#endif

//#include "CommonHederi.h"





class ApuLuokka
{
public:
	ApuLuokka(void);
	~ApuLuokka(void);
	void PelaaPelia(void);
	void gotoxy ( int, int);
	void ArvoLuku(int*);
	int GetRandomNumber(int, int);
	void pause();

	bool seedSet;

	void OtaKortti(int,JaettavaPakka *);
	void Jaa(JaettavaPakka*);

	int yhteisumma;

	int pelaajanSumma1;
	int pelaajanSumma2;
	bool assaJaettu;
	bool gameOver;
	int jakajansumma1;
	int jakajansumma2;
	int jakajansumma3;
	int jakajansumma4;


	int jakajalleAssa;
	int jakajalleToinenAssa;
	void ilmoitaSumma(int);
	void ApuLuokka::ilmoitaSummat(int,int);
};

