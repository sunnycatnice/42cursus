#tests for replace
echo "--------- test 1 -------"
echo "./replace divinacommedia.txt di ciao"
./replace divinacommedia.txt di ciao
echo divinacommedia.txt.replace | grep ciao
echo "------------------------"
echo " "
echo "--------- test 2 -------"
echo "./replace notexist.txt s s"
./replace notexist.txt s s
echo "------------------------"
echo " "
echo "--------- test 3 -------"
echo "./replace"
./replace
echo "------------------------"
echo " "
echo "--------- test 4 -------"
echo "./replace a a a a a a"
./replace a a a a a a
echo "------------------------"
echo " "
echo "--------- test 5 -------"
echo "./replace empty.txt s s"
./replace empty.txt s s
echo "------------------------"
echo " "

