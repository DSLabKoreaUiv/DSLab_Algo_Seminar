#include <iostream>

using namespace std;

const int EMPTY = -987654321;
int n, board[50];
int cache[50][50];

int play(int left, int right)
{
	//���� ���: ��� ���� �� �������� ��
	if(left>right) return 0;
	int& ret = cache[left][right];
	if(ret != EMPTY) return ret;

	//���� �������� ���
	ret = max(board[left] - play(left +1, right),
		board[right] - play(left, right -1));

	//���� ���ִ� ���
	if(right - left +1 >=2){

		ret = max(ret, -play(left +2, right));
		ret = max(ret, -play(left, right -2));
	
	}

	return ret;
}

int main()
{
	int c;
	cin>>c;

	while(c--){
	int n;
	cin>>n;

	int i;
	for(i=0; i<n; i++)
		cin>>board[i];
	for(int i = 0; i<n; i++)
		for(int j = 0; j<n; j++)
			cache[i][j] = EMPTY;

	cout<<play(0, n-1)<<endl;

	}
	
}