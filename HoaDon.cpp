#include <bits\stdc++.h>
#include "VatTu.cpp"
#include"NhanVien.cpp"
using namespace std;
struct HoaDon
{	
	int maHD;
	char NVlap[30];
	char ngaylap[20];
	int soluong;
	VatTu dsvt[30];
	long tongTien;
};
struct NodeHD
{
	HoaDon info;
	struct NodeHD* next;
	struct NodeHD* pre;
};
struct DList
{
	NodeHD* Head;
	NodeHD* Tail;
};
//nhap ten sp tang gia 10% cua sp co ten nhap vao
void tanggia(DList &LHD,char ten[30])
{
	NodeHD *p;
	for (p=LHD.Head;p!=NULL;p=p->next)
	{
		p->info.tongTien=0;
		for(int i=0;i<p->info.soluong;i++)
		{
			if(strcmp(p->info.dsvt[i].tenVT,ten)==0)
			{
				p->info.dsvt[i].dongia=(p->info.dsvt[i].dongia+(p->info.dsvt[i].dongia*0.1));
				p->info.dsvt[i].thanhTien=p->info.dsvt[i].dongia*p->info.dsvt[i].soluong;
			}
			p->info.tongTien+=p->info.dsvt[i].thanhTien;

		}

	}
}
//tim sp co gia trong khoang x y nhap vao
void timsp(DList &LHD,float x,float y)
{
	NodeHD* p;
	cout<<setw(10)<<"maVT";
	cout<<setw(15)<<"tenVT";
	cout<<setw(10)<<"dongia";
	cout<<setw(15)<<"soluong";
	cout<<setw(10)<<"donvitinh";
	cout<<setw(11)<<"thanhTien\n";
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		for(int i=0;i<p->info.soluong;i++)
		{
			if(p->info.dsvt[i].dongia>x&&p->info.dsvt[i].dongia<y)
				xuatVT(p->info.dsvt[i]);
		}
	}
}
void inDList(DList &LHD)
{
	LHD.Head=LHD.Tail=NULL;
}
NodeHD *getNodeHD(HoaDon x){
	NodeHD *p;
	p=new NodeHD;
	if(p==NULL){
		cout<<"bo nho khong du";
		exit(1);
	}
	p->info=x;
	p->next=NULL;
	p->pre=NULL;
	return p;
}
void themcuoiHD(DList &LHD, NodeHD* q)
{
	if(LHD.Head==NULL){
		LHD.Head=q;
		LHD.Tail=LHD.Head;
	}
	else
	{
		LHD.Tail->next=q;
		q->pre=LHD.Tail;
		LHD.Tail=q;
	}
}
void nhapHD(HoaDon &x,ListNV &Q)
{	
	nodeNV *p;
	cout<<"nhap ma hoa don: "; cin>>x.maHD;
	fflush(stdin);
	do{
	cout<<"nhap nhan vien lap: "; cin>>x.NVlap;
	p=timkiemtheoten(Q,x.NVlap);
	if(p==NULL){
		cout<<"ko ton tai ten nhan vien: ";
	}
	}while(p==NULL);
	fflush(stdin);
	cout<<"nhap ngay lap: "; cin>>x.ngaylap;
	cout<<"nhap so luong vat tu: ";cin>>x.soluong;
	cout<<"nhap danh sach vat tu: \n";
	for(int i=0;i<x.soluong;i++){
		nhapVT(x.dsvt[i]);
	}
	x.tongTien=0;
	for(int i=0;i<x.soluong;i++){
		x.tongTien+=x.dsvt[i].thanhTien;
	}
}
void nhapDSHD(DList &LHD,ListNV &Q){
	NodeHD *p;
	int n;
	HoaDon x;
	cout<<"nhap so luong hoa don: ";
	cin>>n;
	for(int i=0;i<n;i++){
		nhapHD(x,Q);
		p=getNodeHD(x);
		themcuoiHD(LHD,p);
	}
}
void xuatHD(HoaDon x){
	cout<<"\nma hoa don: "<<x.maHD<<endl;
	cout<<"nhan vien lap: "<<x.NVlap<<endl;
	cout<<"ngay lap hoa don: "<<x.ngaylap<<endl;
	cout<<"so luong hoa don: "<<x.soluong<<endl;
	cout<<"danh sach vat tu: \n"<<endl;
	cout<<setw(10)<<"maVT";
	cout<<setw(15)<<"tenVT";
	cout<<setw(10)<<"dongia";
	cout<<setw(15)<<"soluong";
	cout<<setw(10)<<"donvitinh";
	cout<<setw(11)<<"thanhTien\n";
	for(int i=0;i<x.soluong;i++){
		xuatVT(x.dsvt[i]);
		cout<<"\n";
	}
	cout<<"\ntong tien hoa don: "<<x.tongTien;
}
void xuatDSHD(DList &LHD){
	NodeHD *p;
	for(p=LHD.Head;p!=NULL;p=p->next){
		xuatHD(p->info);
	}
}
void luuFileHD(FILE *f,DList &LHD)
{
	f= fopen("HoaDon.dat","wb");
	int n=0;
	NodeHD *p;
	for(p=LHD.Head;p!=NULL;p=p->next)
 	{
 		n+=1;
	 }
	 fwrite(&n,sizeof(int),1,f);
	for(p=LHD.Head;p!=NULL;p=p->next)
 	{
 		fwrite(&p->info,sizeof(HoaDon),1,f);
	 }
	 fclose(f);
	 cout<<"luu file thanh cong";		
}
void DocFileHD(FILE *f,DList &LHD)
{
	int n;
	NodeHD *p;
	HoaDon x;
	inDList(LHD);
	f= fopen("HoaDon.dat","rb");
	fread(&n,sizeof(int),1,f);
	for(int i=0;i<n;i++)
 	{
 		fread((char*)&x, sizeof(HoaDon), 1, f);
		 p=getNodeHD(x);
	     themcuoiHD(LHD,p);		 	
	 }
	 fclose(f);
	 	
}
void suangaylapHD(DList &LHD,int mahd){
	NodeHD *p;
	char nglap[20];
	cout<<"nhap ngay lap thay doi: ";
	cin>>nglap;
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		if(p->info.maHD==mahd){
			strcpy(p->info.ngaylap,nglap);
		}
	}

}
NodeHD* timkiemHDma(DList LHD, int ma){
	NodeHD* p;
	for(p=LHD.Head;p!=NULL;p=p->next){
		if(p->info.maHD==ma){
			break;
		}
	}
	return p;
}
void xoahoadon(DList &LHD,int mahd)
{
	NodeHD* p;
	p=timkiemHDma(LHD,mahd);
	if(p==NULL){
		cout<<"khong ton tai ma hoa don ";
		return ;
	}
	else
	{
		if(p==LHD.Head&&p==LHD.Tail){
			LHD.Head=NULL;
			LHD.Tail=NULL;
		}
		else
			if(p==LHD.Head) LHD.Head=p->next;
		else if(p==LHD.Tail)
		{
			p->pre->next=NULL;
			LHD.Tail=p->pre;
		}
		else{
			p->pre->next=p->next;
			p->next->pre=p->pre;
		}
		free(p);
	}	
}
void sxtangtongtien(DList &LHD){
	HoaDon tg;
	NodeHD *p,*q;
	for(p=LHD.Head;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(p->info.tongTien>q->info.tongTien)
			{
				tg=p->info;
				p->info=q->info;
				q->info=tg;
			}
}
void sxtanggiamtien(DList &LHD){
	HoaDon tg;
	NodeHD *p,*q;
	for(p=LHD.Head;p!=NULL;p=p->next)
		for(q=p->next;q!=NULL;q=q->next)
			if(p->info.tongTien<q->info.tongTien)
			{
				tg=p->info;
				p->info=q->info;
				q->info=tg;
			}
}
void timHDLN(DList LHD){
	NodeHD *p;
	long max;
	max=LHD.Head->info.tongTien;
	for(p=LHD.Head;p!=NULL;p=p->next){
		if(p->info.tongTien>max)
			max=p->info.tongTien;
	}
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		if(p->info.tongTien==max)
			break;
	}
	cout<<"\nhoa don co tong tien > nhat: ";
	xuatHD(p->info);
}
void timHDNN(DList LHD){
	NodeHD *p;
	long min;
	min=LHD.Head->info.tongTien;
	for(p=LHD.Head;p!=NULL;p=p->next){
		if(p->info.tongTien<min)
			min=p->info.tongTien;
	}
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		if(p->info.tongTien==min)
			break;
	}
	cout<<"\nhoa don co tong tien < nhat: ";
	xuatHD(p->info);
}
long tongtienall(DList &LHD)
{
	NodeHD *p;
	long tien;
	tien=0;
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		tien+=p->info.tongTien;
	}
	return tien;
}
void demHD(DList LHD)
{
	long tien;
	NodeHD *p;
	cout<<"nhap so tien hoa don: ";
	cin>>tien;
	int dem;
	dem=0;
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		if(p->info.tongTien>tien)
			dem++;
	}
	cout<<"\nso hoa don co tien > so tien vua nhap la: "<<dem;
}
void lietkeHDtheotien(DList LHD)
{
	long tien;
	cout<<"\nnhap so tien de liet ke: ";
	cin>>tien;
	NodeHD *p;
	cout<<"\ncac hoa don co tong tien > so tien vua nhap: \n"<<endl;
	for(p=LHD.Head;p!=NULL;p=p->next)
	{
		if(p->info.tongTien>tien)
			xuatHD(p->info);
	}
}
