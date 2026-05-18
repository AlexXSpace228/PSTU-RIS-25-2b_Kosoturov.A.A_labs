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
	FODE<T>* new_node = new FODE<T>();
	new_node->data = data;
	new_node->next_ptr = tmp.head;
	tmp.head = new_node;
	tmp.size++;
};

template <class T>
void PopS(Stack<T>& tmp)
{

	if (tmp.head != nullptr)
	{

		FODE<T>* delete_element = tmp.head;
		tmp.head = tmp.head->next_ptr;

		delete delete_element;

		tmp.size--;
	}
};

template <class T>
void PrintStack(Stack<T>& s)
{
	if (s.head == nullptr)
	{
		std::cout << "Стек пуст\n";
		return;
	}

	FODE<T>* cur = s.head;

	while (cur != nullptr)
	{
		std::cout << cur->data << " ";
		cur = cur->next_ptr;
	}

	std::cout << std::endl;
}

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
	if (l.head_node == nullptr)
		return;

	// Удаление головы
	while (l.head_node && l.head_node->key == del)
	{
		point* tmp = l.head_node;
		l.head_node = l.head_node->next;
		delete tmp;
	}

	point* cur = l.head_node;

	while (cur && cur->next)
	{
		if (cur->next->key == del)
		{
			point* toDelete = cur->next;
			cur->next = toDelete->next;

			if (toDelete == l.tail_node)
				l.tail_node = cur;

			delete toDelete;
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

void PrintQueue(Queue* queue)
{
	if (QueueIsEmpty(queue))
	{
		std::cout << "Очередь пуста\n";
		return;
	}

	QNode* cur = queue->head;

	while (cur != nullptr)
	{
		std::cout << cur->key << " ";
		cur = cur->next;
	}

	std::cout << std::endl;
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
	int n;
	std::string key;

	do {
		std::cout << "\n==============================\n";
		std::cout << "      СТРУКТУРЫ ДАННЫХ\n";
		std::cout << "==============================\n";
		std::cout << "1. Двусвязный список\n";
		std::cout << "2. Односвязный список\n";
		std::cout << "3. Стек\n";
		std::cout << "4. Очередь\n";
		std::cout << "0. Выход\n";
		std::cout << "==============================\n";
		std::cout << "Ваш выбор: ";
		std::cin >> choice;

		switch (choice) {

		case 1: {
			std::cout << "\n--- ДВУСВЯЗНЫЙ СПИСОК ---\n";
			List list;
			std::cout << "Создание списка. Введите количество элементов: ";
			std::cin >> n;
			FillList(list, n);

			std::cout << "\n[ Исходный список ]: "; PrintList(list);

			std::cout << "\n[+] PushFront (Добавляем \"START\" в начало)...\n";
			PushFront(list, "START");
			PrintList(list);

			std::cout << "\n[+] PushBack (Добавляем \"END\" в конец)...\n";
			PushBack(list, "END");
			PrintList(list);

			std::cout << "\n[+] InsertByIndex (Вставляем \"MID\" на 2-ю позицию)...\n";
			InsertByIndex(list, "MID", 2);
			PrintList(list);

			std::cout << "\n[+] InsertByKey (Вставляем \"NEXT\" после ключа \"MID\")...\n";
			InsertByKey(list, "NEXT", "MID");
			PrintList(list);

			std::cout << "\n[-] PopFront (Удаляем первый элемент)...\n";
			PopFront(list);
			PrintList(list);

			std::cout << "\n[-] PopBack (Удаляем последний элемент)...\n";
			PopBack(list);
			PrintList(list);

			std::cout << "\n[-] POPByIndex (Удаляем элемент под индексом 1)...\n";
			POPByIndex(list, 1);
			PrintList(list);

			std::cout << "\n[-] DeleteEl (Введите точный ключ для удаления): ";
			std::cin >> key;
			DeleteEl(list, key);
			std::cout << "[ Результат ]: "; PrintList(list);

			break;
		}

		case 2: {
			std::cout << "\n--- ОДНОСВЯЗНЫЙ СПИСОК ---\n";
			Lister1 list1;
			std::cout << "Создание списка. Введите количество элементов: ";
			std::cin >> n;
			FillList11(list1, n);

			std::cout << "\n[ Исходный список ]: "; PrintList11(list1);

			std::cout << "\n[+] PushFront1 (Добавляем \"FIRST\" в начало)...\n";
			PushFront1(list1, "FIRST");
			PrintList11(list1);

			std::cout << "\n[+] pushBACKone (Добавляем \"LAST\" в конец)...\n";
			pushBACKone(list1, "LAST");
			PrintList11(list1);

			std::cout << "\n[-] popFRONTone (Удаляем первый элемент)...\n";
			popFRONTone(list1);
			PrintList11(list1);

			std::cout << "\n[-] PopBackone (Удаляем последний элемент)...\n";
			PopBackone(list1);
			PrintList11(list1);

			std::cout << "\n[-] DeleteEl11 (Введите ключ для удаления): ";
			std::cin >> key;
			DeleteEl11(list1, key);
			std::cout << "[ Результат ]: "; PrintList11(list1);

			break;
		}

		case 3: {
			std::cout << "\n--- СТЕК (LIFO) ---\n";
			Stack<std::string> s;
			SetStack(s);

			std::cout << "[+] Добавляем элементы: \"C++\", \"is\", \"Awesome\"\n";
			Push(s, std::string("C++"));
			Push(s, std::string("is"));
			Push(s, std::string("Awesome"));

			std::cout << "[ Текущий стек ]: ";
			PrintStack(s);

			std::cout << "\n[-] PopS (Снимаем верхний элемент)...\n";
			PopS(s);
			std::cout << "[ Результат ]: ";
			PrintStack(s);

			std::cout << "\n[-] PopS (Снимаем еще один)...\n";
			PopS(s);
			std::cout << "[ Результат ]: ";
			PrintStack(s);

			break;
		}

		case 4: {
			std::cout << "\n--- ОЧЕРЕДЬ (FIFO) ---\n";
			std::cout << "Укажите стартовый размер очереди: ";
			std::cin >> n;

			Queue* q = CreateQueue(n);
			std::cout << "\n[ Исходная очередь ]: "; PrintQueue(q);

			std::cout << "\n[+] AddElements (Добавление новых элементов внутрь)\n";
			std::cout << "Сколько элементов добавить? ";
			int count, pos;
			std::cin >> count;
			std::cout << "Начиная с какой позиции? ";
			std::cin >> pos;
			AddElements(q, count, pos);
			std::cout << "[ После добавления ]: "; PrintQueue(q);

			std::cout << "\n[-] RemoveElement (Удаление по ключу)\n";
			std::cout << "Введите ключ для удаления: ";
			std::cin >> key;
			RemoveElement(q, key);
			std::cout << "[ После удаления ]: "; PrintQueue(q);

			std::cout << "\n[-] QPop (Извлечение элемента из начала очереди)...\n";
			QPop(q);
			std::cout << "[ Итоговая очередь ]: "; PrintQueue(q);

			break;
		}

		case 0:
			std::cout << "Завершение программы...\n";
			break;

		default:
			std::cout << "Ошибка: Неверный пункт меню. Попробуйте снова.\n";
			break;
		}

	} while (choice != 0);

	return 0;
}