#include <bits\stdc++.h>
#include <fstream>
using namespace std;
struct NhanVien
{
	int maNV;
	char name[30];
	char gt[10];
	char diachi[50];
	char ngaysinh[20];
	float hsl;
	long luong;
};
struct nodeNV{
	NhanVien info;
	struct nodeNV *next;
};
struct ListNV
{
	nodeNV *head;
	nodeNV *tail;
};
void inList(ListNV &Q)
{
	Q.head=Q.tail=NULL;
}

nodeNV *get_node(NhanVien x)
{
	nodeNV *p;
	p=new nodeNV;
	if(p==NULL){
		cout<<"khong du bo nho";
		return 0;
	}
	p->info=x;
	p->next=NULL;
	return p;
}
void insertLast(ListNV &Q, nodeNV *q){
	if (Q.head==NULL)
	{
		Q.head=q;
		Q.tail=Q.head;
	}
	else{
		Q.tail->next=q;
		Q.tail=q;
	}
}
void nhapNV(NhanVien &x){
	cout<<"nhap ma nhan vien: ";cin>>x.maNV;
	fflush(stdin);
	cout<<"nhap ten nhan vien: "; cin>>x.name;
	fflush(stdin);
	cout<<"nhap gioi tinh: ";cin>>x.gt;
	fflush(stdin);
	cout<<"nhap dia chi: ";cin>>x.diachi;
	fflush(stdin);
	cout<<"nhap ngay sinh: ";cin>>x.ngaysinh;
	cout<<"nhap he so luong: ";cin>>x.hsl;
	x.luong=x.hsl*1000;
}
void nhapdsNV(ListNV &Q){
	int n;
	nodeNV *p;
	NhanVien x;
	cout<<"nhap so luong nhan vien: "; cin>>n;
	for(int i=0;i<n;i++){
		nhapNV(x);
		p=get_node(x);
		insertLast(Q,p);
	}
}
void xuatNV(NhanVien &x){
	cout<<setw(10)<<x.maNV;
	cout<<setw(15)<<x.name;
	cout<<setw(10)<<x.gt;
	cout<<setw(15)<<x.diachi;
	cout<<setw(14)<<x.ngaysinh;
	cout<<setw(10)<<x.hsl;
	cout<<setw(10)<<x.luong<<endl;
}
void xuatdsNV(ListNV &Q){
	nodeNV *p;
	cout<<"danh sach vua nhap la: "<<endl;
	for(p=Q.head;p!=NULL;p=p->next){
		xuatNV(p->info);
	}
}

void suaNVhotenNV(ListNV &Q, int ma)
{
	char hoten[30];
	cout<<"nhap ho ten nhan vien: "; cin>>hoten;
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.maNV==ma){
			strcpy(p->info.name,hoten);
		}
	}
}

int xoaNV(ListNV &Q, int mnv){
	nodeNV *p=Q.head;
	nodeNV *q=NULL;
	while(p!=NULL){
		if(p->info.maNV==mnv) break;
		q=p;
		p=p->next;
	}
	if(p==NULL) return 0;
	if(q!=NULL){
		if(q==Q.tail) Q.tail=q;
		q->next=p->next;
		delete(p);
	}else{
		Q.head=p->next;
		if(Q.head==NULL) Q.tail=NULL;
	}
	return 1;
}
nodeNV *timkiemtheoma(ListNV &Q, int k){
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.maNV==k) break;
	}
	return p;
}
nodeNV *timkiemtheoten(ListNV &Q, char ten[30]){
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next){
		if(strcmp(p->info.name,ten)==0) break;
	}
	return p;
}
void sapxepLuong(ListNV &Q){
	NhanVien tg;
	nodeNV *p,*q;
	for(p=Q.head;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(p->info.luong<q->info.luong){
				tg=p->info;
				p->info=q->info;
				q->info=tg;
			}
}
void sapxeptheoten(ListNV &Q){
	NhanVien tg;
	nodeNV *p,*q;
	for (p=Q.head;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next){
			if(strcmp(p->info.name,q->info.name)>0){
				tg=p->info;
				p->info=q->info;
				q->info=tg;
			}
		}
	
}
void timNVLNN(ListNV Q){
	nodeNV* p;
	long min;
	min=Q.head->info.luong;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong<min){
			min=p->info.luong;
		}
	}
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong==min){
			break;
		}
	}
	cout<<"\nnhan vien co luong nho nhat: "<<endl;
	xuatNV(p->info);
}
void timNVLLN(ListNV Q){
	nodeNV* p;
	long max;
	max=Q.head->info.luong;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong>max){
			max=p->info.luong;
		}
	}
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong==max){
			break;
		}
	}
	cout<<"\nnhan vien co luong lon nhat: "<<endl;
	xuatNV(p->info);
}
long tinhtongluong(ListNV &Q){
	nodeNV *p;
	long tongluong;
	tongluong=0;
	for(p=Q.head;p!=NULL;p=p->next)
	{
		tongluong+=p->info.luong;
	}
	return tongluong;
}
void demNVtheoluong(ListNV Q){
	long luongct;
	cout<<"nhap luong de lam moc dem so luong: ";
	cin>>luongct;
	int dem=0;
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong>luongct)
			dem++;
	}
	cout<<"so luong nhan vien co luong > hon luong vua nhap: "<<dem<<endl;
}
void lietkeNV(ListNV &Q){
	long luongct;
	cout<<"nhap luong : ";cin>>luongct;
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next){
		if(p->info.luong>luongct){
			xuatNV(p->info);
		}
	}
}
void luuFile(FILE *f,ListNV &Q)
{
	f= fopen("nhanvien.dat","wb");
	int n=0;
	nodeNV *p;
	for(p=Q.head;p!=NULL;p=p->next)
 	{
 		n+=1;
	 }
	 fwrite(&n,sizeof(int),1,f);
	for(p=Q.head;p!=NULL;p=p->next)
 	{
 		fwrite(&p->info,sizeof(NhanVien),1,f);
	 }
	 fclose(f);	
	 cout<<"luu file thanh cong";	
}
void DocFile(FILE *f,ListNV &Q)
{
	int n;
	nodeNV *p;
	NhanVien x;
	inList(Q);
	f= fopen("nhanvien.dat","rb");
	fread(&n,sizeof(int),1,f);
	for(int i=0;i<n;i++)
 	{
 		fread((char*)&x, sizeof(NhanVien), 1, f);
		 p=get_node(x);
	     insertLast(Q,p);		 	
	 }
	 fclose(f);	
}
