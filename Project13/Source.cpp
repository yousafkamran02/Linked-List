#include <iostream>
using namespace std;
class link_list
{
public:
	int data;
	link_list* next;
};
void menu()
{
	for (int i = 0; i < 35; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout<<"\t\tMENU"<<endl;
	for (int i = 0; i < 35; i++)
	{
		cout << "_";
	}
	cout << endl;
	cout << "1.Insert node in the beginning" << endl;
	cout << "2.Insert node in the middle" << endl;
	cout << "3.Insert node in the end" << endl;
	for (int i = 0; i < 35; i++)
	{
		cout << "_";
	}
	cout << endl;
}
void start(link_list**head_ref,int new_data)
{
	link_list* new_node = new link_list();
	new_node->data=new_data;
	new_node->next = (*head_ref);
	*head_ref = new_node;
}
void middle(link_list* previous_node, int new_data)
{
	if (previous_node == NULL)
	{
		cout << "Cannot enter value" << endl;
	}
	link_list* new_node = new link_list();
	new_node->data = new_data;
	new_node->next=previous_node->next;
	previous_node->next = new_node;
}
void end(link_list** head_ref, int new_data)
{
	link_list* new_node = new link_list();
	link_list*last_node = *head_ref;
	new_node->data = new_data;
	new_node->next=NULL;
	while (last_node->next != NULL)
	{
		last_node = last_node->next;
	}
	last_node->next = new_node;
}
void print_list(link_list*temp)
{
	int i = 1;
	cout << "Values entered in the link list are:" << endl;
	while (temp != NULL)
	{
		
		cout<<i<<" Value is ="<<temp->data;
		temp= temp->next;
		i++;
		cout << endl;
	}
}
int main()
{
	int option, new_entry;
	link_list* head = NULL;
	head = new link_list();
	cout << "Enter values in link list" << endl;
	cout << "First value=";
	cin>>head->data;
	head->next=NULL;
	cout << endl;
	do {
		print_list(head);
		system("pause");
		system("CLS");
		print_list(head);
		menu();

		cout << "Enter option:";
		cin >> option;
		for (int i = 0; i < 35; i++)
		{
			cout << "_";
		}
		cout << endl;
		if (option == 1)
		{

			system("CLS");
			cout << "\t\t\tEnter node at start" << endl;
			cout << "Enter value of the new node:";
			cin >> new_entry;
			cout << endl;
			cout << "Privous link list" << endl;
			print_list(head);
			start(&head, new_entry);
			cout << "New link list" << endl;
			print_list(head);
		}
		else if (option == 2)
		{
			system("CLS");
			cout << "\t\t\tEnter node at middle" << endl;
			cout << "Enter value of new node:";
			cin >> new_entry;
			print_list(head);
			cout << "NEW link list" << endl;
			middle(head, new_entry);
			print_list(head);
		}
		else if (option == 3)
		{
			system("CLS");
			cout << "\t\t\tEnter node at end" << endl;
			cout << "Enter value of new node:";
			cin >> new_entry;
			cout << endl;
			cout << "Privous link list" << endl;
			print_list(head);
			end(&head, new_entry);
			cout << "New link list" << endl;
			print_list(head);
		}
	} while (true);
	return 0;
}