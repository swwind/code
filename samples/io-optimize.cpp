// io 优(lie)化
// Copyright (c) zhzh2001

#include <bits/stdc++.h>
using namespace std;

namespace IOStream {
  class InputStream {
  private:
    static const size_t defaultBufsz = 1e6;
    FILE *stream;
    size_t bufsz;
    char *buf, *p;
    bool good;
    void fetch() {
      if (!buf)
        p = buf = new char [bufsz+1];
      size_t sz = fread(buf,1,bufsz,stream);
      p = buf;
      buf[sz] = '\0';
      good = sz;
    }
    char nextchar() {
      if (!*p) fetch();
      return *p++;
    }
    template <typename Int>
    void readint(Int& x) {
      char c;
      for (c = nextchar(); isspace(c); c = nextchar())
        ;
      x = 0;
      Int sign = 1;
      if (c == '-')
        sign = -1, c = nextchar();
      for (; isdigit(c); c = nextchar())
        x = x * 10 + c - '0';
      x *= sign;
    }
  public:
    InputStream():
    stream(NULL),
    bufsz(defaultBufsz),
    buf(NULL),
    p(NULL),
    good(false) {
    }
    explicit InputStream(const std::string& filename, size_t bufsz = defaultBufsz):
    stream(fopen(filename.c_str(), "r")),
    bufsz(bufsz),
    buf(NULL),
    p(NULL),
    good(false) {
      fetch();
    }
    explicit InputStream(FILE *stream, size_t bufsz = defaultBufsz):
    stream(stream),
    bufsz(bufsz),
    buf(NULL),
    p(NULL),
    good(false) {
      fetch();
    }
    bool close() {
      return !fclose(stream);
    }
    ~InputStream() {
      close();
      delete [] buf;
    }
    operator bool () const {
      return good;
    }
    bool operator ! () const {
      return !good;
    }
    bool open(const std::string& filename, size_t bufsz = defaultBufsz) {
      stream = fopen(filename.c_str(), "r");
      this -> bufsz = bufsz;
      fetch();
      return stream;
    }
    bool open(FILE *stream, size_t bufsz = defaultBufsz) {
      this -> stream = stream;
      this -> bufsz = bufsz;
      fetch();
      return stream;
    }
    InputStream& operator >> (short& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (unsigned short& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (int& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (unsigned int& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (long& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (unsigned long& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (long long& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (unsigned long long& value) {
      readint(value);
      return *this;
    }
    InputStream& operator >> (char& c) {
      for (c = nextchar(); isspace(c); c = nextchar())
        ;
      return *this;
    }
    InputStream& operator >> (std::string& s) {
      char c;
      for (c = nextchar(); isspace(c); c = nextchar())
        ;
      s.clear();
      for (; good && !isspace(c); c = nextchar())
        s += c;
      return *this;
    }
    friend InputStream& getline(InputStream& is, std::string& s, char delim = '\n');
  };
  InputStream& getline(InputStream& is, std::string& s, char delim) {
    char c;
    s.clear();
    for (c = is.nextchar(); is.good && c != delim; c = is.nextchar())
      s += c;
    return is;
  }

  class OutputStream {
  private:
    static const size_t defaultBufsz = 1e6;
    FILE *stream;
    size_t bufsz;
    char *buf, *p, dig[25];
  public:
    OutputStream():
    stream(NULL),
    bufsz(defaultBufsz),
    buf(NULL),
    p(NULL) {
    }
    explicit OutputStream(const std::string& filename, size_t bufsz = defaultBufsz):
    stream(fopen(filename.c_str(), "w")),
    bufsz(bufsz),
    buf(new char [bufsz]),
    p(buf){
    }
    explicit OutputStream(FILE *stream, size_t bufsz = defaultBufsz):
    stream(stream),
    bufsz(bufsz),
    buf(new char [bufsz]),
    p(buf){
    }
    bool close() {
      return !fclose(stream);
    }
    void flush() {
      fwrite(buf, 1, p - buf, stream);
      p = buf;
    }
  private:
    void writechar(char c) {
      *p ++ = c;
      if (p == buf + bufsz)
        flush();
    }
    template <typename Int>
    void writeint(Int x) {
      if (x < 0)
        writechar('-'), x = -x;
      int len = 0;
      do
        dig[++ len] = x % 10;
      while (x /= 10);
      for (; len; len --)
        writechar(dig[len] + '0');
    }
  public:
    ~OutputStream() {
      flush();
      close();
      delete [] buf;
    }
    bool open(const std::string& filename, size_t bufsz = defaultBufsz) {
      stream = fopen(filename.c_str(), "w");
      this -> bufsz = bufsz;
      delete [] buf;
      p = buf = new char [bufsz];
      return stream;
    }
    bool open(FILE *stream, size_t bufsz = defaultBufsz) {
      this -> stream = stream;
      this -> bufsz = bufsz;
      delete [] buf;
      p = buf = new char [bufsz];
      return stream;
    }
    OutputStream& operator << (short value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (unsigned short value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (int value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (unsigned int value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (long value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (unsigned long value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (long long value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (unsigned long long value) {
      writeint(value);
      return *this;
    }
    OutputStream& operator << (char c) {
      writechar(c);
      return *this;
    }
    OutputStream& operator << (const std::string& s) {
      for (size_t i = 0; i < s.length(); i++)
        writechar(s[i]);
      return *this;
    }
    OutputStream& operator << (OutputStream& (*func) (OutputStream&)) {
      return func(*this);
    }
    friend OutputStream& endl(OutputStream& os);
  };
  OutputStream& endl(OutputStream& os) {
    os.writechar('\n');
    return os;
  }
}

int main(int argc, char const *argv[]) {
	IOStream::InputStream fin(stdin);
	IOStream::OutputStream fout(stdout);
  int a, b;
  fin >> a >> b;
  fout << a + b << IOStream::endl;
  return 0;
}
