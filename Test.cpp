#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

// Абстрактный транспорт
class Transport
{
public:
    virtual void display() = 0;
};

// Мотоцикл
class Motorbike : public Transport
{
public:
    int wheel = 2;
    int speed = 120;
    string name = "мотоцикл";
    void display()
    {
        cout << "Наименование транспорта: " << name 
            << "\nКол-во колес: " << wheel 
            << "\nМаксимальная скорость: " << speed << "км/ч\n" << endl;
    }
};

// Самокат
class Scooter :public Transport
{
public:
    int wheel = 3;
    int speed = 10;
    string name = "самокат";
    void display()
    {
        cout << "Наименование транспорта: " << name
            << "\nКол-во колес: " << wheel
            << "\nМаксимальная скорость: " << speed << "км/ч\n" << endl;
    }
};

// Автомобиль
class Car :public Transport
{
public:
    int wheel = 4;
    int speed = 150;
    string name = "автомобиль";
    void display()
    {
        cout << "Наименование транспорта: " << name
            << "\nКол-во колес: " << wheel
            << "\nМаксимальная скорость: " << speed << "км/ч\n" << endl;
    }
};

// Автобус
class Bus :public Transport
{
public:
    int wheel = 6;
    int speed = 100;
    string name = "автобус";
    void display()
    {
        cout << "Наименование транспорта: " << name
            << "\nКол-во колес: " << wheel
            << "\nМаксимальная скорость: " << speed << "км/ч\n" << endl;
    }
};

// Фабрика
class Factory
{
public:
    static Transport* createTransport(const int& transportNumber) 
    {
        Transport* t = NULL;
        switch (transportNumber) {
        case 0: return new Motorbike();
        case 1: return new Scooter();
        case 2: return new Car();
        case 3: return new Bus();
        default:
            return t;
        }
    }
};

int main()
{
    setlocale(LC_ALL, "");

    vector <Transport*> a; // Здесь будут храниться запрашиваемые объекты
    string number;
    int val = -1;

    getline(cin, number);
    stringstream parse( number );
    number = "";
    
    // Проверяем каждое введенное число через пробел, если является числом, добавляем в конец вектора
    while (parse >> number) 
    {
        if (stringstream(number) >> val) 
        {           
            a.push_back(Factory::createTransport(val));  
        }
    }

    // Перебираем вектор, если объект существует, то выводим информацию
    for (auto i : a) 
    {
        if(i == NULL) 
            cout << "НЕИЗВЕСТНЫЙ ТИП ТРАНСПОРТА\n" << endl;
        else 
        {
            i->display();
            delete i;
        }
    }
}