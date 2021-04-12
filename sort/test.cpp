#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;

void show_list(vector<int> nums){
	for(int i=0; i<nums.size(); ++i) cout << nums[i] << ' ';
	cout << endl;
}

void Select_Sort(vector<int> & nums, int n){
	if(n == 0) return;
	for(int i = 0; i < n; ++i){
		int temp = nums[i], temp_index = i;
		for(int j = i; j < n; ++j){
			if(nums[j] < temp){
				temp = nums[j];
				temp_index = j;
			}
		}
		swap(nums[i], nums[temp_index]);
	}
}

void Bubble_Sort(vector<int> & nums, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - 1; ++j){
			if(nums[j] > nums[j + 1]){
				swap(nums[j], nums[j + 1]);
			}
		}
	}
}

void Insertion_Sort_1(vector<int> & nums, int n){
	for(int i = 0; i < n; ++i){
		int temp = nums[i];
		int j = 0; 
		// 找到第一个大于等于temp的位置
		while(j < i){
			if(nums[j] < temp){
				++j;
			} else break;
		}
		// 将插入位置后的元素都向后移动一位. 
		for(int k = i; k > j; --k){
			nums[k] = nums[k-1];
		}
		// 插入元素
		nums[j] = temp;
	}
}

void Insertion_Sort_2(vector<int> & nums, int n){
	for(int i= 0 ; i < n; ++i){
		for(int j = i; j > 0 && nums[j] < nums[j-1]; --j){
			swap(nums[j], nums[j-1]);
		}
	}
}

void Binary_Insertion_Sort(vector<int> & nums, int n){
	int left = 0, right = 0;
	for(int i=0; i < n; ++i){
		left = 0;
		right = i - 1;
		// int temp = nums[i];
		while(left <= right){
			int mid = left + right >> 1;
			if(nums[mid] <= nums[i]){
				left = mid + 1;
			} else if(nums[mid] > nums[i]){
				right = mid - 1;
			}
		}

		for(int j = i; j > left; --j){
			swap(nums[j], nums[j-1]);
		}
	}
}

void Shell_Sort(vector<int> & nums, int n){
	int h = 1;
	while(h < n/3){
		h = h * 3 + 1; // 1, 4, 13, 40, ...
	}
	while(h >= 1){
		for(int i = h; i < n; ++i){
			for(int j = i; j >= h && nums[j] < nums[j-h]; j -= h){
				swap(nums[j], nums[j-h]);
			}
		}
		h = h / 3;
	}
}
int Partition(vector<int> & nums, int left, int right){
	int pivot = nums[left];
	while(left < right){
		while(left < right && nums[right] >= pivot) --right;
		nums[left] = nums[right];
		while(left < right && nums[left] <= pivot) ++left;
		nums[right] = nums[left];
	}
	nums[left] = pivot;
	return left;
}
void Quick_Sort(vector<int> & nums, int left, int right){
	if(left < right){
		int pivotkey = Partition(nums, left, right);
		Quick_Sort(nums, left, pivotkey - 1);
		Quick_Sort(nums, pivotkey + 1, right);
	}
}

int main(){
		int n = 10;
	vector<int> nums(n, 0);
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    nums[i] = rand() % 9 + 1;
	show_list(nums);
	// Select_Sort(nums, nums.size());
	// Bubble_Sort(nums, nums.size());
	// Insertion_Sort(nums, nums.size());
	// Insertion_Sort_2(nums, nums.size());
	// Binary_Insertion_Sort(nums, nums.size());
	// Shell_Sort(nums, nums.size());
	Quick_Sort(nums, 0, nums.size()-1);
	show_list(nums);
	return 0;
}
