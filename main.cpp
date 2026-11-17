
#include <iostream>
using namespace std;

// FUNCTION DECLARATIONS
void excavationSiteMenu();
void artifactMenu();
void classificationMenu();
void agePeriodMenu();
void teamMenu();
void conditionMenu();
void preservationMenu();
void restorationMenu();
void ownershipMenu();
void reportsMenu();
void userMenu();

int main() {

    int choice;

    do {

        cout << "\n============================================" << endl;
        cout << "   ARCHAEOLOGICAL ARTIFACT MANAGEMENT SYSTEM" << endl;
        cout << "============================================" << endl;

        cout << "\nMAIN MENU" << endl;
        cout << "1. Excavation Site Management" << endl;
        cout << "2. Artifact Discovery and Cataloguing" << endl;
        cout << "3. Artifact Classification" << endl;
        cout << "4. Age and Historical Period Management" << endl;
        cout << "5. Excavation Team Management" << endl;
        cout << "6. Artifact Condition Assessment" << endl;
        cout << "7. Preservation Management" << endl;
        cout << "8. Restoration and Museum Management" << endl;
        cout << "9. Artifact Ownership and Tracking" << endl;
        cout << "10. Reports and Records" << endl;
        cout << "11. User Management" << endl;
        cout << "12. Exit" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {

            case 1:
                excavationSiteMenu();
                break;

            case 2:
                artifactMenu();
                break;

            case 3:
                classificationMenu();
                break;

            case 4:
                agePeriodMenu();
                break;

            case 5:
                teamMenu();
                break;

            case 6:
                conditionMenu();
                break;

            case 7:
                preservationMenu();
                break;

            case 8:
                restorationMenu();
                break;

            case 9:
                ownershipMenu();
                break;

            case 10:
                reportsMenu();
                break;

            case 11:
                userMenu();
                break;

            case 12:
                cout << "\nThank you for using the system!" << endl;
                break;

            default:
                cout << "\nInvalid choice! Please try again." << endl;
        }

    } while (choice != 12);

    return 0;
}

// TEMPORARY MODULE FUNCTIONS

void excavationSiteMenu() {
    cout << "\nExcavation Site Management selected." << endl;
}

void artifactMenu() {
    cout << "\nArtifact Discovery and Cataloguing selected." << endl;
}

void classificationMenu() {
    cout << "\nArtifact Classification selected." << endl;
}

void agePeriodMenu() {
    cout << "\nAge and Historical Period Management selected." << endl;
}

void teamMenu() {
    cout << "\nExcavation Team Management selected." << endl;
}

void conditionMenu() {
    cout << "\nArtifact Condition Assessment selected." << endl;
}

void preservationMenu() {
    cout << "\nPreservation Management selected." << endl;
}

void restorationMenu() {
    cout << "\nRestoration and Museum Management selected." << endl;
}

void ownershipMenu() {
    cout << "\nArtifact Ownership and Tracking selected." << endl;
}

void reportsMenu() {
    cout << "\nReports and Records selected." << endl;
}

void userMenu() {
    cout << "\nUser Management selected." << endl;
}
