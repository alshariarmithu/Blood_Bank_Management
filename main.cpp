#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>

using namespace std;

/* ALSHARIAR HOSSIAN MITHU */
/*
1.Class and Objects
2.Constructors and Destructors
3.Friend function
4.Operator Overloading
5.Inheritance
6.Polymorphism
7.Virtual functions
8.File Management and Console I/O
9.Abstract Class
10.Standard Template Library
*/

// Class to represent a Blood Donor
class Donor
{
public:
    string name;
    int age;
    string bloodGroup;

    // Donor(){}
    Donor(string _name, int _age, string _bloodGroup) : name(_name), age(_age), bloodGroup(_bloodGroup) {}
    //~Donor();
};

// Class to represent a Blood Recipient
class Recipient
{
public:
    string name;
    int age;
    string bloodGroup;

    Recipient(string _name, int _age, string _bloodGroup) : name(_name), age(_age), bloodGroup(_bloodGroup) {}
};

// Class to manage the Blood Bank
class BloodBank
{
private:
    vector<Donor> donors;
    vector<Recipient> recipients;

public:
    // Add a new donor to the system
    void addDonor(string name, int age, string bloodGroup)
    {
        Donor donor(name, age, bloodGroup);
        donors.push_back(donor);
    }

    // Add a new recipient to the system
    void addRecipient(string name, int age, string bloodGroup)
    {
        Recipient recipient(name, age, bloodGroup);
        recipients.push_back(recipient);
    }

    // Save donor and recipient data to files
    void saveDataToFile()
    {
        ofstream donorFile("donors.txt");
        ofstream recipientFile("recipients.txt");

        for (const Donor &donor : donors)
        {
            donorFile << donor.name << "," << donor.age << "," << donor.bloodGroup << "\n";
        }

        for (const Recipient &recipient : recipients)
        {
            recipientFile << recipient.name << "," << recipient.age << "," << recipient.bloodGroup << "\n";
        }

        donorFile.close();
        recipientFile.close();
    }

    // Load donor and recipient data from files
    void loadDataFromFile()
    {
        ifstream donorFile("donors.txt");
        ifstream recipientFile("recipients.txt");

        string line;

        while (getline(donorFile, line))
        {
            stringstream ss(line);
            string name, bloodGroup;
            int age;

            getline(ss, name, ',');
            ss >> age;
            ss.ignore(); // Ignore the comma
            getline(ss, bloodGroup, ',');

            Donor donor(name, age, bloodGroup);
            donors.push_back(donor);
        }

        while (getline(recipientFile, line))
        {
            stringstream ss(line);
            string name, bloodGroup;
            int age;

            getline(ss, name, ',');
            ss >> age;
            ss.ignore(); // Ignore the comma
            getline(ss, bloodGroup, ',');

            Recipient recipient(name, age, bloodGroup);
            recipients.push_back(recipient);
        }

        donorFile.close();
        recipientFile.close();
    }

    // Display list of donors
    void displayDonors()
    {
        cout << "Donors List:\n";
        for (const Donor &donor : donors)
        {
            cout << "Name: " << donor.name << ", Age: " << donor.age << ", Blood Group: " << donor.bloodGroup << endl
                 << endl;
        }
    }

    // Display list of recipients
    void displayRecipients()
    {
        cout << "Recipients List:\n";
        for (const Recipient &recipient : recipients)
        {
            cout << "Name: " << recipient.name << ", Age: " << recipient.age << ", Blood Group: " << recipient.bloodGroup << endl
                 << endl;
        }
    }
};

class Details
{
public:
    string Name;
    string email;
    string phoneNumber;
    Details()
    {
        Name = "ALSHARIAR HOSSAIN MITHU";
    }
    virtual void display()=0;
};

class contact : virtual public Details
{
public:
    contact()
    {
        email = "hossain2107066@stud.kuet.ac.bd";
        phoneNumber = "01740419073";
    }
    void display()
    {
        cout<<Name<<"\n";
        cout<<phoneNumber<<"\n";
        cout<<email<<"\n";
    }
    friend ostream & operator << (ostream &out, const contact &c);
};

ostream &operator<<(ostream &out, const contact &c)
    {
        out << c.Name << endl;
        out << c.phoneNumber << endl;
        out << c.email << endl;
        return out;
    }

int main()
{
    BloodBank bloodBank;
    contact c;
    // Load data from files (if any)
    bloodBank.loadDataFromFile();

    int choice;
    do
    {
        cout << "\n";
        cout << "\t\t\t KUET's Dream Blood Bank Management System Menu:\n";
        cout << "\t\t\t\t1. Add a Donor\n";
        cout << "\t\t\t\t2. Add a Recipient\n";
        cout << "\t\t\t\t3. Display Donors\n";
        cout << "\t\t\t\t4. Display Recipients\n";
        cout << "\t\t\t\t5. Save Data to Files\n";
        cout << "\t\t\t\t6. Contact to KUET's Dream\n";
        cout << "\t\t\t\t7. Exit\n";
        cout << "\t\t\t\tEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
        {
            string name, bloodGroup;
            int age;
            cout << "Enter Donor Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Donor Age: ";
            cin >> age;
            cout << "Enter Donor Blood Group: ";
            cin >> bloodGroup;
            bloodBank.addDonor(name, age, bloodGroup);
            break;
        }
        case 2:
        {
            string name, bloodGroup;
            int age;
            cout << "Enter Recipient Name: ";
            cin.ignore();
            getline(cin, name);
            cout << "Enter Recipient Age: ";
            cin >> age;
            cout << "Enter Recipient Blood Group: ";
            cin >> bloodGroup;
            bloodBank.addRecipient(name, age, bloodGroup);
            break;
        }
        case 3:
            bloodBank.displayDonors();
            break;
        case 4:
            bloodBank.displayRecipients();
            break;
        case 5:
            bloodBank.saveDataToFile();
            cout << "Data saved to files.\n";
            break;
        case 6:
            cout<<"KUET's Dream Contact Info:\n";
            cout << c;
            break;
        case 7:
            cout << "Exiting the program.\n";
            break;
        default:
            cout << "Invalid choice. Please try again.\n";
            break;
        }
    } while (choice>0 && choice<7);

    return 0;
}
