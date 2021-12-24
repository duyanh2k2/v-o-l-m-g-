#include <bits\stdc++.h>
using namespace std;

struct VatTu
{
	int maVT;
	char tenVT[30];
	float dongia;
	float soluong;
	char donvitinh[10];
	float thanhTien;
};

void nhapVT(VatTu &x){
	cout<<"nhap ma vat tu: ";cin>>x.maVT;
	fflush(stdin);
	cout<<"nhap ten vat tu: "; cin>>x.tenVT;
	cout<<"nhap don gia: "; cin>>x.dongia;
	cout<<"nhap so luong: "; cin>>x.soluong;
	fflush(stdin);
	cout<<"nhap don vi tinh: "; cin>>x.donvitinh;
	x.thanhTien=x.dongia*x.soluong;
}
void xuatVT( VatTu &x){
	cout<<setw(10)<<x.maVT;
	cout<<setw(15)<<x.tenVT;
	cout<<setw(10)<<x.dongia;
	cout<<setw(10)<<x.soluong;
	cout<<setw(10)<<x.donvitinh;
	cout<<setw(10)<<x.thanhTien<<"\n";
}
