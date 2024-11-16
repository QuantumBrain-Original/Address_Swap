#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

class Address_Storage
{
    std::string Name_City;
    std::string Name_Street;
    int Num_House;
    int Num_Apartment;

    public:
        void set_custom_address(std::string& city, std::string& street, int& house, int& apartment)
        {
            Name_City = city;
            Name_Street = street;
            Num_House = house;
            Num_Apartment = apartment;
        }

        std::string string_assembly()
        {
            return Name_City + ", " + Name_Street + ", " + std::to_string(Num_House) + ", " + std::to_string(Num_Apartment);
        }

        Address_Storage(const std::string city = "Санкт-Петербург", const std::string street = "Невский проспект", const int house = 17, const int apartment = 7)
        {
            Name_City = city;
            Name_Street = street;
            Num_House = house;
            Num_Apartment = apartment;
        }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "Russian");

    std::ifstream input("in.txt");

    if (input.is_open())
    {
        int size;
        input >> size;
        if (size <= 0)
        {
            std::cout << "Файл должен содержать больше 0 строк!\nПроверьте файл. Заполните строки и укажите их количество.";
            input.close();
            return 1;
        }
        else
        {
            Address_Storage* address_arr = new Address_Storage[size];
            std::string str1, str2;
            int tmp1, tmp2;

            for (int i = 0; i < size; i++)
            {
                if (!(input >> str1 >> str2 >> tmp1 >> tmp2))
                    break;
                address_arr[i].set_custom_address(str1, str2, tmp1, tmp2);
            }

            input.close();

            std::ofstream output("out.txt");
            output << size << std::endl;

            std::cout << "Количество строк: " << size << std::endl;

            for (int i = size - 1; i >= 0; i--)
            {
                std::cout << address_arr[i].string_assembly() << std::endl;
                output << address_arr[i].string_assembly() << std::endl;
            }

            output.close();
            delete[] address_arr;
        }
    }
    else
    {
        input.close();
        std::cout << "Файл поврежден или не найден!\nПроверьте файл и повторите попытку.";
        return 2;
    }
}
