#include <stdio.h>

long long todec(int R, long long v[], long long b[]) {
  int i;
  long long d,k;
  d=0;
  k=1;
  for(i=0;i<R;i++) {
    d+=k*v[i];
    k*=b[i];
  }
  return d;
}

void tokul(int R, long long d, long long v[], long long b[]) {
  int i;
  for(i=0;i<R;i++) {
    v[i]=d%b[i];
    d/=b[i];
  }
}

int main() {
  long long v[20],h[20],b[20];
  int i,j,k,R;
  long long M,N;
  scanf("%d",&R);
  for(i=R-1;i>=0;i--) {
    scanf("%lld %lld",&v[i],&h[i]);
    b[i]=v[i]+h[i]+1;
  }
  scanf("%lld",&N); 
  M=todec(R,v,b);
  tokul(R,M+N,v,b);
  for(i=R-1;i>=0;i--) {
    printf("%lld %lld\n",v[i],b[i]-v[i]-1);
  }  
  return 0;
}
