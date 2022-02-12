#include <iostream>
#include <vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

class orginization{
    public:
        string name;
        int age;
        vector<int> arr_age;
        vector<string> arr_name;
        vector<int> arr_emp_id;
        string department;
        vector<string> arr_department;
        vector<int> arr_dep_id;
        void Add(char choice,int id){
            if(choice=='e'||choice=='E'){
                cout << "Enter Name:- ";
                cin >> name;
                cout << "Enter Age:- ";
                cin >> age;
                int check=0;
                for (int i = 0; i < arr_name.size(); ++i)
                {
                    if (name == arr_name[i])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    arr_age.push_back(age);
                    arr_name.push_back(name);
                    arr_emp_id.push_back(id);
                }
                else{
                    cout << "Entry already there\n";
                }
            }
            else if(choice=='d'||choice=='D'){
                cout << "Enter Department:- ";
                cin >> department;
                int check=0;
                for (int i = 0; i < arr_name.size(); ++i)
                {
                    if (department == arr_department[i])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    arr_department.push_back(department);
                    arr_dep_id.push_back(id);
                }
                else{
                    cout << "Entry already there\n";
                }
            }
        }

        void Edit(char choice,int id){
            if(choice=='e'||choice=='E'){
                string name_change;
                int age_change;
                int check=0;
                for (int i = 0; i < arr_emp_id.size(); ++i)
                {
                    if (id == arr_emp_id[i])
                    {
                        cout << "Name:- " << arr_name[i] << endl;
                        cout << "Age:- " << arr_age[i] << "\n" << endl;
                        check=1;
                    }
                }
                if(check==1){
                    cout << "For Change" << endl;
                    cout << "Enter Name:- ";
                    cin >> name_change;
                    cout << "Enter Age:- ";
                    cin >> age_change;
                    arr_name[id-1] = name_change;
                    arr_age[id-1] = age_change;
                }
                else{
                    cout<<"Employee doesn't exist"<<endl;
                }
            }
            else if(choice=='d'||choice=='D'){
                string department_change;
                int check=0;
                for (int i = 0; i < arr_dep_id.size(); ++i)
                {
                    if (id == arr_dep_id[i])
                    {
                        cout<<arr_department[i]<<endl;
                        check=1;
                        break;
                    }
                }
                if(check==1){
                    cout << "Enter Department:- ";
                    cin >> department_change;
                    arr_department[id-1] = department_change;
                }
                else{
                    cout<<"Department dosen't exist"<<endl;
                }
            }
        }

        void Delete(char choice, int id){
            if(choice=='e'||choice=='E'){
                int check=0;
                for (int i = 0; i < arr_emp_id.size(); ++i)
                {
                    if (id == arr_emp_id[i])
                    {
                        check=1;
                        arr_name.erase(arr_name.begin()+i);
                        arr_age.erase(arr_age.begin()+i);
                        arr_emp_id.pop_back();
                        break;
                    }
                }
                if(check==0){
                    for (int i = 0; i < arr_emp_id.size(); ++i)
                    {
                        cout << "Name:- " << arr_name[i] << endl;
                        cout << "Age:- " << arr_age[i] << "\n\n";
                    }
                }
                // ask for age doubt
                int age_change;
                cout << "Enter Age:- ";
                cin >> age_change;
                for (int i = 0; i < arr_age.size(); ++i)
                {
                    if (age_change == arr_age[i])
                    {
                        continue;
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                int check=0;
                for (int i = 0; i < arr_dep_id.size(); ++i)
                {
                    if (id == arr_dep_id[i])
                    {
                        check=1;
                        arr_department.erase(arr_department.begin()+i);
                        arr_dep_id.pop_back();
                        break;
                    }
                }
                if(check==0){
                    for (int i = 0; i < arr_dep_id.size(); ++i)
                    {
                        cout << "Department:- " << arr_department[i] << "\n\n";
                        
                    }
                }
            }
        }

        void List(char choice){
            if(choice=='e'||choice=='E'){
                if (arr_emp_id.size() == 0)
                {
                    cout << "No Entry\n";
                }
                else
                {
                    for (int i = 0; i < arr_emp_id.size(); ++i)
                    {
                        cout <<arr_emp_id[i]<<"-"<<"   Name:- " << arr_name[i] << endl;
                        cout <<"     Age:- " << arr_age[i] << "\n\n";
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                char key;

                if (arr_dep_id.size() == 0)
                {
                    cout << "No Entry\n";
                }
                else{
                    for (int i = 0; i < arr_dep_id.size(); ++i)
                    {
                        if (i>0&&i%5==0)
                        {
                            cout << "\nPress N/n for next page" << endl;
                            cin >> key;
                            if (key == 'n' || key == 'N')
                            {
                                system("cls");

                            }
                            else
                            {
                                cout << "\nWrong input\n";
                                break;
                            }
                        }

                        cout <<arr_dep_id[i]<<"-  "<<arr_department[i] << endl;
                    }
                }
            }
        }

        void Sort(char choice){
            if(choice=='e'||choice=='E'){
                string temp_name;
                int temp_age;
                for(int i=0;i<arr_age.size()-1;++i){
                    temp_name=arr_name[i];
                    temp_age=arr_age[i];
                    for(int j=i+1;j<arr_age.size();++j){
                        if(arr_age[i]>arr_age[j]){
                            arr_age[i]=arr_age[j];
                            arr_age[j]=temp_age;
                            arr_name[i]=arr_name[j];
                            arr_name[j]=temp_name;
                        }
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                sort(arr_department.begin(),arr_department.end());
            }
        }

        void Search(char choice){
            if(choice=='e'||choice=='E'){
                int id;
                cout<<"Enter ID:- ";
                cin>>id;
                int start=0;
                int end=arr_name.size();
                while(start<=end){
                    int mid=start+(end-1)/2;
                    if(arr_emp_id[mid]==id){
                        cout<<"\nFound\n";
                        cout<<"Name:- "<<arr_name[mid]<<endl;
                        cout<<"Age:- "<<arr_age[mid]<<endl;
                        break;
                    }
                    else if(arr_emp_id[mid]>id){
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
                if(start>end){
                    cout<<"\nNot Found\n";
                } 
            }
            else if(choice=='d'||choice=='D'){
                int id;
                cout<<"Enter ID:- ";
                cin>>id;
                int start=0;
                int end=arr_department.size();
                while(start<=end){
                    int mid=start+(end-1)/2;
                    if(arr_dep_id[mid]==id){
                        cout<<"\nFound\n";
                        cout<<arr_department[mid]<<endl;
                        break;
                    }
                    else if(arr_dep_id[mid]>id){
                        end=mid-1;
                    }
                    else{
                        start=mid+1;
                    }
                }
                if(start>end){
                    cout<<"\nNot Found\n";
                } 
            }
        }
};



class employeeManagment: public orginization
{
    public:
        orginization emp;
        void AddEmployee(char choice,int id)
        {
            emp.Add(choice,id);
            
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

class departmentManagment: public orginization
{
    public:
        orginization dep;
        void AddDepartment(char choice,int id)
        {
            dep.Add(choice,id);
            
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

int main()
{
    int dep_choice, emp_choice, emp_ID = 0, dep_ID = 0, ID_check;
    char choice;
    employeeManagment emp;
    departmentManagment dep;
    while (true)
    {
        cout << "Press D for Department\n"
             << "Press E for Employee\n"
             << "Press Any Key for Exit"
             << "\n";
        cout << endl;
        cout << "Enter Choice:- ";
        cin >> choice;
        if (choice == 'e' || choice == 'E')
        {
            while (true)
            {
                cout << endl;
                cout << "\nPress 1 for Add Employee\n"
                     << "Press 2 for Edit Employee\n"
                     << "Press 3 for Delete Employee\n"
                     << "Press 4 for All Employees\n"
                     <<"Press 5 for Sorting By Age\n"
                     <<"Press 6 for Searching\n"
                     << "Press 7 for Add Employee_Department\n"
                     << "Press 8 for Edit Employee_Department\n"
                     << "Press 9 for Delete Employee_Department\n"
                     << "Press 10 for All Employee_Department\n"
                     << "Press 11 for Sorting\n"
                     << "Press -1 for exit\n\n";
                cout << "Enter Emp_choice:- ";
                cin >> emp_choice;
                cout << endl;

                if (emp_choice == 1)
                {
                    ++emp_ID;
                    emp.AddEmployee(choice,emp_ID);
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
                else if (emp_choice == 7)
                {
                    dep.AddDepartment(choice,dep_ID);
                    ++dep_ID;
                }
                else if (emp_choice == 8)
                {
                    cout << "Enter ID:-";
                    cin >> ID_check;
                    dep.EditDepartment(choice,ID_check);
                }
                else if (emp_choice == 9)
                {
                    cout << "Enter ID:-";
                    cin >> ID_check;
                    dep.DeleteDepartment(choice,ID_check);
                }
                else if (emp_choice == 10)
                {
                    dep.ListDepartment(choice);
                }
                else if(emp_choice == 11){
                    dep.SortDepartment(choice);
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
                cout<< "\nPress 1 for Add Department\n"
                    << "Press 2 for Edit Department\n"
                    << "Press 3 for Delete Department\n"
                    << "Press 4 for All Department\n"
                    <<"Press 5 for Sorting\n"
                    <<"Press 6 for Searching\n"
                    << "Press -1 for exit\n\n";
                cout << endl;

                cout << "Press Dep_choice:- ";
                cin >> dep_choice;
                cout << endl;
                if (dep_choice == 1)
                {
                    ++dep_ID;
                    dep.AddDepartment(choice,dep_ID);
                    
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


