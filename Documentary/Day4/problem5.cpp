#include <bits/stdc++.h>

using namespace std;

struct Ad {
    string advertiser;
    double bidAmount;
    double engagementRate;
    double remainingBudget;
};

struct CompareAds {
    bool operator()(const Ad &a, const Ad &b) {
        if (a.bidAmount != b.bidAmount) return a.bidAmount < b.bidAmount;
        if (a.engagementRate != b.engagementRate) return a.engagementRate < b.engagementRate;
        return a.remainingBudget < b.remainingBudget;
    }
};

int main() {
    priority_queue<Ad, vector<Ad>, CompareAds> adQueue;

    adQueue.push({"Advertiser A", 5.0, 0.8, 1000.0});
    adQueue.push({"Advertiser B", 6.0, 0.7, 800.0});
    adQueue.push({"Advertiser C", 5.5, 0.9, 900.0});
    adQueue.push({"Advertiser D", 6.0, 0.85, 700.0});
    adQueue.push({"Advertiser E", 4.5, 0.75, 1200.0});

    cout << "Ads sorted by priority:" << endl;
    while (!adQueue.empty()) {
        const auto &ad = adQueue.top();
        cout << "Advertiser: " << ad.advertiser << ", Bid: " << ad.bidAmount
             << ", Engagement: " << ad.engagementRate << ", Budget: " << ad.remainingBudget << endl;
        adQueue.pop();
    }

    return 0;
}
