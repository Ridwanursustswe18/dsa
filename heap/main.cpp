#include<bits/stdc++.h>
using namespace std;
vector<int>heap_;
void push(int val){
    if(heap_.empty()){
        heap_.push_back(0);
       
    }
     heap_.push_back(val);
    int i = heap_.size()-1;
    while(heap_[i] < heap_[i/2]){
        int temp = heap_[i];
         heap_[i] = heap_[i/2];
         heap_[i/2] = temp;
        i /=2;
    } 
}
int main(){
    push(10);
    push(5);
    
}