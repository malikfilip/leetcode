class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0;
        int right = nums.size() - 1;
        int mid = (left + right)  / 2;
        int min = -1;


        //Trazimo poziciju minimalnog elementra jer je on problem kod kog se narusava uslov obicne binarne da je niz rastuci


        while(left != right){
            
            if (nums[mid] > nums[right]){
                left = mid + 1;
            }
            else{right = mid;}
            mid = (left + right)  / 2;
        }
        min = left;


        if(target < nums[min]){return -1;}
        if(min == 0){ //Ako je minimalni element na pocetku, samo obicna binarna pretraga
            right = nums.size() - 1;
            left = 0;
        }else if(target >= nums[min] && target <= nums[nums.size() - 1]){ //Ako je target u desnoj polovini (obe polovine su sortirane pa samo mozemo obicnu binarnu da opalimo)
            left = min; //leva granica je najmanji element 
            right = nums.size() - 1; //a desna kraj niza
        }else if(target >= nums[0] && target <= nums[min-1]){ //Ako je u levoj polovini
            left = 0;
            right = min-1;

        }

        while(left <= right){ //Sada samo obicna binarna kada smo namestili left i right
            mid = (left + right)  / 2;
            if(target == nums[mid]){return mid;}
            else if (target < nums[mid]){
                right = mid - 1;
            }else {
                left = mid + 1;
            }
        }
        return -1;
        
    }
};

