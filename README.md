# learn-git
learn how to use git on terminal

# git commands  
git status   
git add .  
git commit -m 'some text explaining this commit'  
git push  
pit pull  
gitk  
git checkout <branch_to_checkout_to>  
git clone <link>  
git fetch --prune  
git pull --prune  
git merge --no-ff feature-x  

# 🚀 Meine Git Start-Routine
1. Den Status prüfen (Der Blick in den Briefkasten)  
`git fetch`  
Lädt die Änderungen vom Server, ohne den eigenen Code zu berühren.  

2. Was hat der Kollege gemacht?  
`git status`  
**Optional:** Zeigt die Commit-Nachrichten des Kollegen  
`git log --oneline main..origin/main`  

3. Änderungen sauber einfügen  
Falls du noch keine eigenen neuen Commits hast: `git pull`  
Falls du schon lokal gearbeitet/committet hast (hält die Historie linear): `git pull --rebase`

# `pull` vs. `fetch`
Kurz gesagt: `git pull` ist ungeduldig, `git fetch` ist vorsichtig.  

Der technische Unterschied  
Man kann es sich wie einen Postdienst vorstellen:  

`git fetch` (Der Blick in den Briefkasten)  
Git schaut beim Server (GitHub) vorbei und fragt: "Gibt es was Neues?". Wenn ja, lädt er die Informationen und neuen Dateien herunter, aber er verändert deine Arbeit nicht. Er legt die neuen Sachen in einen versteckten Bereich (den sogenannten origin/main Pointer). Du kannst dann in Ruhe prüfen, was der Kollege gemacht hat, bevor du es in deinen Code lässt.  

`git pull` (Das Paket sofort aufreißen)  
git pull ist eigentlich eine Kombination aus zwei Befehlen: `git fetch` + `git merge` (oder `rebase`). Er lädt die Daten nicht nur herunter, sondern versucht sofort, sie mit deinem aktuellen Stand zu vermischen.  

# Git Feature Branch Workflow
1. Create a new branch (from main)
```
git checkout main
git pull --prune # make sure main is up-to-date
git checkout -b feature-x
```
👉 You now have a local feature-x branch.

2. Work on the branch
```
# edit files...
git add .
git commit -m "Add my feature"
```
Repeat as needed.

3. Push branch to GitHub (so others see it)
```
git push -u origin feature-x
```
👉 Creates the branch on GitHub and sets up tracking.

4. Merge the branch (after review / PR)
Either via GitHub Pull Request (common in teams).
Or locally:
```
git checkout main
git pull --prune            # update main
git merge feature-x         # merge your work
git merge --no-ff feature-x # to have the side line bending effect in GitKraken
git push                    # update GitHub
```

5. Clean up
a) Delete your local branch (safe if merged):
```
git branch -d feature-x
```
make sure it's deleted on git-hub (remote) as well! Must be done manually online on git-hub or has been done automated during pull request.   

b) Delete the remote branch (if you created it):
```
git fetch --prune
```
✅ After step 5, your repo is tidy again — no clutter, only active branches remain.

⚡ Tip: In GitKraken, these same steps are:
Right-click → Create branch from main
Commit changes visually
Push branch → creates it on GitHub
Merge PR → GitHub cleans up automatically (if you check the “delete branch” box)
Fetch + prune → clears stale remote references

# How to check your upstream (this is the key command)
Run:
```
git branch -vv
```

You should see something like:

```css
* main  a1b2c3d [origin/main] Commit message
```

That [origin/main] part is crucial.
✅ Present → git push works
❌ Missing → Git doesn’t know where to push

# How to synch Remote and Local in case they have different states
Given the situation that one branch (e.g. main) has commits that are not on your local copy but you also have commits which are not added and commited to remote.  

## Option 1: Der saubere Weg (Stash & Pull)
Diese Methode ist am sichersten, da sie deine aktuellen (ungespeicherten) Änderungen kurzzeitig "parkt", die Änderungen deines Kollegen holt und deine Arbeit dann wieder oben drauf legt. 

Änderungen zwischenparken:
```
git stash
```
(Dies räumt dein Arbeitsverzeichnis auf und speichert deine Änderungen in einem temporären Speicher.)

Updates vom Server holen:
```
git pull origin main
```
Deine Änderungen zurückholen:
```
git stash pop
```
Normal weitermachen:
Jetzt kannst du wie gewohnt git add ., git commit -m "..." und git push ausführen.

## Option 2: Erst Committen, dann Rebase (Best Practice)
Wenn du deine Arbeit lieber direkt dokumentieren willst, bevor du die Sachen vom Kollegen ziehst:

Lokal committen:
```
git add .
git commit -m "Mein aktueller Stand"
```
Mit Rebase ziehen:
```
git pull --rebase origin main
```
Warum --rebase? Es nimmt deinen neuen Commit, setzt ihn kurz beiseite, holt die Änderungen vom Kollegen und setzt deinen Commit dann ans Ende der Kette. Das hält die Historie sauber und linear.  

Hochladen:
```
git push origin main
```
**Tipp:** Nutze Option 1, wenn deine Änderungen noch sehr "unfertig" sind, und Option 2, wenn du eigentlich bereit zum Pushen wärst.

Das einfache `git push` funktioniert auch. Git ist heute sehr schlau vorkonfiguriert ist. In der Standardeinstellung geht Git davon aus, dass dein aktueller Branch (in deinem Fall main) auf den gleichnamigen Branch beim Standard-Server (origin) hochgeladen werden soll. Das Kommando `git push` ist also quasi die Kurzform von `git push origin main`.  

Warum Option 2 (Rebase) so gut ist
Durch den Befehl `git pull --rebase` wird verhindert, dass im Verlauf ein unnötiger „Merge-Commit“ (wie z. B. "Merge branch 'main' of github.com...") entsteht.  

Stattdessen die Historie jetzt so aus, als hättest deine Arbeit erst begonnen, nachdem der Kollege seine Dateien hochgeladen hatte. Das hält den Branch sauber und übersichtlich. 

## 💡 Profi-Tipp
Solltest du mal mitten in einer Arbeit stecken und der `pull` verweigert den Dienst, weil du ungespeicherte Änderungen hast, merk dir das "Parkmanöver":
- `git stash` (Arbeit kurz wegpacken)
- `git pull` (Updates holen)
- `git stash pop` (Arbeit wieder herausholen)














