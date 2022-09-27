#include <iostream>
using namespace std;
template <typename T>
class List
{
public:
	List();
	~List();
	List(const List&);
	void DelAll();
	void AddTail(T n);
	int GetCount() { return count; };
	void Extract();
	void Print();
	T& operator[](const int index);
	bool IsEmpty();
private:
	template <typename T>
	class Node
	{
	public:
		Node* next;
		Node* prev;
		T data;
		Node(T data = T(), Node* pNext = nullptr, Node* pRev = nullptr)
		{
			this->data = data;
			this->next = pNext;
			this->prev = pRev;
		}
	};
	int count;
	Node<T>* Head;
	Node<T>* Tail;
};
template <typename T>
List<T>::List()
{
	// Изначально список пуст
	Head = Tail = NULL;
	count = 0;
}
template <typename T>
List<T>::List(const List& L)
{
	Head = Tail = NULL;
	count = 0;
	Node<T>* temp = L.Head;
	while (temp != 0)
	{
		AddTail(temp->data);
		temp = temp->next;
	}
}
template <typename T>
List<T>::~List()
{
	DelAll();
}
template <typename T>
void List<T>::DelAll()
{
	Head = Tail = NULL;
	count = 0;
}
template <typename T>
void List<T>::AddTail(T n)
{
	// Создаем новый элемент
	Node<T>* temp = new Node<T>;
	// Следующего нет
	temp->next = 0;
	// Заполняем данные
	temp->data = n;
	// Предыдущий - бывший хвост
	temp->prev = Tail;

	// Если элементы есть?
	if (Tail != 0)
		Tail->next = temp;

	// Если элемент первый, то он одновременно и голова и хвост
	if (count == 0)
		Head = Tail = temp;
	else
		// иначе новый элемент - хвостовой
		Tail = temp;

	count++;
}
template <typename T>
void List<T>::Extract()
{
	Node<T>* temp = Head;
	if (Head == temp->prev)
	{
		return;
	}
	Head = Head->next;
	delete temp;
	count--;
}
template <typename T>
void List<T>::Print()
{
	if (count != 0)
	{
		Node<T>* temp = Head;
		cout << "| ";
		while (temp->next != 0)
		{
			cout << temp->data << " | ";
			temp = temp->next;
		}

		cout << temp->data << " |\n";
	}
}
template<typename T>
bool List<T>::IsEmpty()
{
	if (GetCount() == 0)
	{
		return true;
	}
	return false;
}
template<typename T>
T& List<T>::operator[](const int index)
{
	int counter = 0;
	Node<T>* current = this->Head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			return current->data;
		}
		current = current->next;
		counter++;
	}

}
int main()
{
	List<int>obj;
	cout << "Empty? : " << obj.IsEmpty();
	cout << endl;
	int get;
	obj.AddTail(8);
	cout << "Enter the number of values: ";
	cin >> get;
	for (int i = 0; i < get; i++)
	{
		obj.AddTail(rand() % 10);
	}
	obj.Print();
	cout << endl;
	cout << "Empty? : " << obj.IsEmpty();
	obj.Extract();
	cout << endl;
	obj.Print();
	cout << endl;
	obj.DelAll();
	obj.Print();


}