#!/usr/bin/env gnuplot
unset sur
set contour
set cntrparam levels 10
set view 0,0
splot 'circles.dat' using 1:2:3 with lines lw 2 
pause -1 "Hit return to continue"
