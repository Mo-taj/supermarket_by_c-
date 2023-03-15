#include <iostream>
#include<fstream>
#include<string.h>
using namespace std;
class supermarket{
        public:
        //data of the product.
        int id;
        double price;
        int expirydate;
        char productname[20];
        //data user
        char name[10];
        int phone;
        int num_product;
        char prod_order[20];
void add_items()   //to add a product to the supermarket (Write fun)
{
    ofstream out;
    out.open("supermarket.txt",ios::app);
    if(out.is_open())
    {
   supermarket s;
    int j;
    do
    {
    cout<<"\t\tEnter id\n\n"<<endl;
    cin>>s.id;
    cout<<"\t\tEnter productname\n\n"<<endl;
    cin>>s.productname;
    cout<<"\t\tEnter price\n\n"<<endl;
    cin>>s.price;
    cout<<"\t\tEnter expirydate\n\n"<<endl;
    cin>>s.expirydate;
    out.write((char*)&s,sizeof(s));
    cout<<"\t\t\t Enter 0 to exit :: Enter 1 to add\n\n";
    cin>>j;
    }
    while(j==1);
    out.close();
    }
    else
    {
        cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
    }
}
void show_items()           // to view products in the super market (Read fun).
  {
    int id=0;
    supermarket s;                 //object from the class
    ifstream in("supermarket.txt",ios::in);
    if(in.is_open())
      {     cout<<"\tid\tname\tprice\texpirydate\n\n"<<endl;
            while(!in.eof())
            {
            in.read((char*)&s,sizeof(s));
            if(s.id!=id){
            cout<<"\t"<<s.id<<"\t"<<s.productname<<"\t"<<s.price<<"\t"<<s.expirydate<<endl; id=s.id;}
            }

          in.close();
      }
         else
         {
            cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
         }

   }
   void show_orders() // to view orders (Read fun)
   {
      int j;
      int phone=0;
      supermarket b;   //object
      ifstream in("user_data.txt",ios::in);
      if(in.is_open())
      {     do

      {
      cout<<"\tproduct Name\tName\tmobile phone\ttotal number product\n\n"<<endl;
            while(!in.eof())
            {
            in.read((char*)&b,sizeof(b));
            if(b.phone!=phone){
      cout<<"\t"<<b.prod_order<<"\t"<<b.name<<"\t"<<"\t"<<b.phone<<"\t"<<b.num_product<<endl; phone=b.phone;}
            }
            cout<<"\t\t\t Enter 0 to Exit\n\n";
            cin>>j;

      }
          while(j==1);
          in.close();
      }
         else
         {
            cout<<"\t\t\t !!!!!!!!!!! cant found file  !!!!!!!!!!!\n\n"<<endl;
         }
   }

void searchitem()
{
    char str[20];
    cout<<"\t\t\tenter productname to search\n\n";
    cin>>str;

      supermarket s;
      ifstream in("supermarket.txt");
      if(in.is_open())
      {
          while(!in.eof()){
            in.read((char*)&s,sizeof(s));
            if(strcmp(s.productname,str)==0){
                cout<<"\tid\t\tname\t\tprice\t\texpirydate\n\n"<<endl;
                cout<<"\t"<<s.id<<"\t\t"<<s.productname<<"\t\t"<<s.price<<"\t\t"<<s.expirydate<<"\n\n\n";
            break;
          }
          }
          in.close();

      }
          else{
            cout<<"\t\t\tcannot open\n\n"<<endl;
          }

}


void book_order(){
	fstream f1,f2;
	supermarket s , b;
	f1.open("user_data.txt",ios::out|ios::in|ios::app);
	f2.open("supermarket.txt",ios::in);
		cout<<" Enter product Name : ";   //enter user data
		cin>>b.prod_order;
		cout<<" your Name : ";
		cin>>b.name;
		cout<<" mobile phone : ";
		cin>>b.phone;
		cout<<" total number product  : ";
		cin>>b.num_product;
		f1.write((char*)&b,sizeof(b));
		cout<<" _________________________________________________\n";

  /*************************************************************/

	int id=0;
	int flag=0;
	string str=b.prod_order;
	while(!f1.eof() || !f2.eof())             //view user data
    {
		f1.read((char*)&b,sizeof(b));
		f2.read((char*)&s,sizeof(s));
		if(s.id != id )
        {
	    	if(s.productname == str )
        {
            cout<<"\n\tReservation sucessful \n";
		   	cout<<"\n\tName : "<<b.name
		   	<<"\n\tNumber phone : "<<b.phone
		   	<<"\n\tproduct code : "<<s.id
		   	<<"\n\tproduct Name : "<<s.productname
		   	<<"\n\tTotal order : "<<b.num_product
		   	<<"\n\tTotal Amount : "<<(s.price)*(b.num_product)<<" EGP"<<"\n";
				cout<<"____________________________________________________\n";
		  	   flag=1;
	      }
	      id=s.id;
	   }
	}
	if(flag==0)
    {
		cout<<"\n\tthis order not found..!\n";
		cout<<" _________________________________________________\n";
	}
	/****************************************************************/
	f1.close();
	f2.close();
}
};
int main()
{
    supermarket x;
    int y;
    int f;
    int k , p;
    cout<<"\n\t\t===============SuperMarket================\n\n"<<endl;
    cout<<"\t\t\t1_Clint"<<"\n\n"<<"\t\t\t2_Seller\n\n"<<"\t\t______________chosse 1 or 2______________\n\n"<<endl;
    cin>>f;
    if(f==2)
    {
        cout<<"\t\t\tEnter password \n\n";
        cin>>k;
        if(k==123)
        do
    {
    cout<<"\n\t\t===============SuperMarket================\n\n"<<endl;
    cout<<"\t\t\tMAIN MENU\n\n"<<endl;
    cout<<"\t\t\t 1-Show all items\n\n"<<endl;
    cout<<"\t\t\t 2-Add new item\n\n"<<endl;
    cout<<"\t\t\t 3-Search for item\n\n"<<endl;
    cout<<"\t\t\t 4-orders\n\n"<<endl;
    cout<<"\t\t\t 0-exit\n\n"<<endl;
    cout<<"\t\t\t**chosse from ((0 to 4)**\n\n"<<endl;
    cin>>y;
    switch(y){
    case 1:
              x.show_items();
              cout<<"\n\n\t\t\tPress (0) Exit \n"
	  			  <<"\t\t\tPress (1) Return to the menu\n";

	  			   int p;   cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tExit!\n";
							return 0;
						}
	  		    	else{}
        break;
    case 2:
              x.add_items();
        break;
    case 3:
              x.searchitem();
              cout<<"__Press (0) Exit \n"
	  			  <<"__Press (1) Return\n";

	  			     cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return 0;
						}
	  		    	else{}

        break;
    case 4:
              x.show_orders();
              cout<<"\n\t\t\tPress (0) Exit \n"
	  			  <<"\t\t\tPress (1) Return\n\n";

	  			      cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return 0;
						}
	  		    	else{}
       break;
    case 0:
              cout<<"$$$$$$$$$$$$$$$$$$$ EXIT $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
         return 0;
         break;

    default:
              cout<<"/t/t/t!!!!!!error!!!!!!!"<<endl;
    }
    }
    while(y!=0);}else if(f==1)
    {
    do
    {
     cout<<"\n\t\t===============SuperMarket================\n\n"<<endl;
     cout<<"\t\t\tMAIN MENU\n\n"<<endl;
     cout<<"\t\t\t 1-Show all items\n\n"<<endl;
     cout<<"\t\t\t 2-Search for item\n\n"<<endl;
     cout<<"\t\t\t 3-Book Order\n\n"<<endl;
     cout<<"\t\t\t 0-exit\n\n"<<endl;
     cout<<"\t\t\t**chosse from ((0 to 3)**\n\n"<<endl;
     cin>>y;
    switch(y)
    {
    case 1:
              x.show_items();
              cout<<"\n\t\t\tPress (0) Exit \n"
	  			  <<"\t\t\tPress (1) Return\n\n";

	  			      cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return 0;
						}
	  		    	else{}
        break;

    case 2:
              x.searchitem();
                           cout<<"\n\t\t\tPress (0) Exit\n"
	  			           <<"\t\t\tPress (1) Return\n\n";

                            cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return 0;
						}
	  		    	else{}

        break;

    case 3:
              x.book_order();
              cout<<"\n\t\t\tPress (0) Exit \n"
	  			  <<"\t\t\tPress (1) Return\n\n";

	  			      cin>>p;
	  		  cout<<" _________________________________________________\n";
	  		    	if(p==0){
	  		    		cout<<"\t\t\tThank you !\n";
							return 0;
						}
	  		    	else{}
        break;

    case 0:
              cout<<"$$$$$$$$$$$$$$$$$$$ EXIT $$$$$$$$$$$$$$$$$$$$$$$"<<endl;
              return 0;
         break;
    default:
              cout<<"/t/t/t!!!!!!error!!!!!!!"<<endl;
    }
    }
    while(y!=4);}
    return 0;}