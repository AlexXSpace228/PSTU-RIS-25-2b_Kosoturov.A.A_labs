#include <iostream>
#include <fstream>
#include <string>
#include "Random.h"

int collision_count = 0;

struct Human {

    std::string name;
    std::string ID;
    std::string birth_date;

    void createRandom() {
        name = getRandomName();
        ID = getRandomID();
        birth_date = getRandomDate();
    }

    void show() {
        std::cout << "ФИО:\t\t" << name
            << "\nДата рождения:\t" << birth_date
            << "\nНомер паспорта:\t" << ID << std::endl << std::endl;
        return;
    }
};

struct HashTable
{
    Human* arr;
    int size;

    void save() {
        std::ofstream name("FILEHASH.bin", std::ios::binary);
        name.write(reinterpret_cast<const char*>(&size), sizeof(size));
        for (int ind = 0; ind < size; ind++) {
            size_t len = arr[ind].name.length();
            name.write(reinterpret_cast<const char*>(&len), sizeof(len));
            name.write(arr[ind].name.c_str(), len);

            // Записываем дату рождения
            len = arr[ind].birth_date.length();
            name.write(reinterpret_cast<const char*>(&len), sizeof(len));
            name.write(arr[ind].birth_date.c_str(), len);

            // Записываем номер паспорта
            len = arr[ind].ID.length();
            name.write(reinterpret_cast<const char*>(&len), sizeof(len));
            name.write(arr[ind].ID.c_str(), len);
        }
        name.close();
    }

    int getSumDate(const std::string& s) {
        return stoi(s.substr(0, 6));
    }
    int hashFunction(const std::string& s) {
        double a = 150 / (0.045 * (7.512 - static_cast<int>(7.512)));//((sqrt(5) - 1) / 2) * getSumDate(s)
        double c = size * (a - static_cast<int>(a));
        return static_cast<int>(c);
    }

    void createBlankTable(int s) {
        size = s;
        arr = new Human[size];
    }
    void clearTable() {
        delete[] arr;
    }

    void showw() {
        for (int i = 0; i < size; i++) {
            std::cout << "\nИндекс ячейки: " << i << std::endl;
            arr[i].show();
        }
        return;
    }

    void add(const Human& to_add) {
        int ind = hashFunction(to_add.ID);
        int hash = ind;

        if (arr[ind].name == "") {
            arr[ind] = to_add;
            return;
        }
        else {
            while (ind < size) {

                if (arr[ind].name == "") {
                    arr[ind] = to_add;
                    return;
                }
                ind++;
                collision_count++;
            }

            if (ind >= size) {
                ind = 0;
                while (ind < hash) {
                    if (arr[ind].name == "") {
                        arr[ind] = to_add;
                        return;
                    }
                    ind++;
                    collision_count++;
                }
                if (ind >= hash) {
                    std::cout << "Таблица заполнена, элемент не может быть добавлен. \n\n";
                    return;
                }
            }
        }
    }

    void pop(const std::string& to_delete)
    {
        int ind = findIndex(to_delete);

        if (ind != -1)
        {
            arr[ind] = Human();
            return;
        }
        return;
    }

    int findIndex(const std::string& to_find) {
        int hash = hashFunction(to_find);
        int ind = hash;

        while (ind < size && arr[ind].ID != to_find)
            ind++;

        if (ind >= size) {
            ind = 0;

            while (ind < hash && arr[ind].ID != to_find)
                ind++;

            if (ind >= hash)
                return -1;
            else
                return ind;
        }
        else
            return ind;
    }
};

void fillArrayRandom(Human* arr, int count)
{
    Human stub;
    for (int i = 0; i < count; i++) {
        stub.createRandom();
        arr[i] = stub;
    }
    return;
}

void ReadFromFile() {

}

int main() {
    srand(time(0));
    setlocale(LC_ALL, "RU");

    int size = 0;
    do
    {
        std::cout << "Введите кол-во элементов в массиве (не меньше 1): ";
        std::cin >> size;
    } while (size < 1);
    std::cout << std::endl;
    std::fstream name("FILEHASH.bin", std::ios::binary);
    name.write(reinterpret_cast<const char*>(&size), sizeof(size));
    Human* arr = new Human[size];
    HashTable table;

    fillArrayRandom(arr, size);
    table.createBlankTable(size);

    for (int i = 0; i < size; i++)
        table.add(arr[i]);

    table.showw();

    table.save();

    std::ifstream file("FILEHASH.bin", std::ios::binary);
    if (!file.is_open()) return false;

    table.clearTable();

    file.read(reinterpret_cast<char*>(&size), sizeof(size));

    table.createBlankTable(size);

    std::cout << "\nЧтение из файла, кол-во пользователей: " << size << "\n\n";
    for (int i = 0; i < size; i++) {
        Human person;

        // Читаем ФИО
        size_t len;
        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        char* buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        person.name = buffer;
        delete[] buffer;

        // Читаем дату рождения
        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        person.birth_date = buffer;
        delete[] buffer;
        // Читаем номер паспорта
        file.read(reinterpret_cast<char*>(&len), sizeof(len));
        buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        person.ID = buffer;
        delete[] buffer;

        table.add(person);
    }

    file.close();

    table.showw();

    std::string id;
    std::cout << "Введите номер паспорта: ";
    std::cin >> id;
    int result_search = table.findIndex(id);

    if (result_search == -1)
        std::cout << "Человека с номером паспорта: \"" << id << "\" нет. \n\n";
    else
        std::cout << "Человек с номером паспорта: \"" << id << "\" содержится по индексу " << result_search << std::endl << std::endl;

    table.pop(id);

    std::cout << std::endl << std::endl << "====================================" << std::endl << std::endl;

    table.showw();

    std::cout << std::endl << "Кол-во коллизий для " << size << " записей: " << collision_count << std::endl << std::endl;

    table.clearTable();
    delete[] arr;
    return 0;
}