#include <iostream>
using namespace std;

class DonThuc {
private:
    float heSo;
    int soMu;
public:
    void input();
    void output();
    float getHeSo() { return heSo; }
    int getSoMu() { return soMu; }
    void copy(DonThuc x);
    void setHeSo(float x);
    void setSoMu(int x);
    float value(float x);
    int compare(DonThuc x);
};

struct Node {
    DonThuc value;
    Node* pNext;
};

struct List {
    Node* pHead, * pTail;
};

Node* getNode(DonThuc x) {
    Node* p = new Node;
    p->value.copy(x);
    p->pNext = nullptr;

    return p;
}
void addHead(List& l, DonThuc x) {
    Node* p = getNode(x);
    if (l.pHead == nullptr) l.pHead = l.pTail = p;
    else {
        p->pNext = l.pHead;
        l.pHead = p;
    }
}
void addTail(List& l, DonThuc x) {
    Node* p = getNode(x);
    if (l.pHead == nullptr) l.pHead = l.pTail = p;
    else {
        l.pTail->pNext = p;
        l.pTail = p;
    }
}
void printList(List l) {
    Node* p = l.pHead;
    while (p != nullptr) {
        if (p->value.getHeSo() < 0) cout << " - ";
        else {
            if (p != l.pHead) cout << " + ";
        }
        p->value.output();
        p = p->pNext;
    }

}
void input(List& l) {
    int n;
    cout << "\nNhap so luong don thuc trong da thuc: "; cin >> n;
    DonThuc x;
    for (int i = 0; i < n; ++i) {
        x.input();
        addTail(l, x);
    }
}
float value(List l, float x) {
    float sum = 0;
    Node* p = l.pHead;
    while (p != nullptr) {
        sum += p->value.value(x);
        p = p->pNext;
    }
    return sum;
}

int compare(List l1, List l2) {
    Node* p1 = l1.pHead;
    Node* p2 = l2.pHead;
    while (p1 != nullptr && p2 != nullptr) {
        if (p1->value.getSoMu() > p2->value.getSoMu()) return 1;
        if (p1->value.getSoMu() < p2->value.getSoMu()) return -1;
        if (p1->value.getSoMu() == p2->value.getSoMu()) {
            if (p1->value.getHeSo() > p2->value.getHeSo()) return 1;
            if (p1->value.getHeSo() < p2->value.getHeSo()) return 0;
            return 0;
        }
    }
}
void DonThuc::input() {
    cout << "Nhap ax^b: "; cin >> heSo >> soMu;
}
void DonThuc::output() {

    if (heSo != 1) cout << heSo;
    if (heSo != 0) {
        if (soMu == 1) cout << "x";
        else if (soMu > 1) cout << "x^" << soMu;
    }
}
void DonThuc::copy(DonThuc x) {
    heSo = x.heSo;
    soMu = x.soMu;
}
void DonThuc::setHeSo(float x) {
    heSo = x;
}
void DonThuc::setSoMu(int x) {
    soMu = x;
}

float DonThuc::value(float x) {
    if (soMu == 0) return heSo;
    for (int i = 1; i < soMu; ++i)
        x *= x;
    return heSo * x;
}

int DonThuc::compare(DonThuc x) {
    if (heSo > x.heSo) return 1;
    if (heSo == x.heSo) return 0;
    return -1;
}

int main() {
    DonThuc n1, n2;
    List DaThuc1, DaThuc2;
    DaThuc1.pHead = DaThuc1.pTail = nullptr;
    DaThuc2.pHead = DaThuc1.pTail = nullptr;
    cout << "Nhap da thuc theo so mu giam dan\n";
    input(DaThuc1);

    float x; cout << "Nhap x: "; cin >> x;
    cout << "Gia tri da thuc tai f(" << x << ") = " << value(DaThuc1, x);
    input(DaThuc2);

    cout << '\n';
    switch (compare(DaThuc1, DaThuc2)) {
    case -1:
        cout << "Da thuc 1 lon hon da thuc 2";
        break;
    case 0:
        cout << "Hai da thuc bang nhau";
        break;
    case 1:
        cout << "Da thuc 1 nho hon da thuc 2";
        break;
    }
    return 0;
}