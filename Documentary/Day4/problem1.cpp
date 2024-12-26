#include <bits/stdc++.h>

using namespace std;

struct Transaction {
    int id;
    double score;
};

bool compareTransactions(const Transaction &a, const Transaction &b) {
    return a.score > b.score;
}

vector<Transaction> getTopKTransactions(vector<Transaction> &transactions, int k) {
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> minHeap;
    for (const auto &t : transactions) {
        minHeap.emplace(t.score, t.id);
        if (minHeap.size() > k) minHeap.pop();
    }
    vector<Transaction> topK;
    while (!minHeap.empty()) {
        topK.push_back({minHeap.top().second, minHeap.top().first});
        minHeap.pop();
    }
    reverse(topK.begin(), topK.end());
    return topK;
}

int main() {
    vector<Transaction> transactions = {
        {1, 85.6}, {2, 90.2}, {3, 76.4}, {4, 99.1}, {5, 80.0}, {6, 89.5}, {7, 92.3}
    };
    sort(transactions.begin(), transactions.end(), compareTransactions);
    for (const auto &t : transactions) {
        cout << "ID: " << t.id << ", Score: " << t.score << endl;
    }
    int k = 3;
    vector<Transaction> topK = getTopKTransactions(transactions, k);
    cout << "Top " << k << " Transactions:" << endl;
    for (const auto &t : topK) {
        cout << "ID: " << t.id << ", Score: " << t.score << endl;
    }
    return 0;
}
