#include<iostream>
#include<fstream>
#include<string>
#include<string.h>


using namespace std;


struct Carte
{
    char autor[256];
    char titlu[256];
    char boxa[5];
};

void citire(struct Carte a[],int *n)
{

    ifstream in("baza.txt");
    int i=0;
    while(!in.eof())
    {
        in.getline(a[i].autor,255);
        in.getline(a[i].titlu,255);
        in.getline(a[i].boxa,255);
        i++;

    }
    *n=i;

}

void afisare()
{
    char abc[255];
    ifstream in("baza.txt");
    while(!in.eof())
    {
        in.getline(abc,255);
        cout<<abc<<endl;
    }

}

void cautare_dupa_boxa(struct Carte a[],int n)
{
    int i;
    int j;
    cout<<"Introdu numarul boxei: ";
    cin>>j;
    for(int i=0; i<n; i++)
    {

        if(atoi(a[i].boxa)==j)
            cout<<endl<<a[i].autor<<endl<<a[i].titlu<<endl;
    }
}

void cautare_dupa_autor(struct Carte a[],int n)
{
    char nume[256];
    cout<<"introdu numele autorului: ";
    cin>>nume;
    for(int i=0;i<n;i++)
    {
        if(strstr(a[i].autor,nume)!=NULL)
            cout<<endl<<a[i].autor<<endl<<a[i].titlu<<endl<<a[i].boxa<<endl;
    }


}

void cautare_dupa_titlu(struct Carte a[],int n)
{
    char nume[256];
    cout<<"introdu numele cartii: ";
    cin>>nume;
    for(int i=0;i<n;i++)
    {
        if(strstr(a[i].titlu,nume)!=NULL)
            cout<<endl<<a[i].autor<<endl<<a[i].titlu<<endl<<a[i].boxa<<endl;
    }


}

void cautare_dupa_orice(struct Carte a[],int n)
{
    char orice[256];
    cin>>orice;
    for(int i=0;i<n;i++)
    {
        if((strstr(a[i].titlu,orice)!=NULL ) || (strstr(a[i].autor,orice)!=NULL ))
            cout<<endl<<a[i].autor<<endl<<a[i].titlu<<endl<<a[i].boxa<<endl;
    }

}


void meniu()
{
    cout<<endl<<"1.Cautare dupa titlu"<<endl<<"2.Cautare dupa Autor"<<endl<<"3.cautare dupa boxa"<<endl<<"4.Cautare dupa orice"<<endl<<"0.exit"<<endl;
}

int main()
{
    int n;
    struct Carte a[4000];
    int v=10;
    citire(a,&n);
    while(v)
    {
        meniu();
        cin>>v;
    switch(v)
    {
    case 1:
        cautare_dupa_titlu(a,n);
        break;
    case 2:
        cautare_dupa_autor(a,n);
        break;
    case 3:
        cautare_dupa_boxa(a,n);
        break;
    case 4:
        cautare_dupa_orice(a,n);
        break;
    case 0:
        break;

    }





    }

    //cautare_dupa_boxa(a,n);
    //cautare_dupa_autor(a,n);
    //cautare_dupa_titlu(a,n);
    //cautare_dupa_orice(a,n);
    //afisare();
}
