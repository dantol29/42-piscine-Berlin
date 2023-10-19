find . -name "*.sh" -printf "%f\n"  | sed 's|.sh$||' 
