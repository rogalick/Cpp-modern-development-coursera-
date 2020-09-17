#include <iostream>
#include <vector>
#include <map>
#include <utility>
// ���������� ����� TeamTasks, ����������� ������� ���������� �� �������� ����� ������� �������������
using namespace std;
// ������������ ��� ��� ������� ������
//enum class TaskStatus {
//    NEW,          // �����
//    IN_PROGRESS,  // � ����������
//    TESTING,      // �� ������������
//    DONE          // ���������
//};

// ��������� ���-������� ��� map<TaskStatus, int>,
// ������������ ������� ���������� ����� ������� �������
//using TasksInfo = map<TaskStatus, int>;

class TeamTasks {
    map <string, TasksInfo> team_tasks;
public:
    // �������� ���������� �� �������� ����� ����������� ������������
    const TasksInfo& GetPersonTasksInfo(const string& person) const {
        return team_tasks.at(person);
    }

    // �������� ����� ������ (� ������� NEW) ��� ����������� �������������
    void AddNewTask(const string& person) {
        ++team_tasks[person][TaskStatus::NEW];
    }

    // �������� ������� �� ������� ���������� ����� ����������� ������������,
    // ����������� ��. ����
    tuple<TasksInfo, TasksInfo> PerformPersonTasks(
        const string& person, int task_count) {
        TasksInfo before_tasks, after_tasks, buffer;

        if (!team_tasks.count(person)) {
            return tie(after_tasks, before_tasks);
        }
        buffer = team_tasks.at(person);
        for (const auto& [key, value] : team_tasks[person]) {
            if (key != TaskStatus::DONE) {
                for (int i = 0; i < value; ++i) {
                    auto possition = static_cast<int>(key) + 1;
                    if (task_count) {
                        --buffer[key];
                        if (buffer[key] == 0) {
                            buffer.erase(key);
                        }
                        ++buffer[static_cast<TaskStatus>(possition)];
                        ++after_tasks[static_cast<TaskStatus>(possition)];
                        task_count--;
                    }
                    else {
                        ++before_tasks[key];
                    }
                }
            }
        }
        team_tasks.at(person) = buffer;
        return make_tuple(after_tasks, before_tasks);
    }
};

void PrintTasksInfo(TasksInfo tasks_info) {
    cout << tasks_info[TaskStatus::NEW] << " new tasks" <<
        ", " << tasks_info[TaskStatus::IN_PROGRESS] << " tasks in progress" <<
        ", " << tasks_info[TaskStatus::TESTING] << " tasks are being tested" <<
        ", " << tasks_info[TaskStatus::DONE] << " tasks are done" << endl;
}


//int main() {
//    TeamTasks tasks;
//   // tasks.AddNewTask("Ilia");
//    for (int i = 0; i < 3; ++i) {
//        tasks.AddNewTask("Ivan");
//    }
//    cout << "Ilia's tasks: ";
//   // PrintTasksInfo(tasks.GetPersonTasksInfo("Ilia"));
//    cout << "Ivan's tasks: ";
//    PrintTasksInfo(tasks.GetPersonTasksInfo("Ivan"));
//
//    TasksInfo updated_tasks, untouched_tasks;
//
//    tie(updated_tasks, untouched_tasks) =
//        tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    tie(updated_tasks, untouched_tasks) =
//        tasks.PerformPersonTasks("Ivan", 2);
//    cout << "Updated Ivan's tasks: ";
//    PrintTasksInfo(updated_tasks);
//    cout << "Untouched Ivan's tasks: ";
//    PrintTasksInfo(untouched_tasks);
//
//    return 0;
//}