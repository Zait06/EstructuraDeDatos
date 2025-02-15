#!/bin/bash

# Define the function
flag_in_array() {
  local search_string="$1"  # The string to search for
  shift                     # Shift to skip the first argument (the search string)
  local array=("$@")        # The rest of the arguments are the array elements

  # Loop through the array
  for element in "${array[@]}"; do
    if [[ "$element" == "$search_string" ]]; then
      return 0  # String found, return success (0)
    fi
  done

  return 1  # String not found, return failure (1)
}

msg_error() {
  message="Usage:\n\t$0 "
  for struct in "${structures[@]}"; do
    message+="[-${struct,,}] "
  done
  message+="[-all]"
  echo -e "${message}"
}

rm -rf build/
mkdir build/

structures=(
  'STATIC_STACK'
  'DYNAMIC_STACK'
  'STATIC_QUEUE'
  'DYNAMIC_QUEUE'
)

if [ $# -eq 0 ]; then
  echo "No arguments"
  msg_error
  exit 0
fi

flags=()
if flag_in_array "-all" "$@"; then
  echo "all is in the array."
  for struct in "${structures[@]}"; do
    flags+=("-D${struct}=ON")
  done
  echo "cmake -B build/ -S . -GNinja ${flags[*]}"
  cmake -B build/ -S . -GNinja "${flags[@]}"
  exit 0$
fi

for flag in "$@"; do
  name="${flag^^}"
  name="${name:1}"
  if flag_in_array "$name" "${structures[@]}"; then
    echo $name
    flags+=("-D${name}=ON")
  fi
done

if [ ${#flags[@]} -eq 0 ]; then
  echo "Unknown option: $@"
  msg_error
  exit 0
fi

echo "cmake -B build/ -S . -GNinja ${flags[*]}"
cmake -B build/ -S . -GNinja "${flags[@]}"

exit 0

