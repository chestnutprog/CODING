$n=1
do{
echo "µÚ $n ´Î¶ÔÅÄ"
sleep 1
./gen.exe >input
cat input |./std.exe >stdoutput
cat input |./wa.exe >waoutput
$output1 = Get-Content stdoutput
$output2 = Get-Content waoutput
$n=$n+1
}while($output1 -eq $output2)