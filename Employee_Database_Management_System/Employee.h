#pragma once
#include <iostream>
#include <string>

using namespace std;

class Employee 
{
public:
    string id;
    string name;
    string address;
    int position;
    int working_hours;
    int salary;
    Employee* next;
    Employee(string Id,string Name, string Address, int Position, int Working_hours)
    {
        id = Id;
        name = Name;
        address = Address;
        position = Position;
        working_hours = Working_hours;
        salary = getSalary();
        next = NULL;
    }
    int getSalary() {
        int salary;
        if (position == 1)
        {
            salary = 1500 * working_hours;
        }
        else if (position == 2)
        {
            salary = 1200 * working_hours;
        }
        else if (position == 3)
        {
            salary = 1000 * working_hours;
        }
        else if (position == 4)
        {
            salary = 800 * working_hours;
        }
        else
        {
            salary = 500 * working_hours;
        }
        return salary;
    }
    
};

class EmployeeList 
{
private:
    Employee* head;
public:
    EmployeeList() 
    {
        head = NULL;
 
    }
    Employee* Gethead() 
    {
        return head;
    }
    
    

    bool isIdexist(string id) 
    {
        Employee* currentEmployee = head;

        while (currentEmployee != NULL) 
        {
            if (currentEmployee->id == id) 
            {
                return true;
            }
            currentEmployee = currentEmployee->next;

        }
        return false;

    }
    
    
    void addEmployee() 
    {
        string id;
        string name;
        string address;
        int position;
        int working_hours;
        string other = "Y";
        while (other == "Y"||other=="y")
        {
            bool x = false;
            while (x == false) 
            {
                system("cls");
                cout << "Enter the Employee ID      : ";
                cin >> id;
                x = isIdexist(id);
                if (x == true) 
                {
                    cout << "The Id Already Exists" << endl;
                    x = false;
                    system("pause");
                }
                else 
                {
                    x = true;
                }
            }

            cout << "Enter the Employee Name    : ";
            cin >> name;

            cout << "Enter the Employee address : ";
            cin >> address;

            
            
            cout << "Select the Employee Position" << endl;;
            cout << "1. Level 1" << endl;
            cout << "2. Level 2" << endl;
            cout << "3. Level 3" << endl;
            cout << "4. Level 4" << endl;
            cout << "5. Level 5" << endl;
            cout << "Enter the position: ";
            while ((!(cin >> position)) || position < 1 || position > 5) {
                    cout << "\nERROR!\nEnter a Valid Position:";
                    cin.clear();
                    cin.ignore(123, '\n');
                   
            }
               
            cout << "Working Hours(Per month): ";
            //find the invalid input
            while (!(cin >> working_hours)) {
                cout << "\nERROR!\nEnter a Valid working hours:";
                cin.clear();
                cin.ignore(123, '\n');
            }
            Employee* newEmployee = new Employee(id, name, address, position, working_hours);
            // If the linked list is empty, set the head to the new employee
            if (head == NULL) 
            {
                head = newEmployee;
            }
            // Otherwise, add the new employee to the end of the linked list
            else 
            {
                Employee* currentEmployee = head;
                while (currentEmployee->next != NULL) 
                {
                    currentEmployee = currentEmployee->next;
                }
                currentEmployee->next = newEmployee;
            }

            cout << "\nEmployee added successfully" << endl;

            cout << "\nEnter Y to add another Employee\nEnter N to return to Mainmenu" << endl;
            cout << "Y / N: ";
            cin >> other;
        }
    }


    void deleteEmployee() 
    {
        string id;

        if (head == NULL) 
        {
            cout << "Employee List is Empty" << endl;
            system("pause");
            return;
        }
        cout << "Enter the Employee ID to Delete: ";
        cin >> id;
        Employee* currentEmployee = head;
        Employee* prevEmployee = NULL;

        while (currentEmployee != NULL && currentEmployee->id != id) 
        {
            prevEmployee = currentEmployee;
            currentEmployee = currentEmployee->next;
        }

        if (currentEmployee == NULL) 
        {
            cout << "Employee not found" << endl;
            system("pause");
            return;
        }

        if (prevEmployee == NULL) 
        {
            head = head->next;
        }
        else {
            prevEmployee->next = currentEmployee->next;
        }

        delete currentEmployee;
        cout << "Employee deleted successfully" << endl;
        system("pause");
    }

    void displayEmployees() 
    {
        if (head == NULL) 
        {
            cout << "Employee List is Empty" << endl;
            return;
        }

        cout << "List of Employees" << endl;
        cout << "-----------------" << endl;
        Employee* currentEmployee = head;
        while (currentEmployee != nullptr) 
        {
            cout << "ID                       : " << currentEmployee->id << endl;
            cout << "Name                     : " << currentEmployee->name << endl;
            cout << "Address                  : " << currentEmployee->address << endl;
            cout << "Position                 : " << currentEmployee->position << endl;
            cout << "Working Hours (Per month): " << currentEmployee->working_hours<< endl;
            cout << "Salary                   : " << currentEmployee->salary<<"LKR"<< endl;
            cout << endl;
            currentEmployee = currentEmployee->next;
        }
    }

    Employee* searchEmployee(string id) 
    {
        Employee* currentEmployee = head;

        while (currentEmployee != NULL && currentEmployee->id != id) 
        {
            currentEmployee = currentEmployee->next;
        }

        if (currentEmployee == NULL) 
        {
            //cout << "Employee not found" << endl;
            return NULL;
        }

        return currentEmployee;
    }

   

    //insertion sort
     void sortbySalary() {
             Employee* sorted = NULL;

             while (head != NULL) {
                 Employee* current = head;
                 head = current->next;

                 if (sorted == NULL || current->salary < sorted->salary) {
                     current->next = sorted;
                     sorted = current;
                 }
                 else {
                     Employee* temp = sorted;
                     while (temp->next != NULL && current->salary >= temp->next->salary) {
                         temp = temp->next;
                     }
                     current->next = temp->next;
                     temp->next = current;
                 }
             }

             head = sorted;
         }
        
     

    
};





