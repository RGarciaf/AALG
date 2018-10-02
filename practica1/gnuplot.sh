gnuplot << END_GNUPLOT
set key right bottom
set grid
set term png
set output "Tamano-Obs.png"
plot "ejercicio5.dat" using 1:3 with lines title 'Tamano - Media' , "ejercicio5.dat" using 1:4 with lines title 'Tamano - Max', "ejercicio5.dat" using 1:5 with lines title 'Tamano - Min'
replot
quit
END_GNUPLOT
