// You are given an array of non-overlapping intervals intervals where intervals[i] = [starti, endi] represent the start
// and the end of the ith interval and intervals is sorted in ascending order by starti. You are also given an interval
// newInterval = [start, end] that represents the start and end of another interval.
// Insert newInterval into intervals such that intervals is still sorted in ascending order by starti and intervals
// still does not have any overlapping intervals (merge overlapping intervals if necessary).
// Return intervals after the insertion.
// Note that you don't need to modify intervals in-place. You can make a new array and return it.
// Link: https://leetcode.com/problems/two-sum/description/

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> insertInterval(vector<vector<int>>& intervals, vector<int>& newInterval) {
    vector<vector<int>> result;

    for (auto &interval: intervals) {
        // Trường hợp 1: interval nằm hoàn toàn bên trái newInterval (không chồng lấn)
        if (interval[1] < newInterval[0]) {
            result.push_back(interval);

            continue;
        }

        // Trường hợp 2: interval nằm hoàn toàn bên phải newInterval (không chồng lấn)
        if (interval[0] > newInterval[1]) {
            // Trước khi thêm interval bên phải, ta thêm newInterval đã xử lý xong
            result.push_back(newInterval);
            // Gán interval hiện tại làm newInterval mới để xử lý tiếp
            newInterval = interval;

            continue;
        }

        // Trường hợp 3: chồng lấn -> gộp lại
        newInterval[0] = min(newInterval[0], interval[0]);
        newInterval[1] = max(newInterval[1], interval[1]);
    }
    result.push_back(newInterval);

    return result;
}

void initArray(vector<vector<int>> &intervals, vector<int> &newInterval, int &n) {
    cout << "Nhap so luong interval: ";
    cin >> n;

    intervals.resize(n, vector<int>(2));
    cout << "Nhap cac interval (vi du: 2 5): " << endl;
    for (int i = 0; i < n; i++) {
        cin >> intervals[i][0] >> intervals[i][1];
    }

    newInterval.resize(2);
    cout << "Nhap newInterval (start end): ";
    cin >> newInterval[0] >> newInterval[1];
}

void printArray(const vector<vector<int>> &arr) {
    cout << "Ket qua sau khi chen: ";
    for (auto& interval : arr) {
        cout << "[" << interval[0] << "," << interval[1] << "] ";
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
    int n;
    vector<vector<int>> intervals;
    vector<int> newInterval;

    initArray(intervals, newInterval, n);

    const vector<vector<int>> res = insertInterval(intervals, newInterval);
    printArray(res);
}
