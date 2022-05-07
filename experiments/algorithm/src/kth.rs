pub mod group_select;
pub mod quick_select;
pub mod std_select;

pub trait Kth<T> {
  fn kth(v: &mut [T], k: usize) -> Option<T>;
}

#[cfg(test)]
mod tests {
  extern crate test;

  use crate::kth::std_select::StdSelect;

  use super::{group_select::GroupSelect, quick_select::QuickSelect, Kth};
  use rand::{seq::SliceRandom, Rng};
  use test::Bencher;

  fn generate_data(n: u32) -> (Vec<u32>, usize) {
    let mut rng = rand::thread_rng();
    let mut data = (0..n).into_iter().collect::<Vec<_>>();
    data.shuffle(&mut rng);

    (data, rng.gen_range(0..n) as usize)
  }

  #[test]
  fn quick_select_test() {
    let (mut data, k) = generate_data(1_000_000);
    assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
  }

  #[test]
  fn group_select_test() {
    let (mut data, k) = generate_data(1_000_000);
    assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
  }

  #[bench]
  fn quick_select_bench_1k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(1_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_2k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(2_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_5k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(5_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_10k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(10_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_20k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(20_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_50k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(50_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn quick_select_bench_100k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(100_000);
      assert_eq!(QuickSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_1k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(1_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_2k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(2_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_5k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(5_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_10k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(10_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_20k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(20_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_50k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(50_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn group_select_bench_100k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(100_000);
      assert_eq!(GroupSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_1k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(1_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_2k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(2_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_5k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(5_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_10k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(10_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_20k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(20_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_50k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(50_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }

  #[bench]
  fn std_select_bench_100k(b: &mut Bencher) {
    b.iter(|| {
      let (mut data, k) = generate_data(100_000);
      assert_eq!(StdSelect::kth(&mut data, k), Some(k as u32));
    });
  }
}
