use postgres::{Client, NoTls, Row};

#[derive(Clone, Debug, Default)]
struct Student {
  sno: i32,
  sname: String,
  ssex: String,
  sage: i32,
  saddr: String,
}

impl From<Row> for Student {
  fn from(row: Row) -> Self {
    Self {
      sno: row.get(0),
      sname: row.get(1),
      ssex: row.get(2),
      sage: row.get(3),
      saddr: row.get(4),
    }
  }
}

struct Database {
  client: Client,
}

impl Database {
  fn new() -> Self {
    let mut client = Client::connect("postgresql://test@localhost:5432/sqlexpr", NoTls).unwrap();

    client
      .batch_execute(
        r#"
CREATE TABLE IF NOT EXISTS Student (
  SNO    INT NOT NULL,
  SNAME  VARCHAR(255) NOT NULL,
  SSEX   VARCHAR(8) NOT NULL,
  SAGE   INT NOT NULL,
  SADDR  VARCHAR(255) NOT NULL,
  PRIMARY KEY (SNO),
  CHECK (SSEX = 'M' or SSEX = 'F'),
  CHECK (SAGE > 0)
)
"#,
      )
      .unwrap();

    Self { client }
  }

  fn insert(&mut self, student: &Student) {
    self
      .client
      .execute(
        "INSERT INTO Student(SNO, SNAME, SSEX, SAGE, SADDR) VALUES ($1, $2, $3, $4, $5)",
        &[
          &student.sno,
          &student.sname,
          &student.ssex,
          &student.sage,
          &student.saddr,
        ],
      )
      .unwrap();
  }

  fn delete_by_sno(&mut self, sno: &i32) {
    self
      .client
      .execute("DELETE FROM Student WHERE SNO = $1", &[sno])
      .unwrap();
  }

  fn search_addr(&mut self, addr: &String) -> Vec<Student> {
    self
      .client
      .query(
        "SELECT SNO, SNAME, SSEX, SAGE, SADDR FROM Student WHERE SADDR LIKE $1",
        &[addr],
      )
      .unwrap()
      .into_iter()
      .map(|row| row.into())
      .collect()
  }
}

impl Default for Database {
  fn default() -> Self {
    Self::new()
  }
}

use iced::{button, text_input, window, Alignment, Button, Sandbox, Settings, Text, TextInput};

#[derive(Default)]
struct GUI {
  database: Database,
  students: Vec<(Student, button::State)>,
  search_button: button::State,
  insert_button: button::State,

  sno_input: text_input::State,
  sname_input: text_input::State,
  ssex_input: text_input::State,
  sage_input: text_input::State,
  saddr_input: text_input::State,

  search_input: text_input::State,

  student_sno: String,
  student_sname: String,
  student_ssex: String,
  student_sage: String,
  student_saddr: String,

  search_string: String,
}

#[derive(Debug, Clone)]
enum Message {
  InsertStudent,
  DeleteStudent(i32),
  SearchStudent,
  SetStudentSno(String),
  SetStudentSname(String),
  SetStudentSsex(String),
  SetStudentSage(String),
  SetStudentSaddr(String),
  SetSearchString(String),
}

impl Sandbox for GUI {
  type Message = Message;

  fn new() -> Self {
    Self::default()
  }

  fn title(&self) -> String {
    "Naive you guys".into()
  }

  fn update(&mut self, message: Self::Message) {
    match message {
      Message::SearchStudent => {
        self.students = self
          .database
          .search_addr(&self.search_string)
          .into_iter()
          .map(|student| (student, button::State::default()))
          .collect()
      }
      Message::DeleteStudent(sno) => {
        self.database.delete_by_sno(&sno);
        self.students = self
          .students
          .iter()
          .cloned()
          .filter(|(student, _)| student.sno != sno)
          .collect()
      }
      Message::SetStudentSno(sno) => self.student_sno = sno,
      Message::SetStudentSname(sname) => self.student_sname = sname,
      Message::SetStudentSsex(ssex) => self.student_ssex = ssex,
      Message::SetStudentSage(sage) => self.student_sage = sage,
      Message::SetStudentSaddr(saddr) => self.student_saddr = saddr,
      Message::InsertStudent => self.database.insert(&Student {
        sno: self.student_sno.parse().unwrap_or(0),
        sname: self.student_sname.clone(),
        ssex: self.student_ssex.clone(),
        sage: self.student_sage.parse().unwrap_or(0),
        saddr: self.student_saddr.clone(),
      }),
      Message::SetSearchString(search) => self.search_string = search,
    }
  }

  fn view(&mut self) -> iced::Element<'_, Self::Message> {
    use iced::{Column, Row};

    let mut student_column = Column::new().align_items(Alignment::Start);

    for (student, delete_button) in self.students.iter_mut() {
      student_column = student_column.push(
        Row::new()
          .spacing(20)
          .push(Text::new(format!("{}", student.sno)))
          .push(Text::new(format!("{}", student.sname)))
          .push(Text::new(format!("{}", student.ssex)))
          .push(Text::new(format!("{}", student.sage)))
          .push(Text::new(format!("{}", student.saddr)))
          .push(
            Button::new(delete_button, Text::new("Delete"))
              .on_press(Message::DeleteStudent(student.sno)),
          ),
      )
    }

    Column::new()
      .padding(20)
      .spacing(20)
      .push(
        Row::new()
          .spacing(20)
          .push(
            TextInput::new(&mut self.sno_input, "sno", &self.student_sno, |sno| {
              Message::SetStudentSno(sno)
            })
            .padding(5),
          )
          .push(
            TextInput::new(
              &mut self.sname_input,
              "sname",
              &self.student_sname,
              |sname| Message::SetStudentSname(sname),
            )
            .padding(5),
          )
          .push(
            TextInput::new(&mut self.ssex_input, "ssex", &self.student_ssex, |ssex| {
              Message::SetStudentSsex(ssex)
            })
            .padding(5),
          )
          .push(
            TextInput::new(&mut self.sage_input, "sage", &self.student_sage, |sage| {
              Message::SetStudentSage(sage)
            })
            .padding(5),
          )
          .push(
            TextInput::new(
              &mut self.saddr_input,
              "saddr",
              &self.student_saddr,
              |saddr| Message::SetStudentSaddr(saddr),
            )
            .padding(5),
          )
          .push(
            Button::new(&mut self.insert_button, Text::new("Insert"))
              .on_press(Message::InsertStudent),
          ),
      )
      .push(
        Row::new()
          .spacing(20)
          .push(
            TextInput::new(
              &mut self.search_input,
              "search address",
              &self.search_string,
              |search| Message::SetSearchString(search),
            )
            .padding(5),
          )
          .push(
            Button::new(&mut self.search_button, Text::new("Search"))
              .on_press(Message::SearchStudent),
          ),
      )
      .push(student_column)
      .into()
  }
}

fn main() -> iced::Result {
  GUI::run(Settings {
    window: window::Settings {
      size: (500, 500),
      ..Default::default()
    },
    ..Default::default()
  })
}
