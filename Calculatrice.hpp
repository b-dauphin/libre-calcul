/*
This file is part of LibreCalcul

The MIT License (MIT)

Copyright (c) 2011 Benjamin Dauphin

Permission is hereby granted, free of charge, to any person obtaining a copy of
this software and associated documentation files (the "Software"), to deal in
the Software without restriction, including without limitation the rights to
use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of
the Software, and to permit persons to whom the Software is furnished to do so,
subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS
FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER
IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN
CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*/

#ifndef CALCULATRICE_HPP
#define CALCULATRICE_HPP

#include <QObject>

#include <QPushButton>
#include <QRadioButton>
#include <QGridLayout>
#include <QWidget>
#include <QLineEdit>
#include <QIntValidator>
#include <QDoubleValidator>
#include <QString>
#include <QChar>

class Calculatrice : public QWidget
{
	Q_OBJECT

	public:
		Calculatrice();

	public slots:
		//Fonctions des Bouton-chiffres
		void fonctionBouton0();
		void fonctionBouton1();
		void fonctionBouton2();
		void fonctionBouton3();
		void fonctionBouton4();
		void fonctionBouton5();
		void fonctionBouton6();
		void fonctionBouton7();
		void fonctionBouton8();
		void fonctionBouton9();
		//Hexadécimaux
		void fonctionBoutonA();
		void fonctionBoutonB();
		void fonctionBoutonC();
		void fonctionBoutonD();
		void fonctionBoutonE();
		void fonctionBoutonF();

		//Fonctions des Opérateurs Basiques
		void fonctionBoutonAdd();
		void fonctionBoutonSou();
		void fonctionBoutonMul();
		void fonctionBoutonDiv();
		void fonctionBoutonMod();

		void fonctionBoutonVirg();
		void fonctionBoutonSolv();
		void fonctionBoutonPM();

		//Fonctions Trigonométriques
		void fonctionBoutonSin();
		void fonctionBoutonCos();
		void fonctionBoutonTan();
		void fonctionBoutonAsin();
		void fonctionBoutonAcos();
		void fonctionBoutonAtan();
		//Hyperboliques
		void fonctionBoutonSinh();
		void fonctionBoutonCosh();
		void fonctionBoutonTanh();

		//Fonctions Exponentielle et Logarithmes
		void fonctionBoutonExp();
		void fonctionBoutonLn();
		void fonctionBoutonLog();

		//Fonctions d'exposants
		void fonctionBoutonXExp2();
		void fonctionBoutonXExpY();
		void fonctionBoutonSqrt();
		void fonctionBoutonYRt();
		void fonctionBoutonInv();

		void fonctionBoutonPi();
		void fonctionBoutonFact();

		//Fonctions des Opérateurs binaires
		void fonctionBoutonAnd();
		void fonctionBoutonOr();
		void fonctionBoutonXor();
		void fonctionBoutonNot();
		void fonctionBoutonInt();

		//Fonctions des changements de base
		void fonctionBoutonbase2();
		void fonctionBoutonbase8();
		void fonctionBoutonbase10();
		void fonctionBoutonbase16();

		void binOct();
		void binDec();
		void binHex();
		void octBin();
		void octDec();
		void octHex();
		void decBin();
		void decOct();
		void decHex();
		void hexBin();
		void hexOct();
		void hexDec();

	private:
		//Widgets non-boutons
		QGridLayout *layout;

		QLineEdit *ligne;
		QDoubleValidator *valid;
		QIntValidator *valid2;

		//Liste des boutons
		QPushButton *bouton0;
		QPushButton *bouton1;
		QPushButton *bouton2;
		QPushButton *bouton3;
		QPushButton *bouton4;
		QPushButton *bouton5;
		QPushButton *bouton6;
		QPushButton *bouton7;
		QPushButton *bouton8;
		QPushButton *bouton9;

		QPushButton *boutonA;
		QPushButton *boutonB;
		QPushButton *boutonC;
		QPushButton *boutonD;
		QPushButton *boutonE;
		QPushButton *boutonF;

		QPushButton *boutonSolv;

		QPushButton *boutonAdd;
		QPushButton *boutonSou;
		QPushButton *boutonMul;
		QPushButton *boutonDiv;
		QPushButton *boutonMod;
		QPushButton *boutonVirg;
		QPushButton *boutonPM;

		QPushButton *boutonSin;
		QPushButton *boutonCos;
		QPushButton *boutonTan;
		QPushButton *boutonAsin;
		QPushButton *boutonAcos;
		QPushButton *boutonAtan;
		QPushButton *boutonSinh;
		QPushButton *boutonCosh;
		QPushButton *boutonTanh;

		QPushButton *boutonExp;
		QPushButton *boutonLn;
		QPushButton *boutonLog;

		QPushButton *boutonXExp2;
		QPushButton *boutonXExpY;
		QPushButton *boutonSqrt;
		QPushButton *boutonYRt;
		QPushButton *boutonInv;

		QPushButton *boutonFact;
		QPushButton *boutonPi;

		QPushButton *boutonAnd;
		QPushButton *boutonOr;
		QPushButton *boutonXor;
		QPushButton *boutonNot;
		QPushButton *boutonInt;

		QRadioButton *base2;
		QRadioButton *base8;
		QRadioButton *base10;
		QRadioButton *base16;

		//Variables et Booléens
		char clicbouton;
		QString texteA;
		QString texteB;
		bool btnclic;
		bool numbersloved;
		int base;
};

#endif // CALCULATRICE_HPP
