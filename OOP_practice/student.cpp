#include <iostream>
#include <string>
using namespace std;

class Student
{
    private:
    
        int rollnum;
        string name;
        int math_marks;
        int phy_marks;
        int chem_marks;
    
    public:

        Student(int r, string n, int m, int p, int c)
        {
            rollnum = r;
            name = n;
            math_marks = m;
            phy_marks = p;
            chem_marks = c;
        }

        int total_marks()
        {
            return math_marks+phy_marks+chem_marks;
        }

        char Grade()
        {
            float average = total_marks()/3;
            if(average > 60)
                return 'A';
            else if(40 <= average && average <= 60)
                return 'B';
            else
                return 'C'; 
        }
};

int main()
{
    int rollnum;
    string name;
    int m,p,c;
    cout << " Please enter the rollnum " << endl;
    cin >> rollnum;
    cout << " Please enter the name " << endl;
    cin >> name;
    cout << " Please enter the marsk in maths, physics, chem respectively " << endl;
    cin >> m >> p >> c;
    Student s(rollnum, name ,m , p ,c);
    cout << "Toatal Marks " << s.total_marks() << endl;
    cout << "Grade " << s.Grade();

}