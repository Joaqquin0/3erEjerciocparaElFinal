#pragma once
#include"Controlador.h"
#include"Personaje.h"
#include"Archivo.h"


namespace My3erEjerciocparaElFinal {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Resumen de MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
			srand(time(NULL));

			gr = this->CreateGraphics();
			ct = BufferedGraphicsManager::Current;
			buffer = ct->Allocate(gr, this->ClientRectangle);

			archivo = new File();
			archivo->leerdatos();

			bmpersonaje = gcnew Bitmap("imagen\\Alien.png");
			controlador = new Controlador(archivo->getx(), archivo->gety(), bmpersonaje, archivo->getvida());

			controlador->agregarBola();
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén usando.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::ComponentModel::IContainer^ components;
	protected:

	private:
		/// <summary>
		/// Variable del diseñador necesaria.
		/// </summary>


		Graphics^ gr;
		BufferedGraphicsContext^ ct;
		BufferedGraphics^ buffer;

		
		Controlador* controlador;
		Bitmap^ bmpersonaje;

		int contaador;

	private: System::Windows::Forms::Timer^ timer1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Timer^ timer2;
		   File* archivo;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido de este método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->timer2 = (gcnew System::Windows::Forms::Timer(this->components));
			this->SuspendLayout();
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Tick += gcnew System::EventHandler(this, &MyForm::timer1_Tick);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(339, 9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"label1";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(408, 13);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(35, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"label2";
			// 
			// timer2
			// 
			this->timer2->Enabled = true;
			this->timer2->Interval = 1000;
			this->timer2->Tick += gcnew System::EventHandler(this, &MyForm::timer2_Tick);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(516, 474);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Name = L"MyForm";
			this->Text = L"MyForm";
			this->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &MyForm::MyForm_KeyDown);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void timer1_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		buffer->Graphics->Clear(Color::White);

		controlador->dibujartodo(buffer->Graphics, bmpersonaje);

		controlador->movertodo(buffer->Graphics);

		controlador->colision(buffer->Graphics, archivo->getx(), archivo->gety());

		label1->Text = "Vidas: " + controlador->getpersonaje()->getvidas();
		label2->Text = "Tiempo: " + contaador;

		if (controlador->getpersonaje()->getvidas() == 0) {

			timer1->Enabled = false;
			MessageBox::Show("PERDISTE");
			this->Close();

		}

		if (contaador >=20)
		{
			timer1->Enabled = false;
			MessageBox::Show("GANASTE");
			this->Close();
		}

		//render
		buffer->Render(gr);

	
	}
	private: System::Void MyForm_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e) {
	
		switch (e->KeyCode)
		{
		case Keys::Left:

			controlador->getpersonaje()->mover(buffer->Graphics, 'A');
			//controlador->getZombie()->mover(buffer->Graphics, 'A');
			break;

		case Keys::Down:	

			controlador->getpersonaje()->mover(buffer->Graphics, 'S');
			break;

		case Keys::Right:

			controlador->getpersonaje()->mover(buffer->Graphics, 'D');
			break;

		case Keys::Up:

			controlador->getpersonaje()->mover(buffer->Graphics, 'W');
			break;
		}
	
	
	}
	private: System::Void timer2_Tick(System::Object^ sender, System::EventArgs^ e) {
	
		contaador++;

	}
};
}
