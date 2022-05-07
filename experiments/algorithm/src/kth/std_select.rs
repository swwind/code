use super::Kth;

pub struct StdSelect;

impl<T> Kth<T> for StdSelect
where
  T: Ord + Copy,
{
  fn kth(v: &mut [T], k: usize) -> Option<T> {
    v.select_nth_unstable(k);
    Some(v[k])
  }
}
