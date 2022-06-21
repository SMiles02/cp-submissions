use std::io;

fn main() {
    let mut n = String::new();

    io::stdin()
        .read_line(&mut n)
        .expect("Failed to read line");

    let n: u32 = match n.trim().parse() {
        Ok(num) => num,
        Err(_) => 0,
    };
    
    if n % 2 == 0 && n > 2 {
        println!("YES");
    }
    else {
        println!("NO");
    }
}