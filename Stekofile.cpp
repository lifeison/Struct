#include <stdlib.h> 
#include "stdafx.h" 
#include <iostream> 
#include <windows.h> 
#include <fstream>
#include "stdafx.h"
#include <clocale> 

using namespace std;

struct node_s {
	int data;
	node_s* prev;
};

const char* db_file_name = "test_db.txt\0"; 

typedef struct db_file_s {
	FILE *file_ptr = NULL;
	char file_name[512];
} DBFile;

DBFile* initialize(const char *db_file_name);

void open_db(DBFile *db);

void close_db(DBFile *db);

void save_node_to_db(DBFile *db, node_s *data);

int read_from_db(DBFile *db, node_s**);

void free_db(DBFile *db);

int pop(node_s*);

void push(int);

node_s* top_adress = NULL;

int _tmain(int argc, _TCHAR* argv[]) {
	setlocale(LC_ALL, "Rus");      
	node_s* node = NULL;
	DBFile* db = initialize(db_file_name);
	cout << "Ñ÷èòûâàåì èç ôàéëà" << endl << endl;
	open_db(db);
	close_db(db);
    open_db(db);
while (read_from_db(db, &node)) {

		if (top_adress == NULL) {
			node->prev = NULL;
			top_adress = node;
		}
		else {

			node->prev = top_adress;
			top_adress = node;
		}
	}
	close_db(db);

	int request = -1;

	cout << "Ðàáîòà ñî ñòåêîì" << endl << endl;
	cout << "Çàïðîñ íà äåéñòâèå" << endl;
	cout << "1 - äîáàâèòü" << endl;
	cout << "2 - óäàëèòü" << endl;
	cout << "0 - âûõîä" << endl;
	while (request != 0)
	{
		cout << endl << "Âûáîð : ";
		cin >> request;
		switch (request) {
		case 1:
		{
			int data;
			cout << "Äîáàâèòü áàçó = ";
			cin >> data;
			push(data);
			break; }
		case 2:
		{if (top_adress == NULL)
			cout << "Íåò ýëåìåíòîâ â ñòåêå" << endl;
		else
			cout << "Çàïðàøèâàåìûå äàííûå = " << pop(top_adress) << endl;
		break;
		}
		default: break;
		}
	}
	cout << endl << "Ðàáîòà ñ ôàéëîì" << endl << endl;

	node_s* TOP = top_adress;

	open_db(db);
	while (TOP != 0) {
		save_node_to_db(db, TOP);
		TOP = TOP->prev;
	}
	close_db(db);

	_gettch();
	return 0;
}

int pop(node_s* top) {
	int saved_data = top->data;
	top_adress = top->prev;
	delete top;
	return saved_data;
}

void push(int new_data) {
	node_s* node = new node_s;
	node->data = new_data;
	node->prev = top_adress;
	top_adress = node;
}

void open_db(DBFile *db) {
	db->file_ptr = fopen(db->file_name, "ab+");
}

void close_db(DBFile *db) {
	fclose(db->file_ptr);
}

void save_node_to_db(DBFile *db, node_s *data) {
	fwrite(data, sizeof(node_s), 1, db->file_ptr);
}

void free_db(DBFile *db) {
	free(db);
}

int read_from_db(DBFile *db, node_s** node) {
	*node = (node_s*)malloc(sizeof(node_s));
	return fread(*node, sizeof(node_s), 1, db->file_ptr);
}

DBFile* initialize(const char *db_file_name) {
	DBFile *db_file = (DBFile *)malloc(sizeof(DBFile));
	db_file->file_ptr = NULL;
	strncpy(db_file->file_name, db_file_name, 512);
	return db_file;
}
