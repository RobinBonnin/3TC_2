set terminal svg
set output "graph.svg"
set title "Tps d'execution des tris à bulle, fusion et rapide"
set xlabel "Taille du tableau"
set ylabel "Tps (ms)"
plot "data" using 1:2 title "bulle" with lines, "data" using 1:3 title "fusion" with lines, "data" using 1:4 title "rapide" with lines 
