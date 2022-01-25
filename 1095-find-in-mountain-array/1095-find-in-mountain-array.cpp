/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &arr) {
        int l=0,h=arr.length()-1,m=0;
        while(l<h){
            int mid=(l+h)/2;
            if(arr.get(mid)<arr.get(mid+1))l=mid+1;
            else h=mid;
        }
        m=l,l=0,h=m;
        if(arr.get(m)==target)return m;
        
        while(l<=h){
            int mid=(l+h)/2;
            int val=arr.get(mid);
            if(target==val)return mid;
            else if(target<val)h=mid-1;
            else l=mid+1;
        }
        l=m,h=arr.length()-1;
        while(l<=h){
            int mid=(l+h)/2;
            int val=arr.get(mid);
            if(target==val)return mid;
            else if(target<val)l=mid+1;
            else h=mid-1;
        }
        return -1;
    }
};