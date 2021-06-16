#include <cstdio>
using namespace std;
int main() {

    int x;

    while(scanf("%d",&x)!=EOF) {
		if(!(x % 27)){
			printf("sad\n");
		} else if(!(x % 9)){
			printf("happy\n");
		} else if(!(x % 3)){
			printf("sad\n");
		} else {
			printf("happy\n");
		}
      // 主要程式內容 ...

    }

  }
