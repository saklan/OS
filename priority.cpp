#include<bits/stdc++.h>

using namespace std;

struct Process {
    int id;
    int att, bt, priority;
    int ct, tat, wt, res;
    bool is_completed = false;
};


struct ComparePriority {
    bool operator()(Process* const& p1, Process* const& p2) {

        if (p1->priority == p2->priority) {
            return p1->att < p2->att;
        }

        return p1->priority > p2->priority;

    }
};

int main() {
    int n;
    cout << "Enter n: ";
    if (!(cin >> n)) return 0;

    Process p[n];


    cout << "Enter all " << n << " process arrival times: ";
    for (int i = 0; i < n; i++) {
        p[i].id = i + 1;
        cin >> p[i].att;
    }

    cout << "Enter all " << n << " process burst times: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i].bt;
    }

    cout << "Enter all " << n << " process priorities: ";
    for (int i = 0; i < n; i++) {
        cin >> p[i].priority;
    }

    priority_queue<Process*, vector<Process*>, ComparePriority> pq;
    vector<pair<int, int>> gantt;
    int time = 0, completed = 0;

    cout << "\n--- Execution Steps ---\n";

    while (completed < n) {

        for (int i = 0; i < n; i++) {
            if (p[i].att <= time && !p[i].is_completed) {

                bool already_in = false;

            }
        }

        for (int i = 0; i < n; i++) {
            if (p[i].att <= time && !p[i].is_completed) {
                static bool in_ready[100] = {false};
                if(!in_ready[i]){
                    pq.push(&p[i]);
                    in_ready[i] = true;
                }
            }
        }

        if (pq.empty()) {
            time++;
            continue;
        }

        Process* current = pq.top();
        pq.pop();

        current->res = time - current->att;
        time += current->bt;
        current->ct = time;
        current->tat = current->ct - current->att;
        current->wt = current->tat - current->bt;
        current->is_completed = true;
        completed++;

        gantt.push_back({current->id, time});

        cout << "Time: " << time - current->bt << " to " << time
             << " | P" << current->id << " (Priority: " << current->priority << ")\n";
    }


    cout << "\nPID\tATT\tBT\tPRI\tCT\tTAT\tWT\n";
    float total_wt = 0, total_tat = 0;
    for (int i = 0; i < n; i++) {
        cout << p[i].id << "\t" << p[i].att << "\t" << p[i].bt << "\t"
             << p[i].priority << "\t" << p[i].ct << "\t" << p[i].tat << "\t" << p[i].wt << endl;
        total_wt += p[i].wt;
        total_tat += p[i].tat;
    }

    cout << fixed << setprecision(2);
    cout << "\nAverage Waiting Time: " << total_wt / n;
    cout << "\nAverage Turnaround Time: " << total_tat / n << endl;

    return 0;
}
