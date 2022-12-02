#pragma once
#include"Entidad.h"

class BolasBlue :public Entidad
{
private:

	int radio;

public:
	BolasBlue() {


		x = 1 + rand() % (300);
		y = 1 + rand() % (300);

		dx = dy = 10 + rand() % (15);
		visibilidad = true;

		indiceW = indiceH = 0;

		//id = 1 + rand() % (2); // entre 1 y 2

		radio = 69;
	}

	~BolasBlue() {}

	void dibujars(Graphics^ gr) {

		//if (id == 1)
		//{
		//	SolidBrush^ b = gcnew SolidBrush(Color::Red);
		//	gr->FillEllipse(b, x, y, radio, radio);
		//}
		//else
		//{
		//	if (id == 2)
		//	{
		//		SolidBrush^ b = gcnew SolidBrush(Color::Blue);
		//		gr->FillEllipse(b, x, y, radio, radio);
		//	}
		//}

		SolidBrush^ b = gcnew SolidBrush(Color::Blue);
		gr->FillEllipse(b, x, y, radio, radio);

	}

	void mover(Graphics^ gr) {

		if (x + dx<0 || x + dx + radio>gr->VisibleClipBounds.Width)
		{
			dx *= -1;
		}
		/*if (dy > 0)
		{
			indiceW = 7;

		}
		else
		{
			indiceW = 6;
		}*/
		x += dx;

		//switch (id)
		//{
		//case 1:

		//	if (y + dy<0 || y + dy + radio>gr->VisibleClipBounds.Height)
		//	{
		//		dy *= -1;
		//	}
		//	//if (dy > 0)
		//	//{
		//	//	indiceW = 7;

		//	//}
		//	//else
		//	//{
		//	//	indiceW = 6;
		//	//}
		//	y += dy;
		//	break;

		//case 2:

		//	if (x + dx<0 || x + dx + radio>gr->VisibleClipBounds.Width)
		//	{
		//		dx *= -1;
		//	}
		//	/*if (dy > 0)
		//	{
		//		indiceW = 7;

		//	}
		//	else
		//	{
		//		indiceW = 6;
		//	}*/
		//	x += dx;

		//	break;

		//}


	}

	Rectangle getRectangles() {

		return Rectangle(x, y, radio, radio);

	}

	void setdx(int Dx) {
		dx *= Dx;
	}
	void setdy(int Dy) {
		dy *= Dy;
	}


};

