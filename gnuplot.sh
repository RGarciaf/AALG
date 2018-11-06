gnuplot << END_GNUPLOT
set ylabel "Nº Operaciones Basicas"
set xlabel "Tamaño"
set key right bottom
set grid
set term png

set output "SelectSort Tamano-Obs.png"
plot "SelectSort_ejercicio5.dat" using 1:3 with lines title 'SelectSort Tamano - Media' , \
    "SelectSort_ejercicio5.dat" using 1:4 with lines title 'SelectSort Tamano - Max', \
    "SelectSort_ejercicio5.dat" using 1:5 with lines title 'SelectSort Tamano - Min', \
    "SelectSortInv_ejercicio5.dat" using 1:3 with lines title 'SelectSortInv Tamano - Media', \
    "SelectSortInv_ejercicio5.dat" using 1:4 with lines title 'SelectSortInv Tamano - Max', \
    "SelectSortInv_ejercicio5.dat" using 1:5 with lines title 'SelectSortInv Tamano - Min'
replot

set ylabel "Tiempo (ns)"
set xlabel "Tamaño"
set output "SelectSort Tamano-Tiempo.png"
plot "SelectSort_ejercicio5.dat" using 1:2 with lines title 'SelectSort Tamano - Tiempo' , \
    "SelectSortInv_ejercicio5.dat" using 1:2 with lines title 'SelectSortInv Tamano - Tiempo'
replot

quit
END_GNUPLOT
