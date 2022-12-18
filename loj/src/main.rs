use std::{fmt::Display, io};

#[derive(Debug, Clone, PartialEq, Eq)]
enum Regex {
  C0,
  C1,
  Or(Vec<Regex>),
  Concat(Vec<Regex>),
  Star(Box<Regex>),
}

impl Regex {
  const NONE: Regex = Regex::Or(vec![]);
  const EPSILON: Regex = Regex::Concat(vec![]);
}

impl Display for Regex {
  fn fmt(&self, f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
    match self {
      Regex::C0 => write!(f, "0"),
      Regex::C1 => write!(f, "1"),
      Regex::Or(rx) => write!(
        f,
        "({})",
        rx.iter()
          .map(|x| format!("{x}"))
          .collect::<Vec<_>>()
          .join("|")
      ),
      Regex::Concat(rx) => write!(
        f,
        "{}",
        rx.iter().map(|x| format!("{x}")).collect::<String>()
      ),
      Regex::Star(rx) => match **rx {
        Regex::Or(_) | Regex::C0 | Regex::C1 => write!(f, "{rx}*"),
        _ => write!(f, "({rx})*"),
      },
    }
  }
}

fn make_or(or: Vec<Regex>) -> Regex {
  let vec = or
    .into_iter()
    .flat_map(|x| match x {
      Regex::Or(rx) => rx,
      rx => vec![rx],
    })
    .collect::<Vec<_>>();

  if vec.len() == 1 {
    vec.into_iter().next().unwrap()
  } else {
    Regex::Or(vec)
  }
}

fn make_star(regex: Regex) -> Regex {
  match regex {
    Regex::Star
    Regex::Star(rx) => Regex::Star(rx),
    rx => Regex::Star(Box::new(rx)),
  }
}

fn make_concat(concat: Vec<Regex>) -> Regex {
  let vec = concat
    .into_iter()
    .flat_map(|x| match x {
      Regex::Concat(rx) => rx,
      Regex::Epsilon => vec![],
      rx => vec![rx],
    })
    .collect::<Vec<_>>();

  if vec.is_empty() {
    Regex::Epsilon
  } else if vec.iter().any(|x| x == &Regex::None) {
    Regex::None
  } else if vec.len() == 1 {
    vec.into_iter().next().unwrap()
  } else {
    Regex::Concat(vec)
  }
}

fn main() {
  // let n = 2;
  let mut string = String::new();
  io::stdin().read_line(&mut string).unwrap();
  let n = string.trim().parse().unwrap();

  let mut matrix = vec![vec![Regex::None; n]; n];
  (0..n).for_each(|x| matrix[x][x] = Regex::Epsilon);

  // initialize
  (0..n).for_each(|x| {
    matrix[x][x * 2 % n] = Regex::C0;
    matrix[x][(x * 2 + 1) % n] = Regex::C1;
  });

  // floyd
  for k in 0..n {
    for i in 0..n {
      for j in 0..n {
        if !is_none(&matrix[i][k]) && !is_none(&matrix[k][j]) {
          matrix[i][j] = make_or(vec![
            matrix[i][j].clone(),
            make_concat(vec![
              matrix[i][k].clone(),
              make_star(matrix[k][k].clone()),
              matrix[k][j].clone(),
            ]),
          ]);
        }
      }
    }
  }

  // println!("{:?}", matrix[0][0]);
  println!("{}", matrix[0][0]);
}
