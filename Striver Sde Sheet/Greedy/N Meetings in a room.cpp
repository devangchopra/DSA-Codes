#include <bits/stdc++.h>

struct obj {
  int start;
  int finish;
};
static bool comp(obj a, obj b) {
  return a.finish < b.finish;
}
int maximumActivities(vector<int> &start, vector<int> &finish) {
  // Write your code here.
  int n = start.size();
  obj arr[n];
  for (int i = 0; i < n; i++) {
    arr[i].start = start[i];
    arr[i].finish = finish[i];
  }
  sort(arr, arr + n, comp);
  int ans = 1;
  int end = arr[0].finish;
  for (int i = 1; i < n; i++)
  {
    if (arr[i].start >= end)
    {
      end = arr[i].finish;
      ans++;
    }
  }
  return ans;
}