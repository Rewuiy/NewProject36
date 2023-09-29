#pragma once
#include"Main_Screen.h"
bool check_systems(); // функция проверки установки соединения сервера с клиентом
namespace TRSPUAVC
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Start_Screen : public System::Windows::Forms::Form
	{
	public:
		Start_Screen()
		{
			InitializeComponent();
			Next_Page = gcnew Main_Screen();
			diagnostics_message->Show();
		}
	protected:
		~Start_Screen()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}

	// объявление элементов интерфейса
	private:
	System::Windows::Forms::Label^ status_title;
	System::Windows::Forms::Label^ diagnostics_message;
	System::Windows::Forms::Label^ readiness_message;
	System::Windows::Forms::Label^ issue_message;
	System::Windows::Forms::Button^ start_button;
	Main_Screen^ Next_Page;
	System::Windows::Forms::Button^ connection_start;
	System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		   /// <summary>
		   /// Требуемый метод для поддержки конструктора — не изменяйте 
		   /// содержимое этого метода с помощью редактора кода.
		   /// </summary>
		   void InitializeComponent(void)
		   {
			   this->status_title = (gcnew System::Windows::Forms::Label());
			   this->diagnostics_message = (gcnew System::Windows::Forms::Label());
			   this->readiness_message = (gcnew System::Windows::Forms::Label());
			   this->issue_message = (gcnew System::Windows::Forms::Label());
			   this->start_button = (gcnew System::Windows::Forms::Button());
			   this->connection_start = (gcnew System::Windows::Forms::Button());
			   this->SuspendLayout();
			   // 
			   // status_title
			   // 
			   this->status_title->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				   | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->status_title->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->status_title->Location = System::Drawing::Point(305, 399);
			   this->status_title->Name = L"status_title";
			   this->status_title->Size = System::Drawing::Size(259, 46);
			   this->status_title->TabIndex = 0;
			   this->status_title->Text = L"СОСТОЯНИЕ:";
			   // 
			   // diagnostics_message
			   // 
			   this->diagnostics_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->diagnostics_message->Location = System::Drawing::Point(508, 399);
			   this->diagnostics_message->Name = L"diagnostics_message";
			   this->diagnostics_message->Size = System::Drawing::Size(203, 35);
			   this->diagnostics_message->TabIndex = 1;
			   this->diagnostics_message->Text = L"Диагностика";
			   this->diagnostics_message->Visible = false;
			   // 
			   // readiness_message
			   // 
			   this->readiness_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->readiness_message->ForeColor = System::Drawing::Color::Green;
			   this->readiness_message->Location = System::Drawing::Point(508, 399);
			   this->readiness_message->Name = L"readiness_message";
			   this->readiness_message->Size = System::Drawing::Size(169, 33);
			   this->readiness_message->TabIndex = 2;
			   this->readiness_message->Text = L"Готовность";
			   this->readiness_message->Visible = false;
			   // 
			   // issue_message
			   // 
			   this->issue_message->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 16.2F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->issue_message->ForeColor = System::Drawing::Color::Red;
			   this->issue_message->Location = System::Drawing::Point(508, 395);
			   this->issue_message->Name = L"issue_message";
			   this->issue_message->Size = System::Drawing::Size(223, 39);
			   this->issue_message->TabIndex = 3;
			   this->issue_message->Text = L"Неисправность";
			   this->issue_message->Visible = false;
			   // 
			   // start_button
			   // 
			   this->start_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				   static_cast<System::Byte>(0)));
			   this->start_button->Location = System::Drawing::Point(1375, 756);
			   this->start_button->Name = L"start_button";
			   this->start_button->Size = System::Drawing::Size(156, 45);
			   this->start_button->TabIndex = 4;
			   this->start_button->Text = L"ЗАПУСК";
			   this->start_button->UseVisualStyleBackColor = true;
			   this->start_button->Click += gcnew System::EventHandler(this, &Start_Screen::start_button_Click);
			   // 
			   // connection_start
			   // 
			   this->connection_start->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				   System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			   this->connection_start->Location = System::Drawing::Point(311, 438);
			   this->connection_start->Name = L"connection_start";
			   this->connection_start->Size = System::Drawing::Size(406, 47);
			   this->connection_start->TabIndex = 5;
			   this->connection_start->Text = L"начать диагностику";
			   this->connection_start->UseVisualStyleBackColor = true;
			   this->connection_start->Click += gcnew System::EventHandler(this, &Start_Screen::connection_start_Click);
			   // 
			   // Start_Screen
			   // 
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			   this->ClientSize = System::Drawing::Size(1582, 853);
			   this->Controls->Add(this->connection_start);
			   this->Controls->Add(this->start_button);
			   this->Controls->Add(this->issue_message);
			   this->Controls->Add(this->readiness_message);
			   this->Controls->Add(this->diagnostics_message);
			   this->Controls->Add(this->status_title);
			   this->MaximizeBox = false;
			   this->Name = L"Start_Screen";
			   this->ShowIcon = false;
			   this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			   this->Text = L"ВзПУ";
			   this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			   this->ResumeLayout(false);

		   }
#pragma endregion

	// объявление функций интерфейса
	private: System::Void start_button_Click(System::Object^ sender, System::EventArgs^ e); // функция перехода на основной экран
	private: System::Void connection_start_Click(System::Object^ sender, System::EventArgs^ e); // функция установки соединения с НДПУ и ПУ ГБУ
	};
}
