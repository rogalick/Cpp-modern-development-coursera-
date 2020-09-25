#include <iostream>
#include <map>
#include <exception>
//Реализуйте шаблонную функцию GetRefStrict, которая на вход принимает: map и значение ключа k.
//Если элемент по ключу k в коллекции отсутствует,
//то функция должна бросить исключение runtime_error, иначе вернуть ссылку на элемент в коллекции.
using namespace std;
template <typename Key, typename Value>
Value& GetRefStrict(map<Key, Value>& m, Key k) {
	if (m.count(k) == 1) {
		return m[k];
	}
	else {
		throw runtime_error("K isn`t exist\n");
	}
}
