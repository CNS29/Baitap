#include<stdio.h>
#include<conio.h>
using namespace std;
/*
Nguyen Minh Canh 
STT: 1751062223 
Lop: K59TH
*/
struct thongtinsv{
	char ten[30];
	char masv[20];
	char tenmonhoc[20];
	float diemmonhoc;
};
typedef thongtinsv SV;
//khai bao pphan tu va danh sach lien ket 
struct NODE{
    SV Info;
    NODE *pNext;
 };
 //
struct LIST{
	NODE* pHead;
	NODE* pTail;
};
//khoi tao danh sach rong
void Init(LIST &l)
{
l.pHead = l.pTail = NULL;
}
//tao phan tu
NODE* GetNode(SV x)
{
NODE *p= new NODE;
if (p==NULL) {
printf("Khong du bo nho"); return NULL;
}
p->Info = x;//luu x vào sv
p->pNext = NULL;
return p;
}
//them vao cuoi phan tu
void AddTail(LIST &l, NODE *p)
{
if (l.pHead==NULL)
l.pHead = l.pTail = p;
else
l.pTail = l.pTail->pNext = p;
}
void nhapttsv(SV &sv)
{
    printf("\nNhap ten: ");
    fflush(stdin);
	gets(sv.ten);
    printf("\nNhap ma sv: "); 
	gets(sv.masv);
    printf("\nNhap ten mon hoc: "); 
	gets(sv.tenmonhoc);
	printf("\nNhap diem mon hoc: "); 
	scanf("%f",&sv.diemmonhoc);
}
void Input(LIST &l)
{
	SV sv;
	int n;
	printf("nhap vao so luong sinh vien:");
	scanf("%d",&n);
	printf("NHAP THONG TIN SINH VIEN:");
	for(int i=0;i<n;i++)
	{
		nhapttsv(sv);
		NODE* p=GetNode(sv);
		AddTail(l,p);
		printf("\n--------------------------------");
	}
}
void xuatthongtinsv(SV sv){
    printf("\nHo ten SV: %s", sv.ten);
    printf("\nMa SV: %s", sv.masv);
    printf("\nTen mon hoc: %s", sv.tenmonhoc);
    printf("\nDiem mon hoc: %.2f", sv.diemmonhoc);
}
void Output(LIST l)
{
	printf("\nXUAT THONG TIN SINH VIEN");
	for(NODE* p=l.pHead; p!=NULL; p=p->pNext)
	{
		xuatthongtinsv(p->Info);
	}
}
void Max(LIST l)
{
	NODE*p,*max;
	max=l.pHead;
	for(p=l.pHead; p!=NULL; p=p->pNext)
	{
		if(p->Info.diemmonhoc>max->Info.diemmonhoc)
		{
			max=p;
		}
	}
	printf("\n--------------------------------");
	printf("\nSINH VIEN CO DIEM CAO NHAT ");
	xuatthongtinsv(max->Info);
}
void Min(LIST l)
{
	NODE*p,*min;
	min=l.pHead;
	for(p=l.pHead; p!=NULL; p=p->pNext)
	{
		if(p->Info.diemmonhoc<min->Info.diemmonhoc)
		{
			min=p;
		}
	}
	printf("\n--------------------------------");
	printf("\nSINH VIEN CO DIEM THAP NHAT ");
	xuatthongtinsv(min->Info);
}
int main(){
	LIST l;
	Input(l);
	Output(l);
	Max(l);
	Min(l);
	getch();
	return 0;
}
