// Design a system in C++ that uses a linked list to simulate a real-time task scheduler for a multi-threaded operating system. Each node in the linked list represents a task, containing attributes like a unique task ID, task priority, estimated execution time, and a pointer to the next task. The linked list must dynamically adapt to new tasks being added, tasks completing, or tasks being pre-empted based on their priority. Implement functionality to insert tasks into the list in priority order (higher priority tasks come first), remove tasks upon completion, and dynamically reallocate execution slots if a higher priority task is added mid-execution. Additionally, the system should support a circular linked list to handle periodic tasks that need to re-enter the scheduling queue after a defined time interval. The implementation must ensure efficient memory usage and handle edge cases, such as managing tasks with the same priority, handling an empty task queue, and dealing with corrupted nodes. The program should output the current state of the task list, showing the order of execution and periodically updating it as tasks are added, completed, or preempted in real-time. This problem challenges your understanding of advanced linked list manipulation, dynamic memory management, and multi-threaded system simulation.

#include <iostream>
#include <string>
#include <thread>
#include <chrono>

struct Task {
    int id;
    int priority;
    int executionTime;
    int period;
    Task* next;

    Task(int id, int priority, int executionTime, int period = 0)
        : id(id), priority(priority), executionTime(executionTime), period(period), next(nullptr) {}
};

class TaskScheduler {
    Task* head;

public:
    TaskScheduler() : head(nullptr) {}

    void insertTask(int id, int priority, int executionTime, int period = 0) {
        Task* newTask = new Task(id, priority, executionTime, period);
        if (!head || priority > head->priority) {
            newTask->next = head;
            head = newTask;
        } else {
            Task* temp = head;
            while (temp->next && temp->next->priority >= priority)
                temp = temp->next;
            newTask->next = temp->next;
            temp->next = newTask;
        }
    }

    void executeTasks() {
        while (head) {
            Task* current = head;
            head = head->next;
            std::cout << "Executing Task ID: " << current->id << " with priority: " << current->priority << std::endl;
            std::this_thread::sleep_for(std::chrono::seconds(current->executionTime));

            if (current->period > 0) {
                insertTask(current->id, current->priority, current->executionTime, current->period);
                std::this_thread::sleep_for(std::chrono::seconds(current->period));
            } else {
                delete current;
            }
        }
    }

    void displayTasks() {
        Task* temp = head;
        std::cout << "Current Task Queue:\n";
        while (temp) {
            std::cout << "Task ID: " << temp->id << ", Priority: " << temp->priority << ", Execution Time: " << temp->executionTime << std::endl;
            temp = temp->next;
        }
    }

    ~TaskScheduler() {
        while (head) {
            Task* temp = head;
            head = head->next;
            delete temp;
        }
    }
};

int main() {
    TaskScheduler scheduler;

    scheduler.insertTask(1, 3, 2);
    scheduler.insertTask(2, 1, 1);
    scheduler.insertTask(3, 2, 3, 5);
    scheduler.insertTask(4, 4, 2);

    scheduler.displayTasks();

    std::thread executionThread(&TaskScheduler::executeTasks, &scheduler);
    executionThread.join();

    scheduler.displayTasks();

    return 0;
}
