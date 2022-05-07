pub fn pivot<T>(v: &mut [T]) -> (usize, usize)
where
  T: Ord + Copy,
{
  let n = v.len();
  let x = rand::random::<usize>() % n;
  let baseline = v[x];

  let (mut l, mut r) = (0, n);

  for i in 0..n {
    if v[i] < baseline {
      v.swap(i, l);
      l += 1;
    }
  }

  for i in (0..n).rev() {
    if v[i] > baseline {
      v.swap(i, r - 1);
      r -= 1;
    }
  }

  (l, r)
}
