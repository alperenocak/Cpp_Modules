#!/bin/bash

# ex00, ex01 ve ex02 dizinlerinde make fclean çalıştırır

DIRS=("ex00" "ex01" "ex02")

for dir in "${DIRS[@]}"; do
    if [ -d "$dir" ]; then
        echo "--> $dir temizleniyor..."
        make -C "$dir" fclean
    else
        echo "--> $dir bulunamadı!"
    fi
done

echo "Tüm dizinler temizlendi."
