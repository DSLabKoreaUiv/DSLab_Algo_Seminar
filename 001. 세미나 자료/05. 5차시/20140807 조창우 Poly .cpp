#include <iostream>
#define FOR(a, b) for(int a=0; a<b; a++)
  
int cache[101][101];
const int MOD = 10*1000*1000;
using namespace std;

int poly(int n, int first) {
  if(n==first) return 1;                
  int& ret=cache[n][first];
  if(ret!=-1) return ret;
  ret=0;
  for(int second=1;second<=n-first;++second) { 
	  int add = second+first-1;   // ������ ���簢���� ���� ��� 
	  if(first==0) add=1;         // �ʱ���� first==0       
	  
	  add *= poly(n-first, second); 
	  add %=MOD;                  
	  ret +=add;
	  ret %=MOD;
  }
  return ret;
}

int main(void)
 {
#ifdef _WIN32    //cache �ʱ�ȭ 
  freopen("test.txt", "r", stdin);
  memset(cache, -1, sizeof(cache));
#else
  for (int ci = 0; ci < 101	; ci++)
    for (int cj = 0; cj < 101	; cj++)
      cache[ci][cj] = -1;
#endif

  int testcase;   
  cin>>testcase;                   //�½�Ʈ ���̽� �Է� 

  FOR(i, testcase) {  
	int n;
    cin>>n;                        //���簢�� �� �Է� 

	cout<<poly(n,0)<<endl;         
  }
  return 0;
 } 
