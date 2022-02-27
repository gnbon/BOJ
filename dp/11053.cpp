#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int N, vector<int> A) {
	int answer = 0;
	int dp[1001];
	
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		int dp_max = 0;
		
		for (int j = 0; j < i; j++) {
			if (A[i] > A[j]) {
				if (dp_max < dp[j])
					dp_max = dp[j];
			}
		}
		dp[i] = dp_max + 1;
		answer = max(answer, dp[i]);
	}
	
	return answer;
}

int main(void)
{
	int N;
	cin >> N;
	vector<int> A(N, 1);
		
	cout << solution(N, A);
}