#include <iostream>
#include <queue>        // подключаем заголовочный файл очереди
#include <string>       // заголовочный файл для работы со строками типа string
using namespace std;
#include <cstdio>
 
int main()
{
    queue<string> myQueue;     // создаем пустую очередь типа string
    if (myQueue.front()==NULL){
		printf("ff");
	}
 
    // добавили в очередь несколько элементов типа string
    //myQueue.push("No pain ");
    //myQueue.push("- no gain");
    
 
    //cout << "Количество элементов в очереди: " << myQueue.size() << endl;
    //cout << "\nВот они: " << myQueue.front() << myQueue.back();
 
    //myQueue.pop(); // удаляем один элемент в очереди
    //cout << "\nТеперь в очереди остался один элемент: " << myQueue.front();
    //myQueue.pop();
    //cout << "\nТеперь в очереди остался один элемент: " << myQueue.front();
    //myQueue.pop();
    //cout << "\nТеперь в очереди остался один элемент: " << myQueue.front();
    //myQueue.pop();
    //cout << "\nТеперь в очереди остался один элемент: " << myQueue.front();
    return 0;
}
