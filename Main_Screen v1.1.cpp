#include "Main_Screen.h"
System::Void TRSPUAVC::Main_Screen::Select_Units_Click(System::Object^ sender, System::EventArgs^ e) // обработка кнопки выбора выделенных БЛА в группу
{
    active_squad_list->Items->Add(Electronic_Recon_list->SelectedItem);
    Electronic_Recon_list->Items->Remove(Electronic_Recon_list->SelectedItem);
    active_squad_list->Items->Add(Radio_Recon_list->SelectedItem);
    Radio_Recon_list->Items->Remove(Radio_Recon_list->SelectedItem);
    active_squad_list->Items->Add(Repeaters_list->SelectedItem);
    Repeaters_list->Items->Remove(Repeaters_list->SelectedItem);
    active_squad_list->Items->Add(Spotters_list->SelectedItem);
    Spotters_list->Items->Remove(Spotters_list->SelectedItem);
    active_squad_list->Items->Add(Strikers_list->SelectedItem);
    Strikers_list->Items->Remove(Strikers_list->SelectedItem);
}

System::Void TRSPUAVC::Main_Screen::activate_squad_button_Click(System::Object^ sender, System::EventArgs^ e) // обработка кнопки активации группы БЛА
{
    active_squad_list->Items->Clear();
    string name = to_string(active_squads_list->Items->Count + 1);
    name += " отряд"; // формирование названия группы БЛА для списка
    active_squads_list->Items->Add(gcnew String(name.c_str())); // запись новой группы в список активных групп
}

System::Void TRSPUAVC::Main_Screen::load_data_Click(System::Object^ sender, System::EventArgs^ e) // функция загрузки данных о БЛА с НДПУ
{
    const string empty = " ";
    for (size_t i = 0; i < 2; i++)
    {
        Electronic_Recon_list->Items->Add(gcnew String((Electronic_Recon[i].type + to_string(Electronic_Recon[i].number) + empty + Electronic_Recon[i].name).c_str()));
        Radio_Recon_list->Items->Add(gcnew String((Radio_Recon[i].type + to_string(Radio_Recon[i].number) + empty + Radio_Recon[i].name).c_str()));
        Repeaters_list->Items->Add(gcnew String((Repeaters[i].type + to_string(Repeaters[i].number) + empty + Repeaters[i].name).c_str()));
        Spotters_list->Items->Add(gcnew String((Spotters[i].type + to_string(Spotters[i].number) + empty + Spotters[i].name).c_str()));
        Strikers_list->Items->Add(gcnew String((Strikers[i].type + to_string(Strikers[i].number) + empty + Strikers[i].name).c_str()));
    }
}
