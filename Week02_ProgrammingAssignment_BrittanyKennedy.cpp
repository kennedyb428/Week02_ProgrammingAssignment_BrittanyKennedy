/*
Name: Brittany Kennedy
Date: 10/22/2025
Section: ITCS 2530 H0801 2025FA - C++ Programming 1

Week02_Programming_Assignment_Brittany_Kennedy.cpp:
********************Vegetarian Nutrition for Weightlifting*********************
Program to help user figure out their suggested daily and per meal macros (protein/carbs/fats).
The percentages used in the macros target calculations are geared toward vegetarians that weightlift.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>

using namespace std;

// **********************Define constants for calculations*********************
// Macro ratios as percentages of daily calories: 30% protein, 40% carbs, 30% fats
const double PROTEIN_PERCENT = 0.30;
const double CARB_PERCENT = 0.40;
const double FAT_PERCENT = 0.30;

// Calories per gram for each macro
const int CALORIES_PER_GRAM_PROTEIN = 4;
const int CALORIES_PER_GRAM_CARBS = 4;
const int CALORIES_PER_GRAM_FAT = 9;
// ****************************************************************************

int main()
{
    // **************************Variables************************************* 
    ofstream outFile;  // Declare file stream variable for output report

    string name;
    string favoriteProtein;
    int totalCalories = 0;
    int mealsPerDay = 0;
    double workoutHours = 0;

    int proteinCalories = 0;
    int carbCalories = 0;
    int fatCalories = 0;

    int gramsProtein = 0;
    int gramsCarbs = 0;
    int gramsFats = 0;

    int proteinPerMeal = 0;
    int carbsPerMeal = 0;
    int fatsPerMeal = 0;


    // ***********************Introduction*************************************
    cout << setfill('*') << setw(75) << '*' << endl;
    cout << setfill(' ');
    cout << left << setw(5) << " "
        << " Welcome to the Vegetarian Nutrition for Weightlifters Program! "
        << right << setw(5) << " " << endl;
    cout << setfill('*') << setw(75) << '*' << endl;
    cout << "Let's learn more about you so we can figure out what your macros should be!\n\n";
    cout << endl;
    

    // ************************User Input**************************************
    // Get user's name
    cout << "What is your name? ";
    getline(cin, name);
    cout << endl;

    // Get user's favorite protein source
    cout << "Hi " << name << "!\n\n";
    cout << "What is your favorite vegetarian protein source? ";
    getline(cin, favoriteProtein);
    cout << "Great choice!\n\n";

    // Ask for desired daily calorie target
    // Set default value if input is invalid.
    cout << "How many calories you are targeting each day? ";
    cin >> totalCalories;
    cout << endl;
    if (cin.fail()) {
        cout << "That is not a valid number. Defaulting to 2000 calories.\n\n";
        cin.clear();
        cin.ignore(200, '\n');
        totalCalories = 2000;
    }
    
    // Get how many meals per day the user eats
    // Set default value if input is invalid.
    cout << "How many meals you eat per day? ";
    cin >> mealsPerDay;
    cout << endl;
    if (cin.fail())
    {
        cout << "That is not a valid number. Defaulting to 3 meals.\n\n";
        cin.clear();
        cin.ignore(200, '\n');
        mealsPerDay = 3;
    }
       
    // Get how many hours per week the user weightlifts
    // Set default value if input is invalid.
    cout << "Last question! How many hours per week do you weightlift? ";
    cin >> workoutHours;
    cout << endl;
    if (cin.fail())
    {
        cout << "That is not a valid number. Defaulting to 4 hours per week.\n\n";
        cin.clear();
        cin.ignore(200, '\n');
        workoutHours = 4;
    }
        

    // ***********************Calculations*************************************
    // Calculate user's macros using defined macro ratios
    proteinCalories = static_cast<int>(totalCalories * PROTEIN_PERCENT);
    carbCalories = static_cast<int>(totalCalories * CARB_PERCENT);
    fatCalories = static_cast<int>(totalCalories * FAT_PERCENT);

    // Convert calories to grams for daily targets
    gramsProtein = proteinCalories / CALORIES_PER_GRAM_PROTEIN;
    gramsCarbs = carbCalories / CALORIES_PER_GRAM_CARBS;
    gramsFats = fatCalories / CALORIES_PER_GRAM_FAT;

    // Calculate macro targets per meal
    proteinPerMeal = gramsProtein / mealsPerDay;
    carbsPerMeal = gramsCarbs / mealsPerDay;
    fatsPerMeal = gramsFats / mealsPerDay;


    // ***********************Results Section*************************************
    ////////////// Display results to both the console and report \\\\\\\\\\\\\\

    // Open output file
    outFile.open("report.txt");

    // Pretty header
    cout << setfill('*') << setw(75) << '*' << endl;
    outFile << setfill('*') << setw(75) << '*' << endl;

    // Display the input provided by user
    cout << "Thank you for all of your details - here is the information you provided:\n";
    outFile << "Thank you for all of your details - here is the information you provided:\n";

    cout << left << setw(50) << setfill('.') << "Favorite protein source: " << right << favoriteProtein << endl;
    outFile << left << setw(50) << setfill('.') << "Favorite protein source: " << right << favoriteProtein << endl;

    cout << left << setw(50) << setfill('.') << "Daily calorie target: " << right << totalCalories << endl;
    outFile << left << setw(50) << setfill('.') << "Daily calorie target: " << right << totalCalories << endl;

    cout << left << setw(50) << setfill('.') << "Meals per day: " << right << mealsPerDay << endl;
    outFile << left << setw(50) << setfill('.') << "Meals per day: " << right << mealsPerDay << endl;

    cout << fixed << showpoint << setprecision(2);
    cout << left << setw(50) << setfill('.') << "Weekly workout hours: " << right << workoutHours << endl;
    outFile << left << setw(50) << setfill('.') << "Weekly workout hours: " << right << workoutHours << endl;
    
    // Display the calculated daily macro targets
    cout << "\nHere are your suggested daily macros:\n";
    outFile << "\nHere are your suggested daily macros:\n";

    cout << left << setw(50) << setfill('.') << "Protein: " << right << gramsProtein << " grams (" << proteinCalories << " cal)\n";
    outFile << left << setw(50) << setfill('.') << "Protein: " << right << gramsProtein << " grams (" << proteinCalories << " cal)\n";

    cout << left << setw(50) << setfill('.') << "Carbs: " << right << gramsCarbs << " grams (" << carbCalories << " cal)\n";
    outFile << left << setw(50) << setfill('.') << "Carbs: " << right << gramsCarbs << " grams (" << carbCalories << " cal)\n";

    cout << left << setw(50) << setfill('.') << "Fats: " << right << gramsFats << " grams (" << fatCalories << " cal)\n\n";
    outFile << left << setw(50) << setfill('.') << "Fats: " << right << gramsFats << " grams (" << fatCalories << " cal)\n\n";

    // Display the calculated per meal macro targets
    cout << "For your " << mealsPerDay << " meals per day, your macro targets per meal are:\n";
    outFile << "For your " << mealsPerDay << " meals per day, your macro targets per meal are:\n";

    cout << left << setw(50) << setfill('.') << "Protein grams per meal: " << right << proteinPerMeal << endl;
    outFile << left << setw(50) << setfill('.') << "Protein grams per meal: " << right << proteinPerMeal << endl;

    cout << left << setw(50) << setfill('.') << "Carbs grams per meal:   " << right << carbsPerMeal << endl;
    outFile << left << setw(50) << setfill('.') << "Carbs grams per meal:   " << right << carbsPerMeal << endl;

    cout << left << setw(50) << setfill('.') << "Fats grams per meal:    " << right << fatsPerMeal << endl;
    outFile << left << setw(50) << setfill('.') << "Fats grams per meal:    " << right << fatsPerMeal << endl;

    // Pretty footer
    cout << setfill('*') << setw(75) << '*' << endl;
    outFile << setfill('*') << setw(75) << '*' << endl;

    cout << "Keep fueling with " << favoriteProtein << " to hit that " << gramsProtein << " grams of protein!\n";
    outFile << "Keep fueling with " << favoriteProtein << " to hit that " << gramsProtein << " grams of protein!\n";

    cout << "Remember to hit your " << workoutHours << " hours of weightlifting per week...\n";
    outFile << "Remember to hit your " << workoutHours << " hours of weightlifting per week...\n";

    cout << "And keep lifting heavy, " << name << "!\n\n";
    outFile << "And keep lifting heavy, " << name << "!\n\n";

    cout << "Note: Open file named report.txt for a printable report!\n\n";

    // Close the file
    outFile.close();

    return 0;
}
// *******************Vegetarian Nutrition for Weightlifting*******************
