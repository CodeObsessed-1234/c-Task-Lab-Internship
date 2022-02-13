#include <iostream>
#include <vector>
#include<stdlib.h>
#include<algorithm>
#include"function.h"
using namespace std;


//Derived Employee Class
class employeeManagment: public orginization
{
    public:
        orginization emp;
        void AddEmployee(char choice)
        {
            emp.Add(choice);
        }
        void EditEmployee(char choice,int id)
        {
            emp.Edit(choice,id);
        }
        void DeleteEmployee(char choice,int id)
        {
            emp.Delete(choice,id);
        }
        void EmployeeList(char choice)
        {
            emp.List(choice);
        }

        void SortEmployeeAge(char choice){
            emp.Sort(choice);
        }
        void SearchEmployeeByID(char choice){
            emp.Search(choice);
        }
};

//Derived Department Class
class departmentManagment: public orginization
{
    public:
        orginization dep;
        void AddDepartment(char choice)
        {
            dep.Add(choice);
            
        }
        void EditDepartment(char choice,int id)
        {
            dep.Edit(choice,id);

        }
        void DeleteDepartment(char choice,int id)
        {
            dep.Delete(choice,id);
        }
        void ListDepartment(char choice)
        {
             dep.List(choice);
        }
        void SortDepartment(char choice){
            dep.Sort(choice);
        }
        void SearchDepartmentByID(char choice){
            dep.Search(choice);
        }
};

// Execution start from here
int main()
{
    int dep_choice, emp_choice, ID_check;
    char choice;
    employeeManagment emp;// object of employeeManagment Class
    departmentManagment dep;// object of departmentMangment Class
    while (true)
    {
        cout << "Press D for Department\n"<< "Press E for Employee\n"<< "Press Any Key for Exit"<< "\n";
        cout << endl;
        cout << "Enter Choice:- ";
        cin >> choice;
        if (choice == 'e' || choice == 'E')
        {
            while (true)
            {
                cout << endl;
                cout << "\nPress 1 for Add Employee\n"<< "Press 2 for Edit Employee\n"<< "Press 3 for Delete Employee\n"<< "Press 4 for All Employees\n"<<"Press 5 for Sorting By Age\n"<<"Press 6 for Searching\n"<< "Press -1 for exit\n\n";
                cout << "Enter Emp_choice:- ";
                cin >> emp_choice;
                cout << endl;
                if (emp_choice == 1)
                {
                    emp.AddEmployee(choice);
                }
                else if (emp_choice == 2)
                {
                    cout << "Enter ID:- ";
                    cin >> ID_check;
                    emp.EditEmployee(choice,ID_check);
                }
                else if (emp_choice == 3)
                {
                    cout << "Enter ID:- ";
                    cin >> ID_check;
                    emp.DeleteEmployee(choice,ID_check);
                }
                else if (emp_choice == 4)
                {
                    emp.EmployeeList(choice);
                }
                else if(emp_choice == 5){
                    emp.SortEmployeeAge(choice);
                }
                else if(emp_choice == 6){
                    emp.SearchEmployeeByID(choice);
                }
                else if (emp_choice == -1)
                {
                    break;
                }
                else
                {
                    cout << "Wrong input\n";

                }
            }
        }
        else if (choice == 'd' || choice == 'D')
        {
            while (true)
            {
                cout<< "\nPress 1 for Add Department\n"<< "Press 2 for Edit Department\n"<< "Press 3 for Delete Department\n"<< "Press 4 for All Department\n"<<"Press 5 for Sorting\n"<<"Press 6 for Searching\n"<< "Press -1 for exit\n\n";
                cout << endl;
                cout << "Press Dep_choice:- ";
                cin >> dep_choice;
                cout << endl;
                if (dep_choice == 1)
                {
                    dep.AddDepartment(choice);
                }
                else if (dep_choice == 2)
                {
                    cout << "Enter ID:-";
                    cin >> ID_check;
                    dep.EditDepartment(choice,ID_check);
                }
                else if (dep_choice == 3)
                {
                    cout << "Enter ID:-";
                    cin >> ID_check;
                    dep.DeleteDepartment(choice,ID_check);
                }
                else if (dep_choice == 4)
                {
                    dep.ListDepartment(choice);
                }
                else if( dep_choice == 5){
                    dep.SortDepartment(choice);
                }
                else if( dep_choice == 6){
                    dep.SearchDepartmentByID(choice);
                }
                else if(dep_choice==-1){
                    break;
                }
                else
                {
                    cout << "Wrong input\n";

                }
            }
        }
        else{
            break;
        }

    }
    return 0;
}