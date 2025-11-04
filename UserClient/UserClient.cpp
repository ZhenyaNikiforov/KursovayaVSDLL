#include <iostream>
#include <vector>
#include "../KursovayaVSDLL/lib.h"
using namespace std;

int main()
{
    /*camel Verbluzhka("Verbluzhka");
    std::cout << Verbluzhka.namePrint() << std::endl;

    dog Sobachka("Sobachka");
    std::cout << Sobachka.namePrint() << std::endl;

    cat Koshechka("Koshechka");
    std::cout << Koshechka.namePrint() << std::endl;*/

    setlocale(LC_ALL, "Russian"); //-- русский язык в консоли;

    int typeOfRace = 0; //-- Тип гонки (1, 2 или 3);
    string nameRace = ""; //-- Имя гонки (наземная, воздушная или наземно-воздушная);
    int distanceLength = 0; //-- Длина дистанции (положительная);
    int selectTransport = 0; //-- Разрешение на выбор транспорта;
    int typeTransport = 0; //-- Тип транспортного средства;
    vector<string>vehicles{ "", "1. Ботинки-вездеходы",  "2. Метла", "3. Верблюд", "4. Кентавр", "5. Орёл", "6. Верблюд-быстроход", "7. Ковёр-самолёт" }; //-- Набор транспортных средств;
    vector<int>ourVehicles{100}; //-- Пользовательский набор транспортных средств (изначальное значение);
    
    while (true) { //-- Основной цикл программы;
        cout << "Добро пожаловать в гоночный симулятор!\n"; //-- Вступительная речь;
        while (true) { //-- Цикл выбора типа гонки;
            cout << "1. Гонка для наземного транспорта\n";
            cout << "2. Гонка для воздушного транспорта\n";
            cout << "3. Гонка для наземного и воздушного транспорта\n";
            cout << "Выберите тип гонки: ";
            cin >> typeOfRace;
            if (typeOfRace == 1) {
                nameRace = "наземного";
                break;
            };
            if (typeOfRace == 2) {
                nameRace = "воздушного";
                break;
            };
            if (typeOfRace == 3) {
                nameRace = "наземно-воздушного";
                break;
            };
            cout << "Неправильно выбранный тип гонки!\n";
        };
        while (true) { //-- Цикл выбора длины дистанции;
            cout << "Укажите длину дистанции (должна быть положительной): ";
            cin >> distanceLength;
            if (distanceLength >= 0) {
                break;
            };
            cout << "Отрицательная длина дистанции!\n";
        };
        cout << "Должно быть зарегистрировано хотя бы два транспортных средства\n";
        while (true) { //-- Цикл разрешения выбора транспорта;
            cout << "1. Зарегистрировать транспорт\n";
            cout << "Выберите действие: ";
            cin >> selectTransport;
            if (selectTransport == 1) {
                break;
            };
            cout << "Ввод неправильного числа.\n";
        };
        while (true) { //-- Цикл выбора транспортных средств для гонки;
            cout << "Гонка для "<<nameRace<<" транспорта. Расстояние: "<<distanceLength<<endl;
            for (int i = 0; i < vehicles.size(); ++i) { cout << vehicles[i] << endl; };
            cout << "0. Закончить регистрацию\n";
            cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
            cin >> typeTransport;
            bool air = ((typeOfRace == 2) && ((typeTransport == 2) || (typeTransport == 5) || (typeTransport == 7)));
            bool terrestrial = ((typeOfRace == 1) && ((typeTransport == 1) || (typeTransport == 3) || (typeTransport == 4) || (typeTransport == 6)));
            bool airTerrestrial = ((typeOfRace == 3) && ((typeTransport > 0) && (typeTransport < 8)));
            bool breakSelectTransport = (typeTransport == 0);
            bool errorTransport = ((!breakSelectTransport) && (!airTerrestrial) && (!terrestrial) && (!air));
            if (errorTransport) { cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n"; continue; };
            if (breakSelectTransport) { break; };
            if (air || terrestrial || airTerrestrial) { 
                bool coincidence = false; 
                for (int i = 0; i < ourVehicles.size(); ++i) {  
                    if (ourVehicles[i] == typeTransport) { coincidence = true; break; }
                };
                if (coincidence) { cout << "Ошибка! " << vehicles[typeTransport] << " уже есть!\n"; }
                else { ourVehicles.push_back(typeTransport); cout << "Добавлен " << vehicles[typeTransport] << endl; };
            };
        };
    };

    return 0;
};