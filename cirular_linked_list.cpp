#include <iostream>

#define DEFAULT_DATA_TYPE char
#define DEFAULT_VALUE 'A'
namespace circular_space {
	struct Node {
		Node *prev;
		Node *next;
		DEFAULT_DATA_TYPE value;
	};

	class circular_linked_list {
	public:
		Node *head;
		circular_linked_list() {
			Node *tmp;
			head = new Node();
			tmp = new Node();

			head->value = DEFAULT_VALUE;
			tmp->value = DEFAULT_VALUE;

			head->next = tmp;
			head->prev = tmp;

			tmp->next = head;
			tmp->prev = head;


			
		}


		void print_values() {
			Node *point;
			point = head;
			while (point != head->prev) {
				std::cout << point->value << '\t';
				point = point->next;
			}
			std::cout << point->value << std::endl;
		}
		void push_node(DEFAULT_DATA_TYPE value) {
			Node *tmp,*prev;
			tmp = new Node();
			tmp->value = value;

			prev = head->prev;
			prev->next = tmp;

			tmp->prev = prev;
			tmp->next = head;

			head->prev = tmp;
		}
	};
}

using namespace circular_space;

int main() {
	int tmp;
	circular_linked_list *list = new circular_linked_list();
	list->print_values();
	list->push_node('B');
	list->print_values();

	std::cin >> tmp;
}