# Reflection



## Part 0 – Run the Starter Code
What do the two nested for loops over x and y represent in the program?
- The x and y in the nested loop are providing the size of the image.

## Part 1 – Find the Color Logic
Add a short comment near that section explaining what it does in your own words.
- Commented in line 39 in main.cpp.

## Part 2 – Choose ONE Color Option
Option A – Fixed Color Palette Using C-Style Arrays

## Part 3 – Reflection
1. We chose option A.
2. We used three C-style arrays (red[], green[], blue[]) with size 5 to store RGB color values that map iteration counts to palette colors.
3. It creates colorful rings around the fractal based on how fast pixels escape—without it, you'd just see a flat, boring single color.
4. The tricky part was figuring out how to iterate through the color arrays correctly—using the modulo operator to cycle through the palette indices so each iteration value maps to a specific RGB color.