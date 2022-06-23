fn main() {
    let (read_input, write_output) = (std::io::stdin(), std::io::stdout());
    let mut sc = IO::new(read_input.lock(), write_output.lock());
 
    let t: u32 = sc.read();
    for _ in 0..t {
        let n: u32 = sc.read();
        let mut ans: u32 = sc.read();
        let mut a = vec![0; 100];
        let mut b = vec![0; 100];
        const INF : u32 = 1000000000;
        for i in 0 .. n as usize {
            a[i] = sc.read();
        }
        for i in 0 .. n as usize {
            b[i] = sc.read();
        }
        for _j in 0 .. n {
            for i in 0 .. n as usize {
                if ans >= a[i] {
                    ans += b[i];
                    a[i] = INF;
                }
            }
        }
        println!("{}", ans);
    }
}

pub struct IO<R, W: std::io::Write>(R, std::io::BufWriter<W>);

impl<R: std::io::Read, W: std::io::Write> IO<R, W> {
    pub fn new(r: R, w: W) -> IO<R, W> {
        IO(r, std::io::BufWriter::new(w))
    }
    pub fn write<S: ToString>(&mut self, s: S) {
        use std::io::Write;
        self.1.write_all(s.to_string().as_bytes()).unwrap();
    }
    pub fn read<T: std::str::FromStr>(&mut self) -> T {
        use std::io::Read;
        let buf = self
            .0
            .by_ref()
            .bytes()
            .map(|b| b.unwrap())
            .skip_while(|&b| b == b' ' || b == b'\n' || b == b'\r' || b == b'\t')
            .take_while(|&b| b != b' ' && b != b'\n' && b != b'\r' && b != b'\t')
            .collect::<Vec<_>>();
        unsafe { std::str::from_utf8_unchecked(&buf) }
            .parse()
            .ok()
            .expect("Parse error.")
    }
    pub fn usize0(&mut self) -> usize {
        self.read::<usize>() - 1
    }
    pub fn vec<T: std::str::FromStr>(&mut self, n: usize) -> Vec<T> {
        (0..n).map(|_| self.read()).collect()
    }
    pub fn chars(&mut self) -> Vec<char> {
        self.read::<String>().chars().collect()
    }
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn test_io() {
        let input = br"10
        1 2 3 4 5 6 7 8 9 10
        abcde fghij
        
        3.14 -1592
        no_empty_line";
        let mut sc = IO::new(&input[..], Vec::new());

        let n: usize = sc.read();
        assert_eq!(n, 10);

        let a: Vec<u64> = sc.vec(n);
        assert_eq!(&a, &[1, 2, 3, 4, 5, 6, 7, 8, 9, 10]);

        let s = sc.chars();
        let t = sc.chars();
        assert_eq!(&s, &['a', 'b', 'c', 'd', 'e']);
        assert_eq!(&t, &['f', 'g', 'h', 'i', 'j']);

        let f: f64 = sc.read();
        assert_eq!(f, 3.14);

        let neg: i64 = sc.read();
        assert_eq!(neg, -1592);

        let s = sc.read::<String>();
        assert_eq!(&s, "no_empty_line");
        sc.write(format!("1\n"));

        let mut output = Vec::new();
        {
            let mut sc = IO::new(&b""[..], &mut output);
            sc.write(format!("{}\n", 1));
            sc.write(format!("{}\n", 2));
            sc.write(format!("{}\n", 3));
        }

        let output = String::from_utf8(output).expect("Not UTF-8");
        assert_eq!(&output, "1\n2\n3\n");
    }
}