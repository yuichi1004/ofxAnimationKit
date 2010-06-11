#!/opt/local/bin/gnuplot -persist
#
#    
#    	G N U P L O T
#    	Version 4.2 patchlevel 5 
#    	last modified Mar 2009
#    	System: Darwin 10.3.0
#    
#    	Copyright (C) 1986 - 1993, 1998, 2004, 2007 - 2009
#    	Thomas Williams, Colin Kelley and many others
#    
#    	Type `help` to access the on-line reference manual.
#    	The gnuplot FAQ is available from http://www.gnuplot.info/faq/
#    
#    	Send bug reports and suggestions to <http://sourceforge.net/projects/gnuplot>
#    
set terminal png size 300,300 font 'Times' 8
set xlabel "t" 0,0
set ylabel "f (t)" 2,0
set xrange [0:1]
set yrange [0:1]
set nokey
set size square
set grid
set sample 10000

set lmargin 4.5 
set tmargin 1 
set rmargin 0.5
set bmargin 4 

set output "function_linear.png"
f(x)=x
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeIn.png"
f(x)=x*x
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeOut.png"
f(x)=2*x-x*x
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeInOut.png"
f(x)=3*x*x-2*x*x*x
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeInCubic.png"
f(x)=x*x*x
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeOutCubic.png"
f(x)=(-x*x*x+3*x)/2
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_easeInOutCubic.png"
f(x)=x<0.5?(2*x*2*x*2*x)/2: 0.5+(-2*(x-0.5)*2*(x-0.5)*2*(x-0.5)+3*2*(x-0.5))/4
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

set output "function_bounce.png"
f(x)=x<1.0/2.75?7.5625*x*x: x<2.0/2.75?7.5625*(x-1.5/2.75)*(x-1.5/2.75)+0.75: x<2.5/2.75?7.5625*(x-2.25/2.75)*(x-2.25/2.75)+0.9375: 7.5625*(x-2.625/2.75)*(x-2.625/2.75)+.984375
plot f(x) title "f(t)" lw 3 lc rgbcolor "#0000cd"

#    EOF
