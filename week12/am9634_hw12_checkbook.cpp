#include <iostream>
#include <vector>
using namespace std;

class Money
{
public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.
    
    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount 1 minus amount2.
    
    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.
    
    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.
    
    friend bool operator < (const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.
    
    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.
    
    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.
    
    Money( );
    //Initializes the object so its value represents $0.00.
    
    double get_value( ) const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.
    
    friend istream& operator >>(istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in -$100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.
    
    
    friend ostream& operator <<(ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.
private:
    long all_cents;
};

int digit_to_int(char c)
{
    return ( static_cast<int>(c) - static_cast<int>('0') );
}

Money::Money(long dollars, int cents)
{
    if(dollars*cents < 0) //If one is negative and one is positive
    {
        cout << "Illegal values for dollars and cents.\n";
        exit(1);
    }
    all_cents = dollars*100 + cents;
}

Money::Money(long dollars) : all_cents(dollars*100)
{
    //Body intentionally blank.
}

Money::Money( ) : all_cents(0)
{
    //Body intentionally blank.
}

//Reads in 5 amounts of money and shows how much each
//amount differs from the largest amount.

Money operator -(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount)
{
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

Money operator +(const Money& amount1, const Money& amount2)
{
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

//Uses iostream, cctype, cstdlib:
istream& operator >>(istream& ins, Money& amount)
{
    char one_char, decimal_point,
    digit1, digit2; //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.
    
    ins >> one_char;
    if (one_char == '-')
    {
        negative = true;
        ins >> one_char; //read '$'
    }
    else
        negative = false;
    //if input is legal, then one_char == '$'
    
    ins >> dollars >> decimal_point >> digit1 >> digit2;
    
    if ( one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2) )
    {
        cout << "Error illegal form for money input\n";
        exit(1);
    }
    
    cents = digit_to_int(digit1)*10 + digit_to_int(digit2);
    
    amount.all_cents = dollars*100 + cents;
    if (negative)
        amount.all_cents = -amount.all_cents;
    
    
    return ins;
}


//Uses cstdlib and iostream:
ostream& operator <<(ostream& outs, const Money& amount)
{
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents/100;
    cents = positive_cents%100;
    
    if (amount.all_cents < 0)
        outs << "-$" << dollars << '.';
    else
        outs << "$" << dollars << '.';
    
    if (cents < 10)
        outs << '0';
    outs << cents;
    
    return outs;
}

double Money::get_value() const {
    return all_cents / 100.0;
}


class Check {
private:
    int number;
    Money amount;
    bool cashed;
public:
    void set_number(int n) {
        number = n;
    }
    void set_amount(Money& a) {
        amount = a;
    }
    void set_cashed(bool c) {
        cashed = c;
    }
    int get_number() {
        return number;
    }
    Money& get_amount() {
        return amount;
    }
    bool get_cashed() {
        return cashed;
    }
    Check(int n, Money& a, bool c) {
        number = n;
        amount = a;
        cashed = c;
    }
    Check() {};
    
    void input() {
        cout << "Enter the check number: ";
        int n;
        cin >> n;
        set_number(n);
        cout << "Enter check amount as a decimal (with $ ): ";
        Money a;
        cin >> a;
        set_amount(a);
        cout << "Was this check cashed (y/n)?: ";
        char c;
        cin >> c;
        if (c == 'y')
            set_cashed(true);
        else
            set_cashed(false);
    }
    
    void output() {
        string c = "(cashed)";
        if (!cashed) c = "(not cashed)";
        cout << "check#" << number << "\t"
        << amount << c << endl;
    }
    
};

vector<Check> input_checks() {
    vector<Check>  checks;
    int i = 1;
    char ch;
    do {
        cout << endl << "check #" << i << endl;
        Check temp;
        temp.input();
        checks.push_back(temp);
        cout << endl << "Whould you like to add another check?(y/n): ";
        cin >> ch;
        i++;
    } while (ch == 'y');
    return checks;
}

vector<Money> input_deposites() {
    cout << "Please enter your bank deposites (with $ and end with $00.00): " << endl;
    vector<Money> dep;
    Money d;
    while(cin >> d && d.get_value() != 0) {
        dep.push_back(d);
    }
    return dep;
}

Money get_total_amount_cashed(vector<Check> checks) {
    Money total_amount_cashed(0.00);
    for (int i = 0; i < checks.size(); i++)
        if (checks[i].get_cashed())
            total_amount_cashed = total_amount_cashed + checks[i].get_amount();
    return total_amount_cashed;
}

Money get_total_amount_deposited(vector<Money> dep) {
    Money total_amount_deposited(0.00);
    for (int i = 0; i < dep.size(); i++)
        total_amount_deposited = total_amount_deposited + dep[i];
    return total_amount_deposited;
}

Money get_new_balance(vector<Check> checks, vector<Money> dep, Money& old_balance) {
    Money new_balance(0);
    new_balance = new_balance + old_balance;
    new_balance = new_balance + get_total_amount_deposited(dep);
    new_balance = new_balance - get_total_amount_cashed(checks);
    return new_balance;
}

Money get_pending_balance(vector<Check> checks, vector<Money> dep, Money& old_balance) {
    Money pending_balance(0);
    pending_balance = pending_balance + get_new_balance(checks, dep, old_balance);
    for (int i = 0; i < checks.size(); i++)
        if (!checks[i].get_cashed())
            pending_balance = pending_balance - checks[i].get_amount();
    return pending_balance;
}

void print_cashed_checks(vector<Check> checks) {
    cout << "Cashed checks: " << endl;
    for (int i = 0; i < checks.size(); i++)
        if (checks[i].get_cashed())
            checks[i].output();
}

void print_uncashed_checks(vector<Check> checks) {
    cout << "Uncashed checks: " << endl;
    for (int i = 0; i < checks.size(); i++)
        if (!checks[i].get_cashed())
            checks[i].output();
}

int main( )
{
    Money old_balance;
    cout << "Please input your old account balance (with $ and in decimal):  ";
    cin >> old_balance;
    vector<Check>  checks;
    checks = input_checks();
    vector<Money> dep;
    dep = input_deposites();
    
    cout << "============================================================"<< endl;
    
    cout << "Old Balance: " << old_balance << endl;
    cout << "New Balance: " <<  get_new_balance(checks, dep, old_balance) << endl;
    cout << "Pending Balance: " << get_pending_balance(checks, dep, old_balance) << endl;
    cout << "Balance Difference: "
    << get_new_balance(checks, dep, old_balance) -
    get_pending_balance(checks, dep, old_balance)
    << endl;
    cout << "Total amount cashed: " << get_total_amount_cashed(checks) << endl;
    cout << "Total amount deposited: " << get_total_amount_deposited(dep) << endl;
    print_cashed_checks(checks);
    print_uncashed_checks(checks);
    
    
    return 0;
}
