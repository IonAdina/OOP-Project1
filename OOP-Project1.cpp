//nr3 v1
#include <iostream>
using namespace std;

class Vector{
    int v[100],n;
public:
    void get_citire(){
        cout<<"Dati nr elem:";
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>v[i];
    }
    void get_afisare(){
        for(int i=1;i<=n;i++)
            cout<<v[i]<<" ";
            cout<<endl;
    }
    Vector(int x=0,int n=0);
    Vector1(){}
    Vector(const Vector& ob);
    ~Vector();
    Vector& operator=(const Vector&);
    void React(int y,int m);
    void suma();
    void sortare();
    void maxi();
    friend istream& operator >> (istream&,Vector&);
    friend ostream& operator << (ostream&,Vector&);
    Vector& operator+(int);
    Vector operator+(Vector& ob);
    friend Vector& operator+(int,Vector&);
    friend int operator<(Vector&,Vector&);
    int Dinamism();
};

istream& operator>>(istream& in,Vector& ob){
    int n;
    for(int i;i<=n;i++)
        in>>ob.v[i];
    return in;
}
ostream& operator<<(ostream& out,Vector& ob){
    int n;
    for(int i;i<=n;i++)
        out<<ob.v[i]<<" ";
    return out;
}

Vector& Vector::operator+(int x){
    for(int i=1;i<=n;i++)
        this->v[i]=this->v[i]+x;
    return *this;
}

Vector& operator+(int x,Vector& ob){
    int n;
    for(int i=1;i<=n;i++)
        ob.v[i]=ob.v[i]+x;
    return ob;
}

int operator<(Vector& x,Vector& y)
    {
        return x<y;
    }

Vector::Vector(int x,int n){
    for(int i=1;i<=n;i++)
        v[i]=x;
}

Vector::Vector(const Vector& ob){
    for(int i=1;i<=n;i++)
        v[i]=ob.v[i];
}

Vector::~Vector(){
    for(int i=1;i<=n;i++)
        v[i]=0;
}

Vector& Vector::operator=(const Vector& ob){
    for(int i=1;i<=n;i++)
        if (this!=&ob)
            this->v[i]=ob.v[i];
    return *this;
}

void Vector::suma(){
    int s=0;
    for(int i=1;i<=n;i++)
        s=s+v[i];
    cout<<"suma elem vectorului este:"<<s<<endl;
}

void Vector::React(int y,int m){
    for(int i=1;i<=y;i++)
        v[i]=m;
    cout<<"noul vector dupa reactualizare este:";
    for(int i=1;i<=y;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void Vector::sortare(){
    int aux;
    for(int i=1;i<=n-1;i++)
        for(int j=i+1;j<=n;j++)
            if(v[i]>v[j])
                {
                    aux=v[i];
                    v[i]=v[j];
                    v[j]=aux;
                }
    cout<<"Ordonarea crescatoare a vectorului este:";
    for(int i=1;i<=n;i++)
        cout<<v[i]<<" ";
    cout<<endl;
}

void Vector::maxi(){
    int maxim=0,poz=0;
    for(int i=1;i<=n;i++)
        if(v[i]>maxim)
        {
            maxim=v[i];
            poz=i;
        }

    cout<<"Maximul din vector este "<<maxim<<"si se afla pe pozitia "<<poz<<endl;
}

int main(){
    Vector x;
    x.Dinamism();
}

int Vector::Dinamism(){
    Vector D;
    D.get_citire();
    D.get_afisare();
    D.suma();
    D.maxi();
    D.sortare();
    int y,m;
    cout<<"dati y:";
    cin>>y;
    cout<<"dati m:";
    cin>>m;
    D.React(y,m);
    char choice;
    char choice1;
    cout<<" What do you want? "<<endl;
    cout<<"stay(s) or cancel(c): ";
    cin>>choice;
    while(choice != 'c'& choice=='s')
    {
        if(choice=='s')
        {
            Vector A;
            A.get_citire();
            A.get_afisare();
            cout<<"What now ? (Suma-u or Maxi-m or Ordonare/Sortare-o or Reactualizare-Vector-r) : ";
            cin>>choice1;
            if(choice1=='u')
                A.suma();
            else if(choice1=='m')
                A.maxi();
            else if(choice1=='o')
                A.sortare();
            else if(choice1=='r')
                {
                cout<<"dati y:";
                cin>>y;
                cout<<"dati m:";
                cin>>m;
                A.React(y,m);
                }
        }
        else if(choice=='c'||choice!='c')
        return 0;
        cout<<"What now? "<<endl;
        cout<<"stay(s) or cancel(c): ";
        cin>>choice;
    }
}

