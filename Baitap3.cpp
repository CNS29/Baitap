#include<stdlib.h>
#include<stdio.h>
#include<conio.h>
struct Node{
	int Data;
	struct Node *pLeft;
	struct Node *pRight;	
};
typedef Node *TREE;
//khoi tao cay
void Createtree(TREE &t)
{
	t=NULL;
}
//them node vao cay
void AddNodeToTree(TREE &t,int x)
{
	if(t==NULL)
	{
		Node *p= new Node;
		p->Data=x;
		p->pLeft=NULL;
		p->pRight=NULL;
		t=p;
	}else
	{
		if(t->Data>x)
		{
			AddNodeToTree(t->pLeft,x);
		}
		else if(t->Data<x)
		{
			AddNodeToTree(t->pRight,x);
		}
	}
}
void NLR(TREE t)
{
	if (t != NULL)
	{
	//xu li t
	printf("%d ", t->Data);
	NLR(t->pLeft);
	NLR(t->pRight);
	}
}
void LNR(TREE t)
{
	if (t != NULL)
	{
	//xu li t
	LNR(t->pLeft);
	printf("%d ", t->Data);
	LNR(t->pRight);
	}
}
void LRN(TREE t)
{
	if (t != NULL)
	{
	//xu li t
	LRN(t->pLeft);
	LRN(t->pRight);
	printf("%d ", t->Data);
	}
}
void Replace(TREE &q, TREE &p){
    // tim phan tu trai nhat cua cay ben phai
    if(p->pLeft!=NULL){
        Replace(q,p->pLeft);
    }
    else {
        q->Data = p->Data;
        q=p;
        p=p->pRight;
    }

}
void DeleteNode(TREE &t,int data)//data la gia tri node can xoa
{
	if(t==NULL)
	{
		return;//ket thuc ham
	}
	else 
	{
		if(data < t->Data)
		{
			DeleteNode(t->pLeft,data);
		}else if(data > t->Data)
		{
			DeleteNode(t->pRight,data);
		}else//data==t->Data da tim ra cai node can xoa
		{
			Node *p=t;
			if(t->pLeft==NULL)
			{
				t=t->pRight;
			}
			else if(t->pRight==NULL)
			{
				t=t->pLeft;
			}
			else 
			{
				Replace(p,t->pRight);	
			}
			delete p;
		}
	}
}
void SearchNode(TREE t)//tim node co 2 con
{
	if(t != NULL)
	{
		if(t->pLeft !=NULL && t->pRight != NULL)
		{
			printf("%d ",t->Data);
		}
		SearchNode(t->pLeft);
		SearchNode(t->pRight);
	}
}
int EvenTotal(TREE t)//tinh tong cac nut chan
{
	if(t!=NULL)
	{
		int a=EvenTotal(t->pLeft);
		int b=EvenTotal(t->pRight);
		if(t->Data%2==0)
		{
			return t->Data+a+b;
		}
		else
		{
			return a+b;
		}
		return 0;
	}
}
int OddTotal(TREE t)//tinh tong cac nut le
{
	if(t!=NULL)
	{
		int a=OddTotal(t->pLeft);
		int b=OddTotal(t->pRight);
		if(t->Data%2!=0)
		{
			return t->Data+a+b;
		}
		else
		{
			return a+b;
		}
		return 0;
	}
}
bool SearchPrime(int x)//tim x co phai la so nguyen to hay khong
{
	if(x<2)
	{
		return false;
	}
	else if(x==2)
	{
		return true;
	}
	else if(x%2==0)
	{
		return false;
	}
	else
	{
		for(int i=2;i<x;i++)
		{
			if(x%i==0)
			{
				return false;
			}
		}
	}
	return true;
}
/*void Prime(TREE t)//tim cac so nguyen to
{
	if(t!=NULL)
	{
		if(SearchPrime(t->Data)==true)
		{
			printf("%d ",t->Data);
			
		}
		Prime(t->pLeft);
		Prime(t->pRight);
	}
}*/
int CountPrime(TREE t)//Tinh tong và tim cac so nguyen to
{
	if(t!=NULL)
	{
		int a=CountPrime(t->pLeft);
		int b=CountPrime(t->pRight);
		if(SearchPrime(t->Data)==true)
		{
			printf("So nguyen to: %d \n",t->Data);//xuat cac so nguyen to
			return t->Data+a+b;//tinh tong 
		}
		else
		{
			return a+b;
		}
		return 0;
	}
}
void Menu(TREE &t)
{
	while (true)
	{
		system("cls");
		printf("\n\n\t\t =========== MENU ===========");
		printf("\n1. Nhap du lieu");
		printf("\n2. Nhap du lieu co san 18, 31, 15, 2, 20, 12, 30, 9, 8, 4");
		printf("\n3. Xuat du lieu cay NLR");
		printf("\n4. Xuat du lieu cay LNR");
		printf("\n5. Xuat du lieu cay LRN");
		printf("\n6. Xoa 1 phan tu trong cay ");
		printf("\n7. Xuat phan tu co 2 con ");
		printf("\n8. Xuat tong so chan và so le");
		printf("\n9. Xuat cac so nguyen to trong cay va tinh tong ");
		printf("\n0. Ket thuc");
		printf("\n\n\t\t ============================");
		int n;
		printf("\nNhap lua chon: ");
		scanf("%d",&n);
		if (n < 0 || n > 11)
		{
			printf("\nLua chon khong hop le");
			printf("\nNhan Enter de nhap lai ");
			getch();
		}
		else if (n == 1)
		{
			int x;
			printf("\nNhap so nguyen x: ");
			scanf("%d",&x);
			AddNodeToTree(t, x);
		}
		else if (n == 2)
		{
			int a[]={18, 31, 15, 2, 20, 12, 30, 9, 8, 4};
			for(int i=0;i<10;i++)
			{
				AddNodeToTree(t,a[i]);
			}
			printf("\nPhan tu da duoc them vao ");
			printf("\nNhan Enter de tiep tuc ");
			getch();
		}
		else if (n == 3)
		{
			printf("\n\t\t DUYET CAY THEO NLR\n");
			NLR(t);
			getch();
		}
		else if (n == 4)
		{
			printf("\n\t\t DUYET CAY THEO LNR\n");
			LNR(t);
			getch();
		}
		else if (n == 5)
		{
			printf("\n\t\t DUYET CAY THEO LRN\n");
			LRN(t);
			getch();
		}
		else if (n == 6)
		{
			int x;
			printf("\n\t\t XOA PHAN TU\n");
			printf("\nNhap phan tu muon xoa: ");
			scanf("%d",&x);
			DeleteNode(t,x);
		}
		else if (n == 7)
		{
			printf("\n\t\t XUAT PHAN TU 2 CON\n");
			SearchNode(t);
			getch();
		}
		else if (n == 8)
		{
			printf("\n\t\t XUAT TONG SO CHAN\n");
			printf("%d ",EvenTotal(t));
			printf("\n\t\t XUAT TONG SO LE\n");
			printf("%d ",OddTotal(t));
			getch();
		}
		else if (n == 9)
		{
			printf("\n\t\t XUAT CAC SO NGUYEN TO VA TONG CAC SO NGUYEN TO\n");
			printf("%d ",CountPrime(t));
			getch();
		}
		else
		{
			break;
		}
	}

}
int main(){
	TREE t;
	Createtree(t);
	Menu(t);
	getch();
}
