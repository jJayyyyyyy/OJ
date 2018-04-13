#include <cstdio>
#include <cmath>
#include <algorithm>
using namespace std;

int cmp(int a, int b){
  return a>b;
}

int getRowCol(const int N, int &m, int &n){
  for( int i=sqrt(N); i>0; i-- ){
    if( N%i==0 ){
      n = i;
      m = N/i;
      break;
    }
  }

  return 0;
}

int main(){
  int N=0, k;

  scanf("%d", &N);
  int *num = new int[N];
  for( k=0; k<N; k++ )
    scanf("%d", &num[k]);

  sort(num, num+N, cmp);

  int m, n;
  getRowCol(N, m, n);

  int **v = new int*[m];
  for( k=0; k<m; k++ )
    v[k] = new int[n]();

  int right=n-1, left=0, down=m-1, up=0, i=0, j=0;
  int isOver=0, cnt=0;

  if( N==1 ){
    printf("%d\n", num[0]);
  }else{
    while(1){
      while( i<right ){
        v[j][i++] = num[cnt++];
        if(cnt==N){
          isOver=1;
          break;
        }
      }
      if(isOver)
        break;

      while( j<down ){
        v[j++][i] = num[cnt++];
        if(cnt==N){
          isOver=1;
          break;
        }
      }
      if(isOver)
        break;

      while( i>left ){
        v[j][i--] = num[cnt++];
        if(cnt==N){
          isOver=1;
          break;
        }
      }
      if(isOver)
        break;

      while( j>up ){
        v[j--][i] = num[cnt++];
        if(cnt==N){
          isOver=1;
          break;
        }
      }
      if(isOver)
        break;

      right--;
      down--;
      left++;
      up++;
      j++;
      i++;
      if(right==left && up==down){
        v[j][i] = num[cnt++];
        break;
      }
    }

    for( i=0; i<m; i++ ){
      int isFirst = 1;
      for( j=0; j<n; j++ ){
        if( isFirst ){
          printf("%d", v[i][j]);
          isFirst = 0;
        }else{
          printf(" %d", v[i][j]);
        }
      }
      printf("\n");
    }
  }



  delete []num;
  for( k=0; k<m; k++ ){
    delete [] v[k];
  }
  delete []v;
  return 0;
}