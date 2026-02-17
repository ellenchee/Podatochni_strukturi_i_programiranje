/*2. Да се провери дали во даден аритметички израз заградите се балансирани.
Пример: Балансирани загради {1+[2–5]+(2+{6*3})/1}
 Небалансирани загради {1+[2–5}+(2+{6*3})/1}*/
 #include <iostream>
 #include <string>
 using namespace std;
 int const MAX=20;
 struct element{
    char info; 
 };
 struct magacin{
    element niza[MAX];
    int top; 
    void init (){
        top=-1;
    }
    void overflow(){
        cout<<"overflow"<<endl;
        exit (-1);
    }
    void underflow(){
        cout<<"underflow"<<endl;
        exit (-1);
    }
    bool iEmp(){
        return top==-1;
    }
    bool iFull(){
        return top==(MAX-1);
    }
    void push (element e){
        if (top>(MAX-1)) overflow();
        niza[++top]=e;
    }
    element pop (){
        if (top<0) underflow();
        return niza[top--];
    }
    element peek (){
        if (top<0) underflow();
        return niza [top]; 
    }
 };
bool proveriZ (magacin &m, string izraz)
{
    m.init();
    for (int i=0; i<izraz.length(); i++)
    {
        if (izraz[i]== '{' || izraz[i]=='[' || izraz[i]=='(')
        {
            element e;
            e.info=izraz[i];
            m.push(e);
        }
        else if ( izraz[i]=='}')
            if (m.peek().info == '{') m.pop();
            else return false; 
        else if ( izraz[i]==']')
            if (m.peek().info=='[') m.pop();
            else return false;
        else if (izraz[i]==')')
            if (m.peek().info=='(') m.pop();
            else return false;
    }
    if (m.iEmp()) return true;
    else return false;
}
 int main ()
 {
    magacin mag;
    string izraz; 
    cout<<"vnesi aritmeticki izraz: "<<endl;
    cin>>izraz;
    if (proveriZ(mag, izraz))
        cout<<"izrazot ima balansirani zagradi"<<endl;
    else 
        cout<<"izrazot nema balansirani zagradi"<<endl;
 }