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
    vector<int>vehicles{}; //-- Набор транспортных средств (изначально пустой);

    while (true) { //-- Основной цикл программы;
        cout << "Добро пожаловать в гоночный симулятор!\n"; //-- Вступительная речь;
        while (true) { //-- Цикл выбора типа гонки;
            cout << "1. Гонка для наземного транспорта\n";
            cout << "2. Гонка для воздушного транспорта\n";
            cout << "3. Гонка для наземного и воздушного транспорта\n";
            cout << "Выберите тип гонки: ";
            cin >> typeOfRace;
            if ((typeOfRace == 1) || (typeOfRace == 2) || (typeOfRace == 3)) {
                if (typeOfRace == 1) {
                    nameRace = "наземного";
                }
                else if (typeOfRace == 2) {
                    nameRace = "воздушного";
                }
                else {
                    nameRace = "наземно - воздушного";
                };
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
            cout << "1. Ботинки-вездеходы\n";
            cout << "2. Метла\n";
            cout << "3. Верблюд\n";
            cout << "4. Кентавр\n";
            cout << "5. Орёл\n";
            cout << "6. Верблюд-быстроход\n";
            cout << "7. Ковёр-самолёт\n";
            cout << "0. Закончить регистрацию\n";
            cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";
            cin >> typeTransport;
            if ((typeTransport > 7) || (typeTransport < 0)) { //-- Если трансп. средст. больше 7 и меньше 0...
                cout << "Выбрано несуществующее транспортное средство\n"; //-- ...то нет такого трансп. средства! Всё заново
            }else if((typeTransport>0)&&(typeTransport<8)){ //-- Иначе если трансп. средст. больше 0 и меньше 8, то...
                if (typeOfRace == 1) { //-- если тип гонки наземная, то...
                    if (typeTransport == 2 || typeTransport == 5 || typeTransport == 7) { //-если метла, орёл или ковёр...
                        cout<<"Неправильный тип трансп. ср-ва!"; //-то выдать ошибку
                    }
                    else { //- но если не метла, не орёл и не ковёр...
                        vehicles.push_back(typeTransport); //- ...зачислить тр. ср.
                    };
                }
                else if (typeOfRace == 2) { //-- но, если тип гонки воздушная, то...
                    if (typeTransport == 2 || typeTransport == 5 || typeTransport == 7) { //-если метла, орёл или ковёр...
                        vehicles.push_back(typeTransport); //-то зачислить тр. ср.
                    }
                    else { //-но если не метла, не орёл и не ковёр...
                        cout << "Неправильный тип трансп. ср-ва!"; //- ...выдать ошибку
                    };
                }
                else { //-но, если тип гонки смешанная...
                    vehicles.push_back(typeTransport); //-...зачислить все транспортные ср-ва.
                };
            }else{ //-иначе если транс. ср. =0, то...
                if (...) { //- если выбрано 2 тр. ср-вв...
                    break; //-...завершать цикл выбора транспортных ср-вв.
                }else{//-если меньше чем 2, выдавать ошибку и ...
                    ;//-...возвращаться к выбору тр.с.
                };
            };
        };
    };

    return 0;
};