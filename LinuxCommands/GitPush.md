# Pushing local project files into github
1. First clone the repository that you want work on.
2. Open the cloned repository.
3. Initialize the respoitory into github using >> git init.
4. Initialize the to add the files using >> git add .
5. Commit the changes you've made using >> git commit -m "xxx changes"
6. Upload the changes you've made using >> git push origin branch(usually master)
7. Login with your credentials and Done!
8. Repeat 4,5,6,7 everytime you commit the changes 

# Merging Repositories into one.
1. First clone the repository that you want to merge into.
2. Open the cloned repository.
3. Use command >> git subtree add -P DirectoryName RepositoryYouWantToMergeURL.git master
4. Commit the changes you've made using >> git commit -m "xxx changes"
5. Upload the changes you've made using >> git push origin branch(usually master)
6. Delete the old repository.
