#include <bits/stdc++.h>

using namespace std;

struct Trade {
    long long timestamp;
    string symbol;
    double price;
    int volume;
};

bool compareByTimestamp(const Trade &a, const Trade &b) {
    return a.timestamp < b.timestamp;
}

bool compareBySymbol(const Trade &a, const Trade &b) {
    return a.symbol < b.symbol;
}

map<int, vector<Trade>> groupByVolume(const vector<Trade> &trades) {
    map<int, vector<Trade>> volumeGroups;
    for (const auto &trade : trades) {
        volumeGroups[trade.volume].push_back(trade);
    }
    return volumeGroups;
}

int main() {
    vector<Trade> trades = {
        {1620045601, "AAPL", 135.67, 100},
        {1620045603, "MSFT", 250.12, 200},
        {1620045602, "AAPL", 136.12, 150},
        {1620045604, "GOOG", 2345.34, 100},
        {1620045600, "MSFT", 249.99, 300}
    };

    sort(trades.begin(), trades.end(), compareByTimestamp);
    cout << "Sorted by Timestamp:" << endl;
    for (const auto &trade : trades) {
        cout << trade.timestamp << " " << trade.symbol << " " << trade.price << " " << trade.volume << endl;
    }

    sort(trades.begin(), trades.end(), compareBySymbol);
    cout << "\nSorted by Symbol:" << endl;
    for (const auto &trade : trades) {
        cout << trade.timestamp << " " << trade.symbol << " " << trade.price << " " << trade.volume << endl;
    }

    map<int, vector<Trade>> groupedTrades = groupByVolume(trades);
    cout << "\nGrouped by Volume:" << endl;
    for (const auto &[volume, group] : groupedTrades) {
        cout << "Volume: " << volume << endl;
        for (const auto &trade : group) {
            cout << trade.timestamp << " " << trade.symbol << " " << trade.price << " " << trade.volume << endl;
        }
    }

    return 0;
}
