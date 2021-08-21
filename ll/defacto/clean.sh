for i in `ls`;
do
    if [ -d $i ]; then
        make -C $i clean
    fi
done