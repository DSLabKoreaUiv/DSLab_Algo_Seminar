#include <stdio.h>

int N,M,X,D,R,C[55][55],S[55];
double P[111][55];

int main()
{
	//freopen("input.txt", "r", stdin);


	int test_num,i,j,d;

	scanf ("%d",&test_num); 
	while (test_num--)
	{
		//N : ���� ��
		//D : ���� �� ��
		//R : �����Ұ� �ִ� ������ ��ȣ
		scanf ("%d %d %d",&N,&D,&R);
		
		for (i=0;i<N;i++) S[i] = 0;
		
		for (i=0;i<N;i++) 
			for (j=0;j<N;j++) {
				
				// C[] �����ִ� �� �迭 �Է�
				scanf ("%d",&C[i][j]);

				// S[] �� ���������� Ȯ��
				S[i] += C[i][j];
			}

		
		//�� ���� �ʱ�ȭ = 0 , ������ =1
		
			for (i=0;i<N;i++) 
				P[0][i] = 0;
			P[0][R] = 1;
		
		// for �����ϼ�, for ���� ��
		for (d=1;d<=D;d++){
			for (i=0;i<N;i++) 
				P[d][i] = 0;
			
			for (i=0;i<N;i++)
				for (j=0;j<N;j++)
					// ������ ������ִ� Ȯ���� Ȯ���� ����
					if (C[i][j])
						P[d][j] += P[d-1][i] / S[i];
		}

		// M ����� ���� ��
		scanf ("%d",&M);

		// ����� ������ȣ �Է� �� ���
		for (i=0;i<M;i++){
			scanf ("%d",&X);
			printf ("%.9lf ",P[D][X]);
		}
		printf ("\n");
	}

	return 0;
}
