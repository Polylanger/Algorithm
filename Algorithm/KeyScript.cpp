
/* 二分查找法代码模板
 */
int binarySearch(int list[], int left, int right, int target) {
  int middle, low = left, high = right;
  while (low < high) {
    middle = (low + high) / 2;
    if (list[middle] > target) {
      high = middle - 1;
    }
    else if (list[middle] < target) {
      low = middle + 1;
    }
    else {
      return middle;
    }
  }
  return -1;
}