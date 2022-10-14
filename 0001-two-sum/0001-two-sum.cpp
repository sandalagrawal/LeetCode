class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
    
        //another solution is using only 1 for loop, storing the element in an iterator and using the find function we try to find the (target-it) number 

vector<int>result;
for(auto it = nums.begin(); it!= nums.end();++it){
auto it2 = find(it+1, nums.end(), target-*it);
if(it2!=nums.end())
{
result.push_back(it-nums.begin());
result.push_back(it2-nums.begin());
}
}
return result;
        
  /*
 // here we use hash maps to solve the problem
 unordered_map<int,int> map;
 for(int i=0;i<nums.size();i++){
 int ini = nums[i];
 int compliment = target - ini;
 auto it = map.find(compliment);
 if(it != map.end()){
 return (it->second, i)
 }
 map[ini]=i;
 }
    return {};    
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        /*first solution, by me, very noob
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(target==nums[i]+nums[j])
                {
                    ans.push_back(i);
                    ans.push_back(j);
                }
                    
            }
        }
        
        return ans;*/
        
    }
};

