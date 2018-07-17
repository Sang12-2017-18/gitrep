Commands used:
     
     git config user.name "MyUserName"
     git config user.email "***@example.com"
     mkdir gitrep
After moving to gitrep:
     
     git init
     touch readme
     git commit -m "first commit"
     git remote add origin https://github.com/<Username>/gitrep.git.
After this command, I created a gitrep repository in the website.Then I typed this:
     
     git push -u origin master

My file got uploaded to github with the following output:

     Username for 'https://github.com': Sang12-2017-18
     Password for 'https://<MyUsername>@github.com': 
      Counting objects: 3, done.
     Writing objects: 100% (3/3), 217 bytes | 0 bytes/s, done.
     Total 3 (delta 0), reused 0 (delta 0)
     To https://github.com/<MyUserName>/gitrep.git
     * [new branch]      master -> master
     Branch master set up to track remote branch master from origin.
     
I can now operate github from terminal!
