#include <bits/stdc++.h>

using namespace std;

struct SINHVIEN {
    char hoten[25];
    char gioitinh[5];
    float dtk;
};

struct Node {
    SINHVIEN infor;
    Node* next;
};

typedef Node* TRO;
TRO L;

void rong(TRO& L) {
    L = NULL;
}

int checkrong(TRO L) {
    return (L == NULL);
}

void nhaptt(SINHVIEN& sv) {
    cout << "Nhap ho ten: "; fflush(stdin);
    gets(sv.hoten);
    if (strcmp(sv.hoten, "*") == 0)
        return;
    cout << "Nhap gioi tinh: "; fflush(stdin);
    gets(sv.gioitinh);
    cout << "Nhap diem: ";
    cin >> sv.dtk;
}

void nhapds(TRO& L) {
    rong(L);
    SINHVIEN X;
    TRO Q, P;
    int i = 1;
    do {
        cout << "\nNhap sinh vien thu " << i << endl;
        nhaptt(X);
        if (strcmp(X.hoten, "*") == 0)
            return;
        P = new (Node);
        P->infor = X;
        P->next = NULL;
        if (L == NULL)
            L = P;
        else
            Q->next = P;
        Q = P;
        i++;
    } while (1);
}

void xuatds(TRO L) {
    if (L == NULL) {
        cout << "DANH SACH RONG" << endl;
        return;
    }
    TRO Q = L;
    int i = 0;
    while (Q != NULL) {
        SINHVIEN X = Q->infor;
        cout<<"SV :"<< (i + 1)<< endl;
        cout<<"Ten " <<X.hoten<< endl;
        cout<<"Gioi tinh " <<X.gioitinh<< endl;
        cout<<"Diem "<<X.dtk << endl;
        Q = Q->next;
        i++;
    }
}
void hienThiDiemDuoi10(TRO L) {
    if (L == NULL) {
        cout << "DANH SACH RONG" << endl;
        return;
    }
    TRO Q = L;
    int i=0;
    while (Q != NULL) {
        SINHVIEN X = Q->infor;
        if (strcmp(X.gioitinh,"nu")==0) {
            cout << "SV :" << (i + 1) << endl;
            cout << "Ten: " << X.hoten << endl;
            cout << "Gioi tinh: " << X.gioitinh << endl;
            cout << "Diem: " << X.dtk << endl;
        }
        Q = Q->next;
        i++;
    }
}
void hienThiDiemNhoNhat(TRO L) {
    if (L == NULL) {
        cout << "DANH SACH RONG" << endl;
        return;
    }
    TRO Q = L;
    TRO T = L;
    while (Q != NULL) {
        if (Q->infor.dtk < T->infor.dtk) {
            T = Q;
        }
        Q = Q->next;
    }
    SINHVIEN X = T->infor;
    cout << "Sinh vien co diem nho nhat:" << endl;
    cout << "Ten: " << X.hoten << endl;
    cout << "Gioi tinh: " << X.gioitinh << endl;
    cout << "Diem: " << X.dtk << endl;
}

void xoa(TRO&L,TRO Q) {
    char ten[25];
    cout << "\nNhap ten sinh vien can tim: ";
    fflush(stdin);
    gets(ten);
    Q=L;
    TRO T;
    while(Q!=NULL&&strcmp(Q->infor.hoten,ten)!=0)
    {
        T=Q;
        Q=Q->next;
    }
    if (Q == NULL) {
        cout << "\nKHONG CO SINH VIEN TRONG DANH SACH" << endl;
        return;
    }
    SINHVIEN X = Q->infor;
    cout << "TIM THAY SINH VIEN. THONG TIN LA: " << endl;
    cout << "HO TEN: " << X.hoten;
    cout << "\nGIOI TINH: " << X.gioitinh;
    cout << "\nDIEM TONG KET: " << X.dtk << endl;
    T->next=Q->next;
    delete Q;
    cout<<"\nDANH SACH SAU KHI XOA: "<<endl;
    xuatds(L);
}

void chen(TRO& L,TRO Q, SINHVIEN X) {
    nhaptt(X);
    Q=L;
    int d=1;
    while(Q!=NULL&&d<3)
    {
        Q=Q->next;
        d++;
    }
    if(d==3&&Q!=NULL)
    {
    TRO P;
    P=new Node;
    P->infor=X;
    P->next=Q->next;
    Q->next=P;
    }
    else
    {
        cout<<"Khong chen duoc vi ds be hon 3 phan tu";
    }
}
int main()
{
    TRO L,Q;
    cout<<"NHAP DANH SACH SINH VIEN: "<<endl;
    nhapds(L);
    cout<<"\nDANH SACH VUA NHAP: "<<endl;
    xuatds(L);
    xoa(L,Q);
    SINHVIEN X;
    cout << "\nNhap thong tin sinh vien moi de chen vao sau sinh vien thu 3:" << endl;
    chen(L,Q,X);
    cout<<"\nDANH SACH SINH VIEN: "<<endl;
    xuatds(L);
    cout<<"\nYC"<<endl;
    hienThiDiemDuoi10(L);
    cout<<"\nYC"<<endl;
    hienThiDiemNhoNhat(L);
}
