use std::io::Write;

use sha2::{digest::Update, Digest, Sha256};

fn sha256(word: &String) -> String {
    hex::encode(Sha256::new().chain(word).finalize())
}

fn generate_otp_chain(word: String, times: usize) -> Vec<String> {
    std::iter::successors(Some(word), |word| Some(sha256(word)))
        .skip(1)
        .take(times)
        .collect()
}

fn main() {
    let mut seed = String::new();
    print!("input password: ");
    std::io::stdout().flush().unwrap();
    std::io::stdin().read_line(&mut seed).unwrap();
    let seed = seed.trim().to_string();

    let mut iters = String::new();
    print!("input iterations: ");
    std::io::stdout().flush().unwrap();
    std::io::stdin().read_line(&mut iters).unwrap();
    let iters = iters.trim().parse::<usize>().unwrap();

    let otps = generate_otp_chain(seed, iters);
    for otp in otps.into_iter().rev() {
        println!("password = {}", otp);
    }
}
