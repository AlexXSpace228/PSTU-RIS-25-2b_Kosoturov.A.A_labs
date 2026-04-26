#pragma once
#include <iostream>



class Vector
{
public:
	Vector(int s, int k = 0); //конструктор с параметрами: выделяет память под s элементов и заполняет их значением k
	Vector(const Vector&a); //конструктор с параметрами 

	//деструктор
	~Vector();

	Vector&operator=(const Vector&a); //оператор присваивания 

	int&operator[](int index); //операция доступа по индексу 

	Vector operator+(const int k); //операция для добавление константы

	int operator()(); //операция, возвращающая длину вектора 

	//перегруженные операции ввода-вывода
friend std::ostream& operator<<(std::ostream& out, const Vector& a);
friend std::istream& operator>>(std::istream& in, Vector& a);

private:
	int size;//размер вектора
	int* data;//укзатель на динамический массив значений вектора
};



//конструктор с параметрами
Vector::Vector(int s, int k)
{
	size = s;
	data = new int[size]; for (int i = 0; i < size; i++)
		data[i] = k;
}
//конструктор копирования
Vector::Vector(const Vector& a)
{
	size = a.size; data = new int[size];
	for (int i = 0; i < size; i++) data[i] = a.data[i];
}


//деструктор
Vector::~Vector()
{
	delete[]data; data = 0;
}


Vector&Vector::operator=(const Vector&a) //операция присваивания 
{
	if (this == &a)return *this; size = a.size;
	if (data != 0) delete[]data; data = new int[size]; for (int i = 0; i < size; i++)
		data[i] = a.data[i]; return *this;
}
int&Vector::operator[](int index)   //операция доступа по индексу 
{
	if (index < 0 || index >= size)
		throw std::out_of_range("Index out of range");
	return data[index];
}
Vector Vector::operator+(const int k)  //+k операция для добавления константы 
{
	Vector temp(size);
	for (int i = 0; i < size; ++i) temp.data[i] = data[i] + k;
	return temp;
}
int Vector::operator ()() //операция для получения длины вектора 
{
	return size;
}
std::ostream&operator<<(std::ostream&out,const Vector&a) //операции для ввода-выода 
{
	for (int i = 0; i < a.size; ++i) out << a.data[i] << " ";
	return out;
}
std::istream& operator>>(std::istream& in, Vector& a)
{
	for (int i = 0; i < a.size; ++i) in >> a.data[i];
	return in;
}