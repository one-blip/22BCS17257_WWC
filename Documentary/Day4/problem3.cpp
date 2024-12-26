#include <bits/stdc++.h>

using namespace std;

struct Patient {
    string name;
    int triagePriority;
    int severity;
    long long arrivalTime;
};

struct ComparePatients {
    bool operator()(const Patient &a, const Patient &b) {
        if (a.triagePriority != b.triagePriority) return a.triagePriority < b.triagePriority;
        if (a.severity != b.severity) return a.severity < b.severity;
        return a.arrivalTime > b.arrivalTime;
    }
};

int main() {
    priority_queue<Patient, vector<Patient>, ComparePatients> emergencyQueue;

    emergencyQueue.push({"John Doe", 1, 5, 1620045601});
    emergencyQueue.push({"Jane Smith", 2, 4, 1620045602});
    emergencyQueue.push({"Alice Brown", 1, 6, 1620045603});
    emergencyQueue.push({"Bob Johnson", 3, 3, 1620045604});
    emergencyQueue.push({"Eve Davis", 2, 5, 1620045605});

    cout << "Patients sorted by priority:" << endl;
    while (!emergencyQueue.empty()) {
        const auto &patient = emergencyQueue.top();
        cout << "Name: " << patient.name << ", Triage: " << patient.triagePriority
             << ", Severity: " << patient.severity << ", Arrival: " << patient.arrivalTime << endl;
        emergencyQueue.pop();
    }

    return 0;
}
