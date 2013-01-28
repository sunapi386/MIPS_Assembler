#/bin/bash

clear
echo "Github"
read -p "Commit message: " commitMsg
git add .
git commit -m "${commitMsg}"
git push
