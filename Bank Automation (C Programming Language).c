#include <stdio.h>
#include <stdlib.h>

int bakiyesorgu();
int parayatirma();
int paracekme();
int sifredegistirme();
void musteriekle();
int musterisilme();
void musterilistele();
int musteriguncelle();

int PERSONELSIFRE=123456; //PERSONELE OZEL ISLEMLERDE PERSONEL SIFRESI!!

// IC ICE STRUCT, ID VE KISISEL BILGILER

 struct musteribilgi{

 char ad[20];
 char soyad[20];
 int yas;
 int bakiye;
 int musterisifre;

};



 struct bilgi{

 int id;
 struct musteribilgi musteri;
 };



struct bilgi *p1;


// ilk sayi icin ayarlanan ve musteri ekledikce artirilan sayi(yer kalmadiginda yeni yer ekliyor)
int baslangicsayisi=10;


//BAKIYE SORGULAMA FONKSIYONU
int bakiyesorgu()
{
    int sorgulananid,denenensifre;
    printf("ID'nizi giriniz(Enter your ID:");
    scanf("%d",&sorgulananid);
    for(int x=0;x<baslangicsayisi;x++)
    {
        if((p1+x)->id==sorgulananid)
        {
            printf("Musteri sifrenizi giriniz(Enter your costumer password):");
            scanf("%d",&denenensifre);
            if((p1+x)->musteri.musterisifre==denenensifre)
            {

                printf("BU HESAPTA %d TL PARA BULUNUYOR(THERE IS %d TL IN THIS ACCOUNT)\n\n",(p1+x)->musteri.bakiye,(p1+x)->musteri.bakiye);
                return 0;
            }
            else
            {
                printf("YANLIS SIFRE!(WRONG PASSWORD!)\n");
                printf("Menuye donuluyor...(Returning to menu...)\n\n");
                return 0;
            }

        }
    }
    printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL!(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
    printf("Menuye donuluyor...(Returning to menu...)\n\n");
     return 0;
}

//PARA YATIRMA FONKSIYONU
int parayatirma()
{
  int parayatirilanid,yatirilanpara,denenensifre;
  printf("ID'nizi giriniz(Enter your ID):");
  scanf("%d",&parayatirilanid);
  for(int y=0;y<baslangicsayisi;y++)
  {
      if((p1+y)->id==parayatirilanid);
      {
          printf("Musteri sifrenizi giriniz(Enter your costumer password):");
          scanf("%d",&denenensifre);
          if((p1+y)->musteri.musterisifre==denenensifre)
       {

          printf("Ne kadar para yatirmak istiyorsunuz?(How much money do you want to deposit):");
          scanf("%d",&yatirilanpara);
          printf("LUTFEN PARAYI ALT BOLMEYE YERLESTIRIN!(PLEASE PLACE THE MONEY IN THE BOTTOM COMPARTMENT!)\n");
          (p1+y)->musteri.bakiye=((p1+y)->musteri.bakiye)+yatirilanpara;
          printf("%d TL %d ID'LI HESABINIZA YATIRILDI(%d TL WAS DEPOSITED INTO YOUR ACCOUNT WITH ID %d\n\n",yatirilanpara,(p1+y)->id,yatirilanpara,(p1+y)->id);
          return 0;
       }
       else
       {
          printf("YANLIS SIFRE!(WRONG PASSWORD!)\n");
          printf("Menuye donuluyor...(Returning to menu...)\n\n");
          return 0;
       }
      }
  }
    printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL!(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
    printf("Menuye donuluyor...(Returning to menu...)\n\n");
     return 0;
}


//PARA CEKME FONKSIYONU
int paracekme()
{
   int paracekilenid,cekilmekistenenpara,denenensifre;
    printf("ID'nizi giriniz(Enter your ID):");
    scanf("%d",&paracekilenid);
    for(int z=0;z<baslangicsayisi;z++)
    {
        if((p1+z)->id==paracekilenid)
        {
            printf("Musteri sifrenizi giriniz(Enter your costumer password):");
            scanf("%d",&denenensifre);
            if((p1+z)->musteri.musterisifre==denenensifre)
        {


            printf("Ne kadar para cekmek istiyorsunuz?(How much money do you want to withdraw?):");
            scanf("%d",&cekilmekistenenpara);
            if(cekilmekistenenpara<=(p1+z)->musteri.bakiye)
            {
              (p1+z)->musteri.bakiye=(p1+z)->musteri.bakiye-cekilmekistenenpara;
              printf("LUTFEN PARAYI ALT BOLMEDEN ALINIZ!(PLEASE TAKE THE MONEY FROM THE BOTTOM COMPARTMENT!\n)");
              return 0;
            }
            else
            {
                printf("%d ID'LI HESAPTA BU KADAR PARA BULUNMAMAKTADIR!(THERE ISN'T MONEY THIS MUCH IN THE ACCOUNT WITH ID %d\n",(p1+z)->id,(p1+z)->id);
                printf("BAKIYE SORGULAMA SECENEGINDEN BAKIYENIZI KONTROL EDINIZ!(CHECK YOUR BALANCE FROM THE BALANCE INQUIRY OPTION!)\n");
                printf("Menuye donuluyor...(Returning to menu...)\n\n");
                return 0;
            }

         }
         else
         {
            printf("YANLIS SIFRE!(WRONG PASSWORD!)\n");
            printf("Menuye donuluyor...(Returning to menu...)\n\n");
            return 0;
         }
        }
    }
    printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL!(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
    printf("Menuye donuluyor...(Returning to menu...)\n\n");
     return 0;
}

//SIFRE DEGISTIRME FONKSIYONU
int sifredegistirme()
{
    int sifreguncellenenid,denenensifre,yenisifre;
    printf("ID'nizi giriniz(Enter your ID):");
    scanf("%d",&sifreguncellenenid);
    for(int a=0;a<baslangicsayisi;a++)
    {
        if((p1+a)->id==sifreguncellenenid)
        {
            printf("Musteri sifrenizi giriniz(Enter your costumer password):");
            scanf("%d",&denenensifre);
            if((p1+a)->musteri.musterisifre==denenensifre)
            {
                printf("Yeni musteri sifrenizi giriniz(Enter your new costumer password):");
                scanf("%d",&yenisifre);
                (p1+a)->musteri.musterisifre=yenisifre;
                printf("Sifreniz degistirildi(Your password has been changed).\n");
                   return 0;
            }
            else
          {
            printf("YANLIS SIFRE!(WRONG PASSWORD!)\n");
            printf("Menuye donuluyor...(Returning to menu...)\n\n");
            return 0;
          }
        }


    }
        printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL!(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
        printf("Menuye donuluyor...(Returning to menu...)\n\n");
        return 0;


}





//BUNDAN SONRAKI MUSTERI EKLEME,SILME VE LISTELEME FONKSIYONLARI PERSONELE OZEL OLUP PERSONEL SIFRESI ISTEMEKTEDIR!!


//MUSTERI EKLEME FONKSIYONU
void musteriekle()
{
  int i,denenensifre;
  printf("Personel sifresi giriniz(Enter password of employee):");
  scanf("%d",&denenensifre);
  if(PERSONELSIFRE==denenensifre)
{
  printf("Sifre dogru!(Password is correct!)\n");
  for(i=0;i<baslangicsayisi;i++)
  {

      if((p1+i)->id==0)
      {
        printf("ID giriniz(Enter ID):");
        scanf("%d",&((p1+i)->id));
        printf("Ad giriniz(Enter name):");
        scanf("%s",&((p1+i)->musteri.ad));
        printf("Soyad giriniz(Enter surname):");
        scanf("%s",&((p1+i)->musteri.soyad));
        printf("Yas giriniz(Enter age):");
        scanf("%d",&((p1+i)->musteri.yas));
        printf("Ilk bakiyeyi giriniz(Enter first balance):");
        scanf("%d",&((p1+i)->musteri.bakiye));
        printf("Musteri sifre giriniz(Enter costumer password):");
        scanf("%d",&((p1+i)->musteri.musterisifre));
        printf("YENI MUSTERI EKLENDI!(NEW COSTUMER HAS BEEN ADDED!)\n\n");

        break;

      }
  }

  //YER BITTIGINDE YENI ALAN TAHSIS ETMEK ICIN
  if(i==baslangicsayisi)
  {
      baslangicsayisi=baslangicsayisi+1;


       p1=(struct bilgi *)realloc(p1,baslangicsayisi*sizeof(struct bilgi));


        printf("ID giriniz(Enter ID):");
        scanf("%d",&((p1+(baslangicsayisi-1))->id));
        printf("Ad giriniz(Enter name):");
        scanf("%s",&((p1+(baslangicsayisi-1))->musteri.ad));
        printf("Soyad giriniz(Enter surname):");
        scanf("%s",&((p1+(baslangicsayisi-1))->musteri.soyad));
        printf("Yas giriniz(Enter age):");
        scanf("%d",&((p1+(baslangicsayisi-1))->musteri.yas));
        printf("Ilk bakiyeyi giriniz(Enter first balance):");
        scanf("%d",&((p1+(baslangicsayisi-1))->musteri.bakiye));
        printf("Musteri sifre giriniz(Enter costumer password):");
        scanf("%d",&((p1+(baslangicsayisi-1))->musteri.musterisifre));
        printf("YENI MUSTERI EKLENDI!(NEW COSTUMER HAS BEEN ADDED!)\n\n");


  }
}
   else
   {
       printf("Yanlis Sifre!(Wrong Password!)\n");
       printf("Menuye donuluyor...(Returning to menu...)\n\n");
   }
}

//MUSTERI SILME FONKSIYONU
int musterisilme()
{
    int silinmekistenenid;
    int denenensifre;
    printf("Personel sifresi giriniz(Enter password of employee):");
    scanf("%d",&denenensifre);
  if(PERSONELSIFRE==denenensifre)
{
    printf("Sifre dogru!(Password is correct!)\n");
    printf("Silmek istediginiz musterinin ID'sini giriniz(Enter the ID of the costumer you want to delete):");
    scanf("%d",&silinmekistenenid);
    for(int k=0;k<baslangicsayisi;k++)
    {
        if((p1+k)->id==silinmekistenenid)
        {
            (p1+k)->id=0;
            (p1+k)->musteri.yas=0;
            (p1+k)->musteri.bakiye=0;
            (p1+k)->musteri.musterisifre=0;
             printf("MUSTERI KAYDI SILINDI!(COSTUMER RECORD DELETED!)\n");
             printf("Menuye donuluyor...(Returning to menu)\n\n");
             return 0;

        }
    }
    printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
    printf("Menuye donuluyor...(Returning to menu)\n\n");
    return 0;
}
  else
  {
     printf("Yanlis Sifre!(Wrong Password!)\n");
     printf("Menuye donuluyor...(Returning to menu...)\n\n");
     return 0;
  }
}

//MUSTERI LISTELEME FONKSIYONU
void musterilistele()
{
    int denenensifre;
    printf("Personel sifresi giriniz(Enter password of employee):");
    scanf("%d",&denenensifre);
  if(PERSONELSIFRE==denenensifre)
{
    printf("Sifre dogru!(Password is correct!)\n");

    printf("ID\t\t");
    printf("AD\t\t");
    printf("SOYAD\t\t");
    printf("YAS\t\t");
    printf("BAKIYE\n");

    for(int j=0;j<baslangicsayisi;j++)
    {
        printf("%d\t\t",(p1+j)->id);
        printf("%s\t\t",(p1+j)->musteri.ad);
        printf("%s\t\t",(p1+j)->musteri.soyad);
        printf("%d\t\t",(p1+j)->musteri.yas);
        printf("%d\n",(p1+j)->musteri.bakiye);
    }
}
  else
  {
     printf("Yanlis Sifre!(Wrong Password)\n");
     printf("Menuye donuluyor...(Returning to menu...)\n\n");
  }
}



//MUSTERİ BILGI GUNCELLEME FONKSIYONU
int musteriguncelle()
{
   int denenensifre,guncellenenid,guncellemesecim;
    printf("Personel sifresi giriniz(Enter password of employee):");
    scanf("%d",&denenensifre);
    if(PERSONELSIFRE==denenensifre)
    {
        printf("Bilgilerini guncelleyececeginiz musterinin ID'sini giriniz(Enter the ID of the customer whose info you will update):");
        scanf("%d",&guncellenenid);
        for(int m=0;m<baslangicsayisi;m++)
        {
            if((p1+m)->id==guncellenenid)
            {
                printf("Hangi bilgiyi degistirmek istiyorsunuz?(What info do you want to update?):\n");
                printf("---------------------------------------------\n");
                printf("AD(NAME) (1)\n");
                printf("SOYAD(SURNAME) (2)\n");
                printf("YAS(AGE) (3)\n");
                printf("ID (4)\n");
                printf("---------------------------------------------\n");
                scanf("%d",&guncellemesecim);
                switch(guncellemesecim)
                {
                 case 1:
                    printf("YENI ADI GIRINIZ(ENTER NEW NAME):");
                    scanf("%s",&((p1+m)->musteri.ad));
                    printf("AD BILGISI DEGISTIRILDI(INFO OF NAME HAS BEEN CHANGED)!\n\n");
                    break;
                 case 2:
                     printf("YENI SOYADI GIRINIZ(ENTER NEW SURNAME):");
                     scanf("%s",&((p1+m)->musteri.soyad));
                     printf("SOYAD  BILGISI DEGISTIRILDI(INFO OF SURNAME HAS BEEN CHANGED)!\n\n");
                     break;
                 case 3:
                     printf("YENI YASI GIRINIZ(ENTER NEW AGE):");
                     scanf("%d",&((p1+m)->musteri.yas));
                     printf("YAS BILGISI DEGISTIRILDI(INFO OF AGE HAS BEEN CHANGED)!\n\n");
                     break;
                 case 4:
                     printf("YENI ID GIRINIZ(ENTER NEW ID):");
                     scanf("%d",&((p1+m)->id));
                     printf("ID DEGISTIRILDI(ID HAS BEEN CHANGED)!\n\n");
                     break;
                 default:
                      printf("GECERSIZ SAYIYI TUSLADINIZ(YOU DIALED INVALID NUMBER)!\n");
                      printf("Menuye donuluyor...(Returning to menu...)\n\n");
                     break;
                }
                     return 0;


            }
        }
       printf("BU ID'DE BIR MUSTERI KAYITLI DEGIL(NO COSTUMER IS REGISTERED WITH THIS ID!)\n");
       printf("Menuye donuluyor...(Returning to menu)\n\n");
       return 0;
    }
  else
  {
     printf("Yanlis Sifre!(Wrong Password)\n");
     printf("Menuye donuluyor...(Returning to menu...)\n\n");
  }
}







int main()
{
   int secim;
   p1=(struct bilgi *)calloc(baslangicsayisi,sizeof(struct bilgi));
   if(p1==NULL)
   {
       printf("Yeterli bellek tahsis edilemedi.Program kapatiliyor...(Could not allocate enough memory.The program is closing...)");
       return 0;
   }
   //BU BIR OTOMASYON OLDUGU ICIN SONSUZ DONGU
   while(1)
{

   printf("TUTKUN BANKASINA HOS GELDINIZ!(WELCOME TO TUTKUN BANK!)\n");
   printf("LUTFEN YAPMAK ISTEDIGINIZ ISLEMI TUSLAYINIZ(PLEASE CLICK ON THE ACTION YOU WANT TO PERFORM):\n");
   printf("--------------------------------------------------------------------------\n");
   printf("BAKIYE SORGULAMA(BALANCE INQUIRY)  (1)\n");
   printf("HESABA PARA YATIRMA(DEPOSIT MONEY INTO ACCOUNT)  (2)\n");
   printf("HESAPTAN PARA CEKME(WITHDRAW MONEY FROM ACCOUNT)  (3)\n");
   printf("MUSTERI SIFRE DEGISTIRME(CHANGE PASSWORD)  (4)\n");
   printf("--------------------------------------------------------------------------\n");
   printf("MUSTERI EKLEME(!Yalnizca Personel!)(ADD COSTUMER(!ONLY EMPLOYEE!))  (5)\n");
   printf("MUSTERI SILME(!Yalnizca Personel!)(DELETE COSTUMER(!ONLY EMPLOYEE!))  (6)\n");
   printf("MUSTERILERI LISTELEME(!Yalnizca Personel!)(LIST COSTUMERS(!ONLY EMPLOYEE!)) (7)\n");
   printf("MUSTERI BILGI GUNCELLEME(!Yalnizca Personel!)(UPDATE COSTUMER INFO(!ONLY EMPLOYEE!)) (8)\n");
   printf("--------------------------------------------------------------------------\n");
   scanf("%d",&secim);
   switch(secim)
   {
    case 1:
        bakiyesorgu();
        break;

    case 2:
        parayatirma();
        break;

    case 3:
        paracekme();
        break;

    case 4:
        sifredegistirme();
        break;

    case 5:
        musteriekle();
        break;

    case 6:
        musterisilme();
        break;
    case 7:
        musterilistele();
        break;
    case 8:
        musteriguncelle();
        break;
    default:
        printf("GECERSİZ SAYİ TUSLADİNİZ!(YOU DIALED INVALID NUMBER!)\n");
        break;
   }


}
    return 0;
}

