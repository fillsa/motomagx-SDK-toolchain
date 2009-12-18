#! /bin/bash

# This file is in KOI8-R. When copying to handset, it should
# be converted to UTF8:
#    iconv -f koi8-r -t utf-8 test.sh > /z6/mmc/mmca1/tests/test.sh

cd /mmc/mmca1/tests/

echo znoticedlg.cpp

./znoticedlg -H "Проверяем ZNoticeDlg, #1" -t 10 \
             -S notice \
             "Жмите кнопку"

echo Exit code $?

./znoticedlg -H "Проверяем ZNoticeDlg, #2" -t 10 \
             -S exclamation \
             "Жмите кнопку"

echo Exit code $?

./znoticedlg -H "Проверяем ZNoticeDlg, #3" \
             -S nothing -t 5 \
             -M "Ничего не жмите" "Ждите 5 sec"

echo Exit code $?

echo zmessagedlg.cpp

./zmessagedlg -H "Проверяем ZMessageDlg, #1" \
             -S ok_cancel \
             "Жмите кнопку OK"

echo Exit code $?

./zmessagedlg -H "Проверяем ZMessageDlg, #2" \
             -S yes_no \
             "Жмите кнопку NO"

echo Exit code $?

./zmessagedlg -H "Проверяем ZMessageDlg, #3" \
             -S ok -t 5 \
             "Ничего не жмите" "Ждите 5 cек"

echo Exit code $?

echo znumpickerdlg.cpp

./znumpickerdlg -H "Проверяем ZNumPickerDlg #1" \
              -V 20 -m 0 -M 100 -L "33!" "Наберите 33"

echo Exit code $?

./znumpickerdlg -H "Проверяем ZNumPickerDlg #2" -t 5 \
                 -V 10 -m 0 -M 100 -L "Не трогаете ничего" "Ждите 5 sec..." 

echo Exit code $?


echo zsinglecapturedlg.cpp

./zsinglecapturedlg -H "Проверяем ZSingleCaptureDlg #1" \
                    -S normal "Набираем что-нибудь"

echo Exit code $?

echo zsingleselectdlg.cpp

./zsingleselectdlg -H "Проверяем ZSingleSelectDlg #1" \
                       -M "Выбираем овощ" \
                       "Вишня" "Малина" "Огурец" "Дом"

echo Exit code $?

./zsingleselectdlg -H "Проверяем ZSingleSelectDlg #2" -t 5 \
                       -M "Не трогаем, ждем 5 sec" \
                       "Вишня" "Малина" "Огурец" "+Дом"

echo Exit code $?

echo zmultiselectdlg.cpp

./zmultiselectdlg -H "Проверяем ZMultiSelectDlg #1" \
                       -M "Выбираем фрукты" \
                       "Яблоко" "+Малина" "+Груша" "+Дом" "Лимон"

echo Exit code $?

./zmultiselectdlg -H "Проверяем ZMultiSelectDlg #2" -t 5 \
                       -M "Ничего делать не надо, просто ждать 5 сек" \
                       "Яблоко" "+Малина" "+Груша" "+Дом" "Лимон"

echo Exit code $?

