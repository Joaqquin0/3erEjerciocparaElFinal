#pragma once
#include"Entidad.h"

class Personaje:public Entidad
{
private:

	int vidas;

public:
	Personaje(int x, int y, int W, int H, int vidas ) {

		this->x = x;
		this->y = y;
		this->W = W;
		this->H = H;
		this->vidas = vidas;

		dx = dy = 10;
		indiceH = indiceW = 0;
		visibilidad = true;

	}

	~Personaje(){}

	void mover(Graphics^ gr, char Tecla) {

		switch (Tecla)
		{
		case 'A':

			if (x + dx > 0) {

				x -= dx;
				indiceH = 1;

			}

			break;

		case 'D':

			if (x + W + dx < gr->VisibleClipBounds.Width) {

				x += dx;
				indiceH = 2;


			}
			break;

		case 'W':

			if (y > 0) {

				y -= dy;
				indiceH = 3;

			}

			break;

		case 'S':

			if (y + H + dy < 790) {

				y += dy;
				indiceH = 0;


			}
			break;

		}


		indiceW++;
		if (indiceW > 3)
		{
			indiceW = 0;
		}


	}
	int getvidas() { return vidas; }
	void menosvidas() { vidas--; }

};

