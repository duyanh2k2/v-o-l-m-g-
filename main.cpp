#include <bits\stdc++.h>
#include "HoaDon.cpp"
using namespace std;
int main()

{
	ListNV Q;
	inList(Q);
	DList LHD;
	inDList(LHD);
	FILE *f;
	f=new FILE;
	FILE *fD;
	fD=new FILE;
	int chon;
	label73:
	do
	{
		cout<<"\n----cong ty san xuat vat tu------";
		cout<<"\n 1. Quan ly nhan vien";
		cout<<"\n 2. Quan ly hoa don ban vat tu";
		cout<<"\n 3. thoat chuong trinh";
		cout<<"\n moi ban chon: "; cin>>chon;
		switch(chon)
		{
			case 1:{
	
	int chonNV;
	do{
		cout<<"\n-----Quan ly nhan vien-----";
		cout<<"\n 1.nhap danh sach nhan vien";
		cout<<"\n 2.xuat danh sach nhan vien";
		cout<<"\n 3.luu danh sach vao file";
		cout<<"\n 4.doc danh sach tu file";
		cout<<"\n 5.sua ten nhan vien";
		cout<<"\n 6.xoa nhan vien theo ma";
		cout<<"\n 7.tim kiem nhan vien theo ma";
		cout<<"\n 8.tim kiem nhan vien theo ten";
		cout<<"\n 9.sap xep theo luong nhan vien";
		cout<<"\n 10.sap xep theo ten nhan vien";
		cout<<"\n 11.tim kiem nhan vien co luong nho nhat";
		cout<<"\n 12.tim kiem nhan vien co luong lon nhat";
		cout<<"\n 13.tinh tong toan bo luong cua nhan vien";
		cout<<"\n 14.dem so luong nhan vien theo luong";
		cout<<"\n 15.liet ke nhan vien theo luong";
		cout<<"\n 0.thoat quan ly nhan vien";
		cout<<"\n moi ban chon: "; cin>>chonNV;
		switch(chonNV)
		{
			case 1: nhapdsNV(Q);break;
			case 2: xuatdsNV(Q); break;
			case 3: luuFile(f,Q); break;
			case 4: 
			{
				DocFile(f,Q);
				xuatdsNV(Q);
			} break;
			case 5: 
				{
					int ma;
					cout<<"nhap ma nhan vien can sua: ";
					cin>>ma;
					suaNVhotenNV(Q,ma);
				}break;
			case 6:
			{ 
				int ma;
				cout<<"nhap ma nhan vien can xoa: ";
				cin>>ma;
				xoaNV(Q,ma);
			}
			break;
			case 7: 
			{
				int ma;
				cout<<"nhap ma nhan vien can tim kiem: ";
				cin>>ma;
				nodeNV *p;
				p=timkiemtheoma(Q,ma);
				if(p!=NULL)
					xuatNV(p->info);
				else
					cout<<"\nkhong tim thay ma nhan vien";
			}
			break;
			case 8: 
			{
				char tenNV[30];
				cout<<"nhap ten nhan vien can tim kiem: ";
				cin>>tenNV;
				nodeNV *p;
				p=timkiemtheoten(Q,tenNV);
				if(p!=NULL)
					xuatNV(p->info);
				else
					cout<<"\nkhong tim thay ma nhan vien";
			}
			break;
			case 9:sapxepLuong(Q);break;
			case 10: sapxeptheoten(Q); break;
			case 11: timNVLNN(Q); break;
			case 12: timNVLLN(Q); break;
			case 13: 
			{
				long luongNV;
				luongNV=tinhtongluong(Q);
				cout<<"\n tong luong tat ca nhan vien la: "<<luongNV;
			}
			break;
			case 14: demNVtheoluong(Q); break;
			case 15: lietkeNV(Q); break;
			case 0: goto label73;break;
		}
	}while(chonNV!=0);
} break;
			case 2:
{
	int chonHD;
	do{
		cout<<"\n-----Quan ly hoa don ban vat tu-----";
		cout<<"\n 1.nhap danh sach Hoa don";
		cout<<"\n 2.xuat danh sach hoa don";
		cout<<"\n 3.luu danh sach vao file";
		cout<<"\n 4.doc danh sach tu file";
		cout<<"\n 5.sua ngay lap theo ma hoa don";
		cout<<"\n 6.xoa hoa don theo ma";
		cout<<"\n 7.tim kiem hoa don theo ma";
		cout<<"\n 8.sap xep tong tien tang dan";
		cout<<"\n 9.sap xep tong tien giam dan";
		cout<<"\n 10.tim kiem hoa don co tong tien nho nhat";
		cout<<"\n 11.tim kiem hoa don co tong tien lon nhat";
		cout<<"\n 12.tong tien cua tat ca hoa don";
		cout<<"\n 13.dem so luong hoa don";
		cout<<"\n 14.liet ke hoa don";
		cout<<"\n 15.tang gia 10% theo ten san pham";
		cout<<"\n 16.tim san pham trong khoang x y";
		cout<<"\n 0.thoat quan ly hoa don";
		cout<<"\n moi ban chon: "; cin>>chonHD;
		switch(chonHD)
		{
			case 1: nhapDSHD(LHD,Q);break;
			case 2: xuatDSHD(LHD); break;
			case 3: luuFileHD(fD,LHD); break;
			case 4: 
			{
				DocFileHD(fD,LHD);
				xuatDSHD(LHD);
			} break;
			case 5: 
				{
					int ma;
					cout<<"nhap ma hoa don can sua: ";
					cin>>ma;
					suangaylapHD(LHD,ma);
				}break;
			case 6:
			{ 
				int ma;
				cout<<"nhap ma hoa don can xoa: ";
				cin>>ma;
				xoahoadon(LHD,ma);
			}
			break;
			case 7: 
			{
				int ma;
				cout<<"nhap ma hoa don can tim kiem: ";
				cin>>ma;
				NodeHD *p;
				p=timkiemHDma(LHD,ma);
				if(p!=NULL)
					xuatHD(p->info);
				else
					cout<<"\nkhong tim thay ma nhan vien";
			}
			break;
			
			case 8:sxtanggiamtien(LHD);break;
			case 9: sxtangtongtien(LHD); break;
			case 10: timHDNN(LHD); break;
			case 11: timHDLN(LHD); break;
			case 12: 
			{
				long tongtienHD;
				tongtienHD=tongtienall(LHD);
				cout<<"\n tong tien tat ca hoa don la: "<<tongtienHD;
			}
			break;
			case 13: demHD(LHD); break;
			case 14: lietkeHDtheotien(LHD); break;
			case 15: 
			{
				char ten[30];
				cout<<"nhap ten vat tu de tang gia: ";
				cin>>ten;
				tanggia(LHD,ten);
			}
			break;
			case 16:
			{
				float x,y;
				cout<<"nhap x: "; cin>>x;
				cout<<"nhap y: "; cin>>y;
				timsp(LHD,x,y);
			}
			break;
			case 0: goto label73;break;
		}
	}while(chonHD!=0);
}break;

			case 3: exit(1);
		}
	}while(chon!=0);
	return 0;
}