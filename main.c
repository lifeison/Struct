#include "iostream.h"
#include "stack.h"
#include "stackdbio.h"
#include "malloc.h"

using namespace std;
const char *db_file_name = "stack_db_file.bin\0";

int main(int argc, char **argv) {

	DBFile* db = initialize(db_file_name);
	struct elem
	{
		int num;
		elem *prev;
	};

	void push(int, elem **);
	int pop(elem **);
	void output(elem *);

}
	{
		const int N = 10;
		elem *top(NULL);

		for (int i = 0; i < N; i++){
			push(i, &top);
		}

		//output(top);

		for (int i = 0; i<N; ++i){
			cout << pop(&top);
		}

		//output(top);

		system("pause");
		return 0;
	}

	void push(int num, elem **top)
	{
		elem *curr = new elem;
		curr->num = num;
		if (*top == NULL){
			curr->prev = NULL;
		}
		else{
			curr->prev = *top;
		}

		*top = curr;
	}

	int pop(elem **top)
	{
		int tmp = (**top).num;

		if (*top == NULL)
			return -1;
		elem *tmp_top = *top;
		*top = (**top).prev;
		delete tmp_top;
		return tmp;
	}

	void output(elem *top)
	{
		while (top != NULL)
		{
			cout << top->num;
			top = top->prev;
		}
	}
	node *test_data = generate_test_data();
	open_db(db);
	save_node_to_db(db,test_data);
	close_db(db);

	open_db(db);
	node *new_test_data = (node*)malloc(sizeof(node));
	read_from_db(db, new_test_data);
	close_db(db);
	delete_test_data(test_data);
	free_db(db);
	
}