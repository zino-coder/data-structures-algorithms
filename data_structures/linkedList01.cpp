#include <iostream>

// Struct node của linked list
struct Node {
    int data;
    Node *next;
};

// Set Node8 => node cho tiện dụng
typedef struct Node *node;

// Cấp phát node mới
node makeNode(int x) {
    node temp = new Node();
    temp->data = x;
    temp->next = nullptr;
    return temp;
}

// Kiểm tra xem node có rỗng không?
bool empty(node a) {
    return a == nullptr;
}

// Đếm số phần tử của Node
int size(node a) {
    int count = 0;
    while (a != nullptr) {
        // Gán địa chỉ tiếp theo của List cho a, node cuối sẽ có next = null
        a = a->next;
        count++;
    }

    return count;
}

// Thêm 1 phần tử vào đầu List
void insertFirst(node &a, int x) {
    node temp = makeNode(x);
    if (a == nullptr) {
        a = temp;
    } else {
        temp->next = a;
        a = temp;
    }
}

// Thêm 1 phần tử vào cuối List
void insertLast(node &a, int x) {
    node temp = makeNode(x);
    if (a == nullptr) {
        a = temp;
    } else {
        node p = a;
        while (p->next != nullptr) {
            p = p->next;
        }

        p->next = temp;
    }
}

// Thêm một phần tử vào giữa
void insertMiddle(node &a, int x, int pos) {
    int n = size(a);
    if (pos < 0 || pos > n) {
        std::cout << "Wrong position!" << std::endl;
        return;
    }

    if (n == 0) {
        insertFirst(a, x);
        return;
    }

    if (pos == n) {
        insertLast(a, x);
        return;
    }

    node p = a;
    for (int i = 0; i < pos - 1; i++) {
        p = p->next;
    }
    node temp = makeNode(x);
    temp->next = p->next;
    p->next = temp;
}

// Xoá phần tử ở đầu
void deleteFirst(node &a) {
    if (empty(a)) {
        std::cout << "Empty List!" << std::endl;
        return;
    }
    a = a->next;
}

// Xoá phần tử cuối
void deleteLast(node &a) {
    if (empty(a)) {
        std::cout << "Empty List!" << std::endl;
        return;
    }

    node prev = nullptr, next = a;
    while (next->next != nullptr) {
        prev = next;
        next = next->next;
    }

    if (prev == nullptr) {
        a = nullptr;
    } else {
        prev->next = nullptr;
    }
}

// Xoá ở giữa
void deleteMiddle(node &a, int pos) {
    int n = size(a);
    if (pos < 0 || pos > n) {
        std::cout << "Wrong position!" << std::endl;
    }

    node prev = nullptr, next = a;
    for (int i = 0; i < pos; i++) {
        prev = next;
        next = next->next;
    }
    if (prev == nullptr) {
        a = a->next;
    } else {
        prev->next = next->next;
    }
}

// Xuất list ra màn hình
void print(node a) {
    while (a != nullptr) {
        std::cout << a->data << " ";
        a = a->next;
    }
    std::cout << std::endl;
}

// Selection sort
void sort(const node &a) {
    for (node p = a; p->next != nullptr; p = p->next) {
        node min = p;
        for (node q = p->next; q != nullptr; q = q->next) {
            if (q->data < min->data) {
                min = q;
            }
        }

        const int tmp = min->data;
        min->data = p->data;
        p->data = tmp;
    }
}

int main(int argc, char *argv[]) {
    node head = nullptr;
    int x, pos;
    while (true) {
        int selection;
        std::cout << "===============================MENU================================" << std::endl;
        std::cout << "1. Insert at beginning" << std::endl;
        std::cout << "2. Insert at end" << std::endl;
        std::cout << "3. Insert middle" << std::endl;
        std::cout << "4. Delete at beginning" << std::endl;
        std::cout << "5. Delete at end" << std::endl;
        std::cout << "6. Delete middle" << std::endl;
        std::cout << "7. Print linked list to screen" << std::endl;
        std::cout << "8. Sort Linked list" << std::endl;
        std::cout << "9. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> selection;
        switch (selection) {
            case 1:
                std::cout << "Insert a number: ";
                std::cin >> x;
                insertFirst(head, x);
                break;
            case 2:
                std::cout << "Insert a number: ";
                std::cin >> x;
                insertLast(head, x);
                break;
            case 3:
                std::cout << "Insert a number: ";
                std::cin >> x;
                std::cout << "Insert a positive number: ";
                std::cin >> pos;
                insertMiddle(head, x, pos);
                break;
            case 4:
                deleteFirst(head);
                break;
            case 5:
                deleteLast(head);
                break;
            case 6:
                std::cout << "Choose a position to delete: ";
                std::cin >> pos;
                deleteMiddle(head, pos);
                break;
            case 7:
                print(head);
                break;
            case 8:
                sort(head);
                break;
            case 9:
                exit(0);
            default:
                std::cout << "Wrong choice!" << std::endl;
                break;
        }
    }
}
