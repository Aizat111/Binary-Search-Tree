#include<stdio.h>
#include<stdlib.h>

typedef struct Veri{
	int sayi;
	struct Veri * right;
	struct Veri * left;
}Agac;

Agac *root=NULL;
int toplam=0,sayac=0;

Agac * BilgiAl(int sayi)
{
	Agac* yeni;
	yeni=(Agac*)malloc(sizeof(Agac));
	yeni->sayi=sayi;
	yeni->left=NULL;
	yeni->right=NULL;
	return yeni;
}

void Ekle(Agac *dugum)
{
	Agac *parent, *gecici;
	if(root==NULL)
	root=dugum;
	else
	{
		gecici=root;
		while(gecici)
		{
			parent=gecici;
			if(dugum->sayi < gecici->sayi)
			{
				gecici=gecici->left;
			} 
			else
			{
				gecici=gecici->right;
			}
		}
		if(dugum->sayi<parent->sayi)
		{
			parent->left=dugum;
		}
		else
		{
			parent->right=dugum;
		}
	}
}

void SeviyeOku(Agac *dugum,int seviye,int temp)
{
	if(dugum!=NULL)
	{
	if(temp==seviye)
	{	
	printf("%d\t",dugum->sayi);
	return;
	}
	SeviyeOku(dugum->left,seviye,temp+1);
	SeviyeOku(dugum->right,seviye,temp+1);
	}
	
	
}

int Ara(Agac *dugum,int aranan,int sayac)
{
	if(dugum==NULL)return 0;
	if(dugum->sayi==aranan)return sayac;
	
	else if(dugum->sayi>aranan){
		Ara(dugum->left,aranan,sayac+1);
	}
	else if(dugum->sayi<aranan)
	{
		Ara(dugum->right,aranan,sayac+1);
	}
	
}
void dolas(Agac *dugum,int deger)
{
	if(dugum==NULL) return;
	dolas(dugum->left,deger);
	if(dugum->sayi>deger)
	printf("%d\t",dugum->sayi);	
	dolas(dugum->right,deger);
}


float YaprakOrtalama(Agac *dugum)
{
	
	if(dugum==NULL) return 0 ;
	YaprakOrtalama(dugum->left);
	YaprakOrtalama(dugum->right);
	if(dugum->left==NULL&&dugum->right==NULL)
	{
	toplam+=dugum->sayi;
	sayac++;
	}
	return (float)toplam/sayac;
}

int main()
{
	char secim;
	int sayi;
	while(true)
	{
	printf("\n******Menu*******\n");
	printf("a)Agaca veri ekle\nb)Herhangi bir seviyedeki degerleri ogren\nc)Eleman ara\nd)Yaprak dugumlerin ortalamasi\ne)Girilen degerden buyuk olan sayilarin listesi\nf)Cikis\n");
	printf("Sizin secim->>>");
	scanf("%s",&secim);
	switch(secim)
	{
		case 'a':	{
						printf("Agaca eklenecek sayiyi giriniz->>");
						scanf("%d",&sayi);
						Ekle(BilgiAl(sayi));
						break;
					}
		case 'b':	{
						printf("Hangi seviyedeki degerleri ogrenmek istersiniz->>");
						scanf("%d",&sayi);
						SeviyeOku(root,sayi,0);
						break;
					}
		case 'c':	{
						printf("Aratmak istediginiz degeri giriniz->>");
						scanf("%d",&sayi);
						int sonuc=Ara(root,sayi,1);
						if(sonuc==0)printf("%d elemani bulunmadi",sayi);
						else
						printf("\n%d elemani %d adimda bulundu.\n",sayi,sonuc);
						break;
					}
		case 'd':	{	
						printf("Yaprak dugumlerin ortalamasi:%.2f",YaprakOrtalama(root));
						break;
					}
		case 'e':	{
						printf("Hangi degerden buyuk olan elemanlari ogrenmek  istiyorsunuz->>");
						scanf("%d",&sayi);
						printf("\n%d sayisindan buyuk olan elemanlar->>",sayi);
						dolas(root,sayi);
						break;
					}
		case 'f':	{
						exit(0);
						break;
					}
		default:	{
						printf("Menude olmayan secim yaptiniz.\n");
						break;
					}
	}
	}	
	return 0;
}
