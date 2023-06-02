#include<iostream>
#include<fstream>

using namespace std;

class shopping
{
    private:
      int pcode;
      float price;
      float dis;
      string pname;

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

void shopping :: menu()
{ 
    m:
    int choice;
    string email;
    string password;

    cout<<"\t\t\t\t_________________________________________\n";
    cout<<"\t\t\t\t_________________________________________\n";
    cout<<"\t\t\t           Supermarket Menu                 \n";
    cout<<"\t\t\t                                            \n";
    cout<<"\t\t\t\t_________________________________________ \n";
    cout<<"\t\t\t\t                                         \n";
    cout<<"\t\t\t|  1)Administrator  |\n";
    cout<<"\t\t\t|                   |\n";
    cout<<"\t\t\t|  2)Buyer          |\n";
    cout<<"\t\t\t|                   |\n";
    cout<<"\t\t\t|  3)Exit           |\n";
    cout<<"\t\t\t|                   |\n";
    cout<<"\t\tPlease Select!!";
    cin>>choice;
    switch(choice)
    {
        case 1: 
        cout<<"\t\t\t Please login \n";
        cout<<"\t\t\t Enter email:  \n";
        cin>>email;
        cout<<"\t\t\t Enter password: \n";
        cin>>password;
        if(email=="raghuwnashiaditi6@gmail.com" && password=="aditi188")
        {
            administrator();
        }
        else
       {
          cout<<"invalid email/password";
        }
        break;
        
        case 2:
        {
            buyer();
        }
        
        case 3:
        {
            exit(0);
        }
        
        default:
    {
        cout<<"please select from the given options ";
        
    }
        

    }
    
    

goto m;
}

void shopping :: administrator()
{
    m:
    int choice;
    cout<<"\n\n\t\t\t Administrator menu";
    cout<<"\n\n\t\t\t| 1) Add the product_______|";
    cout<<"\n\n\t\t\t|                          |";
    cout<<"\n\n\t\t\t| 2) Modify the product_______|";
    cout<<"\n\n\t\t\t|                          |";
    cout<<"\n\n\t\t\t| 3) Delete the product_______|";
    cout<<"\n\n\t\t\t|                             |";
    cout<<"\n\n\t\t\t| 4) Back to the menu_______|";
    
    cout<<"\n\n\t Please enter your choice";
    cin>>choice;
    
    switch(choice)
    {
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
        
        default :
        cout<<"invalid choice";
        
        
    }
    goto m;
    
}
 
 
void shopping :: buyer()
{
    m:
    int choice;
    cout<<"\t\t\t  Buyer \n";
    cout<<"\t\t\t_______________________ \n";
    cout<<"\t\t\t 1) Buy product \n";
    cout<<"                     \n";
    cout<<"\t\t\t 2) Go back    \n";
    cout<<"\t\t\t Enter your choice : ";
   
    switch(choice)
    {
        case 1:
        receipt();
        break;
        
        case 2:
        menu();
        break;
        
        default :
        cout<<"invalid choice";
        
    }
    
     
    goto m;
}
  
  
void shopping :: add()
{
    m:
    fstream data;
    int c;
    int token=0;
    float p;
    float d;
    string n;
    
    cout<<"\n\n\t\t\t Add new product";
    cout<<"\n\n\t Product code of the product";
    cin>>pcode;
    cout<<"\n\n\t Name of the product";
    cin>>pname;
    cout<<"\n\n\t Price of the product";
    cin>>price;
    cout<<"\n\n\t Discount on the product";
    cin>>dis;
    
    data.open("database.txt", ios::in);
    if(!data)
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
        /*if block will run when file does not exist nd we have to make it*/
    }
    else
    {
        data>>c>>n>>p>>d;
        /*these are reading from the files here we are initializing the files bcoz we need while loop to iterate 
        through the files*/
        while(!data.eof())
        {
            if(c == pcode)
            {
                token++;
                /*here it is written that ki jb data end of file fun pr pouch jaye tb end krdenge or code jb pcode
                k duplicate hua toh usko increment krenge by one abhi wo initialize h by zero*/
            }
            data>>c>>n>>p>>d;
        }
        data.close();
    }
    /*jb product duplicate hoto if nhi to else*/
    if(token==1)
    {
        goto m;
    }
    else
    {
        data.open("database.txt", ios::app|ios::out);
        data<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
        data.close();
    }
    
    cout<<"\n\n\t Record inserted !";
}

void shopping :: edit()
{
    fstream data, data1; /*two objects of fstream class*/
    int pkey;
    int token=0;
    int c;
    float p;
    float d;
    string n;
    
    cout<<"\n\t\t\t Modify the record";
    cout<<"\n\t\t\t enter the product code : ";
    cin>>pkey;
    
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\nfile does not exit! ";
    } 
    /*now in else we will open the file but not this file other file with the help of 
    object data1*/
    else
    {
        data1.open("database1.txt", ios::app|ios::out);
        /*modify krke isme dalenge or rename krenge as database.txt*/
        data>>pcode>>pname>>price>>dis;
        while(!data.eof())
        {
            if(pkey==pcode)
            /*pkey entered data jo administrator ne dala match krne k lie*/
            {
                cout<<"\n\t\t Product new code";
                cin>>c;
                cout<<"\n\t\t Enter the name of product";
                cin>>n;
                cout<<"\n\t\t Enter the price of product";
                cin>>p;
                /*now all the updated details will be entered using data1 object , data data1 aree objects*/
                data1<<" "<<c<<" "<<n<<" "<<p<<" "<<d<<"\n";
                cout<<"\n\n\t\t Record edited !";
                token++;
                
            }
            
            else
            {
                /*if the product code dosen't matches with any of the product file*/
                data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
            }
            data>>pcode>>pname>>price>>dis;
            
        }
        data.close();
        data1.close();
        /*humne database1 me edit krke dala tha jo nhi tha ab humko wps rename krna h database1 ko data me to 
        ab hum function bnayenge hum do function bnayenge remove or renname remove me list ko remove krenge that is 
        database.txt file h and then rename me rename krenge database1.txt ko database.txt me
        */
        remove("database.txt");
        rename("database1.txt" , "database.txt");
        
        if(token==0)
        {
            cout<<"\n\n Record not found !";
        }
        }
        
    
}

void shopping::rem()
{
    fstream data,data1;
    int pkey;
    int token=0;
    cout<<"\n\n\t Delete product";
    cout<<"\n\n\t Enter the product code : ";
    cin>>pkey;
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"does not exist";
    }
    else
    {
        data1.open("database1.txt",ios::app|ios::out);
        data>>pcode>>pname>>price>>dis;
        //read from the file
        while(!data.eof())
        {
            if(pcode==pkey)
            {
                cout<<"\n\n\t product deleted successfully";
                token++;
                }
                else
                {
                    data1<<" "<<pcode<<" "<<pname<<" "<<price<<" "<<dis<<"\n";
                    //if pcode matches pkey product will be deleted if not else will be executed and database1 
                    //file be displayed all the other product will be displayed unko chhodkr jinko del krna hai 
                    //so we will show this file as database1 and rename as database
                    
                    
                }
                 data>>pcode>>pname>>price>>dis;
                 //this follows the iteration of while loop
        }
        data.close();
        data1.close();
        remove("database.txt");
        rename("database1.txt" , "database.txt");
        
        if(token==0)
        {
            cout<<"\n\n\t Record cannot found :) ";
        }
    }
}

void shopping:: list() //it will help us to show list to the buyer
{
    fstream data;
    data.open("database.txt",ios::in);
    cout<<"\n\n|______________________________________________________\n";
    cout<<"Prono\t\tName\t\tPrice\n";
    cout<<"\n\n|______________________________________________________\n";
    data>>pcode>>pname>>price>>dis;
    while(!data.eof())
    {
        cout<<pcode<<"\t\t"<<pname<<"\t\t"<<price<<"\n";
        data>>pcode>>pname>>price>>dis;
    
    }
        data.close();
        
    
}
void shopping::receipt()
{
    //isme array ayege bcoz we need to store multiple prodct keys and multiple quantities of those products
    
    fstream data;
    int arrc[100];//array c mtlb array of code
    int arrq[100];//array q quantity
    char choice;
    int c=0;//counter var
    float amount=0;
    float dis=0;
    float total=0;
    
    cout<<"\n\n\n\t\t RECEIPT";
    //file open krenge and check ki wo exist krti h ki nhi
    data.open("database.txt",ios::in);
    if(!data)
    {
        cout<<"\n\n Empty database";
    }
    else
    {
        data.close();
        list();
        cout<<"\n____________________________________________\n";
        cout<<"\n|                                           \n";
        cout<<"\n         please place the order             \n";    
        cout<<"\n____________________________________________\n";
        //we are using do while loop and the purpose of it is bcoz we need to run specific part of the code
        //other part of the code we need to run by the choice
        
        do
        {
            m:
            //in do we say usser to enter pro code and quantity
            cout<<"\n\n enter the product code:";
            cin>>arrc[c];
            cout<<"\n\n enter the product quantity:";
            cin>>arrq[c];
            //chacking for duplicacy
            for(int i=0;i<c;i++)
            {
                if(arrc[c]==arrc[i]) //check krega product code alreaduy jo entered h or jo user enter kr rha wo match honge
                //to duplicate h i ye iterate krega
                {
                    cout<<"\n\nduplicate product code please try again :)";
                    goto m;
                }
            }
            c++;
            //duplicate nhi h to counter increment hoga
            cout<<"\n\n Do you want to buy another product . if yes then press y else no";
            cin>>choice;
            
            
        }
        while(choice=="y");
        //if user presses y then this loop will executed
        cout<<"\n\n\t\t\t____________________RECEIPT______________\n";
        cout<<"\nproduct no\t product name\t product quantity\tprice\tamount\tamount with discount";
        
        for(int i=0;i<c;i++)
        {
           data.open("database.txt",ios::in);
           data>>pcode>>pname>>price>>dis;
           while(!data.eof())
           {
               //we are matching that the file entered by the customer and the arr[i] are matching arrc[c]==arrc[i]
               //then we will do cal and add in customer basket
               if(pcode==arrc[i])
               {
                   amount=price*arrq[i];
                  dis=amount-(amount*dis/100);
                  total=total+dis;
                  cout<<"\n"<<pcode<<"\t\t"<<pname<<"\t\t"<<arrq[i]<<"\t\t"<<price<<"\t\t"<<amount<<"\t\t"<<dis;
                  
                   
               }
               data>>pcode>>pname>>price>>dis;
           }
        }
        data.close();
        
    }
    cout<<"\n\n_______________________________________________\n";
    cout<<"\n\n         total amount : "<<total;
    
    
    
}

int main()
{
    shopping s;
    s.menu();
    
}











