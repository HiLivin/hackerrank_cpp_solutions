#include <iostream>
#include <deque> 
using namespace std;

void printKMax(int arr[], int n, int k){
	//Write your code here.
    
    //deque of arr indices
    deque<int> dq;
    
    //insert first k elements
    for(int i = 0; i < k; ++i){
        if(dq.empty() || arr[i] >= arr[dq.front()]){
            dq.clear();
            dq.push_front(i);
        }else{
            while(arr[dq.back()] < arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
    }
    
    printf("%d ", arr[dq.front()]);

    //slide the window
    for(int i = k; i < n; ++i){
        while(!dq.empty() && dq.front() <= i - k){
            //delete front element if it's beyond the window
            dq.pop_front();
        }
        
        if(dq.empty() || arr[i] >= arr[dq.front()]){
            dq.clear();
            dq.push_front(i);
        }else{
            while(arr[dq.back()] < arr[i])
                dq.pop_back();
            dq.push_back(i);
        }
        
        printf("%d ", arr[dq.front()]);
    }
    
    printf("\n");
}

int main(){
  
	int t;
	cin >> t;
	while(t>0) {
		int n,k;
    	cin >> n >> k;
    	int i;
    	int arr[n];
    	for(i=0;i<n;i++)
      		cin >> arr[i];
    	printKMax(arr, n, k);
    	t--;
  	}
  	return 0;
}
