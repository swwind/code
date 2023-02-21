use base64;
use md5;
use rpassword;
use std::io::Write;

fn md5sum(s: String) -> String {
    format!("{:x}", md5::compute(s))
}

fn hash(s: &String, key: &String, times: i32) -> String {
    if times > 0 {
        hash(&md5sum(format!("{s}{key}")), &s, times - 1)
    } else {
        s.to_string()
    }
}

fn calc(key1: &String, key2: &String, key3: &String, partition: &String) -> String {
    let hs = [
        hash(&key1, &key2, 10),
        hash(&key2, &key3, 10),
        hash(&key3, &key1, 10),
        hash(&key1, &key3, 10),
        hash(&key2, &key1, 10),
        hash(&key3, &key2, 10),
    ];

    let rs = [
        hash(&md5sum(hs[0..3].concat()), &partition, 10),
        hash(&md5sum(hs[3..6].concat()), &partition, 10),
    ];

    base64::encode(hash(&rs[0], &rs[1], 10))
        .chars()
        .take(16)
        .collect()
}

fn main() {
    let p1 = rpassword::prompt_password_stdout("Password#1: ").unwrap();
    let p2 = rpassword::prompt_password_stdout("Password#2: ").unwrap();
    let p3 = rpassword::prompt_password_stdout("Password#3: ").unwrap();

    println!("{}", calc(&p1, &p2, &p3, &String::new()));

    print!("Partition: ");
    std::io::stdout().flush().unwrap();
    let mut pt = String::new();
    std::io::stdin().read_line(&mut pt).unwrap();

    let result = calc(&p1, &p2, &p3, &pt.trim().to_string());

    // println!("{}", result);

    std::process::Command::new("sh")
        .arg("-c")
        .arg(format!("echo -n {} | wl-copy", result))
        .spawn()
        .expect("Failed to copy to clipboard");

    println!("Copied to clipboard.");
}
