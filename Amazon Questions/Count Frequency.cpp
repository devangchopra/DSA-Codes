vector<int> findFrequency(string S) {
	// Write your code here.
	vector<int>freq(26, 0);
	for (auto& i : S) {
		freq[i - 'a']++;
	}
	return freq;
}