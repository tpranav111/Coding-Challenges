//136. Single Number = https://leetcode.com/problems/single-number/description/ 



class Solution {
public:
    //XOR logic= xor of 2 same nos = 0 & xor of 0 with any number = that number
    /*
        If we take XOR of zero and some bit, it will return that bit
        a⊕0=aa \oplus 0 = aa⊕0=a
        If we take XOR of two same bits, it will return 0
        a⊕a=0a \oplus a = 0a⊕a=0
        a⊕b⊕a=(a⊕a)⊕b=0⊕b=ba \oplus b \oplus a = (a \oplus a) \oplus b = 0 \oplus b = ba⊕b⊕a=(a⊕a)⊕b=0⊕b=b
    */
    int singleNumber(vector<int>& nums) {
        int a = 0;
        for(int i=0; i<nums.size(); i++)
        {
            a ^=nums[i];
        }
        return a;
    }

    int singleNumber1(vector<int>& nums) {
        //int n = sizeof(nums)/sizeof(nums[0]);
        
        //dont rmv !! sort(nums.begin(), nums.end());
        //for(int i=0; i<nums.size(); i++)
        //    cout<<nums[i]<<endl;

        for(int i=0; i<nums.size(); i++)
        {
            if(i-1 < 0 && i+1 < nums.size())    // 3 cases to compare adjacency elemts with current element
            {
                if(nums[i] == nums[i+1])
                    continue;
                return nums[i];
            }
            else if(i-1 >= 0 && i+1<nums.size())
            {
                if(nums[i-1] == nums[i] || nums[i+1] == nums[i])
                    continue;
                return nums[i];
            }
            else if(i-1 >= 0 && i+1 >= nums.size())
            {
                if(nums[i-1] == nums[i])
                    continue;
                return nums[i];
            }
        }
        return nums[0];
    }
};