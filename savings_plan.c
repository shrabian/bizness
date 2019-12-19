#include <stdio.h>
#include <stdlib.h>
double saving_plan(double initial, double payments, double debit_ann_rate, 
	double credit_ann_rate, int years);
int
main(int argc, char **argv){
	double initial, payments, debit_ann_rate, credit_ann_rate, balance;
	int years;
	printf("Enter initial balance	:");
	scanf("%lf", &initial);
	printf("Enter monthly transfers to be made	:");
	scanf("%lf", &payments);
	printf("Enter the number of years of the annuity	:");
	scanf("%d", &years);
	printf("Enter the annual interest rate on savings	:");
	scanf("%lf", &debit_ann_rate);
	printf("Enter the annual interest rate on mortgage loans	:");
	scanf("%lf", &credit_ann_rate);
	balance = saving_plan(initial, payments, debit_ann_rate, credit_ann_rate,
		years);
	printf("Savings of $%f plus $%f per month for %d years is $%f\n", initial, 
		payments, years, balance);
	return 0;
}

double saving_plan(double initial, double payments, double debit_ann_rate,
	double credit_ann_rate, int years){
	int month;
	double monthly_interest, balance = initial;
	for (month=0; month<12*years; month++){
		if (balance>=0){
			monthly_interest = 1.00 + ((debit_ann_rate/100)/12);
		}
		else {
			monthly_interest = 1.00 +((credit_ann_rate/100)/12);
		}
		balance *= monthly_interest;
		balance += payments; 	
	}
	return balance;
}
	
	
