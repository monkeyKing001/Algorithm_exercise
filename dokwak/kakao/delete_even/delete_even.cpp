#include <bits/stdc++.h>
#include <type_traits>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);

class SinglyLinkedListNode {
    public:
        int data;
        SinglyLinkedListNode *next;

        SinglyLinkedListNode(int node_data) {
            this->data = node_data;
            this->next = nullptr;
        }
};

class SinglyLinkedList {
    public:
        SinglyLinkedListNode *head;
        SinglyLinkedListNode *tail;

        SinglyLinkedList() {
            this->head = nullptr;
            this->tail = nullptr;
        }

        void insert_node(int node_data) {
            SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

            if (!this->head) {
                this->head = node;
            } else {
                this->tail->next = node;
            }

            this->tail = node;
        }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}



/*
 * Complete the 'deleteEven' function below.
 *
 * The function is expected to return an INTEGER_SINGLY_LINKED_LIST.
 * The function accepts INTEGER_SINGLY_LINKED_LIST listHead as parameter.
 */

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

SinglyLinkedListNode* deleteEven(SinglyLinkedListNode* listHead) {
	int i = 0;
    SinglyLinkedListNode *temp_head = listHead;
    SinglyLinkedListNode *prev_head = listHead;
    while (temp_head != nullptr)
    {
		if (i % 2 == 0 && temp_head -> next != nullptr)
		{
			temp_head -> next = temp_head -> next -> next;
			delete (temp_head -> next);
			i++;
		}
		i++;
		temp_head = temp_head -> next;
    }
    return (listHead);
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    SinglyLinkedList* listHead = new SinglyLinkedList();

    string listHead_count_temp;
    getline(cin, listHead_count_temp);

    int listHead_count = stoi(ltrim(rtrim(listHead_count_temp)));

    for (int i = 0; i < listHead_count; i++) {
        string listHead_item_temp;
        getline(cin, listHead_item_temp);

        int listHead_item = stoi(ltrim(rtrim(listHead_item_temp)));

        listHead->insert_node(listHead_item);
    }

    SinglyLinkedListNode* result = deleteEven(listHead->head);

    print_singly_linked_list(result, "\n", fout);
    fout << "\n";

    fout.close();

    return 0;
}

string ltrim(const string &str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string &str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

