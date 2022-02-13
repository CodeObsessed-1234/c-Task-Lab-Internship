#include <iostream>
#include <vector>
#include<stdlib.h>
#include<algorithm>
using namespace std;

struct department{
    int dep_ID = 0;
    string department;
    vector<string> arr_department;//Store Department
    vector<int> arr_dep_id;// Store Department Id
};

struct employee{
    string name;
    int age;
    int emp_ID = 0;
    vector<int> arr_age; //Store Employee Age
    vector<string> arr_name; //Store Employee Name
    vector<int> arr_emp_id; // Store Employee Id
};

//base class
class orginization{
    public:
        struct employee emp;
        struct department dep; 
        
        // Adding Employee and Department
        void Add(char choice){
            if(choice=='e'||choice=='E'){
                cout << "Enter Name:- ";
                cin >> emp.name;
                cout << "Enter Age:- ";
                cin >> emp.age;
                int check=0;
                for (int i = 0; i < emp.arr_name.size(); ++i)
                {
                    if (emp.name == emp.arr_name[i])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    ++emp.emp_ID;
                    emp.arr_age.push_back(emp.age);
                    emp.arr_name.push_back(emp.name);
                    emp.arr_emp_id.push_back(emp.emp_ID);
                }
                else{
                    cout << "Entry already there\n";
                }
            }
            else if(choice=='d'||choice=='D'){
                cout << "Enter Department:- ";
                cin >> dep.department;
                int check=0;
                for (int i = 0; i < dep.arr_department.size(); ++i)
                {
                    if (dep.department == dep.arr_department[i])
                    {
                        check=1;
                        break;
                    }
                }
                if(check==0){
                    ++dep.dep_ID;
                    dep.arr_department.push_back(dep.department);
                    dep.arr_dep_id.push_back(dep.dep_ID);
                }
                else{
                    cout << "Entry already there\n";
                }
            }
        }

        // For Editing Employee and Department
        void Edit(char choice,int id){
            if(choice=='e'||choice=='E'){
                string name_change;
                int age_change;
                int check=0;
                for (int i = 0; i < emp.arr_emp_id.size(); ++i)
                {
                    if (id == emp.arr_emp_id[i])
                    {
                        cout << "Name:- " << emp.arr_name[i] << endl;
                        cout << "Age:- " << emp.arr_age[i] << "\n" << endl;
                        check=1;
                    }
                }
                if(check==1){
                    cout << "For Change" << endl;
                    cout << "Enter Name:- ";
                    cin >> name_change;
                    cout << "Enter Age:- ";
                    cin >> age_change;
                    emp.arr_name[id-1] = name_change;
                    emp.arr_age[id-1] = age_change;
                }
                else{
                    cout<<"Employee doesn't exist"<<endl;
                }
            }
            else if(choice=='d'||choice=='D'){
                string department_change;
                int check=0;
                for (int i = 0; i < dep.arr_dep_id.size(); ++i)
                {
                    if (id == dep.arr_dep_id[i])
                    {
                        cout<<dep.arr_department[i]<<endl;
                        check=1;
                        break;
                    }
                }
                if(check==1){
                    cout << "Enter Department:- ";
                    cin >> department_change;
                    dep.arr_department[id-1] = department_change;
                }
                else{
                    cout<<"Department dosen't exist"<<endl;
                }
            }
        }

        //For Deleting Employee and Department
        void Delete(char choice, int id){
            if(choice=='e'||choice=='E'){
                int check=0;
                if(emp.arr_emp_id.size()>0){
                    for (int i = 0; i < emp.arr_emp_id.size(); ++i)
                    {
                        if (id == emp.arr_emp_id[i])
                        {
                            check=1;
                            --emp.emp_ID;
                        emp.arr_name.erase(emp.arr_name.begin()+i);
                            emp.arr_age.erase(emp.arr_age.begin()+i);
                            emp.arr_emp_id.pop_back();
                            break;
                        }
                    }
                    if(check==0){
                        for (int i = 0; i < emp.arr_emp_id.size(); ++i)
                        {
                            cout << "Name:- " << emp.arr_name[i] << endl;
                            cout << "Age:- " << emp.arr_age[i] << "\n\n";
                        }
                    }
                }
                else{
                    cout<<"\nNo Record\n";
                }
                
                // ask for age doubt
                int age_change;
                cout << "Enter Age:- ";
                cin >> age_change;
                for (int i = 0; i < emp.arr_age.size(); ++i)
                {
                    if (age_change == emp.arr_age[i])
                    {
                        continue;
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                int check=0;
                if(dep.arr_dep_id.size()>0){
                    for (int i = 0; i < dep.arr_dep_id.size(); ++i)
                    {
                        if (id == dep.arr_dep_id[i])
                        {
                            check=1;
                            --dep.dep_ID;
                            dep.arr_department.erase(dep.arr_department.begin()+i);
                            dep.arr_dep_id.pop_back();
                            break;
                        }
                    }
                    if(check==0){
                        for (int i = 0; i < dep.arr_dep_id.size(); ++i)
                        {
                            cout << "Department:- " << dep.arr_department[i] << "\n\n";
                            
                        }
                    }
                }
                else{
                    cout<<"\nNo Record\n";
                }
                
            }
        }

        //Show all Records of Emploee and Department
        void List(char choice){
            if(choice=='e'||choice=='E'){
                if (emp.arr_emp_id.size() == 0)
                {
                    cout << "No Entry\n";
                }
                else
                {
                    for (int i = 0; i < emp.arr_emp_id.size(); ++i)
                    {
                        cout <<emp.arr_emp_id[i]<<"-"<<"   Name:- " << emp.arr_name[i] << endl;
                        cout <<"     Age:- " << emp.arr_age[i] << "\n\n";
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                char key;

                if (dep.arr_dep_id.size() == 0)
                {
                    cout << "No Entry\n";
                }
                else{
                    for (int i = 0; i < dep.arr_dep_id.size(); ++i)
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

                        cout <<dep.arr_dep_id[i]<<"-  "<<dep.arr_department[i] << endl;
                    }
                }
            }
        }

        //Sort Employee and Department Record
        void Sort(char choice){
            if(choice=='e'||choice=='E'){
                string temp_name;
                int temp_age;
                for(int i=0;i<emp.arr_age.size()-1;++i){
                    temp_name=emp.arr_name[i];
                    temp_age=emp.arr_age[i];
                    for(int j=i+1;j<emp.arr_age.size();++j){
                        if(emp.arr_age[i]>emp.arr_age[j]){
                            emp.arr_age[i]=emp.arr_age[j];
                            emp.arr_age[j]=temp_age;
                            emp.arr_name[i]=emp.arr_name[j];
                            emp.arr_name[j]=temp_name;
                        }
                    }
                }
            }
            else if(choice=='d'||choice=='D'){
                sort(dep.arr_department.begin(),dep.arr_department.end());
            }
        }

        //Search For Secific record in Employee and Department
        void Search(char choice){
            if(choice=='e'||choice=='E'){
                int id;
                cout<<"Enter ID:- ";
                cin>>id;
                int start=0;
                int end=emp.arr_name.size();
                while(start<=end){
                    int mid=start+(end-1)/2;
                    if(emp.arr_emp_id[mid]==id){
                        cout<<"\nFound\n";
                        cout<<"Name:- "<<emp.arr_name[mid]<<endl;
                        cout<<"Age:- "<<emp.arr_age[mid]<<endl;
                        break;
                    }
                    else if(emp.arr_emp_id[mid]>id){
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
                int end=dep.arr_department.size();
                while(start<=end){
                    int mid=start+(end-1)/2;
                    if(dep.arr_dep_id[mid]==id){
                        cout<<"\nFound\n";
                        cout<<dep.arr_dep_id[mid]<<"- "<<dep.arr_department[mid]<<endl;
                        break;
                    }
                    else if(dep.arr_dep_id[mid]>id){
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