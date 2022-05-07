use crate::utils;

use super::Sort;

pub struct QuickSort;

impl<T> Sort<T> for QuickSort
where
  T: Ord + Copy,
{
  fn sort(v: &mut [T]) -> () {
    let n = v.len();

    if n < 2 {
      return;
    }

    let (l, r) = utils::pivot(v);

    Self::sort(&mut v[..l]);
    Self::sort(&mut v[r..]);
  }
}
