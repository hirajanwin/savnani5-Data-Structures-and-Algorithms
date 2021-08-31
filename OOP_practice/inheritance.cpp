#include <iostream>
#include <string>
using namespace std;

class Employee
{
    private:
        int eid;
        string name;
    
    public:
        Employee(int e, string n)
        {
            eid = e;
            name = n;
        }
        void setEid(int e)
        {
            eid = e;
        }
        void setName(int n)
        {
            name = n;
        }        
        int geteid()
        {
            return eid;
        }
        string getname()
        {
            return name;
        }
};

class Ftemployee : public Employee
{
    private:
        int salary;
    
    public:
        Ftemployee(int e, string n, int s): Employee(e,n)
        {
            salary = s;
        }
        int getsalary()
        {
            return salary;
        }
};

class Ptemployee : public Employee
{
    private:
        int wage;
    
    public:
        Ptemployee(int e, string n, int w): Employee(e,n)
        {
            wage = w;
        }
        int getwage()
        {
            return wage;
        }
};

int main()
{
    Ftemployee f(12, "Paras", 1000);
    Ptemployee p(13, "Tony", 1500);
    cout << "Salary of Paras is " << f.getsalary() << endl << "Salary of Tony is " << p.getwage() << endl; 
}