
#pragma once

#include "CommonHederi.h"



JaettavaPakka::JaettavaPakka(void)
{
	    //char suit[] = {'h','d','c','s'};
    //char card[] = {'2','3','4','5','6','7','8','9','T','J','Q','K','A'};

	pelikortit.reserve(Pelikortti::skNumCards);

	// Kortit pakkaan -->
	for ( int cardValue = 0; cardValue < Pelikortti::skNumCards; ++cardValue )
	{
		pelikortit.push_back( Pelikortti( cardValue ) );
	}

	random_shuffle( pelikortit.begin(), pelikortit.end() );
}


JaettavaPakka::~JaettavaPakka(void)
{
}
