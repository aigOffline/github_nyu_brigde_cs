#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Employee {
private:
    int ID;
    double pay_rate;
    string full_name;
    int total_hours = 0;
    
public:
    Employee() { }
    Employee(int ID, double pay_rate, string full_name) {
        this->ID = ID;
        this->pay_rate = pay_rate;
        this->full_name = full_name;
    }
    void add_total_hours(int total_hours) {
        this->total_hours += total_hours;
    }
    void write_to_file() {
        ofstream file;
        file.open("employee.txt", ios_base::app);
        file << ID << " " << pay_rate << " " << full_name;
        file.close();
    }
    void input() {
        cout << "ID "; cin >> ID;
        cout << "Name: "; getline(cin >> ws, full_name);
        cout << "Pay rate: "; cin >> pay_rate;
    }
    
    int get_total_hours() {return total_hours;}
    int get_ID(){return ID;}
    double get_pay_rate(){return pay_rate;}
    string get_full_name(){return full_name;}
    
    friend ostream& operator <<(ostream &outs, const Employee& emp);
    
};

ostream& operator <<(ostream &outs, const Employee& emp) {
    outs <<  emp.ID << " " << emp.pay_rate << " " << emp.full_name << endl;
    return outs;
}

template<class T>
class List {
private:
    struct ListNode {
        T data;
        ListNode *next;
        ListNode *prev;
    };
    ListNode *first;
    ListNode *last;
public:
    
    List() {
        last = nullptr;
        first = nullptr;
    }
    
    void push_back(T data) {
        ListNode *temp = new ListNode;
        temp->data = data;
        temp->next = nullptr;
        temp->prev = last;
        if (first == nullptr) {
            last = temp;
            first = last;
        }
        else {
            last->next = temp;
            last = temp;
        }
    }
    T pop_back() {
        ListNode* temp;
        temp = last;
        last = last->prev;
        if (last != nullptr)
            last->next = nullptr;
        else
            first = nullptr;
        T data = temp->data;
        delete temp;
        return data;
    }
    
    void push_front(T data) {
        ListNode *temp = new ListNode;
        temp->data = data;
        temp->next = first;
        temp->prev = nullptr;
        if (first == nullptr) {
            last = temp;
            first = last;
        }
        else {
            first->prev = temp;
            first = temp;
        }
    }
    
    void pop_front(){
        ListNode *temp;
        temp = first;
        first = first -> next;
        if(first != nullptr)
            first -> prev = nullptr;
        else
            last = nullptr;
        T data = temp -> data;
        delete temp;
        return data;
    }
    
    void print_list() {
        ListNode *p = first;
        while(p != nullptr) {
            cout << p->data;
            p = p->next;
        }
        cout << endl;
    }
    
    void print_reverse_list() {
        ListNode *p = last;
        while(p != nullptr) {
            cout << p->data;
            p = p->prev;
        }
        cout << endl;
    }
    
    bool is_empty() {
        return first == nullptr;
    }
    
    void erase() {
        while(!is_empty())
            pop_back();
    }
    
    void input() {
        cout << "Enter number of your employees: ";
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
    cout << "Please enter Number " << i + 1 << " employee information: " <<endl;
            Employee emp;
            emp.input();
            push_back(emp);
        }
    }
    
    void write_to_file() {
        if(!is_empty()) {
            ofstream file;
            file.open("employee.txt");
            ListNode* p = first;
            while (p != nullptr) {
                file << p->data.get_ID() << " " << p->data.get_pay_rate() << " " << p->data.get_full_name();
                if (p->next != nullptr)
                    file << "\n";
                p=p->next;
            }
        }
    }
    
    void read_from_file() {
        ifstream file;
        file.open("employee.txt");
        while (!file.eof()) {
            int ID;
            double pay_rate;
            string full_name;
            file >> ID >> pay_rate;
            getline(file >> ws, full_name);
            Employee emp(ID, pay_rate, full_name);
            push_back(emp);
        }
    }
    
    T& find(int ID) {
        ListNode* p = first;
        while (p != nullptr) {
            if (p->data.get_ID() == ID)
                break;
            p =  p->next;
        }
        return p->data;
    }
    void print_pay_roll_information() {
        ListNode* p = first;
    cout << "*********Payroll Information********" << endl;
        while(p != nullptr) {
            cout << p->data.get_full_name() << " ";
            cout << p->data.get_total_hours() * p->data.get_pay_rate();
            cout << endl;
            p = p->next;
        }
        cout << "*********End payroll**************" << endl;
    }
    
    
    ~List() {
        erase();
        if (is_empty())
            cout << "The list is empty." << endl;
    }
    void sort() {
        ListNode *temp = first;
        while (temp->next)
        {
            if (temp->data.get_total_hours() * temp->data.get_pay_rate() < temp->next->data.get_total_hours() *
                temp->next->data.get_pay_rate())
            {
                swap(temp->data, temp->next->data);
                temp = temp->next;
                sort();
            }
            else
                temp = temp->next;
        }
    }
    
};


void create_payrolls() {
    ofstream file;
    file.open("payrolls.txt");
    cout << "enter number of payrolls: " << endl;
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
    cout << "Please enter Number " << i + 1 << " payroll information: " << endl;
        int ID, hours;
        cout << "ID: "; cin >> ID;
        cout << "hours: "; cin >> hours;
        file << ID << " " << hours;
        if (i != n - 1)
            file << endl;
    }
    file.close();
}



void read_payrolls(List<Employee>& list) {
    ifstream file;
    file.open("payrolls.txt");
    while (!file.eof()) {
        int ID, hours;
        file >> ID >> hours;
        list.find(ID).add_total_hours(hours);
    }
    file.close();
}

void menu() {
    int n = 0;
    List<Employee> list;
    do {
        cout << "What would you like to do?" << endl;
        cout << "1. Create list" << endl;
        cout << "2. Write list to file" << endl;
        cout << "3. Read list from file" << endl;
        cout << "4. Print list" << endl;
        cout << "5. Create payrolls file" << endl;
        cout << "6. Read payrolls file" << endl;
        cout << "7. Print payroll information" << endl;
        cout << "0. Exit" << endl;
        cin >> n;
        switch (n) {
            case 1 : list.input(); break;
            case 2 : list.write_to_file(); break;
            case 3 : list.erase(); list.read_from_file(); break;  // we need to erase the list firstly to avoid duplicate record in the list
    case 4 : list.print_list(); break;
            case 5 : create_payrolls(); break;
            case 6 : read_payrolls(list); break;
            case 7 : list.sort(); list.print_pay_roll_information(); break;
            case 0 : break;
        }
    }
    while (n != 0);
}


int main() {
    
    menu();
    
}
