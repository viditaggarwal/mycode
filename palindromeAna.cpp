#include<iostream>
#include<stdlib.h>
using namespace std;

//int calcArea(int K, int L, int M, int N){
//	int l = abs(M - K);
//	int w = abs(N - L);
//	return l*w;
//}
//
//int check(int K, int L, int M, int N, int P, int Q, int R, int S) {
//	if((K==P && M == R)&&(L==Q && N==S)){
//		return calcArea(P,Q,R,S);	
//	}
//	if((K<P && M > R)&&(L<Q&&N>S)){
//		return calcArea(P,Q,R,S);	
//	}
//	if((K<P && M < R)&&(L>Q&&N>S)){
//		return calcArea(P, L, M, S);
//	}
//	if((K<P && M < R)&&(L<Q && N<S)){
//		return calcArea(P, Q, M, N);
//	}
//	if((K>P && M > R)&&(L>Q && N>S)){
//		return calcArea(K,L,R,S);
//	}
//	if((K>P && M > R)&&(L<Q && N<S)){
//		return calcArea(K,Q,R,N);
//	}
//	return 0;
//}
//
//int solution(int K, int L, int M, int N, int P, int Q, int R, int S) {
//	int A1 = calcArea(K,L,M,N);
//	int A2 = calcArea(P,Q,R,S);
//	int A3 = check(K,L,M,N,P,Q,R,S);
//	return A1+A2-A3;
//}

int solution(int M, int N) {if(M > N)return -1;
	int prod = M;
	M++;	
	while(M <= N){
		prod = prod & M++;
	}
	return prod;// write your code in C++98
}

int main(){
	//cout<<solution(-4,1,2,6,0,-1,4,3);
	
	cout<<solution(1025,2046);
	return 0;
}
