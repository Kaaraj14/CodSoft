#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Task
{
public:
    string description;
    bool completed;
Task(const string& description) {
        this->description = description;
        completed = false;
    }

    
};

class ToDoListManager
{
public:
    void add_task(const string &description)
    {
        tasks.push_back(Task(description));
        cout << "Task '" << description << "' added." << endl;
    }

    void view_tasks()
    {
        if (tasks.empty())
        {
            cout << "No tasks in the list." << endl;
            return;
        }

        cout << "Tasks:" << endl;
        for (auto i = 0; i < tasks.size(); ++i)
        {
            const Task &task = tasks[i];
            string status = task.completed ? "Completed" : "Pending";
            cout << i + 1 << ". [" << status << "] " << task.description << endl;
        }
    }

    void mark_completed(size_t task_index)
    {
        if (task_index >= 1 && task_index <= tasks.size())
        {
            Task &task = tasks[task_index - 1];
            if (!task.completed)
            {
                task.completed = true;
                cout << "Task '" << task.description << "' marked as completed." << endl;
            }
            else
            {
                cout << "Task is already completed." << endl;
            }
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

    void remove_task(size_t task_index)
    {
        if (task_index >= 1 && task_index <= tasks.size())
        {
            Task removedTask = tasks[task_index - 1];
            tasks.erase(tasks.begin() + task_index - 1);
            cout << "Task '" << removedTask.description << "' removed." << endl;
        }
        else
        {
            cout << "Invalid task index." << endl;
        }
    }

private:
    vector<Task> tasks;
};

int main()
{
    ToDoListManager manager;

    while (true)
    {
        cout << "Options:" << endl;
        cout << "1. Add Task" << endl;
        cout << "2. View Tasks" << endl;
        cout << "3. Mark Task as Completed" << endl;
        cout << "4. Remove Task" << endl;
        cout << "5. Exit" << endl;

        int choice;
        cin >> choice;

        if (choice == 1)
        {
            cout << "Enter task description: ";
            string description;
            cin >> description;
            manager.add_task(description);
        }
        else if (choice == 2)
        {
            manager.view_tasks();
        }
        else if (choice == 3)
        {
            size_t task_index;
            cout << "Enter task index: ";
            cin >> task_index;
            manager.mark_completed(task_index);
        }
        else if (choice == 4)
        {
            size_t task_index;
            cout << "Enter task index: ";
            cin >> task_index;
            manager.remove_task(task_index);
        }
        else if (choice == 5)
        {
            break;
        }
        else
        {
            cout << "Invalid choice." << endl;
        }
    }

    return 0;
}
