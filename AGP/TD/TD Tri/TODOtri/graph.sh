function usage
{
    echo "Basic usage $0 <option> "
    echo "NB: option can be "
    echo "\t 0 (increasing order)"
    echo "\t 9 (decreasing order)"
    echo "\t 5 (random)"
}

if [ $# -ne 1 ]
then 
    usage
    exit 1
fi

case $1 in
    0) 
	./benchmark 0 > data ;;
    9)
	./benchmark 9 > data ;;
    5)
	./benchmark d number.data > data ;;
    *)
	usage
	exit 1
esac

gnuplot graph.gnuplot
rm -f data
echo "Done. See graph.svg."

exit 0