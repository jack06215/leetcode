class Solution {
public:
	vector<int> arr;

	int cross(int left,int right,int mid){
		//if(left==right) return arr[left];
		int cur=0;
		int ans1=INT_MIN;
		int ans2=INT_MIN;
		for(int i=mid;i>=left;i--){
			cur+=arr[i];
			ans1=max(ans1,cur);
		}

		cur=0;
		for(int i=mid+1;i<=right;i++){
			cur+=arr[i];
			ans2=max(ans2,cur);
		}

		return ans1+ans2;


	}

	int helper(int left, int right){
		if(left>=right){
			return arr[left];
		}
		int mid=(left+right)/2;

		int sumLeft=helper(left,mid);
		int sumRight=helper(mid+1,right);
		int sumCross=cross(left,right,mid);

		return max(sumCross,max(sumLeft,sumRight));
	}
	int maxSubArray(vector<int>& nums) {
		arr=nums;
		int n=nums.size();
		return helper(0,n-1);

	}
};