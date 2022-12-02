#pragma once
#include"Entidad.h"

class Tercerabola :public Entidad
{
private:

	int id, radio;

public:
	Tercerabola() {

		//this -> W = W;
		//this -> H = H;
		x = 1 + rand() % (300);
		y = 1 + rand() % (300);

		dx = dy = 7;
		visibilidad = true;

		indiceW = indiceH = 0;

		id = 1 + rand() % (2); // entre 1 y 2

		radio = 69;
	}

	~Tercerabola() {}

	void dibujars(Graphics^ gr) {



		SolidBrush^ b = gcnew SolidBrush(Color::Black);
		gr->FillEllipse(b, x, y, radio, radio);


	}

	void mover(Graphics^ gr) {

		if (x + dx<0 || x + dx + radio>gr->VisibleClipBounds.Height)
		{
			dx *= -1;
		}
		x += dx;

		if (y + dy<0 || y + dy + radio>gr->VisibleClipBounds.Height)
		{
			dy *= -1;
		}
		y += dy;

	}


	Rectangle getRectangles() {

		return Rectangle(x, y, radio, radio);

	}



};
