use crate::utils;

use super::Kth;

pub struct QuickSelect;

impl<T> Kth<T> for QuickSelect
where
  T: Ord + Copy,
{
  fn kth(v: &mut [T], k: usize) -> Option<T> {
    let n = v.len();

    if k >= n {
      return None;
    }

    let (l, r) = utils::pivot(v);

    if (l..r).contains(&k) {
      Some(v[l])
    } else if k < l {
      Self::kth(&mut v[..l], k)
    } else {
      Self::kth(&mut v[r..], k - r)
    }
  }
}
