#include<bits/stdc++.h>
using namespace std;
vector<int>heap_;
void push(int val){
    if(heap_.empty()){
        heap_.push_back(0);
       return;
    }
     heap_.push_back(val);
    int i = heap_.size()-1;
    while(i>1 && heap_[i] < heap_[i/2]){
       swap(heap_[i],heap_[i/2]);
        i /=2;
    } 
}
int top(){
     if (heap_.size() > 1) {
            return heap_[1];
        }
      
        return -1;
}
int pop(){
    int res;
    if(heap_.size()==1){
        return -1;
    }
    
    if(heap_.size()==2){
          int res = heap_[heap_.size() - 1];
            heap_.pop_back();
            return res; 
    }
    res = heap_[1];
    heap_[1] = heap_[heap_.size()-1];
    heap_.pop_back();
    int i = 1;
   
    while (2*i<heap_.size())
    {
     if(2*i+1<heap_.size()&& heap_[2*i+1]<heap_[2*i] && heap_[i]>heap_[2*i+1]){
       swap(heap_[i],heap_[2*i+1]);
        i  = 2*i+1;
        
     }
     else if(heap_[i]>heap_[2*i]){
        swap(heap_[i],heap_[2*i]);
        i  = 2*i;
        
     }
     else{
        break;
     }  
       
    }
    
    return res;
}
void heapify(vector<int>&nums){
    nums.push_back(nums[0]);
    int curr = (nums.size() - 1)/2;
    while(curr>0){
        int i = curr;
        while(2*i+1<nums.size()){
            
        if(2*i+1<nums.size() && nums[2*i+1]<nums[2*i] && nums[i]>nums[2*i+1]){
            swap(nums[i],nums[2*i+1]);
            i = 2 * i+1;
        }
        else if(nums[i]>nums[2*i]){
            swap(nums[i],nums[2*i]);
            i = 2 * i;
        }
       else{ 
        break;
        }
    }
     curr--;
    }
}
int main(){
    push(10);
    push(5);
    push(15);
    push(3);
    push(20);
    push(2);
  heapify(heap_);
  for(int i = 1;i<heap_.size()-1;i++){
    cout<<heap_[i]<<endl;
  }
    

}