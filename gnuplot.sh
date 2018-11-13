gnuplot << END_GNUPLOT
set ylabel "Nº Operaciones Basicas"
set xlabel "Tamaño"
set key right bottom
set grid
set term png

set output "ms Tamano-Obs.png"
plot "mergesort_ejercicio5.dat" using 1:3 with lines title 'mergesort Tamano - Media', \
    "mergesort_ejercicio5.dat" using 1:4 with lines title 'mergesort Tamano - Max', \
    "mergesort_ejercicio5.dat" using 1:5 with lines title 'mergesort Tamano - Min'
replot

set output "qs Tamano-Obs.png"
plot "quicksort_ejercicio5.dat" using 1:3 with lines title 'quicksort Tamano - Media' , \
    "quicksort_ejercicio5.dat" using 1:4 with lines title 'quicksort Tamano - Max', \
    "quicksort_ejercicio5.dat" using 1:5 with lines title 'quicksort Tamano - Min',
replot

set output "qs ms Tamano-Obs.png"
plot "quicksort_ejercicio5.dat" using 1:3 with lines title 'quicksort Tamano - Media' , \
    "quicksort_ejercicio5.dat" using 1:4 with lines title 'quicksort Tamano - Max', \
    "quicksort_ejercicio5.dat" using 1:5 with lines title 'quicksort Tamano - Min', \
    "mergesort_ejercicio5.dat" using 1:3 with lines title 'mergesort Tamano - Media', \
    "mergesort_ejercicio5.dat" using 1:4 with lines title 'mergesort Tamano - Max', \
    "mergesort_ejercicio5.dat" using 1:5 with lines title 'mergesort Tamano - Min'
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

quit
END_GNUPLOT
