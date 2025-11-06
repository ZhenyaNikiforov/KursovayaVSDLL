#include <iostream>
#include <vector>
#include "../KursovayaVSDLL/lib.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian"); //-- русский язык в консоли;

    /*- Создаём экземпляры классов -*/
    camel runningCamel; //-- Экземпляр верблюда;
    speedCamel runningSpeedCamel; //-- экземпляр быстрого верблюда
    kentauros runningKentauros; //-- Экземпляр кентавра;
    boots runningBoots; //- экземпляр ботинок
    eagle runningEagle; //- экземпляр орла;
    flyingCarpet runningFlyingCarpet; //- экземпляр летающего ковра;
    broom runningBroom; //- экземпляр метлы;

    /*- Создаём указатели и ссылки -*/
    camel* camelClassIndicator; //-- указатель на класс верблюда
    camelClassIndicator = &runningSpeedCamel; //- ссылка с экземрляра быст. верб. на указатель
    kentauros* kentaurosClassIndicator; //- Указатель на класс кентавра
    kentaurosClassIndicator = &runningBoots; //- ссылка с экземпляра ботинок на на указатель
    eagle* indicatorForCarpet; //- указатель на орла для ковра
    indicatorForCarpet = &runningFlyingCarpet; //- ссылка с экземпляра ковра на указатель
    eagle* indicatorForBroom; //- указатель на орла для метлы
    indicatorForBroom = &runningBroom; //- ссылка с экземпляра метлы на указатель

    /*- Запускаем методы расчёта времени у экземпляров -*/
    cout <<"Верблюд: "<< runningCamel.calcTime(4500) << endl; //-- отображение результатов верблюда
    cout<<"Быстр. верблюд: " << camelClassIndicator->calcTime(4500) << endl; //- отображение быст. верб. через указатель
    cout<<"Кентавр: " << runningKentauros.calcTime(4500) << endl; //-- Отображение результатов кентавра
    cout <<"Ботинки: " << kentaurosClassIndicator->calcTime(4500) << std::endl; //- отображение результатов ботинок
    cout <<"Орёл: " << runningEagle.calcTime(4500) << endl; //- отображение результатов орла
    cout <<"Летающий ковёр: " <<indicatorForCarpet->calcTime(4500)<< endl; //- отображение результатов ковра
    cout <<"Метла: " <<indicatorForBroom->calcTime(4500)<< endl; //- отображение результатов метлы

    /*- Инициализируем переменные основного цикла программы -*/
    int typeOfRace = 0; //-- Тип гонки (1, 2 или 3);
    std::string nameRace = ""; //-- Имя гонки (наземная, воздушная или наземно-воздушная);
    int distanceLength = 0; //-- Длина дистанции (положительная);
    int selectTransport = 0; //-- Разрешение на выбор транспорта;
    int typeTransport = 0; //-- Тип транспортного средства;
    /*-- Набор названий транспортных средств будем использовать в качестве ассоциативного кэша --*/
    std::vector<string>vehicles{ "1. Ботинки-вездеходы",  "2. Метла", "3. Верблюд", "4. Кентавр", "5. Орёл", "6. Верблюд-быстроход", "7. Ковёр-самолёт" };
    std::vector<int>ourVehicles{}; //-- Пользовательский набор транспортных средств (изначальное значение);
    bool startRace = false; //-- Разрешение на запуск гонки;
    bool newRace = false; //-- Флаг новой гонки;
    bool exitRace = false; //-- Выход из гонки;
    bool stop = false; //-- Прерывание основного цикла программы;
    
    while (true) { //-- Основной цикл программы;

        /*- Сбрасываем значения переменных при каждом пробеге по циклу -*/
        typeOfRace = 0; //-- Тип гонки (1, 2 или 3);
        nameRace = ""; //-- Имя гонки (наземная, воздушная или наземно-воздушная);
        distanceLength = 0; //-- Длина дистанции (положительная);
        selectTransport = 0; //-- Разрешение на выбор транспорта;
        typeTransport = 0; //-- Тип транспортного средства;
        //vehicles -- Набор транспортных средств не меняется;
        ourVehicles.clear(); //-- Пользовательский набор транспортных средств (очищаем);
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
                bool registration = true;//флаг регистрации изначально поднят
                if (ourVehicles.size() < 2) { registration = false; }//если выбрано меньше 2-х Т.С., то флаг спускаем
                else { registration = true; };//если 2 или больше, то поднимаем
                /*если флаг регистрации спущен, то печатаем строку ниже:*/
                if (!registration) { cout << "Должно быть зарегистрировано хотя бы два транспортных средства\n"; };
                cout << "1. Зарегистрировать транспорт\n";
                if (registration) { cout << "2. Начать гонку\n"; }//если флаг рег-ции поднят, выводим вариант 2
                cout << "Выберите действие: ";
                std::cin >> selectTransport;//вводим выбор действия
                if (selectTransport == 1) { startRace = false; break; }/*если 1(регистрация транспорта),
                флаг старта гонки (startRace) спускаем, рвём цикл.*/
                else if ((selectTransport == 2) && (registration)) { startRace = true; break; }/*если 2(начало гонки),
                и флаг рег-ции поднят, флаг старта гонки(startRace) поднимаем, рвём цикл*/
                else { cout << "Ввод неправильного числа.\n"; };//если не 1 и не 2, выводим ошибку и начинаем сначала
            };
            if (startRace) {//-если флаг старта гонки startRace поднят
                //-производим гонку;
                cout << "Результаты гонки:\n";//выводим результаты гонки
                //--...;
                while (true) {//-цикл выбора дальнейших действий:
                    int action = 0;
                    cout << "1. Произвести новую гонку\n";
                    cout << "2. Выйти\n";
                    cout << "Выбираем действие: ";
                    std::cin >> action;
                    if (action == 1) { newRace = true; break; }//если 1, поднимаем глобальный флаг newRace, рвём цикл;
                    else if (action == 2) { exitRace = true;  break; }//если 2, поднимаем глобальный флаг exitRace, рвём цикл;
                    else { cout << "Неправильный номер действия!\n"; }//если не 1 и не 2, бежим по циклу дальше;
                };
                if (newRace) { break; }/*если поднят флаг newRace (новая гонка),
                рвём общий цикл гонки без подъёма флага stop*/
                if (exitRace) { stop = true; break; }/*если поднят флаг exitRace (выход из гонки), поднимаем флаг stop
                и рвём цикл гонки*/
            };
            while (true) { //-- Цикл выбора транспортных средств для гонки;
                cout << "Гонка для " << nameRace << " транспорта. Расстояние: " << distanceLength << endl;
                if (ourVehicles.size() > 0) {//-если в наших трансп. ср-вах что-то есть, то...
                    cout << "Выбраны: ";//пишем: выбраны и выводим, что выбрано:
                    for (int i = 0; i < ourVehicles.size(); ++i) { cout << vehicles[ourVehicles[i]-1] << " "; };
                    cout << endl;
                };
                for (int i = 0; i < vehicles.size(); ++i) { cout << vehicles[i] << endl; };//выводим список всех ТС
                cout << "0. Закончить регистрацию\n";//-0 это код окончания
                cout << "Выберите транспорт или 0 для окончания процесса регистрации: ";//постоянная фраза
                std::cin >> typeTransport;//вводим тип транспортного средства
                /*воздушный, если тип гонки 2 и тип транспорта 2, или 5, или 7*/
                bool air = ((typeOfRace == 2) && ((typeTransport == 2) || (typeTransport == 5) || (typeTransport == 7)));
                /*наземный, если тип гонки 1 и тип транспорта 1,или 3,или 4, или 6*/
                bool terrestrial = ((typeOfRace == 1) && ((typeTransport == 1) || (typeTransport == 3) || (typeTransport == 4) || (typeTransport == 6)));
                /*наземно-воздушный, если тип гонки 3 и тип транспорта больше 0 и меньше 8*/
                bool airTerrestrial = ((typeOfRace == 3) && ((typeTransport > 0) && (typeTransport < 8)));
                bool breakSelectTransport = (typeTransport == 0);//слом цикла, если тип транспорта 0
                /*ошибка выбора транспорта, если не слом цикла, не воздушный, не наземный и не смешанный*/
                bool errorTransport = ((!breakSelectTransport) && (!airTerrestrial) && (!terrestrial) && (!air));
                /*если ошибка транспорта, то сообщение и возврат к началу*/
                if (errorTransport) { cout << "Попытка зарегистрировать неправильный тип транспортного средства!\n"; continue; };
                if (breakSelectTransport) { break; };//если слом цикла, то разрыв
                if (air || terrestrial || airTerrestrial) {//если воздушный, наземный или смешанный, то...
                    bool coincidence = false;//флаг совпадения, изначально спущен
                    for (int i = 0; i < ourVehicles.size(); ++i) {//обходим массив избранных тр. ср-в, если он пустой, то не обходим
                        if (ourVehicles[i] == typeTransport) { coincidence = true; break; }//если совпадение, поднимаем флаг и бросаем обход
                        /*если совпадений нет, флаг остаётся спущенным, а если массив был пустой и мы его не обходили,
                        то флаг тоже остаётся спущенным*/
                    };
                    /*если флаг совпадения поднят, то выводим ошибку повторного выбора*/
                    if (coincidence) { cout << "Ошибка! " << vehicles[typeTransport-1] << " уже есть!\n"; }
                    /*если флаг совп. спущен, добавляем номер типа транспорта и выводим сообщение об этом*/
                    else { ourVehicles.push_back(typeTransport); cout << "Добавлен " << vehicles[typeTransport-1] << endl; };
                    /*типы транспорта начинаются с 1, поэтому в 
                    строковом массиве названий vehicles элемент 1 по индексу 0*/
                };
            };//дно цикла выборки транспортных средств для гонки;
        }//дно общего цикла проведения гонки
        if (stop) { break; };//если поднят флаг прерывания основного цикла программы, выход из неё
    };//дно основного цикла программы

    return 0;
};