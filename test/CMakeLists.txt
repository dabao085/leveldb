cmake_minimum_required(VERSION 3.9)

function(configure_leveldb_test target_name)
  target_include_directories(${target_name}
      PRIVATE
      ${PROJECT_SOURCE_DIR}/include
      ${PROJECT_BINARY_DIR}
      ${PROJECT_BINARY_DIR}/include
      )

  target_link_libraries(${target_name}
      PRIVATE
      leveldb
      pthread
      snappy
      )
endfunction()

add_executable(write_test test.cc)
target_compile_definitions(write_test PRIVATE WRITE_MODE)
configure_leveldb_test(write_test)

add_executable(read_test test.cc)
configure_leveldb_test(read_test)

add_executable(log_writer_test log_writer_test.cc)
configure_leveldb_test(log_writer_test)

add_executable(block_builder_test block_builder_test.cc)
configure_leveldb_test(block_builder_test)