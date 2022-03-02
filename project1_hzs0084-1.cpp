//Hemant Sherawat
//hzs0084
//I used stackoverflow to debug some compile errors
//Used nothing but basic if and else statement for the code
//use g++ to compile
///and ./a.out to run


#include <iostream>
#include <iomanip>
#include <string>
using namespace std;


int main()
{
//	cout.imbue(std::locale("en_US.UTF-8"));
	double loanAmount;
	double interestRate;
	double monthlyPayments;
//input
	cout << "Loan Amount: ";
	cin >> loanAmount;
	cout << "Interest Rate (% per year): ";
	cin >> interestRate;
	cout << "Monthly Payments: ";
	cin >> monthlyPayments;

	double balance = loanAmount;
	int month = 0;
	double rate = interestRate / 1200;
	double payment = monthlyPayments;
	double principal = 0;
	double interest = 0;
	double totalInterest = 0;

	if(rate * balance >= payment) {
		cout << "Your monthly interest is larger than your monthly payments." << endl;
		cout << "Enter a sufficient amount." << endl;
		return 0;
	}
//start format
	string stars = "*******************************************************************";
	cout << stars << endl;
	cout << "\tAmortization Table" << endl;
	cout << stars << endl;
	cout << left << setw(11)  << "Month" << setw(11) << "Balance"
	<< setw(10) << " Payment" << setw(9) << "  Rate"
	<< setw(10) << "  Interest" << "   Principal" << endl;

	cout.precision(2);

	while(balance > 0) {
		if (month == 0) {
			cout << left << fixed << setw(11) << "0"
			<< "$"<< setw(11) << balance << setw(10)
			<< "N/A" << setw(9) << " N/A" << setw(10)
			<< " N/A" << "  N/A" << endl;
			month++;
		}
		else {
			interest = rate * balance;
			if (balance < payment + interest) {
				principal = balance;
				balance = 0;
				payment = principal + interest;
			}
			else {
				principal = payment - interest;
				balance = balance - principal;
			}
			cout << left << fixed << setw(11) << month << "$"
			<< setw(11) <<  balance << "$" << setw(10) << payment
			<< setw(9) << setprecision(1) << rate * 100
			<< setprecision(2) << "$" << setw(10) << interest
			<< "$" << principal << endl;
			totalInterest = totalInterest + interest;
			if (balance > 0) {
				month++;
			}
                }
	}
	cout << stars << endl;
	cout << endl;
	cout << "It takes " << month << " months to pay off this loan." << endl;
	cout << "Total interest paid is: $" << fixed <<  totalInterest << endl;
}
