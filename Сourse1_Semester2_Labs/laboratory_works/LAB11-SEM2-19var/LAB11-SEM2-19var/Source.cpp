#include <iostream>
#include <string>
#include <clocale>

// стек
template <class T>
struct FODE
{
	T data;
	FODE<T>* next_ptr;
};

template <class T>
struct Stack
{
	FODE<T>* head;
	int size;
};

template <class T>
void SetFODE(FODE<T>*& node, T data = T(), FODE<T>* next_ptr = nullptr)
{
	node = new FODE<T>();
	node->next_ptr = next_ptr;
	node->data = data;
};

template <class T>
void SetStack(Stack<T>& tmp)
{
	tmp.head = nullptr;
	tmp.size = 0;
};

template<class T>
void Push(Stack<T>& tmp, const T& data)
{
	//Создается новый узел
	FODE<T>* new_node;

	//Устанавливаются его поля, при помощи функции SetNode
	//Параметр data - то что добавляется
	//Поле next_ptr должно указывать на верхушку стека
	SetFODE(new_node, data, tmp.head);

	//Теперь голова стека, является новым узлом
	tmp.head = new_node;
	//Изменение поля размер
	tmp.size++;
};

template <class T>
void PopS(Stack<T>& tmp)
{
	//Если есть что удалять
	if (tmp.head != nullptr)
	{
		//Запоминаем адрес текущей головы
		FODE<T>* delete_element = tmp.head;

		//Перемещаем голову на следующий узел
		tmp.head = tmp.head->next_ptr;

		//Освобождаем ресурсы
		delete delete_element;

		//Изменяем поле размер
		tmp.size--;
	}
};

//двунаправленный
struct Node
{
	std::string data;
	Node* pointer_to_prev_node;
	Node* pointer_to_next_node;
};

struct List
{
	Node* head_node = nullptr;
	Node* tail_node = nullptr;
};

struct List1
{
	Node* head_node = nullptr;
};

struct point //однонаправленный
{
	std::string key;
	point* next;
};

struct Lister //однонаправленный
{
	point* head_node = nullptr;
};

struct Lister1 //однонаправленный
{
	point* head_node = nullptr;
	point* tail_node = nullptr;
};


//удаление в двунаправленном по элементу
static void DeleteEl(List& l, std::string& del)
{
	Node* cur = l.head_node;
	while (cur != nullptr)
	{
		if (cur->data == del)
		{
			Node* toDelete = cur; // сохраняем удаляемый узел
			cur = cur->pointer_to_next_node; // переходим к следующему до удаления

			if (toDelete == l.head_node && toDelete == l.tail_node)
			{
				// единственный элемент
				l.head_node = nullptr;
				l.tail_node = nullptr;
			}
			else if (toDelete == l.head_node)
			{
				// удаление головы
				l.head_node = toDelete->pointer_to_next_node;
				l.head_node->pointer_to_prev_node = nullptr;
			}
			else if (toDelete == l.tail_node)
			{
				// удаление хвоста
				l.tail_node = toDelete->pointer_to_prev_node;
				l.tail_node->pointer_to_next_node = nullptr;
			}
			else
			{
				// удаление из середины
				toDelete->pointer_to_prev_node->pointer_to_next_node = toDelete->pointer_to_next_node;
				toDelete->pointer_to_next_node->pointer_to_prev_node = toDelete->pointer_to_prev_node;
			}

			delete toDelete; // удаляем сохраненный узел
		}
		else
		{
			cur = cur->pointer_to_next_node;
		}
	}
}

//удаление в двунаправленном первого элемента
static void PopFront(List& l)
{
	if (l.head_node == nullptr) return;

	Node* tmp = l.head_node;
	l.head_node = tmp->pointer_to_next_node;

	if (l.head_node != nullptr)
		l.head_node->pointer_to_prev_node = nullptr;
	else
		l.tail_node = nullptr;

	delete tmp;
}
//удаление в двунаправленном последнего элемента
static void PopBack(List& l)
{
	if (l.tail_node == nullptr) return;

	Node* tmp = l.tail_node;
	l.tail_node = tmp->pointer_to_prev_node;

	if (l.tail_node != nullptr)
		l.tail_node->pointer_to_next_node = nullptr;
	else
		l.head_node = nullptr;

	delete tmp;
}
//удаление в двунаправленном по индексу
static void POPByIndex(List& l, int index)
{
	if (index <= 0)
	{
		PopFront(l);
		return;
	}

	Node* cur = l.head_node;
	int i = 0;

	while (cur != nullptr && i < index - 1)
	{
		cur = cur->pointer_to_next_node;
		i++;
	}

	if (cur == nullptr)
	{
		PopBack(l);
		return;
	}

	Node* toDelete = cur; // сохраняем удаляемый узел
	cur = cur->pointer_to_next_node; // переходим к следующему до удаления

	if (toDelete == l.head_node && toDelete == l.tail_node)
	{
		// единственный элемент
		l.head_node = nullptr;
		l.tail_node = nullptr;
	}
	else if (toDelete == l.head_node)
	{
		// удаление головы
		l.head_node = toDelete->pointer_to_next_node;
		l.head_node->pointer_to_prev_node = nullptr;
	}
	else if (toDelete == l.tail_node)
	{
		// удаление хвоста
		l.tail_node = toDelete->pointer_to_prev_node;
		l.tail_node->pointer_to_next_node = nullptr;
	}
	else
	{
		// удаление из середины
		toDelete->pointer_to_prev_node->pointer_to_next_node = toDelete->pointer_to_next_node;
		toDelete->pointer_to_next_node->pointer_to_prev_node = toDelete->pointer_to_prev_node;
	}

	delete toDelete; // удаляем сохраненный узел
}
// добавление в начало в двунаправленном
static void PushFront(List& l, const std::string& data)
{
	Node* n = new Node;
	n->data = data;
	n->pointer_to_prev_node = nullptr;
	n->pointer_to_next_node = l.head_node;

	if (l.head_node != nullptr)
		l.head_node->pointer_to_prev_node = n;
	else
		l.tail_node = n; // если список пуст

	l.head_node = n;
}
// добавление в конец в двунаправленном
static void PushBack(List& l, const std::string& data)
{
	Node* n = new Node;
	n->data = data;
	n->pointer_to_next_node = nullptr;
	n->pointer_to_prev_node = l.tail_node;

	if (l.tail_node != nullptr)
		l.tail_node->pointer_to_next_node = n;
	else
		l.head_node = n;

	l.tail_node = n;
}
// ды
static void PrintList1(List1 l)
{
	Node* cur = l.head_node;
	while (cur != nullptr)
	{
		std::cout << cur->data << ' ';
		cur = cur->pointer_to_next_node;
	}
	std::cout << std::endl;
}
// вывод двунаправленного
static void PrintList(List l)
{
	Node* cur = l.head_node;
	while (cur != nullptr)
	{
		std::cout << cur->data << ' ';
		cur = cur->pointer_to_next_node;
	}
	std::cout << std::endl;
}

static void InsertByIndex(List& l, const std::string& data, int index)
{
	if (index <= 0)
	{
		PushFront(l, data);
		return;
	}

	Node* cur = l.head_node;
	int i = 0;

	while (cur != nullptr && i < index - 1)
	{
		cur = cur->pointer_to_next_node;
		i++;
	}

	if (cur == nullptr)
	{
		PushBack(l, data);
		return;
	}

	Node* n = new Node;
	n->data = data;

	n->pointer_to_next_node = cur->pointer_to_next_node;
	n->pointer_to_prev_node = cur;

	if (cur->pointer_to_next_node != nullptr)
		cur->pointer_to_next_node->pointer_to_prev_node = n;
	else
		l.tail_node = n;

	cur->pointer_to_next_node = n;
}

static void FillList(List& l, int size)
{
	std::string temp;
	std::cout << "Введите элементы: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << "-й элемент: ";
		std::cin >> temp;
		InsertByIndex(l, temp, i);
	}
}

static void InsertByKey(List& l, const std::string& newData, const std::string& key)
{
	Node* cur = l.head_node;

	while (cur != nullptr)
	{
		if (cur->data == key)
		{
			Node* n = new Node;
			n->data = newData;

			n->pointer_to_next_node = cur->pointer_to_next_node;
			n->pointer_to_prev_node = cur;

			if (cur->pointer_to_next_node != nullptr)
				cur->pointer_to_next_node->pointer_to_prev_node = n;
			else
				l.tail_node = n;

			cur->pointer_to_next_node = n;
			return;
		}
		cur = cur->pointer_to_next_node;
	}
}

static void PushFront1(List1& l, const std::string& data)
{
	Node* n = new Node;
	n->data = data;
	n->pointer_to_prev_node = nullptr;
	n->pointer_to_next_node = l.head_node;

	if (l.head_node != nullptr)
		l.head_node->pointer_to_prev_node = n;

	l.head_node = n;
}

static void PushBack1(List1& l, const std::string& data)
{
	Node* n = new Node;
	n->data = data;
	n->pointer_to_next_node = nullptr;
	if (!l.head_node) {
		// Список пуст
		l.head_node = n;
	}
	else {
		// Находим последний элемент (проходим весь список)
		Node* current = l.head_node;
		while (current->pointer_to_next_node) {
			current = current->pointer_to_next_node;
		}

		// Вставляем после последнего
		current->pointer_to_next_node = n;
		n->pointer_to_prev_node = current;
	}
}

static void InsertByIndex1(List1& l, const std::string& data, int index)
{
	if (index <= 0)
	{
		PushFront1(l, data);
		return;
	}

	Node* cur = l.head_node;
	int i = 0;

	while (cur != nullptr && i < index - 1)
	{
		cur = cur->pointer_to_next_node;
		i++;
	}

	if (cur == nullptr)
	{
		PushBack1(l, data);
		return;
	}

	Node* n = new Node;
	n->data = data;

	n->pointer_to_next_node = cur->pointer_to_next_node;
	n->pointer_to_prev_node = cur;

	if (cur->pointer_to_next_node != nullptr)
		cur->pointer_to_next_node->pointer_to_prev_node = n;
	cur->pointer_to_next_node = n;
}
//при создании однонаправленного
//std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

static void popFRONTone(Lister1& list) {
	if (list.head_node == nullptr)
		return;
	point* remove = list.head_node;
	list.head_node = list.head_node->next;
	delete remove;
}

static void DeleteEl11(Lister1& l, std::string del)
{
	point* cur = l.head_node;
	if (cur->key == del)
	{
		popFRONTone(l);
		return;
	}
	while (cur != nullptr)
	{
		if (cur->next->key == del)
		{
			point* toDelete = cur->next; // сохраняем удаляемый узел

			if (toDelete == l.head_node && toDelete == l.tail_node)
			{
				// единственный элемент
				l.head_node = nullptr;
				l.tail_node = nullptr;
			}
			else if (toDelete == l.head_node)
			{
				// удаление головы
				l.head_node = toDelete->next;
			}
			else if (toDelete == l.tail_node)
			{
				l.tail_node->next = nullptr;
			}
			else
			{
				// удаление из середины
				cur->next = toDelete->next;
			}

			delete toDelete; // удаляем сохраненный узел
		}
		else
		{
			cur = cur->next;
		}
	}
}

static void PushFront1(Lister1& l, const std::string& data)
{
	point* n = new point;
	n->key = data;
	n->next = l.head_node;
	/*
	if (l.head_node != nullptr)
		l.head_node->pointer_to_prev_node = n;
	*/
	l.head_node = n;
}

static void pushBACKone(Lister1& list, const std::string& data) {
	point* new_node = new point;
	new_node->key = data;
	new_node->next = nullptr; 

	if (list.tail_node != nullptr)
		list.tail_node->next = new_node;
	else
		list.head_node = new_node;

	list.tail_node = new_node;
}

static void FillList11(Lister1& l, int size)
{
	std::string temp;
	std::cout << "Введите элементы: " << std::endl;
	for (int i = 0; i < size; i++)
	{
		std::cout << i + 1 << "-й элемент: ";
		std::cin >> temp;
		pushBACKone(l, temp);
	}
}

static void PopBackone(Lister1& l)
{
	if (l.tail_node == nullptr) return;

	point* tmp = l.tail_node;

	if (!l.head_node->next) {
		// Только один элемент
		delete l.head_node;
		l.head_node = nullptr;
	}
	else {
		// Находим предпоследний элемент
		point* current = l.head_node;
		while (current->next != l.tail_node) {
			current = current->next;
		}
		delete l.tail_node;
		l.tail_node = current;
		l.tail_node->next = nullptr;
	}
}

static void PrintList11(Lister1 l)
{
	point* cur = l.head_node;
	while (cur != nullptr)
	{
		std::cout << cur->key << ' ';
		cur = cur->next;
	}
	std::cout << std::endl;
}

//Очереди
struct QNode
{
	std::string key;             // Данные, хранимые в узле (строка – "ключ")
	QNode* next = nullptr;   // Указатель на следующий узел (по умолчанию nullptr)
};

struct Queue
{
	QNode* head = nullptr;   // Указатель на первый элемент (голову) очереди
	QNode* tail = nullptr;   // Указатель на последний элемент (хвост) очереди
	int size = 0;           // Текущий размер очереди (количество элементов)
};

void QPop(Queue* queue)
{
	QNode* temp = queue->head;    // Сохраняем ссылку на удаляемый узел
	queue->head = temp->next;    // Перенаправляем head на следующий узел
	queue->size--;               // Уменьшаем счетчик элементов
	delete temp;                 // Освобождаем память
}

// Состояние очереди (пустая/непустая)
bool QueueIsEmpty(Queue* queue)
{
	return queue->size == 0;
}

// Добавление элемента в конец очереди
void QPushBack(Queue* queue, std::string str)
{
	if (!QueueIsEmpty(queue))
	{
		QNode* new_node = new QNode;    // Создаем новый узел
		queue->size++;
		new_node->key = str;
		new_node->next = nullptr;
		queue->tail->next = new_node; // Добавляем в конец очереди
		queue->tail = new_node;       // Обновляем указатель на хвост
	}

	else // Если очередь пуста
	{
		QNode* new_node = new QNode;    // Создаем первый узел
		queue->size = 1;              // Размер становится 1
		new_node->key = str;
		queue->head = new_node;       // Голова и хвост указывают на новый узел
		queue->tail = new_node;
	}
}

void RemoveElement(Queue* queue, std::string k)
{
	if (QueueIsEmpty(queue))
	{
		std::cout << "Очередь пуста!" << std::endl;
		return;
	}

	int i = 1;                        // Счетчик обработанных элементов
	while (i <= queue->size)
	{
		if (queue->head->key != k)    // Если не искомый элемент
		{
			QPushBack(queue, queue->head->key); // Переносим в конец
			QPop(queue);                        // Удаляем из начала
			i++;                               // Увеличиваем счетчик
		}
		else
		{
			QPop(queue);               // Если нашли элемент, просто удаляем
		}
	}
}


void AddElements(Queue* queue, int count, int number)
{
	int i = 1;
	while (i < number) // Перемещение первых (number-1) элементов в конец
	{
		QPushBack(queue, queue->head->key);
		QPop(queue);
		i++;
	}
	std::string key;

	for (int j = 1; j <= count; j++) // Ввод и добавление новых элементов
	{
		std::cout << "Введите новый ключ: ";
		std::cin >> key;
		QPushBack(queue, key);
	}
	// Перенос оставшихся элементов из начала в конец
	for (i; i <= queue->size - count; i++)
	{
		QPushBack(queue, queue->head->key);
		QPop(queue);
	}
}

Queue* CreateQueue(int size)
{
	Queue* queue = new Queue; // Создание пустой очереди
	std::string str;

	std::cout << "Введите ключи элементов:" << std::endl;

	// Заполнение очереди элементами
	for (int i = 1; i <= size; i++)
	{
		std::cout << i << '\t';
		std::cin >> str;
		QPushBack(queue, str); // Добавление элемента в очередь
	}
	return queue;
}

int main() {

	setlocale(LC_ALL, "RU");
	system("chcp 1251");
	system("cls");

	int choice;

	do {
		std::cout << "\n=== МЕНЮ ===\n";
		std::cout << "1 - Двусвязный список\n";
		std::cout << "2 - Односвязный список\n";
		std::cout << "3 - Стек\n";
		std::cout << "4 - Очередь\n";
		std::cout << "0 - Выход\n";
		std::cout << "Выбор: ";
		std::cin >> choice;

		switch (choice) {

		case 1: {
			List list;
			int n;
			std::cout << "Размер: ";
			std::cin >> n;

			FillList(list, n);
			PrintList(list);

			std::cout << "Удаление по ключу: ";
			std::string key;
			std::cin >> key;
			DeleteEl(list, key);

			PrintList(list);
			break;
		}

		case 2: {
			Lister1 list;
			int n;
			std::cout << "Размер: ";
			std::cin >> n;

			FillList11(list, n);
			PrintList11(list);

			std::cout << "Удаление по ключу: ";
			std::string key;
			std::cin >> key;
			DeleteEl11(list, key);

			PrintList11(list);
			break;
		}

		case 3: {
			Stack<std::string> s;

			Push(s, std::string("A"));
			Push(s, std::string("B"));
			Push(s, std::string("C"));

			std::cout << "Pop...\n";
			PopS(s);
			break;
		}

		case 4: {
			int n;
			std::cout << "Размер очереди: ";
			std::cin >> n;

			Queue* q = CreateQueue(n);

			std::cout << "Удалить элемент по ключу: ";
			std::string k;
			std::cin >> k;

			RemoveElement(q, k);
			break;
		}

		case 0:
			std::cout << "Выход...\n";
			break;

		default:
			std::cout << "Ошибка выбора\n";
		}

	} while (choice != 0);

	return 0;

	/*
	List list;
	int N, K, num;
	std::string deleting, temp;

	std::cout << "Написать функцию для создания списка. Функция может создавать пустой список, а затем добавлять в него элементы.\n\n";
	std::cout << "Укажите количество элементов списка: ";

	std::cin >> N; // N - длинна массива
	FillList(list, N);

	std::cout << "\nНаписать функцию для печати списка. Функция должна предусматривать вывод сообщения, если список пустой.\n\n";

	PrintList(list);

	std::cout << "\nНаписать функции для удаления и добавления элементов списка в соответствии со своим вариантом (Удалить  К элементов с заданными номерами.).\n\n";

	int deletingK;
	std::cout << "Введите количество элементов которые хотите удалить: ";
	std::cin >> deletingK;
	for (int i = 0; i < deletingK; i++) {
		std::cout << "Какой элемент вы хотите удалить?" << std::endl;
		std::cin >> deleting;
		DeleteEl(list, deleting);
		PrintList(list);
	}

	std::cout << "Введите количество элементов, которые хотите добавить: ";
	std::cin >> K;

	if (K > 0) {
		std::cout << "Введите номер элемента перед которым хотите добавить новые элементы: ";
		std::cin >> num;
		std::cout << "Вводите элементы: " << std::endl;
		for (int i = 0; i < K; i++)
		{
			std::cout << (i+1) << " новый элемент: ";
			std::cin >> temp;
			InsertByIndex(list, temp, num - 1);
		}
		PrintList(list);
	}
	
	std::string key, data;
	std::cout << "Введите элемент после которого следует добавить новый: ";
	std::cin >> key;
	std::cout << "Введите новый элемент: ";
	std::cin >> data;
	InsertByKey(list, data, key);

	PrintList(list);

	std::cout << "Удаление элемента по номеру: ";

	int k;
	std::cin >> k;
	POPByIndex(list, k);

	PrintList(list);

	std::string delEle;
	std::cout << "Удаление элемента по ключу: ";
	std::cin >> delEle;
	DeleteEl(list, delEle);

	PrintList(list);
	*/
	/*
	List1 list1;
	PushBack1(list1, ".");
	PushBack1(list1, "4");
	PushFront1(list1, "5");
	PushBack1(list1, "2");

	PrintList1(list1);
	

	Lister1 list;
	int N, K, num;
	std::string deleting, temp;


	std::cout << "Укажите количество элементов списка: ";
	std::cin >> N; // N - длинна массива
	FillList11(list, N);
	PrintList11(list);
	PopBackone(list);
	PrintList11(list);
	PushFront1(list, "ggg");
	PrintList11(list);
	std::string s = "bbb";
	DeleteEl11(list, s);
	PrintList11(list);*/
	return 0;
}

/*

1. 11 лабу надо сделать для односвязных и двусвязных списков, неважно, что указано в твоём варианте. Для очередей и для стеков.
2. Организовать функции:
   2.1. Добавление элемента в конец/начало. +
   2.2. Удаление элемента из конца и из начала. *
   2.3. Удаление элемента по ключу. -
   2.4. Удаление элемента по номеру. +
   2.5. Добавление элемента по ключу. +
   2.6. Добавление элемента по номеру. +
3. Выполнить задание, которое указано в варианте.
4. Учесть, что для списков нужно организовать два способа добавления элемента:
	1 способ - функция, где хранится только головной узел. ----------> list1
	2 способ - где хранятся и головной, и хвостовой узлы. +
5. Обязательно нужно организовать вывод элементов. +
6. В методичке есть постановка и шаги решения, в шагах около 10 пунктов? Не помню точно. Некоторые, которые в методичке, совпадают с теми, которые дала Полякова.
Но, которые не совпадают, тоже желательно добавить в код.
7. В очередях ещё организовать вставку элементов перед заданным номером.

*/

/*

Постановка задачи

Написать программу, в которой создаются динамиче-ские структуры и  выполнить их обработку в соответствии со своим вариантом.
Для каждого вариант разработать следующие функции:
1.	Создание списка. +
2.	Добавление элемента в список (в соответствии со своим вариантом). +
3.	Удаление элемента из списка (в соответствии со своим вариантом). +
4.	Печать списка. +
5.	Запись списка в файл. -
6.	Уничтожение списка. - 
7.	Восстановление списка из файла. -

*/

/*

Порядок выполнения работы

+ 1.	Написать функцию для создания списка. Функция может создавать пустой список, а затем добавлять в него элементы. 
+ 2.	Написать функцию для печати списка. Функция должна предусматривать вывод сообщения, если список пустой.
+ 3.	Написать функции для удаления и добавления элементов списка в соответствии со своим вариантом (Удалить  К элементов с заданными номерами.).
+ 4.	Выполнить изменения в списке и печать списка после каждого изменения.
- 5.	Написать функцию для записи списка в файл.
- 6.	Написать функцию для уничтожения списка.
- 7.	Записать список в файл, уничтожить его и выполнить печать (при печати должно быть выдано сообщение "Спи-сок пустой").
- 8.	Написать функцию для восстановления списка из файла.
- 9.	Восстановить список и распечатать его.
- 10.	Уничтожить список.

*/
