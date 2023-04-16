git init
git add .
git commit -m "$(date +'%H:%M:%S') commit"
git branch -M main
git remote add origin git@github.com:jirahandler/susy_r21_ana_tools
git push -u origin main