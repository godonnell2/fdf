fdf: Wireframes So Good, They're Almost 3D! (But Not Quite)

What is this sorcery?!
fdf  "Fil De Fer," which is French for "wireframe" – ) takes a simple numerical map and transforms it into an isometric projection. Its a retro way to visualize terrain,.

Features 
Reads .fdf files: B
Isometric Projection: Makes everything look angled. So that the data is easier to understand as a visualisation.
Adjustable Zoom
Colors
Height Scaling

Getting Started 
Clone this repo:

Bash

git clone https://github.com/your-username/fdf.git
(Replace your-username with your actual username, unless you are "your-username," in which case, well played.)

Compile the magic:

Bash

make
This incantation will summon the executable fdf from the ether.

Run it with your map:

Bash

./fdf maps/42.fdf
Replace maps/42.fdf with your own .fdf file. it needs to be a grid of numbers, separated by spaces.

Example .fdf file (because we're not monsters):
0 0 0 0 0
0 5 10 5 0
0 10 20 10 0
0 5 10 5 0
0 0 0 0 0

Controls (Because Mice and Keyboards Are a Thing)
Move: Arrow keys ( ↑ ↓ ← → ) - Wiggle your wireframe around the screen.

Zoom: + / - - Get up close and personal, or take a step back.


Height: [ / ] - Make those peaks taller or shorter. Sculpt your digital landscape!

Exit: ESC - H

Contributing 
Found a bug? H? Feel free to fork, clone, and send pull requests! 


