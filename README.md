txt_to_obj.c
 - Reads heightgrid/heightmap from keyboard input (decimal numbers with space in between: "1.37 5.18 2.3748 0.93 ") and converts it to an .obj file (3D model file) (the .obj file contents are written to standard output)

IMPORTANT: You must end every row with "666", and end the whole input with anything higher than or equal to "999". This is obviously stupid but I've also tried to make the code simple enough for you to understand how to change this yourself.

Max size of terrain is now 64x64, you can change that in the variables "vertexno" and "rowstart" in the code.

/kbrecordzz 2022
License: CC0
