#!/usr/bin/env gnuplot
load 'moreland.pal'
set terminal pdf size 15,10 enhanced
set output 'circles.pdf'
set view map
unset key
unset surface
set contour base
set pm3d
unset clabel
splot 'circles.dat' using 1:2:3 with lines lw 1
