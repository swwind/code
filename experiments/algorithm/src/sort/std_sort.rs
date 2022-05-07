use super::Sort;

pub struct StdSort;

impl<T> Sort<T> for StdSort
where
  T: Ord,
{
  fn sort(v: &mut [T]) -> () {
    v.sort()
  }
}
