$n=1
do{
echo "第 $n 次对拍"
sleep 1
./gen.exe >input
cat input |./std.exe >stdoutput
cat input |./wa.exe >waoutput
$output1 = Get-Content stdoutput
$output2 = Get-Content waoutput
$n=$n+1
}while($output1 -eq $output2)
echo "WA的一声就哭了"