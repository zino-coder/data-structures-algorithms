// You are given the heads of two sorted linked lists list1 and list2.
// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.
// Return the head of the merged linked list.

#include <bits/stdc++.h>

struct Node {
    int data;
    Node *next;

    explicit Node(const int val) : data(val), next(nullptr) {
    }
};

typedef struct Node *node;

void push(node &head, int x) {
    node temp = new Node(x);

    if (head == nullptr) head = temp;
    else {
        node index = head;
        while (index->next != nullptr) {
            index = index->next;
        }

        index->next = temp;
    }
}

void print(node head) {
    while (head != nullptr) {
        std::cout << std::setw(3) << head->data;
        head = head->next;
    }

    std::cout << std::endl;
}

node mergeTwoSortedLists(node a, node b) {
    Node dummy(0);
    node tail = &dummy;

    while (a != nullptr && b != nullptr) {
        if (a->data < b->data) {
            tail->next = a;
            a = a->next;
        } else {
            tail->next = b;
            b = b->next;
        }

        tail = tail->next;
    }

    // Noi phan con lai
    tail->next = (a ? a : b);

    return dummy.next;
}

int main(int argc, char *argv[]) {
    node head1 = nullptr, head2 = nullptr;
    int x;

    while (true) {
        int selection;
        std::cout << "===============================MENU================================" << std::endl;
        std::cout << "1. Insert number to list 01" << std::endl;
        std::cout << "2. Insert number to list 02" << std::endl;
        std::cout << "3. Show lists" << std::endl;
        std::cout << "4. Merge 2 lists and show" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> selection;

        std::cout << "=============================================" << std::endl;
        switch (selection) {
            case 1:
                std::cout << "Insert a number: ";
                std::cin >> x;
                push(head1, x);
                break;
            case 2:
                std::cout << "Insert a number: ";
                std::cin >> x;
                push(head2, x);
                break;
            case 3:
                std::cout << "List 01: ";
                print(head1);
                std::cout << "List 02: ";
                print(head2);
                break;
            case 4:
                print(mergeTwoSortedLists(head1, head2));
                exit(0);
                break;
            case 5:
                exit(0);
                break;
            default:
                std::cout << "Invalid choice." << std::endl;
                break;
        }
    }
}
