#include <bits/stdc++.h>
using namespace std;
struct Student {
    int id;
    string name;
    int born;
    float gpa;
};

struct Node {
    Student data;
    Node *next;
};

typedef Node* node;

Student inputSingleStudent() {
    Student student;
    cout << "Nhap id hoc sinh: ";
    cin >> student.id;
    cout << "Nhap name hoc sinh: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, student.name);
    cout << "Nhap born hoc sinh: ";
    cin >> student.born;
    cout << "Nhap gpa hoc sinh: ";
    cin >> student.gpa;
    cout << "Nhap thong tin sinh vien " << student.name << " hoan tat!" << endl;
    return student;
}

node createNode(const Student &student) {
    const auto p = new Node;
    p->data = student;
    p->next = nullptr;

    return p;
}

void pushBack(node &head, const Student &student) {
    node p = createNode(student);
    if (head == nullptr) {
        head = p;
    } else {
        node ref = head;
        while (ref->next != nullptr) {
            ref = ref->next;
        }

        ref->next = p;
    }
}

void printLine() {
    cout << "+"
    << string(15, '-') << "+"
    << string(30, '-') << "+"
    << string(10, '-') << "+"
    << string(6, '-') << "+"
    << endl;
}
void printHeaderSql() {
    printLine();
    cout << "|"
    << setw(15) << "Ma sinh vien   " << "|"
    << setw(30) << "Ten sinh vien   " << "|"
    << setw(10) << "nam sinh " << "|"
    << setw(6) << "GPA  " << "|"
    << endl;
    printLine();
}

void printStudent(Student student) {
    cout << "|"
    << right <<setw(15) << student.id << "|"
        << left << setw(30) << student.name << "|"
        << right << setw(10) << student.born << "|"
        << right << setw(6) << student.gpa << "|"
        << endl;
    printLine();
}
void showList (const node head) {
    printHeaderSql();
    for (node p = head; p != nullptr; p = p->next) {
        printStudent(p->data);
    }
}

void menu() {
    cout << endl << "========== MENU QUAN LY SINH VIEN ==========" << endl;
    cout << "1. Nhap danh sach tai nghe" << endl;
    cout << "2. In danh sach tai nghe" << endl;
    cout << "3. Tim kiem tai nghe theo ten" << endl;
    cout << "4. Sap xep danh sach theo don gia tang dan (Merge Sort - de quy)" << endl;
    cout << "5. Tinh tong tien cac tai nghe" << endl;
    cout << "6. Hien thi ten tai nghe co don gia > 250000" << endl;
    cout << "7. Thong tin tai nghe co don gia cao nhat" << endl;
    cout << "0. Thoat" << endl;
    cout << "99. Nhap demo data cho nhanh" << endl;
    cout << "==========================================" << endl;
    cout << "Nhap lua chon: ";
}

int main() {
    node head = nullptr;
    int choice;
    do {
        menu();
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            choice = -1;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        switch (choice) {
            case 1: {
                Student student = inputSingleStudent();
                pushBack(head, student);
                cout << "Nhap danh sach thanh cong!" << endl;
                break;
            }
            case 2: {
                cout << endl << "--- DANH SACH TAI NGHE ---" << endl;
                showList(head);
                break;
            }
            case 3: {
                string ten;
                cout << "Nhap ten tai nghe can tim: ";
                getline(cin, ten);
                cout << endl << "--- KET QUA TIM KIEM ---" << endl;
                break;
            }
            case 4: {
                cout << "Da sap xep tang dan theo don gia (Merge Sort - de quy)!" << endl;
                break;
            }
            default:
                cout << "Lua chon khong hop le!" << endl;
        }
    } while (choice != 0);
    return 0;
}