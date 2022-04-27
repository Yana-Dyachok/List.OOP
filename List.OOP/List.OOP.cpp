/*Реалізуйте клас Однонаправлений список з методами:
	List(void);                                         void pushFront(T data); //в початок списку додає елемент
	~List(void);                                        void removeAt(int index);  //видаляє елемент по вказаному індексу
	void pushBack(T data); //додає елемент підряд       void popBack(); // видаляє з кінця спику елемент
	void popFront();//Видаляє перший елемент в списку   void insert(T data, int index); //вставка в заданий індекс
	void clear();//Видаляє всі елементи в списку        list.count(x)  Повертає кількість елементів зі значенням x
	int getSize();                                      T& operator[](const int index);*/
#include <iostream>
#include "List.h"
using namespace std;
void Print(List<int>& A);
int main()
{
	List<int> A;
	A.pushBack(23);//додає елемент підряд 
	A.pushBack(98);
	A.pushBack(4);
	A.pushBack(56);
	cout << "Push_back:" << endl; Print(A); cout<< endl;
	A.popFront();//Видаляє перший елемент в списку 
	cout << "Pop_front:"<< endl; Print(A); cout << endl;
	A.pushFront(5); //в початок списку додає елемент
	cout<< "Push_front:" << endl; Print(A); cout << endl;
	A.removeAt(2);//видаляє елемент по вказаному індексу
	cout << "Remove element:" << endl; Print(A); cout << endl;
	A.popBack();// видаляє з кінця спику елемент
	cout << "Pop_back:" << endl; Print(A); cout << endl;
	A.insert(34, 1);//вставка в заданий індекс
	cout << "Insert :" << endl; Print(A); cout << endl;
	cout<<"Overloading []=" << A[2]<<endl;
	cout<< "List=" << A.listCount(98) << endl;// повертає кількість елементів зі значенням x
	A.clear();//Видаляє всі елементи в списку
}


void Print(List<int>& A) {
	for (int i = 0; i < A.getSize(); i++)
	{
		cout << A[i] << "\t";
	}
}