# 異常なマップのテスト
echo "Testing abnormal maps..."
for map in map/error/*.rt; do
    echo "Testing ${map}"
    ./miniRT "${map}"
    if [ $? -eq 0 ]; then
        echo "SUCCESS Test unexpectedly passed for ${map}"
    else
        echo "ERROR Test correctly failed for ${map}"
    fi
	echo
done
echo "END abnormal maps..."
