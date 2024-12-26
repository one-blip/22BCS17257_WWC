#include <bits/stdc++.h>

using namespace std;

struct CatalogItem {
    string title;
    int totalViews;
    double userRating;
    int releaseYear;
};

bool compareByTrending(const CatalogItem &a, const CatalogItem &b) {
    double scoreA = a.totalViews * 0.7 + a.userRating * 0.3 - (2024 - a.releaseYear) * 0.1;
    double scoreB = b.totalViews * 0.7 + b.userRating * 0.3 - (2024 - b.releaseYear) * 0.1;
    return scoreA > scoreB;
}

bool compareByRelevance(const CatalogItem &a, const CatalogItem &b, const vector<string> &userHistory) {
    auto itA = find(userHistory.begin(), userHistory.end(), a.title);
    auto itB = find(userHistory.begin(), userHistory.end(), b.title);
    return (itA != userHistory.end() && itB == userHistory.end()) || (itA != userHistory.end() && itB != userHistory.end() && itA < itB);
}

int main() {
    vector<CatalogItem> catalog = {
        {"Movie A", 100000, 8.5, 2022},
        {"Show B", 200000, 9.0, 2021},
        {"Movie C", 150000, 7.5, 2023},
        {"Show D", 50000, 8.0, 2020},
        {"Movie E", 300000, 9.5, 2022}
    };

    sort(catalog.begin(), catalog.end(), compareByTrending);
    cout << "Sorted by Trending:" << endl;
    for (const auto &item : catalog) {
        cout << item.title << " " << item.totalViews << " " << item.userRating << " " << item.releaseYear << endl;
    }

    vector<string> userHistory = {"Movie C", "Show D"};
    sort(catalog.begin(), catalog.end(), [&userHistory](const CatalogItem &a, const CatalogItem &b) {
        return compareByRelevance(a, b, userHistory);
    });
    cout << "\nSorted by Relevance:" << endl;
    for (const auto &item : catalog) {
        cout << item.title << " " << item.totalViews << " " << item.userRating << " " << item.releaseYear << endl;
    }

    return 0;
}
