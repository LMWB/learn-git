# learn-git
learn how to use git and test, commands, commits and rollbacks

# git commands
git status   
git add .  
git commit -m 'some text explaining this commit'  
git push
git push  
pit pull  
gitk  
git checkout <branch_to_checkout_to>  
git clone <link>
git fetch --prune
git pull --prune

git merge --no-ff feature-x


📝 Git Feature Branch Workflow (Cheat-Sheet)
1. Create a new branch (from main)
git checkout main
git pull --prune         # make sure main is up-to-date
git checkout -b feature-x
👉 You now have a local feature-x branch.
2. Work on the branch
# edit files...
git add .
git commit -m "Add my feature"
Repeat as needed.
3. Push branch to GitHub (so others see it)
git push -u origin feature-x
👉 Creates the branch on GitHub and sets up tracking.
4. Merge the branch (after review / PR)
Either via GitHub Pull Request (common in teams).
Or locally:
git checkout main
git pull --prune            # update main
git merge feature-x         # merge your work
git merge --no-ff feature-x # to have the side line bending effect in GitKraken
git push                    # update GitHub
5. Clean up
a) Delete your local branch (safe if merged):
git branch -d feature-x
b) Delete the remote branch (if you created it):
git fetch --prune
✅ After step 5, your repo is tidy again — no clutter, only active branches remain.

⚡ Tip: In GitKraken, these same steps are:
Right-click → Create branch from main
Commit changes visually
Push branch → creates it on GitHub
Merge PR → GitHub cleans up automatically (if you check the “delete branch” box)
Fetch + prune → clears stale remote references