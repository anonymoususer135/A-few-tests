#include<fstream>

#include<limits>

#include<iostream>

#include<cstdlib>

#include <string>

#include <vector>

#include <sstream>
#include <iomanip>

#include <algorithm>
#include <typeinfo>

using namespace std;



void remove(std::vector<string>& v)

{

    auto end = v.end();

    for (auto it = v.begin(); it != end; ++it) {

        end = std::remove(it + 1, end, *it);

    }



    v.erase(end, v.end());

}




class BookList {

public:

    string title;

    string author;

    string publisher;

    string publicationDate;

    string category;

};

ostream& operator<<(ostream& out, const BookList& p) {
    out << p.title << endl;
    out << p.author << endl;
    out << p.publisher << endl;
    out << p.publicationDate << endl;
    out << p.category << endl;
    //copy(p.author.begin(), p.author.end(), ostream_iterator<string>(out, " "));
    return out;
}

int separatemonthfromdate(string date) {
    int month;
    stringstream ss(date);
    vector<string> dateThings;
    while (ss.good()) {
        string dates;
        getline(ss, dates, '/');
        dateThings.push_back(dates);
    }
    month = stoi(dateThings.at(0));
    return month;
}
int separatedayfromdate(string date) {
    int day;
    stringstream ss(date);
    vector<string> dateThings;
    while (ss.good()) {
        string dates;
        getline(ss, dates, '/');
        dateThings.push_back(dates);
    }
    day = stoi(dateThings.at(1));
    return day;
}

int separateyearfromdate(string date) {
    int year;
    stringstream ss(date);
    vector<string> dateThings;
    while (ss.good()) {
        string dates;
        getline(ss, dates, '/');
        dateThings.push_back(dates);
    }
    year = stoi(dateThings.at(2));
    return year;
}
int myCompare(string date1,
    string date2)
{
    //Dad added below 2 lines
    if (date1.empty() || date2.empty())
        return 0;

    string day1 = to_string(separatedayfromdate(date1));
    string month1 = to_string(separatemonthfromdate(date1));
    string year1 = to_string(separateyearfromdate(date1));

    string day2 = to_string(separatedayfromdate(date2));
    string month2 = to_string(separatemonthfromdate(date2));
    string year2 = to_string(separateyearfromdate(date2)); //cool.

    // Condition to check the year
    if (year1 < year2)
        return 1;
    if (year1 > year2)
        return 0;

    // Condition to check the month
    if (month1 < month2)
        return 1;
    if (month1 > month2)
        return 0;

    // Condition to check the day
    if (day1 < day2)
        return 1;
    if (day1 > day2)
        return 0;
    return 0;
}

void yearRange(bool& isFound, string& line, vector<string>& search) {
    vector <string> things;
    vector <string> fileLines;
    vector <string> orderedDates;
    vector <string> orderedFile;
    string lines;
    vector <int> possibleIndexes;
    vector <string> titles;
    vector <string> authors;
    vector <string> dates;
    vector <string> publishers;
    vector <string> categories;
    vector <string> orderedTitles;
    vector <string> orderedAuthors;
    vector <string> orderedPublishers;
    vector <string> orderedCategories;
    BookList Book;
    BookList OrderedBook;
    ifstream fin;
    int beginningyear;
    int endingyear;
    vector <int> years;
    string beginningyearasstring;
    string endingyearasstring;
    int count = 0;
    int startyearCount = 0;
    int endyearCount = 0;
    vector <int> years2;
    bool enterYear = 0;
    vector <int> yearsInRange;
    vector <string> booksinRange;
    vector <int>::iterator it;
    fin.open("booklist.csv");
    while (!fin.eof()) {
        getline(fin, line);
        //cout << line << endl;
        stringstream s_stream(line);


        while (getline(fin, lines, '\n')) { //Forgot to add the comma to this equation. I fixed it now.
            //cout << "In the file are " << lines << endl; //Very nice. Now let's search for the year range

            if (lines.find("/") != std::string::npos) {
                fileLines.push_back(lines);
            }
        }

        }

    //for (int i = 0; i < fileLines.size(); i++) {
     //   cout << i << " " << fileLines.at(i) << endl;
    //}

    for (int i = 0; i < fileLines.size(); i++) {
        stringstream ss(fileLines.at(i));
        //string item;
        while (ss.good()) {
            //getline(ss, item, ',');
            //things.push_back(item);
            
                getline(ss, Book.title, ','); //get first string delimited by comma
                titles.push_back(Book.title);
                //cout << "Title: " << Book.title << endl;
                getline(ss, Book.author, ','); //get first string delimited by comma
                authors.push_back(Book.author);
                //cout << "Author: " << Book.author << endl;
                getline(ss, Book.publisher, ','); //get first string delimited by comma
                publishers.push_back(Book.publisher);
                //cout << "Publisher: " << Book.publisher << endl;
                getline(ss, Book.publicationDate, ','); //get first string delimited by comma
                dates.push_back(Book.publicationDate);
                //cout << "Publication Date: " << Book.publicationDate << endl;
                getline(ss, Book.category); //get first string delimited by comma
                categories.push_back(Book.category);
                //cout << "Category: " << Book.category << endl;
        }

    }
    //for (int i = 0; i < titles.size(); i++) {
    //    cout << i << " " << titles.at(i) << endl;
    //}
    for (int i = 0; i < categories.size(); i++) {
        categories.at(i).erase(categories.at(i).length()-3, categories.at(i).length());
    //    cout << "in the list are: " << categories.at(i) << endl;
    }//That was supposed to remove the commas from the category items
    //for (int i = 0; i < BookVector.size(); i++) {
    //    cout << "in the list are: " << BookVector.at(i);
    //}//I'm starting to think I don't need BookVector
    //cout << titles.size() << endl;
    //cout << authors.size() << endl;
    //cout << categories.size() << endl;
    //cout << dates.size() << endl;
    //cout << publishers.size() << endl;
    sort(dates.begin(), dates.end(), myCompare); //Now it works!
    // Loop to print the dates
    for (int i = 0; i < dates.size(); i++) {
        //cout << dates[i] << "\n";
        years.push_back(separateyearfromdate(dates.at(i)));
        orderedDates.push_back(dates[i]);
    }

    //cout << things.size();
    for (int i = 0; i < dates.size(); i++) {
        for (int j = 0; j < fileLines.size(); j++) {
            if (fileLines.at(j).find(dates.at(i)) != std::string::npos) {
                //cout << i << " " << fileLines.at(j) << endl;
                orderedFile.push_back(fileLines.at(j));
            }
        }
    } //Just look into the ordered file array. :3
    //stringstream orderedthings;
    for (int i = 0; i < orderedFile.size(); i++) {
        stringstream orderedthings(orderedFile.at(i));
        while (orderedthings.good()) {
            getline(orderedthings, OrderedBook.title, ','); //get first string delimited by comma
            //cout << OrderedBook.title << endl;
            orderedTitles.push_back(OrderedBook.title);
            getline(orderedthings, OrderedBook.author, ','); //get first string delimited by comma
            orderedAuthors.push_back(OrderedBook.author);
            getline(orderedthings, OrderedBook.publisher, ','); //get first string delimited by comma
            orderedPublishers.push_back(OrderedBook.publisher);
            getline(orderedthings, OrderedBook.publicationDate, ','); //get first string delimited by comma
            //orderedDates.push_back(OrderedBook.publicationDate);
            //cout << OrderedBook.publicationDate << endl;
            getline(orderedthings, OrderedBook.category);
            orderedCategories.push_back(OrderedBook.category);//get first string delimited by comma
            //cout << ordered << endl;
        }
        //Just need to getline inside here to do the ordered things
    }

    //for (int i = 0; i < orderedTitles.size(); i++) {
    //    cout << i << " " << orderedTitles.at(i) << " " << orderedDates.at(i) << " " << endl;
    //}
    

    while (enterYear == 0) {
        cout << "Enter your starting year: (If year not on list then next year will be searched)";
        int x = 0;
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
        beginningyear = x;
        //cin >> beginningyear; //Why do I need this startyear thing anyway?
        beginningyearasstring = to_string(beginningyear);
        //if (beginningyearasstring.find_first_not_of("0123456789") == std::string::npos) {
        //    enterYear = 1;
        //}
        //else {
        //    cout << "Enter a number please." << endl;
        //}
        cout << "Enter your ending year; (If year not on list then prev. year will be searched)";
        x = 0;
        while (!(cin >> x)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input.  Try again: ";
        }
        endingyear = x;
        //cin >> endingyear;
        endingyearasstring = to_string(endingyear);
        //if (endingyearasstring.find_first_not_of("0123456789") == std::string::npos) {
            //enterYear = 1;
        //}
        //else {
            //cout << "Enter a number please." << endl;
        //}
        if (endingyear >= beginningyear) {
            enterYear = 1;
        }
        else {
            cout << "Ending year should not be earlier than beginning year" << endl;
        }
    }

    for (int i = *min_element(years.begin(), years.end()); i <= *max_element(years.begin(), years.end()); i++) {
        yearsInRange.push_back(i);
    }
    for (int i = 0; i < years.size(); i++) {
        years2.push_back(years.at(i));
    }
    it = unique(years2.begin(), years2.end());
    years2.resize(distance(years2.begin(), it));

    //cout << "years2 size is " << years2.size() << endl; //42
    //cout << "years size is " << years.size() << endl; //90
    //cout << "yearsinrange size is " << yearsInRange.size() << endl; //70

    for (int i = 0; i < yearsInRange.size(); i++) {
        while (years2.size() != yearsInRange.size()) {
            years2.push_back(yearsInRange.at(i)); //I'm sure this will return an exception
        }
    }
    //cout << years2.size() << endl; //70
    while ((std::find(yearsInRange.begin(), yearsInRange.end(), beginningyear) != yearsInRange.end()) && (!(std::find(years2.begin(), years2.end(), beginningyear) != years2.end()))) { //If the year is in the yearsInRange but not in the year2
        beginningyear = beginningyear + 1;
    }
    beginningyearasstring = to_string(beginningyear);
    //cout << beginningyear << endl;
    while ((std::find(yearsInRange.begin(), yearsInRange.end(), endingyear) != yearsInRange.end()) && (!(std::find(years2.begin(), years2.end(), endingyear) != years2.end()))) { //If the year is in the yearsInRange but not in the year2
        endingyear = endingyear - 1;
    }
    endingyearasstring = to_string(endingyear);
    //string temp = "";
    

    for (int i = 0; i < dates.size(); i++) {
        if (dates.at(i).find(beginningyearasstring) != std::string::npos) {
            possibleIndexes.push_back(i);
        }
        if (dates.at(i).find(endingyearasstring) != std::string::npos) {
            possibleIndexes.push_back(i);
        }
    }


    //cout << endingyear << endl;
    //cout << beginningyear;
    if (beginningyear < *min_element(years.begin(), years.end()) || (endingyear > *max_element(years.begin(), years.end()))) {
        cout << "No matches found...";
        return;
    }
    
    startyearCount = possibleIndexes.at(0);
    //cout << startyearCount << endl;
    endyearCount = possibleIndexes.at(possibleIndexes.size() - 1);
    //cout << endyearCount << endl;
    cout << "You entered the years " << beginningyear << " and " << endingyear << endl;
    cout << "Books in range: " << endl;
    for (int i = startyearCount; i <= endyearCount; i++) {
        cout << orderedTitles.at(i) << "(" << years.at(i) << ")" << endl; //I just need to order the titles
    }


    //I need to find the number lines with the year
    //How to search integer within a string: first convert integer to string and then take it from here
    //Find all the lines with the year and make a range

}//Well that was easy.

void searchAuthor() {
    vector <string> fileLines;
    vector <string> orderedDates;
    vector <string> orderedFile;
    string lines;
    vector <int> possibleIndexes;
    vector <string> titles;
    vector <string> authors;
    vector <string> dates;
    vector <string> publishers;
    vector <string> categories;
    string author;
    BookList Book;
    int foundStatus = 0;
    ifstream fin;
    fin.open("booklist.csv");

    cout << "Enter the name of an author: " << endl;
    cin.ignore();
    getline(cin, author);
    

    while (getline(fin, lines, '\n')) { //Forgot to add the comma to this equation. I fixed it now.
    //cout << "In the file are " << lines << endl; //Very nice. Now let's search for the year range

        if (lines.find("/") != std::string::npos) {
            fileLines.push_back(lines);
        }
    }

    for (int i = 0; i < fileLines.size(); i++) {
        stringstream ss(fileLines.at(i));
        //string item;
        while (ss.good()) {
            //getline(ss, item, ',');
            //things.push_back(item);

            getline(ss, Book.title, ','); //get first string delimited by comma
            titles.push_back(Book.title);
            //cout << "Title: " << Book.title << endl;
            getline(ss, Book.author, ','); //get first string delimited by comma
            authors.push_back(Book.author);
            //cout << "Author: " << Book.author << endl;
            getline(ss, Book.publisher, ','); //get first string delimited by comma
            publishers.push_back(Book.publisher);
            //cout << "Publisher: " << Book.publisher << endl;
            getline(ss, Book.publicationDate, ','); //get first string delimited by comma
            dates.push_back(Book.publicationDate);
            //cout << "Publication Date: " << Book.publicationDate << endl;
            getline(ss, Book.category); //get first string delimited by comma
            categories.push_back(Book.category);
            //cout << "Category: " << Book.category << endl;
        }

    }
    for (int i = 0; i < fileLines.size(); i++) {
        transform(fileLines.at(i).begin(), fileLines.at(i).end(), fileLines.at(i).begin(), ::tolower); //case sensitivity
        transform(authors.at(i).begin(), authors.at(i).end(), authors.at(i).begin(), ::tolower);
    }
    for (int i = 0; i < authors.size(); i++) {
        if (authors.at(i).find(author) != std::string::npos) {
            if (foundStatus == 0)
            {
                foundStatus = 1;
                cout << "\nbooks writter by " << author << " are below:" << endl;
            }
            cout << titles.at(i) << endl;
        }
    }
    if (foundStatus == 0) {
        //    if (!(std::find(authors.begin(), authors.end(), author) != authors.end())) {
        cout << "No books written by this author. " << endl;
        return;
    }
}


void displayBooksInCategory() {
    vector <string> fileLines;
    vector <string> orderedDates;
    vector <string> orderedFile;
    string lines;
    vector <int> possibleIndexes;
    vector <string> titles;
    vector <string> authors;
    vector <string> dates;
    vector <string> publishers;
    vector <string> categories;
    string category;
    BookList Book;
    ifstream fin;
    fin.open("booklist.csv");

    cout << "Enter a category: " << endl;
    cin.ignore();
    getline(cin, category);

    while (getline(fin, lines, '\n')) { //Forgot to add the comma to this equation. I fixed it now.
//cout << "In the file are " << lines << endl; //Very nice. Now let's search for the year range

        if (lines.find("/") != std::string::npos) {
            fileLines.push_back(lines);
        }
    }

    for (int i = 0; i < fileLines.size(); i++) {
        stringstream ss(fileLines.at(i));
        //string item;
        while (ss.good()) {
            //getline(ss, item, ',');
            //things.push_back(item);

            getline(ss, Book.title, ','); //get first string delimited by comma
            titles.push_back(Book.title);
            //cout << "Title: " << Book.title << endl;
            getline(ss, Book.author, ','); //get first string delimited by comma
            authors.push_back(Book.author);
            //cout << "Author: " << Book.author << endl;
            getline(ss, Book.publisher, ','); //get first string delimited by comma
            publishers.push_back(Book.publisher);
            //cout << "Publisher: " << Book.publisher << endl;
            getline(ss, Book.publicationDate, ','); //get first string delimited by comma
            dates.push_back(Book.publicationDate);
            //cout << "Publication Date: " << Book.publicationDate << endl;
            getline(ss, Book.category); //get first string delimited by comma
            categories.push_back(Book.category);
            //cout << "Category: " << Book.category << endl;
        }

    }
    for (int i = 0; i < categories.size(); i++) {
        categories.at(i).erase(categories.at(i).length() - 3, categories.at(i).length());
        //    cout << "in the list are: " << categories.at(i) << endl;
    }
    for (int i = 0; i < fileLines.size(); i++) {
        transform(fileLines.at(i).begin(), fileLines.at(i).end(), fileLines.at(i).begin(), ::tolower); //case sensitivity
        transform(categories.at(i).begin(), categories.at(i).end(), categories.at(i).begin(), ::tolower);
    }
    //cout << fileLines.size() << endl;
    //cout << categories.size() << endl;
    //cout << titles.size() << endl; This is like the author function.
    if (!(std::find(categories.begin(), categories.end(), category) != categories.end())) {
        cout << "No books written in that category. " << endl;
        return;
    }
    cout << "List of books written in " << category << ":" << endl;
    for (int i = 0; i < fileLines.size(); i++) {
        if (category == categories.at(i)) {
            cout << titles.at(i) << endl;
        }
    }


}


int main() {
    string line;
    vector<BookList> BookVector;
    char menu = 0;
    std::vector<string> search;
    bool isFound = 0;

    int num = 0;

    BookList Book;

    //Just realized that the date is actually a string so...

    ifstream list("booklist.csv");

    //                list.open("booklist.csv");



    if (!list.is_open()) std::cout << "ERROR: File Open" << '\n';
    while ((menu != 'q') && (menu != 'Q')) {
        cout << "What would you like to do?" << endl;
        cout << "1. Look up year range " << endl;
        cout << "2. Search for an author " << endl;
        cout << "3. Display all books for a category " << endl;
    
        cin >> menu;

        if (menu == '1') {
            yearRange(isFound, line, search);
        }
        if (menu == '2') {
            searchAuthor();
        }
        if (menu == '3') {
            displayBooksInCategory();
        }
        if ((menu != '1') && (menu != '2') && (menu != '3') && (menu != 'q') && (menu != 'Q')) {
            cout << "Invalid input." << endl;
        }
        //if (menu == 'q') {
        //    return 0;
        //}
    }




    while (!list.eof()) {
        getline(list, line);
        //                           cout << line << endl;
        stringstream s_stream(line);
        while (s_stream.good()) {
            getline(s_stream, Book.title, ','); //get first string delimited by comma
            getline(s_stream, Book.author, ','); //get first string delimited by comma
            getline(s_stream, Book.publisher, ','); //get first string delimited by comma
            getline(s_stream, Book.publicationDate, ','); //get first string delimited by comma
            getline(s_stream, Book.category); //get first string delimited by comma
            BookVector.push_back(Book);
        }


        //cout << "In the list are: " << i;
    //For now I'm just going to test if all the variables are in the vector.
    //With this thing I copied from Stack Overflow, it worked out just as I expected!
    //However there are some spaces between the items...
    //Now that this works, I will now find out how to search for something in the spreadsheet!


    //string key = Book.category;
    //if (std::count(BookVector.begin(), BookVector.end(), key)) {
    //    cout << "in list";
    //}



        //I'm believing that this pushes all 5 variables to the vector.
        //Which means I have to put something saying "throughout the file, the vectors with the 5 variables are put into one vector.
        //for (int i = 0; i < BookVector.size(); i++) {    //print all splitted strings
        //    cout << "title: " << BookVector.at(i).title << "***";
        //    cout << "author: " << BookVector.at(i).author << "***";
        //    cout << "publisher: " << BookVector.at(i).publisher << "***";
        //    cout << "publicationDate: " << BookVector.at(i).publicationDate << "***";
        //    cout << "category: " << BookVector.at(i).category << endl;
        //}


        //                                cout << "test \n";
        //                                list << column << '\n';
        //                                cout << column << "\n";
        //                                cout << book_string << "\n";

                        //            list >> book1[num];

                        //            ++num;





//I just need to getline column by column

    }



    list.close();
    return 0;


}