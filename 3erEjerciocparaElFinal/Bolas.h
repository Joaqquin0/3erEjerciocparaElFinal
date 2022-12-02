#pragma once
#include"Entidad.h"

class Bolas:public Entidad
{
private:

	int id, radio;

public:
	Bolas() {

		//this -> W = W;
		//this -> H = H;
		x = 1 + rand() % (300);
		y = 1 + rand() % (300);

		dx=dy= 10 + rand() % (15);
		visibilidad = true;

		indiceW = indiceH = 0;

		id= 1 + rand() % (2); // entre 1 y 2

		radio = 69;
	}

	~Bolas(){}

	void dibujars(Graphics^gr) {

		
		
			SolidBrush^ b = gcnew SolidBrush(Color::Red);
			gr->FillEllipse(b, x, y, radio, radio);
		

	

	}

	void mover(Graphics^ gr) {



		if (y + dy<0 || y + dy + radio>gr->VisibleClipBounds.Height)
		{
			dy *= -1;
		}
		//if (dy > 0)
		//{
		//	indiceW = 7;

		//}
		//else
		//{
		//	indiceW = 6;
		//}
		y += dy;

	}


	Rectangle getRectangles() {

		return Rectangle(x, y, radio, radio);

	}


	void setdy(int Dy) {
		dy *= Dy;
	}


};

