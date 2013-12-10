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

#include "Calculatrice.hpp"
#include <cmath>

Calculatrice::Calculatrice() : QWidget() {
	//Initialisation des variables de base
	btnclic = false;
	numbersloved = false;
	clicbouton = '_';
	texteA = "";
	texteB = "";
	base = 10;

	setFixedSize(400, 275);

	//Allocation des widgets non-boutons
	layout = new QGridLayout(this);

	valid = new QDoubleValidator(-1000000000000.0, 1000000000000.0, 16, this);
	valid2 = new QIntValidator(-1000000, 1000000, this);
	ligne = new QLineEdit(this);
		ligne->setValidator(valid);
		ligne->setAlignment(Qt::AlignRight);

	//Allocation des boutons
	bouton0 = new QPushButton("0", this);
	bouton1 = new QPushButton("1", this);
	bouton2 = new QPushButton("2", this);
	bouton3 = new QPushButton("3", this);
	bouton4 = new QPushButton("4", this);
	bouton5 = new QPushButton("5", this);
	bouton6 = new QPushButton("6", this);
	bouton7 = new QPushButton("7", this);
	bouton8 = new QPushButton("8", this);
	bouton9 = new QPushButton("9", this);

	boutonA = new QPushButton("A", this);
	boutonB = new QPushButton("B", this);
	boutonC = new QPushButton("C", this);
	boutonD = new QPushButton("D", this);
	boutonE = new QPushButton("E", this);
	boutonF = new QPushButton("F", this);

	boutonSolv = new QPushButton("=", this);

	boutonAdd = new QPushButton("+", this);
	boutonSou = new QPushButton("-", this);
	boutonMul = new QPushButton("*", this);
	boutonDiv = new QPushButton("/", this);
	boutonMod = new QPushButton("mod", this);
	boutonVirg = new QPushButton(",", this);
	boutonPM = new QPushButton("+/-", this);

	boutonSin = new QPushButton("sin", this);
	boutonCos = new QPushButton("cos", this);
	boutonTan = new QPushButton("tan", this);
	boutonAsin = new QPushButton("arcsin", this);
	boutonAcos = new QPushButton("arccos", this);
	boutonAtan = new QPushButton("arctan", this);
	boutonSinh = new QPushButton("sh", this);
	boutonCosh = new QPushButton("ch", this);
	boutonTanh = new QPushButton("th", this);

	boutonExp = new QPushButton("exp", this);
	boutonLn = new QPushButton("ln", this);
	boutonLog = new QPushButton("log", this);

	boutonXExp2 = new QPushButton("x^2", this);
	boutonXExpY = new QPushButton("x^y", this);
	boutonSqrt = new QPushButton("v", this);
	boutonYRt = new QPushButton("nv", this);
	boutonInv = new QPushButton("1/x", this);

	boutonFact = new QPushButton("n!", this);
	boutonPi = new QPushButton("Pi", this);

	boutonAnd = new QPushButton("And", this);
	boutonOr = new QPushButton("Or", this);
	boutonXor = new QPushButton("Xor", this);
	boutonNot = new QPushButton("Not", this);
	boutonInt = new QPushButton("Int", this);

	base2 = new QRadioButton("Binaire", this);
	base8 = new QRadioButton("Octal", this);
	base10 = new QRadioButton("Décimal", this);
		base10->setChecked(true);
	base16 = new QRadioButton("Hexadécimal", this);

	//base=10, donc on rend les boutons hexadécimaux incliquables
	boutonA->setEnabled(false);
	boutonB->setEnabled(false);
	boutonC->setEnabled(false);
	boutonD->setEnabled(false);
	boutonE->setEnabled(false);
	boutonF->setEnabled(false);

	//Mise en place du layout
	layout->addWidget(ligne, 0, 0, 1, 10);

	layout->addWidget(bouton0, 5, 9);
	layout->addWidget(bouton1, 4, 9);
	layout->addWidget(bouton2, 4, 8);
	layout->addWidget(bouton3, 4, 7);
	layout->addWidget(bouton4, 3, 9);
	layout->addWidget(bouton5, 3, 8);
	layout->addWidget(bouton6, 3, 7);
	layout->addWidget(bouton7, 2, 9);
	layout->addWidget(bouton8, 2, 8);
	layout->addWidget(bouton9, 2, 7);

	layout->addWidget(boutonA, 7, 7);
	layout->addWidget(boutonB, 7, 8);
	layout->addWidget(boutonC, 7, 9);
	layout->addWidget(boutonD, 8, 7);
	layout->addWidget(boutonE, 8, 8);
	layout->addWidget(boutonF, 8, 9);

	layout->addWidget(boutonSolv, 5, 8);

	layout->addWidget(boutonAdd, 5, 5);
	layout->addWidget(boutonSou, 4, 5);
	layout->addWidget(boutonMul, 3, 5);
	layout->addWidget(boutonDiv, 2, 5);
	layout->addWidget(boutonMod, 7, 5);
	layout->addWidget(boutonVirg, 5, 7);
	layout->addWidget(boutonPM, 8, 5);

	layout->addWidget(boutonSin, 2, 0);
	layout->addWidget(boutonCos, 3, 0);
	layout->addWidget(boutonTan, 4, 0);
	layout->addWidget(boutonAsin, 2, 1);
	layout->addWidget(boutonAcos, 3, 1);
	layout->addWidget(boutonAtan, 4, 1);
	layout->addWidget(boutonSinh, 7, 0);
	layout->addWidget(boutonCosh, 7, 1);
	layout->addWidget(boutonTanh, 7, 2);

	layout->addWidget(boutonExp, 2, 2);
	layout->addWidget(boutonLn, 3, 2);
	layout->addWidget(boutonLog, 4, 2);

	layout->addWidget(boutonXExp2, 2, 3);
	layout->addWidget(boutonXExpY, 3, 3);
	layout->addWidget(boutonSqrt, 4, 3);
	layout->addWidget(boutonYRt, 5, 3);
	layout->addWidget(boutonInv, 5, 2);

	layout->addWidget(boutonFact, 7, 3);
	layout->addWidget(boutonPi, 5, 0);

	layout->addWidget(boutonAnd, 8, 0);
	layout->addWidget(boutonOr, 8, 1);
	layout->addWidget(boutonXor, 8, 2);
	layout->addWidget(boutonNot, 8, 3);
	layout->addWidget(boutonInt, 5, 1);

	layout->addWidget(base2, 1, 7, 1, 2);
	layout->addWidget(base8, 1, 4, 1, 2);
	layout->addWidget(base10, 1, 2, 1, 2);
	layout->addWidget(base16, 1, 0, 1, 2);

	setLayout(layout);

	//Connexion des Signaux aux Slots
	QObject::connect(bouton0, SIGNAL(clicked()), this, SLOT(fonctionBouton0()));
	QObject::connect(bouton1, SIGNAL(clicked()), this, SLOT(fonctionBouton1()));
	QObject::connect(bouton2, SIGNAL(clicked()), this, SLOT(fonctionBouton2()));
	QObject::connect(bouton3, SIGNAL(clicked()), this, SLOT(fonctionBouton3()));
	QObject::connect(bouton4, SIGNAL(clicked()), this, SLOT(fonctionBouton4()));
	QObject::connect(bouton5, SIGNAL(clicked()), this, SLOT(fonctionBouton5()));
	QObject::connect(bouton6, SIGNAL(clicked()), this, SLOT(fonctionBouton6()));
	QObject::connect(bouton7, SIGNAL(clicked()), this, SLOT(fonctionBouton7()));
	QObject::connect(bouton8, SIGNAL(clicked()), this, SLOT(fonctionBouton8()));
	QObject::connect(bouton9, SIGNAL(clicked()), this, SLOT(fonctionBouton9()));

	QObject::connect(boutonA, SIGNAL(clicked()), this, SLOT(fonctionBoutonA()));
	QObject::connect(boutonB, SIGNAL(clicked()), this, SLOT(fonctionBoutonB()));
	QObject::connect(boutonC, SIGNAL(clicked()), this, SLOT(fonctionBoutonC()));
	QObject::connect(boutonD, SIGNAL(clicked()), this, SLOT(fonctionBoutonD()));
	QObject::connect(boutonE, SIGNAL(clicked()), this, SLOT(fonctionBoutonE()));
	QObject::connect(boutonF, SIGNAL(clicked()), this, SLOT(fonctionBoutonF()));

	QObject::connect(boutonAdd, SIGNAL(clicked()), this, SLOT(fonctionBoutonAdd()));
	QObject::connect(boutonSou, SIGNAL(clicked()), this, SLOT(fonctionBoutonSou()));
	QObject::connect(boutonMul, SIGNAL(clicked()), this, SLOT(fonctionBoutonMul()));
	QObject::connect(boutonDiv, SIGNAL(clicked()), this, SLOT(fonctionBoutonDiv()));
	QObject::connect(boutonMod, SIGNAL(clicked()), this, SLOT(fonctionBoutonMod()));
	QObject::connect(boutonVirg, SIGNAL(clicked()), this, SLOT(fonctionBoutonVirg()));
	QObject::connect(boutonPM, SIGNAL(clicked()), this, SLOT(fonctionBoutonPM()));

	QObject::connect(boutonSolv, SIGNAL(clicked()), this, SLOT(fonctionBoutonSolv()));

	QObject::connect(boutonSin, SIGNAL(clicked()), this, SLOT(fonctionBoutonSin()));
	QObject::connect(boutonCos, SIGNAL(clicked()), this, SLOT(fonctionBoutonCos()));
	QObject::connect(boutonTan, SIGNAL(clicked()), this, SLOT(fonctionBoutonTan()));
	QObject::connect(boutonAsin, SIGNAL(clicked()), this, SLOT(fonctionBoutonAsin()));
	QObject::connect(boutonAcos, SIGNAL(clicked()), this, SLOT(fonctionBoutonAcos()));
	QObject::connect(boutonAtan, SIGNAL(clicked()), this, SLOT(fonctionBoutonAtan()));
	QObject::connect(boutonSinh, SIGNAL(clicked()), this, SLOT(fonctionBoutonSinh()));
	QObject::connect(boutonCosh, SIGNAL(clicked()), this, SLOT(fonctionBoutonCosh()));
	QObject::connect(boutonTanh, SIGNAL(clicked()), this, SLOT(fonctionBoutonTanh()));

	QObject::connect(boutonExp, SIGNAL(clicked()), this, SLOT(fonctionBoutonExp()));
	QObject::connect(boutonLn, SIGNAL(clicked()), this, SLOT(fonctionBoutonLn()));
	QObject::connect(boutonLog, SIGNAL(clicked()), this, SLOT(fonctionBoutonLog()));

	QObject::connect(boutonXExp2, SIGNAL(clicked()), this, SLOT(fonctionBoutonXExp2()));
	QObject::connect(boutonXExpY, SIGNAL(clicked()), this, SLOT(fonctionBoutonXExpY()));
	QObject::connect(boutonSqrt, SIGNAL(clicked()), this, SLOT(fonctionBoutonSqrt()));
	QObject::connect(boutonYRt, SIGNAL(clicked()), this, SLOT(fonctionBoutonYRt()));
	QObject::connect(boutonInv, SIGNAL(clicked()), this, SLOT(fonctionBoutonInv()));

	QObject::connect(boutonPi, SIGNAL(clicked()), this, SLOT(fonctionBoutonPi()));
	QObject::connect(boutonFact, SIGNAL(clicked()), this, SLOT(fonctionBoutonFact()));

	QObject::connect(boutonAnd, SIGNAL(clicked()), this, SLOT(fonctionBoutonAnd()));
	QObject::connect(boutonOr, SIGNAL(clicked()), this, SLOT(fonctionBoutonOr()));
	QObject::connect(boutonXor, SIGNAL(clicked()), this, SLOT(fonctionBoutonXor()));
	QObject::connect(boutonNot, SIGNAL(clicked()), this, SLOT(fonctionBoutonNot()));
	QObject::connect(boutonInt, SIGNAL(clicked()), this, SLOT(fonctionBoutonInt()));

	QObject::connect(base2, SIGNAL(clicked()), this, SLOT(fonctionBoutonbase2()));
	QObject::connect(base8, SIGNAL(clicked()), this, SLOT(fonctionBoutonbase8()));
	QObject::connect(base10, SIGNAL(clicked()), this, SLOT(fonctionBoutonbase10()));
	QObject::connect(base16, SIGNAL(clicked()), this, SLOT(fonctionBoutonbase16()));
}

//Binaire vers ...
void Calculatrice::binOct() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 2));
	texteA.setNum(nombreA, 8);
	ligne->setText(texteA);
}
void Calculatrice::binDec() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 2));
	texteA.setNum(nombreA, 10);
	ligne->setText(texteA);
}
void Calculatrice::binHex() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 2));
	texteA.setNum(nombreA, 16);
	ligne->setText(texteA);
}
//Octal vers ...
void Calculatrice::octBin() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 8));
	texteA.setNum(nombreA, 2);
	ligne->setText(texteA);
}
void Calculatrice::octDec() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 8));
	texteA.setNum(nombreA, 10);
	ligne->setText(texteA);
}
void Calculatrice::octHex() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 8));
	texteA.setNum(nombreA, 16);
	ligne->setText(texteA);
}
//Décimal vers ...
void Calculatrice::decBin() {
	texteA = ligne->text();
	int nombreA(texteA.toInt());
	texteA.setNum(nombreA, 2);
	ligne->setText(texteA);
}
void Calculatrice::decOct() {
	texteA = ligne->text();
	int nombreA(texteA.toInt());
	texteA.setNum(nombreA, 8);
	ligne->setText(texteA);
}
void Calculatrice::decHex() {
	texteA = ligne->text();
	int nombreA(texteA.toInt());
	texteA.setNum(nombreA, 16);
	ligne->setText(texteA);
}

//Héxadécimal vers ...
void Calculatrice::hexBin() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 16));
	texteA.setNum(nombreA, 2);
	ligne->setText(texteA);
}
void Calculatrice::hexOct() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 16));
	texteA.setNum(nombreA, 8);
	ligne->setText(texteA);
}
void Calculatrice::hexDec() {
	texteA = ligne->text();
	bool ok;
	int nombreA(texteA.toInt(&ok, 16));
	texteA.setNum(nombreA, 10);
	ligne->setText(texteA);
}


//Fonctions des bouton-chiffres
void Calculatrice::fonctionBouton0() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("0");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "0");
}
	void Calculatrice::fonctionBouton1() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("1");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "1");
}
void Calculatrice::fonctionBouton2() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("2");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "2");
}
void Calculatrice::fonctionBouton3() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("3");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "3");
}
void Calculatrice::fonctionBouton4() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("4");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "4");
}
void Calculatrice::fonctionBouton5() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("5");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "5");
}
void Calculatrice::fonctionBouton6() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("6");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "6");
}
void Calculatrice::fonctionBouton7() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("7");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "7");
}
void Calculatrice::fonctionBouton8() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("8");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "8");
}
void Calculatrice::fonctionBouton9() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("9");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "9");
}
//Hexadécimaux
void Calculatrice::fonctionBoutonA() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("a");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "a");
}
void Calculatrice::fonctionBoutonB() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("b");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "b");
}
void Calculatrice::fonctionBoutonC() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("c");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "c");
}
void Calculatrice::fonctionBoutonD() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("d");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "d");
}
void Calculatrice::fonctionBoutonE() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("e");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "e");
}
void Calculatrice::fonctionBoutonF() {
	if (btnclic == true || numbersloved == true) {
		ligne->setText("f");
		btnclic = false;
		numbersloved = false;
	}
	else
		ligne->setText(ligne->text() + "f");
}
//Fonctions des autres boutons
void Calculatrice::fonctionBoutonVirg() {
	bool autVirg = true;
	QString texte = ligne->text();
	int taille = texte.size();
	while (taille > 0) {
		taille--;
		if (texte[taille] == '.')
			autVirg = false;
	}
	if (autVirg == true) {
		if (btnclic == false)
			ligne->setText(ligne->text() + ".");
		else {
			ligne->setText("0.");
			btnclic = false;
		}
	}
}
void Calculatrice::fonctionBoutonPM() {
	texteA = ligne->text();
	double nombreA = texteA.toDouble();
	nombreA *= -1;
	ligne->setText(QString::number(nombreA, 'g', 16));
}

//Opérateurs Classiques
void Calculatrice::fonctionBoutonAdd() {
	clicbouton = '+';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonSou() {
	clicbouton = '-';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonMul() {
	clicbouton = '*';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonDiv() {
	clicbouton = '/';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonMod() {
	clicbouton = '%';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonXExpY() {
	clicbouton = 'Y';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonYRt() {
	clicbouton = 'R';
	texteA = ligne->text();
	btnclic = true;
}

//Fonctions des Boutons Opérateurs Binaires
void Calculatrice::fonctionBoutonAnd() {
	clicbouton = 'A';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonOr() {
	clicbouton = 'O';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonXor() {
	clicbouton = 'X';
	texteA = ligne->text();
	btnclic = true;
}
void Calculatrice::fonctionBoutonNot() {
	if (base == 8)
		octBin();
	if (base == 10)
		decBin();
	if (base == 16)
		hexBin();

	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = (nombre + 1) * -1;
	ligne->setText(QString::number(nombre));

	if (base == 8)
		binOct();
	if (base == 10)
		binDec();
	if (base == 16)
		binHex();
}
void Calculatrice::fonctionBoutonInt() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = floor(nombre);
	ligne->setText(QString::number(nombre));
}

//Bouton Égal
void Calculatrice::fonctionBoutonSolv() {
	texteB = ligne->text();
	double solvnbr(0.0);
	int solvnbr2(0);
	int aNombre = texteA.toInt();
	int bNombre = texteB.toInt();

	if (base == 10) {
		double nombreA = texteA.toDouble();
		double nombreB = texteB.toDouble();
		
		switch(clicbouton) {
			case '+':
				solvnbr = nombreA + nombreB;
				break;
			case '-':
				solvnbr = nombreA - nombreB;
				break;
			case '*':
				solvnbr = nombreA * nombreB;
				break;
			case '/':
				if (nombreB != 0)
					solvnbr = nombreA / nombreB;
				break;
			case '%':
				if (bNombre != 0)
					solvnbr2 = aNombre % bNombre;
				break;
			case 'Y':
				solvnbr = pow(nombreA, nombreB);
				break;
			case 'R':
				solvnbr = pow(nombreB, 1/nombreA);
				break;
			case 'A':
				solvnbr2 = aNombre & bNombre;
				break;
			case 'O':
				solvnbr2 = aNombre | bNombre;
				break;
			case 'X':
				solvnbr2 = aNombre ^ bNombre;
				break;
			default:
				solvnbr = 0.0;
				break;
		}
	}
	else
		switch(clicbouton) {
			case '+':
				solvnbr2 = aNombre + bNombre;
				break;
			case '-':
				solvnbr2 = aNombre - bNombre;
				break;
			case '*':
				solvnbr2 = aNombre * bNombre;
				break;
			case '/':
				if (bNombre != 0)
					solvnbr2 = aNombre / bNombre;
				break;
			case '%':
				if (bNombre != 0)
					solvnbr2 = aNombre % bNombre;
			break;
			case 'Y':
				solvnbr2 = pow(aNombre, bNombre);
				break;
			case 'A':
				solvnbr2 = aNombre & bNombre;
				break;
			case 'O':
				solvnbr2 = aNombre | bNombre;
				break;
			case 'X':
				solvnbr2 = aNombre ^ bNombre;
				break;
			default:
				solvnbr2 = 0;
				break;
		}
	numbersloved = true;
	if (base != 10 || clicbouton == '%' || clicbouton == 'A' || clicbouton == 'O' || clicbouton == 'X')
		ligne->setText(QString::number(solvnbr2));
	else
		ligne->setText(QString::number(solvnbr, 'g', 16));
}

//Fonctions des boutons des Fonctions Trigonométriques
void Calculatrice::fonctionBoutonSin() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	
	if (nombre == 3.141592653589793)
		nombre = 0;
	else
		nombre = sin(nombre);

	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonCos() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();

	if (nombre == 3.141592653589793)
		nombre = -1;
	else
		nombre = cos(nombre);

	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonTan() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();

	if (nombre == 3.141592653589793)
		nombre = 0;
	else
		nombre = tan(nombre);

	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonAsin() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = asin(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonAcos() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = acos(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonAtan() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = atan(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
//Hyperbolique
void Calculatrice::fonctionBoutonSinh() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = sinh(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonCosh() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = cosh(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonTanh() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = tanh(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}

//Exponentielle et Logaryihmes
void Calculatrice::fonctionBoutonExp() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = exp(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonLn() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = log(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonLog() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = log10(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}

//Pi et Factorielle
void Calculatrice::fonctionBoutonPi() {
	double pi = 3.141592653589793;
	ligne->setText(QString::number(pi, 'g', 16));
}

int Fact(int nombre) {
	if (nombre < 2)
		return 1;
	else
		return nombre * Fact(nombre - 1);

}
void Calculatrice::fonctionBoutonFact() {
	if (base == 2)
		binDec();
	if (base == 8)
		octDec();
	if (base == 16)
		hexDec();

	QString nbtxt = ligne->text();
	double nombre = floor(nbtxt.toDouble());
	nombre = Fact(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre));
	if (base == 2)
		decBin();
	if (base == 8)
		decOct();
	if (base == 16)
		decHex();
}

//Exposants
void Calculatrice::fonctionBoutonXExp2() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = nombre * nombre;
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonSqrt() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	nombre = sqrt(nombre);
	numbersloved = true;
	ligne->setText(QString::number(nombre, 'g', 16));
}
void Calculatrice::fonctionBoutonInv() {
	QString nbtxt = ligne->text();
	double nombre = nbtxt.toDouble();
	if (nombre != 0)
		nombre = 1/nombre;
	numbersloved = true;
	ligne->setText(QString::number(nombre));
}

//Fonctions des boutons de changement de base
void Calculatrice::fonctionBoutonbase2() {
	if (base == 8)
		octBin();
	if (base == 10)
		decBin();
	if (base == 16)
		hexBin();

	btnclic = true;
	base = 2;
	ligne->setValidator(valid2);

	bouton2->setEnabled(false);
	bouton3->setEnabled(false);
	bouton4->setEnabled(false);
	bouton5->setEnabled(false);
	bouton6->setEnabled(false);
	bouton7->setEnabled(false);
	bouton8->setEnabled(false);
	bouton9->setEnabled(false);

	boutonA->setEnabled(false);
	boutonB->setEnabled(false);
	boutonC->setEnabled(false);
	boutonD->setEnabled(false);
	boutonE->setEnabled(false);
	boutonF->setEnabled(false);

	boutonVirg->setEnabled(false);

	boutonSin->setEnabled(false);
	boutonCos->setEnabled(false);
	boutonTan->setEnabled(false);
	boutonAsin->setEnabled(false);
	boutonAcos->setEnabled(false);
	boutonAtan->setEnabled(false);

	boutonLn->setEnabled(false);
	boutonLog->setEnabled(false);
	boutonExp->setEnabled(false);

	boutonSqrt->setEnabled(false);
	boutonYRt->setEnabled(false);

	boutonPi->setEnabled(false);
	boutonInv->setEnabled(false);

	boutonInt->setEnabled(false);
}
void Calculatrice::fonctionBoutonbase8() {
	if (base == 2)
		binOct();
	if (base == 10)
		decOct();
	if (base == 16)
		hexOct();

	btnclic = true;
	base = 8;
	ligne->setValidator(valid2);

	bouton2->setEnabled(true);
	bouton3->setEnabled(true);
	bouton4->setEnabled(true);
	bouton5->setEnabled(true);
	bouton6->setEnabled(true);
	bouton7->setEnabled(true);
	bouton8->setEnabled(false);
	bouton9->setEnabled(false);

	boutonA->setEnabled(false);
	boutonB->setEnabled(false);
	boutonC->setEnabled(false);
	boutonD->setEnabled(false);
	boutonE->setEnabled(false);
	boutonF->setEnabled(false);

	boutonVirg->setEnabled(false);

	boutonSin->setEnabled(false);
	boutonCos->setEnabled(false);
	boutonTan->setEnabled(false);
	boutonAsin->setEnabled(false);
	boutonAcos->setEnabled(false);
	boutonAtan->setEnabled(false);

	boutonLn->setEnabled(false);
	boutonLog->setEnabled(false);
	boutonExp->setEnabled(false);

	boutonSqrt->setEnabled(false);
	boutonYRt->setEnabled(false);

	boutonPi->setEnabled(false);
	boutonInv->setEnabled(false);

	boutonInt->setEnabled(false);
}
void Calculatrice::fonctionBoutonbase10() {
	if (base == 2)
		binDec();
	if (base == 8)
		octDec();
	if (base == 16)
		hexDec();

	btnclic = true;
	base = 10;
	ligne->setValidator(valid);

	bouton2->setEnabled(true);
	bouton3->setEnabled(true);
	bouton4->setEnabled(true);
	bouton5->setEnabled(true);
	bouton6->setEnabled(true);
	bouton7->setEnabled(true);
	bouton8->setEnabled(true);
	bouton9->setEnabled(true);

	boutonA->setEnabled(false);
	boutonB->setEnabled(false);
	boutonC->setEnabled(false);
	boutonD->setEnabled(false);
	boutonE->setEnabled(false);
	boutonF->setEnabled(false);

	boutonVirg->setEnabled(true);

	boutonSin->setEnabled(true);
	boutonCos->setEnabled(true);
	boutonTan->setEnabled(true);
	boutonAsin->setEnabled(true);
	boutonAcos->setEnabled(true);
	boutonAtan->setEnabled(true);

	boutonLn->setEnabled(true);
	boutonLog->setEnabled(true);
	boutonExp->setEnabled(true);

	boutonSqrt->setEnabled(true);
	boutonYRt->setEnabled(true);

	boutonPi->setEnabled(true);
	boutonInv->setEnabled(true);

	boutonInt->setEnabled(true);
}
void Calculatrice::fonctionBoutonbase16() {
	if (base == 2)
		binHex();
	if (base == 8)
		octHex();
	if (base == 10)
		decHex();

	btnclic = true;
	base = 16;
	ligne->setValidator(valid2);

	bouton2->setEnabled(true);
	bouton3->setEnabled(true);
	bouton4->setEnabled(true);
	bouton5->setEnabled(true);
	bouton6->setEnabled(true);
	bouton7->setEnabled(true);
	bouton8->setEnabled(true);
	bouton9->setEnabled(true);

	boutonA->setEnabled(true);
	boutonB->setEnabled(true);
	boutonC->setEnabled(true);
	boutonD->setEnabled(true);
	boutonE->setEnabled(true);
	boutonF->setEnabled(true);

	boutonVirg->setEnabled(false);

	boutonSin->setEnabled(false);
	boutonCos->setEnabled(false);
	boutonTan->setEnabled(false);
	boutonAsin->setEnabled(false);
	boutonAcos->setEnabled(false);
	boutonAtan->setEnabled(false);

	boutonLn->setEnabled(false);
	boutonLog->setEnabled(false);
	boutonExp->setEnabled(false);

	boutonSqrt->setEnabled(false);
	boutonYRt->setEnabled(false);

	boutonPi->setEnabled(false);
	boutonInv->setEnabled(false);

	boutonInt->setEnabled(false);
}
