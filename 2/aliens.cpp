#include <stdio.h> 
#include <algorithm>
using namespace std;
int solve(int n, int a[]) {
    int b[1005];
    int ret = 0xfffffff;
    int i, j, k;
    for(i = 0, j = n; i < n; i++, j++)
        a[j] = a[i];
    for(i = 0; i < n; i++) {
        int mark[505], cnt = 0;
        for(j = 0; j < n; j++) {
            mark[a[i+j]] = i+j;
            b[i+j] = a[i+j];
        }
        for(j = 0; j < n; j++) {
            if(b[i+j] != j) {
                cnt++;
                int idx = mark[j];
                swap(b[i+j], b[idx]);
                mark[b[idx]] = idx;
            }
        }
        ret = min(ret, cnt);
    }
    return ret;
}
int main() {
    int n, i, j, k;
    int a[1005];
    while(scanf("%d", &n) == 1 && n) {
        for(i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            a[i]--;
        }
        int ret;
        ret = solve(n, a);
        reverse(a, a+n);
        ret = min(ret, solve(n, a));
        printf("%d\n", ret);
    }
    return 0;
}