
#include <iostream>
#include <string>
#include <limits>
using namespace std;

// MAXIMUM NUMBER OF SITES
const int MAX_SITES = 100;

// STRUCTURE FOR EXCAVATION SITE
struct ExcavationSite {
    int siteID;
    string siteName;
    string location;
    double latitude;
    double longitude;
    string description;
    string status;
};

struct Artifact {
    int artifactID;
    int siteID;
    string artifactName;
    string discoveryDate;
    string discoverer;
    string excavationGrid;
    string discoveryDescription;
    string photoFilename;
};

// GLOBAL ARRAY
ExcavationSite sites[MAX_SITES];
int siteCount = 0;
int nextSiteID = 1;

// MAXIMUM NUMBER OF ARTIFACTS
const int MAX_ARTIFACTS = 500;

// GLOBAL ARTIFACT ARRAY
Artifact artifacts[MAX_ARTIFACTS];
int artifactCount = 0;
int nextArtifactID = 1;

// FUNCTION DECLARATIONS
void excavationSiteMenu();
void registerSite();
void viewSites();
void searchSite();
void updateSite();
void deleteSite();
int findSite(int id);

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

// ARTIFACT DISCOVERY AND CATALOGUING
void artifactMenu();
void registerArtifact();
void viewArtifacts();
void searchArtifact();
void updateArtifact();
void deleteArtifact();

int findArtifact(int id);
void displayArtifact(int index);

// MAIN FUNCTION
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

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input!" << endl;
            continue;
        }

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

// ============================================
// EXCAVATION SITE MANAGEMENT
// ============================================

void excavationSiteMenu() {

    int choice;

    do {

        cout << "\n================================" << endl;
        cout << "     EXCAVATION SITE MANAGEMENT" << endl;
        cout << "================================" << endl;

        cout << "\n1. Register New Excavation Site" << endl;
        cout << "2. View All Excavation Sites" << endl;
        cout << "3. Search Excavation Site" << endl;
        cout << "4. Update Site Information" << endl;
        cout << "5. Delete Site Record" << endl;
        cout << "6. Return to Main Menu" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "\nInvalid input!" << endl;
            continue;
        }

        switch (choice) {

            case 1:
                registerSite();
                break;

            case 2:
                viewSites();
                break;

            case 3:
                searchSite();
                break;

            case 4:
                updateSite();
                break;

            case 5:
                deleteSite();
                break;

            case 6:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);
}

// ============================================
// REGISTER NEW EXCAVATION SITE
// ============================================

void registerSite() {

    if (siteCount >= MAX_SITES) {
        cout << "\nMaximum number of sites reached!" << endl;
        return;
    }

    ExcavationSite newSite;

    newSite.siteID = nextSiteID++;

    cout << "\n===== REGISTER EXCAVATION SITE =====" << endl;

    cout << "\nSite ID: " << newSite.siteID << endl;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Site Name: ";
    getline(cin, newSite.siteName);

    cout << "Enter Location: ";
    getline(cin, newSite.location);

    cout << "Enter Latitude: ";
    cin >> newSite.latitude;

    cout << "Enter Longitude: ";
    cin >> newSite.longitude;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter Site Description: ";
    getline(cin, newSite.description);

    cout << "\nSite Status" << endl;
    cout << "1. Active" << endl;
    cout << "2. Inactive" << endl;
    cout << "3. Completed" << endl;

    int statusChoice;
    cout << "Select Status: ";
    cin >> statusChoice;

    switch (statusChoice) {
        case 1:
            newSite.status = "Active";
            break;

        case 2:
            newSite.status = "Inactive";
            break;

        case 3:
            newSite.status = "Completed";
            break;

        default:
            newSite.status = "Inactive";
            cout << "Invalid selection. Default status: Inactive." << endl;
    }

    sites[siteCount] = newSite;
    siteCount++;

    cout << "\nExcavation site successfully registered!" << endl;
    cout << "Assigned Site ID: " << newSite.siteID << endl;
}

// ============================================
// VIEW ALL EXCAVATION SITES
// ============================================

void viewSites() {

    if (siteCount == 0) {
        cout << "\nNo excavation sites registered yet." << endl;
        return;
    }

    cout << "\n===== REGISTERED EXCAVATION SITES =====" << endl;

    for (int i = 0; i < siteCount; i++) {

        cout << "\nSite ID: " << sites[i].siteID << endl;
        cout << "Site Name: " << sites[i].siteName << endl;
        cout << "Location: " << sites[i].location << endl;

        cout << "Coordinates: "
             << sites[i].latitude << ", "
             << sites[i].longitude << endl;

        cout << "Description: " << sites[i].description << endl;
        cout << "Status: " << sites[i].status << endl;

        cout << "--------------------------------" << endl;
    }
}

// ============================================
// FIND SITE USING ID
// ============================================

int findSite(int id) {

    for (int i = 0; i < siteCount; i++) {

        if (sites[i].siteID == id) {
            return i;
        }
    }

    return -1;
}

// ============================================
// SEARCH EXCAVATION SITE
// ============================================

void searchSite() {

    int id;

    cout << "\nEnter Site ID to Search: ";
    cin >> id;

    int index = findSite(id);

    if (index == -1) {
        cout << "\nExcavation site not found!" << endl;
        return;
    }

    cout << "\n===== SITE RECORD FOUND =====" << endl;

    cout << "Site ID: " << sites[index].siteID << endl;
    cout << "Site Name: " << sites[index].siteName << endl;
    cout << "Location: " << sites[index].location << endl;
    cout << "Latitude: " << sites[index].latitude << endl;
    cout << "Longitude: " << sites[index].longitude << endl;
    cout << "Description: " << sites[index].description << endl;
    cout << "Status: " << sites[index].status << endl;
}

// ============================================
// UPDATE SITE INFORMATION
// ============================================

void updateSite() {

    int id;

    cout << "\nEnter Site ID to Update: ";
    cin >> id;

    int index = findSite(id);

    if (index == -1) {
        cout << "\nExcavation site not found!" << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\n===== UPDATE SITE INFORMATION =====" << endl;

    cout << "Enter New Site Name: ";
    getline(cin, sites[index].siteName);

    cout << "Enter New Location: ";
    getline(cin, sites[index].location);

    cout << "Enter New Latitude: ";
    cin >> sites[index].latitude;

    cout << "Enter New Longitude: ";
    cin >> sites[index].longitude;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Enter New Description: ";
    getline(cin, sites[index].description);

    cout << "\nSelect New Status" << endl;
    cout << "1. Active" << endl;
    cout << "2. Inactive" << endl;
    cout << "3. Completed" << endl;

    int statusChoice;
    cout << "Enter choice: ";
    cin >> statusChoice;

    switch (statusChoice) {

        case 1:
            sites[index].status = "Active";
            break;

        case 2:
            sites[index].status = "Inactive";
            break;

        case 3:
            sites[index].status = "Completed";
            break;

        default:
            cout << "Invalid status. Previous status retained." << endl;
    }

    cout << "\nSite information successfully updated!" << endl;
}

// ============================================
// DELETE SITE RECORD
// ============================================

void deleteSite() {

    int id;

    cout << "\nEnter Site ID to Delete: ";
    cin >> id;

    int index = findSite(id);

    if (index == -1) {
        cout << "\nExcavation site not found!" << endl;
        return;
    }

    for (int i = index; i < siteCount - 1; i++) {
        sites[i] = sites[i + 1];
    }

    siteCount--;

    cout << "\nSite record successfully deleted!" << endl;
}

// ============================================
// TEMPORARY MODULE FUNCTIONS
// ============================================

// ============================================
// ARTIFACT DISCOVERY AND CATALOGUING MENU
// ============================================

void artifactMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << "   ARTIFACT DISCOVERY AND CATALOGUING" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Register New Artifact" << endl;
        cout << "2. View All Artifacts" << endl;
        cout << "3. Search Artifact" << endl;
        cout << "4. Update Artifact Information" << endl;
        cout << "5. Delete Artifact Record" << endl;
        cout << "6. Return to Main Menu" << endl;

        cout << "\nEnter your choice: ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "\nInvalid input!" << endl;
            continue;
        }

        switch (choice) {

            case 1:
                registerArtifact();
                break;

            case 2:
                viewArtifacts();
                break;

            case 3:
                searchArtifact();
                break;

            case 4:
                updateArtifact();
                break;

            case 5:
                deleteArtifact();
                break;

            case 6:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);
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
