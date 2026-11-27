
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <algorithm>
#include <cctype>
#include <cmath>

#include <fstream>
#include <sstream>
#include <random>

using namespace std;

// MAXIMUM NUMBER OF SITES
const int MAX_SITES = 100;

// STRUCTURE FOR EXCAVATION SITE
struct ExcavationSite {
    string siteID;
    string siteName;
    string location;
    double latitude;
    double longitude;
    string description;
    string status;
};

struct Artifact {
    int artifactID;
    string siteID;
    string artifactName;
    string discoveryDate;
    string discoverer;
    string excavationGrid;
    string discoveryDescription;
    
};

// STRUCTURE FOR ARTIFACT CLASSIFICATION
struct ArtifactClassification {
    int artifactID;
    string category;
    string material;
    string characteristics;
    string classificationNotes;
};

// STRUCTURE FOR ARTIFACT AGE ESTIMATION
struct AgeEstimation {
    int artifactID;
    string historicalPeriod;
    int startingYear;
    int endingYear;
    int minimumAge;
    int maximumAge;
    string referenceBasis;
    string estimationNotes;
};

// STRUCTURE FOR HISTORICAL PERIOD REFERENCES
struct HistoricalPeriod {
    string periodName;
    int startingYear;
    int endingYear;
};

struct ExcavationTeam {
    string teamMemberID;
    string memberName;
    string contactInformation;
    string assignedRole;
    string siteID;
};

vector<ExcavationTeam> excavationTeam;
int nextTeamID = 1;


// STRUCTURE FOR PRESERVATION MANAGEMENT

struct PreservationRecord {

    int preservationID;
    int artifactID;
    string preservationActivity;
    string preservationMethod;
    string responsiblePerson;
    string preservationDate;
    string nextMonitoringDate;
    string preservationStatus;

};

// STRUCTURE FOR RESTORATION FACILITIES AND MUSEUMS

struct HeritageFacility {

    int facilityID;
    string facilityName;
    string facilityType;
    string location;
    string contactPerson;
    string contactNumber;
    string services;

};


// STRUCTURE FOR ARTIFACT TRANSFERS

struct ArtifactTransfer {

    int transferID;
    int artifactID;
    int facilityID;
    string transferDate;
    string transferPurpose;
    string transferStatus;

};

// STRUCTURE FOR USER MANAGEMENT

struct User {

    int userID;
    string fullName;
    string username;
    string password;
    string role;

};



// GLOBAL ARRAY
ExcavationSite sites[MAX_SITES];
int siteCount = 0;


// MAXIMUM NUMBER OF ARTIFACTS
const int MAX_ARTIFACTS = 500;

// GLOBAL ARTIFACT ARRAY
Artifact artifacts[MAX_ARTIFACTS];
int artifactCount = 0;
int nextArtifactID = 1;


// MAXIMUM NUMBER OF CLASSIFICATIONS
const int MAX_CLASSIFICATIONS = 500;

// GLOBAL CLASSIFICATION ARRAY
ArtifactClassification classifications[MAX_CLASSIFICATIONS];
int classificationCount = 0;

// TWO-DIMENSIONAL ARRAY FOR CLASSIFICATION CATEGORIES
string classificationOptions[5][2] = {

    {"Fossils", "Preserved remains or traces of ancient organisms."},

    {"Pottery", "Ceramic objects such as pots, jars, and fragments."},

    {"Tools", "Objects made or used for practical activities."},

    {"Jewelry", "Decorative objects such as rings, beads, and ornaments."},

    {"Other Artifacts", "Other discovered materials that do not fit the listed categories."}

};

// MAXIMUM NUMBER OF AGE ESTIMATION RECORDS
const int MAX_AGE_RECORDS = 500;

// GLOBAL AGE ESTIMATION ARRAY
AgeEstimation ageRecords[MAX_AGE_RECORDS];
int ageCount = 0;

// CURRENT REFERENCE YEAR
const int CURRENT_YEAR = 2026;

// PREDEFINED PHILIPPINE HISTORICAL PERIODS
HistoricalPeriod historicalPeriods[5] = {

    {"Precolonial Period (before 1565)", 0, 1565},

    {"Spanish Colonial Period", 1565, 1898},

    {"American Colonial Period", 1898, 1946},

    {"Japanese Occupation Period", 1942, 1945},

    {"Postwar Period (1946 onward)", 1946, 2026}

};

// EXCAVATION TEAM ARRAY

const int MAX_TEAM_MEMBERS = 100;

ExcavationTeam teamMembers[MAX_TEAM_MEMBERS];


int teamCount = 0;

int nextMemberID = 1;

// PRESERVATION RECORD ARRAY

const int MAX_PRESERVATION = 500;

PreservationRecord preservationRecords[MAX_PRESERVATION];

int preservationCount = 0;
int nextPreservationID = 1;

// RESTORATION AND MUSEUM ARRAYS

const int MAX_FACILITIES = 100;
const int MAX_TRANSFERS = 500;

HeritageFacility facilities[MAX_FACILITIES];
ArtifactTransfer transfers[MAX_TRANSFERS];

int facilityCount = 0;
int transferCount = 0;

int nextFacilityID = 1;
int nextTransferID = 1;


// USER MANAGEMENT ARRAY

const int MAX_USERS = 100;

User users[MAX_USERS];

int userCount = 0;
int nextUserID = 1;



// FUNCTION DECLARATIONS

//EXCAVATION SITE MANAGEMENT
void excavationSiteMenu();
void registerSite();
void viewSites();
void searchSite();
void updateSite();
void deleteSite();
int findSite(string id);
string generateSiteID();

void artifactMenu();
void classificationMenu();
void agePeriodMenu();
void teamMenu();
void preservationMenu();
void restorationMenu();
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

// ARTIFACT CLASSIFICATION
void classificationMenu();
void classifyArtifact();
void viewClassifications();
void searchClassification();
void updateClassification();
void deleteClassification();

int findClassification(int id);
void displayClassification(int index);

string toLowerCase(string text);

string suggestClassification(
    string artifactName,
    string material,
    string characteristics
);

string confirmClassification(string suggested);

// AGE ESTIMATION AND HISTORICAL PERIOD MANAGEMENT
void ageEstimationMenu();
void estimateArtifactAge();
void viewAgeEstimates();
void searchAgeEstimate();
void updateAgeEstimate();
void deleteAgeEstimate();

int findAgeEstimate(int id);
void displayAgeEstimate(int index);
void calculateAgeRange(int periodChoice, int &minimumAge, int &maximumAge);





// TEAM MANAGEMENT
void registerTeamMember();
void viewTeamMembers();
void searchTeamMember();
void updateTeamMember();
void deleteTeamMember();

// SEARCH FUNCTIONS
int findTeamMember(int id);

// DISPLAY FUNCTIONS
void displayTeamMember(int index);

// PRESERVATION MANAGEMENT FUNCTIONS

void preservationMenu();

void addPreservationRecord();
void viewPreservationRecords();
void searchPreservationRecord();
void updatePreservationRecord();
void deletePreservationRecord();

int findPreservationRecord(int id);

void displayPreservationRecord(int index);


// RESTORATION AND MUSEUM FUNCTIONS

void restorationMuseumMenu();

// FACILITY MANAGEMENT
void registerFacility();
void viewFacilities();
void searchFacility();
void updateFacility();
void deleteFacility();

// ARTIFACT TRANSFER MANAGEMENT
void recordArtifactTransfer();
void viewArtifactTransfers();
void searchArtifactTransfer();

// SEARCH FUNCTIONS
int findFacility(int id);
int findArtifactTransfer(int id);

// DISPLAY FUNCTIONS
void displayFacility(int index);
void displayArtifactTransfer(int index);


// REPORTS AND RECORDS FUNCTIONS

void reportsMenu();


void generateSystemSummary();
void displaySite(int index);
void generateSiteReport();
void generateArtifactReport();
void generateActivityReport();



int findUser(int id);
void displayUser(int index);

void registerUser();
void login();
void userAccountMenu();
bool loginUser();
void userMenu();
void adminMenu();
void adminLogin();


// EXCAVATION SITE FILE HANDLING

void saveSites();
void loadSites();
//artifact catalog FH
void saveArtifacts();
void loadArtifacts();
void saveClassifications();
void loadClassifications();
string readValidatedName(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        bool valid = !input.empty();
        bool hasLetter = false;

        for (char c : input) {
            if (isalpha(static_cast<unsigned char>(c))) {
                hasLetter = true;
            }
            else if (c != ' ' && c != '-') {
                valid = false;
                break;
            }
        }

        if (valid && hasLetter) {
            return input;
        }

        cout << "Invalid name! Use letters, spaces, and hyphens only.\n";
    }
}

string readValidatedWords(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        bool valid = !input.empty();
        bool hasLetter = false;

        for (char c : input) {
            if (isalpha(static_cast<unsigned char>(c))) {
                hasLetter = true;
            }
            else if (c != ' ') {
                valid = false;
                break;
            }
        }

        if (valid && hasLetter) {
            return input;
        }

        cout << "Invalid input! Please enter words using letters and spaces only.\n";
    }
}

string readValidatedDescription(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        bool valid = !input.empty();

        for (char c : input) {
            if (!isalnum(static_cast<unsigned char>(c))
                && c != ' ') {
                valid = false;
                break;
            }
        }

        if (valid) {
            return input;
        }

        cout << "Invalid description! Use letters, numbers, and spaces only.\n";
    }
}

int readValidatedInteger(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        bool valid = !input.empty();

        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }

        if (valid) {
            try {
                size_t position;
                long long number = stoll(input, &position);

                if (position == input.length() &&
                    number <= numeric_limits<int>::max()) {
                    return static_cast<int>(number);
                }
            }
            catch (...) {
                // Invalid or out-of-range number.
            }
        }

        cout << "Invalid input! Please enter whole numbers only.\n";
    }
}


string readValidatedDigits(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin >> ws, input);

        bool valid = (input.length() == 11);

        for (char c : input) {
            if (!isdigit(static_cast<unsigned char>(c))) {
                valid = false;
                break;
            }
        }

        if (valid) {
            return input;
        }

        cout << "Invalid input! Please enter exactly 11 digits only.\n";
    }
}



void registerUser() {
    string fullname, username, password, confirmPassword;
    string savedUsername, savedPassword, savedName;

    cout << "\n===== CREATE USER ACCOUNT =====\n";

    fullname = readValidatedName("Enter Full Name: ");
    username = readValidatedWords("Create Username: ");

    if (username.empty() || username.find('|') != string::npos) {
        cout << "Invalid username.\n";
        return;
    }

    // Check if username already exists
    ifstream file("users.txt");
    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, savedName, '|');
        getline(ss, savedUsername, '|');
        getline(ss, savedPassword, '|');

        if (username == savedUsername) {
            cout << "Username already exists!\n";
            file.close();
            return;
        }
    }

    file.close();

    // Password requirements
    cout << "\nPASSWORD REQUIREMENTS:\n";
    cout << "- Exactly 8 characters\n";
    cout << "- Must contain at least one letter (A-Z)\n";
    cout << "- Must contain at least one number (0-9)\n";
    cout << "- Must contain at least one special character\n";
    cout << "- Allowed special characters: _ - * @ # $ % & ! + ? .\n";
    cout << "- No spaces or other special characters allowed\n";

    bool validPassword;

do {
    bool hasLetter = false;
    bool hasNumber = false;
    bool hasSpecial = false;
    validPassword = true;

    cout << "\nCreate Password: ";
    getline(cin, password);

    if (password.length() != 8) {
        validPassword = false;
    }

    for (char c : password) {
        if (isalpha(static_cast<unsigned char>(c))) {
            hasLetter = true;
        }
        else if (isdigit(static_cast<unsigned char>(c))) {
            hasNumber = true;
        }
        else if (string("_-*@#$%&!+?.").find(c) != string::npos) {
            hasSpecial = true;
        }
        else {
            validPassword = false;
        }
    }

    if (!hasLetter || !hasNumber || !hasSpecial) {
        validPassword = false;
    }

    if (!validPassword) {
        cout << "\nInvalid password!\n";
        cout << "Your password must follow all the requirements.\n";
    }

} while (!validPassword);

    cout << "Confirm Password: ";
    getline(cin, confirmPassword);

    if (password != confirmPassword) {
        cout << "Passwords do not match!\n";
        return;
    }

    // Save account
    ofstream output("users.txt", ios::app);

    output << fullname << "|"
           << username << "|"
           << password << "\n";

    output.close();

    cout << "\nAccount created successfully!\n";
    cout << "You can now log in.\n";
}

bool loginUser() {
    string username, password;
    string savedName, savedUsername, savedPassword;

    cout << "\n===== USER LOGIN =====\n";

    

            username = readValidatedWords("Username: ");

    cout << "Password: ";
    getline(cin, password);

    ifstream file("users.txt");

    string line;

    while (getline(file, line)) {
        stringstream ss(line);

        getline(ss, savedName, '|');
        getline(ss, savedUsername, '|');
        getline(ss, savedPassword, '|');

        if (username == savedUsername &&
            password == savedPassword) {

            file.close();

            cout << "\nLogin successful!\n";
            cout << "Welcome, " << savedName << "!\n";

            return true;
        }
    }

    file.close();

    cout << "\nInvalid username or password.\n";

    return false;
}

void userAccountMenu() {
    int choice;

    do {
        cout << "\n===== USER ACCOUNT =====\n";
        cout << "[1] Log In\n";
        cout << "[2] Create Account\n";
        cout << "[3] Back\n";

                choice = readValidatedInteger("Enter choice: ");

        

        if (choice == 1) {
            if (loginUser()) {
                userMenu();
            }
        }
        else if (choice == 2) {
            registerUser();
        }
        else if (choice == 3) {
            cout << "Returning to main menu...\n";
        }
        else {
            cout << "Invalid choice.\n";
        }

    }
     while (choice != 3);
}

void ExcavationTeamManagement();
void userMenu() {
    int choice;

    do {
        cout << "\n============================================================== \n";
        cout << "                          USER MENU\n"; 
        cout << "================================================================\n";
        cout << "[1] Excavation Site Management\n";
        cout << "[2] Artifact Discovery and Cataloguing\n";
        cout << "[3] Artifact Classification\n";
        cout << "[4] Artifact Age Estimation\n";
        cout << "[5] Excavation Team Management\n";
        cout << "[6] Preservation Management\n";
        cout << "[7] Log Out\n";
        cout << "================================================================\n";
                choice = readValidatedInteger("Enter your choice: ");
        

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
                ageEstimationMenu();
                break;

                case 5:
    ExcavationTeamManagement();
    break;

case 6:
    preservationMenu();
    break;

            case 7:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 7);
}

void trackingReportsMenu();
void adminMenu() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "               ADMIN MENU\n";
        cout << "========================================\n";
        cout << "[1] Tracking, Reports and Records\n";
        cout << "[2] Restoration and Museum Management\n";
        cout << "[3] Log Out\n";
        cout << "========================================\n";
                choice = readValidatedInteger("Enter your choice: ");
        

        switch (choice) {
            case 1:
                trackingReportsMenu();
                break;

            case 2:
                restorationMuseumMenu();
                break;

            case 3:
                cout << "\nLogging out...\n";
                break;

            default:
                cout << "\nInvalid choice. Please try again.\n";
        }

    } while (choice != 3);
}


void login() {
    int choice;

    string username;
    string password;

    do {
        cout << "\n========================================\n";
        cout << "       ARCHAEOLOGICAL MANAGEMENT SYSTEM\n";
        cout << "========================================\n";
        cout << "\n";
        cout << "                 LOGIN\n";
        cout << "\n";
        cout << "[1] User\n";
        cout << "[2] Admin\n";
        cout << "[3] Exit\n";
        cout << "========================================\n";
                choice = readValidatedInteger("Enter your choice: ");
        


 if (choice == 1) {

    userAccountMenu();

}
else if (choice == 2) {

            cout << "\nEnter Username: ";
            cin >> username;

            cout << "Enter Password: ";
            cin >> password;

                if (username == "admin" && password == "admin123") {
                    cout << "\nAdmin Login Successful!\n";
                    adminMenu();
                }
                else {
                    cout << "\nInvalid username or password.\n";
                }
            

        } else if (choice == 3) {
            cout << "\nExiting Archaeological Management System...\n";
        }
        else {
            cout << "\nInvalid choice. Please try again.\n";
        }


    } while (choice != 3);
}

void trackingReportsMenu() {
    int choice;

    do {
        cout << "\n========================================\n";
        cout << "       TRACKING, REPORTS AND RECORDS\n";
        cout << "========================================\n";
        cout << "[1] View Excavation Site Records\n";
        cout << "[2] View Artifact Catalogue\n";
        cout << "[3] View Classification Records\n";
        cout << "[4] View Age Estimation Records\n";
        cout << "[5] View Preservation Records\n";
        cout << "[6] Back to Admin Menu\n";
        cout << "========================================\n";
                choice = readValidatedInteger("Enter your choice: ");
        

        switch (choice) {
            case 1:
                viewSites();
                break;

            case 2:
                viewArtifacts();
                break;

            case 3:
                viewClassifications();
                break;

            case 4:
                viewAgeEstimates();
                break;

            case 5:
                viewPreservationRecords();
                break;

            case 6:
                cout << "\nReturning to Admin Menu...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);
}

// MAIN FUNCTION
int main() {
     loadSites();
    loadArtifacts();
    loadClassifications();

login();
    return 0;
}
// EXCAVATION SITE MANAGEMENT

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

                choice = readValidatedInteger("\nEnter your choice: ");
        

        

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



bool isValidText(string input) {
    bool hasLetter = false;

    if (input.empty()) {
        return false;
    }

    for (int i = 0; i < input.length(); i++) {
        char ch = input[i];

        if (isalpha(static_cast<unsigned char>(ch))) {
            hasLetter = true;
        }
        else if (isspace(static_cast<unsigned char>(ch)) ||
                 ch == ',' || ch == '.' ||
                 ch == '-' || ch == '\'') {
            continue;
        }
        else {
            return false;
        }
    }

    return hasLetter;
}


string readValidatedText(string prompt) {
    string input;

    while (true) {
        cout << prompt;
        getline(cin, input);

        if (isValidText(input)) {
            return input;
        }

        cout << "Invalid input! Please enter letters and words only.\n";
    }
}


double readValidatedDouble(string prompt, double minimum, double maximum) {
    string input;
    double number;

    while (true) {
        cout << prompt;
        getline(cin, input);

        try {
            size_t position;
            number = stod(input, &position);

            if (position != input.length() ||
                !isfinite(number) ||
                number < minimum ||
                number > maximum) {

                cout << "Invalid input! Please enter a valid number within the allowed range.\n";
            }
            else {
                return number;
            }
        }
        catch (...) {
            cout << "Invalid input! Numbers only. Please try again.\n";
        }
    }
}

// REGISTER NEW EXCAVATION SITE
// GENERATE UNIQUE 8-CHARACTER EXCAVATION SITE ID

string generateSiteID() {

    const string characters =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

    random_device rd;
    mt19937 generator(rd());

    uniform_int_distribution<int> distribution(
        0, static_cast<int>(characters.length()) - 1
    );

    string newID;
    bool exists;

    do {
        newID.clear();

        for (int i = 0; i < 8; i++) {
            newID += characters[distribution(generator)];
        }

        exists = false;

        for (int i = 0; i < siteCount; i++) {
            if (sites[i].siteID == newID) {
                exists = true;
                break;
            }
        }

    } while (exists);

    return newID;
}

void registerSite() {

    if (siteCount >= MAX_SITES) {
        cout << "\nSite storage is full!\n";
        return;
    }

    ExcavationSite newSite;

    cout << "\n========================================\n";
    cout << "       REGISTER EXCAVATION SITE\n";
    cout << "========================================\n";

    newSite.siteID = generateSiteID();

    newSite.siteName = readValidatedText("Enter Site Name: ");

    newSite.location = readValidatedText("Enter Location: ");

    newSite.latitude = readValidatedDouble(
        "Enter Latitude: ", -90.0, 90.0
    );

    newSite.longitude = readValidatedDouble(
        "Enter Longitude: ", -180.0, 180.0
    );

    newSite.description = readValidatedText("Enter Description: ");

    cout << "\nSelect Site Status:\n";
    cout << "[1] Active\n";
    cout << "[2] Inactive\n";
    cout << "[3] Completed\n";

    string statusChoice;

    while (true) {
        cout << "Enter Choice: ";
        getline(cin, statusChoice);

        if (statusChoice == "1") {
            newSite.status = "Active";
            break;
        }
        else if (statusChoice == "2") {
            newSite.status = "Inactive";
            break;
        }
        else if (statusChoice == "3") {
            newSite.status = "Completed";
            break;
        }
        else {
            cout << "Invalid choice! Please select 1, 2, or 3.\n";
        }
    }

    sites[siteCount] = newSite;

    siteCount++;

    // Save the updated site records.
saveSites();
    

    cout << "\nEXCAVATION SITE REGISTERED SUCCESSFULLY!\n";
    cout << "Site ID: " << newSite.siteID << endl;
    cout << "Site Name: " << newSite.siteName << endl;
    cout << "Location: " << newSite.location << endl;
    cout << "Latitude: " << newSite.latitude << endl;
    cout << "Longitude: " << newSite.longitude << endl;
    cout << "Description: " << newSite.description << endl;
    cout << "Status: " << newSite.status << endl;
}

// VIEW ALL EXCAVATION SITES


    
void displaySite(int index) {

    if (index < 0 || index >= siteCount) {
        cout << "\nInvalid excavation site index." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "       EXCAVATION SITE DETAILS" << endl;
    cout << "========================================" << endl;

    cout << "Site ID: " << sites[index].siteID << endl;
    cout << "Site Name: " << sites[index].siteName << endl;
    cout << "Location: " << sites[index].location << endl;
    cout << "Latitude: " << sites[index].latitude << endl;
    cout << "Longitude: " << sites[index].longitude << endl;
    cout << "Description: " << sites[index].description << endl;
    cout << "Status: " << sites[index].status << endl;

    cout << "========================================" << endl;
}


void viewSites() {

    cout << "\n========================================" << endl;
    cout << "       REGISTERED EXCAVATION SITES" << endl;
    cout << "========================================" << endl;

    if (siteCount == 0) {
        cout << "No excavation sites registered yet." << endl;
        return;
    }

    cout << "Total Registered Sites: " << siteCount << endl;

    for (int i = 0; i < siteCount; i++) {
        displaySite(i);
    }
}


// FIND SITE USING ID

int findSite(string id) {

    for (int i = 0; i < siteCount; i++) {

        if (sites[i].siteID == id) {
            return i;
        }
    }

    return -1;
}

// SEARCH EXCAVATION SITE

void searchSite() {

    string id;

    cout << "\nEnter Site ID to Search: ";
    getline(cin >> ws, id);

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

// UPDATE SITE INFORMATION

void updateSite() {

    string id;

    cout << "\nEnter Site ID to Update: ";
    getline(cin >> ws, id);

    int index = findSite(id);

    if (index == -1) {
        cout << "\nExcavation site not found!" << endl;
        return;
    }

    cout << "\n===== UPDATE SITE INFORMATION =====" << endl;

    sites[index].siteName =
        readValidatedName("Enter New Site Name: ");

    sites[index].location =
        readValidatedText("Enter New Location: ");

    sites[index].latitude = readValidatedDouble(
        "Enter New Latitude: ", -90.0, 90.0
    );

    sites[index].longitude = readValidatedDouble(
        "Enter New Longitude: ", -180.0, 180.0
    );

    sites[index].description =
        readValidatedText("Enter New Description: ");

    cout << "\nSelect New Status" << endl;
    cout << "1. Active" << endl;
    cout << "2. Inactive" << endl;
    cout << "3. Completed" << endl;

    int statusChoice;

    do {
        statusChoice = readValidatedInteger("Enter choice: ");

        if (statusChoice < 1 || statusChoice > 3) {
            cout << "Invalid status! Please select 1, 2, or 3.\n";
        }

    } while (statusChoice < 1 || statusChoice > 3);

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
    }

    cout << "\nSite information successfully updated!" << endl;
saveSites();
}
// DELETE SITE RECORD

void deleteSite() {

    string id;

    cout << "\nEnter Site ID to Delete: ";
    getline(cin >> ws, id);

    int index = findSite(id);

    if (index == -1) {
        cout << "\nExcavation site not found!" << endl;
        return;
    }

    for (int i = 0; i < artifactCount; i++) {
        if (artifacts[i].siteID == id) {
            cout << "\nCannot delete this site! "
                 << "Artifacts are still assigned to it.\n";
            return;
        }
    }

    for (int i = 0; i < excavationTeam.size(); i++) {
        if (excavationTeam[i].siteID == id) {
            cout << "\nCannot delete this site! "
                 << "Team members are still assigned to it.\n";
            return;
        }
    }
    
    for (int i = index; i < siteCount - 1; i++) {
        sites[i] = sites[i + 1];
    }

    siteCount--;
    saveSites();

    cout << "\nSite record successfully deleted!" << endl;
}

// ========================================
// EXCAVATION SITE FILE HANDLING
// ========================================

// SAVE EXCAVATION SITES TO FILE

void saveSites() {

    ofstream file("sites.txt");

    if (!file.is_open()) {
        cout << "\nError: Unable to save excavation site records.\n";
        return;
    }

    for (int i = 0; i < siteCount; i++) {

        file << sites[i].siteID << "|"
             << sites[i].siteName << "|"
             << sites[i].location << "|"
             << sites[i].latitude << "|"
             << sites[i].longitude << "|"
             << sites[i].description << "|"
             << sites[i].status << "\n";
    }

    file.close();
}


// LOAD EXCAVATION SITES FROM FILE

void loadSites() {

    ifstream file("sites.txt");

    if (!file.is_open()) {
        // The file does not exist yet.
        // It will be created when the first site is saved.
        return;
    }

    string line;

    siteCount = 0;

    while (getline(file, line) && siteCount < MAX_SITES) {

        stringstream ss(line);
        ExcavationSite loadedSite;
        string latitudeText;
        string longitudeText;

        getline(ss, loadedSite.siteID, '|');
        getline(ss, loadedSite.siteName, '|');
        getline(ss, loadedSite.location, '|');
        getline(ss, latitudeText, '|');
        getline(ss, longitudeText, '|');
        getline(ss, loadedSite.description, '|');
        getline(ss, loadedSite.status);

        try {

            loadedSite.latitude = stod(latitudeText);
            loadedSite.longitude = stod(longitudeText);

            sites[siteCount] = loadedSite;
            siteCount++;

        }
        catch (...) {

            // Skip a record if its coordinates are invalid.
            continue;
        }
    }

    file.close();
}

// ARTIFACT DISCOVERY AND CATALOGUING MENU

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

                choice = readValidatedInteger("\nEnter your choice: ");

        

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

bool isValidDiscoveryDate(string date) {
    if (date.length() != 10 ||
        date[2] != '/' || date[5] != '/') {
        return false;
    }

    for (int i = 0; i < 10; i++) {
        if (i == 2 || i == 5)
            continue;

        if (!isdigit(static_cast<unsigned char>(date[i])))
            return false;
    }

    int month = stoi(date.substr(0, 2));
    int day = stoi(date.substr(3, 2));
    int year = stoi(date.substr(6, 4));

    if (month < 1 || month > 12 || year < 1)
        return false;

    int daysInMonth[] = {
        31, 28, 31, 30, 31, 30,
        31, 31, 30, 31, 30, 31
    };

    if (year % 400 == 0 ||
        (year % 4 == 0 && year % 100 != 0)) {
        daysInMonth[1] = 29;
    }

    if (day < 1 || day > daysInMonth[month - 1])
        return false;

    return true;
}

// REGISTER NEW ARTIFACT

void registerArtifact() {

    if (artifactCount >= MAX_ARTIFACTS) {
        cout << "\nMaximum number of artifacts reached!" << endl;
        return;
    }

    if (siteCount == 0) {
        cout << "\nNo excavation sites registered yet." << endl;
        cout << "Please register an excavation site first." << endl;
        return;
    }

    Artifact newArtifact;

    cout << "\n===== REGISTER NEW ARTIFACT =====" << endl;

    cout << "\n===== AVAILABLE EXCAVATION SITES =====" << endl;

    viewSites();

        cout << "\nEnter Excavation Site ID: ";
getline(cin >> ws, newArtifact.siteID);

    int siteIndex = findSite(newArtifact.siteID);

    

    if (siteIndex == -1) {
        cout << "\nInvalid Site ID! Artifact registration cancelled." << endl;
        return;
    }

    newArtifact.artifactID = nextArtifactID++;

    cout << "\nArtifact ID: " << newArtifact.artifactID << endl;
    cout << "Excavation Site: " << sites[siteIndex].siteName << endl;

            newArtifact.artifactName =
        readValidatedName("\nEnter Artifact Name: ");

    cout << "\nNOTICE: Date format must be MM/DD/YYYY.\n";
cout << "Example: 11/27/2026\n";

do {
    cout << "Enter Discovery Date: ";
    getline(cin, newArtifact.discoveryDate);

    if (!isValidDiscoveryDate(newArtifact.discoveryDate)) {
        cout << "Invalid date! Please use MM/DD/YYYY "
             << "and enter a valid calendar date.\n";
    }

} while (!isValidDiscoveryDate(newArtifact.discoveryDate));

    newArtifact.discoverer =
        readValidatedName("Enter Discoverer's Name: ");

    cout << "Enter Excavation Grid or Area: ";
    getline(cin, newArtifact.excavationGrid);

    newArtifact.discoveryDescription =
    readValidatedDescription("Enter Discovery Description: ");

    

    artifacts[artifactCount] = newArtifact;
    artifactCount++;
    saveArtifacts();

    cout << "\nArtifact successfully registered!" << endl;
    cout << "Assigned Artifact ID: " << newArtifact.artifactID << endl;
}

// VIEW ALL ARTIFACTS

void viewArtifacts() {

    if (artifactCount == 0) {
        cout << "\nNo artifacts registered yet." << endl;
        return;
    }

    cout << "\n===== REGISTERED ARTIFACTS =====" << endl;

    for (int i = 0; i < artifactCount; i++) {

        displayArtifact(i);

    }
}
// DISPLAY ARTIFACT INFORMATION

void displayArtifact(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Artifact ID: " << artifacts[index].artifactID << endl;
    cout << "Artifact Name: " << artifacts[index].artifactName << endl;
    cout << "Excavation Site ID: " << artifacts[index].siteID << endl;

    int siteIndex = findSite(artifacts[index].siteID);

    if (siteIndex != -1) {
        cout << "Excavation Site: " << sites[siteIndex].siteName << endl;
    }

    cout << "Discovery Date: " << artifacts[index].discoveryDate << endl;
    cout << "Discoverer: " << artifacts[index].discoverer << endl;
    cout << "Excavation Grid: " << artifacts[index].excavationGrid << endl;
    cout << "Description: " << artifacts[index].discoveryDescription << endl;
    
    cout << "----------------------------------------" << endl;
}

// FIND ARTIFACT USING ID

int findArtifact(int id) {

    for (int i = 0; i < artifactCount; i++) {

        if (artifacts[i].artifactID == id) {
            return i;
        }
    }

    return -1;
}

// SEARCH ARTIFACT

void searchArtifact() {

        int id = readValidatedInteger("\nEnter Artifact ID to Search: ");

    int index = findArtifact(id);

    if (index == -1) {
        cout << "\nArtifact not found!" << endl;
        return;
    }

    cout << "\n===== ARTIFACT RECORD FOUND =====" << endl;

    displayArtifact(index);
}

// UPDATE ARTIFACT INFORMATION

void updateArtifact() {

    

        int id = readValidatedInteger("\nEnter Artifact ID to Update: ");

    int index = findArtifact(id);

    if (index == -1) {
        cout << "\nArtifact not found!" << endl;
        return;
    }

    cout << "\n===== UPDATE ARTIFACT INFORMATION =====" << endl;

    cout << "\nCurrent Artifact Name: " << artifacts[index].artifactName << endl;

    cout << "\n===== AVAILABLE EXCAVATION SITES =====" << endl;
    viewSites();

string newSiteID;

    cout << "\nEnter New Excavation Site ID: ";
    getline(cin >> ws, newSiteID);

    int siteIndex = findSite(newSiteID);

    if (siteIndex == -1) {
        cout << "\nInvalid Site ID! Update cancelled." << endl;
        return;
    }

    artifacts[index].siteID = newSiteID;

        artifacts[index].artifactName =
        readValidatedName("Enter New Artifact Name: ");

    cout << "\nNOTICE: Date format must be MM/DD/YYYY.\n";
cout << "Example: 11/27/2026\n";

do {
    cout << "Enter New Discovery Date: ";
    getline(cin, artifacts[index].discoveryDate);

    if (!isValidDiscoveryDate(artifacts[index].discoveryDate)) {
        cout << "Invalid date! Please use MM/DD/YYYY "
             << "and enter a valid calendar date.\n";
    }

} while (!isValidDiscoveryDate(artifacts[index].discoveryDate));

    artifacts[index].discoverer =
        readValidatedName("Enter New Discoverer's Name: ");

    cout << "Enter New Excavation Grid or Area: ";
    getline(cin, artifacts[index].excavationGrid);

    artifacts[index].discoveryDescription =
    readValidatedDescription("Enter New Discovery Description: ");

    

    cout << "\nArtifact information successfully updated!" << endl;
    saveArtifacts();
}

// DELETE ARTIFACT RECORD

void deleteArtifact() {

        int id = readValidatedInteger("\nEnter Artifact ID to Delete: ");
    int index = findArtifact(id);

    if (index == -1) {
        cout << "\nArtifact not found!" << endl;
        return;
    }

    cout << "\nArtifact Name: " << artifacts[index].artifactName << endl;

    char confirmation;

    cout << "Are you sure you want to delete this artifact? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {

        for (int i = index; i < artifactCount - 1; i++) {
            artifacts[i] = artifacts[i + 1];
        }

        artifactCount--;
        saveArtifacts();

        cout << "\nArtifact record successfully deleted!" << endl;

    } else {

        cout << "\nDeletion cancelled." << endl;
    }
}

// ========================================
// ARTIFACT FILE HANDLING
// ========================================

// SAVE ARTIFACT RECORDS

void saveArtifacts() {

    ofstream file("artifacts.txt");

    if (!file.is_open()) {
        cout << "\nError: Unable to save artifact records.\n";
        return;
    }

    for (int i = 0; i < artifactCount; i++) {

        file << artifacts[i].artifactID << "|"
             << artifacts[i].siteID << "|"
             << artifacts[i].artifactName << "|"
             << artifacts[i].discoveryDate << "|"
             << artifacts[i].discoverer << "|"
             << artifacts[i].excavationGrid << "|"
             << artifacts[i].discoveryDescription << "\n";
    }

    file.close();
}


// LOAD ARTIFACT RECORDS

void loadArtifacts() {

    ifstream file("artifacts.txt");

    if (!file.is_open()) {
        return;
    }

    string line;

    artifactCount = 0;
    nextArtifactID = 1;

    while (getline(file, line) &&
           artifactCount < MAX_ARTIFACTS) {

        stringstream ss(line);
        Artifact loadedArtifact;

        string idText;

        getline(ss, idText, '|');

        try {
            loadedArtifact.artifactID = stoi(idText);
        }
        catch (...) {
            continue;
        }

        getline(ss, loadedArtifact.siteID, '|');
        getline(ss, loadedArtifact.artifactName, '|');
        getline(ss, loadedArtifact.discoveryDate, '|');
        getline(ss, loadedArtifact.discoverer, '|');
        getline(ss, loadedArtifact.excavationGrid, '|');
        getline(ss, loadedArtifact.discoveryDescription, '|');

        artifacts[artifactCount] = loadedArtifact;

        artifactCount++;

        if (loadedArtifact.artifactID >= nextArtifactID) {
            nextArtifactID = loadedArtifact.artifactID + 1;
        }
    }

    file.close();
}

// ARTIFACT CLASSIFICATION MENU

void classificationMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << "        ARTIFACT CLASSIFICATION" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Classify Artifact" << endl;
        cout << "2. View All Classifications" << endl;
        cout << "3. Search Classification" << endl;
        cout << "4. Update Classification" << endl;
        cout << "5. Delete Classification" << endl;
        cout << "6. Return to Main Menu" << endl;

                choice = readValidatedInteger("\nEnter your choice: ");

        

        switch (choice) {

            case 1:
                classifyArtifact();
                break;

            case 2:
                viewClassifications();
                break;

            case 3:
                searchClassification();
                break;

            case 4:
                updateClassification();
                break;

            case 5:
                deleteClassification();
                break;

            case 6:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);
}

// CONVERT TEXT TO LOWERCASE

string toLowerCase(string text) {

    for (int i = 0; i < text.length(); i++) {
        text[i] = tolower(text[i]);
    }

    return text;
}


// SUGGEST ARTIFACT CLASSIFICATION

string suggestClassification(
    string artifactName,
    string material,
    string characteristics
) {

    artifactName = toLowerCase(artifactName);
    material = toLowerCase(material);
    characteristics = toLowerCase(characteristics);

    string information = artifactName + " " +
                         material + " " +
                         characteristics;

    // FOSSILS
    if (information.find("fossil") != string::npos ||
        information.find("fossilized") != string::npos) {

        return "Fossils";
    }

    // POTTERY
    else if (information.find("pottery") != string::npos ||
             information.find("ceramic") != string::npos ||
             information.find("clay") != string::npos ||
             information.find("pot fragment") != string::npos ||
             information.find("jar") != string::npos) {

        return "Pottery";
    }

    // JEWELRY
    else if (information.find("jewelry") != string::npos ||
             information.find("jewellery") != string::npos ||
             information.find("bead") != string::npos ||
             information.find("necklace") != string::npos ||
             information.find("ring") != string::npos ||
             information.find("pendant") != string::npos ||
             information.find("ornament") != string::npos) {

        return "Jewelry";
    }

    // TOOLS
    else if (information.find("tool") != string::npos ||
             information.find("blade") != string::npos ||
             information.find("axe") != string::npos ||
             information.find("scraper") != string::npos ||
             information.find("spearhead") != string::npos) {

        return "Tools";
    }

    // NO CLEAR MATCH
    else {

        return "No clear match";
    }
}


// CONFIRM ARTIFACT CLASSIFICATION

string confirmClassification(string suggested) {

    cout << "\n===== SYSTEM CLASSIFICATION RESULT =====" << endl;

    if (suggested != "No clear match") {

        cout << "Suggested Category: " << suggested << endl;

        char confirmation;

        cout << "Confirm this classification? (Y/N): ";
        cin >> confirmation;

        if (confirmation == 'Y' || confirmation == 'y') {
            return suggested;
        }
    }
    else {

        cout << "The system could not identify a clear category." << endl;
    }

    cout << "\n===== SELECT CLASSIFICATION MANUALLY =====" << endl;

    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << classificationOptions[i][0] << endl;
    }

        int choice = readValidatedInteger("\nEnter your preferred category: ");

    if (choice >= 1 && choice <= 5) {
        return classificationOptions[choice - 1][0];
    }

    cout << "\nInvalid selection. Classification cancelled." << endl;

    return "";
}

// CLASSIFY ARTIFACT

void classifyArtifact() {

    if (artifactCount == 0) {
        cout << "\nNo registered artifacts available." << endl;
        return;
    }

    if (classificationCount >= MAX_CLASSIFICATIONS) {
        cout << "\nMaximum number of classifications reached!" << endl;
        return;
    }

        cout << "\n===== AUTOMATIC ARTIFACT CLASSIFICATION =====" << endl;

    viewArtifacts();

    int id = readValidatedInteger("\nEnter Artifact ID to Classify: ");

    int artifactIndex = findArtifact(id);

    if (artifactIndex == -1) {
        cout << "\nArtifact not found!" << endl;
        return;
    }

    int existingIndex = findClassification(id);

    if (existingIndex != -1) {
        cout << "\nThis artifact already has a classification." << endl;
        cout << "Use Update Classification to modify it." << endl;
        return;
    }

    ArtifactClassification newClassification;

    newClassification.artifactID = id;

    cout << "\nArtifact Name: "
         << artifacts[artifactIndex].artifactName << endl;

    cout << "\nEnter Artifact Material: ";
    getline(cin, newClassification.material);

    cout << "Enter Artifact Characteristics: ";
    getline(cin, newClassification.characteristics);

    // SYSTEM GENERATES CLASSIFICATION SUGGESTION

    string suggested = suggestClassification(
        artifacts[artifactIndex].artifactName,
        newClassification.material,
        newClassification.characteristics
    );

    // USER CONFIRMS OR CORRECTS THE SUGGESTION

    newClassification.category = confirmClassification(suggested);

    if (newClassification.category == "") {
        cout << "\nClassification cancelled." << endl;
        return;
    }

    cout << "\nEnter Additional Classification Notes: ";
    getline(cin, newClassification.classificationNotes);

    classifications[classificationCount] = newClassification;

    classificationCount++;
saveClassifications();
    cout << "\nArtifact successfully classified!" << endl;

    cout << "Artifact ID: " << id << endl;
    cout << "Artifact Name: "
         << artifacts[artifactIndex].artifactName << endl;
    cout << "Final Category: "
         << newClassification.category << endl;
}


// VIEW ALL CLASSIFICATIONS

void viewClassifications() {

    if (classificationCount == 0) {
        cout << "\nNo artifact classifications recorded yet." << endl;
        return;
    }

    cout << "\n===== ARTIFACT CLASSIFICATION RECORDS =====" << endl;

    for (int i = 0; i < classificationCount; i++) {

        displayClassification(i);

    }
}

// DISPLAY CLASSIFICATION INFORMATION

void displayClassification(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Artifact ID: "
         << classifications[index].artifactID << endl;

    int artifactIndex = findArtifact(classifications[index].artifactID);

    if (artifactIndex != -1) {

        cout << "Artifact Name: "
             << artifacts[artifactIndex].artifactName << endl;
    }

    cout << "Category: "
         << classifications[index].category << endl;

    cout << "Material: "
         << classifications[index].material << endl;

    cout << "Characteristics: "
         << classifications[index].characteristics << endl;

    cout << "Classification Notes: "
         << classifications[index].classificationNotes << endl;

    cout << "----------------------------------------" << endl;
}

// FIND CLASSIFICATION USING ARTIFACT ID

int findClassification(int id) {

    for (int i = 0; i < classificationCount; i++) {

        if (classifications[i].artifactID == id) {
            return i;
        }
    }

    return -1;
}

// SEARCH CLASSIFICATION

void searchClassification() {

        int id = readValidatedInteger("\nEnter Artifact ID to Search: ");

    int index = findClassification(id);

    if (index == -1) {
        cout << "\nClassification record not found!" << endl;
        return;
    }

    cout << "\n===== CLASSIFICATION RECORD FOUND =====" << endl;

    displayClassification(index);
}

// UPDATE CLASSIFICATION

// UPDATE CLASSIFICATION

void updateClassification() {

        int id = readValidatedInteger("\nEnter Artifact ID to Update: ");

    int index = findClassification(id);

    if (index == -1) {
        cout << "\nClassification record not found!" << endl;
        return;
    }

    int artifactIndex = findArtifact(id);

    if (artifactIndex == -1) {
        cout << "\nAssociated artifact record not found!" << endl;
        return;
    }

    cout << "\n===== UPDATE CLASSIFICATION =====" << endl;

    cout << "Artifact Name: "
         << artifacts[artifactIndex].artifactName << endl;

    cout << "\nEnter New Material: ";
    getline(cin, classifications[index].material);

    cout << "Enter New Characteristics: ";
    getline(cin, classifications[index].characteristics);

    string suggested = suggestClassification(
        artifacts[artifactIndex].artifactName,
        classifications[index].material,
        classifications[index].characteristics
    );

    string newCategory = confirmClassification(suggested);

    if (newCategory == "") {
        cout << "\nUpdate cancelled." << endl;
        return;
    }

    classifications[index].category = newCategory;

    cout << "Enter New Classification Notes: ";
    getline(cin, classifications[index].classificationNotes);

    cout << "\nClassification successfully updated!" << endl;
    saveClassifications();
}
// DELETE CLASSIFICATION

void deleteClassification() {

        int id = readValidatedInteger("\nEnter Artifact ID to Delete Classification: ");
    int index = findClassification(id);

    if (index == -1) {
        cout << "\nClassification record not found!" << endl;
        return;
    }

    char confirmation;

    cout << "\nAre you sure you want to delete this classification? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {

        for (int i = index; i < classificationCount - 1; i++) {
            classifications[i] = classifications[i + 1];
        }

        classificationCount--;
        saveClassifications();

        cout << "\nClassification successfully deleted!" << endl;

    } else {

        cout << "\nDeletion cancelled." << endl;
    }
}

// ========================================
// ARTIFACT CLASSIFICATION FILE HANDLING
// ========================================

// SAVE CLASSIFICATION RECORDS

void saveClassifications() {

    ofstream file("classifications.txt");

    if (!file.is_open()) {
        cout << "\nError: Unable to save classification records.\n";
        return;
    }

    for (int i = 0; i < classificationCount; i++) {

        file << classifications[i].artifactID << "|"
             << classifications[i].category << "|"
             << classifications[i].material << "|"
             << classifications[i].characteristics << "|"
             << classifications[i].classificationNotes << "\n";
    }

    file.close();
}


// LOAD CLASSIFICATION RECORDS

void loadClassifications() {

    ifstream file("classifications.txt");

    if (!file.is_open()) {
        return;
    }

    string line;

    classificationCount = 0;

    while (getline(file, line) &&
           classificationCount < MAX_CLASSIFICATIONS) {

        stringstream ss(line);
        ArtifactClassification loadedClassification;

        string idText;

        getline(ss, idText, '|');

        try {
            loadedClassification.artifactID = stoi(idText);
        }
        catch (...) {
            continue;
        }

        getline(ss, loadedClassification.category, '|');
        getline(ss, loadedClassification.material, '|');
        getline(ss, loadedClassification.characteristics, '|');
        getline(ss, loadedClassification.classificationNotes);

        classifications[classificationCount] = loadedClassification;

        classificationCount++;
    }

    file.close();
}



// AGE ESTIMATION AND HISTORICAL PERIOD MENU

void ageEstimationMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << " AGE ESTIMATION AND HISTORICAL PERIOD" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Estimate Artifact Age" << endl;
        cout << "2. View All Age Estimates" << endl;
        cout << "3. Search Age Estimate" << endl;
        cout << "4. Update Age Estimate" << endl;
        cout << "5. Delete Age Estimate" << endl;
        cout << "6. Return to Main Menu" << endl;

                choice = readValidatedInteger("\nEnter your choice: ");

        

        switch (choice) {

            case 1:
                estimateArtifactAge();
                break;

            case 2:
                viewAgeEstimates();
                break;

            case 3:
                searchAgeEstimate();
                break;

            case 4:
                updateAgeEstimate();
                break;

            case 5:
                deleteAgeEstimate();
                break;

            case 6:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);
}

// CALCULATE ARTIFACT AGE RANGE

void calculateAgeRange(
    int periodChoice,
    int &minimumAge,
    int &maximumAge
) {

    int startingYear = historicalPeriods[periodChoice - 1].startingYear;
    int endingYear = historicalPeriods[periodChoice - 1].endingYear;

    minimumAge = CURRENT_YEAR - endingYear;

    if (startingYear == 0) {

        // PRECOLONIAL PERIOD HAS NO DEFINED OLDEST YEAR
        maximumAge = 0;

    } else {

        maximumAge = CURRENT_YEAR - startingYear;
    }
}

// ESTIMATE ARTIFACT AGE

void estimateArtifactAge() {

    if (artifactCount == 0) {
        cout << "\nNo registered artifacts available." << endl;
        cout << "Please register an artifact first." << endl;
        return;
    }

    if (ageCount >= MAX_AGE_RECORDS) {
        cout << "\nMaximum number of age records reached!" << endl;
        return;
    }

        cout << "\n===== ARTIFACT AGE ESTIMATION =====" << endl;

    viewArtifacts();

    int id = readValidatedInteger("\nEnter Artifact ID: ");

    int artifactIndex = findArtifact(id);

    if (artifactIndex == -1) {
        cout << "\nArtifact not found!" << endl;
        return;
    }

    int existingIndex = findAgeEstimate(id);

    if (existingIndex != -1) {
        cout << "\nAn age estimation record already exists for this artifact." << endl;
        cout << "Use Update Age Estimate to modify it." << endl;
        return;
    }

    cout << "\nArtifact Name: "
         << artifacts[artifactIndex].artifactName << endl;

    cout << "\n===== HISTORICAL PERIOD REFERENCES =====" << endl;

    for (int i = 0; i < 5; i++) {

        cout << "\n" << i + 1 << ". "
             << historicalPeriods[i].periodName << endl;

        if (historicalPeriods[i].startingYear == 0) {
            cout << "   Before "
                 << historicalPeriods[i].endingYear << endl;
        }
        else {
            cout << "   "
                 << historicalPeriods[i].startingYear
                 << " - "
                 << historicalPeriods[i].endingYear << endl;
        }
    }

        int periodChoice =
        readValidatedInteger("\nSelect Historical Period Reference: ");

    if (periodChoice < 1 || periodChoice > 5) {
        cout << "\nInvalid historical period selection!" << endl;
        return;
    }

    AgeEstimation newRecord;

    newRecord.artifactID = id;

    newRecord.historicalPeriod =
        historicalPeriods[periodChoice - 1].periodName;

    newRecord.startingYear =
        historicalPeriods[periodChoice - 1].startingYear;

    newRecord.endingYear =
        historicalPeriods[periodChoice - 1].endingYear;

    calculateAgeRange(
        periodChoice,
        newRecord.minimumAge,
        newRecord.maximumAge
    );

    cout << "\nEnter Historical Reference or Evidence Basis: ";
    getline(cin, newRecord.referenceBasis);

    cout << "Enter Additional Estimation Notes: ";
    getline(cin, newRecord.estimationNotes);

    ageRecords[ageCount] = newRecord;

    ageCount++;

    cout << "\n===== AGE ESTIMATION RESULT =====" << endl;

    displayAgeEstimate(ageCount - 1);

    cout << "\nAge estimation record successfully saved!" << endl;
}

// DISPLAY AGE ESTIMATION RECORD

void displayAgeEstimate(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Artifact ID: "
         << ageRecords[index].artifactID << endl;

    int artifactIndex = findArtifact(ageRecords[index].artifactID);

    if (artifactIndex != -1) {
        cout << "Artifact Name: "
             << artifacts[artifactIndex].artifactName << endl;
    }

    cout << "Historical Period: "
         << ageRecords[index].historicalPeriod << endl;

    cout << "Possible Age Range: ";

    if (ageRecords[index].maximumAge == 0) {

        cout << "At least "
             << ageRecords[index].minimumAge
             << " years old" << endl;

    } else {

        cout << ageRecords[index].minimumAge
             << " - "
             << ageRecords[index].maximumAge
             << " years old" << endl;
    }

    cout << "Reference Years: ";

    if (ageRecords[index].startingYear == 0) {

        cout << "Before "
             << ageRecords[index].endingYear << endl;

    } else {

        cout << ageRecords[index].startingYear
             << " - "
             << ageRecords[index].endingYear << endl;
    }

    cout << "Historical Reference or Evidence Basis: "
         << ageRecords[index].referenceBasis << endl;

    cout << "Estimation Notes: "
         << ageRecords[index].estimationNotes << endl;

    cout << "Estimation Type: Preliminary Reference" << endl;

    cout << "----------------------------------------" << endl;
}

// FIND AGE ESTIMATION USING ARTIFACT ID

int findAgeEstimate(int id) {

    for (int i = 0; i < ageCount; i++) {

        if (ageRecords[i].artifactID == id) {
            return i;
        }
    }

    return -1;
}

// VIEW ALL AGE ESTIMATES

void viewAgeEstimates() {

    if (ageCount == 0) {
        cout << "\nNo age estimation records available." << endl;
        return;
    }

    cout << "\n===== ALL ARTIFACT AGE ESTIMATES =====" << endl;

    for (int i = 0; i < ageCount; i++) {

        displayAgeEstimate(i);
    }
}

// SEARCH AGE ESTIMATE

void searchAgeEstimate() {

        int id = readValidatedInteger("\nEnter Artifact ID to Search: ");

    int index = findAgeEstimate(id);

    if (index == -1) {
        cout << "\nAge estimation record not found!" << endl;
        return;
    }

    cout << "\n===== AGE ESTIMATION RECORD FOUND =====" << endl;

    displayAgeEstimate(index);
}

// UPDATE AGE ESTIMATION

void updateAgeEstimate() {

        int id = readValidatedInteger("\nEnter Artifact ID to Update: ");

    int index = findAgeEstimate(id);

    if (index == -1) {
        cout << "\nAge estimation record not found!" << endl;
        return;
    }

    cout << "\n===== UPDATE AGE ESTIMATION =====" << endl;

    cout << "\n===== HISTORICAL PERIOD REFERENCES =====" << endl;

    for (int i = 0; i < 5; i++) {

        cout << i + 1 << ". "
             << historicalPeriods[i].periodName << endl;
    }

        int periodChoice =
        readValidatedInteger("\nSelect New Historical Period: ");

    if (periodChoice < 1 || periodChoice > 5) {
        cout << "\nInvalid selection! Update cancelled." << endl;
        return;
    }

    ageRecords[index].historicalPeriod =
        historicalPeriods[periodChoice - 1].periodName;

    ageRecords[index].startingYear =
        historicalPeriods[periodChoice - 1].startingYear;

    ageRecords[index].endingYear =
        historicalPeriods[periodChoice - 1].endingYear;

    calculateAgeRange(
        periodChoice,
        ageRecords[index].minimumAge,
        ageRecords[index].maximumAge
    );

    

    cout << "Enter New Historical Reference or Evidence Basis: ";
    getline(cin, ageRecords[index].referenceBasis);

    cout << "Enter New Estimation Notes: ";
    getline(cin, ageRecords[index].estimationNotes);

    cout << "\nAge estimation successfully updated!" << endl;

    displayAgeEstimate(index);
}

// DELETE AGE ESTIMATION RECORD

void deleteAgeEstimate() {

        int id = readValidatedInteger("\nEnter Artifact ID to Delete: ");

    int index = findAgeEstimate(id);

    if (index == -1) {
        cout << "\nAge estimation record not found!" << endl;
        return;
    }

    char confirmation;

    cout << "\nAre you sure you want to delete this age estimation? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {

        for (int i = index; i < ageCount - 1; i++) {
            ageRecords[i] = ageRecords[i + 1];
        }

        ageCount--;

        cout << "\nAge estimation record successfully deleted!" << endl;

    } else {

        cout << "\nDeletion cancelled." << endl;
    }
}




// EXCAVATION TEAM MENU

void ExcavationTeamManagement() {

    int choice;

    do {

        cout << "\n===== EXCAVATION TEAM MANAGEMENT =====\n";
        cout << "[1] Register Team Member\n";
        cout << "[2] View Team Members\n";
        cout << "[3] Update Team Member\n";
        cout << "[4] Delete Team Member\n";
        cout << "[5] Return to User Menu\n";

                choice = readValidatedInteger("\nEnter your choice: ");

        switch (choice) {

            case 1:
                registerTeamMember();
                break;

            case 2:
                viewTeamMembers();
                break;

            case 3:
                updateTeamMember();
                break;

            case 4:
                deleteTeamMember();
                break;

            case 5:
                cout << "Returning to User Menu...\n";
                break;

            default:
                cout << "Invalid Choice. Please Try Again.\n";
        }

    } while (choice != 5);
}

void registerTeamMember() {

    ExcavationTeam member;

    cout << "\n===== REGISTER TEAM MEMBER =====\n";

        member.memberName = readValidatedName("Enter Member Name: ");

    member.contactInformation =
        readValidatedDigits("Enter Contact Information: ");

    member.assignedRole = readValidatedWords("Enter Assigned Role: ");

    cout << "\n===== AVAILABLE EXCAVATION SITES =====\n";
viewSites();

cout << "Enter Excavation Site ID: ";
getline(cin >> ws, member.siteID);

if (findSite(member.siteID) == -1) {
    cout << "Invalid Site ID! Registration cancelled.\n";
    return;
}

    member.teamMemberID = string("TM") +
    (nextTeamID < 10 ? "00" :
    nextTeamID < 100 ? "0" : "") +
    to_string(nextTeamID);

    nextTeamID++;

    excavationTeam.push_back(member);

    cout << "\nTeam Member Successfully Registered!\n";
    cout << "Team Member ID: " << member.teamMemberID << endl;
}

void viewTeamMembers() {

    cout << "\n===== EXCAVATION TEAM RECORDS =====\n";

    if (excavationTeam.empty()) {
        cout << "No team members recorded.\n";
        return;
    }

    for (int i = 0; i < excavationTeam.size(); i++) {

        cout << "\nTeam Member ID: "
             << excavationTeam[i].teamMemberID;

        cout << "\nMember Name: "
             << excavationTeam[i].memberName;

        cout << "\nContact Information: "
             << excavationTeam[i].contactInformation;

        cout << "\nAssigned Role: "
             << excavationTeam[i].assignedRole;

        cout << "\nExcavation Site ID: "
             << excavationTeam[i].siteID;

        cout << "\n----------------------------------\n";
    }
}

int findExcavationTeamMember(string id) {

    for (int i = 0; i < excavationTeam.size(); i++) {

        if (excavationTeam[i].teamMemberID == id) {
            return i;
        }
    }

    return -1;
}


void updateTeamMember() {

    string id;

    cout << "\nEnter Team Member ID: ";
    getline(cin, id);

    int index = findExcavationTeamMember(id);

    if (index == -1) {
        cout << "Team Member Not Found.\n";
        return;
    }

    cout << "\n===== AVAILABLE EXCAVATION SITES =====\n";
    viewSites();

    string newSiteID;

    cout << "Enter New Excavation Site ID: ";
    getline(cin >> ws, newSiteID);

    if (findSite(newSiteID) == -1) {
        cout << "Invalid Site ID! Update cancelled.\n";
        return;
    }

    excavationTeam[index].memberName =
        readValidatedName("Enter New Member Name: ");

    excavationTeam[index].contactInformation =
        readValidatedDigits("Enter New Contact Information: ");

    excavationTeam[index].assignedRole =
        readValidatedWords("Enter New Assigned Role: ");

    excavationTeam[index].siteID = newSiteID;

    cout << "\nTeam Member Record Successfully Updated!\n";
}

void deleteTeamMember() {

    string id;

    cout << "\nEnter Team Member ID: ";
    getline(cin, id);

    int index = findExcavationTeamMember(id);

    if (index == -1) {
        cout << "Team Member Not Found.\n";
        return;
    }

    excavationTeam.erase(excavationTeam.begin() + index);

    cout << "\nTeam Member Record Successfully Deleted!\n";
}


// PRESERVATION MANAGEMENT MENU

void preservationMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << "       PRESERVATION MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "\n1. Add Preservation Record" << endl;
        cout << "2. View All Preservation Records" << endl;
        cout << "3. Search Preservation Record" << endl;
        cout << "4. Update Preservation Record" << endl;
        cout << "5. Delete Preservation Record" << endl;
        cout << "6. Return to Main Menu" << endl;

                choice = readValidatedInteger("\nEnter your choice: ");
        

        switch (choice) {

            case 1:
                addPreservationRecord();
                break;

            case 2:
                viewPreservationRecords();
                break;

            case 3:
                searchPreservationRecord();
                break;

            case 4:
                updatePreservationRecord();
                break;

            case 5:
                deletePreservationRecord();
                break;

            case 6:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 6);
}

// ADD PRESERVATION RECORD

void addPreservationRecord() {

    if (artifactCount == 0) {

        cout << "\nNo registered artifacts available." << endl;
        cout << "Please register an artifact first." << endl;
        return;
    }

    if (preservationCount >= MAX_PRESERVATION) {

        cout << "\nMaximum number of preservation records reached!" << endl;
        return;
    }

    PreservationRecord newRecord;

    int artifactID;

    cout << "\n===== ADD PRESERVATION RECORD =====" << endl;

    cout << "\n===== REGISTERED ARTIFACTS =====" << endl;

    viewArtifacts();

        artifactID = readValidatedInteger("\nEnter Artifact ID: ");
    

    int artifactIndex = findArtifact(artifactID);

    if (artifactIndex == -1) {

        cout << "\nArtifact not found!" << endl;
        return;
    }

    newRecord.artifactID = artifactID;

    newRecord.preservationID = nextPreservationID;

    cout << "\nArtifact Name: "
         << artifacts[artifactIndex].artifactName << endl;



    

    cout << "\nEnter Preservation Activity: ";
    getline(cin, newRecord.preservationActivity);

    cout << "Enter Preservation Method: ";
    getline(cin, newRecord.preservationMethod);

        newRecord.responsiblePerson =
        readValidatedName("Enter Responsible Person: ");

    cout << "Enter Preservation Date: ";
    getline(cin, newRecord.preservationDate);

    cout << "Enter Next Monitoring Date: ";
    getline(cin, newRecord.nextMonitoringDate);

    cout << "\n===== PRESERVATION STATUS =====" << endl;
    cout << "1. Planned" << endl;
    cout << "2. Ongoing" << endl;
    cout << "3. Completed" << endl;

        int statusChoice =
        readValidatedInteger("\nSelect Preservation Status: ");

    if (statusChoice < 1 || statusChoice > 3) {

        cout << "\nInvalid status selection! Record cancelled." << endl;
        return;
    }

    if (statusChoice == 1) {
        newRecord.preservationStatus = "Planned";
    }
    else if (statusChoice == 2) {
        newRecord.preservationStatus = "Ongoing";
    }
    else {
        newRecord.preservationStatus = "Completed";
    }

    preservationRecords[preservationCount] = newRecord;

    preservationCount++;
    nextPreservationID++;

    cout << "\nPreservation record successfully added!" << endl;

    cout << "Preservation ID: "
         << newRecord.preservationID << endl;

    cout << "Artifact ID: "
         << newRecord.artifactID << endl;
}

// DISPLAY PRESERVATION RECORD

void displayPreservationRecord(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Preservation ID: "
         << preservationRecords[index].preservationID << endl;

    cout << "Artifact ID: "
         << preservationRecords[index].artifactID << endl;

    int artifactIndex = findArtifact(
        preservationRecords[index].artifactID
    );

    if (artifactIndex != -1) {

        cout << "Artifact Name: "
             << artifacts[artifactIndex].artifactName << endl;
    }

    cout << "Preservation Activity: "
         << preservationRecords[index].preservationActivity << endl;

    cout << "Preservation Method: "
         << preservationRecords[index].preservationMethod << endl;

    cout << "Responsible Person: "
         << preservationRecords[index].responsiblePerson << endl;

    cout << "Preservation Date: "
         << preservationRecords[index].preservationDate << endl;

    cout << "Next Monitoring Date: "
         << preservationRecords[index].nextMonitoringDate << endl;

    cout << "Preservation Status: "
         << preservationRecords[index].preservationStatus << endl;

    cout << "----------------------------------------" << endl;
}

// VIEW ALL PRESERVATION RECORDS

void viewPreservationRecords() {

    if (preservationCount == 0) {

        cout << "\nNo preservation records available." << endl;
        return;
    }

    cout << "\n===== ALL PRESERVATION RECORDS =====" << endl;

    for (int i = 0; i < preservationCount; i++) {

        displayPreservationRecord(i);
    }
}


// FIND PRESERVATION RECORD

int findPreservationRecord(int id) {

    for (int i = 0; i < preservationCount; i++) {

        if (preservationRecords[i].preservationID == id) {

            return i;
        }
    }

    return -1;
}


// SEARCH PRESERVATION RECORD

void searchPreservationRecord() {

        int id = readValidatedInteger("\nEnter Preservation ID to Search: ");

    int index = findPreservationRecord(id);

    if (index == -1) {

        cout << "\nPreservation record not found!" << endl;
        return;
    }

    cout << "\n===== PRESERVATION RECORD FOUND =====" << endl;

    displayPreservationRecord(index);
}

// UPDATE PRESERVATION RECORD

void updatePreservationRecord() {

        int id = readValidatedInteger("\nEnter Preservation ID to Update: ");

    int index = findPreservationRecord(id);

    if (index == -1) {

        cout << "\nPreservation record not found!" << endl;
        return;
    }

    PreservationRecord updatedRecord = preservationRecords[index];

    cout << "\n===== UPDATE PRESERVATION RECORD =====" << endl;



    

    cout << "\nEnter New Preservation Activity: ";
    getline(cin, updatedRecord.preservationActivity);

    cout << "Enter New Preservation Method: ";
    getline(cin, updatedRecord.preservationMethod);

        updatedRecord.responsiblePerson =
        readValidatedName("Enter New Responsible Person: ");

    cout << "Enter New Preservation Date: ";
    getline(cin, updatedRecord.preservationDate);

    cout << "Enter New Monitoring Date: ";
    getline(cin, updatedRecord.nextMonitoringDate);

    cout << "\n===== PRESERVATION STATUS =====" << endl;
    cout << "1. Planned" << endl;
    cout << "2. Ongoing" << endl;
    cout << "3. Completed" << endl;

        int statusChoice =
        readValidatedInteger("\nSelect New Status: ");

    if (statusChoice < 1 || statusChoice > 3) {

        cout << "\nInvalid status! Update cancelled." << endl;
        return;
    }

    if (statusChoice == 1) {
        updatedRecord.preservationStatus = "Planned";
    }
    else if (statusChoice == 2) {
        updatedRecord.preservationStatus = "Ongoing";
    }
    else {
        updatedRecord.preservationStatus = "Completed";
    }

    preservationRecords[index] = updatedRecord;

    cout << "\nPreservation record successfully updated!" << endl;

    displayPreservationRecord(index);
}

// DELETE PRESERVATION RECORD

void deletePreservationRecord() {

        int id = readValidatedInteger("\nEnter Preservation ID to Delete: ");

    int index = findPreservationRecord(id);

    if (index == -1) {

        cout << "\nPreservation record not found!" << endl;
        return;
    }

    char confirmation;

    cout << "\nAre you sure you want to delete this record? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {

        for (int i = index; i < preservationCount - 1; i++) {

            preservationRecords[i] = preservationRecords[i + 1];
        }

        preservationCount--;

        cout << "\nPreservation record successfully deleted!" << endl;
    }
    else {

        cout << "\nDeletion cancelled." << endl;
    }
}

// RESTORATION AND MUSEUM MANAGEMENT MENU

void restorationMuseumMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << "   RESTORATION AND MUSEUM MANAGEMENT" << endl;
        cout << "========================================" << endl;

        cout << "\n===== FACILITY AND MUSEUM RECORDS =====" << endl;
        cout << "1. Register Facility or Museum" << endl;
        cout << "2. View All Facilities and Museums" << endl;
        cout << "3. Search Facility or Museum" << endl;
        cout << "4. Update Facility Information" << endl;
        cout << "5. Delete Facility Record" << endl;

        cout << "\n===== ARTIFACT TRANSFERS =====" << endl;
        cout << "6. Record Artifact Transfer" << endl;
        cout << "7. View All Artifact Transfers" << endl;
        cout << "8. Search Artifact Transfer" << endl;

        cout << "\n9. Return to Main Menu" << endl;

                choice = readValidatedInteger("\nEnter your choice: ");
        

        switch (choice) {

            case 1:
                registerFacility();
                break;

            case 2:
                viewFacilities();
                break;

            case 3:
                searchFacility();
                break;

            case 4:
                updateFacility();
                break;

            case 5:
                deleteFacility();
                break;

            case 6:
                recordArtifactTransfer();
                break;

            case 7:
                viewArtifactTransfers();
                break;

            case 8:
                searchArtifactTransfer();
                break;

            case 9:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 9);
}

// REGISTER FACILITY OR MUSEUM

void registerFacility() {

    if (facilityCount >= MAX_FACILITIES) {

        cout << "\nMaximum number of facility records reached!" << endl;
        return;
    }

    HeritageFacility newFacility;

    int typeChoice;

    cout << "\n===== REGISTER FACILITY OR MUSEUM =====" << endl;

    cout << "\n1. Restoration Facility" << endl;
    cout << "2. Museum" << endl;

        typeChoice = readValidatedInteger("\nSelect Institution Type: ");

    if (typeChoice < 1 || typeChoice > 2) {

        cout << "\nInvalid selection!" << endl;
        return;
    }

    if (typeChoice == 1) {
        newFacility.facilityType = "Restoration Facility";
    }
    else {
        newFacility.facilityType = "Museum";
    }




    

        newFacility.facilityName =
        readValidatedText("\nEnter Institution Name: ");

    cout << "Enter Location: ";
    getline(cin, newFacility.location);

    newFacility.contactPerson =
        readValidatedName("Enter Contact Person: ");

    newFacility.contactNumber =
        readValidatedDigits("Enter Contact Number: ");

    cout << "Enter Services or Facilities Offered: ";
    getline(cin, newFacility.services);

    newFacility.facilityID = nextFacilityID;

    facilities[facilityCount] = newFacility;

    facilityCount++;
    nextFacilityID++;

    cout << "\nInstitution successfully registered!" << endl;

    cout << "Facility ID: " << newFacility.facilityID << endl;
    cout << "Institution Name: " << newFacility.facilityName << endl;
    cout << "Institution Type: " << newFacility.facilityType << endl;
}
// DISPLAY FACILITY OR MUSEUM

void displayFacility(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Facility ID: "
         << facilities[index].facilityID << endl;

    cout << "Institution Name: "
         << facilities[index].facilityName << endl;

    cout << "Institution Type: "
         << facilities[index].facilityType << endl;

    cout << "Location: "
         << facilities[index].location << endl;

    cout << "Contact Person: "
         << facilities[index].contactPerson << endl;

    cout << "Contact Number: "
         << facilities[index].contactNumber << endl;

    cout << "Services Offered: "
         << facilities[index].services << endl;

    cout << "----------------------------------------" << endl;
}

// VIEW ALL FACILITIES AND MUSEUMS

void viewFacilities() {

    if (facilityCount == 0) {

        cout << "\nNo registered facilities or museums available." << endl;
        return;
    }

    cout << "\n===== REGISTERED FACILITIES AND MUSEUMS =====" << endl;

    for (int i = 0; i < facilityCount; i++) {

        displayFacility(i);
    }
}


// FIND FACILITY USING FACILITY ID

int findFacility(int id) {

    for (int i = 0; i < facilityCount; i++) {

        if (facilities[i].facilityID == id) {

            return i;
        }
    }

    return -1;
}

// SEARCH FACILITY OR MUSEUM

void searchFacility() {

        int id = readValidatedInteger("\nEnter Facility ID to Search: ");

    int index = findFacility(id);

    if (index == -1) {

        cout << "\nFacility record not found!" << endl;
        return;
    }

    cout << "\n===== FACILITY RECORD FOUND =====" << endl;

    displayFacility(index);
}

// UPDATE FACILITY INFORMATION

void updateFacility() {

        int id = readValidatedInteger("\nEnter Facility ID to Update: ");

    int index = findFacility(id);

    if (index == -1) {

        cout << "\nFacility record not found!" << endl;
        return;
    }



    

    cout << "\n===== UPDATE FACILITY INFORMATION =====" << endl;

        facilities[index].facilityName =
        readValidatedText("Enter New Institution Name: ");

    cout << "Enter New Location: ";
    getline(cin, facilities[index].location);

    facilities[index].contactPerson =
        readValidatedName("Enter New Contact Person: ");

    facilities[index].contactNumber =
        readValidatedDigits("Enter New Contact Number: ");

    cout << "Enter New Services Offered: ";
    getline(cin, facilities[index].services);

    cout << "\nFacility information successfully updated!" << endl;
}

// DELETE FACILITY RECORD

void deleteFacility() {

        int id = readValidatedInteger("\nEnter Facility ID to Delete: ");

    int index = findFacility(id);

    if (index == -1) {

        cout << "\nFacility record not found!" << endl;
        return;
    }

    for (int i = 0; i < transferCount; i++) {

        if (transfers[i].facilityID == id) {

            cout << "\nCannot delete this facility." << endl;
            cout << "It is linked to an artifact transfer record." << endl;

            return;
        }
    }

    char confirmation;

    cout << "\nAre you sure you want to delete this facility? (Y/N): ";
    cin >> confirmation;

    if (confirmation == 'Y' || confirmation == 'y') {

        for (int i = index; i < facilityCount - 1; i++) {

            facilities[i] = facilities[i + 1];
        }

        facilityCount--;

        cout << "\nFacility record successfully deleted!" << endl;
    }
    else {

        cout << "\nDeletion cancelled." << endl;
    }
}

// RECORD ARTIFACT TRANSFER

void recordArtifactTransfer() {

    if (artifactCount == 0) {

        cout << "\nNo registered artifacts available." << endl;
        return;
    }

    if (facilityCount == 0) {

        cout << "\nNo registered facilities or museums available." << endl;
        cout << "Please register an institution first." << endl;
        return;
    }

    if (transferCount >= MAX_TRANSFERS) {

        cout << "\nMaximum number of transfer records reached!" << endl;
        return;
    }

    ArtifactTransfer newTransfer;

    int artifactID;
    int facilityID;

    cout << "\n===== RECORD ARTIFACT TRANSFER =====" << endl;

    cout << "\n===== REGISTERED ARTIFACTS =====" << endl;

    viewArtifacts();

        artifactID = readValidatedInteger("\nEnter Artifact ID: ");

    int artifactIndex = findArtifact(artifactID);

    if (artifactIndex == -1) {

        cout << "\nArtifact not found!" << endl;
        return;
    }

    cout << "\n===== REGISTERED FACILITIES AND MUSEUMS =====" << endl;

    viewFacilities();

        facilityID = readValidatedInteger("\nEnter Destination Facility ID: ");

    int facilityIndex = findFacility(facilityID);

    if (facilityIndex == -1) {

        cout << "\nFacility not found!" << endl;
        return;
    }

    newTransfer.transferID = nextTransferID;
    newTransfer.artifactID = artifactID;
    newTransfer.facilityID = facilityID;

    cout << "\nArtifact: "
         << artifacts[artifactIndex].artifactName << endl;

    cout << "Destination: "
         << facilities[facilityIndex].facilityName << endl;



    

    cout << "\nEnter Transfer Date: ";
    getline(cin, newTransfer.transferDate);

    cout << "Enter Transfer Purpose: ";
    getline(cin, newTransfer.transferPurpose);

    cout << "\n===== TRANSFER STATUS =====" << endl;
    cout << "1. Scheduled" << endl;
    cout << "2. In Transit" << endl;
    cout << "3. Received" << endl;

        int statusChoice =
        readValidatedInteger("\nSelect Transfer Status: ");
    if (statusChoice < 1 || statusChoice > 3) {

        cout << "\nInvalid status! Transfer record cancelled." << endl;
        return;
    }

    if (statusChoice == 1) {
        newTransfer.transferStatus = "Scheduled";
    }
    else if (statusChoice == 2) {
        newTransfer.transferStatus = "In Transit";
    }
    else {
        newTransfer.transferStatus = "Received";
    }

    transfers[transferCount] = newTransfer;

    transferCount++;
    nextTransferID++;

    cout << "\nArtifact transfer successfully recorded!" << endl;

    cout << "Transfer ID: " << newTransfer.transferID << endl;
    cout << "Artifact Name: "
         << artifacts[artifactIndex].artifactName << endl;
    cout << "Destination: "
         << facilities[facilityIndex].facilityName << endl;
}


// DISPLAY ARTIFACT TRANSFER

void displayArtifactTransfer(int index) {

    cout << "\n----------------------------------------" << endl;

    cout << "Transfer ID: "
         << transfers[index].transferID << endl;

    cout << "Artifact ID: "
         << transfers[index].artifactID << endl;

    int artifactIndex = findArtifact(transfers[index].artifactID);

    if (artifactIndex != -1) {

        cout << "Artifact Name: "
             << artifacts[artifactIndex].artifactName << endl;
    }

    cout << "Destination Facility ID: "
         << transfers[index].facilityID << endl;

    int facilityIndex = findFacility(transfers[index].facilityID);

    if (facilityIndex != -1) {

        cout << "Destination Institution: "
             << facilities[facilityIndex].facilityName << endl;

        cout << "Institution Type: "
             << facilities[facilityIndex].facilityType << endl;
    }

    cout << "Transfer Date: "
         << transfers[index].transferDate << endl;

    cout << "Transfer Purpose: "
         << transfers[index].transferPurpose << endl;

    cout << "Transfer Status: "
         << transfers[index].transferStatus << endl;

    cout << "----------------------------------------" << endl;
}

// VIEW ALL ARTIFACT TRANSFERS

void viewArtifactTransfers() {

    if (transferCount == 0) {

        cout << "\nNo artifact transfer records available." << endl;
        return;
    }

    cout << "\n===== ARTIFACT TRANSFER RECORDS =====" << endl;

    for (int i = 0; i < transferCount; i++) {

        displayArtifactTransfer(i);
    }
}

// FIND ARTIFACT TRANSFER

int findArtifactTransfer(int id) {

    for (int i = 0; i < transferCount; i++) {

        if (transfers[i].transferID == id) {

            return i;
        }
    }

    return -1;
}

// SEARCH ARTIFACT TRANSFER

void searchArtifactTransfer() {

        int id = readValidatedInteger("\nEnter Transfer ID to Search: ");

    int index = findArtifactTransfer(id);

    if (index == -1) {

        cout << "\nArtifact transfer record not found!" << endl;
        return;
    }

    cout << "\n===== ARTIFACT TRANSFER FOUND =====" << endl;

    displayArtifactTransfer(index);
}

// REPORTS AND RECORDS MENU

void reportsMenu() {

    int choice;

    do {

        cout << "\n========================================" << endl;
        cout << "          REPORTS AND RECORDS" << endl;
        cout << "========================================" << endl;

        cout << "\n1. System Summary Report" << endl;
        cout << "2. Excavation Site Report" << endl;
        cout << "3. Artifact Inventory Report" << endl;
        cout << "4. Activity Report" << endl;
        cout << "5. Return to Main Menu" << endl;

                choice = readValidatedInteger("\nEnter your choice: ");

        switch (choice) {

            case 1:
                generateSystemSummary();
                break;

            case 2:
                generateSiteReport();
                break;

            case 3:
                generateArtifactReport();
                break;

            case 4:
                generateActivityReport();
                break;

            case 5:
                cout << "\nReturning to Main Menu..." << endl;
                break;

            default:
                cout << "\nInvalid choice!" << endl;
        }

    } while (choice != 5);
}

// GENERATE SYSTEM SUMMARY REPORT

void generateSystemSummary() {

    cout << "\n========================================" << endl;
    cout << "          SYSTEM SUMMARY REPORT" << endl;
    cout << "========================================" << endl;

    cout << "\n===== RECORD TOTALS =====" << endl;

    cout << "Registered Excavation Sites: "
         << siteCount << endl;

    cout << "Registered Artifacts: "
         << artifactCount << endl;

    cout << "Age Estimation Records: "
         << ageCount << endl;

    cout << "Excavation Team Members: "
         << teamCount << endl;

    cout << "Preservation Records: "
         << preservationCount << endl;

    cout << "Registered Facilities and Museums: "
         << facilityCount << endl;

    cout << "Artifact Transfer Records: "
         << transferCount << endl;

    cout << "\n========================================" << endl;
}

// GENERATE EXCAVATION SITE REPORT

void generateSiteReport() {

    if (siteCount == 0) {

        cout << "\nNo excavation site records available." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "         EXCAVATION SITE REPORT" << endl;
    cout << "========================================" << endl;

    cout << "\nTotal Registered Sites: "
         << siteCount << endl;

    for (int i = 0; i < siteCount; i++) {

        cout << "\n===== SITE RECORD " << i + 1 << " =====" << endl;

        displaySite(i);
    }

    cout << "\n===== END OF SITE REPORT =====" << endl;
}

// GENERATE ARTIFACT INVENTORY REPORT

void generateArtifactReport() {

    if (artifactCount == 0) {

        cout << "\nNo artifact records available." << endl;
        return;
    }

    cout << "\n========================================" << endl;
    cout << "        ARTIFACT INVENTORY REPORT" << endl;
    cout << "========================================" << endl;

    cout << "\nTotal Registered Artifacts: "
         << artifactCount << endl;

    for (int i = 0; i < artifactCount; i++) {

        cout << "\n===== ARTIFACT RECORD " << i + 1 << " =====" << endl;

        displayArtifact(i);
    }

    cout << "\n===== END OF ARTIFACT REPORT =====" << endl;
}

// GENERATE ACTIVITY REPORT

void generateActivityReport() {

    cout << "\n========================================" << endl;
    cout << "             ACTIVITY REPORT" << endl;
    cout << "========================================" << endl;

    // PRESERVATION ACTIVITIES

    cout << "\n===== PRESERVATION ACTIVITIES =====" << endl;

    cout << "Total Preservation Records: "
         << preservationCount << endl;

    if (preservationCount > 0) {

        for (int i = 0; i < preservationCount; i++) {

            displayPreservationRecord(i);
        }
    }
    else {

        cout << "No preservation activities recorded." << endl;
    }

    // ARTIFACT TRANSFERS

    cout << "\n===== ARTIFACT TRANSFERS =====" << endl;

    cout << "Total Transfer Records: "
         << transferCount << endl;

    if (transferCount > 0) {

        for (int i = 0; i < transferCount; i++) {

            displayArtifactTransfer(i);
        }
    }
    else {

        cout << "No artifact transfers recorded." << endl;
    }

    cout << "\n===== END OF ACTIVITY REPORT =====" << endl;
}

// =====================================
// MENU FUNCTION DEFINITIONS
// =====================================

void agePeriodMenu() {
    ageEstimationMenu();
}

void restorationMenu() {
    restorationMuseumMenu();
}

