/**
 * Mã Sinh viên: 25C1001S1465
 * Họ và tên: Nguễn Vũ Hiển
 * Lớp: CNT223
 * Môn kiểm tra: Cấu trúc dữ liệu & Giải thuật - Bài tập tự luận
 * Mã đề: Đề 01
 */

#include <bits/stdc++.h>
using namespace std;

struct TaiNghe {
    string MaTaiNghe;
    string TenTaiNghe;
    string NuocSX;
    long long DonGia;
    int SoLuong;

    [[nodiscard]] long long ThanhTien() const {
        return DonGia * 1LL * SoLuong;
    }
};

struct Node {
    TaiNghe data;
    Node* next;
};

struct List {
    Node* head;
    Node* tail;
};

typedef Node* node;

void initList(List &l) {
    l.head = l.tail = nullptr;
}

node createNode(const TaiNghe &taiNghe) {
    node p = new Node;
    p->data = taiNghe;
    p->next = nullptr;

    return p;
}

bool isEmpty(const List &l) {
    return l.head == nullptr;
}

void pushBack(List &l, const TaiNghe &taiNghe) {
    const node p = createNode(taiNghe);
    if (isEmpty(l)) {
        l.head = l.tail = p;
    } else {
        l.tail->next = p;
        l.tail = p;
    }
}

void clearList(List &l) {
    node p = l.head;
    while (p != nullptr) {
        node temp = p;
        p = p->next;
        delete temp;
    }

    l.head = l.tail = nullptr;
}

void updateTail(List &l) {
    l.tail = l.head;

    if (l.tail == nullptr) return;
    while (l.tail->next != nullptr) {
        l.tail = l.tail->next;
    }
}

void pressEnter() {
    cout << endl << "Nhan Enter de tiep tuc...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

//================MERGE SORT======================
void splitList(node source, node* front, node* back) {
    if (source == nullptr || source->next == nullptr) {
        *front = source;
        *back = nullptr;

        return;
    }

    node slow = source;
    node fast = source->next;

    while (fast != nullptr) {
        fast = fast->next;
        if (fast != nullptr) {
            slow = slow->next;
            fast = fast->next;
        }
    }

    *front = source;
    *back = slow->next;
    slow->next = nullptr;
}

node merge(node a, node b) {
    if (a == nullptr) return b;
    if (b == nullptr) return a;

     node result = nullptr;

    if (a->data.DonGia <= b->data.DonGia) {
        result = a;
        result->next = merge(a->next, b);
    } else {
        result = b;
        result->next = merge(a, b->next);
    }

    return result;
}

void mergeSort(node* head) {
    const node h = *head;
    if (h == nullptr || h->next == nullptr) return;

    node a = nullptr;
    node b = nullptr;

    splitList(h, &a, &b);
    mergeSort(&a);
    mergeSort(&b);
    *head = merge(a, b);
}

//================================================================
TaiNghe inputSingleHeadphone() {
    TaiNghe t;
    cout << "Nhap ma tai nghe: " << endl;
    getline(cin, t.MaTaiNghe);
    cout << "Nhap ten tai nghe: " << endl;
    getline(cin, t.TenTaiNghe);
    cout << "Nhap ten nuco san xuat: " << endl;
    getline(cin, t.NuocSX);
    cout << "Nhap Don gia: ";
    while (!(cin >> t.DonGia) || t.DonGia < 0) {
        cout << "Don gia khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << "Nhap So luong: ";
    while (!(cin >> t.SoLuong) || t.SoLuong < 0) {
        cout << "So luong khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // clear endline
    return t;
}

void inputList(List &l) {
    int n;
    cout << "Nhap so luong tai nghe: ";
    while (!(cin >> n) || n < 0) {
        cout << "So luong khong hop le. Nhap lai: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int i = 0; i < n; i++) {
        cout << "- << endl-- Nhap tai nghe thu " << i + 1 << " ---" << endl;
        TaiNghe x = inputSingleHeadphone();
        pushBack(l, x);
    }
}

//=====================OUTPUT==================
void printLine() {
    cout << "+"
         << string(15, '-') << "+"
         << string(25, '-') << "+"
         << string(15, '-') << "+"
         << string(15, '-') << "+"
         << string(10, '-') << "+"
         << string(18, '-') << "+"
         << endl;
}

void printHeaderSQL() {
    printLine();
    cout << "|"
         << left  << setw(15) << "Ma TN"       << "|"
         << left  << setw(25) << "Ten Tai Nghe" << "|"
         << left  << setw(15) << "Nuoc san xuat"     << "|"
         << right << setw(15) << "Don gia"     << "|"
         << right << setw(10) << "SL"         << "|"
         << right << setw(18) << "Thanh Tien"  << "|"
         << endl;
    printLine();
}

void printOneSQL(const TaiNghe &x) {
    cout << "|"
         << left  << setw(15) << x.MaTaiNghe     << "|"
         << left  << setw(25) << x.TenTaiNghe    << "|"
         << left  << setw(15) << x.NuocSX        << "|"
         << right << setw(15) << x.DonGia        << "|"
         << right << setw(10) << x.SoLuong       << "|"
         << right << setw(18) << x.ThanhTien()   << "|"
         << endl;
}

void printListSQL(List &l) {
    if (isEmpty(l)) {
        cout << "Danh sach rong!" << endl;
        return;
    }

    printHeaderSQL();
    for (const Node* p = l.head; p != nullptr; p = p->next) {
        printOneSQL(p->data);
    }
    printLine();
}

// Yeu cau 3: Tim kiem!
void searchByName(List &l, const string &ten) {
    if (isEmpty(l)) {
        cout << "Danh sach rong!" << endl;

        return;
    }

    bool found = false;
    printHeaderSQL();
    for (const Node* p = l.head; p != nullptr; p = p->next) {
        if (p->data.TenTaiNghe == ten) {
            printOneSQL(p->data);
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay tai nghe co ten la: " << ten << endl;
    }
}

// Yeu cau 4: sap xep
    void sortByDonGia(List &l) {
    mergeSort(&l.head);
    updateTail(l);
}

// Yeu cau 5:
long long totalMoney(const List &l) {
    long long total = 0;
    for (node p = l.head; p != nullptr; p = p->next) {
        total += p->data.ThanhTien();
    }

    return total;
}

// Yeu cau 6: Tim tai nghe co down gia cao hon 250000
void getNameHeadphoneCondition(const List &l, long long price = 250000) {
    bool found = false;
    for (node p = l.head; p != nullptr; p = p->next) {
        if (p->data.DonGia > price) {
            cout << "- " << p->data.TenTaiNghe << " (" << p->data.DonGia << ")" << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Khong tim thay tai nghe nao co don gia cao hon " << price << endl;
    }
}

void getDetailHeadphoneMaxPrice(const List &l) {
    if (isEmpty(l)) {
        cout << "Danh sach rong!" << endl;

        return;
    }

    node maxNode = l.head;
    for (node p = l.head; p != nullptr; p = p->next) {
        if (p->data.DonGia > maxNode->data.DonGia) {
            maxNode = p;
        }
    }

    cout << "Tai nghe co don gia cao nhat la: " << endl;
    cout << "===============================================" << endl;
    printHeaderSQL();
    printOneSQL(maxNode->data);
}

// ================== MENU ==================
void menu() {
    cout << endl << "========== MENU QUAN LY TAI NGHE ==========" << endl;
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

// Demo data cho ez
void addDemoData(List &l) {
    clearList(l);

    TaiNghe demo[] = {
        {"TN01", "Sony WH-1000XM4",      "Japan",   7200000, 2},
        {"TN02", "Apple AirPods Pro 2",  "USA",     5900000, 3},
        {"TN03", "JBL Tune 510BT",       "USA",      950000, 5},
        {"TN04", "Razer BlackShark V2",  "USA",     2350000, 4},
        {"TN05", "Sennheiser HD 560S",   "Germany", 4300000, 1},
        {"TN06", "Xiaomi Redmi Buds 4",  "China",    790000, 6},
        {"TN07", "AKG K52",              "Austria",  620000,10},
        {"TN08", "HyperX Cloud II",      "USA",     1790000, 2}
    };

    for (const TaiNghe &x : demo) {   // foreach kiểu C++11
        pushBack(l, x);
    }

    cout << "Da nap demo data thanh cong!" << endl;
}

int main(int argc, char *argv[]) {
    List l{};
    initList(l);

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
                clearList(l);
                inputList(l);
                cout << "Nhap danh sach thanh cong!" << endl;
                pressEnter();
                break;
            }
            case 2: {
                cout << endl << "--- DANH SACH TAI NGHE ---" << endl;
                printListSQL(l);
                pressEnter();
                break;
            }
            case 3: {
                string ten;
                cout << "Nhap ten tai nghe can tim: ";
                getline(cin, ten);
                cout << endl << "--- KET QUA TIM KIEM ---" << endl;
                searchByName(l, ten);
                pressEnter();
                break;
            }
            case 4: {
                sortByDonGia(l);
                cout << "Da sap xep tang dan theo don gia (Merge Sort - de quy)!" << endl;
                pressEnter();
                break;
            }
            case 5: {
                cout << "Tong tien cac tai nghe: " << totalMoney(l) << " dong" << endl;
                pressEnter();
                break;
            }
            case 6: {
                constexpr int findingPrice = 250000;
                cout << "Cac tai nghe co don gia > 250000:" << endl;
                getNameHeadphoneCondition(l, findingPrice);
                pressEnter();
                break;
            }
            case 7: {
                getDetailHeadphoneMaxPrice(l);
                pressEnter();
                break;
            }
            case 0:
                cout << "Cam on ban da su dung ung dung! Hen gap lai!!." << endl;
                break;
            case 99:
                addDemoData(l);
                pressEnter();
                break;
            default:
                cout << "Lua chon khong hop le!" << endl;
                pressEnter();
        }
    } while (choice != 0);

    clearList(l);
    return 0;
}
