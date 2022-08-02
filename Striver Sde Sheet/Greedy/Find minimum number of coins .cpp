int findMinimumCoins(int amount) {
  // Write your code here
  vector<int>arr = {1000, 500, 100, 50, 20, 10, 5, 2, 1};
  int index = -1;
  int ans = 0;
  while (amount != 0) {
    index++;
    if (arr[index] > amount) {
      continue;
    }
    else {
      int x = amount / arr[index];
      amount = amount - (arr[index] * x);
      ans += x;
    }
  }
  return ans;

}
