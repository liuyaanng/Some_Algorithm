#include <iostream>
#include <time.h>
#include <cstdlib>
#include <vector>

using namespace std;
//
// 插入排序, n为数组长度
void Insertion_Sort_1(vector<int> & nums, int n){
	for(int i = 0; i < n; ++i){
		for(int j = i; j > 0 && nums[j] < nums[j - 1]; --j){
			swap(nums[j], nums[j-1]);
		}
	}
}

void Straight_Insertion_Sort(vector<int> & nums, int n){
	for(int i = 0; i < n; ++i){
		int X = nums[i];
		int j = i-1;
		for(; j >= 0 && nums[j] > X; --j){
			nums[j+1] = nums[j];
		}
		nums[j+1] = X;
	}
}

void Binary_Insertion_Sort(vector<int> & nums, int n){
	int left, right, mid, i, j;

	for(i = 1; i < n; ++i){
		//寻找到满足 nums[mid] <= nums[i] <= nums[mid+1]
		int X = nums[i];
		left = 0;
		right = i - 1;

		while(left <= right){
			mid = right + left >> 1;
			if(nums[mid] <= nums[i]){
				left = mid + 1;
			}else{
				right = mid - 1;
			}
		}

		for(j = i - 1; j >= right + 1; --j){
			nums[j+1] = nums[j];
		}
		nums[j+1] = X;
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

void Bubble_Sort(vector<int>& nums, int n){
	for(int i = 0; i < n; ++i){
		for(int j = 0; j < n - i - 1; ++j){
			if(nums[j] > nums[j+1]){
				swap(nums[j], nums[j+1]);
			}
		}
	}
}

void Selection_Sort(vector<int>& nums, int n){
	int min_index;
	for(int i = 0; i < n; ++i){
		min_index = i;
		for(int j = i; j < n; ++j){
			if(nums[j] < nums[min_index]){
				min_index = j;
			}
		}
		swap(nums[i], nums[min_index]);
	}
}

// 快速排序
// 划分子序列, 返回枢纽所在位置
int Partition(vector<int>& nums, int left, int right){
	int pivotkey = rand() % (right - left + 1) + left;
	swap(nums[pivotkey], nums[left]);
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

int Random_Partition(vector<int> & nums, int left, int right){
	int pivotkey = rand() % (right - left + 1) + left;
	int pivot = nums[pivotkey];
	swap(nums[pivotkey], nums[right]);
	int i = left - 1, j = left;
	for(; j < right; ++j){
		if(nums[j] <= pivot){
			//保证小于pivot 的数在左边
			swap(nums[++i], nums[j]);
		}
	}
	swap(nums[i+1], nums[right]);
	return i+1;
}

void Quick_Sort(vector<int>& nums, int left, int right){
	if(left < right){
		// int pivotkey = Random_Partition(nums, left, right);
		int pivotkey = Partition(nums, left, right);
		Quick_Sort(nums, left, pivotkey - 1);
		Quick_Sort(nums, pivotkey + 1, right);
	}
}

void Merge_Sort(vector<int>& nums, int left, int right, vector<int>& temp){
	if(left + 1 >= right) return;

	// divide
	int mid = right + left >> 1;
	Merge_Sort(nums, left, mid, temp);
	Merge_Sort(nums, mid, right, temp);

	//conquer
	int p = left, q = mid, i = left;
	while(p < mid || q < right){
		if(q >= right || (p < mid && nums[p] <= nums[q])){
			temp[i++] = nums[p++];
		} else {
			temp[i++] = nums[q++];
		}
	}

	for(i = left; i < right; ++i){
		nums[i] = temp[i];
	}
}

void show_list(const vector<int> nums){
	for(int i=0; i<nums.size(); ++i) cout << nums[i] << ' ';
}


//升序排序
int main(){
	int n = 10;
	vector<int> nums(n, 0);
	vector<int> temp(n);
	srand(time(NULL)); // 随机种子
	for (int i = 0; i < n; i++)
	    nums[i] = rand() % 50;
	show_list(nums);
	cout << endl;
	// Insertion_Sort_2(nums, nums.size());
	// Binsertion_Sort(nums, nums.size());
	// Shell_Sort(nums, nums.size());
	// Bubble_Sort(nums, nums.size());
	// Selection_Sort(nums, nums.size());
	// Quick_Sort(nums, 0, nums.size() - 1); //这里的left right为数组下标, 所以要用 nums.size()-1
	Merge_Sort(nums, 0, nums.size(), temp);
	show_list(nums);
	return 0;
}
