
#pragma once

#include "CommonHederi.h"




ApuLuokka::ApuLuokka(void)
{
	seedSet=false;
	assaJaettu=false;
	gameOver=false;
	jakajalleAssa=false;
	jakajalleToinenAssa=false;
	jakajansumma3=0;
	jakajansumma4=0;
}


ApuLuokka::~ApuLuokka(void)
{
}

void ApuLuokka::PelaaPelia(void)
{
	int* luku=nullptr;
	luku = new int;
	ArvoLuku(luku);
	bool assaJaettu1=false;
	bool assaJaettu2=false;
	int luku1;
	int luku2;
	int luku3;
	int tuplausValinta=2;

	JaettavaPakka* pakka = new JaettavaPakka();

	cout<<"Hei tama on 1 pakan venttipeli !"<<endl<<endl;
	Pelikortti jakajankortti1 = pakka->pelikortit.back();
	pakka->pelikortit.pop_back();
	cout<<"Jakajan ensimmainen kortti on : ";
	luku3 = jakajankortti1.GetRank()+1;

	if(luku3 == 1)
	{
		cout<<" 1 tai 11";
		jakajansumma1=1;
		jakajansumma2=11;
	}
	else if(luku3 >=10)
	{
		cout<<"10";
		jakajansumma1=10;
		jakajansumma2=10;
	}
	else
	{
		cout<<luku3;
		jakajansumma1=luku3;
		jakajansumma2=luku3;
	}
	yhteisumma=0;




	Pelikortti pelaajankortti1 = pakka->pelikortit.back();
	pakka->pelikortit.pop_back();
	Pelikortti pelaajankortti2 = pakka->pelikortit.back();
	pakka->pelikortit.pop_back();
	cout<<"\n\n";
	cout<<"Pelaajan kortti 1 on : ";

	luku1 = pelaajankortti1.GetRank()+1;
	
	if(luku1>=10) // MAX 10
		luku1=10;


	// Debug Molemmet ‰ssi‰ ?
	//luku1=1;
	//


	if(luku1 == 1)
	{
		cout<<"1 tai 11";
		assaJaettu1=true;
	}

	else if(luku1 >=10)
	{
		cout<<"10";
	}

	else
		cout<<luku1;




	cout<<"\n";
	cout<<"Pelaajan kortti 2 on : ";

	luku2 = pelaajankortti2.GetRank()+1;
	
	if(luku2>=10)
		luku2=10;





	if(luku2 == 1)
	{
		cout<<"1 tai 11";
		assaJaettu2=true;
	}
	else if(luku2 >=10)
	{
		cout<<"10";
	}

	else
		cout<<luku2;




	if(luku1+luku2==9 || luku1+luku2==10 || luku1+luku2==11)
	{
		cout << "\n\nVoit tuplata panoksesi\n";
		cout << "\nHaluatko tuplata ? 1 = kylla, 2 = ei\n: ";
		tuplausValinta;
		cin >> tuplausValinta;

		while(tuplausValinta!=1 && tuplausValinta !=2)
			cin>>tuplausValinta;

	}




	if(assaJaettu1)
	{
		pelaajanSumma1=luku2+1;
		pelaajanSumma2=luku2+11;
		cout<<"\n\n";
		cout<<"Yhteensa : "<<pelaajanSumma2<<" tai "<<pelaajanSumma1<<endl;
	}

	else if(assaJaettu2)
	{
		pelaajanSumma1=luku1+1;
		pelaajanSumma2=luku1+11;
		cout<<"\n\n";
		cout<<"Yhteensa : "<<pelaajanSumma2<<" tai "<<pelaajanSumma1<<endl;
	}

	else if(assaJaettu1 && assaJaettu2)
	{
		pelaajanSumma1=2;
		pelaajanSumma2=2;
		cout<<"\n\n";
		cout<<"Yhteensa : "<<pelaajanSumma2<<endl;
	}

	else
	{
		pelaajanSumma1=luku1+luku2;
		pelaajanSumma2=luku1+luku2;

		cout<<"\n\n";
		cout<<"Yhteensa : "<<pelaajanSumma1<<endl;
	}


	if(tuplausValinta==1)
		Jaa(pakka);


	else // Ei tuplattu
	{

		cout<<"\nOta kortti anna 1 "<<"jaa tahan anna 2 : "; 


		int valinta;
		cin>>valinta;

		while(1) // Toistaa kunnes gameover flagi nousee
		{
	

			if(valinta==1)
			{
				OtaKortti(1,pakka);
			
			}
		
			else
			{
				Jaa(pakka); // Pelaaja j‰‰
			}

			if(gameOver)
				break;

			cout<<"\n\nOta kortti anna 1 "<<" -- Jaa tahan anna 2 :   "; 
			cin>>valinta;		

		}

	}

	delete pakka;
	delete luku;
}


void ApuLuokka::ilmoitaSumma(int jakajansumma1)
{
	cout<<"\n";
	cout<<"\nKaden arvo nyt : "<<jakajansumma1;
	cout<<endl;
	pause();
}


void ApuLuokka::ilmoitaSummat(int jakajansumma1,int jakajansumma2)
{
	cout<<"\n";
	cout<<"\nKaden arvo nyt : "<<jakajansumma1 <<" tai "<< jakajansumma2;
	cout<<endl;
	pause();
}



void ApuLuokka::Jaa(JaettavaPakka* pakka)
{
	while(1)
	{
		Pelikortti jakajanKortti = pakka->pelikortit.back();
		pakka->pelikortit.pop_back();

		int lukuArvo = jakajanKortti.GetRank()+1;

		cout<<"\n";
		cout<<"Jakajan lisakortti on : "<<lukuArvo;


		////debug
		//lukuArvo=1;

		if(jakajansumma1!=jakajansumma2) // ƒss‰ ekassa jaossa 
		{
			if(lukuArvo!=1) // Ei toista ‰ss‰‰
			{
				jakajansumma1+=lukuArvo;
				jakajansumma2+=lukuArvo;
				if(jakajansumma1>jakajansumma2)
					ilmoitaSumma(jakajansumma1);
				else
					ilmoitaSumma(jakajansumma2);
			}

			else // Toinen ‰ss‰
			{
				jakajansumma1+=1;
				jakajansumma2+=11;

				if(jakajansumma1>21)
					ilmoitaSumma(jakajansumma2);

				else if(jakajansumma2>21)
					ilmoitaSumma(jakajansumma1);

				else
					ilmoitaSummat(jakajansumma1,jakajansumma2);
			}
		}

		else
		{
			if(lukuArvo!=1) // Ei toista ‰ss‰‰
			{
				jakajansumma1+=lukuArvo;
				jakajansumma2+=lukuArvo;

				ilmoitaSumma(jakajansumma1);
			}

			else // ƒss‰
			{
				jakajansumma1+=1;
				jakajansumma2+=11;


				if(jakajansumma1>21)
					ilmoitaSumma(jakajansumma2);

				else if(jakajansumma2>21)
					ilmoitaSumma(jakajansumma1);

				else
					ilmoitaSummat(jakajansumma1,jakajansumma2);
			}
		}


		if(jakajansumma1>=17 || jakajansumma2>=17) // House must stay
		{
			if(!(jakajansumma1>21)) // Alle 21 kuitenkin
				cout<<"\n\nTalon on jaatava\n\n";
			
			if(jakajansumma1==pelaajanSumma1)
			{
				cout<<"\n\nTasapeli !!!\n\n";
				gameOver=true;
				pause();
				break;
			}

			if(pelaajanSumma1>jakajansumma1)
			{
				cout<<"\n\nVoitto !!!\n\n";
				gameOver=true;
				pause();
				break;
			}

			if(((pelaajanSumma1<jakajansumma1) || (pelaajanSumma2<jakajansumma1)) && jakajansumma1<=21 )
			{
				if(!(pelaajanSumma1>21 && pelaajanSumma2>21))
				{
					cout<<"\n\nHavio !!!\n\n";
					gameOver=true;
					pause();
					break;
				}
			}

			if(jakajansumma1>21)
			{
				cout<<"\n\nTalo meni yli, voitto !!!\n\n";
				gameOver=true;
				pause();
				break;
			}
		}
	}
}



void ApuLuokka::OtaKortti(int monesko,JaettavaPakka* pakka) // Pelaaja ottaa yhden kortin lis‰‰
{
	assaJaettu=false;
	Pelikortti pelaajankortti1 = pakka->pelikortit.back();
	pakka->pelikortit.pop_back();

	cout<<"\n";
	cout<<"Pelaajan lisakortti 1 on : ";
	int luku2;
	luku2 = pelaajankortti1.GetRank()+1;
	
	//Debug
	//luku2=1;
	//


	if(luku2 == 1)
	{
		cout<<" 1 tai 11";
		assaJaettu=true;
	}

	else if(luku2 >=10)
	{
		luku2=10;
		cout<<"10";
	}

	else
		cout<<luku2;


	if(pelaajanSumma1==pelaajanSumma2 && !assaJaettu)
	{
		pelaajanSumma1+=luku2;
		cout<<"\n\n";
		cout<<"Yhteensa : "<<pelaajanSumma1<<endl;
		if(pelaajanSumma1>21)
		{
			cout<<"\n\nYli meni !!! Game over\n\n";
			gameOver=true;
			pause();
		}
	}

	else if(pelaajanSumma1==pelaajanSumma2 && assaJaettu)
	{
		pelaajanSumma1+=1;
		pelaajanSumma2+=11;

		if(pelaajanSumma1>21 && pelaajanSumma2>21)
		{
			cout<<"\n\nYli meni !!! Game over\n\n";
			pause();
		}

		else if(pelaajanSumma1>21)
		{
			cout<<"\n\n";
			cout<<"Yhteensa : "<<pelaajanSumma2<<endl;
			pelaajanSumma1=pelaajanSumma2;
		}

		else if(pelaajanSumma2>21)
		{
			cout<<"\n\n";
			cout<<"Yhteensa : "<<pelaajanSumma1<<endl;
			pelaajanSumma2=pelaajanSumma1;
		}

		else
		{
			cout<<"\n\n";
			cout<<"Yhteensa : "<<pelaajanSumma1<<" tai "<<pelaajanSumma2<<endl;
		}

	}

	else if(pelaajanSumma1!=pelaajanSumma2 && assaJaettu)
	{
		int luku1,luku2,luku3,luku4;
		luku1=pelaajanSumma1+1;
		luku2=pelaajanSumma1+11;
		luku3=pelaajanSumma2+1;
		luku4=pelaajanSumma2+11;

		if(pelaajanSumma1>pelaajanSumma2)
		{
			cout<<"\n\n";
			cout<<"Yhteensa : "<<luku3<<" tai "<<luku2<<endl;
			pelaajanSumma1=luku3;
			pelaajanSumma2=luku2;
		}

		else
		{
			cout<<"\n\n";
			int yhteinen;
			
			if(luku1>21)
			{
				yhteinen=luku2;
				cout<<"Yhteensa : "<<yhteinen;
				pelaajanSumma1=yhteinen;
				pelaajanSumma2=yhteinen;
			}
			
			else if(luku2>21)
			{
				yhteinen=luku1;
				cout<<"Yhteensa : "<<yhteinen;
				pelaajanSumma1=yhteinen;
				pelaajanSumma2=yhteinen;
			}

			else
			{
				cout<<"Yhteensa : "<<luku1<<" tai "<<luku2<<endl;
				pelaajanSumma1=luku3;
				pelaajanSumma2=luku2;
			}

		}
	}

	else if(pelaajanSumma1!=pelaajanSumma2 && !assaJaettu)
	{
		pelaajanSumma1+=luku2;
		pelaajanSumma2+=luku2;

		if(pelaajanSumma1>21)
		{
			cout<<"\n\nYhteensa : "<<pelaajanSumma1;
			pelaajanSumma1=pelaajanSumma2;
			cout<<"\n\nYli meni !!! Game over\n\n";
			gameOver=true;
			pause();
		}

		else if(pelaajanSumma2>21)
		{
			cout<<"\n\nYhteensa : "<<pelaajanSumma1;
			pelaajanSumma2=pelaajanSumma1;
		}

		else
		{
			cout<<"\n\nYhteensa : "<<pelaajanSumma2;
			pelaajanSumma1=pelaajanSumma2;

		}
	}
}






void ApuLuokka::pause() // System pause funktio
{
  cout << endl << "Press enter to continue...";
  getchar();
  getchar();
}


void ApuLuokka::ArvoLuku(int* luku) 
{
	if(!seedSet) // Set seed only once !
	{
		srand( time(0) ); // setting the seed value
		seedSet=!seedSet;
	}
	*luku=GetRandomNumber(0,52);
}


int ApuLuokka::GetRandomNumber(int nLow, int nHigh) 
{
	return (rand() % (nHigh - nLow + 1)) + nLow;
}


void ApuLuokka::gotoxy ( int column, int line )  // Liikutetaan kursoria konsolissa
{
  COORD coord;
  coord.X = column;
  coord.Y = line;
  SetConsoleCursorPosition(
    GetStdHandle( STD_OUTPUT_HANDLE ),
    coord
    );
}
