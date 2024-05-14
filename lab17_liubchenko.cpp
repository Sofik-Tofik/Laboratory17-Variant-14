#include <iostream>
#include <string>

using namespace std;

class OrganizationAddress {
private:
    string street;
    string city;
    string postalCode;

    bool isValidPostalCode(const string& code) {
        return !code.empty();
    }

public:
    OrganizationAddress(string street, string city, string postalCode) {
        if (street.empty() || city.empty() || !isValidPostalCode(postalCode)) {
            cerr << "Invalid address details provided." << endl;
            exit(1);
        }
        this->street = street;
        this->city = city;
        this->postalCode = postalCode;
    }

    void changeStreet(const string& newStreet) {
        if (!newStreet.empty()) {
            street = newStreet;
        }
        else {
            cerr << "Street cannot be empty." << endl;
        }
    }

    void changeCity(const string& newCity) {
        if (!newCity.empty()) {
            city = newCity;
        }
        else {
            cerr << "City cannot be empty." << endl;
        }
    }

    void changePostalCode(const string& newPostalCode) {
        if (isValidPostalCode(newPostalCode)) {
            postalCode = newPostalCode;
        }
        else {
            cerr << "Invalid postal code." << endl;
        }
    }

    void display() const {
        cout << "Street: " << street << endl;
        cout << "City: " << city << endl;
        cout << "Postal Code: " << postalCode << endl;
    }
};

class OrganizationInfo : public OrganizationAddress {
private:
    string name;
    int numOfEmployees;

public:
    OrganizationInfo(string street, string city, string postalCode, string name, int numOfEmployees)
        : OrganizationAddress(street, city, postalCode) {
        this->name = name;
        this->numOfEmployees = numOfEmployees;
    }

    void changeName(const string& newName) {
        if (!newName.empty()) {
            name = newName;
        }
        else {
            cerr << "Name cannot be empty." << endl;
        }
    }

    void changeNumOfEmployees(int newNum) {
        if (newNum >= 0) {
            numOfEmployees = newNum;
        }
        else {
            cerr << "Number of employees cannot be negative." << endl;
        }
    }

    void display() const {
        OrganizationAddress::display();
        cout << "Organization Name: " << name << endl;
        cout << "Number of Employees: " << numOfEmployees << endl;
    }
};

int main() {
    OrganizationInfo org("405 Black Pearl", "Singapore", "96745", "Pirates", 350);
    org.display();

    cout << "Changing organization name..." << endl;
    org.changeName("Pirates of the Caribbean");
    org.display();

    cout << "Changing number of employees..." << endl;
    org.changeNumOfEmployees(400);
    org.display();

    return 0;
}

