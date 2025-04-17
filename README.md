<h1>  
🚀 Space Shooter Game
 </h1>


<h2>🤝Made by Digital Dreamers</h2>
<br>

![Image](https://github.com/user-attachments/assets/4912025c-413c-4271-8815-b7d27415c82f)
<br>

<h2> 📝Description</h2>

Space Shooter is a console-based game where you control a spaceship to shoot at enemies, avoid collisions, and rack up a high score. The game features a simple yet engaging experience where you move left and right to avoid and shoot down enemies.

<h2> ✨ Features </h2>
<br>🚀 Move the spaceship left and right using the A and D keys.
<br>🔫 Shoot bullets with the spacebar.
<br>👾 Avoid enemies that move towards the spaceship.
<br>💥 Destroy enemies with bullet collisions.
<br>💀 Game Over screen when a collision happens.
<br>🏆 Score tracker to keep track of your score as you destroy enemies.
<br>

   <h2> 🎮 Controls</h2>
<br>➡️A: Move left.
<br>➡️D: Move right.
<br>➡️Space: Shoot bullets.
<br>➡️ESC: Quit the game.
<br>➡️1: Start the game.
<br>➡️2: View instructions.
<br>➡️3: Quit from the main menu.

<h2>  ▶️ How to Play</h2>
<br>➡️ Start the game by selecting the Start Game 🎮 option from the main menu.
<br>➡️Use A and D to move your spaceship left and right.
<br>➡️Shoot bullets using the Space key to destroy incoming enemies.
<br>➡️Avoid enemy ships. If an enemy touches your spaceship, the game ends.
<br>➡️Your score is updated each time you destroy an enemy.

<h2> 🧑‍🏫 Instructions</h2>
<br>➡️A: Move Left.
<br>➡️D: Move Right.
<br>➡️Space: Shoot 🔫.
<br>➡️Avoid enemies (👾) and stay alive as long as possible!

<h2>Function overview</h2>

<h3>📌 Console Handling Functions</h3>
<br>gotoxy(int x, int y)
<br>Moves the console cursor to the specified (x, y) position for drawing.
<br>setcursor(bool visible, DWORD size)
<br>Sets the visibility and size of the console cursor.

<h3>🎮 Game UI and Player Functions</h3>
<br>drawBorder()
<br>Draws the game boundary using special characters (±). Also marks the score and life area.
<br>drawBird()
<br>Displays the player character (the airplane) using emojis at its current horizontal position.
<br>eraseBird()
<br>Erases the player airplane from the screen before redrawing it in a new position.

<h3>👾 Enemy Functions</h3>
<br>genEnemy(int ind)
<br>Generates a new horizontal position for an enemy. ind is the enemy index (0 or 1).
<br>drawEnemy(int ind)
<br>Draws an enemy (👽) at its (x, y) position.
<br>eraseEnemy(int ind)
<br>Erases the enemy graphics from the screen.
<br>resetEnemy(int ind)
<br>Resets an enemy to the top of the screen with a new horizontal position.

<h3>🔫 Player Bullet Functions</h3>
<br>genBullet()
<br>Generates a pair of bullets (left and right) from the airplane's wings.
<br>moveBullet()
<br>Moves the bullets upward (toward the enemies). If they reach the top, they're deactivated.
<br>drawBullets()
<br>Displays all active bullets on the screen as ⚡.
<br>eraseBullets()
<br>Erases all bullets from their current positions before moving them.
<br>eraseBullet(int i)
<br>Erases a specific bullet by index i.

<h2> ♠️ Game Over</h2>
<br>The game ends when your spaceship collides with an enemy.<br> You will see a Game Over screen displaying your final score. <br>Press any key to return to the main menu.

<h2> ℹ️ Installation </h2>
<br>➡️Make sure you have a C++ compiler (e.g., GCC or Visual Studio).
<br>➡️Clone or download this repository.

<h2>⭕️Compilation and Execution</h2>

1. Clone the repository:
   ```bash
   https://github.com/VivekAmipara05/Shooter-Game
   ```
2. Navigate to the project directory:
   ```bash
   cd Shooter-game
   ```
3. Compile using g++:
   ```bash
   g++ Shooter.cpp -o code.exe
   ```
4. Run the game:
   ```bash
   ./code.exe
   ```

<h2> 🌼Dependencies</h2>

<br>➡️ Windows: This game uses Windows-specific libraries, such as <conio.h> and <windows.h>, which are available on Windows systems.

<h2> 📒 Notes</h2>

<br>➡️Make sure your console window is large enough to fit the game (recommendation: at least 90x26 characters).
<br>➡️Emoji characters are supported in the console if your system supports UTF-8 encoding.
## 📈Improvements to be done:-
  1. Dynamic Difficulty
  2. Graphics
  3. Recording HighScore via file Handling
     

## 👉original source:
  <a href= https://github.com/AngularsCoding/Space-Shooter>Source</a><br>
  
<h2>⭕️Github</h2>
<a href="https://github.com/Yug-Gabani" style="text-decoration: none; display: block;">Yug_Gabani</a><br>
<a href="https://github.com/hetpatel06" style="text-decoration: none; display: block;">Het_Bhungaliya</a><br>
<a href="https://github.com/shyambhuva" style="text-decoration: none; display: block;">Shyam_Bhuva</a><br>
<a href="https://github.com/VivekAmipara05" style="text-decoration: none; display: block;">Vivek_Amipara</a><br>





