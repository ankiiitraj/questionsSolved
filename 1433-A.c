#include<stdio.h>

int main(){
	int t;
	scanf("%d", &t);
	while(t--){
		int n;
		bool arr[n];
		scanf("%d", &n);
		for(int i = 0; i < n; ++i){
			scanf("%d", &arr[i]);
		}
		int lest_one = -1, res = 0;
		for(int i = 0; i < n; ++i){
			if(a[i] == 0 and last_one != -1){
				int j = i;
				while(!a[j] and j < n){
					++j;
				}
				if(j < n and a[j])
					gaps += j - i;
				i = j -1;
			}else if(a[i]){
				prev = i;
			}
		}

		printf("%d\n", res);
	}
}