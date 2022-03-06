project('admiratium', 'c',
  version : '0.1',
  default_options : ['warning_level=3'])


# Subdirectory 'src': All Source Files
subdir('src')

# Create an Executable
exe = executable(
  'admiratium',
  src_files,
  install : true
)

test('basic', exe)
