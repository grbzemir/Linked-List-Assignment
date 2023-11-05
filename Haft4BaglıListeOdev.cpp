#include<iostream>
#include<locale.h>
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct node

{

    int sayi;
    struct node* sonraki;

};


node* ilk = NULL;

int mevcut = 0;


void menu(void);

void ekle();


void sirali_ekle();

void liste(void);

void ara(void);

void guncelle(void);

void sil(void);

int main()


{
    
    system("color 0a");
    
    setlocale(LC_ALL, "turkish");
     
    do
    {

        menu();

    } 
    
    while(1);

    system("pause");

    return(0);
    

}


void menu(void)


{

    char secim;
    system("cls");

    printf("Bagli Liste MENU                            düğüm adet : %d\n", mevcut);

    printf("1. Kayit Ekle\n");
    printf("2. Kayit Ara\n");
    printf("3. Kayit Listele\n");
    printf("4. Kayit Güncelle\n");
    printf("5. Kayit Sil\n");
    printf("6. Cikis\n");
    printf("Seciminiz(1/2/3/4/5/6) ");

    do

    {
            
            secim = _getch();


    }

    while(!(secim > 48 && secim < 55));

    printf("\n");


    switch(secim)

    {

        case 49: 

        sirali_ekle();

        break;

        case 50: 

        ara();

        break;

        case 51:

        liste();

        break;

        case 52:

        guncelle();

        break;

        case 53:

        sil();

        break;

        case 54:

        exit(0);


    }

}


void ekle()

{

    int data;

    printf("\n Eklenecek Sayi: ");

    scanf("%d", &data);

    struct node* temp = (node*)malloc(sizeof(node));

    mevcut++;

    if (temp != NULL)

    {

        temp->sayi = data;

        temp->sonraki = NULL;

        struct node* ptr = ilk;

        if (ilk == NULL)

        {

            ilk = temp;

        }

        else

        {

            while (ptr->sonraki != NULL)

            {

                ptr = ptr->sonraki;

            }

            ptr->sonraki = temp;

               
    }
}

else
{
    
        printf("\nYer ayrilamadi!");
}

}


void sirali_ekle()

{

    int data;

    printf("\n Eklenecek Sayi: ");

    scanf("%d", &data);

    struct node* temp = (node*)malloc(sizeof(node));

    mevcut++;

    if (temp != NULL)

    {

        temp->sayi = data;

        temp->sonraki = NULL;

        struct node* ptr = ilk , *onceki = NULL;

        if (ilk == NULL)

        {

            ilk = temp;

        }

        else

        {

            onceki = NULL;

                while (ptr->sonraki != NULL && ptr->sonraki->sayi < data)

                {
                    
                    onceki = ptr;
                    ptr = ptr->sonraki;

                }

               if(ptr-> sayi < data)

               {

                ptr-> sonraki = temp;

               }

               else
               {
                   
                   if(onceki == NULL)

                   {
                      
                      temp->sonraki = ilk;
                        ilk = temp;


                   }

                   else
                   {
                    
                    onceki->sonraki = temp;
                    temp->sonraki = ptr;

                   }

               }

        }

    }

    else

    {

        printf("\nYer ayrilamadi!");

    }

}


    void liste() 
    
    {

    struct node* temp = (node*)malloc(sizeof(node));
    struct node* ptr = ilk;
    system("cls");

    while (ptr != NULL) 
    
    {
        if(ptr->sonraki!=NULL) printf("[%d ]%d --> ", ptr,ptr->sayi);
        else printf("[%d ]%d", ptr,ptr->sayi);
        ptr = ptr->sonraki;

    }

    printf("\n");

    system("pause");

}

void ara() 

{
    int ara_sayi;
    printf("\nAranan Sayi :");
    scanf("%d",&ara_sayi);
    struct node* ptr = ilk;

    system("cls");

    bool durum = false;

    while (ptr != NULL) 
    
    {
        if (ptr->sayi == ara_sayi) 
        
        {

            printf("Buldum  adresi : %p\n", ptr);
            durum = true;

        }

        ptr = ptr->sonraki;
    }


    if (durum == false) 
    {
        printf("Aranan sayi bulunamadi.\n");

    }

    system("pause");

 }


void guncelle() 

{

    int gun_sayi;

    printf("Sirasiz ekle ile kullaniniz,\nverileriniz listede sirali olarak tutuluyor ise bu veriyi güncellemeniz bu yapiyi bozabilir\n");
    printf("\nGüncellenecek Sayi :");
    scanf("%d", &gun_sayi);
    struct node* ptr = ilk;

    system("cls");

    bool durum = false;

    while (ptr != NULL) 
    
    {
        if (ptr->sayi == gun_sayi)
        
         {

            printf("Buldum  adresi : %p\n", ptr);
            printf("Yeni sayi gir: ");
            scanf("%d", &ptr->sayi);
            durum = true;

        }

        ptr = ptr->sonraki;

    }

    if (durum == false) 
    
    {
        printf("Aranan sayi bulunamadi.\n");

    }

}

void sil(void) 
{
    int ara_sayi;

    printf("\nSilinecek Sayi :");
    scanf("%d", &ara_sayi);
    struct node* ptr = ilk, * onceki = NULL;
    bool durum = false;

    while (ptr->sonraki != NULL) 
    
    {
        if (ptr->sayi == ara_sayi) 
        
        {
            if (onceki == NULL)
            
            ilk = ilk->sonraki;

            else 
            
            {
                onceki->sonraki = ptr->sonraki;
                free(ptr);

            }

            durum = true;
            mevcut--;
            break;
        }

        onceki = ptr;
        ptr = ptr->sonraki;

    }

    if (ptr->sayi == ara_sayi && durum==false )
    
     {

        if (onceki != NULL) 
        
        {
            onceki->sonraki = NULL;   

        }

        else 
        
        {
            free(ilk);
            ilk = NULL;

        }

        mevcut--;
    }

}

