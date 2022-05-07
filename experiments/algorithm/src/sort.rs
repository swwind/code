pub mod merge_sort;
pub mod quick_sort;
pub mod std_sort;

pub trait Sort<T> {
  fn sort(v: &mut [T]) -> ();
}

#[cfg(test)]
mod tests {
  extern crate test;
  use rand::prelude::SliceRandom;
  use test::Bencher;

  use super::{merge_sort::MergeSort, quick_sort::QuickSort, std_sort::StdSort, Sort};

  fn generate_data(rate: u32) -> Vec<u32> {
    let mut rng = rand::thread_rng();
    let dup = (rate * 100_000) as usize;

    let mut vec = std::iter::repeat(0)
      .take(dup)
      .chain((1..).into_iter().take(1_000_000 - dup))
      .collect::<Vec<_>>();
    vec.shuffle(&mut rng);
    vec
  }

  #[test]
  fn quick_sort_test() {
    for i in 0..=10 {
      let mut data = generate_data(i);
      QuickSort::sort(&mut data);
      assert!(data.is_sorted());
    }
  }

  #[test]
  fn merge_sort_test() {
    for i in 0..=10 {
      let mut data = generate_data(i);
      MergeSort::sort(&mut data);
      assert!(data.is_sorted());
    }
  }

  #[bench]
  fn quick_sort_bench_0(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(0)));
  }

  #[bench]
  fn quick_sort_bench_1(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(1)));
  }

  #[bench]
  fn quick_sort_bench_2(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(2)));
  }

  #[bench]
  fn quick_sort_bench_3(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(3)));
  }

  #[bench]
  fn quick_sort_bench_4(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(4)));
  }

  #[bench]
  fn quick_sort_bench_5(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(5)));
  }

  #[bench]
  fn quick_sort_bench_6(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(6)));
  }

  #[bench]
  fn quick_sort_bench_7(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(7)));
  }

  #[bench]
  fn quick_sort_bench_8(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(8)));
  }

  #[bench]
  fn quick_sort_bench_9(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(9)));
  }

  #[bench]
  fn quick_sort_bench_10(b: &mut Bencher) {
    b.iter(|| QuickSort::sort(&mut generate_data(10)));
  }

  #[bench]
  fn merge_sort_bench_0(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(0)));
  }

  #[bench]
  fn merge_sort_bench_1(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(1)));
  }

  #[bench]
  fn merge_sort_bench_2(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(2)));
  }

  #[bench]
  fn merge_sort_bench_3(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(3)));
  }

  #[bench]
  fn merge_sort_bench_4(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(4)));
  }

  #[bench]
  fn merge_sort_bench_5(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(5)));
  }

  #[bench]
  fn merge_sort_bench_6(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(6)));
  }

  #[bench]
  fn merge_sort_bench_7(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(7)));
  }

  #[bench]
  fn merge_sort_bench_8(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(8)));
  }

  #[bench]
  fn merge_sort_bench_9(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(9)));
  }

  #[bench]
  fn merge_sort_bench_10(b: &mut Bencher) {
    b.iter(|| MergeSort::sort(&mut generate_data(10)));
  }

  #[bench]
  fn std_sort_bench_0(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(0)));
  }

  #[bench]
  fn std_sort_bench_1(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(1)));
  }

  #[bench]
  fn std_sort_bench_2(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(2)));
  }

  #[bench]
  fn std_sort_bench_3(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(3)));
  }

  #[bench]
  fn std_sort_bench_4(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(4)));
  }

  #[bench]
  fn std_sort_bench_5(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(5)));
  }

  #[bench]
  fn std_sort_bench_6(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(6)));
  }

  #[bench]
  fn std_sort_bench_7(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(7)));
  }

  #[bench]
  fn std_sort_bench_8(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(8)));
  }

  #[bench]
  fn std_sort_bench_9(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(9)));
  }

  #[bench]
  fn std_sort_bench_10(b: &mut Bencher) {
    b.iter(|| StdSort::sort(&mut generate_data(10)));
  }
}
