#include <iostream>
#include <string>
#include <iomanip>
#include <fstream>
#include <cstdlib> // to clear console

using namespace std;

const int MAX_TASKS = 100; //max no of tasks
const int MAX_PRODUCTS = 100;
const int MAX_ACCOUNTS = 5; // Maximum number of accounts
const int MAX_TRANSACTIONS = 10; // Maximum number of transactions per account

    
//functions called

void clearConsole(); //function to clear console 
void addTask(string tasks[][2], int& taskCount);//add a task
void markascompl(string tasks[][2], string completed[][2], int index, int& taskCount, int& compltaskCount); //mark as complete
void edittask(string tasks[][2], int &c);//edit a task 
void searchtasks(const string task[MAX_TASKS][2], string taskk, int c);
void printToDoList(const string tasks[][2], int numTasks); //print inclomplete tasks
void printToDoList2(const string completed[][2], int& compltaskCount); //print completed tasks 
void getaquote(int &s, int &a, int &d, int &m); // get a quotes
void taskclearer(string tasks[][2],int & taskCount); //clear one of the tasks
void setZero(string tasks[][2], int &taskCount, string complete[][2], int &compltaskCount); //clear all tasks 
void addTaskstudies(string tasks[MAX_TASKS][3], int &numTasks); 
void planDay(string day[MAX_TASKS][2]);
void markascomplstudies(string task[MAX_TASKS][3], string comp[MAX_TASKS][3], int ind, int &tasks, int &c);
void edittaskstudies(string task[MAX_TASKS][3], int c);
void viewTasks(string taskss[MAX_TASKS][3], int numTasks,string comple[MAX_TASKS][3], int c);
void studclear(string tasks[MAX_TASKS][3],int & taskCount, string complete[MAX_TASKS][3], int &complcount);
void addExpense(double accounts[][2], int& numAccounts);
void addIncome(double accounts[][2], int& numAccounts);
void printTransactions(const double accounts[][2], int numAccounts);
void printAccounts(const double accounts[][2], int numAccounts);
void createAccount(double accounts[][2], int& numAccounts);
void manageHealth();
void addproduct(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount);//add product
void markasbought(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], string bdpro[][3], string bfvpro[][3], string bfpro[][3], string bmpro[][3], int ind, int& dpcount, int& fvpcount, int& fpcount, int& mpcount, int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount);
void editproduct(string dairy[][3], string fruit_veg[][3], string  frozen[][3], string meat[][3]);
void searchproducts(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], string s, int& dpcount, int& fvpcount, int& fpcount, int& mpcount);
void prodlearer(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount);
void setprozero(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount, string bdpro[][3], string bfvpro[][3], string bfpro[][3], string bmpro[][3], int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount);
void printtobuyList(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount);
void printtobuyList2(string bdpro[][3], string bfvpro[][3], string bfpro[][3], string bmpro[][3], int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount);
void travelmarkcomp(string array[100],int ind);
void travelremove(string array[100],int ind, int a);
void traveledit(string array[100],int ind,int a);
void traveladd(string array[100],int ind,int a);
void travelview(string array[100],int ind, int a );
void travel();




int main(){
    cout << setw(100) << "Welcome to MTR TO DO LIST APPLICATION !" << endl;
    cout << setw(95) << "Enter your Username and password " << endl;
    string uname;
    int pass=123 , c = 0;
    cout << "Username: ";
    cin >> uname;
    cout << "Password: ";
    cin >> pass;

    if(pass==123){
        clearConsole();
        cout << "Welcome back " << uname << endl;
        while(c!=8){
        cout << setw(100) << "====== MTR =========" << endl;
        cout << setw(100) << "1. Manage Finance " << endl;
        cout << setw(100) << "2. Manage Daily life" << endl;
        cout << setw(100) << "3. Manage Health" << endl;
        cout << setw(100) << "4. Manage Travelling" << endl;
        cout << setw(100) << "5. Manage Studies" << endl;
        cout << setw(100) << "6. Manage Grocery" << endl;
        cout << setw(100) << "7. FAQ's or Suggestions" << endl;
        cout << setw(100) << "8. Exit" << endl;
        cout << setw(100) << "==================" << endl;
        cout << "Enter your choice: ";
        cin >> c;
        clearConsole();
        if(c==1){
            double accounts[MAX_ACCOUNTS][2] = {0}; 

    int numAccounts = 0;
    int choice;
    do {
        cout << "\nMain Menu:\n";
        cout << "1. Add Expense\n";
        cout << "2. Add Income\n";
        cout << "3. View Transactions\n";
        cout << "4. View Accounts\n";
        cout << "5. Create Account\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                addExpense(accounts, numAccounts);
                break;
            case 2:
                addIncome(accounts, numAccounts);
                break;
            case 3:
                printTransactions(accounts, numAccounts);
                break;
            case 4:
                printAccounts(accounts, numAccounts);
                break;
            case 5:
                createAccount(accounts, numAccounts);
                break;
            case 6:
                cout << "Exiting...\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;

        }

        // daily life 
        else if (c==2){
            cout <<setw(100)<< "===== To-Do List Application =====" << endl;
            cout <<setw(79)<<"1. Add a task" << endl;
            cout <<setw(86)<< "2. Mark as complete " << endl;
            cout <<setw(80)<< "3. Edit a task" << endl;
            cout <<setw(79)<< "4. View tasks" << endl;
            cout <<setw(82)<< "5. Search a task" << endl;
            cout <<setw(81)<< "6. Get a Quote " << endl;
            cout <<setw(80)<< "7. Clear task " << endl;
            cout <<setw(73)<< "8. Exit" << endl;
            cout << setw(100)<< "==================================" << endl;

            string tasks[MAX_TASKS][2] , line;
            string completed[MAX_TASKS][2];
            int taskCount = 0;
            int compltaskCount = 0;
            int choice=0;
            int ind;
            int s=0,an=0,d=0,m=0; //emotions for quotes
            string t; //search a string 
            fstream daily,comple;
           

            while(choice!=8){
                cout << "Enter your choice: ";
                cin >> choice;

                switch (choice){
                    case 1:
                    addTask(tasks,taskCount);
                    break;

                    case 2:
                    cout << "Enter Index: ";
                    cin >> ind;
                    markascompl(tasks,completed,ind,taskCount,compltaskCount);
                    break;

                    case 3:
                    edittask(tasks, taskCount);
                    break;

                    case 4:
                    int c;
                    cout << endl << setw(40) << "1 for incomplete Task, 2 for complete tasks, 3 for all tasks: " << endl << "Enter: ";
                    cin >> c;
                    if(c==1){
                        printToDoList(tasks,taskCount);   
                    }
            
                    else if(c==2){
                             printToDoList2(completed,compltaskCount);
                    }
                    else if(c==3){
                             printToDoList(tasks,taskCount);
                             cout << endl << "Completed: ";
                             printToDoList2(completed,compltaskCount);
                    }
                    else {
                        cout << "Invalide choice";
                    }
                    break;

                    case 5: 
                    cout << "Enter task you want to find: ";
                    cin >> t;
                    searchtasks(tasks,t,taskCount);
                    break;

                    case 6:
                    getaquote(s,an,d,m);
                    continue;
        
                    break;

                    case 7:
                    c=0;
                    cout << endl << setw(40) << "1 to clear single task, 2 to clear all tasks" << endl << "Enter: ";
                    cin >> c;
                    if(c==1){
                        taskclearer(tasks,taskCount);
                    }
                    else if(c==2){
                          setZero(tasks,taskCount,completed,compltaskCount);
                    }
                    else {
                        cout << "Invalid choice";
                    }    
                    break;

        
                    case 8:
                    //clearing files ones it ends
                    daily.open("manageday.txt", ios :: out);
                    comple.open("Completedaily.txt", ios :: out);
                    if(daily.is_open()){
                        while(getline(daily,line)){
                            daily << " ";
                        }
                        daily.close();
                    }
                    if(comple.is_open()){
                        while(getline(comple,line)){
                            comple << " ";
                        }
                        comple.close();
                    }
                    cout << "Hope u have a Great Day :)" << endl;
                    break;

                    default:
                    cout << "Please choose from 1-9";
                    break;

            }
            if(choice!=8){
                cout << endl;
                cout << setw(100) << "Completed tasks: " << compltaskCount << endl;
                cout << setw(100) << "Tasks remaining: " << taskCount << endl;
                double prog = (static_cast<double>(compltaskCount) / (taskCount + compltaskCount)) * 100;
                if(taskCount!=0){
                     cout << setw(100) << "Your progress: " << prog << endl;
                }
            }

    }
    
        }
        else if (c==3){
            manageHealth();
        }
        else if (c==4){
            travel();
        }

        //manage studies
        else if (c==5){
            int ch=0;
            string day[8][2], stud[MAX_TASKS][3], stcomple[MAX_TASKS][3], line;
            int counter, complcounter, ind;
            fstream studi,stud2;
            while(ch!=7){
                cout <<  "1. Plan your day" << endl;
                cout <<"2. Manage your quizzes and Assignments" << endl;
                cout << "3. Mark as complete" << endl;
                cout << "4. Edit quizes/asssignments, deadlines or priority" << endl;
                cout << "5. View tasks" << endl;
                cout <<  "6. Clear tasks" << endl;
                cout <<  "7. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> ch;

                switch(ch){
                    case 1:
                    planDay(day);
                    break;

                    case 2:
                    addTaskstudies(stud,counter);
                    break;

                    case 3:
                    cout << "Enter Index: ";
                    cin >> ind;
                    markascomplstudies(stud,stcomple,ind, counter,complcounter);
                    break;

                    case 4:
                    edittaskstudies(stud, counter);
                    break;

                    case 5:
                    viewTasks(stud,counter,stcomple,complcounter);
                    break;

                    case 6:
                    studclear(stud,counter,stcomple,complcounter);
                    break;

                    case 7:
                    cout << "Have a nice day";
                    
                    studi.open("studies.txt", ios :: out);
                    stud2.open("studiescompl.txt", ios :: out);
                    if(studi.is_open()){
                        while(getline(studi,line)){
                            studi << " ";
                        }
                        studi.close();
                    }
                    if(stud2.is_open()){
                        while(getline(stud2,line)){
                            stud2 << " ";
                        }
                        stud2.close();
                    }
                    break;
                }
   
            }
        }

        else if (c==6){
            cout << "===== The Grocery List =====" << endl;
    cout << "1. Add a product in the list" << endl;
    cout << "2. Tick off the product  " << endl;
    cout << "3. Edit a product" << endl;
    cout << "4. View product" << endl;
    cout << "5. Search a product" << endl;
    cout << "6. Clear product " << endl;
    cout << "7. Exit" << endl;
    cout << "==================================" << endl;
    int choice = 0;
    string s;//search a product
    int d;//clear function choice(one or all)
    int dpcount = 0, fvpcount = 0, fpcount = 0, mpcount;
    int bdpcount = 0, bfvpcount = 0, bfpcount = 0, bmpcount = 0;//bought product counters
    int ind = 0;
    
    string bdpro[MAX_PRODUCTS][3], bfvpro[MAX_PRODUCTS][3], bfpro[MAX_PRODUCTS][3], bmpro[MAX_PRODUCTS][3];
    string dairy[MAX_PRODUCTS][3], fruit_veg[MAX_PRODUCTS][3], frozen[MAX_PRODUCTS][3], meat[MAX_PRODUCTS][3];
    while (choice != 7) {
        cout << "Enter your choice : ";
        cin >> choice;

        switch (choice) {
        case 1:
            addproduct(dairy, fruit_veg, frozen, meat, dpcount, fvpcount, fpcount, mpcount);
            break;

        case 2:
            cout << "Enter Index: ";
            cin >> ind;
            markasbought(dairy, fruit_veg, frozen, meat, bdpro, bfvpro, bfpro, bmpro, ind, dpcount, fvpcount, fpcount, mpcount, bdpcount, bfvpcount, bfpcount, bmpcount);
            break;

        case 3:
            editproduct(dairy, fruit_veg, frozen, meat);
            break;

        case 4:
            int c;
            cout << endl << setw(40) << "1 for products not bought, 2 for bought products, 3 for all products: " << endl << "Enter: ";
            cin >> c;
            if (c == 1) {
                printtobuyList(dairy, fruit_veg, frozen, meat, dpcount, fvpcount, fpcount, mpcount);
            }

            else if (c == 2) {
                printtobuyList2(bdpro, bfvpro, bfpro, bmpro, bdpcount, bfvpcount, bfpcount, bmpcount);
            }
            else if (c == 3) {
                printtobuyList(dairy, fruit_veg, frozen, meat, dpcount, fvpcount, fpcount, mpcount);
                cout << endl << "bought: ";
                printtobuyList2(bdpro, bfvpro, bfpro, bmpro, bdpcount, bfvpcount, bfpcount, bmpcount);
            }
            else {
                cout << "Invalide choice";
            }
            break;

        case 5:
            cout << "Enter product you want to find: ";
            cin >> s;
            searchproducts(dairy, fruit_veg, frozen, meat, s, dpcount, fvpcount, fpcount, mpcount);
            break;

        case 6:
            d = 0;
            cout << endl << setw(40) << "1 to clear single product, 2 to clear all products" << endl << "Enter: ";
            cin >> d;
            if (d == 1) {
                prodlearer(dairy, fruit_veg, frozen, meat, dpcount, fvpcount, fpcount, mpcount);
            }
            else if (d == 2) {
                setprozero(dairy, fruit_veg, frozen, meat, dpcount, fvpcount, fpcount, mpcount, bdpro, bfvpro, bfpro, bmpro, bdpcount, bfvpcount, bfpcount, bmpcount);
            }
            else {
                cout << "Invalid choice";
            }
            break;

        case 7:
            cout << "Happy Shopping :)" << endl;
            break;

        default:
            cout << "Please choose from 1-9";
            break;
        }
        }
        }

        else if (c==7){
            int ch=0 , ch2;
            char n;
            string sug;
            while(ch!=3){
                cout << "1. FAQ's" << endl;
                cout <<  "2. Suggestions" << endl;
                cout <<  "3. Exit" << endl;
                cout << "Enter your choice: ";
                cin >> ch;
                
                switch(ch){
                    case 1: 
                    cout << "1. How do I add a task?" << endl;
                    cout << "2. How can I mark a task as complete?" << endl;
                    cout << "3. How do I view the details of a task?" << endl;
                    cout << "4. How can I clear a task from my list?" << endl;
                    cout << "5. Can I get a quote according to my current emotions?" << endl;
                    cout << "6. How do I edit a task?" << endl;
                    cout << "7. Is there a search feature to find specific tasks?" << endl;
                    cout << "Enter: ";
                    cin >> ch2;
                    if(ch2==1){
                        cout << "To add a task, simply click on the Add Task button or tap the + icon. Then, type in the details of your task and press enter or the save button to add it to your list.";
                    }
                    else if(ch2==2){
                        cout << "You can mark a task as complete by clicking on the checkbox next to the task or tapping on the task itself to strike it through. This visually indicates that the task has been completed.";
                    }
                    else if(ch2==3){
                        cout << "To view the details of a task, simply click or tap on the task in your list. This will display the task's title, description, due date, priority, and any other relevant information.";
                    }
                    else if(ch2==4){
                        cout << "You can clear a task from your list by selecting the task and then clicking on the Clear Task button or tapping on the delete icon. This will remove the task from your list.";
                    }
                    else if(ch2==5){
                        cout << "Yes, the app can provide you with quotes tailored to your current emotions. Simply indicate your mood or emotion within the app, and it will generate relevant quotes to uplift or inspire you.";
                    }
                    else if(ch2==6){
                        cout << "To edit a task, click or tap on the task to view its details, then select the edit option. You can then make changes to the task's title, description, due date, priority, or any other details as needed.";
                    }
                    else if(ch2==7){
                        cout << "Yes, the app includes a search feature that allows you to quickly find specific tasks by typing keywords or phrases into the search bar. This helps you locate tasks within large lists or across multiple categories.";
                    }
                    else{
                        cout << "Choose from 1-6";
                    }
                    cout << endl;
                    break;

                    case 2:
                    cout << "Are you happy with our service: (y/n)";
                    cin >> n;
                    n = toupper(n);
                    if(n=='Y'){
                        cout << "Enjoy our app and don't forget to give a review" << endl;;
                    }
                    else if(n == 'N'){
                        cout << "Sorry to hear that. Please give us some suggetions: " << endl;
                        cin >> sug;
                        cout << "We will try our best to improve this!" << endl << "Thanks for the review" << endl;
                    }
                    else{
                        cout << "Invalid choice";
                    }

                }
                

                

            }
            clearConsole();
        }
        else if(c==8){
            cout << "Hope You Enjoyed :)" << endl;
            cout << "Have a nice day";
            break;
        }
        else{
            cout << "Please choose from 1-8" << endl;
        }
        }
    }

     

    else  {
        cout << "Invalid Password :(";
    }

}


void clearConsole() {
    #ifdef _WIN32
        system("cls"); // For Windows
    #elif __linux__
        system("clear"); // For Linux
    #elif __APPLE__
        system("clear"); // For macOS
    #endif
}

//functions 

//add a task 
void addTask(string tasks[MAX_TASKS][2], int &numTasks) //2d array ofstring
{
    fstream dailylife;
    dailylife.open("manageday.txt", ios::out | ios::app);
    string task, date;
    cout << "Enter task: ";
    cin>>task; //  user inputs the task
    cout << "Enter due date (DD-MM-YYYY): ";
    cin>>date; // user inputs the date
    
    if(dailylife.is_open()){
        dailylife << task << "  Date: " << date << endl;
    }

    // Store task and date in the 2D array
    tasks[numTasks][0] = task;
    tasks[numTasks][1] = date;
    numTasks++;
}

//mark as complete 
void markascompl(string task[MAX_TASKS][2], string comp[MAX_TASKS][2], int ind, int &tasks, int &c) {
    if (ind < 1 || ind > tasks) {
        cout << "Invalid index ";
    } else {
        comp[c][0] = task[ind - 1][0];
        comp[c][1] = task[ind - 1][1];
        ofstream comple("Completeddaily.txt", ios::app); // Open in append mode
        if (comple.is_open()) {
            comple << comp[c][0] << " Date: " << comp[c][1] << endl;
            comple.close(); // Close the file after writing
        }
        c++;

        for (int i = ind - 1; i < tasks - 1; i++) {
            task[i][0] = task[i + 1][0];
            task[i][1] = task[i + 1][1];
        }
        tasks--;

        ofstream daily("manageday.txt");
        if (daily.is_open()) {
            for (int i = 0; i < tasks; i++) {
                daily << task[i][0] << "  Date: " << task[i][1] << endl;
            }
            daily.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }
    }
    // Clear the completed task
    task[tasks][0] = "";
    task[tasks][1] = "";
}

//edit a task 
void edittask(string task[MAX_TASKS][2], int &tasks){
    int ind;
    char n;
    cout << "Index of task you want to edit: ";
    cin >> ind;
    cout << "Enter edited version: ";
    cin >> task[ind-1][0];
    cout << "Do u want to change the date as well ?(y) ";
    cin >> n;
    n = toupper(n);
    if(n=='Y'){
        cout << "New date: ";
        cin >> task[ind-1][1];
    }
    fstream daily("manageday.txt", ios::out);
        if (daily.is_open()) {
            for (int i = 0; i < tasks; i++) {
                daily << task[i][0] << "  Date: " << task[i][1] << endl;
            }
            daily.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }
}

//search a task
void searchtasks(const string tasks[MAX_TASKS][2], string taskk, int c) {
    int i;
    int flag=0;
    for (i = 0; i < c; i++) {
        if (taskk == tasks[i][0]) {
            cout << taskk << " is located at index: " << i + 1 << endl;
            cout << "It's due on: " << tasks[i][1] << endl;
            flag = 1;
            break;
        }
    
    }
    if(flag==0){
        cout << "Task is not in the list";
    }
    
}

// Function to print all tasks and their dates in the to-do list
void printToDoList(const string tasks[MAX_TASKS][2], int numTasks) {
    string line;
    ifstream daily;
    cout << endl; 
    daily.open("manageday.txt",ios::in); 
    if(daily.is_open()){
        while(getline(daily, line)){
            cout << line << endl;
        }
    daily.close();
    }
    else{
        cout << "Unable to open the file";
    }
}

// Function to print completed tasks and their dates in the to-do list
void printToDoList2(const string complete[MAX_TASKS][2], int &c) {
    string line;
    ifstream comple;
    cout << endl; 
    comple.open("Completeddaily.txt",ios::in); 
    if(comple.is_open()){
        while(getline(comple, line)){
            cout << line << endl;
        }
    comple.close();
    }
    else{
        cout << "Unable to open the file";
    }
}

//get a quote 
void getaquote(int &s, int &a, int &d, int &m){
    string sad[] = {
        "The only way to find true happiness is to risk being completely cut open.",
        "Don't cry because it's over, smile because it happened." ,
        "Behind every sweet smile, there is a bitter sadness that no one can ever see and feel." ,
        "The saddest people smile the brightest." ,
        "Every man has his secret sorrows which the world knows not; and often times we call a man cold when he is only sad." ,
        "Heaven knows we need never be ashamed of our tears, for they are rain upon the blinding dust of earth, overlying our hard hearts." ,
        "Tears are words that need to be written." ,
        "The greatest pain that comes from love is loving someone you can never have." ,
        "Crying is all right in its way while it lasts. But you have to stop sooner or later, and then you still have to decide what to do." ,
        "I wanted a perfect ending. Now I've learned, the hard way, that some poems don't rhyme, and some stories don't have a clear beginning, middle, and end."
    };

    string anxiety[] = {
        "Worrying does not take away tomorrow's troubles, it takes away today's peace." ,
        "Anxiety happens when you think you have to figure everything out. Turn to the one who has it all figured out." ,
        "Anxiety is the cousin visiting from out of town that depression felt obligated to bring to the party." ,
        "You're not going to master the rest of your life in one day. Just relax. Master the day. Then just keep doing that every day." ,
        "Anxiety is like a rocking chair. It gives you something to do but never gets you anywhere." ,
        "You don't have to control your thoughts. You just have to stop letting them control you." ,
        "Life is ten percent what you experience and ninety percent how you respond to it." ,
        "Anxiety does not empty tomorrow of its sorrows, but only empties today of its strength." ,
        "The mind that never rests cannot find peace but can easily create chaos." ,
        "The truth is you can't control everything. But you can breathe, and let go, and trust that things will work out." ,
    };

    string doubt[] = {
        "Doubt kills more dreams than failure ever will." ,
        "Doubt is a virus that attacks our self-esteem, productivity, and confidence." ,
        "Doubt everything. Find your own light." ,
        "In the end, we only regret the chances we didn't take.",
        "Doubt kills more dreams than failure ever will.",
        "The moment you doubt whether you can fly, you cease forever to be able to do it." ,
        "Don't let the noise of others' opinions drown out your own inner voice." ,
        "Doubt is a pain too lonely to know that faith is his twin brother." ,
        "Doubt is the beginning, not the end, of wisdom." ,
        "You are braver than you believe, stronger than you seem, and smarter than you think." ,
    };

    string moti[] = {
        "The only limit to our realization of tomorrow will be our doubts of today.",
        "The past cannot be changed. The future is yet in your power.",
        "The only way to do great work is to love what you do.",
        "Success is not final, failure is not fatal: It is the courage to continue that counts.",
        "The only thing standing between you and your goal is the story you keep telling yourself as to why you can't achieve it.",
        "Your time is limited, don't waste it living someone else's life.",
        "The future belongs to those who believe in the beauty of their dreams.",
        "If you want to achieve greatness stop asking for permission.",
        "Believe in yourself and all that you are. Know that there is something inside you that is greater than any obstacle.",
        "It does not matter how slowly you go as long as you do not stop.",
    };
    char n;
    cout << "Would you like to share if you're feeling saddened(s), anxious(a), doubtful(d), or in need of motivation(m) ?";
    cin >>n;
    n = toupper(n);
    if(n=='S'){
        cout << sad[s] << endl;;
        s++;
    }
    else if(n=='A'){
        cout << anxiety[a] << endl;
        a++;
    }
    else if(n=='D'){
        cout << doubt[d] << endl;
        d++;
    }
    else if(n=='M'){
        cout << moti[m] << endl;
        m++;
    }
    if(s==10){
        s=0;
    }
    if(a==10){
        a=0;
    }
    if(d==10){
        d=0;
    }
    if(m==10){
        m=0;
    }
}

//clear tasks 
void taskclearer(string tasks[MAX_TASKS][2],int & taskCount) {
    int index;
    cout << "Enter index of task to be cleared: ";
    cin >> index;
    char ch;
    cout << "Are u sure you want to clear this task (y): ";
    cin >> ch;
    ch = toupper(ch);

    if(ch=='Y'){
        if (index >= 1 && index <= taskCount) {                                //checking index entered is valid
                for (int i = index - 1; i < taskCount - 1; i++) {                  //i is the index of the task to be cleared,
                    tasks[i][0] = tasks[i + 1][0];     
                    tasks[i][1] = tasks[i + 1][1];                                  //moving the remaining tasks one index back
                }
                taskCount--;
                ofstream daily("manageday.txt");
                if (daily.is_open()) {
                   for (int i = 0; i < taskCount; i++) {
                    daily << tasks[i][0] << "  Date: " << tasks[i][1] << endl;
                    }
                daily.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
            }
        else {
        cout << "Invalid index." << endl;
    }
    }
    
    
}                                

// clearing all the tasks
void setZero(string tasks[MAX_TASKS][2], int &taskcount, string complete[MAX_TASKS][2], int &complcount) {

    char ch;
    cout << "Are u sure you want to clear this task (y): ";
    cin >> ch;
    ch = toupper(ch);

    if(ch=='Y'){
        for (int i = 0; i < taskcount; ++i) {
        for (int j = 0; j < 2; ++j) {
            tasks[i][j] = " "; //assigning empty space to remove the task 
        }
    }
        for (int i = 0; i < complcount; ++i) {
        for (int j = 0; j < 2; ++j) {
            complete[i][j] = " "; //assigning empty space to remove the task 
        }
    }
    ofstream daily("manageday.txt");
                if (daily.is_open()) {
                   for (int i = 0; i < taskcount; i++) {
                    daily << tasks[i][0] << "  Date: " << tasks[i][1] << endl;
                    }
                daily.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
    ofstream daily2("Completeddaily.txt");
                if (daily2.is_open()) {
                   for (int i = 0; i < taskcount; i++) {
                    daily2 << tasks[i][0] << "  Date: " << tasks[i][1] << endl;
                    }
                daily2.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
    complcount = 0;
    taskcount =0;
    } 
}

//add a task for studies 
void addTaskstudies(string stud[MAX_TASKS][3], int &numTasks) {
    if (numTasks >= MAX_TASKS) {
        cout << "Cannot add more tasks. Maximum limit reached." << endl;
        return;
    }

    string task, date;
    char pr;
    cout << "Enter task: ";
    cin.ignore(); // Ignore newline character left in the buffer
    getline(cin, task); // Use getline to read entire line including spaces
    cout << "Enter due date (DD-MM-YYYY): ";
    cin >> date;
    cout << "Enter priority level (H-high, M-medium, L-low): ";
    cin >> pr;
    pr = toupper(pr);

    while (pr != 'H' && pr != 'M' && pr != 'L') {
        cout << "Invalid priority level. Please enter H, M, or L: ";
        cin >> pr;
        pr = toupper(pr);
    }
    fstream studtask;
    studtask.open("studies.txt", ios::out | ios::app);
    if(studtask.is_open()){
        studtask << "Task: " << task << " Date: " << date << " Priority: " << pr << endl;
        studtask.close(); // Close the file after writing
    }

    // Store task, date, and priority in the 2D array
    stud[numTasks][0] = task;
    stud[numTasks][1] = date;
    stud[numTasks][2] = pr;

    numTasks++;
}

void planDay(string day[8][2]){
    cout << "Wake up at 7" << endl;
    day[0][1] = "7:00 - 9:00";
    cout << "From 7 to 9: ";
    cin >> day[0][0];
    day[1][1] = "9:00 - 11:00";
    cout << "From 9 to 11: ";
    cin >> day[1][0];
    day[2][1] = "11:00 - 13:00";
    cout << "From 11 to 13: ";
    cin >> day[2][0];
    day[3][1] = "13:00 - 15:00";
    cout << "From 13 to 15: ";
    cin >> day[3][0];
    day[4][1] = "15:00 - 17:00";
    cout << "From 15 to 17: ";
    cin >> day[4][0];
    day[5][1] = "17:00 - 19:00";
    cout << "From 17 to 19: ";
    cin >> day[5][0];
    day[6][1] = "19:00 - 21:00";
    cout << "From 19 to 21: ";
    cin >> day[6][0];
    day[7][1] = "21:00 - 7:00";
    day[7][0] = "Sleep";

    for(int i=0; i<=7; i++){
        cout << day[i][1] << " : " << day[i][0];
        cout << endl;
    }
}

//mark as complete 
void markascomplstudies(string task[MAX_TASKS][3], string comp[MAX_TASKS][3], int ind, int &tasks, int &c) {
    if (ind < 1 || ind > tasks) {
        cout << "Invalid index ";
    } else {
        comp[c][0] = task[ind - 1][0];
        comp[c][1] = task[ind - 1][1];
        comp[c][2] = task[ind - 1][2]; 
        c++;
        ofstream studtask2("studiescompl.txt", ios::app); // Open in append mode
        if (studtask2.is_open()) {
            studtask2 << comp[c - 1][0] << " Date: " << comp[c - 1][1] << " Prioroty: " << comp[c - 1][2] << endl;
            studtask2.close(); // Close the file after writing
        }
        
        for (int i = ind - 1; i < tasks - 1; i++) {
            task[i][0] = task[i + 1][0]; 
            task[i][1] = task[i + 1][1]; 
            task[i][2] = task[i + 1][2];
        }
        tasks--;
        
        ofstream studtask("studies.txt");
        if (studtask.is_open()) {
            for (int i = 0; i < tasks; i++) {
                studtask << task[i][0] << "  Date: " << task[i][1] << " Prioroty: " << task[i][2] << endl;
            }
            studtask.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }
    }
}

//edit a task 
void edittaskstudies(string task[MAX_TASKS][3], int c){
    int ind;
    char n;
    cout << "Index of task you want to edit: ";
    cin >> ind;
    cout << "Enter edited version: ";
    cin >> task[ind-1][0];
    cout << "Do u want to change the date as well ?(y) ";
    cin >> n;
    n = toupper(n);
    if(n=='Y'){
        cout << "New date: ";
        cin >> task[ind-1][1];
    }
    cout << "Do u want to change the priority as well ?(y) ";
    cin >> n;
    n = toupper(n);
    if(n=='Y'){
        cout << "New date: ";
        cin >> task[ind-1][2];
    }

    fstream studtask("studies.txt", ios::out);
        if (studtask.is_open()) {
            for (int i = 0; i < c; i++) {
                studtask << task[i][0] << "  Date: " << task[i][1] << " Prioroty: " << task[i][2] << endl;
            }
            studtask.close();
        } else {
            cout << "Error opening file for writing." << endl;
        }
}

//view tasks studies 
void viewTasks(string taskss[MAX_TASKS][3], int numTasks,string comple[MAX_TASKS][3], int c) {
    int ch;
    cout << "1. All Tasks" << endl;
    cout << "2. High priority Tasks" << endl;
    cout << "3. Medium priority Tasks" << endl;
    cout << "4. Low priority Tasks" << endl;
    cout << "5. Completed Tasks" << endl;
    cout << "Enter your choice: ";
    cin >> ch;

    if (ch != 5 && numTasks == 0) {
        cout << "No tasks to display." << endl;
        return;
    }
    else if (ch == 5 && numTasks == 0) {
        cout << "No tasks to display." << endl;
        return;
    }

    else if (ch == 1) {
        for (int i = 0; i < numTasks; i++) {
            cout << "Task: " << taskss[i][0] << endl;
            cout << "Due Date: " << taskss[i][1] << endl;
            cout << "Priority: " << taskss[i][2] << endl << endl;
        }
    }

    else if (ch == 2) {
        for (int i = 0; i < numTasks; i++) {
            if(taskss[i][2]=="H"){
                cout << "Task: " << taskss[i][0] << endl;
                cout << "Due Date: " << taskss[i][1] << endl;
                cout << "Priority: " << taskss[i][2] << endl << endl;
            }
        }
    }

    else if (ch == 3) {
        for (int i = 0; i < numTasks; i++) {
            if(taskss[i][2]=="M"){
                cout << "Task: " << taskss[i][0] << endl;
                cout << "Due Date: " << taskss[i][1] << endl;
                cout << "Priority: " << taskss[i][2] << endl << endl;
            }
        }
    }

    else if (ch == 4) {
        for (int i = 0; i < numTasks; i++) {
            if(taskss[i][2]=="L"){
                cout << "Task: " << taskss[i][0] << endl;
                cout << "Due Date: " << taskss[i][1] << endl;
                cout << "Priority: " << taskss[i][2] << endl << endl;
            }
        }
    }

    else if (ch == 5) {
        for (int i = 0; i < c; i++) {
            cout << "Task: " << comple[i][0] << endl;
            cout << "Due Date: " << comple[i][1] << endl;
            cout << "Priority: " << comple[i][2] << endl << endl;
        }
    }

    else{ 
        cout << "Invalid choice";
    }
}

//clear tasks 
void studclear(string tasks[MAX_TASKS][3],int & taskCount, string complete[MAX_TASKS][3], int &complcount){
    int ch;
    cout << "1. Clear one task" << endl;
    cout << "2. Clear all tasks" << endl;
    cout << "Enter: ";
    cin >> ch;

    if(ch==1){
        int index;
        cout << "Enter index of task to be cleared: ";
        cin >> index;
        char ch;
        cout << "Are u sure you want to clear this task (y): ";
        cin >> ch;
        ch = toupper(ch);

        if(ch=='Y'){
            if (index >= 1 && index <= taskCount) {                              
                for (int i = index - 1; i < taskCount - 1; i++) {                  
                    tasks[i][0] = tasks[i + 1][0];     
                    tasks[i][1] = tasks[i + 1][1];  
                    tasks[i][2] = tasks[i + 1][2];                              
                }
                taskCount--;                                                          
                cout << "The mentioned task is cleared from the list." << endl;
                ofstream stud("studies.txt");
                if (stud.is_open()) {
                   for (int i = 0; i < taskCount; i++) {
                    stud << tasks[i][0] << "  Date: " << tasks[i][1] << endl;
                    }
                stud.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
            }
            else {
                cout << "Invalid index." << endl;
            }
        }
    }

    if(ch==2){
        char ch;
        cout << "Are u sure you want to clear this task (y): ";
        cin >> ch;
        ch = toupper(ch);

        if(ch=='Y'){
            for (int i = 0; i < taskCount; ++i) {
                for (int j = 0; j < 3; ++j) {
                  tasks[i][j] = " "; //assigning empty space to remove the task 
                }
            }
            for (int i = 0; i < complcount; ++i) {
                for (int j = 0; j < 2; ++j) {
                    complete[i][j] = " "; //assigning empty space to remove the task 
                 }
            }
        ofstream stud("studies.txt");
                if (stud.is_open()) {
                   for (int i = 0; i < taskCount; i++) {
                    stud << tasks[i][0] << tasks[i][1] << tasks[i][2] << endl;
                    }
                stud.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
        ofstream stud2("studiescompl.txt");
                if (stud2.is_open()) {
                   for (int i = 0; i < complcount; i++) {
                    stud2 << complete[i][0] << complete[i][1] << complete[i][2] << endl;
                    }
                stud2.close();
                } else {
                     cout << "Error opening file for writing." << endl;
                }
        complcount = 0;
        taskCount = 0;
    }

    else {
        cout << "Invalid choice";
    }
    }
}

void addExpense(double accounts[][2], int& numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts available. Please create an account first.\n";
        return;
    }

    int accountIndex;
    cout << "Select the account to add expense (1-" << numAccounts << "): ";
    cin >> accountIndex;

    if (accountIndex < 1 || accountIndex > numAccounts) {
        cout << "Invalid account selection.\n";
        return;
    }

    double expense;
    cout << "Enter expense amount: Rs";
    cin >> expense;

    accounts[accountIndex - 1][0] -= expense; // Deduct expense from account balance

    cout << "Expense added successfully.\n";
}

void addIncome(double accounts[][2], int& numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts available. Please create an account first.\n";
        return;
    }

    int accountIndex;
    cout << "Select the account to add income (1-" << numAccounts << "): ";
    cin >> accountIndex;

    if (accountIndex < 1 || accountIndex > numAccounts) {
        cout << "Invalid account selection.\n";
        return;
    }

    double income;
    cout << "Enter income amount: Rs";
    cin >> income;

    accounts[accountIndex - 1][0] += income; // Add income to account balance
    accounts[accountIndex - 1][1] += income; // Update total income of the account

    cout << "Income added successfully.\n";
}

void printTransactions(const double accounts[][2], int numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts available. Please create an account first.\n";
        return;
    }

    int accountIndex;
    cout << "Select the account to view transactions (1-" << numAccounts << "): ";
    cin >> accountIndex;

    if (accountIndex < 1 || accountIndex > numAccounts) {
        cout << "Invalid account selection.\n";
        return;
    }

    cout << "Transactions for Account " << accountIndex << ":\n";
    // Implement transaction viewing logic here
}

void printAccounts(const double accounts[][2], int numAccounts) {
    if (numAccounts == 0) {
        cout << "No accounts available.\n";
        return;
    }

    cout << "Accounts:\n";
    for (int i = 0; i < numAccounts; ++i) {
        cout << "Account " << i + 1 << ": Balance Rs" << fixed << setprecision(2) << accounts[i][0];
        cout << ", Total Income Rs" << fixed << setprecision(2) << accounts[i][1] << endl;
    }
}

void createAccount(double accounts[][2], int& numAccounts) {
    if (numAccounts == MAX_ACCOUNTS) {
        cout << "Maximum number of accounts reached.\n";
        return;
    }

    cout << "Creating new account...\n";
   
    accounts[numAccounts][0] = 0; // Initializing balance of new account to 0
    accounts[numAccounts][1] = 0; // Initializing total income of new account to 0
    numAccounts++;
    cout << "Account created successfully.\n";
}

void manageHealth() {
    int exerciseDuration = 0;
    int dailyCalories = 0;
    bool hasAteHealthy = false;
    int sleepHours = 0;
    int stressLevel = 0;
    int waterIntake = 0; 
    double height = 0.0; 
    double weight = 0.0; 
    int restingHeartRate = 0;
    int fruitServings = 0;
    int vegetableServings = 0;
    int alcoholicDrinks = 0;
    bool sunscreenUsed = false;
    int screenTime = 0; 
    int systolicBP = 0;
    int diastolicBP = 0;
    string mood;

    cout << "Enter exercise duration (minutes): ";
    cin >> exerciseDuration;

    cout << "Enter daily calorie intake: ";
    cin >> dailyCalories;

    cout << "Did you eat healthy today? (1 for yes, 0 for no): ";
    cin >> hasAteHealthy;

    cout << "Enter sleep duration (hours): ";
    cin >> sleepHours;

    cout << "Enter stress level (1-10, 1 being low, 10 being high): ";
    cin >> stressLevel;

    cout << "Enter water intake (ounces): ";
    cin >> waterIntake;

    cout << "Enter your height (in inches): ";
    cin >> height;

    cout << "Enter your weight (in pounds): ";
    cin >> weight;

    cout << "Enter your resting heart rate: ";
    cin >> restingHeartRate;

    cout << "How many servings of fruits did you have today? ";
    cin >> fruitServings;

    cout << "How many servings of vegetables did you have today? ";
    cin >> vegetableServings;

    cout << "How many alcoholic drinks did you consume today? ";
    cin >> alcoholicDrinks;

    cout << "Did you use sunscreen today? (1 for yes, 0 for no): ";
    cin >> sunscreenUsed;

    cout << "How many hours did you spend on screens today? ";
    cin >> screenTime;

    cout << "Enter your systolic blood pressure: ";
    cin >> systolicBP;

    cout << "Enter your diastolic blood pressure: ";
    cin >> diastolicBP;

    cout << "How are you feeling today? (e.g., happy, stressed, tired): ";
    cin.ignore(); 
    getline(cin, mood);

    cout << "\nHealth Summary:\n";
    cout << "----------------\n";
    cout << "Exercise Duration: " << exerciseDuration << " minutes\n";
    cout << "Daily Calorie Intake: " << dailyCalories << " calories\n";
    cout << "Ate Healthy: " << (hasAteHealthy ? "Yes" : "No") << endl;
    cout << "Sleep Duration: " << sleepHours << " hours\n";
    cout << "Stress Level: " << stressLevel << " out of 10\n";
    cout << "Water Intake: " << waterIntake << " ounces\n";
    cout << "Height: " << height << " inches\n";
    cout << "Weight: " << weight << " pounds\n";
    cout << "Resting Heart Rate: " << restingHeartRate << " bpm\n";
    cout << "Fruit Servings: " << fruitServings << " servings\n";
    cout << "Vegetable Servings: " << vegetableServings << " servings\n";
    cout << "Alcoholic Drinks: " << alcoholicDrinks << " drinks\n";
    cout << "Sunscreen Used: " << (sunscreenUsed ? "Yes" : "No") << endl;
    cout << "Screen Time: " << screenTime << " hours\n";
    cout << "Systolic Blood Pressure: " << systolicBP << " mmHg\n";
    cout << "Diastolic Blood Pressure: " << diastolicBP << " mmHg\n";
    cout << "Mood: " << mood << endl;

    // BMI Calculation
    double bmi = (weight / (height * height)) * 703;  
    cout << "BMI: " << bmi << endl;

  
    cout << "\nAdvices:\n";

    // Health Advice
    // Exercise duration advice
    if (exerciseDuration < 30) {
        cout << "Aim for at least 30 minutes of moderate-intensity exercise most days of the week for optimal health.\n";
    }

    // Daily calorie intake advice
    if (dailyCalories > 2000) {
        cout << "Consider reducing calorie intake if it exceeds 2000 calories per day for maintaining a healthy weight.\n";
    }

    // Sleep duration advice
    if (sleepHours < 7) {
        cout << "Ensure you're getting at least 7 hours of quality sleep each night to support overall health and well-being.\n";
    }

    // Stress level advice
    if (stressLevel > 5) {
        cout << "Practice stress management techniques such as mindfulness, exercise, or relaxation exercises to reduce stress levels.\n";
    }

    // Water intake advice
    if (waterIntake < 64) {
        cout << "Aim to drink at least 8 glasses (64 ounces) of water per day to stay properly hydrated.\n";
    }

    // BMI advice
    if (bmi < 18.5) {
        cout << "Your BMI indicates you may be underweight. Ensure you're consuming enough nutrients and consider consulting a healthcare professional.\n";
    } else if (bmi >= 25) {
        cout << "Your BMI indicates you may be overweight. Consider incorporating more physical activity and healthier eating habits.\n";
    }

    // Heart rate advice
    if (restingHeartRate < 60 || restingHeartRate > 100) {
        cout << "Your resting heart rate is outside the normal range (60-100 bpm). Please consult a doctor.\n";
    }

    // Fruit and vegetable intake advice
    if (fruitServings + vegetableServings < 5) {
        cout << "You should aim for at least 5 servings of fruits and vegetables combined per day.\n";
    }

    // Alcohol consumption advice
    if (alcoholicDrinks > 2) {
        cout << "Limit alcohol consumption to no more than 2 drinks per day for men and 1 drink per day for women.\n";
    }

    // Sunscreen usage advice
    if (!sunscreenUsed && screenTime > 1) {
        cout << "If you're spending time outdoors, remember to use sunscreen to protect your skin from harmful UV rays.\n";
    }

    // Screen time advice
    if (screenTime > 2) {
        cout << "Try to limit screen time to reduce eye strain and promote better sleep.\n";
    }

    // Blood pressure advice
    if (systolicBP >= 140 || diastolicBP >= 90) {
        cout << "Your blood pressure is elevated. Consider consulting a healthcare professional.\n";
    }

    // Mood-based advice
    if (mood == "stressed") {
        cout << "Take some time to relax and practice stress-reducing activities like deep breathing or meditation.\n";
    } else if (mood == "tired") {
        cout << "Make sure you're getting enough restful sleep each night to combat fatigue.\n";
    }

    // Overall health assessment
    bool isHealthy = (exerciseDuration >= 30) && hasAteHealthy && (dailyCalories <= 2000) && (sleepHours >= 7) && (stressLevel <= 5) && (waterIntake >= 64);
    if (isHealthy) {
        cout << "Your overall health seems good based on the provided information. Keep up the good work!\n";
    } else {
        cout << "Consider making some lifestyle changes to improve your overall health and well-being.\n";
    }
}

void addproduct(string dairy[][3], string fruit_veg[][3], string frozen[][3], string meat[][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount)
{
    string product;
    int qty;
    float price;
    cout << "In which category would you like to add" << endl;
    cout << "a)dairy  b)fruit_veg  c)frozen  d)meat: ";
    char choice;//category choice

    cin >> choice;

    cout << "Enter product name: ";
    cin >> product;
    cout << "Enter quantity: ";
    cin >> qty;
    cout << "enter price: ";
    cin >> price;
    

    switch (choice)
    {
    case 'a':
    
              dairy[dpcount][0] = product;
        dairy[dpcount][1] = to_string(price);
        dairy[dpcount][2] = to_string(qty);
        dpcount++;
        break;
    

    case 'b':
    
        fruit_veg[fvpcount][0] = product;
        fruit_veg[fvpcount][1] = to_string(price);
        fruit_veg[fvpcount][2] = to_string(qty);
        fvpcount++;
        break;
    case 'c':
    
       frozen[fpcount][0] = product;
        frozen[fpcount][1] = to_string(price);
        frozen[fpcount][2] = to_string(qty);
        fpcount++;
        break;

    case 'd':

        meat[mpcount][0] = product;
        meat[mpcount][1] = to_string(price);
        meat[mpcount][2] = to_string(qty);
        mpcount++;
        break;

    default:
        cout << "Invalid choice";
        break;
  }
    
}
void markasbought(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3], string bdpro[MAX_PRODUCTS][3], string bfvpro[MAX_PRODUCTS][3], string bfpro[MAX_PRODUCTS][3], string bmpro[MAX_PRODUCTS][3], int ind, int& dpcount, int& fvpcount, int& fpcount, int& mpcount, int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount)
{
    char b;//category choice
    cout << "In which grocery list would you like to mark the products as bought: ";
    cout << "a)dairy  b)fruit_veg  c)frozen  d)meat: ";
    cin >> b;

    switch (b)
    {
    case 'a':
    
        if (ind < 1 || ind > dpcount) {
            cout << "Invalid index ";
        }
        else {
            bdpro[bdpcount][0] = dairy[ind - 1][0];
            bdpro[bdpcount][1] = dairy[ind - 1][1];
            bdpro[bdpcount][2] = dairy[ind - 1][2];
            bdpcount++;
            for (int i = ind - 1; i < dpcount; i++) {
                dairy[i][0] = dairy[i + 1][0];
                dairy[i][1] = dairy[i + 1][1];
                dairy[i][2] = dairy[i + 1][2];
            }
            dpcount--;
        }
        break;
    

    case 'b':
    
        if (ind < 1 || ind > fvpcount) {
            cout << "Invalid index ";
        }
        else {
            bfvpro[bfvpcount][0] = fruit_veg[ind - 1][0];
            bfvpro[bfvpcount][1] = fruit_veg[ind - 1][1];
            bfvpro[bfvpcount][2] = fruit_veg[ind - 1][2];
            bfvpcount++;
            for (int i = ind - 1; i < fvpcount; i++) {
                fruit_veg[i][0] = fruit_veg[i + 1][0];
                fruit_veg[i][1] = fruit_veg[i + 1][1];
                fruit_veg[i][2] = fruit_veg[i + 1][2];
            }
            fvpcount--;
        }
        break;
    
    case 'c':
    
        if (ind < 1 || ind > fpcount) {
            cout << "Invalid index ";
        }
        else {
            bfpro[bfpcount][0] = frozen[ind - 1][0];
            bfpro[bfpcount][1] = frozen[ind - 1][1];
            bfpro[bfpcount][2] = frozen[ind - 1][2];
            bfpcount++;
            for (int i = ind - 1; i < fpcount; i++) {
                frozen[i][0] = frozen[i + 1][0];
                frozen[i][1] = frozen[i + 1][1];
                frozen[i][2] = frozen[i + 1][2];
            }
            fpcount--;
        }
        break;
    
    case 'd':
    
        if (ind < 1 || ind > mpcount) {
            cout << "Invalid index ";
        }
        else {
            bmpro[bmpcount][0] = meat[ind - 1][0];
            bmpro[bmpcount][1] = meat[ind - 1][1];
            bmpro[bmpcount][2] = meat[ind - 1][2];
            bmpcount++;
            for (int i = ind - 1; i < mpcount; i++) {
                meat[i][0] = meat[i + 1][0];
                meat[i][1] = meat[i + 1][1];
                meat[i][2] = meat[i + 1][2];
            }
            mpcount--;
        }
        break;
    
    }
    
}
void editproduct(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string  frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3])
{
    char c;//category choice
    cout << "In which grocery list would you like to edit the product: ";
    cout << "a)dairy  b)fruit_veg  c)frozen  d)meat: ";
    cin >> c;
    int ind;
    switch (c)
    {
     case'a':
    
        

        cout << "Index of task you want to edit: ";
        cin >> ind;
        cout << "Enter edited version: ";
        cin >> dairy[ind - 1][0];
        break;
    
     case'b':

    

    cout << "Index of task you want to edit: ";
    cin >> ind;
    cout << "Enter edited version: ";
    cin >> fruit_veg[ind - 1][0];
    break;

     case'c':

    

    cout << "Index of task you want to edit: ";
    cin >> ind;
    cout << "Enter edited version: ";
    cin >> frozen[ind - 1][0];
    break;

     case'd':

    

    cout << "Index of task you want to edit: ";
    cin >> ind;
    cout << "Enter edited version: ";
    cin >> meat[ind - 1][0];
    break;

}
}
//search a product
void searchproducts(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3], string s, int& dpcount, int& fvpcount, int& fpcount, int& mpcount) {
    int i;
    int flag = 0;
    char f;
    cout << "In which category would you like to search a product: ";
    cout << "a)dairy  b)fruit_veg c)frozen d)meat: ";
    cin >> f;
    switch (f)
    {
    case 'a':
    {
        for (i = 0; i < dpcount; i++) {
            if (s == dairy[i][0]) {
                cout << s << " is located at index: " << i + 1 << endl;

                flag = 1;
                break;
            }

        }
        if (flag == 0) {
            cout << "Product is not in the list: ";
        }
        break;
    }
    case 'b':
    {
        for (i = 0; i < fvpcount; i++) {
            if (s == fruit_veg[i][0]) {
                cout << s << " is located at index: " << i + 1 << endl;

                flag = 1;
                break;
            }

        }
        if (flag == 0) {
            cout << "Product is not in the list: ";
        }
        break;
    }
    case 'c':
    {
        for (i = 0; i < fpcount; i++) {
            if (s == frozen[i][0]) {
                cout << s << " is located at index: " << i + 1 << endl;

                flag = 1;
                break;
            }

        }
        if (flag == 0) {
            cout << "Product is not in the list: ";
        }
        break;
    }
    case 'd':
    {
        for (i = 0; i < mpcount; i++) {
            if (s == meat[i][0]) {
                cout << s << " is located at index: " << i + 1 << endl;

                flag = 1;
                break;
            }

        }
        if (flag == 0) {
            cout << "Product is not in the list: ";
        }
    }
    break;
    }
}
void prodlearer(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount)
{
    char h;// category choice

    cout << "From which list would you like to clear a product:  " << endl;
    cout << "a)dairy b)fruit_veg c)frozen d)meat: ";
    cin >> h;
    char ch;
    int index;
    switch (h)
    {
case 'a':

    
    cout << "Enter index of product to be cleared: ";
    cin >> index;
    
    cout << "Are u sure you want to clear this task (y): ";
    
    ch = toupper(ch);

    if (ch == 'Y') {
        if (index >= 1 && index <= dpcount) {                                //checking index entered is valid
            for (int i = index - 1; i < dpcount - 1; i++) {                  //i is the index of the product to be cleared,
                dairy[i][0] = dairy[i + 1][0];
                dairy[i][1] = dairy[i + 1][1];                                  //moving the remaining products one index back
            }
            dpcount--;                                                           //decrementing the procount by 1
            cout << "The mentioned product is cleared from the list." << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
break;
case 'b':

    
    cout << "Enter index of product to be cleared: ";
    cin >> index;
    
    cout << "Are u sure you want to clear this task (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        if (index >= 1 && index <= fvpcount) {                                //checking index entered is valid
            for (int i = index - 1; i < fvpcount - 1; i++) {                  //i is the index of the product to be cleared,
                fruit_veg[i][0] = fruit_veg[i + 1][0];
                fruit_veg[i][1] = fruit_veg[i + 1][1];                                  //moving the remaining products one index back
            }
            fvpcount--;                                                           //decrementing the procount by 1
            cout << "The mentioned product is cleared from the list.  " << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
break;
case 'c':

    
    cout << "Enter index of product to be cleared: ";
    cin >> index;
    
    cout << "Are u sure you want to clear this task (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        if (index >= 1 && index <= fpcount) {                                //checking index entered is valid
            for (int i = index - 1; i < fpcount - 1; i++) {                  //i is the index of the product to be cleared,
                frozen[i][0] = frozen[i + 1][0];
                frozen[i][1] = frozen[i + 1][1];                                  //moving the remaining products one index back
            }
            fpcount--;                                                           //decrementing the procount by 1
            cout << "The mentioned product is cleared from the list." << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
break;
case 'd':

    
    cout << "Enter index of product to be cleared: ";
    cin >> index;
    
    cout << "Are u sure you want to clear this task (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        if (index >= 1 && index <= mpcount) {                                //checking index entered is valid
            for (int i = index - 1; i < mpcount - 1; i++) {                  //i is the index of the product to be cleared,
                meat[i][0] = meat[i + 1][0];
                meat[i][1] = meat[i + 1][1];                                  //moving the remaining products one index back
            }
            mpcount--;                                                           //decrementing the procount by 1
            cout << "The mentioned product is cleared from the list." << endl;
        }
        else {
            cout << "Invalid index." << endl;
        }
    }
break;
}
}
void setprozero(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount, string bdpro[][3], string bfvpro[][3], string bfpro[][3], string bmpro[][3], int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount)
{
    char f;
    cout << "Which list would you like to clear" << endl;
    cout  << "a)dairy b)fruit_veg c)frozen d)meat: ";
    cin >> f;
    char ch;
switch (f){
case 'a':
{
    
    cout << "Are u sure you want to clear this list (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        for (int i = 0; i < dpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                dairy[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        for (int i = 0; i < bdpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                bdpro[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        bdpcount = 0;
        dpcount = 0;
    }
case 'b':
{
    
    cout << "Are u sure you want to clear this list (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        for (int i = 0; i < fvpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                fruit_veg[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        for (int i = 0; i < bfvpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                bfvpro[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        bfvpcount = 0;
        fvpcount = 0;
    }
case 'c':

    
    cout << "Are u sure you want to clear this list (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        for (int i = 0; i < fpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                frozen[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        for (int i = 0; i < bfpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                bfpro[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        bfpcount = 0;
        fpcount = 0;
    }
case 'd':
{
    
    cout << "Are u sure you want to clear this list (y): ";
    cin >> ch;
    ch = toupper(ch);

    if (ch == 'Y') {
        for (int i = 0; i < mpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                meat[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        for (int i = 0; i < bmpcount; ++i) {
            for (int j = 0; j < 2; ++j) {
                bmpro[i][j] = " "; //assigning empty space to remove the task 
            }
        }
        bmpcount = 0;
        mpcount = 0;
    }
}
}
}
}
}
void printtobuyList(string dairy[MAX_PRODUCTS][3], string fruit_veg[MAX_PRODUCTS][3], string frozen[MAX_PRODUCTS][3], string meat[MAX_PRODUCTS][3], int& dpcount, int& fvpcount, int& fpcount, int& mpcount)
{
    cout << "Which list would you like to view" << endl;
    cout  << "a)dairy  b)fruit_veg  c)frozen  d)meat: ";
    char d;
    cin >> d;
    switch (d)
    {
    case'a':
    {
        if (dpcount == 0) {
            cout << "No tasks in the dairy products list." << endl;
            return;
        }
        cout << "            To-Do List:" << endl;
        for (int i = 0; i < dpcount; ++i) {
            cout << "- " << dairy[i][0] << endl;
        }
        break;
    }
    case'b':
    {
        if (fvpcount == 0) {
            cout << "No tasks in the fruit and vegetable products list." << endl;
            return;
        }
        cout << "            To-Do List:" << endl;
        for (int i = 0; i < fvpcount; ++i) {
            cout << "- " << fruit_veg[i][0] << endl;
        }
        break;
    }
    case'c':
    {
        if (fpcount == 0) {
            cout << "No tasks in the frozen products list." << endl;
            return;
        }
        cout << "            To-Do List:" << endl;
        for (int i = 0; i < fpcount; ++i) {
            cout << "- " << frozen[i][0] << endl;
        }
        break;
    }
    case'd':
    {
        if (mpcount == 0) {
            cout << "No tasks in the meat products list." << endl;
            return;
        }
        cout << "            To-Do List:" << endl;
        for (int i = 0; i < mpcount; ++i) {
            cout << "- " << meat[i][0] << endl;
        }

    }
    break;
    }
}
// Function to print boughtproducts 
void printtobuyList2(string bdpro[MAX_PRODUCTS][3], string bfvpro[MAX_PRODUCTS][3], string bfpro[MAX_PRODUCTS][3], string bmpro[MAX_PRODUCTS][3], int& bdpcount, int& bfvpcount, int& bfpcount, int& bmpcount) {
    cout << "Which list would you like to view "<< endl;
    cout << "a)dairy  b)fruit_veg  c)frozen  d)meat:  ";
    char e;
    cin >> e;
    switch (e)
    {
    case'a':
        {
            if (bdpcount == 0) {
                cout << "No product is bought yet." << endl;
                return;
            }
            cout << endl;
            for (int i = 0; i < bdpcount; ++i) {
                cout << "- " << bdpro[i][0] << endl;
            }
            break;
        }
    case'b':
        {
            if (bfvpcount == 0) {
                cout << "No product is bought yet." << endl;
                return;
            }
            cout << endl;
            for (int i = 0; i < bfvpcount; ++i) {
                cout << "- " << bfvpro[i][0] << endl;
            }
            break;
        }
    case'c':
        {
            if (bfpcount == 0) {
                cout << "No product is bought yet." << endl;
                return;
            }
            cout << endl;
            for (int i = 0; i < bfpcount; ++i) {
                cout << "- " << bfpro[i][0] << endl;
            }
            break;
        }
    case'd':
        {
            if (bmpcount == 0) {
                cout << "No product is bought yet." << endl;
                return;
            }
            cout << endl;
            for (int i = 0; i < bmpcount; ++i) {
                cout << "- " << bmpro[i][0] << endl;
            }
            break;
        }
    }
}

void travelmarkcomp(string array[100],int ind){
    cout << "Index number you want to mark as complete: ";
        cin >> ind;
        array[ind-1]=array[ind-1]+"  (Done)";
}
void travelremove(string array[100],int ind, int a){
    cout << "Index number you want to remove ";
        cin >> ind;
        if (ind<1||ind>a){
            cout << "Invalid Index"<< endl;
        }
        else{
        
     for(int o = ind; o < a; ++o) {
        array[o - 1] = array[o];
    }}}
    
void traveledit(string array[100],int ind,int a){
    cout << "Index number you want to edit: ";
        cin >> ind;
        if (ind<1||ind>a){
            cout << "Invalid Index"<< endl;
        }
        else{
    
    string edit;
    cout << "Write the edited version: ";
    cin.ignore();
    getline(cin, edit);
    array[ind-1]=edit;  }
}
void traveladd(string array[100],int ind,int a){
    string newtask;
    cin.ignore();
    cout << "What is the new task? ";
    getline(cin, newtask);
    array[a]=newtask;
    
}
void travelview(string array[100],int ind, int a ){
    for (int o=0; o< a;o++){
        cout << o+1  <<". " << array[o] <<endl;
    }
}

 
void travel(){
    int i=0, j=0, k=0,ind,listno=-1,changeno;;
    string des, dep, arrival, task[100], task1[100], task2[100];
    cout << "Destination: ";
    cin.ignore();
    getline(cin, des);
    cout << "Departure date and time: ";
    
    getline(cin, dep);
    cout << "Arrival date and time: ";
    
    getline(cin, arrival);
    cout << "Pre-Departure Checklist(Enter done to end): "<< endl;
    while (i < 100) {
        cout << i + 1 << ". " ;
        cin>>task[i];
        if (task[i] == "done") break;
        i++;
    }
    cout << "Places to visit(Enter done to end): "<< endl;
    while (j < 100) {
        cout << j + 1 << ". " ;
        cin>>task1[j];
        if (task1[j] == "done") break;
        j++;
    }
    cout << "Food to eat(Enter done to end): "<< endl;
    while (k < 100) {
        cout << k + 1 << ". " ;
        cin>>task2[k];
        if (task2[k] == "done") break;
        k++;
    }
   
while (listno!=0){
        while (true) {
        
        cout << "Select the list you want to make changes with:" << endl
             << "1 for Pre-Departure Checklist" <<endl << "2 for Places to visit" <<endl << "3 for Food to eat" << endl << "0 for no changes"<< endl << "Enter: ";
        cin >> listno;
        if (listno == 0 || listno == 1 || listno == 2 || listno == 3) {
            break;
        } else {
            cout << "Invalid Choice" << endl;
        }
         }
    if (listno!=0){
    cout << "What do you want to change: " << endl << "1 for marking as complete" << endl << "2 for removing"<<endl << "3 for editing" <<endl << "4 for adding something to list" << endl << "5 for viewing the updated list "<< endl << "Enter: ";
    cin>> changeno;
    }



//changes for list 1
    if (listno==1){
        
        
    if (changeno==1){
        travelmarkcomp(task,ind);   
    }
    else if (changeno==2){
        
    
        travelremove(task,ind,i);
        i--;
    
        
    
    
        
    }
    else if (changeno==3){
        traveledit(task,ind,i);
    }
        else if (changeno==4){
            traveladd(task,ind,i);
            i++;
        }
        else  if (changeno==5){
            travelview(task,ind,i);
        }
        
}
//changes for list 2
else if (listno==2){
    if (changeno==1){
        travelmarkcomp(task1,ind);  
    }
    else if (changeno==2){
        
        travelremove(task1,ind,j);
        j--;
    
        
        
    }
    else if (changeno==3){
        traveledit(task1,ind,j);
    }
        else if (changeno==4){
            traveladd(task1,ind,j);
            j++;
        }
        else  if (changeno==5){
            travelview(task1,ind,j);
        }
        
}
//changes for list 3
else if (listno==3){
    if (changeno==1){
        travelmarkcomp(task2,ind);  
    }
    else if (changeno==2){
        
        travelremove(task2,ind,k);
        k--;
    
        
        
    }
    else if (changeno==3){
        traveledit(task2,ind,k);
    }
        else if (changeno==4){
            traveladd(task2,ind,k);
            k++;
        }
        else  if (changeno==5){
            travelview(task2,ind,k);
        }
        
}
}
cout << "Your full plan: " << endl ;
cout << "Destination: " << des << endl;
cout << "Departure date and time: " << dep <<setw(50) << " Arrival date and time: " << arrival << endl;
cout << "Pre-Departure Checklist: " << endl;
for (int o = 0 ; o<i ; o++){
    cout << o+1 << ". " << task[o] << endl;
}
cout << "Places to visit: " << endl;
for (int o = 0 ; o<j; o++){
    cout << o+1 << ". " << task1[o] << endl;
}
cout << "Food to eat: " << endl;
for (int o = 0 ; o<k ; o++){
    cout << o+1 << ". " << task2[o] << endl;
}

cout << setw(50)<<"Have a Good Trip!!" << endl;
    
}

