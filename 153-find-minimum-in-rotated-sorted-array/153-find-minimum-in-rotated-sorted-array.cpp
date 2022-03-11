class Solution {
public:
    int binaryFoo(vector<int> v,int l,int r){
			
			int mid=l+(r-l)/2;
		    //when mid is first element
		    if(mid==0 && v[mid]<v[mid+1]){
		    	return v[mid];
		    }

            if(mid==0 && v[mid]>v[mid+1]){
                return v[mid+1];
            }
                        
		    //when mid is last element 
	    	if(mid==v.size()-1 && v[mid-1]>v[mid]){
		    	return v[mid];
	    	}

		    if(v[mid]<v[mid-1] && v[mid]<v[mid+1]){
		    	return v[mid];
		    }

		    if(v[mid]>v.front() && v.front()>v.back()){
		    	return binaryFoo(v,mid+1,r);
		    }

			if(v[mid]<v.front()){
		    	return binaryFoo(v,l,mid-1);
		    }
            
			if(v[0]<v[1]){
				return v[0];
			}
            return v.back();		
	}
    
    int findMin(vector<int>& nums) {
        /**
         * @brief Find an element e such that e-1>e<e+1
         */
		if(nums.size()==1){
			return nums[0];
		}

		return binaryFoo(nums,0,nums.size()-1);
    }
};