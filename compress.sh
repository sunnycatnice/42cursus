#compress a folder passed as an argument

def_dir="$1"
tar_dir="$2"

tar -czf $tar_dir $def_dir
