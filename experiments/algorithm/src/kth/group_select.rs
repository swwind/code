use crate::sort::{quick_sort::QuickSort, Sort};

use super::Kth;

pub struct GroupSelect;

impl<T> Kth<T> for GroupSelect
where
  T: Ord + Copy,
{
  fn kth(v: &mut [T], k: usize) -> Option<T> {
    let n = v.len();

    if k >= n {
      return None;
    }

    if n <= 5 {
      QuickSort::sort(v);
      return Some(v[k]);
    }

    let mut middles = v
      .chunks_exact_mut(5)
      .map(|c| GroupSelect::kth(c, 2).unwrap())
      .collect::<Vec<_>>();

    let baseline = {
      let len = middles.len();
      Self::kth(&mut middles, len / 2).unwrap()
    };

    let mut group_smaller = Vec::new();
    let mut group_greater = Vec::new();

    for i in v.iter() {
      if *i < baseline {
        group_smaller.push(*i);
      } else if *i > baseline {
        group_greater.push(*i);
      }
    }

    let l = group_smaller.len();
    let r = n - group_greater.len();

    if (l..r).contains(&k) {
      Some(baseline)
    } else if k < l {
      Self::kth(&mut group_smaller, k)
    } else {
      Self::kth(&mut group_greater, k - r)
    }
  }
}
