#include <stdio.h>
#include <string.h>

#define MAX_TASKS 100
#define DESCRIPTION_LENGTH 50
#define DEADLINE_LENGTH 20

struct Task {
    char description[DESCRIPTION_LENGTH];
    char deadline[DEADLINE_LENGTH];
    int priority;
};

void addTask(struct Task tasks[], int *taskCount);
void displayTasks(const struct Task tasks[], int taskCount);
void modifyTask(struct Task tasks[], int taskCount);
void deleteTask(struct Task tasks[], int *taskCount);
void orderTasks(struct Task tasks[], int taskCount);
void filterTasks(const struct Task tasks[], int taskCount);

int main() {
    struct Task tasks[MAX_TASKS];
    int taskCount = 0;

    while (1) {
        // Display menu
        printf("\n----- OneHand Task Management System -----\n");
        printf("1. Add a Task\n");
        printf("2. Display Tasks\n");
        printf("3. Modify a Task\n");
        printf("4. Delete a Task\n");
        printf("5. Order Tasks\n");
        printf("6. Filter Tasks\n");
        printf("0. Exit\n");
        printf("-----------------------------------------\n");

        // User choice
        int choice;
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addTask(tasks, &taskCount);
                break;
            case 2:
                displayTasks(tasks, taskCount);
                break;
            case 3:
                modifyTask(tasks, taskCount);
                break;
            case 4:
                deleteTask(tasks, &taskCount);
                break;
            case 5:
                orderTasks(tasks, taskCount);
                break;
            case 6:
                filterTasks(tasks, taskCount);
                break;
            case 0:
                printf("Exiting the application. Goodbye!\n");
                return 0;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}

// Function to add a new task
void addTask(struct Task tasks[], int *taskCount) {
    if (*taskCount < MAX_TASKS) {
        struct Task newTask;
        printf("Enter task description: ");
        scanf("%s", newTask.description);
        printf("Enter task deadline: ");
        scanf("%s", newTask.deadline);
        printf("Enter task priority (1-10): ");
        scanf("%d", &newTask.priority);

        tasks[(*taskCount)++] = newTask;
        printf("Task added successfully!\n");
    } else {
        printf("Cannot add more tasks. Maximum limit reached.\n");
    }
}

// Function to display all tasks
void displayTasks(const struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available.\n");
    } else {
        printf("\n--- Task List ---\n");
        for (int i = 0; i < taskCount; ++i) {
            printf("Index: %d\n", i);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Priority: %d\n", tasks[i].priority);
            printf("-----------------\n");
        }
    }
}

// Function to modify an existing task
void modifyTask(struct Task tasks[], int taskCount) {
    if (taskCount == 0) {
        printf("No tasks available to modify.\n");
        return;
    }

    int index;
    printf("Enter the index of the task to modify: ");
    scanf("%d", &index);

    if (index < 0 || index >= taskCount) {
        printf("Invalid index. Please try again.\n");
    } else {
        struct Task *task = &tasks[index];
        printf("Enter new task description: ");
        scanf("%s", task->description);
        printf("Enter new task deadline: ");
        scanf("%s", task->deadline);
        printf("Enter new task priority (1-10): ");
        scanf("%d", &task->priority);

        printf("Task modified successfully!\n");
    }
}

// Function to delete an existing task
void deleteTask(struct Task tasks[], int *taskCount) {
    if (*taskCount == 0) {
        printf("No tasks available to delete.\n");
        return;
    }

    int index;
    printf("Enter the index of the task to delete: ");
    scanf("%d", &index);

    if (index < 0 || index >= *taskCount) {
        printf("Invalid index. Please try again.\n");
    } else {
        for (int i = index; i < *taskCount - 1; ++i) {
            tasks[i] = tasks[i + 1];
        }
        --(*taskCount);
        printf("Task deleted successfully!\n");
    }
}

// Function to order tasks by deadline using Bubble Sort
void orderTasks(struct Task tasks[], int taskCount) {
    for (int i = 0; i < taskCount - 1; ++i) {
        for (int j = 0; j < taskCount - i - 1; ++j) {
            // Compare tasks based on their deadline
            if (strcmp(tasks[j].deadline, tasks[j + 1].deadline) > 0) {
                // Swap tasks if they are in the wrong order
                struct Task temp = tasks[j];
                tasks[j] = tasks[j + 1];
                tasks[j + 1] = temp;
            }
        }
    }
    printf("Tasks ordered by deadline using Bubble Sort.\n");
}

// Function to filter tasks by priority
void filterTasks(const struct Task tasks[], int taskCount) {
    int filterPriority;
    printf("Enter the priority to filter tasks: ");
    scanf("%d", &filterPriority);

    printf("\n--- Filtered Task List ---\n");
    for (int i = 0; i < taskCount; ++i) {
        if (tasks[i].priority == filterPriority) {
            printf("Index: %d\n", i);
            printf("Description: %s\n", tasks[i].description);
            printf("Deadline: %s\n", tasks[i].deadline);
            printf("Priority: %d\n", tasks[i].priority);
            printf("-----------------\n");
        }
    }
}
