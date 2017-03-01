
class Solution {
public:
    void nextPermutation(vector<int> &num) {
        int len = num.size();
		int i = len - 1;
		while(i > 0)
		{
			if(num[i] > num[i - 1])  // what if the same
			{
				break;
			}
			--i;
		}
		if(i == 0)
		{
			reverse(num, 0, len - 1);
			return;  // !
		}

		int k = i;
		for(int j = len - 1; j > i; --j)  // from right to left 
		{
			if(num[j] > num[i - 1])
			{
				k = j;
				break;  // !
			}
		}

		int tmp = num[k];
		num[k] = num[i - 1];
		num[i - 1] = tmp;

		reverse(num, i, len - 1);
	}

	void reverse(vector<int> &num, int start, int end)
	{
		while(start < end)
		{
			int tmp = num[start];
			num[start++] = num[end];
			num[end--] = tmp;
		}
    }
};

