#include <string> 
#include <iostream> 
#include <cstring> 
#include "class_hash_table.h" 

using namespace std;

const char * array[] = 
{ "a", "b", "c", "d", "i",
  "f", "g", "h", "i", "j", 
  "k", "l", "m", "n", "o", 
  "p", "q", "r", "s", "t",
  "u", "v", "w", "x", "y", 
  "z" };

string HashTable::generate_string() {
	string s = "";
	int n = rand() % 28 + 1;
	for (int i = 0; i < n; i++) {
		s += array[rand() % (sizeof array / sizeof(char *))];
	}
	return s;
}

element_of_table HashTable::generate_element() {
	element_of_table new_element;
	new_element.key = generate_string();
	new_element.value = generate_string();
	return new_element;
}

int HashTable::hash(string key) {
	return ((sizeof(key) + 66) % bucket_size);
}

string HashTable::get_value(string key) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == key) {
			return mass[i].value;
		}
	}
	string v = "";
	return v;
}

void HashTable::put(element_of_table new_element) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == new_element.key) {
			mass[i].value = new_element.value;
			return;
		}
		if (!sizeof(mass[i].key)) {
			mass[hash(mass[i].key)].key = new_element.key;
			mass[hash(mass[i].key)].value = new_element.value;
			return;
		}
	}
}

void HashTable::del(string key) {
	for (int i = 0; i < bucket_size; i++) {
		if (mass[i].key == key) {
			mass[i].key.clear();
			mass[i].value.clear();
			return;
		}
	}
	return;
}

void HashTable::change_capaсity(int new_bucket_size) {
	int buff = bucket_size;
	bucket_size = new_bucket_size;
	element_of_table *new_mass = new element_of_table[new_bucket_size];
	for (int i = 0; i < buff; i++) {
		new_mass[hash(mass[i].key)].key = mass[i].key;
		new_mass[hash(mass[i].key)].value = mass[i].value;
	}
	element_of_table temp = *mass;
	*mass = *new_mass;
	*new_mass = temp;
	delete [] new_mass;
	return;
}
