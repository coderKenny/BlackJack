
#pragma once



#ifndef PELIKORTTI
#define PELIKORTTI

#include "Pelikortti.h"

#endif

#include "CommonHederi.h"

//#include "JaettavaPakka.h"

class JaettavaPakka
{
public:
	JaettavaPakka(void);
	~JaettavaPakka(void);

	std::vector <Pelikortti> pelikortit;
};

