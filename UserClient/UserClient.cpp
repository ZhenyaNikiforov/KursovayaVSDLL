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
    std::string nameRace = ""; //-- Имя гонки (наземная, воздушная или наземно-воздушная);
    int distanceLength = 0; //-- Длина дистанции (положительная);
    int selectTransport = 0; //-- Разрешение на выбор транспорта;
    int typeTransport = 0; //-- Тип транспортного средства;
    std::vector<string>vehicles{ "", "1. Ботинки-вездеходы",  "2. Метла", "3. Верблюд", "4. Кентавр", "5. Орёл", "6. Верблюд-быстроход", "7. Ковёр-самолёт" }; //-- Набор транспортных средств;
    std::vector<int>ourVehicles{100}; //-- Пользовательский набор транспортных средств (изначальное значение);
    bool startRace = false; //-- Разрешение на запуск гонки;
    bool newRace = false; //-- Флаг новой гонки;
    bool exitRace = false; //-- Выход из гонки;
    bool stop = false; //-- Прерывание основного цикла программы;
    
    while (true) { //-- Основной цикл программы;

        typeOfRace = 0; //-- Тип гонки (1, 2 или 3);
        nameRace = ""; //-- Имя гонки (наземная, воздушная или наземно-воздушная);
        distanceLength = 0; //-- Длина дистанции (положительная);
        selectTransport = 0; //-- Разрешение на выбор транспорта;
        typeTransport = 0; //-- Тип транспортного средства;
        //vehicles{ "", "1. Ботинки-вездеходы",  "2. Метла", "3. Верблюд", "4. Кентавр", "5. Орёл", "6. Верблюд-быстроход", "7. Ковёр-самолёт" }; //-- Набор транспортных средств;
        ourVehicles.clear(); //-- Пользовательский набор транспортных средств (очищаем);
        ourVehicles.push_back(100); //-- Пользовательский набор транспортных средств (изначальное значение);
        startRace = false; //-- Разрешение на запуск гонки;
        newRace = false; //-- Флаг новой гонки;
        exitRace = false; //-- Выход из гонки;
        stop = false; //-- Прерывание основного цикла программы;

        cout << "Добро пожаловать в гоночный симулятор!\n"; //-- Вступительная речь;

        while (true) { //-- Цикл выбора типа гонки;
            cout << "1. Гонка для наземного транспорта\n";
            cout << "2. Гонка для воздушного транспорта\n";
            cout << "3. Гонка для наземного и воздушного транспорта\n";
            cout << "Выберите тип гонки: ";
            std::cin >> typeOfRace;
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
            std::cin >> distanceLength;
            if (distanceLength >= 0) {
                break;
            };
            cout << "Отрицательная длина дистанции!\n";
        };
        while (true) { //- общий цикл проведения гонки;
            while (true) { //-- Цикл разрешения выбора транспорта;
                bool registration = true;
                if (ourVehicles.size() < 3) { registration = false; };
                if (!registration) { cout << "Должно быть зарегистрировано хотя бы два транспортных средства\n"; };
                cout << "1. Зарегистрировать транспорт\n";
                if (registration) { cout << "2. Начать гонку\n"; }
                cout << "Выберите действие: ";
                std::cin >> selectTransport;
                if (selectTransport == 1) { startRace = false; break; }
                else if ((selectTransport == 2) && (registration)) { startRace = true; break; }
                else { cout << "Ввод неправильного числа.\n"; };
            };
            if (startRace) {
                //-инициируем гонку;
                cout << "Результаты гонки:\n";
                //--...;
                while (true) {
                    int action = 0;
                    cout << "1. Произвести новую гонку:\n";
                    cout << "2. Выйти:\n";
                    cout << "Выбираем действие: ";
                    std::cin >> action;
                    if (action == 1) { newRace = true; break; }
                    else if (action == 2) { exitRace = true;  break; }
                    else { cout << "Неправильный номер действия!\n"; }
                };
                if (newRace) { break; }
                if (exitRace) { stop = true; break; }
            };
            while (true) { //-- Цикл выбора транспортных средств для гонки;
                cout << "Гонка для " << nameRace << " транспорта. Расстояние: " << distanceLength << endl;
                if (ourVehicles.size() > 1) {
                    cout << "Выбраны: ";
                    for (int i = 1; i < ourVehicles.size(); ++i) { cout << vehicles[ourVehicles[i]] << " "; };
                    cout << endl;
                };
                for (int i = 0; i < vehicles.size(); ++i) { cout << vehicles[i] << endl; };
                cout << "0. Закончить регистрацию\n";
                cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
                std::cin >> typeTransport;
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
        }
        if (stop) { break; };
    };

    return 0;
};