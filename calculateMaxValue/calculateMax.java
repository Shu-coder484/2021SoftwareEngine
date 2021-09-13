public class calculateMax{
	public static int sumParams(int []nums){
		int maxSum = 0;
  		for (int i = 0; i < nums.length; i++) {
   			int sum = 0;
   			for (int j = i; j < nums.length; j++) {
    				sum = sum + nums[j];
    				if (sum > maxSum) {
     					maxSum = sum;
    				}
   			}
 		}
 		//System.out.println("子数组之和的最大值为: "+maxSum);
		System.out.println("MaxValue: "+maxSum);
  		return maxSum;
	}
	public static void main(String args[]){
		int []num={1,-2,3,5,-1};
		int sum;
		sum=sumParams(num);
		return;	
	}
}