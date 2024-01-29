#include <iostream>
#include <string>
using namespace std;


struct STtime
{
    int day;
    int month;
    int year;
};
struct STtask
{
    string TaskName;
    string Description;
    STtime TaskTimeStart;
    STtime TaskTimeEnd;
    int Importance_Counter = 0;
};
struct STCopy
{
    int counterCopy;
    STtask* ArrayCopy;
};

STCopy Add_Task(int TaskNumber)
{
    STtask* ptr = new STtask[TaskNumber];
    int counter = 0;
    STCopy COPY;

    for (int i = 0; i < TaskNumber;i++)
    {
        cout << "Name Your Task \a\n";
        cin >> ptr[i].TaskName;
        cout << "Enter the Descreption \n";
        cin >> ptr[i].Description;
        cout << "Enter the TaskTimeStart : dd/mm/yyyy \a\n";
        cin >> ptr[i].TaskTimeStart.day;
        cin >> ptr[i].TaskTimeStart.month;
        cin >> ptr[i].TaskTimeStart.year;
        cout << "Enter the TaskTimeEnd : dd/mm/yyyy \a\n";
        cin >> ptr[i].TaskTimeEnd.day;
        cin >> ptr[i].TaskTimeEnd.month;
        cin >> ptr[i].TaskTimeEnd.year;
        cout << "Enter the Importance \"LOW = 1\" Or \"MEDIUM = 2\" Or \"HIGH = 3\" \n";
        cin >> ptr[i].Importance_Counter;
        counter++;

    }
    COPY.counterCopy = counter;
    COPY.ArrayCopy = ptr;
    return COPY;
}


void Display(STCopy copy)
{
    for (int i = 0; i < copy.counterCopy;i++)
    {
        cout << "Task " << i + 1 << " Name: " << copy.ArrayCopy[i].TaskName << endl;
        cout << "Task " << i + 1 << " Description: " << copy.ArrayCopy[i].Description << endl;
        cout << "Task " << i + 1 << " Start Date: " << copy.ArrayCopy[i].TaskTimeStart.day << "/"
            << copy.ArrayCopy[i].TaskTimeStart.month << "/" << copy.ArrayCopy[i].TaskTimeStart.year << endl;
        cout << "Task " << i + 1 << " End Date: " << copy.ArrayCopy[i].TaskTimeEnd.day << "/"
            << copy.ArrayCopy[i].TaskTimeEnd.month << "/" << copy.ArrayCopy[i].TaskTimeEnd.year << endl;
        cout << "Task " << i + 1 << " Importance: " << copy.ArrayCopy[i].Importance_Counter << endl;

    }


}


void Filter(STCopy copy, int number)
{
    switch (number)
    {
    case 1:
        for (size_t i = 0;i < copy.counterCopy;i++)
        {
            if (copy.ArrayCopy[i].Importance_Counter == 1)
            {
                cout << "task " << copy.ArrayCopy[i].TaskName << "\n";
            }
        }
        break;

    case 2:
        for (size_t i = 0;i < copy.counterCopy;i++)
        {
            if (copy.ArrayCopy[i].Importance_Counter == 2)
            {
                cout << "task " << copy.ArrayCopy[i].TaskName << "\n";
            }
        }
        break;
    case 3:
        for (size_t i = 0;i < copy.counterCopy;i++)
        {
            if (copy.ArrayCopy[i].Importance_Counter == 3)
            {
                cout << "task " << copy.ArrayCopy[i].TaskName << "\n";
            }
        }
        break;
    default:
        cout << "No task with this Importance \n";
    }
}


void Delete(STCopy copy, string name)
{
    for (size_t i = 0; i < copy.counterCopy; i++)
    {
        if (copy.ArrayCopy[i].TaskName == name)
        {
            // Shift all subsequent tasks one position back
            for (size_t j = i; j < copy.counterCopy - 1; j++)
            {
                copy.ArrayCopy[j] = copy.ArrayCopy[j + 1];
            }
            copy.counterCopy--;
            break;
        }
    }
}





int main()
{
    STCopy taskList;
    int choice;

    // Move the string name declaration outside the switch block
    string name;

    do {
        cout << "\n|||||||||||||||||| Menu: ||||||||||||||||||" << endl;
        cout << "===================================\n\a";
        cout << "1. Add a Task   \n";
        cout << "===================================\n\a";
        cout << "2. Display the tasks \n";
        cout << "===================================\n\a";
        cout << "3. Filter the tasks \n";
        cout << "===================================\n\a";
        cout << "4. Delete a task \n";
        cout << "===================================\n\a";
        cout << "5. Quit \n";
        cout << "===================================\n\a";
        cout << "Enter your \"choice\": ";
        cin >> choice;

        switch (choice) {
        case 1:
            int TaskNumber;
            cout << "How Many Task Do You Want To Add \a\n";
            cin >> TaskNumber;
            taskList = Add_Task(TaskNumber);
            break;
        case 2:
            Display(taskList);
            break;
        case 3:
            cout << "What level do you want to search for\n";
            cout << "\"LOW = 1\" Or \"MEDIUM = 2\" Or \"HIGH = 3\" \n";
            int Index;
            cin >> Index;
            cout << "the filter result is : \n";
            Filter(taskList, Index);
            break;
        case 4:
            cout << "Enter a task name to delete it \n";
            cin >> name;  // Move the input inside the case block
            Delete(taskList, name);
            Display(taskList);
            break;
        case 5:
            cout << "Program terminated.\n";
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }

    } while (choice != 5);

    delete[] taskList.ArrayCopy;
    system("pause");
}