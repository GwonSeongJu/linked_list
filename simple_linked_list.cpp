#include <iostream>

#define VALUE_DATA_TYPE char
#define DEFAULT_VALUE 'A'


namespace simple_linked_list_space {
	struct Node{
		Node *prev;
	    Node *next;
		VALUE_DATA_TYPE value;
	};

	class simple_linked_list {
	public:
		Node *head, *tail, *point;
		simple_linked_list(void){
			head = new Node();
			tail = new Node();
			head->prev = 0;
			head->next = tail;
			head->value = DEFAULT_VALUE;
			tail->prev = head;
			tail->next = 0;
			tail->value = DEFAULT_VALUE;
		}

		void print_values() {
			point = head;
			do{
				std::cout << point->value << '\t';
				point = point->next;
			} while (point != tail);
			std::cout << point->value << std::endl;
		}

		void push_node(VALUE_DATA_TYPE value) {
			Node *tmp;
			tmp = new Node();
			tmp->value = value;
			tail->next = tmp;
			tmp->prev = tail;
			tail = tmp;
		}
		
		VALUE_DATA_TYPE pop_node() {
			Node *tmp;
			VALUE_DATA_TYPE tmp_Value;
			tmp = tail->prev;
			tmp_Value = tail->value;
			delete(tail);
			tail = tmp;
			tail->next = 0;
			return tmp_Value;
		}
	};
}

using namespace simple_linked_list_space;
/*
int main() {
	int tmp;
	simple_linked_list *test = new simple_linked_list();
	
	test->push_node('C');

	test->print_values();

	test->pop_node();

	test->print_values();
	std::cin >> tmp;
	return 1;
}
*/