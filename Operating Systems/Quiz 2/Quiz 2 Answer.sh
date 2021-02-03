function sort_files
mkdir bytes
mkdir kilobytes
mkdir megabytes
mkdir gigabytes
    for var in (find ./ -name "*.$argv" -print | xargs ls)
        set filesize (wc -c $var)
        set size (echo $filesize | head -z | cut -d " " -f1)
        if [ $size -ge 1073741824 ]
            mv $var gigabytes
        else if [ $size -ge 1048576 ]
            mv $var megabytes
        else if [ $size -ge 1024 ]
            mv $var kilobytes
        else
            mv $var bytes
        end
    end    
end # function end