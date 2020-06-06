#include "Common.h"

using namespace std;

/* 冒泡排序
 * 比较次数：与初始排列顺序无关，无论初始列表什么顺序，都需要比较 O(n^2) 次才能结束
 * 交换次数：最坏情况下是初始列表逆序排列，需要交换 O(n^2)
 *           最好情况下是初始即顺序排列，交换次数为 0
 */
void bubbleSort(int list[], int left, int right) {
  for (int i = left + 1; i <= right; i++) {
    // exchange = false;  // 为优化最好情况下效率，定义：是否发生交换标志
    for (int j = right; j >= i; j--) {
      if (list[j - 1] > list[j]) {
        // exchange = true; // 若本次存在逆序，则标志置为有交换状态
        int temp = list[j - 1];
        list[j - 1] = list[j];
        list[j] = temp;
      }
    }
    // if (!exchange) return; // 若标志为未交换状态，说明从尾到头一轮下来没有逆序数，列表有序结束排序。
  }
}

/* 直接插入排序
 * 最好情况：顺序列表，比较 n-1 次，移动 0 次。划重点！正是由于直接插入排序对初始顺序及其敏感，才衍生出 Shell 排序的思想
 * 最坏情况：倒序列表，O(n^2)
 */
void insertSort(int list[], int left, int right) {
  int temp, i, j;
  for (i = left + 1; i <= right; i++) {
    temp = list[i]; 
    for (j = i; j > left && list[j - 1] > temp; j--) {
      list[j] = list[j - 1];
    }
    list[j] = temp;
  }
}

/* 折半插入排序
 * 比较次数与列表初始顺序无关，均要比较 O(nlogn) 次
 * 移动次数与直接插入排序次数相同，O(n^2)
 */
void binaryInsertSort(int list[], int left, int right) {
  int temp, i, j;
  int middle, low, high;
  for (i = left + 1; i <= right; i++) {
    temp = list[i];

    // 二分查找，未查到时确保 low 指向实际位置右边第一个元素
    low = left; high = i - 1;
    while (low <= high) { // 这里取等是应对：实际位置位于变换后的 high 右边的场景
      middle = (low + high) / 2; 
      if (list[middle] > temp) high = middle - 1;
      else low = middle + 1;
    }

    for (j = i; j > low; j--) list[j] = list[j - 1];

    list[low] = temp;
  }
}

/* Shell 排序
 * 不稳定的排序算法
 * 开始时 gap 较大，每个子序列元素较少，排序速度较快；
 * 后期 gap 变小，子序列元素变多，但由于之前的工作，使得每个子序列基本有序，故排序速度依旧很快。
 */
void shellSort(int list[], int left, int right) {
  int temp, i, j, gap = right - left + 1;
  do {
    gap = (gap / 3) + 1;
    // 直接排序的外层循环是从左边第二个元素开始
    // 则Shell排序的外层循环从每个子序列的第二个元素开始，即：left + gap
    for (i = left + gap; i <= right; i++) {
      temp = list[i];
      // 同一子序列两相邻元素下标之差为 gap
      for (j = i; j > left && list[j - gap] > temp; j -= gap) {
        list[j] = list[j - gap];
      }
      list[j] = temp;
    }
  } while (gap > 1);
}

int main() {
  int n = 17;
  int list[] = {77, 5, 29, 52, 4, 6, 31, 2, 21, 9, 10, 11, 8, 7, 33, 3, 1};

  //bubbleSort(list, 0, n - 1);
  //insertSort(list, 0, n - 1);
  //binaryInsertSort(list, 0, n - 1);
  shellSort(list, 0, n - 1);

  for (int i = 0; i < n; i++) {
    cout << list[i] << ", ";
  }
  return 0;
}

