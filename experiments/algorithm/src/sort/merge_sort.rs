use super::Sort;

/// 归并排序
pub struct MergeSort;

impl<T> Sort<T> for MergeSort
where
  T: Ord + Copy,
{
  fn sort(v: &mut [T]) -> () {
    let n = v.len();
    if n < 2 {
      return;
    }

    let (left, right) = v.split_at_mut(n / 2);

    // 递归排序
    Self::sort(left);
    Self::sort(right);

    let mut vec = Vec::with_capacity(n);

    let (mut i, mut j) = (0, 0);

    // 合并左右两半的数组，直到其中一方用尽
    while i < left.len() && j < right.len() {
      if left[i] < right[j] {
        vec.push(left[i]);
        i += 1;
      } else {
        vec.push(right[j]);
        j += 1;
      }
    }

    // 添加左边数组中的剩余部分
    vec.extend_from_slice(&left[i..]);
    // 添加右边数组中的剩余部分
    vec.extend_from_slice(&right[j..]);

    // 复制回原来的数组中
    v.copy_from_slice(&vec);
  }
}
