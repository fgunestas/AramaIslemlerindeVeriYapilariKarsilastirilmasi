#include<iostream>
#include <stdlib.h>
#include <stdio.h>
#include <chrono>  
using namespace std;
using namespace std::chrono;



//düz for döngüsü
int bfSearch(int arry[8], int n)
{
	for (int i = 0; i < n; i++)
	{
		int flag = 0;
		for (int j = 0; j < n; j++)
		{
			if (i == arry[j])
			{
				flag = 1;
			}
		}
		if (flag == 0)
		{
			return i;
		}
	}
};


// Tek bağlantili liste dugum yapisi
struct node
{
	float info;
	struct node* next;
};

// NODEPTR : dugum isaretci tipi
typedef struct node* NODEPTR;
NODEPTR getNode()
{
	NODEPTR p = (NODEPTR)malloc(sizeof(struct node));
	return p;
}
void freeNode(NODEPTR p)
{
	free(p);
}
void push(NODEPTR* list, float k)
{
	NODEPTR p = getNode();    // Bellekten dugum al
	p->info = k;    // Dugumun veri alanini doldur
	p->next = *list; // Yeni dugumu liste basina bağla
	*list = p;    // Liste basini guncelle
}


// Bir ikili agac dugum yapisi
struct btnode
{
	int info;
	struct btnode* left;
	struct btnode* right;
	struct btnode* parent;    // ‹st dugum adres
};
typedef struct btnode* BTNODEPTR;
//bellek ayirma.
BTNODEPTR getbtNode()
{
	BTNODEPTR p = (BTNODEPTR)malloc(sizeof(struct btnode));
	return p;
}
void freebtNode(BTNODEPTR p)
{
	free(p);
}
// info alani r olan bir ikili agac kok dugumu olusturma
BTNODEPTR createRoot(int r)
{
	BTNODEPTR root = getbtNode();
	root->info = r;
	root->left = NULL;
	root->right = NULL;
	root->parent = NULL;
	return root;
}
BTNODEPTR addChildNode(BTNODEPTR parent, int k, bool isLeft)
{
	bool kosul1 = (parent != NULL);
	bool kosul2 = (isLeft == true && parent->left == NULL);
	bool kosul3 = (isLeft == false && parent->right == NULL);

	if (kosul1 && (kosul2 || kosul3))
	{
		BTNODEPTR c = getbtNode();    // Yeni dugumu olustur
		c->info = k;
		c->left = NULL;
		c->right = NULL;
		if (isLeft == true)
			parent->left = c;
		else
			parent->right = c;

		c->parent = parent;      // cocuk dugum ust dugum baglantisi
		return c;
	}
	else
	{
		printf("Cocuk dugum ekleme hatasi!\n");
		return NULL;
	}
}

int searchNode(NODEPTR list, int x)
{
	NODEPTR p = list;
	int flag = 0;
	while (p != NULL)
	{
		if (x == p->info)
		{
			flag = 1;
			return flag;
		}
		p = p->next;
	}
	return flag;
}
int bagliListeArama(NODEPTR bl, int n)
{
	for (int i = 0; i < n; i++)
	{
		int x = searchNode(bl, i);
		if (x == 0)
		{
			return i;
		}
	}
};
int treeeSearch(BTNODEPTR root, int n)
{
	for (int i = 0; i < n; i++)
	{

		int x = treeSearch(root, i);
		if (x == 0)
		{
			return i;
		}
	}
};
int treeSearch(BTNODEPTR root, int n)
{
	BTNODEPTR r = root;
	if (root != NULL) //eger burada bir node yoksa program return 0 edecektir.
	{
		int sol = treeSearch(r->left, n); //sol alt node araması deger 0 dan buyuk gelirse deger bukunmus demektir.
		int sag = treeSearch(r->right, n); //sag alt node araması deger 0 dan buyuk gelirse deger bukunmus demektir.
		int now;
		if (r->info == n) //aranan sayının node infosuna esit olup olmadığı sorulur.
		{
			now = 1; //aradığımız sayı bulununca return değerini tetikleyen deger 0 dan farklı olarak atanır.
		}
		else
			now = 0; //aradığımız sayıya ulasamadıysak return değerine etkisiz eleman atanır.
		return sol + sag + now; //return degerimiz node un altındaki(sağ ve sol) elemanlarla ve node un simdiki değeriyle toplanır.
	}                           //(assagıda yada bu node da aradığımız karakter bulunmuş olursa return değeri 0 dan buyuk olmus olacak.)
	return 0;
}

int main()
{
	//Dizi ile bulma
	int hehehe[8] = { 8,5,2,7,4,1,3,0 };
	auto start1 = high_resolution_clock::now();
	int y = bfSearch(hehehe, 8);
	cout << y;
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	//sonuç çıktısı
	cout << " \nFor fonksiyon calisma suresi: " << duration1.count() << " mikrosaniye" << endl;



	//bağlı liste ile bulma
	NODEPTR liste = NULL;
	push(&liste, 8);
	push(&liste, 5);
	push(&liste, 2);
	push(&liste, 7);
	push(&liste, 4);
	push(&liste, 1);
	push(&liste, 3);
	push(&liste, 0);
	auto start2 = high_resolution_clock::now();
	int z = bagliListeArama(liste, 8);
	cout << z;
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	//sonuç çıktısı
	cout << " \nBagli liste fonksiyon calisma suresi: " << duration2.count() << " mikrosaniye" << endl;


	//ikili ağaç oluşturma.
	BTNODEPTR r = createRoot(8);
	BTNODEPTR p1 = addChildNode(r, 5, true);
	BTNODEPTR p2 = addChildNode(r, 2, false);
	BTNODEPTR p3 = addChildNode(p1, 7, true);
	BTNODEPTR p4 = addChildNode(p1, 4, false);
	BTNODEPTR p5 = addChildNode(p2, 1, true);
	BTNODEPTR p6 = addChildNode(p2, 3, false);
	BTNODEPTR p7 = addChildNode(p3, 0, true);

	//ikili ağaç süresi hesaplama
	auto start = high_resolution_clock::now();
	int x = treeeSearch(r, 8);
	cout << x;
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	//sonuç çıktısı
	cout << " \nBinary tree fonksiyon calisma suresi: " << duration.count() << " mikrosaniye" << endl;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file