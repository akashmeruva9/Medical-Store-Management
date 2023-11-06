#include <bits/stdc++.h>
using namespace std;

class Medicine
{
public:
    int id, price, quantity;
    char medicneName[100], Company[100], Mfg_Date[11], Exp_Date[11], info[5000];
};

class Medicine m[100];

void PurchaseMedicine(int number);
void EnterInfoAboutMedicine(int number);
void StockOfMedicine(int number);
void KnowInfoAboutMedicine(int number);
void AddMedicineinStore(int number, struct Medicine m[]);
void DeleteMedicineStore(int number);
void ChangeMedicineDetails(int number);

int main()
{
    int i, j, choice, number = 0, c;
    for (i = 0; i < 100; i++)
    {
        m[i].id = 0;
        m[i].price = 0;
        m[i].quantity = 0;
        strcpy(m[i].Mfg_Date, "");
        strcpy(m[i].Exp_Date, "");
        strcpy(m[i].medicneName, "");
        strcpy(m[i].Company, "");
        strcpy(m[i].info, "");
    }
    m[0].id = 1;
    m[0].price = 120;
    m[0].quantity = 30;
    strcpy(m[0].Mfg_Date, "23-04-2016");
    strcpy(m[0].Exp_Date, "24-04-2020");
    strcpy(m[0].medicneName, "Paracetmol");
    strcpy(m[0].Company, "ABCD");
    strcpy(m[0].info, "Good Medicine for Fever");
    do
    {
        cout<<endl<<endl<<"---- SRM AP MEDICAL STORE ----"<<endl<<endl;
        cout<<"Enter\n1 - Purchase Medicine\n2 - Enter Information about a Medicine\n3 - Stock of Medicine in Store\n4 - Medicine Information\n5 - Add Medicine\n6 - Delete a Medicine\n7 - Change Quantity of Medicine\n";
        cin>>choice;

        switch (choice)
        {
        case 1:
        {
            PurchaseMedicine(number + 1);
            break;
        }
        case 2:
        {
            EnterInfoAboutMedicine(number + 1);
            break;
        }
        case 3:
        {
            StockOfMedicine(number + 1);
            break;
        }
        case 4:
        {
            KnowInfoAboutMedicine(number + 1);
            break;
        }
        case 5:
        {
            ++number;
            AddMedicineinStore(number, m);
            break;
        }
        case 6:
        {
            DeleteMedicineStore(number + 1);
            break;
        }
        case 7:
        {
            ChangeMedicineDetails(number + 1);
            break;
        }
        }
        cout<<"To Continue with other Options Enter 1 Else any other number\n";
        cin>>c;
    } while (c == 1);
}


void PurchaseMedicine(int number)
{
    int id, check, i, quantity, flag = 0;
    char name[100];
    cout<<"Enter 1 if you know ID else any other number to enter Name of Medicine"<<endl;
    fflush(stdin);
    cin>>check;

    if (check == 1)
    {
        cout<<"Enter Id to purchase Medicine"<<endl;
        fflush(stdin);
        cin>>id;

        for (i = 0; i < number; i++)
        {
            if (m[i].id == id)
            {
                flag = 1;
                int c;
                cout<<"These are the details of Medicine"<<endl;
                cout<<"Name"<<m[i].medicneName<<endl<<"Price="<< m[i].price<<endl<<"Available Quantity="<< m[i].quantity<<endl<<"Company="<< m[i].Company<<endl<<"Mfg Date="<<m[i].Mfg_Date<<endl<<"Exp Date="<< m[i].Exp_Date<<endl;
                if (strcmp(m[i].info, "") == 0)
                {
                    cout<<"Medicine Review/Info=Not Available"<<endl;
                }
                else
                {
                    cout<<"Medicine Review/Info="<<m[i].info<<endl;
                }
                cout<<"Do you want to purchase"<<m[i].medicneName<<endl<<"If Yes Enter 1 else any other number"<<endl;
                fflush(stdin);
                cin>>c;
                if (c == 1)
                {
                    cout<<"Enter Quantity to Purchase"<<endl;
                    cin>>quantity;
                    if (m[i].quantity > quantity)
                    {
                        cout<<"Total Price to be paid="<<quantity * m[i].price<<endl;
                    }
                    else
                    {
                        cout<<"Please Enter quantity below Available Quantity"<<endl;
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            cout<<"Entered Id Not Found"<<endl;
        }
    }
    else
    {
        cout<<"Enter Name to search and Purchase"<<endl;
        fflush(stdin);
        gets(name);
        for (i = 0; i < number; i++)
        {
            if (strcmp(m[i].medicneName, name) == 0)
            {
                flag = 1;
                int c;
                cout<<"These are the details of Medicine"<<endl;
                cout<<"Name="<<m[i].medicneName<<endl<<"Price="<<m[i].price<<endl<<"Available Quantity="<<m[i].quantity<<endl<<"Company="<<m[i].Company<<endl<<"Mfg Date="<<m[i].Mfg_Date<<endl<<"Exp Date="<<m[i].Exp_Date<<endl;
                if (strcmp(m[i].info, "") == 0)
                {
                    cout<<"Medicine Review/Info=Not Available"<<endl;
                }
                else
                {
                    cout<<"Medicine Review/Info="<< m[i].info<<endl;
                }
                cout<<"Do you want to purchase"<<m[i].medicneName<<endl<<"If Yes Enter 1 else any other number"<<endl;
                fflush(stdin);
                cin>>c;
                if (c == 1)
                {
                    cout<<"Enter Quantity to Purchase"<<endl;
                    cin>>quantity;
                    if (m[i].quantity > quantity)
                    {
                        cout<<"Total Price to be paid="<<quantity * m[i].price<<endl;
                    }
                    else
                    {
                        cout<<"Please Enter quantity below Available Quantity"<<endl;
                    }
                }
                break;
            }
        }
        if (flag == 0)
        {
            cout<<"Entered Name Not Found"<<endl;
        }
    }
}

void EnterInfoAboutMedicine(int number)
{
    int i, flag = 0, c;
    char name[100], info[100];
    cout<<"Enter Name of the medicine you want to Review or include Info"<<endl;
    fflush(stdin);
    gets(name);
    for (i = 0; i < number; i++)
    {
        if (strcmp(m[i].medicneName, name) == 0)
        {
            flag = 1;
            cout<<"These are the details of Medicine"<<endl;
            cout<<"Name="<<m[i].medicneName<< endl <<"Price="<<m[i].price<<endl<<"Available Quantity="<<m[i].quantity<< endl <<"Company="<<m[i].Company<< endl <<"Mfg Date="<<m[i].Mfg_Date<< endl <<"Exp Date="<< m[i].Exp_Date<< endl;
            if (strcmp(m[i].info, "") != 0)
            {
                cout<<"Review Already Available!\nIf you want to Add a Review Enter 1 else Any other number"<<endl;
                fflush(stdin);
                cin>>c;
            }
            else
            {
                cout<<"Enter review(less than 100 Characters)"<<endl;
                fflush(stdin);
                gets(m[i].info);
            }
            if (c == 1)
            {
                cout<<"Enter review(less than 100 Characters)"<<endl;
                fflush(stdin);
                gets(info);
                strcat(m[i].info, "; ");
                strcat(m[i].info, info);
            }
        }
    }
    if (flag == 0)
    {
        cout<<"Entered Name Not Found"<<endl;
    }
}


void KnowInfoAboutMedicine(int number)
{
    int i, flag = 0;
    char name[100];
    cout<<"Enter Name of the medicine you want to see Review and Info"<<endl;
    fflush(stdin);
    gets(name);
    for (i = 0; i < number; i++)
    {
        if (strcmp(m[i].medicneName, name) == 0)
        {
            flag = 1;
            cout<<"These are the details of Medicine"<<endl;
            cout<<"Name="<<m[i].medicneName<<endl<<"Price="<<m[i].price<<endl<<"Available Quantity="<<m[i].quantity<<endl<<"Company="<<m[i].Company<<endl<<"Mfg Date="<<m[i].Mfg_Date<<endl<<"Exp Date="<<m[i].Exp_Date<<endl;
            if (strcmp(m[i].info, "") != 0)
            {
                cout<<"Review or Info="<<m[i].info<<endl;
            }
            else
            {
                cout<<"Review or Info=Not Available"<<endl;
            }
        }
    }
    if (flag == 0)
    {
        cout<<"Entered Name Not Found"<<endl;
    }
}


void StockOfMedicine(int number)
{
    int i;
    if (number != 0)
    {
        cout<<"All Available Items are"<<endl;
        for (i = 0; i < number; i++)
        {
            if (m[i].id != 0)
            {
                cout<<"Id="<<m[i].id<<endl<<"Name="<<m[i].medicneName<<"\t\tPrice="<<m[i].price<<"\tAvailable Quantity="<<m[i].quantity<<endl<<"Company="<<m[i].Company<<"\t\tMfg Date="<<m[i].Mfg_Date<<"\tExp Date="<<m[i].Exp_Date<<endl;
                if (strcmp(m[i].info, "") != 0)
                {
                    cout<<"Review or Info="<<m[i].info<<endl;
                }
                else
                {
                    cout<<"Review or Info=Not Available"<<endl;
                }
            }
        }
    }
    else
    {
        cout<<"No Items or Medicines Available"<<endl;
    }
}


void AddMedicineinStore(int number, struct Medicine m[])
{
    char name[100];
    cout<<"Enter Medicine Id"<<endl;
    cin>>m[number].id;
    fflush(stdin);
    cout<<"Enter Medicine Name"<<endl;
    fflush(stdin);
    gets(name);
    strcpy(m[number].medicneName, name);
    cout<<"Enter Company Name"<<endl;
    fflush(stdin);
    gets(m[number].Company);
    cout<<"Enter Manufactured Date"<<endl;
    fflush(stdin);
    gets(m[number].Mfg_Date);
    cout<<"Enter Expiry Date"<<endl;
    fflush(stdin);
    gets(m[number].Exp_Date);
    cout<<"Enter Quantity"<<endl;
    fflush(stdin);
    cin>>m[number].quantity;
    cout<<"Enter Price"<<endl;
    fflush(stdin);
    cin>>m[number].price;
    strcpy(m[number].info, "");
    cout<<"Medicine with id"<<m[number].id<<"Added Successfully"<<endl; 
}

void DeleteMedicineStore(int number)
{
    int id, i, flag = 0, num;
    cout<<"Enter Id to be deleted"<<endl;
    fflush(stdin);
    cin>>id;
    for (i = 0; i < number; i++)
    {
        if (m[i].id == id)
        {
            flag = 1;
            m[i].id = 0;
            m[i].price = 0;
            m[i].quantity = 0;
            strcpy(m[i].medicneName, "");
            strcpy(m[i].Company, "");
            strcpy(m[i].Mfg_Date, "");
            strcpy(m[i].Exp_Date, "");
            strcpy(m[i].info, "");
            num = i;
            break;
        }
    }
    if (flag == 1)
    {
        cout<<"Medicine with "<<id<<" is Deleted Successfully"<<endl;
    }
}

void ChangeMedicineDetails(int number)
{
    int id, quantity, choice, c, i;
    cout<<"Enter id to change Details"<<endl;
    cin>>id;
    for (i = 0; i < number; i++)
    {
        if (m[i].id == id && m[i].id != 0)
        {
            do
            {
                cout<<"Enter\n1 - Change Quantity\n2 - Change Price\n3 - Change Name\n4 - Change Company\n5 - Change Manufaturing Date\n6 - Change Expiry Date\n7 - Change Info\nAny other number to exit";
                cin>>choice;
                if (choice == 1)
                {
                    int quantity;
                    cout<<"Enter Quantity to be changed"<<endl;
                    fflush(stdin);
                    cin>>quantity;
                    m[i].quantity = quantity;
                    cout<<"Quantity changed Successfully"<<endl;
                }
                if (choice == 2)
                {
                    int price;
                    cout<<"Enter Price to be changed"<<endl;
                    fflush(stdin);
                    cin>>price;
                    m[i].price = price;
                    cout<<"Price changed Successfully"<<endl;
                }
                if (choice == 3)
                {
                    char name[100];
                    cout<<"Enter Name to be changed"<<endl;
                    fflush(stdin);
                    gets(name);
                    strcpy(m[i].medicneName, name);
                    cout<<"Medicine Name changed Successfully"<<endl;
                }
                if (choice == 4)
                {
                    char company[100];
                    cout<<"Enter company to be changed"<<endl;
                    fflush(stdin);
                    gets(company);
                    strcpy(m[i].Company, company);
                    cout<<"Company changed Successfully"<<endl;
                }
                if (choice == 5)
                {
                    char mfg[11];
                    cout<<"Enter Manufacturing date to be changed"<<endl;
                    fflush(stdin);
                    gets(mfg);
                    strcpy(m[i].Mfg_Date, mfg);
                    cout<<"Manufacturing Date changed Successfully"<<endl;
                }
                if (choice == 6)
                {
                    char exp[11];
                    cout<<"Enter Expiry date to be changed"<<endl;
                    fflush(stdin);
                    gets(exp);
                    strcpy(m[i].Exp_Date, exp);
                    cout<<"Expiry Date changed Successfully"<<endl;
                }
                if (choice == 7)
                {
                    char info[100];
                    cout<<"Enter Info to be changed(Less than 100 Characters)"<<endl;
                    fflush(stdin);
                    gets(info);
                    strcpy(m[i].info, info);
                    cout<<"Info changed Successfully"<<endl;
                }
                if (choice <= 0 && choice > 7)
                {
                    cout<<"Enter valid Choice"<<endl;
                }
                cout<<"Enter 1 to Change other Details Else any other number"<<endl;
                fflush(stdin);
                cin>>c;
            } while (c == 1);

            break;
        }
    }
}
