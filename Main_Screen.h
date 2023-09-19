#pragma once
#include"SocketsInfo.h"
namespace TRSPUAVC
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Main_Screen : public System::Windows::Forms::Form
	{
	public:
		Main_Screen(void)
		{
			InitializeComponent();	
		}

	protected:
		
		~Main_Screen()
		{
			if (components)
			{
				delete components;
			}
			Application::Exit();
		}

	// объявление элементов интерфейса
	private: System::Windows::Forms::Label^ Electronic_Recon_label;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ Repeaters_label;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ Radio_recon_label;
	private: System::Windows::Forms::Button^ Select_Units;

	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::ListBox^ active_squad_list;

	private: System::Windows::Forms::DataVisualization::Charting::Chart^ Radar_Map;
	private: System::Windows::Forms::ListBox^ Strikers_list;
	private: System::Windows::Forms::ListBox^ Spotters_list;
	private: System::Windows::Forms::ListBox^ Repeaters_list;
	private: System::Windows::Forms::ListBox^ Radio_Recon_list;
	private: System::Windows::Forms::ListBox^ Electronic_Recon_list;
	private: System::Windows::Forms::Label^ active_squads_label;
	private: System::Windows::Forms::ListBox^ active_squads_list;
	private: System::Windows::Forms::Button^ show_squad_button;
	private: System::Windows::Forms::Button^ activate_squad_button;
	private: System::Windows::Forms::Button^ load_data;

	private:
		
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::Windows::Forms::DataVisualization::Charting::ChartArea^ chartArea1 = (gcnew System::Windows::Forms::DataVisualization::Charting::ChartArea());
			System::Windows::Forms::DataVisualization::Charting::Legend^ legend1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Legend());
			System::Windows::Forms::DataVisualization::Charting::Series^ series1 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series2 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series3 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series4 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			System::Windows::Forms::DataVisualization::Charting::Series^ series5 = (gcnew System::Windows::Forms::DataVisualization::Charting::Series());
			this->Electronic_Recon_label = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->Repeaters_label = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->Radio_recon_label = (gcnew System::Windows::Forms::Label());
			this->Select_Units = (gcnew System::Windows::Forms::Button());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->active_squad_list = (gcnew System::Windows::Forms::ListBox());
			this->Radar_Map = (gcnew System::Windows::Forms::DataVisualization::Charting::Chart());
			this->Strikers_list = (gcnew System::Windows::Forms::ListBox());
			this->Spotters_list = (gcnew System::Windows::Forms::ListBox());
			this->Repeaters_list = (gcnew System::Windows::Forms::ListBox());
			this->Radio_Recon_list = (gcnew System::Windows::Forms::ListBox());
			this->Electronic_Recon_list = (gcnew System::Windows::Forms::ListBox());
			this->active_squads_label = (gcnew System::Windows::Forms::Label());
			this->active_squads_list = (gcnew System::Windows::Forms::ListBox());
			this->show_squad_button = (gcnew System::Windows::Forms::Button());
			this->activate_squad_button = (gcnew System::Windows::Forms::Button());
			this->load_data = (gcnew System::Windows::Forms::Button());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Radar_Map))->BeginInit();
			this->SuspendLayout();
			// 
			// Electronic_Recon_label
			// 
			this->Electronic_Recon_label->AutoSize = true;
			this->Electronic_Recon_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Electronic_Recon_label->Location = System::Drawing::Point(38, 23);
			this->Electronic_Recon_label->Name = L"Electronic_Recon_label";
			this->Electronic_Recon_label->Size = System::Drawing::Size(157, 29);
			this->Electronic_Recon_label->TabIndex = 0;
			this->Electronic_Recon_label->Text = L"РТ разведка";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(39, 512);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(117, 29);
			this->label2->TabIndex = 1;
			this->label2->Text = L"Ударные";
			// 
			// Repeaters_label
			// 
			this->Repeaters_label->AutoSize = true;
			this->Repeaters_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Repeaters_label->Location = System::Drawing::Point(32, 274);
			this->Repeaters_label->Name = L"Repeaters_label";
			this->Repeaters_label->Size = System::Drawing::Size(195, 29);
			this->Repeaters_label->TabIndex = 2;
			this->Repeaters_label->Text = L"Ретрансляторы";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(32, 393);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(227, 29);
			this->label4->TabIndex = 3;
			this->label4->Text = L"Корректировщики";
			// 
			// Radio_recon_label
			// 
			this->Radio_recon_label->AutoSize = true;
			this->Radio_recon_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->Radio_recon_label->Location = System::Drawing::Point(31, 157);
			this->Radio_recon_label->Name = L"Radio_recon_label";
			this->Radio_recon_label->Size = System::Drawing::Size(156, 29);
			this->Radio_recon_label->TabIndex = 4;
			this->Radio_recon_label->Text = L"РЛ разведка";
			// 
			// Select_Units
			// 
			this->Select_Units->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->Select_Units->Location = System::Drawing::Point(44, 647);
			this->Select_Units->Name = L"Select_Units";
			this->Select_Units->Size = System::Drawing::Size(250, 83);
			this->Select_Units->TabIndex = 6;
			this->Select_Units->Text = L"Выбрать units";
			this->Select_Units->UseVisualStyleBackColor = true;
			this->Select_Units->Click += gcnew System::EventHandler(this, &Main_Screen::Select_Units_Click);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(1245, 261);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(198, 29);
			this->label6->TabIndex = 7;
			this->label6->Text = L"Текущая группа";
			// 
			// active_squad_list
			// 
			this->active_squad_list->FormattingEnabled = true;
			this->active_squad_list->ItemHeight = 16;
			this->active_squad_list->Location = System::Drawing::Point(1250, 293);
			this->active_squad_list->Name = L"active_squad_list";
			this->active_squad_list->Size = System::Drawing::Size(250, 308);
			this->active_squad_list->TabIndex = 8;
			// 
			// Radar_Map
			// 
			chartArea1->Name = L"ChartArea1";
			this->Radar_Map->ChartAreas->Add(chartArea1);
			legend1->Name = L"Legend1";
			legend1->Title = L"БЛА";
			this->Radar_Map->Legends->Add(legend1);
			this->Radar_Map->Location = System::Drawing::Point(464, 12);
			this->Radar_Map->Name = L"Radar_Map";
			series1->ChartArea = L"ChartArea1";
			series1->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series1->Legend = L"Legend1";
			series1->Name = L"РТ разведка";
			series2->ChartArea = L"ChartArea1";
			series2->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series2->Legend = L"Legend1";
			series2->Name = L"РЛ разведка";
			series3->ChartArea = L"ChartArea1";
			series3->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series3->Legend = L"Legend1";
			series3->Name = L"Ретрансляторы";
			series4->ChartArea = L"ChartArea1";
			series4->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series4->Legend = L"Legend1";
			series4->Name = L"Корректировщики";
			series5->BorderWidth = 2;
			series5->ChartArea = L"ChartArea1";
			series5->ChartType = System::Windows::Forms::DataVisualization::Charting::SeriesChartType::Point;
			series5->Legend = L"Legend1";
			series5->Name = L"ударные";
			this->Radar_Map->Series->Add(series1);
			this->Radar_Map->Series->Add(series2);
			this->Radar_Map->Series->Add(series3);
			this->Radar_Map->Series->Add(series4);
			this->Radar_Map->Series->Add(series5);
			this->Radar_Map->Size = System::Drawing::Size(726, 616);
			this->Radar_Map->TabIndex = 9;
			this->Radar_Map->Text = L"chart1";
			// 
			// Strikers_list
			// 
			this->Strikers_list->FormattingEnabled = true;
			this->Strikers_list->ItemHeight = 16;
			this->Strikers_list->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"5000 Молот", L"5001 Молот" });
			this->Strikers_list->Location = System::Drawing::Point(43, 544);
			this->Strikers_list->Name = L"Strikers_list";
			this->Strikers_list->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->Strikers_list->Size = System::Drawing::Size(146, 84);
			this->Strikers_list->TabIndex = 10;
			// 
			// Spotters_list
			// 
			this->Spotters_list->FormattingEnabled = true;
			this->Spotters_list->ItemHeight = 16;
			this->Spotters_list->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"4000 Наблюдатель", L"4001 Наблюдатель" });
			this->Spotters_list->Location = System::Drawing::Point(37, 425);
			this->Spotters_list->Name = L"Spotters_list";
			this->Spotters_list->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->Spotters_list->Size = System::Drawing::Size(152, 84);
			this->Spotters_list->TabIndex = 11;
			// 
			// Repeaters_list
			// 
			this->Repeaters_list->FormattingEnabled = true;
			this->Repeaters_list->ItemHeight = 16;
			this->Repeaters_list->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"3000 Передатчик", L"3001 Передатчик" });
			this->Repeaters_list->Location = System::Drawing::Point(37, 306);
			this->Repeaters_list->Name = L"Repeaters_list";
			this->Repeaters_list->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->Repeaters_list->Size = System::Drawing::Size(160, 84);
			this->Repeaters_list->TabIndex = 12;
			// 
			// Radio_Recon_list
			// 
			this->Radio_Recon_list->FormattingEnabled = true;
			this->Radio_Recon_list->ItemHeight = 16;
			this->Radio_Recon_list->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"2000 Шпион", L"2001 Шпион" });
			this->Radio_Recon_list->Location = System::Drawing::Point(36, 189);
			this->Radio_Recon_list->Name = L"Radio_Recon_list";
			this->Radio_Recon_list->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->Radio_Recon_list->Size = System::Drawing::Size(161, 84);
			this->Radio_Recon_list->TabIndex = 13;
			// 
			// Electronic_Recon_list
			// 
			this->Electronic_Recon_list->FormattingEnabled = true;
			this->Electronic_Recon_list->ItemHeight = 16;
			this->Electronic_Recon_list->Items->AddRange(gcnew cli::array< System::Object^  >(2) { L"1000 Дозор", L"1001 Дозор" });
			this->Electronic_Recon_list->Location = System::Drawing::Point(36, 70);
			this->Electronic_Recon_list->Name = L"Electronic_Recon_list";
			this->Electronic_Recon_list->SelectionMode = System::Windows::Forms::SelectionMode::MultiExtended;
			this->Electronic_Recon_list->Size = System::Drawing::Size(161, 84);
			this->Electronic_Recon_list->TabIndex = 14;
			// 
			// active_squads_label
			// 
			this->active_squads_label->AutoSize = true;
			this->active_squads_label->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->active_squads_label->Location = System::Drawing::Point(1245, 33);
			this->active_squads_label->Name = L"active_squads_label";
			this->active_squads_label->Size = System::Drawing::Size(215, 29);
			this->active_squads_label->TabIndex = 15;
			this->active_squads_label->Text = L"Активные группы";
			// 
			// active_squads_list
			// 
			this->active_squads_list->FormattingEnabled = true;
			this->active_squads_list->ItemHeight = 16;
			this->active_squads_list->Location = System::Drawing::Point(1250, 70);
			this->active_squads_list->Name = L"active_squads_list";
			this->active_squads_list->Size = System::Drawing::Size(243, 100);
			this->active_squads_list->TabIndex = 16;
			// 
			// show_squad_button
			// 
			this->show_squad_button->Enabled = false;
			this->show_squad_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->show_squad_button->Location = System::Drawing::Point(1250, 189);
			this->show_squad_button->Name = L"show_squad_button";
			this->show_squad_button->Size = System::Drawing::Size(243, 37);
			this->show_squad_button->TabIndex = 17;
			this->show_squad_button->Text = L"Показать состав";
			this->show_squad_button->UseVisualStyleBackColor = true;
			// 
			// activate_squad_button
			// 
			this->activate_squad_button->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular,
				System::Drawing::GraphicsUnit::Point, static_cast<System::Byte>(0)));
			this->activate_squad_button->Location = System::Drawing::Point(1250, 607);
			this->activate_squad_button->Name = L"activate_squad_button";
			this->activate_squad_button->Size = System::Drawing::Size(250, 74);
			this->activate_squad_button->TabIndex = 18;
			this->activate_squad_button->Text = L"Сформировать группу";
			this->activate_squad_button->UseVisualStyleBackColor = true;
			this->activate_squad_button->Click += gcnew System::EventHandler(this, &Main_Screen::activate_squad_button_Click);
			// 
			// load_data
			// 
			this->load_data->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 13.8F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(0)));
			this->load_data->Location = System::Drawing::Point(44, 736);
			this->load_data->Name = L"load_data";
			this->load_data->Size = System::Drawing::Size(250, 54);
			this->load_data->TabIndex = 19;
			this->load_data->Text = L"Загрузить данные";
			this->load_data->UseVisualStyleBackColor = true;
			this->load_data->Click += gcnew System::EventHandler(this, &Main_Screen::load_data_Click);
			// 
			// Main_Screen
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->ClientSize = System::Drawing::Size(1582, 853);
			this->Controls->Add(this->load_data);
			this->Controls->Add(this->activate_squad_button);
			this->Controls->Add(this->show_squad_button);
			this->Controls->Add(this->active_squads_list);
			this->Controls->Add(this->active_squads_label);
			this->Controls->Add(this->Electronic_Recon_list);
			this->Controls->Add(this->Radio_Recon_list);
			this->Controls->Add(this->Repeaters_list);
			this->Controls->Add(this->Spotters_list);
			this->Controls->Add(this->Strikers_list);
			this->Controls->Add(this->Radar_Map);
			this->Controls->Add(this->active_squad_list);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->Select_Units);
			this->Controls->Add(this->Radio_recon_label);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->Repeaters_label);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->Electronic_Recon_label);
			this->MaximizeBox = false;
			this->Name = L"Main_Screen";
			this->ShowIcon = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Main_Screen";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->Radar_Map))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void Select_Units_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void activate_squad_button_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void load_data_Click(System::Object^ sender, System::EventArgs^ e);
};
}
