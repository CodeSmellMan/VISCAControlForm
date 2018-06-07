#pragma once
#include "SerialHandler.h"
#include "ViscaController.h"
#include "ViscaCommandConstants.h"

namespace CppWinForm1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			
			sHandler = new SerialHandler();
			if (sHandler->getCOMopened() == false)
			{
				MessageBox::Show("COM-port finnes ikke eller er opptatt",
				"Kunne ikke åpne COM-port",
				MessageBoxButtons::OK,
				//MessageBoxIcon::Warning // for Warning
				MessageBoxIcon::Error // for Error
				//MessageBoxIcon.Information  // for Information
				//MessageBoxIcon.Question // for Question
				);
				Application::Exit();
			}
			cam1 = new ViscaController(1, sHandler);
			cam2 = new ViscaController(2, sHandler);
			cam1->setAddress();
			currentCam = cam1;
		
			panStep = 50;
			tiltStep = 20;
			zoomStep = 200;

			precisionMode = false;

			runding->Controls->Add(joystick);
			float px = ((float)currentCam->panCurr / (float)VISCA_PAN_MAX_POS)*(float)(runding->Width - joystick->Width);
			float py = (1 - ((float)currentCam->tiltCurr / (float)VISCA_TILT_MAX_POS))*(float)(runding->Height - joystick->Height);
			joystick->Location = Point(px, py);
			joystick->BackColor = System::Drawing::Color::Transparent;

			zoomScroll->Value = 285 - currentCam->zoomCurr/10;
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
				delete sHandler;
				if (cam1)
				{
					delete cam1;
				}
				if (cam2)
				{
					delete cam2;
				}
				if (currentCam)
				{
					delete currentCam;
				}
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	protected:
	private: System::Windows::Forms::Button^  cam2btn;
	private: System::Windows::Forms::Button^  cam1btn;
	private: System::Windows::Forms::Panel^  panel4;
	private: System::Windows::Forms::Panel^  panel3;
	private: System::Windows::Forms::Panel^  panel2;


	private: System::Windows::Forms::PictureBox^  pictureBox2;
	private: System::Windows::Forms::PictureBox^  joystick;





	protected:

	private:
		
		Point StartPoint;
		SerialHandler * sHandler;
		ViscaController * cam1;
		ViscaController * cam2;
		ViscaController * currentCam;

		int panStep;
		int zoomStep;
		int tiltStep;

		bool precisionMode;

	private: System::Windows::Forms::PictureBox^  runding;
	private: System::Windows::Forms::Panel^  joystickPanel;
	private: System::Windows::Forms::VScrollBar^  zoomScroll;
	private: System::Windows::Forms::Button^  resetBtn;


	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::PictureBox^  pictureBox5;
	private: System::Windows::Forms::PictureBox^  pictureBox4;
	private: System::Windows::Forms::Button^  pilerBtn;
	private: System::Windows::Forms::Button^  joystickBtn;
	private: System::Windows::Forms::Panel^  pilerPanel;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Button^  zoomOutBtn;
	private: System::Windows::Forms::Button^  left;

	private: System::Windows::Forms::Button^  right;
	private: System::Windows::Forms::Button^  ned;
	private: System::Windows::Forms::Button^  zoomInbtn;
	private: System::Windows::Forms::Button^  opp;
	private: System::Windows::Forms::Button^  presisjonBtn;








			 /// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->cam2btn = (gcnew System::Windows::Forms::Button());
			this->cam1btn = (gcnew System::Windows::Forms::Button());
			this->panel4 = (gcnew System::Windows::Forms::Panel());
			this->pictureBox2 = (gcnew System::Windows::Forms::PictureBox());
			this->panel3 = (gcnew System::Windows::Forms::Panel());
			this->resetBtn = (gcnew System::Windows::Forms::Button());
			this->panel2 = (gcnew System::Windows::Forms::Panel());
			this->joystickBtn = (gcnew System::Windows::Forms::Button());
			this->pilerBtn = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->joystick = (gcnew System::Windows::Forms::PictureBox());
			this->runding = (gcnew System::Windows::Forms::PictureBox());
			this->joystickPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox5 = (gcnew System::Windows::Forms::PictureBox());
			this->pictureBox4 = (gcnew System::Windows::Forms::PictureBox());
			this->zoomScroll = (gcnew System::Windows::Forms::VScrollBar());
			this->pilerPanel = (gcnew System::Windows::Forms::Panel());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->zoomOutBtn = (gcnew System::Windows::Forms::Button());
			this->left = (gcnew System::Windows::Forms::Button());
			this->right = (gcnew System::Windows::Forms::Button());
			this->ned = (gcnew System::Windows::Forms::Button());
			this->zoomInbtn = (gcnew System::Windows::Forms::Button());
			this->opp = (gcnew System::Windows::Forms::Button());
			this->presisjonBtn = (gcnew System::Windows::Forms::Button());
			this->panel1->SuspendLayout();
			this->panel4->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->BeginInit();
			this->panel3->SuspendLayout();
			this->panel2->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->joystick))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->runding))->BeginInit();
			this->joystickPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->BeginInit();
			this->pilerPanel->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
				static_cast<System::Int32>(static_cast<System::Byte>(65)));
			this->panel1->Controls->Add(this->cam2btn);
			this->panel1->Controls->Add(this->cam1btn);
			this->panel1->Controls->Add(this->panel4);
			this->panel1->Controls->Add(this->panel3);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Left;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(160, 462);
			this->panel1->TabIndex = 0;
			// 
			// cam2btn
			// 
			this->cam2btn->FlatAppearance->BorderSize = 0;
			this->cam2btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cam2btn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cam2btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cam2btn->Location = System::Drawing::Point(0, 105);
			this->cam2btn->Name = L"cam2btn";
			this->cam2btn->Size = System::Drawing::Size(160, 42);
			this->cam2btn->TabIndex = 3;
			this->cam2btn->Text = L"Camera 2";
			this->cam2btn->UseVisualStyleBackColor = true;
			this->cam2btn->Click += gcnew System::EventHandler(this, &MyForm::cam2btn_Click);
			// 
			// cam1btn
			// 
			this->cam1btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->cam1btn->FlatAppearance->BorderSize = 0;
			this->cam1btn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->cam1btn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->cam1btn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->cam1btn->Location = System::Drawing::Point(0, 57);
			this->cam1btn->Name = L"cam1btn";
			this->cam1btn->Size = System::Drawing::Size(160, 42);
			this->cam1btn->TabIndex = 2;
			this->cam1btn->Text = L"Camera 1";
			this->cam1btn->UseVisualStyleBackColor = true;
			this->cam1btn->Click += gcnew System::EventHandler(this, &MyForm::cam1btn_Click);
			// 
			// panel4
			// 
			this->panel4->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(126)),
				static_cast<System::Int32>(static_cast<System::Byte>(49)));
			this->panel4->Controls->Add(this->pictureBox2);
			this->panel4->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel4->Location = System::Drawing::Point(0, 0);
			this->panel4->Name = L"panel4";
			this->panel4->Size = System::Drawing::Size(160, 56);
			this->panel4->TabIndex = 1;
			// 
			// pictureBox2
			// 
			this->pictureBox2->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox2.BackgroundImage")));
			this->pictureBox2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox2->Location = System::Drawing::Point(38, 3);
			this->pictureBox2->Name = L"pictureBox2";
			this->pictureBox2->Size = System::Drawing::Size(81, 50);
			this->pictureBox2->TabIndex = 0;
			this->pictureBox2->TabStop = false;
			// 
			// panel3
			// 
			this->panel3->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
				static_cast<System::Int32>(static_cast<System::Byte>(55)));
			this->panel3->Controls->Add(this->resetBtn);
			this->panel3->Dock = System::Windows::Forms::DockStyle::Bottom;
			this->panel3->Location = System::Drawing::Point(0, 376);
			this->panel3->Name = L"panel3";
			this->panel3->Size = System::Drawing::Size(160, 86);
			this->panel3->TabIndex = 0;
			// 
			// resetBtn
			// 
			this->resetBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->resetBtn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->resetBtn->ForeColor = System::Drawing::SystemColors::ButtonHighlight;
			this->resetBtn->Location = System::Drawing::Point(38, 11);
			this->resetBtn->Name = L"resetBtn";
			this->resetBtn->Size = System::Drawing::Size(79, 63);
			this->resetBtn->TabIndex = 3;
			this->resetBtn->Text = L"Reset";
			this->resetBtn->UseVisualStyleBackColor = true;
			this->resetBtn->Click += gcnew System::EventHandler(this, &MyForm::resetBtn_Click);
			// 
			// panel2
			// 
			this->panel2->BackColor = System::Drawing::SystemColors::HighlightText;
			this->panel2->Controls->Add(this->joystickBtn);
			this->panel2->Controls->Add(this->pilerBtn);
			this->panel2->Controls->Add(this->label1);
			this->panel2->Dock = System::Windows::Forms::DockStyle::Top;
			this->panel2->Location = System::Drawing::Point(160, 0);
			this->panel2->Name = L"panel2";
			this->panel2->Size = System::Drawing::Size(564, 56);
			this->panel2->TabIndex = 1;
			// 
			// joystickBtn
			// 
			this->joystickBtn->BackColor = System::Drawing::SystemColors::ControlDark;
			this->joystickBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"joystickBtn.BackgroundImage")));
			this->joystickBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->joystickBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->joystickBtn->Location = System::Drawing::Point(424, 7);
			this->joystickBtn->Name = L"joystickBtn";
			this->joystickBtn->Size = System::Drawing::Size(56, 46);
			this->joystickBtn->TabIndex = 5;
			this->joystickBtn->UseVisualStyleBackColor = false;
			this->joystickBtn->Click += gcnew System::EventHandler(this, &MyForm::joystickBtn_Click);
			// 
			// pilerBtn
			// 
			this->pilerBtn->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pilerBtn.BackgroundImage")));
			this->pilerBtn->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pilerBtn->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->pilerBtn->Location = System::Drawing::Point(486, 7);
			this->pilerBtn->Name = L"pilerBtn";
			this->pilerBtn->Size = System::Drawing::Size(56, 46);
			this->pilerBtn->TabIndex = 4;
			this->pilerBtn->UseVisualStyleBackColor = true;
			this->pilerBtn->Click += gcnew System::EventHandler(this, &MyForm::switchBtn_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 14.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(16, 15);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(230, 26);
			this->label1->TabIndex = 3;
			this->label1->Text = L"Kamera Bevegelsesstyring";
			// 
			// joystick
			// 
			this->joystick->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"joystick.BackgroundImage")));
			this->joystick->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->joystick->Cursor = System::Windows::Forms::Cursors::NoMove2D;
			this->joystick->Location = System::Drawing::Point(127, 113);
			this->joystick->Name = L"joystick";
			this->joystick->Size = System::Drawing::Size(51, 51);
			this->joystick->TabIndex = 4;
			this->joystick->TabStop = false;
			this->joystick->MouseDown += gcnew MouseEventHandler(this, &MyForm::joystick_MouseDown);
			this->joystick->MouseMove += gcnew MouseEventHandler(this, &MyForm::joystick_MouseMove);
			this->joystick->MouseUp += gcnew MouseEventHandler(this, &MyForm::joystick_MouseUp);
			// 
			// runding
			// 
			this->runding->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"runding.BackgroundImage")));
			this->runding->BackgroundImageLayout = System::Windows::Forms::ImageLayout::None;
			this->runding->Location = System::Drawing::Point(53, 90);
			this->runding->Name = L"runding";
			this->runding->Size = System::Drawing::Size(258, 140);
			this->runding->TabIndex = 5;
			this->runding->TabStop = false;
			// 
			// joystickPanel
			// 
			this->joystickPanel->Controls->Add(this->pictureBox5);
			this->joystickPanel->Controls->Add(this->pictureBox4);
			this->joystickPanel->Controls->Add(this->zoomScroll);
			this->joystickPanel->Controls->Add(this->joystick);
			this->joystickPanel->Controls->Add(this->runding);
			this->joystickPanel->Location = System::Drawing::Point(166, 80);
			this->joystickPanel->Name = L"joystickPanel";
			this->joystickPanel->Size = System::Drawing::Size(558, 319);
			this->joystickPanel->TabIndex = 6;
			// 
			// pictureBox5
			// 
			this->pictureBox5->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox5.BackgroundImage")));
			this->pictureBox5->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox5->Location = System::Drawing::Point(456, 233);
			this->pictureBox5->Name = L"pictureBox5";
			this->pictureBox5->Size = System::Drawing::Size(49, 62);
			this->pictureBox5->TabIndex = 8;
			this->pictureBox5->TabStop = false;
			// 
			// pictureBox4
			// 
			this->pictureBox4->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox4.BackgroundImage")));
			this->pictureBox4->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox4->Location = System::Drawing::Point(456, 47);
			this->pictureBox4->Name = L"pictureBox4";
			this->pictureBox4->Size = System::Drawing::Size(49, 62);
			this->pictureBox4->TabIndex = 7;
			this->pictureBox4->TabStop = false;
			// 
			// zoomScroll
			// 
			this->zoomScroll->Location = System::Drawing::Point(412, 47);
			this->zoomScroll->Maximum = 285;
			this->zoomScroll->Name = L"zoomScroll";
			this->zoomScroll->Size = System::Drawing::Size(23, 248);
			this->zoomScroll->TabIndex = 6;
			this->zoomScroll->Scroll += gcnew System::Windows::Forms::ScrollEventHandler(this, &MyForm::zoomScroll_Scroll);
			// 
			// pilerPanel
			// 
			this->pilerPanel->Controls->Add(this->pictureBox1);
			this->pilerPanel->Controls->Add(this->zoomOutBtn);
			this->pilerPanel->Controls->Add(this->left);
			this->pilerPanel->Controls->Add(this->right);
			this->pilerPanel->Controls->Add(this->ned);
			this->pilerPanel->Controls->Add(this->zoomInbtn);
			this->pilerPanel->Controls->Add(this->opp);
			this->pilerPanel->Controls->Add(this->presisjonBtn);
			this->pilerPanel->Location = System::Drawing::Point(181, 80);
			this->pilerPanel->Name = L"pilerPanel";
			this->pilerPanel->Size = System::Drawing::Size(521, 319);
			this->pilerPanel->TabIndex = 7;
			this->pilerPanel->Visible = false;
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.BackgroundImage")));
			this->pictureBox1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->pictureBox1->Location = System::Drawing::Point(407, 137);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(52, 73);
			this->pictureBox1->TabIndex = 7;
			this->pictureBox1->TabStop = false;
			// 
			// zoomOutBtn
			// 
			this->zoomOutBtn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zoomOutBtn->Location = System::Drawing::Point(407, 233);
			this->zoomOutBtn->Name = L"zoomOutBtn";
			this->zoomOutBtn->Size = System::Drawing::Size(52, 50);
			this->zoomOutBtn->TabIndex = 6;
			this->zoomOutBtn->Text = L"-";
			this->zoomOutBtn->UseVisualStyleBackColor = true;
			this->zoomOutBtn->Click += gcnew System::EventHandler(this, &MyForm::zoomOutBtn_Click);
			// 
			// left
			// 
			this->left->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"left.BackgroundImage")));
			this->left->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->left->Location = System::Drawing::Point(32, 137);
			this->left->Name = L"left";
			this->left->Size = System::Drawing::Size(81, 68);
			this->left->TabIndex = 5;
			this->left->UseVisualStyleBackColor = true;
			this->left->Click += gcnew System::EventHandler(this, &MyForm::left_Click);
			// 
			// right
			// 
			this->right->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"right.BackgroundImage")));
			this->right->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->right->Location = System::Drawing::Point(209, 137);
			this->right->Name = L"right";
			this->right->Size = System::Drawing::Size(81, 68);
			this->right->TabIndex = 4;
			this->right->UseVisualStyleBackColor = true;
			this->right->Click += gcnew System::EventHandler(this, &MyForm::right_Click);
			// 
			// ned
			// 
			this->ned->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ned.BackgroundImage")));
			this->ned->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->ned->Location = System::Drawing::Point(128, 217);
			this->ned->Name = L"ned";
			this->ned->Size = System::Drawing::Size(68, 81);
			this->ned->TabIndex = 3;
			this->ned->UseVisualStyleBackColor = true;
			this->ned->Click += gcnew System::EventHandler(this, &MyForm::ned_Click);
			// 
			// zoomInbtn
			// 
			this->zoomInbtn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 21.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->zoomInbtn->Location = System::Drawing::Point(407, 70);
			this->zoomInbtn->Name = L"zoomInbtn";
			this->zoomInbtn->Size = System::Drawing::Size(52, 50);
			this->zoomInbtn->TabIndex = 2;
			this->zoomInbtn->Text = L"+";
			this->zoomInbtn->UseVisualStyleBackColor = true;
			this->zoomInbtn->Click += gcnew System::EventHandler(this, &MyForm::zoomInbtn_Click);
			// 
			// opp
			// 
			this->opp->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"opp.BackgroundImage")));
			this->opp->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Zoom;
			this->opp->Location = System::Drawing::Point(127, 47);
			this->opp->Name = L"opp";
			this->opp->Size = System::Drawing::Size(68, 81);
			this->opp->TabIndex = 1;
			this->opp->UseVisualStyleBackColor = true;
			this->opp->Click += gcnew System::EventHandler(this, &MyForm::opp_Click);
			// 
			// presisjonBtn
			// 
			this->presisjonBtn->Font = (gcnew System::Drawing::Font(L"Palatino Linotype", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->presisjonBtn->Location = System::Drawing::Point(119, 134);
			this->presisjonBtn->Name = L"presisjonBtn";
			this->presisjonBtn->Size = System::Drawing::Size(84, 76);
			this->presisjonBtn->TabIndex = 0;
			this->presisjonBtn->Text = L"Presisjons modus";
			this->presisjonBtn->UseVisualStyleBackColor = true;
			this->presisjonBtn->Click += gcnew System::EventHandler(this, &MyForm::precBtn_Click);
			// 
			// MyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(724, 462);
			this->Controls->Add(this->pilerPanel);
			this->Controls->Add(this->joystickPanel);
			this->Controls->Add(this->panel2);
			this->Controls->Add(this->panel1);
			this->Name = L"MyForm";
			this->Text = L"Camera Control";
			this->panel1->ResumeLayout(false);
			this->panel4->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox2))->EndInit();
			this->panel3->ResumeLayout(false);
			this->panel2->ResumeLayout(false);
			this->panel2->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->joystick))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->runding))->EndInit();
			this->joystickPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox5))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox4))->EndInit();
			this->pilerPanel->ResumeLayout(false);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
		//this->joystick->MouseDown += gcnew MouseEventHandler(this, &MyForm::joystick_MouseDown);
		//this->joystick->MouseMove += gcnew MouseEventHandler(this, &MyForm::joystick_MouseMove);
		//this->joystick->MouseUp += gcnew MouseEventHandler(this, &MyForm::joystick_MouseUp);
		private: void joystick_MouseUp(Object^ sender, MouseEventArgs^ e)
		{
			Point pt = joystick->Location;
			int width = runding->Width - joystick->Width;
			int height = runding->Height - joystick->Height;
			float horizFactor = (float)pt.X/(float)width;
			float verticFactor = 1 - (float)pt.Y/(float)height;

			if (horizFactor < 0)
			{
				horizFactor = 0;
			}
			else if (horizFactor > 1)
			{
				horizFactor = 1;
			}
			if (verticFactor < 0)
			{
				verticFactor = 0;
			}
			else if (verticFactor > 1)
			{
				verticFactor = 1;
			}

			float panVal = horizFactor * (float)VISCA_PAN_MAX_POS;
			float tiltVal = verticFactor * (float)VISCA_TILT_MAX_POS;

			System::Diagnostics::Debug::WriteLine(panVal);
			currentCam->setPanTilt((int)panVal, (int)tiltVal);
			currentCam->panCurr = (int)panVal;
			currentCam->tiltCurr = (int)tiltVal;
		}

		private: void joystick_MouseDown(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				StartPoint = Point(e->X, e->Y);
			}
		}

		private: void joystick_MouseMove(Object^ sender, MouseEventArgs^ e)
		{
			if (e->Button == System::Windows::Forms::MouseButtons::Left)
			{
				PictureBox^ pb = joystick;
				Point pt = pb->Location;

				if (pt.X >= 0 && pt.Y >= 0 && pt.X <= runding->Width - joystick->Width && pt.Y <= runding->Height - joystick->Height)
				{
					pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					pb->Location = pt;
				}
				else if (pt.X >= 0 && pt.X <= runding->Width - joystick->Width && pt.Y >= 0 && pt.Y > runding->Height - joystick->Height) // For langt ned
				{
					if (e->Y - StartPoint.Y < 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					pb->Location = pt;
				}
				else if (pt.X >= 0 && pt.X <= runding->Width - joystick->Width && pt.Y < 0 && pt.Y <= runding->Height - joystick->Height) // For langt opp
				{
					if (e->Y - StartPoint.Y > 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					pb->Location = pt;
				}
				else if (pt.X >= 0 && pt.X > runding->Width - joystick->Width && pt.Y >= 0 && pt.Y <= runding->Height - joystick->Height) // For langt høyre
				{
					if (e->X - StartPoint.X < 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
				else if (pt.X < 0 && pt.X <= runding->Width - joystick->Width && pt.Y >= 0 && pt.Y <= runding->Height - joystick->Height) // For langt høyre
				{
					if (e->X - StartPoint.X > 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
				else if (pt.X < 0 && pt.X <= runding->Width - joystick->Width && pt.Y < 0 && pt.Y <= runding->Height - joystick->Height) // Venstre oppe hjørne
				{
					if (e->X - StartPoint.X > 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else if(e->X - StartPoint.X > 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					else if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
				else if (pt.X < 0 && pt.X <= runding->Width - joystick->Width && pt.Y >= 0 && pt.Y > runding->Height - joystick->Height) // Venstre nede hjørne
				{
					if (e->X - StartPoint.X > 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else if (e->X - StartPoint.X > 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					else if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
				else if (pt.X >= 0 && pt.X > runding->Width - joystick->Width && pt.Y < 0 && pt.Y <= runding->Height - joystick->Height) // Høyre oppe hjørne
				{
					if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					else if (e->X - StartPoint.X > 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
				else if (pt.X >= 0 && pt.X > runding->Width - joystick->Width && pt.Y >= 0 && pt.Y > runding->Height - joystick->Height) // Høyre nede hjørne
				{
					if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(e->X - StartPoint.X, e->Y - StartPoint.Y);
					}
					else if (e->X - StartPoint.X < 0 && e->Y - StartPoint.Y > 0)
					{
						pt.Offset(e->X - StartPoint.X, 0);
					}
					else if (e->X - StartPoint.X > 0 && e->Y - StartPoint.Y < 0)
					{
						pt.Offset(0, e->Y - StartPoint.Y);
					}
					pb->Location = pt;
				}
			}
		}

	
private: System::Void zoomScroll_Scroll(System::Object^  sender, System::Windows::Forms::ScrollEventArgs^  e) 
{
	if (e->Type == ScrollEventType::EndScroll)
	{
		int zoomVal = 10 * (285 - zoomScroll->Value);
		currentCam->setZoom(zoomVal);
		currentCam->zoomCurr = zoomVal;
	}
	
}

private: System::Void cam2btn_Click(System::Object^  sender, System::EventArgs^  e) {
	currentCam = cam2;
	this->cam2btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
		static_cast<System::Int32>(static_cast<System::Byte>(55)));
	this->cam1btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
		static_cast<System::Int32>(static_cast<System::Byte>(65)));
	float px = ((float)currentCam->panCurr / (float)VISCA_PAN_MAX_POS)*(float)(runding->Width - joystick->Width);
	float py = (1 - ((float)currentCam->tiltCurr / (float)VISCA_TILT_MAX_POS))*(float)(runding->Height - joystick->Height);
	joystick->Location = Point(px, py);
	zoomScroll->Value = 285 - currentCam->zoomCurr / 10;
}
private: System::Void cam1btn_Click(System::Object^  sender, System::EventArgs^  e) {
	currentCam = cam1;
	this->cam1btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(31)), static_cast<System::Int32>(static_cast<System::Byte>(43)),
		static_cast<System::Int32>(static_cast<System::Byte>(55)));
	this->cam2btn->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(41)), static_cast<System::Int32>(static_cast<System::Byte>(53)),
		static_cast<System::Int32>(static_cast<System::Byte>(65)));
	float px = ((float)currentCam->panCurr / (float)VISCA_PAN_MAX_POS)*(float)(runding->Width - joystick->Width);
	float py = (1 - ((float)currentCam->tiltCurr / (float)VISCA_TILT_MAX_POS))*(float)(runding->Height - joystick->Height);
	joystick->Location = Point(px, py);
	zoomScroll->Value = 285 - currentCam->zoomCurr / 10;
}
private: System::Void resetBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	currentCam->resetCamera();
	currentCam->setZoom(0);
	currentCam->tiltCurr = CAMERA_NEUTRAL_TILT;
	currentCam->panCurr = CAMERA_NEUTRAL_PAN;
	currentCam->zoomCurr = 0;
	zoomScroll->Value = 285;
	float px = ((float)CAMERA_NEUTRAL_PAN / (float)VISCA_PAN_MAX_POS)*(float)(runding->Width - joystick->Width);
	float py = (1-((float)CAMERA_NEUTRAL_TILT / (float)VISCA_TILT_MAX_POS))*(float)(runding->Height - joystick->Height);
	joystick->Location = Point(px, py);

}
private: System::Void switchBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->pilerBtn->BackColor = System::Drawing::SystemColors::ControlDark;
	this->joystickBtn->BackColor = System::Drawing::SystemColors::HighlightText;
	this->joystickPanel->Visible = false;
	this->pilerPanel->Visible = true;
}
private: System::Void joystickBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	this->pilerBtn->BackColor = System::Drawing::SystemColors::HighlightText;
	this->joystickBtn->BackColor = System::Drawing::SystemColors::ControlDark;
	this->joystickPanel->Visible = true;
	this->pilerPanel->Visible = false;
	float px = ((float)currentCam->panCurr / (float)VISCA_PAN_MAX_POS)*(float)(runding->Width - joystick->Width);
	float py = (1 - ((float)currentCam->tiltCurr / (float)VISCA_TILT_MAX_POS))*(float)(runding->Height - joystick->Height);
	joystick->Location = Point(px, py);

	zoomScroll->Value = 285 - currentCam->zoomCurr / 10;

}
private: System::Void opp_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->tiltCurr < VISCA_TILT_MAX_POS)
	{
		if (currentCam->tiltCurr + tiltStep > VISCA_TILT_MAX_POS)
		{
			currentCam->setPanTilt(currentCam->panCurr, VISCA_TILT_MAX_POS);
			currentCam->tiltCurr = VISCA_TILT_MAX_POS;
		}
		else
		{
			currentCam->tiltCurr = currentCam->tiltCurr + tiltStep;
			currentCam->setPanTilt(currentCam->panCurr, currentCam->tiltCurr);
		}
	}
}

private: System::Void ned_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->tiltCurr > VISCA_TILT_MIN_POS)
	{
		if (currentCam->tiltCurr - tiltStep < VISCA_TILT_MIN_POS)
		{
			currentCam->setPanTilt(currentCam->panCurr, VISCA_TILT_MIN_POS);
			currentCam->tiltCurr = VISCA_TILT_MIN_POS;
		}
		else
		{
			currentCam->tiltCurr = currentCam->tiltCurr - tiltStep;
			currentCam->setPanTilt(currentCam->panCurr, currentCam->tiltCurr);
		}
	}
}
private: System::Void right_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->panCurr < VISCA_PAN_MAX_POS)
	{
		if (currentCam->panCurr + panStep >= VISCA_PAN_MAX_POS)
		{
			currentCam->setPanTilt(VISCA_PAN_MAX_POS, currentCam->tiltCurr);
			currentCam->panCurr = VISCA_PAN_MAX_POS;
		}
		else
		{
			currentCam->setPanTilt(currentCam->panCurr + panStep, currentCam->tiltCurr);
			currentCam->panCurr = currentCam->panCurr + panStep;
		}
	}
}

private: System::Void left_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->panCurr > VISCA_PAN_MIN_POS)
	{
		if (currentCam->panCurr - panStep < VISCA_PAN_MIN_POS)
		{
			currentCam->setPanTilt(VISCA_PAN_MIN_POS, currentCam->tiltCurr);
			currentCam->panCurr = VISCA_PAN_MIN_POS;
		}
		else
		{
			currentCam->setPanTilt(currentCam->panCurr - panStep, currentCam->tiltCurr);
			currentCam->panCurr = currentCam->panCurr - panStep;
		}
	}
}

private: System::Void precBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (precisionMode == false)
	{
		this->presisjonBtn->BackColor = System::Drawing::Color::Green;
		precisionMode = true;
		panStep = 10;
		tiltStep = 5;
		zoomStep = 20;
	}
	else if (precisionMode = true)
	{
		this->presisjonBtn->BackColor = System::Drawing::SystemColors::Control;
		precisionMode = false;
		panStep = 50;
		tiltStep = 20;
		zoomStep = 200;
	}

	/*MessageBox::Show("your message",
		"window title",
		MessageBoxButtons::OK,
		MessageBoxIcon::Warning // for Warning  
								//MessageBoxIcon.Error // for Error 
								//MessageBoxIcon.Information  // for Information
								//MessageBoxIcon.Question // for Question
	);*/
}

private: System::Void zoomInbtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->zoomCurr < VISCA_ZOOM_MAX_VAL)
	{
		if (currentCam->zoomCurr + zoomStep >= VISCA_ZOOM_MAX_VAL)
		{
			currentCam->setZoom(VISCA_ZOOM_MAX_VAL);
			currentCam->zoomCurr = VISCA_ZOOM_MAX_VAL;
		}
		else
		{
			currentCam->setZoom(currentCam->zoomCurr + zoomStep);
			currentCam->zoomCurr = currentCam->zoomCurr + zoomStep;
		}
	}
}
private: System::Void zoomOutBtn_Click(System::Object^  sender, System::EventArgs^  e) {
	if (currentCam->zoomCurr > VISCA_ZOOM_MIN_VAL)
	{
		if (currentCam->zoomCurr - zoomStep <= VISCA_ZOOM_MIN_VAL)
		{
			currentCam->setZoom(VISCA_ZOOM_MIN_VAL);
			currentCam->zoomCurr = VISCA_ZOOM_MIN_VAL;
		}
		else
		{
			currentCam->setZoom(currentCam->zoomCurr - zoomStep);
			currentCam->zoomCurr = currentCam->zoomCurr - zoomStep;
		}
	}
}
};
}
