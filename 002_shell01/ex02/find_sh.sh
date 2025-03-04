find . -type f -name '*.sh' -execdir basename -s '.sh' {} +
# finds only files, of .sh extension, extracts only basename without .sh and runs the command in batch mode