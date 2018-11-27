gnuplot << END_GNUPLOT
set ylabel "Nº Operaciones Basicas"
set xlabel "Tamaño"
set key right bottom
set grid
set term png

set output "Bbin Tamano-Obs.png"
plot "bbin_1000_10000_10_10.dat" using 1:3 with lines title 'Bbin Tamano - Media', \
    "bbin_1000_10000_10_10.dat" using 1:4 with lines title 'Bbin Tamano - Max', \
    "bbin_1000_10000_10_10.dat" using 1:5 with lines title 'Bbin Tamano - Min'
replot

set output "Blin Tamano-Obs.png"
plot "blin_1000_10000_10_10.dat" using 1:3 with lines title 'Blin Tamano - Media', \
    "blin_1000_10000_10_10.dat" using 1:4 with lines title 'Blin Tamano - Max', \
    "blin_1000_10000_10_10.dat" using 1:5 with lines title 'Blin Tamano - Min'
replot

set output "Blin NO_ORDENADO Tamano-Obs.png"
plot "blin_NO_ORDENADO_1000_10000_10_10.dat" using 1:3 with lines title 'Blin NO_OR Tamano - Media', \
    "blin_NO_ORDENADO_1000_10000_10_10.dat" using 1:4 with lines title 'Blin NO_OR Tamano - Max', \
    "blin_NO_ORDENADO_1000_10000_10_10.dat" using 1:5 with lines title 'Blin NO_OR Tamano - Min'
replot


set ylabel "Tiempo (ns)"
set xlabel "Tamaño"

set output "ms Tamano-Tiempo.png"
plot "mergesort_ejercicio5.dat" using 1:2 with lines title 'mergesort Tamano - Tiempo'
replot

set output "qs Tamano-Tiempo.png"
plot "quicksort_ejercicio5.dat" using 1:2 with lines title 'quicksort Tamano - Tiempo'
replot

set output "qs ms Tamano-Tiempo.png"
plot "quicksort_ejercicio5.dat" using 1:2 with lines title 'quicksort Tamano - Tiempo' , \
    "mergesort_ejercicio5.dat" using 1:2 with lines title 'mergesort Tamano - Tiempo'
replot

set output "qs_src Tamano-Tiempo.png"
plot "quicksort_src_ejercicio5.dat" using 1:2 with lines title 'quicksort_src Tamano - Tiempo'
replot

set output "qs qs_src Tamano-Tiempo.png"
plot "quicksort_ejercicio5.dat" using 1:2 with lines title 'quicksort Tamano - Tiempo' , \
    "quicksort_src_ejercicio5.dat" using 1:2 with lines title 'quicksort_src Tamano - Tiempo'
replot

quit
END_GNUPLOT
