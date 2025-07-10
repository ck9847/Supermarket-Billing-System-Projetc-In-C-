//
// Created by Lenovo on 25-7-10.
//
//
// Created by Lenovo on 25-7-10.
//
#include <iostream>
#include <fstream>

class shopping{
      private:
        int pcode;
        float price;
        float dis;
        std::string pname;

        public:
          void menu();
          void administrator();
          void buyer();
          void add();
          void edit();
          void rem();
          void list();
          void receipt();

  };

 void shopping::menu() {
     m:
     int choice;
     std::string email;
     std::string password;

     std::cout<<"\t\t\t\t______________________________________________________\n";
     std::cout<<"\t\t\t\t                                                      \n";
     std::cout<<"\t\t\t\t             Supermarket Main Menu                    \n";
     std::cout<<"\t\t\t\t                                                      \n";
     std::cout<<"\t\t\t\t______________________________________________________\n";
     std::cout<<"\t\t\t\t                                                      \n";
     std::cout<<"\t\t\t\t| 1)Administrator         |\n ";
     std::cout<<"\t\t\t\t|                         |\n ";
     std::cout<<"\t\t\t\t| 2)Buyer                 |\n ";
     std::cout<<"\t\t\t\t|                         |\n ";
     std::cout<<"\t\t\t\t| 3)Exit                  |\n ";
     std::cout<<"\t\t\t\t|                         |\n ";
     std::cout<<"\n\t\t\t Please Select!";
     std::cin>>choice;

     switch (choice) {
         case 1:
             std::cout<<"\t\t\t Please Login  \n";
             std::cout<<"\t\t\t Enter Email    \n";
             std::cin>>email;
             std::cout<<"\t\t\t Enter Password \n";
             std::cin>>password;

            if (email == "administrator"&&password == "123456") {
                administrator();
            }else {
                std::cout<<"Invalid email/password";
            }
            break;
         case 2:
             buyer();
         case 3:
             exit(0);
         default:
             std::cout<<"Please select from the given options";
     }
    goto m;
 }

void shopping::administrator() {
     m:
     int choice;
     std::cout<<"\n\n\n\t\t\t Administrator menu";
     std::cout<<"\n\t\t\t|______1) Add the product_____|";
     std::cout<<"\n\t\t\t|                             |";
     std::cout<<"\n\t\t\t|______2) Modify the product__|";
     std::cout<<"\n\t\t\t|                             |";
     std::cout<<"\n\t\t\t|______3) Delete the product__|";
     std::cout<<"\n\t\t\t|                             |";
     std::cout<<"\n\t\t\t|______4) Back to main menu___|";

     std::cout<<"\n\n\t Please enter your choice!";
     std::cin>>choice;

     switch (choice) {
         case 1:
             add();
             break;
         case 2:
             edit();
             break;
         case 3:
             rem();
             break;
         case 4:
             menu();
             break;
         default:
             std::cout<<"Invalid choice";
     }
     goto m;
 }

void shopping::buyer() {
     m:
     int choice;
     std::cout<<"\t\t\t  Buyer";
     std::cout<<"\t\t\t_______________ \n";
     std::cout<<"\t\t\t                \n";
     std::cout<<"\t\t\t1) Buy product  \n";
     std::cout<<"\t\t\t                \n";
     std::cout<<"\t\t\t2)Go back       \n";
     std::cout<<"\t\t\t Enter your choice : ";

     std::cin>>choice;

     switch (choice) {
         case 1:
             receipt();
             break;
         case 2:
             menu();
             break;
         default:
             std::cout<<"Invalid choice";
     }
     goto m;
 }

void shopping::add() {
     m:
     std::fstream data;
     int c;
     int token=0;
     float p;
     float d;
     std::string n;

     std::cout<<"\n\n\t\t\t Add new product";
     std::cout<<"\n\n\t Product code of the product";
     std::cin>>pcode;
     std::cout<<"\n\n\t Name of the product";
     std::cin>>pname;
     std::cout<<"\n\n\t Price of the product";
     std::cin>>price;
     std::cout<<"\n\n\t Discount on product";
     std::cin>>dis;

     data.open("database.txt",std::ios::in);

     if(!data) {
         data.open("database.txt",std::ios::app|std::ios::out);
         data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
         data.close();
     }else {
         data>>c>>n>>p>>d;

         while (!data.eof()) {
             if (c==pcode) {
                 token++;
             }
             data>>c>>n>>p>>d;
         }
         data.close();

         if (token==1) {
             goto m;
         }else {
             data.open("database.txt",std::ios::app|std::ios::out);
             data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
             data.close();
         }
     }
     std::cout<<"\n\n\t\t Record inserted !";
 }

void shopping::edit() {
     std::fstream data,data1;
     int pkey;
     int token=0;
     int c;
     float p;
     float d;
     std::string n;

     std::cout<<"\n\t\t\t Modify the record";
     std::cout<<"\n\t\t\t Product code: ";
     std::cin>>pkey;

     data.open("database.txt",std::ios::in);
     if (!data) {
         std::cout<<"\n\nFile doesn't exist !";
     }else {
         data1.open("database1.txt",std::ios::app|std::ios::out);
         data>>pcode>>pname>>price>>dis;
         while (!data.eof()) {
            if (pkey==pcode) {
                std::cout<<"\n\t\t Product new code: ";
                std::cin>>c;
                std::cout<<"\n\t\t Name of the product: ";
                std::cin>>n;
                std::cout<<"\n\t\t Price of the product: ";
                std::cin>>p;
                std::cout<<"\n\t\t Discount on product: ";
                std::cin>>d;
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                std::cout<<"\n\n\t\t Record edited !";
                token++;
            }else {
                data1<<""<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
             data>>pcode>>pname>>price>>dis;
         }
         data.close();
         data1.close();

         remove("database.txt");
         rename("database1.txt","database.txt");

         if (token==0) {
             std::cout<<"\n\n Record not found sorry！";
         }
     }

 }

void shopping::rem() {
     std::fstream data,data1;
     int peky;
     int token=0;
     std::cout<<"\n\n\t Delete product";
     std::cout<<"\n\n\t Product code: ";
     std::cin>>peky;
     data.open("database.txt",std::ios::in);
     if (!data) {
         std::cout<<"\n\nFile doesn't exist !";
     }else {
         data1.open("database1.txt",std::ios::app|std::ios::out);
         data>>pcode>>pname>>price>>dis;
         while (!data.eof()) {
             if (pcode==peky) {
                 std::cout<<"\n\n\t Product deleted successfully";
                 token++;
             }else {
                 data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
             }
             data>>pcode>>pname>>price>>dis;
         }
         data.close();
         data1.close();
         remove("database.txt");
         rename("database1.txt","database.txt");
         if (token==0) {
            std::cout<<"\n\n Record not found";
         }
     }
 }

void shopping::list() {
     std::fstream data;
     data.open("database.txt",std::ios::in);
     std::cout<<"\n\n|__________________________________________|\n";
     std::cout<<"ProNO\t\tName\t\tPrice";
     std::cout<<"\n\n|__________________________________________|\n";
     data>>pcode>>pname>>price>>dis;
     while (!data.eof()) {
         std::cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
         data>>pcode>>pname>>price>>dis;
     }
     data.close();
 }

void shopping::receipt() {
     std::fstream data;
     int arrc[100];
     int arrq[100];
     char choice;
     int c=0;
     float amount=0;
     float dis=0;
     float total=0;

     std::cout<<"\n\n\t\t\t\t RECEIPT";
     data.open("database.txt",std::ios::in);
     if (!data) {
        std::cout<<"\n\n Empty database ";
     }else {
         data.close();
         list();
         std::cout<<"\n_______________________________\n";
         std::cout<<"\n|                              \n";
         std::cout<<"\n     Please place the order    \n";
         std::cout<<"\n|                              \n";
         std::cout<<"\n_______________________________\n";
         do {
             m:
             std::cout<<"\n\nEnter Product code :";
             std::cin>>arrc[c];

             std::cout<<"\n\nEnter the product quantity :";
             std::cin>>arrq[c];
             for (int i=0;i<c;i++) {
                 if (arrc[c]==arrc[i]) {
                     std::cout<<"\n\n Duplicate product code.Please try again! ";
                     goto m;
                 }
             }
             c++;
             std::cout<<"\n\n Do you want to buy another product?press y for yes and n for no";
             std::cin>>choice;
         }while (choice == 'y');

         std::cout<<"\n\n\t\t\t_________________________________RECEIPT____________________________________\n";
         std::cout<<"\nProduct No\t product Name\t product quantity\tprice\tAmount\tAmount with discount\n";
         for (int i=0;i<c;i++) {
             data.open("database.txt",std::ios::in);
             data>>pcode>>pname>>price>>dis;
             while (!data.eof()) {
                 if (pcode==arrc[i]) {
                     amount=price*arrq[i];
                     dis=amount-(amount*dis/100);
                     total=total+dis;
                     std::cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                 }
                 data>>pcode>>pname>>price>>dis;
             }
             data.close();
         }
     }
         std::cout<<"\n\n___________________________________";
         std::cout<<"\n Total Amount :"<<total;

}

int main() {
     shopping s;
     s.menu();


 }