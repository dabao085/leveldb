#include "db/log_writer.h"

#include <iostream>

#include "leveldb/env.h"

#include "util/coding.h"

int main() {
  std::string file_name("log_writer.data");

  leveldb::WritableFile* file;
  leveldb::Status s =
      leveldb::Env::Default()->NewWritableFile(file_name, &file);

  leveldb::log::Writer writer(file);

  // 字符串长度10(即0x0a)
  const std::string data = "HelloWorld";
  s = writer.AddRecord(data);
  std::cout << s.ToString() << std::endl;

  delete file;

  return 0;
}