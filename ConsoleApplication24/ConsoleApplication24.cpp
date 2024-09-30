#include <iostream>
#include <string>

using namespace std;

class PaymentMethod {
public:
    virtual void processPayment(double amount) = 0;
    virtual ~PaymentMethod() {}
};

class CreditCard : public PaymentMethod {
private:
    string cardNumber;
    string expirationDate;
    string cardHolderName;

public:
    CreditCard(string cardNumber, string expirationDate, string cardHolderName)
        : cardNumber(cardNumber), expirationDate(expirationDate), cardHolderName(cardHolderName) {}

    void processPayment(double amount) override {
        cout << "Обробка платежу за допомогою кредитної картки " << cardNumber << " на суму " << amount << endl;
    }
};

class PayPal : public PaymentMethod {
private:
    string email;

public:
    PayPal(string email) : email(email) {}

    void processPayment(double amount) override {
        cout << "Обробка платежу через PayPal на адресу " << email << " на суму " << amount << endl;
    }
};

class BankTransfer : public PaymentMethod {
private:
    string bankAccountNumber;
    string bankName;

public:
    BankTransfer(string bankAccountNumber, string bankName)
        : bankAccountNumber(bankAccountNumber), bankName(bankName) {}

    void processPayment(double amount) override {
        cout << "Обробка платежу через банківський переказ на рахунок " << bankAccountNumber << " в банку " << bankName << " на суму " << amount << endl;
    }
};

int main() {
    PaymentMethod* paymentMethods[] = {
        new CreditCard("1234-5678-9012-3456", "12/2025", "John Doe"),
        new PayPal("john.doe@example.com"),
        new BankTransfer("1234567890", "Bank of America")
    };

    double amounts[] = { 100.0, 200.0, 300.0 };

    for (int i = 0; i < 3; i++) {
        paymentMethods[i]->processPayment(amounts[i]);
    }

    for (int i = 0; i < 3; i++) {
        delete paymentMethods[i];
    }

    return 0;
}