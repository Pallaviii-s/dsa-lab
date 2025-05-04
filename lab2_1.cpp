#include <iostream>
#include <cmath>
using namespace std;

bool isPalindrome(int* num) 
{
    int reversed = 0, original = *num, temp = *num;
    while (temp > 0) 
    {
        reversed = reversed * 10 + temp % 10;
        temp /= 10;
    }
    return (original == reversed);
}

bool isArmstrong(int* num) 
{
    int sum = 0, temp = *num, digits = 0;
    int n = *num;
    while (n > 0)
    {
        digits++;
        n /= 10;
    }
    while (temp > 0) {
        int rem = temp % 10;
        sum += pow(rem, digits);
        temp /= 10;
    }
    return (sum == *num);
}

bool isPerfect(int* num) 
{
    int sum = 0;
    for (int i = 1; i <= *num / 2; i++) 
    {
        if (*num % i == 0)
            sum += i;
    }
    return (sum == *num);
}

int main() 
{
    int choice;
    do 
    {
        cout << "\nMenu:\n";
        cout << "1. Palindrome\n2. Armstrong Number\n3. Perfect Number\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice >= 1 && choice <= 3) 
        {
            int* num = new int;  
            cout << "Enter a number: ";
            cin >> *num;

            if (*num < 0) 
            {
                cout << "Invalid input. Enter a positive number.\n";
                delete num;
                continue;
            }
            switch (choice) 
            {
                case 1:
                    cout << (*isPalindrome(num) ? "It is a Palindrome.\n" : "Not a Palindrome.\n");
                    break;
                case 2:
                    cout << (*isArmstrong(num) ? "It is an Armstrong Number.\n" : "Not an Armstrong Number.\n");
                    break;
                case 3:
                    cout << (*isPerfect(num) ? "It is a Perfect Number.\n" : "Not a Perfect Number.\n");
                    break;
            }
            delete num; 
        } 
        else if (choice != 4) 
        {
            cout << "Invalid choice, please try again.\n";
        }

    } while (choice != 4);

    cout << "Exiting program.\n";
    return 0;
}